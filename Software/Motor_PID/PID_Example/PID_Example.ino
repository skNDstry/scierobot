//The sample code for driving one way motor encoder
#include <PID_v1.h>
const byte encoder0pinA = 20;//A pin -> the interrupt pin 0
const byte encoder0pinB = 25;//B pin -> the digital pin 3
int E_left =22; //L298P直流电机驱动板的使能端口连接到数字接口5
int M_left =5; //L298P直流电机驱动板的转向端口连接到数字接口4
byte encoder0PinALast;
double duration,abs_duration;//the number of the pulses
boolean Direction;//the rotation direction
boolean result;

double val_output;//用于提供给电机PWM功率值。
double Setpoint;
double Kp=1, Ki=4, Kd=1;
PID myPID(&abs_duration, &val_output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
   Serial.begin(9600);//Initialize the serial port
   pinMode(M_left, OUTPUT);   //L298P直流电机驱动板的控制端口设置为输出模式
   pinMode(E_left, OUTPUT);
   Setpoint =180;  //设置PID的输出值
   myPID.SetMode(AUTOMATIC);//设置PID为自动模式
   myPID.SetSampleTime(100);//设置PID采样频率为100ms
   EncoderInit();//Initialize the module
}

void loop()
{   
      Setpoint = 80;
      for(int l = 0;l<=1000;l++){
        advance();//电机正转
        abs_duration=abs(duration);
        result=myPID.Compute();//PID转换完成返回值为1
        if(result)
        {
          Serial.print("Pluse: ");
          Serial.println(duration);
          duration = 0; //计数清零等待下次计数
        }
      }
      Setpoint = 40;
      for(int l = 0;l<=1000;l++){
        advance();//电机正转
        abs_duration=abs(duration);
        result=myPID.Compute();//PID转换完成返回值为1
        if(result)
        {
          Serial.print("Pluse: ");
          Serial.println(duration);
          duration = 0; //计数清零等待下次计数
        }
      }

}

void EncoderInit()
{
  Direction = true;//default -> Forward
  pinMode(encoder0pinB,INPUT);
  attachInterrupt(digitalPinToInterrupt(encoder0pinA), wheelSpeed, CHANGE);
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
     digitalWrite(M_left,LOW);
     analogWrite(E_left,val_output);
}
void back()//电机反转
{
     digitalWrite(M_left,HIGH);
     analogWrite(E_left,255-val_output);
}

void Stop()//电机停止
{
     digitalWrite(M_left,HIGH);
     digitalWrite(E_left,HIGH);
}
