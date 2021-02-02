/*
 * PID basic control for testing the PID library
 * Written by Roger Wang
 */
/*
#include <PID_v1.h>

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,2,5,1, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(3,OUTPUT);
  Input = analogRead(A0);
  Setpoint = 100;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  /*Input = analogRead(A0);
  myPID.Compute();
  analogWrite(3,Output);
  //Serial.println(Output);
  Serial.println("  ");
  Serial.println(Input);
  *
  for(int i = 0; i<=255; i++){
    analogWrite(3,i);
    Serial.println(analogRead(A0));
    delay(50);
  }
}
*/



#include <PID_v1.h>

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,50,5,1, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Input = analogRead(0);
  Setpoint = 700;
  Serial.begin(9600);
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  Input = analogRead(0);
  myPID.Compute();
  analogWrite(3,Output);
  Serial.println(Input);
  delay(30);
}
