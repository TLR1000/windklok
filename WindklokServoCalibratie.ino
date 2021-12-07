//TO DO: NUL meting wordt Max uitslag.

#include <Arduino.h>
#include <Servo.h>

Servo knotsServo;
Servo tempServo;

//----aanpassen wijzerstand na (de-)montage        
const float knotsServoStartPos = 560; //per servo finetunen 
const float tempServoStartPos = 660;  //per servo finetunen
//----vast
const float servoRange = 1950; //verschil tussen 0 en 180 graden
const float knotsServoEndPos = knotsServoStartPos + servoRange; //hulpvariabele voor de leesbaarheid       
const float tempServoEndPos = tempServoStartPos + servoRange; //hulpvariabele voor de leesbaarheid
const float schaalMax = 30; //maximumwaarde van de schaal van de meters
float vermFactor; //hulpvariabele voor de leesbaarheid
int uValue; //microseconden voor servosturing


void setup() {
  knotsServo.attach(D5);
  tempServo.attach(D3);

  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println();
        
        //metinggegevens               
        float value02 = 15; //knots
        float value03 = 15; //temp

        //Knots servo instellen.
        Serial.print("Knots instellen met meetwaarde ");  Serial.println(value02);
        vermFactor = value02 / schaalMax;
        uValue = knotsServoEndPos - (vermFactor * servoRange);
        delay(10); //no rush
        knotsServo.writeMicroseconds(uValue);
        delay(1000); //tijd geven

        //Temp servo instellen.
        Serial.print("Temp instellen met meetwaarde ");  Serial.println(value03);
        vermFactor = value03 / schaalMax;
        uValue = tempServoEndPos - (vermFactor * servoRange);
        delay(10); //no rush
        tempServo.writeMicroseconds(uValue);
        delay(1000); //tijd geven

        delay(2000);
         
        //Temp servo instellen.
        value03 = 10; //temp
        Serial.print("Temp instellen met meetwaarde ");  Serial.println(value03);
        vermFactor = value03 / schaalMax;
        Serial.print("vermFactor ");  Serial.println(vermFactor);
        uValue = tempServoEndPos - (vermFactor * servoRange);
        Serial.print("uValue ");  Serial.println(uValue);
        delay(10); //no rush
        tempServo.writeMicroseconds(uValue);
        delay(1000); //tijd geven

        delay(2000);
         
        //Temp servo instellen.
        value03 = 30; //temp
        Serial.print("Temp instellen met meetwaarde ");  Serial.println(value03);
        vermFactor = value03 / schaalMax;
        uValue = tempServoEndPos - (vermFactor * servoRange);
        delay(10); //no rush
        tempServo.writeMicroseconds(uValue);
        delay(1000); //tijd geven


}

void loop() {
}
