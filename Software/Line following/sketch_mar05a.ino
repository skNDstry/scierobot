byte motor[4][2][2]  = {{{15,4},{5,17}},{{23,7},{2,24}},{{14,5},{4,16}},{{22,6},{3,25}}};
int GREYleft = A14;
int Greyright = A15;
int val;
void init1 (){
  for (byte i = 0; i < 4; i++){
    pinMode(motor[i][0][0], OUTPUT);
    pinMode(motor[i][0][1], OUTPUT);
  }

 
}
void motor_setspeed(int pin1, int pin2, int value){
  if (value > 0){
    digitalWrite(pin1, LOW);
    analogWrite(pin2, value);
  }
  else{
    digitalWrite(pin1, HIGH);
    analogWrite(pin2, 255-value);
  }
}
void setup() {
  init1();
  Serial.begin(9600);
  pinMode(A14, INPUT);
  pinMode(A15, INPUT);
  motor_setspeed(15,4,0);
  motor_setspeed(23,7,0);
  motor_setspeed(14,5,0);
  motor_setspeed(22,6,0);
}

void turn(int diffspeed, int speedo){
  motor_setspeed(15,4,speedo);
  motor_setspeed(23,7,-speedo + diffspeed);
  motor_setspeed(14,5,speedo);
  motor_setspeed(22,6,-speedo + diffspeed);
}

void followline (){
  int val1 = analogRead(A14);
  int val2 = analogRead(A15);
  int diff = val1-val2;
  turn(-diff, 100);
  delay(50);  
}
  

void loop() {
  /*
  motor_setspeed(15,4,255);
  motor_setspeed(23,7,-255);
  motor_setspeed(14,5,255);
  motor_setspeed(22,6,-255);
  */
 
  /*val=analogRead(A14);   //connect grayscale sensor to Analog 0
  Serial.print(val,DEC);//print the value to serial
  Serial.print(',');
  val=analogRead(A15);   //connect grayscale sensor to Analog 0
  Serial.println(val,DEC);//print the value to serial
  delay(100);*/
  followline();
  
}
