struct motor{
  int I1,I2;
  motor(int i1,int i2){
    I1=i1,I2=i2;
    pinMode(I1,OUTPUT),pinMode(I2,OUTPUT);
    setSpeed(0);
  }
  void setSpeed(int speed){
    if(speed>0){
      analogWrite(I1,speed),digitalWrite(I2,HIGH);
    }
    else if(speed<0){
      analogWrite(I1,speed+255),digitalWrite(I2,LOW);
    }
    else{
      analogWrite(I1,0),digitalWrite(I2,HIGH);
    }
  }
};
motor *m;
void setup() {
  Serial.begin(9600);
  m=new motor(2,14);
  pinMode( 2, OUTPUT );
  //pinMode( 3, OUTPUT );
  pinMode( 14, OUTPUT );
  //pinMode( 15, OUTPUT);
  //digitalWrite( 3, LOW );
  //analogWrite(2,100);
  digitalWrite(14,LOW);
}

void loop() {
  //m->setSpeed(-100);
  /*analogWrite(2,100);
  digitalWrite(14,HIGH);
  delay(5000);
  analogWrite(2,200);
  digitalWrite(14,HIGH);
  delay(5000);*/

  for (int i = 0; i<=25; i++){
    analogWrite( 2, 10*i );
    //Serial.println( 10*i );
    //m->setSpeed(10*i);
    delay( 200 );
  }
}
