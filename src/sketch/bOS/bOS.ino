#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void goStraightAhead(double speed, double duration);
MeDCMotor motor_9(9);
MeDCMotor motor_10(10);
double currentTime = 0;
double lastTime = 0;
double getLastTime(){
    	return currentTime = millis()/1000.0 - lastTime;
}
MeBuzzer buzzer;
void turnAround();
void mainProgram();
double state;
void introRoutine();
MeRGBLed rgbled_7(7, 7==7?2:4);
void invokingRoutine();
void waitingRoutine();
void exitRoutine();
MBotDCMotor motor(0);
void userProgram();


void goStraightAhead(double speed, double duration)
{
    motor_9.run((9)==M1?-(speed):(speed));
    
    motor_10.run((10)==M1?-((speed) * (0.96)):((speed) * (0.96)));
    
    lastTime = millis()/1000.0;
    
    while(!((getLastTime()) > (duration)))
    {
        buzzer.tone(4186, 250);
        delay(1000*0.2);
    }
    
}

void turnAround()
{
    motor_9.run((9)==M1?-(170):(170));
    
    motor_10.run((10)==M1?-(0):(0));
    
    delay(1000*1.5);
    
}

void mainProgram()
{
    state = 0;
    
    introRoutine();
    
    state = 1;
    
    while(!((0^(analogRead(A7)>10?0:1))))
    {
        waitingRoutine();
    }
    
    state = 2;
    
    while(!((1^(analogRead(A7)>10?0:1))));
    
    state = 3;
    
    invokingRoutine();
    
    state = 4;
    
    exitRoutine();
    
    state = 5;
    
}

void introRoutine()
{
    rgbled_7.setColor(0,0,20,0);
    rgbled_7.show();
    
    buzzer.tone(196, 250);
    
    buzzer.tone(330, 250);
    
    buzzer.tone(262, 500);
    
    lastTime = millis()/1000.0;
    
}

void invokingRoutine()
{
    rgbled_7.setColor(0,0,0,20);
    rgbled_7.show();
    
    lastTime = millis()/1000.0;
    
    userProgram();
    
}

void waitingRoutine()
{
    rgbled_7.setColor(0,0,0,0);
    rgbled_7.show();
    
    delay(1000*0.1);
    
    rgbled_7.setColor(0,0,10,0);
    rgbled_7.show();
    
    delay(1000*0.1);
    
    rgbled_7.setColor(0,0,40,0);
    rgbled_7.show();
    
}

void exitRoutine()
{
    motor.move(1,0);
    
    rgbled_7.setColor(0,20,0,0);
    rgbled_7.show();
    
    buzzer.tone(262, 250);
    
    buzzer.tone(196, 250);
    
    buzzer.tone(175, 500);
    
    buzzer.noTone();
    
}

void userProgram()
{
    motor.move(1,100);
    
    delay(1000*5);
    
    motor.move(1,0);
    
}


void setup(){
    mainProgram();
    pinMode(A7,INPUT);
    
}

void loop(){
    
    
}

