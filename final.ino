// Incluímos la librería para poder controlar el servo
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo servoMotor;
#define SENSOR A0//the YELLOW pin of the Sensor is connected with A0 of Arduino/OPEN-SMART UNO R3
int Relay1 = 7 ; 
int Relay2 = 8;
void setup()
{
    Serial.begin(9600);
    pinMode(Relay1, OUTPUT);     //Set Pin12 as output 
    pinMode(Relay2, OUTPUT);     //Set Pin12 as output 
}
void loop()

{
  int raw = analogRead(SENSOR);
  float voltaje = (float) raw * 5.0 / 1024.0;
  Serial.print("El voltaje medido es: ");
  //Serial.println((float) raw * 5.0 / 1024.0,  8);
  Serial.println(voltaje, 8);
  if(voltaje < 0.515){
    Serial.println("Inflando");
    servoMotor.write(5);
    digitalWrite(Relay1, HIGH);   //Turn off relay 
    digitalWrite(Relay2, HIGH);   //Turn off relay
    delay(100);
    }
   else if (voltaje > 0.515){
        Serial.println("Des-inflando");
        servoMotor.write(95);
        digitalWrite(Relay1, LOW);    //Turn on relay 
        digitalWrite(Relay2, LOW);    //Turn on relay
        delay(100);
    }
}
