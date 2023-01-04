
#include <SoftwareSerial.h>
#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;


//Constantes a utilizar
char dato,datonuevo;
char dato2;
char dato3;



bool letra = true;
String letra1, letra2;
int angulo = 90;
float dist;
float datoserial;
boolean Recoger = true;
float contadorP=100;
int contadorRecogida=1;
double distan;

//Ultrasonido
const int trigPin =2;
const int ecoPin = 4;
long duracion;
double distancia;

void setup() {
  //Initialization functions and set up the initial position for Braccio
  //All the servo motors will be positioned in the "safety" position:
  //Base (M1):90 degrees
  //Shoulder (M2): 45 degrees
  //Elbow (M3): 180 degrees
  //Wrist vertical (M4): 180 degrees
  //Wrist rotation (M5): 90 degrees
  //gripper (M6): 10 degrees
  
  pinMode(trigPin, OUTPUT);
  pinMode(ecoPin, INPUT);
  Serial.begin(9600);
  Serial.setTimeout(10);
  Braccio.begin();
  
  
  
  delay(2000);
  Serial.print("hola");
  
  
}


double Distancia(){
  //Función encargada de activar un sensor ultrasonico para la detección de profundidad
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
 
  duracion = pulseIn(ecoPin, HIGH);
  distancia = duracion*0.034/2;
 
  return distancia;
  
}

float PrimerCuadranteEnX(char datoserial){
    //Movimientos predefinidos del brazo robótico
    switch(datoserial){
      case 'q':
         Braccio.ServoMovement(50,           angulo,  100, 95, 0, 115, 73 );
      break;
      
      case 'w':
         Braccio.ServoMovement(50,          angulo,  130, 45, 22, 115, 73 );
      break;
      
      case 'e':
         Braccio.ServoMovement(50,           angulo,  140, 27, 33, 115, 73 );
      break;
      
      case 'r':
         Braccio.ServoMovement(50,          angulo,  148, 15, 40, 115, 73 );
      break;
      
      case 't':
         Braccio.ServoMovement(50,          angulo,  148, 15, 33, 115, 73 );
      break;
      
      case 'y':
         Braccio.ServoMovement(50,           angulo,  155, 3, 38, 115, 73 );
      break;
      
      case 'u':
         Braccio.ServoMovement(50,           angulo,       155, 0, 31, 115, 73 );
      break;
      
      case 'o':
        Braccio.ServoMovement(50,           angulo,       137, 0, 45, 115, 73 );
      break;
      
      case 'a':
        Braccio.ServoMovement(50,           angulo,       137, 0, 40, 115, 73 );
      break;
      
      case 's':
         Braccio.ServoMovement(50,          angulo,       134, 0, 35, 115, 73 );
      break;
      
      case 'f':
        Braccio.ServoMovement(50,           angulo,       130, 0, 35, 115, 73 );
      break;
      
      case 'g':
        Braccio.ServoMovement(50,          angulo,       130, 0, 35, 115, 73 );
      break;
      
      
    }
    delay(3000);
}

///////////////////
float SegundoCuadranteEnX(char datoserial){
    //Movimientos predefinidos del brazo robótico
    switch(datoserial){
      case 'q':
        Braccio.ServoMovement(50,           angulo,  90, 95, 10, 115, 73 );
      break;
      
      case 'w':
         Braccio.ServoMovement(50,           angulo,  118, 45, 33, 115, 73 );//2
      break;
      
      case 'e':
        Braccio.ServoMovement(50,          angulo,  127, 27, 44, 115, 73 );//2
      break;
      
      case 'r':
        Braccio.ServoMovement(50,           angulo,  130, 15, 55, 115, 73 );//2 
      break;
      
      case 't':
        Braccio.ServoMovement(50,          angulo,  133, 15, 45, 115, 73 );//2
      break;
      
      case 'y':
         Braccio.ServoMovement(50,           angulo,  137, 3, 55, 115, 73 );//2  Fila
      break;
      
      case 'u':
        Braccio.ServoMovement(50,          angulo,       138, 0, 46, 115, 73 );//2 Septima Fila
      break;
      
      case 'o':
        Braccio.ServoMovement(50,          angulo,       137, 0, 45, 115, 73 );//2 Octava Fila
      break;
      
      case 'a':
        Braccio.ServoMovement(50,           angulo,       137, 0, 40, 115, 73 );//2 NOVENA Fila
      break;
      
      case 's':
        Braccio.ServoMovement(50,          angulo,       134, 0, 35, 115, 73 );//2 decima Fila
      break;
      
      case 'f':
        Braccio.ServoMovement(50,           angulo,       130, 0, 35, 115, 73 );//2 once Fila
      break;
      
      case 'g':
       Braccio.ServoMovement(50,           angulo,       130, 0, 35, 115, 73 );//2 once Fila
      break;
      
      
    }
    delay(3000);
}

