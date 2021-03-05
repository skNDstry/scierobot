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

  if(!direc)  duration++;
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
    analogWrite(5,25*i);
  }
}
