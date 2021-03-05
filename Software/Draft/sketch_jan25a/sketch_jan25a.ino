 #include <PID_v1.h>

const byte encoder0pinA = 19;//A pin -> the interrupt pin 0
const byte encoder0pinB = 16;//B pin -> the digital pin 3
byte Motor1_1 = 5;
byte Motor1_2 = 14;
byte encoder0PinALast;
double duration, abs_duration;//the number of the pulses
boolean Direction, result;//the rotation direction

int inp;

double val_output;
double Setpoint;
double Kp=0.6, Ki=5, Kd=0;
PID myPID(&abs_duration, &val_output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  Serial.begin(57600);//Initialize the serial port
  Setpoint = 50;
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(100);  
  EncoderInit();//Initialize the module
}

void loop()
{
  abs_duration=abs(duration);
  result=myPID.Compute();//PID转换完成返回值为1
  if (Serial.available()>0){
    while (Serial.available()>0){
      inp += char(Serial.read());
    }
    Setpoint = int(inp);
  }
  if(result)
  {
    Serial.print("  ");
    Serial.println(duration);
    Serial.print("  ");
    Serial.print(val_output);
    duration = 0; //计数清零等待下次计数
  }
}

void EncoderInit()
{
  Direction = true;//default -> Forward
  pinMode(encoder0pinB,INPUT);
  attachInterrupt(digitalPinToInterrupt(encoder0pinA), wheelSpeed, CHANGE);
  pinMode(5,OUTPUT);
  pinMode(14,OUTPUT);
  digitalWrite(5,HIGH);
  digitalWrite(14,LOW);
}

void wheelSpeed()
{
  int Lstate = digitalRead(encoder0pinA);
  if((encoder0PinALast == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(encoder0pinB);
    if(val == LOW && Direction)
    {
      Direction = false; //Reverse
    }
    else if(val == HIGH && !Direction)
    {
      Direction = true;  //Forward
    }
  }
  encoder0PinALast = Lstate;

  if(!Direction)  duration++;
  else  duration--;
}

void advance()//电机正转
{
     digitalWrite(Motor1_2,LOW);
     analogWrite(Motor1_1,val_output);
}
/*
const byte encI = 19;
const byte encN = 16;
int duration;
byte encILast;
boolean direc = true;

void whlSpd(){
    int Lstate = digitalRead(encI);
  if((encILast == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(encN);
    if(val == LOW && direc)
    {
      direc = false; //Reverse
    }
    else if(val == HIGH && !direc)
    {
      direc = true;  //Forward
    }
  }
  encILast = Lstate;

  if(!direc){
    duration++;
    Serial.println('1');
  }
  
  else  duration--;
}


void setup(){
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(16,INPUT);
  pinMode(19,INPUT);
  attachInterrupt(19,whlSpd, CHANGE);
  digitalWrite(14,LOW);
}

void loop(){
  for(int i = 0; i< 10; i++){
    Serial.print("Pulse:");
    Serial.println(duration);
    duration = 0;
    delay(100);
  }
}
*/