/////////////////////7
float TercerCuadranteEnX(char datoserial){
    //Movimientos predefinidos del brazo robótico
    switch(datoserial){
      case 'q':
       Braccio.ServoMovement(50,           angulo,  80, 95, 20, 115, 73 );//3
      break;
      
      case 'w':
       Braccio.ServoMovement(50,           angulo,  105, 45, 45, 115, 73 );//3
      break;
      
      case 'e':
        Braccio.ServoMovement(50,           angulo,  115, 30, 58, 115, 73 );//3
      break;
      
      case 'r':
        Braccio.ServoMovement(50,           angulo,  115, 25, 60, 115, 73 );//3 
      break;
      
      case 't':
         Braccio.ServoMovement(50,           angulo,  118, 20, 62, 115, 73 );//3
      break;
      
      case 'y':
        Braccio.ServoMovement(50,           angulo,  120, 3, 75, 115, 73 );//3  Fila
      break;
      
      case 'u':
        Braccio.ServoMovement(50,           angulo,       123, 0, 66, 115, 73 );//3 Septima Fila
      break;
      
      case 'o':
        Braccio.ServoMovement(50,          angulo,       119, 0, 65, 115, 73 );//3 Octava Fila
      break;
      
      case 'a':
       Braccio.ServoMovement(50,           angulo,       117, 0, 60, 115, 73 );//3 NOVENA Fila
      break;
      
      case 's':
        Braccio.ServoMovement(50,           angulo,       114, 0, 58, 115, 73 );//3 decima Fila
      break;
      
      case 'f':
        Braccio.ServoMovement(50,           angulo,       110, 0, 55, 115, 73 );//3 decima Fila
      break;
      
      case 'g':
        Braccio.ServoMovement(50,          angulo,       110, 0, 55, 115, 73 );//3 decima Fila
      break;
      
      
    }
    delay(3000);
 }

 //////////
 float CuartoCuadranteEnX(char datoserial){
    //Movimientos predefinidos del brazo robótico
    switch(datoserial){
      case '-1':
         Braccio.ServoMovement(50,           angulo,  70, 95, 32, 115, 73 );//4
      case 'q':
        Braccio.ServoMovement(50,           angulo,  70, 95, 32, 115, 73 );//4
      break;
      
      case 'w':
         Braccio.ServoMovement(50,           angulo,  95, 45, 60, 115, 73 );//4
      break;
      
      case 'e':
        Braccio.ServoMovement(50,           angulo,  98, 40, 63, 115, 73 );//4
      break;
      
      case 'r':
        Braccio.ServoMovement(50,           angulo,  100, 35, 67, 115, 73 );//4
      break;
      
      case 't':
         Braccio.ServoMovement(50,           angulo,  106, 23, 72, 115, 73 );//4
      break;
      
      case 'y':
        Braccio.ServoMovement(50,           angulo,  104, 13, 84, 115, 73 );//4 ila
      break;
      
      case 'u':
        Braccio.ServoMovement(50,           angulo,       110, 5, 83, 115, 73 );//4 Septima Fila
      break;
      
      case 'o':
        Braccio.ServoMovement(50,           angulo,       100, 10, 80, 115, 73 );//4 Octava Fila
      break;
      
      case 'a':
        Braccio.ServoMovement(50,           angulo,       100, 10, 75, 115, 73 );//4 NOVENA Fila
      break;
      
      case 's':
        Braccio.ServoMovement(50,           angulo,       100, 0, 82, 115, 73 );//4 decima Fila
      break;
      
      case 'f':
         Braccio.ServoMovement(50,           angulo,       95, 0, 80, 115, 73 );//4 decima Fila
      break;
      
      case 'g':
         Braccio.ServoMovement(50,           angulo,       95, 0, 80, 115, 73 );//4 decima Fila
      break;
      
      
    }
    delay(3000);
}

