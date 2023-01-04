import serial
import cv2
import mediapipe as mp


""" Variables a utilizar como datos de envío """

d = 'd'
i = 'i'
p = 'p'

q= 'q'
w  ='w'
e = 'e'
r='r'
t='t'
y = 'y'
u = 'u'
o='o'
a='a'
s='s'
f='f'
g='g'

letra1 = ''
letra2 = ''

""" Submodulos de mediapipe """
detector = mp.solutions.face_detection
dibujo = mp.solutions.drawing_utils
""" videoCaptura """
cap = cv2.VideoCapture(1, cv2.CAP_DSHOW)

def connectionArduino():
    """ Función encargada de realizar la conexión Al puerto Serial """
    print("\nBIENVENIDO - Brazo Robótico\n")
 
    COM = 'com6'
    print("Conectando con Arduino...\n")
    try:
        global arduino
        arduino = serial.Serial(COM, 9600, timeout=1)
        print("Conexión existosa\n")
        return True
    except:
        print("Conexión Fallida\n")


def startMessages():
    """Función encargada de mostrar mensajes si arduino esta conectado correctamente"""
    start = 0
    while start == 0:
        if arduino.inWaiting()>0:
            h = arduino.readline().decode('utf-8')
            if h == "hola":
                print("Arduino está listo\n")
                start = 1 

def sendArduino(letter1, letter2):
    """ Función encargada de guardar y enviar los datos recopilados por el algoritmo de detección hacia Arduino """
    arduino.write((letter1+'\n').encode('utf-8'))
    arduino.write((letter2+'\n').encode('utf-8'))  
    start = 0
    while start == 0:
        if arduino.inWaiting()>0:
            h = arduino.read_until('\n'.encode('utf-8')).decode('utf-8')
            h = h[0:len(h)-1]
            if h == "R":
                start = 1
            else:
                print(h)

      




if connectionArduino():
    startMessages()
    """ Proceso de detección facial permanente """
    with detector.FaceDetection(min_detection_confidence= 0.75, model_selection = 0) as rostros:
        while True:
            ret, frame = cap.read()
            frame = cv2.flip(frame, 1)
            """ Conversión de color BGR->RGB """
            rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

            """ Rostros """
            resultado = rostros.process(rgb)

            """ Creamos Listas """
            listacentro= []
            click = []
            listarostros = []
            """ Si existen rostros """
            if resultado.detections is not None:
                for rostro in resultado.detections:
                    for id,puntos in enumerate(resultado.detections):
                        """ Información """
                        al, an, c = frame.shape

                        """ Medio de la pantalla """
                        centro = int(an/2)
                        """ Coordenadas x e y min """
                        x = puntos.location_data.relative_bounding_box.xmin
                        y = puntos.location_data.relative_bounding_box.ymin
                        
                        """ Extraemos el ancho y alto """
                        ancho  = puntos.location_data.relative_bounding_box.width
                        alto = puntos.location_data.relative_bounding_box.height

                        """  x e y a pixeles """
                        x , y= int(x*an), int(y*al)

                        """ Ancho y alto a pixeles """
                        x1, y1 = int(ancho*an), int(alto*al)
                        xf ,yf =x+x1, y+y1

                        """ Punto central """
                        cx = (x +(x+x1))//2
                        cy = (y+(y+y1))//2
                        print(cx,cy)


                        """ Envio de datos sobre el rango en pixeles de la cara encontrada """
                        if(cy>=0 and cy<=100):
                            letra1 = 'q'
                        elif(cy>100 and cy<=134):
                            letra1 = 'w'
                        elif(cy>134 and cy<=168):
                            letra1 = 'e'
                        elif(cy>168 and cy<=202):   
                            letra1 = 'r'
                        elif(cy>202 and cy<=236):   
                            letra1 = 't'
                        elif(cy>236 and cy<=270):   
                            letra1 = 'y'  
                        elif(cy>270 and cy<=304):   
                            letra1 = 'u' 
                        elif(cy>304 and cy<=338):   
                            letra1 = 'o'
                        elif(cy>338 and cy<=372):   
                            letra1 = 'a' 
                        elif(cy>372 and cy<=406):   
                            letra1 = 's' 
                        elif(cy>406 and cy<=440):   
                            letra1 = 'd' 
                        elif(cy>440 and cy<=500):   
                            letra1 = 'f'     

                            
                        listacentro.append([id, cx, cy])
                        listarostros.append([x, y, x1, y1])
                        cv2.circle(frame, (cx,cy),3,(0,0,255),cv2.FILLED)
                        cv2.line(frame, (cx,0),(cx,480),(0,0,255),2)

                        cv2.namedWindow('Camera')
                        """ Envío de datos del cuadrante de la cara detectada para el direccionamiento """
                        if cx <centro -50:
                            #movemos hacia la izquierda
                            print('Izquierda')
                            letra2 = 'i'
                        elif cx >centro +50:
                            #movemos hacia la derecha 
                            print('Derecha')
                            letra2 = 'd'
                        else:
                            print('Parar')
                            letra2 = 'p' 

                        sendArduino(letra1, letra2)       
                                        
            cv2.imshow('Camera', frame) 
            cv2.waitKey(1)  
            t = cv2.waitKey(1)
            if t == 27:
                break 
    cap.release()    
    cv2.destroyAllWindows()  
   
    arduino.close()