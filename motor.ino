struct motor{
  int I1,I2;
  motor(int i1,int i2){
    I1=i1,I2=i2;
    pinMode(I1,OUTPUT),pinMode(I2,OUTPUT);
    setSpeed(0);
  }
  void setSpeed(int speed){
    if(speed>0){
      analogWrite(I1,speed),digitalWrite(I2,LOW);
    }
    else if(speed<0){
      analogWrite(I1,speed+255),digitalWrite(I2,HIGH);
    }
    else{
      analogWrite(I1,0),digitalWrite(I2,HIGH);
    }
  }
};
struct colorSenser{
  int s0,s1,s2,s3;
  colorSenser(int S0,int S1,int S2,int S3)
  {
    s0=S0,s1=S1,s2=S2,s3=S3;
    pinMode(s0,OUTPUT),pinMode(s1,OUTPUT),pinMode(s2,OUTPUT),pinMode(s3,OUTPUT);
    digitalWrite(s0,HIGH),digitalWrite(s1,HIGH);
  }
  int G()
  {
    digitalWrite(s2,HIGH),digitalWrite(s3,HIGH);
    
  }
};
motor *m1,*m2,*m3,*m4;
void setup() {
  // put your setup code here, to run once:
  m1=new motor(4,15);
  m2=new motor(5,14);
  m3=new motor(6,22);
  m4=new motor(7,23);
  pinMode(23,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  m1->setSpeed(255);
  m2->setSpeed(255);
  m3->setSpeed(255);
  m4->setSpeed(255);
  //delay(1000);
}