float QuintoCuadranteEnX(char datoserial){
    //Movimientos predefinidos del brazo robótico
    switch(datoserial){
      case 'q':
        Braccio.ServoMovement(50,           angulo,  60, 95, 47, 115, 73 );//5
      break;
      
      case 'w':
        Braccio.ServoMovement(50,           angulo,  60, 100, 35, 115, 73 );//5
      break;
      
      case 'e':
        Braccio.ServoMovement(50,           angulo,  80, 50, 75, 115, 73 );//5
      break;
      
      case 'r':

        Braccio.ServoMovement(50,          angulo,  85, 45, 70, 115, 73 );//5
      break;
      
      case 't':
        Braccio.ServoMovement(50,           angulo,  80, 46, 70, 115, 73 );//5
      break;
      
      case 'y':
        Braccio.ServoMovement(50,           angulo,  85, 26, 91, 115, 73 );//5 Fila
      break;
      
      case 'u':
        Braccio.ServoMovement(50,           angulo,       90, 20, 85, 115, 73 );//5 Septima Fila
      break;
      
      case 'o':
        Braccio.ServoMovement(50,           angulo,       80, 25, 85, 115, 73 );//5 Octava Fila
      break;
      
      case 'a':
       Braccio.ServoMovement(50,           angulo,       80, 24, 80, 115, 73 );//5 NOVENA Fila
      break;
      
      case 's':
        Braccio.ServoMovement(50,           angulo,       80,15, 90, 115, 73 );//5 decima Fila
      break;
      
      case 'f':
        Braccio.ServoMovement(50,           angulo,       75, 0, 115, 115, 73 );//5 decima Fila
      break;
      
      case 'g':
        Braccio.ServoMovement(50,           angulo,       75, 0, 115, 115, 73 );//5 decima Fila
      break;
      
      
    }
    delay(3000);
  
  
  
  
  
  }


  float SextoCuadranteEnX(char datoserial){
    //Movimientos predefinidos del brazo robótico
    switch(datoserial){
      case 'q':
         Braccio.ServoMovement(50,           angulo,  45, 95, 77, 115, 73 );
      break;
      
      case 'w':
        Braccio.ServoMovement(50,           angulo,  45, 100, 69, 115, 73 );//5
      break;
      
      case 'e':
        Braccio.ServoMovement(50,           angulo,  50, 75, 90, 115, 73 );//6
        
      break;
      
      case 'r':
          Braccio.ServoMovement(50,           angulo,  50, 75, 83, 115, 73 );//6
        
      break;
      
      case 't':
        Braccio.ServoMovement(50,           angulo,  55, 76, 65 , 115, 73 );//6
      break;
      
      case 'y':
        Braccio.ServoMovement(50,           angulo,  60, 49, 95, 115, 73 );//6  Fila
      break;
      
      case 'u':
        Braccio.ServoMovement(50,           angulo,       60, 45, 95, 115, 73 );//6 Septima Fila
      break;
      
      case 'o':
        Braccio.ServoMovement(50,           angulo,       60, 45, 85, 115, 73 );//6 Octava Fila
      break;
      
      case 'a':
       Braccio.ServoMovement(50,           angulo,       55, 50, 84, 115, 73 );//6 NOVENA Fila
      break;
      
      case 's':
        Braccio.ServoMovement(50,           angulo,       60,38, 90, 115, 73 );//6 decima Fila
      break;
      
      case 'f':
        Braccio.ServoMovement(50,           angulo,       50, 30, 120, 115, 73 );//5 decima Fila
      break;
      
      case 'g':
        Braccio.ServoMovement(50,           angulo,       50, 30, 120, 115, 73 );//5 decima Fila
      break;
      
      
    }
    delay(3000);
  
  
  
  
  }
  
  


