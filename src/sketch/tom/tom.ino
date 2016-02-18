
#include <MeMCore.h>

#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <SoftwareSerial.h>



double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeRGBLed rgbled_7(7, 7==7?2:4);



void setup(){
    rgbled_7.setColor(0,150,0,0);
    rgbled_7.show();
    delay(1000*1);
    rgbled_7.setColor(0,0,0,0);
    rgbled_7.show();
    
}

void loop(){
    
    
}