float Recogercomida(){
   //Función encargada de realizar la recogida de comida
  Braccio.ServoMovement(50,           90,       155, 10, 30, 115, 73 );//default finAL
  delay(1000);
  
  //bajada
  Braccio.ServoMovement(50,           140,       155, 10, 30, 115, 73 );
    delay(1000);
  Braccio.ServoMovement(50,           157,       48   , 0, 134, 62, 73 );

  
   delay(2000);
  if(contadorRecogida==1){
 //busqueda1   
  Braccio.ServoMovement(50,           165,    48   , 0, 134, 62, 73 );
  delay(2000);

  Braccio.ServoMovement(50,           165,    48   , 0, 134, 115, 73 );
  delay(2000);


  Braccio.ServoMovement(50,           165,    48   , 0, 134, 115, 73 );
  delay(2000);
  
  Braccio.ServoMovement(50,           165,   90   , 0, 100, 115, 73 );

  Braccio.ServoMovement(50,           90,       155, 10, 30, 115, 73 );//default finAL
  delay(1000);
  contadorRecogida  =2;

  }else if(contadorRecogida==2){
    //busqueda2
    Braccio.ServoMovement(50,           165,    48   , 0, 134, 62, 73 );
  delay(2000);
    
    Braccio.ServoMovement(50,           175,    48   , 0, 134, 62, 73 );
    delay(2000);
    Braccio.ServoMovement(50,           175,    48   , 0, 134, 115, 73 );
    delay(2000);

    
    Braccio.ServoMovement(50,           175,    48   , 0, 134, 115, 73 );
    delay(2000);
  
    Braccio.ServoMovement(50,           175,   90   , 0, 100, 115, 73 );

    Braccio.ServoMovement(50,           90,       155, 10, 30, 115, 73 );//default finAL
    delay(1000);
    contadorRecogida  =3;
    

  }else if(contadorRecogida  ==3){
    //busqueda3
   Braccio.ServoMovement(50,           175,    48   , 0, 134, 62, 73 );
    delay(2000);
    
    Braccio.ServoMovement(50,           190,    48   , 0, 134, 62, 73 );
    delay(2000);

    Braccio.ServoMovement(50,           190,    48   , 0, 134, 115, 73 );
    delay(2000);

    
    Braccio.ServoMovement(50,           190,    48   , 0, 134, 115, 73 );
    delay(2000);
  
    Braccio.ServoMovement(50,           190,   90   , 0, 100, 115, 73 );

    Braccio.ServoMovement(50,           90,       155, 10, 30, 115, 73 );//default finAL
    delay(1000);
    contadorRecogida =1;

  }
  





  
 
  




  

  
  
}
void estirarBrazo(double distancia, char dato2){
      //Estiramiento del brazo robótico hacia la boca de la persona
   
      if(distancia>=5 && distancia<13){
         PrimerCuadranteEnX(dato2);
        
      }
      if(distancia>=13 && distancia<17){
       
        SegundoCuadranteEnX(dato2);
        
      }
      if(distancia>=17 && distancia<22){
        
         TercerCuadranteEnX(dato2);
         
      }
       if(distancia>=22 && distancia<25){
        
          CuartoCuadranteEnX(dato2);
      }
       if(distancia>=25 && distancia<29){
           QuintoCuadranteEnX(dato2);
        
      }
      if(distancia>=29 && distancia<34){
           
          SextoCuadranteEnX(dato2);
      }
      if(distancia>=34 && distancia<50){
           
          SextoCuadranteEnX(dato2);
      }
  
       

     
}
void getDatos() {
  \\Función para recolectar los datos provenientes del puertoSerial, datos entregados por Python
   if (Serial.available() > 0) {
    letra1 = Serial.readStringUntil('\n');
    while (Serial.available() <= 0) {

    }
    letra2 = Serial.readStringUntil('\n');
    Serial.print("Letras recibidas: ");
    Serial.print(letra1);
    Serial.print(" y ");
    Serial.print(letra2);
    Serial.print('\n');
    Serial.print("R");
    Serial.print('\n');

    baseBrazo(letra1,letra2);
  }
}

void baseBrazo(String letra1S,String letra2S){
    //Movimiento de direccionamiento hacia la cara de la persona
    Braccio.ServoMovement(5,           angulo,       155, 10, 30, 115, 73 );//Default
    
    char letra1= letra1S[0]; 
    char letra2= letra2S[0];
    switch(letra2){
      case 'd':
      angulo = angulo -2;
      
      Braccio.ServoMovement(5,           angulo,       155, 10, 30, 115, 73 );//Default
      
      break;

      case 'i':
      angulo = angulo +2;
      Braccio.ServoMovement(5,           angulo,       155, 10, 30, 115, 73 );//Default
      break;
      
      case 'p':
       angulo = angulo;
       Braccio.ServoMovement(5,           angulo,       155, 10, 30, 115, 73 );//Default
       contadorP=contadorP-1;
       
       if(contadorP <= 0){
        distan = Distancia();
          if(distan<=34){ 
            estirarBrazo(distan,letra1);
            contadorP = 100;
            Recoger = true;
          }
       }
       break;
       
       
    }
 

  
  
  
  
  
}


void loop() {
   /*
   Step Delay: a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
   M1=base degrees. Allowed values from 0 to 180 degrees
   M2=shoulder degrees. Allowed values from 15 to 165 degrees
   M3=elbow degrees. Allowed values from 0 to 180 degrees
   M4=wrist vertical degrees. Allowed values from 0 to 180 degrees
   M5=wrist rotation degrees. Allowed values from 0 to 180 degrees
   M6=gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
  */
 
  
if(Recoger == true){
    Recogercomida();
    Recoger = false;
  }


  
 getDatos(); 
  
 
 
  
}
