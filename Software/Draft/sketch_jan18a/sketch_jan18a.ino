const int M1_1 = 9;
const int M1_2 = 8;
const int M2_1 = 4;
const int M2_2 = 15;
const int M3_1 = 7;
const int M3_2 = 23;
const int M4_1 = 6;
const int M4_2 = 22;



void setspeed(int IA1, int IA2, int Speed) {
  if (Speed >= 0) {
    digitalWrite(IA2, LOW);
    analogWrite(IA1, Speed);
  }
  else{
    digitalWrite(IA2, HIGH);
    analogWrite(IA1, 256-Speed);
  }
  
}

void setup() {
  Serial.begin(9600);
  pinMode(M1_1, OUTPUT);
  pinMode(M1_2, OUTPUT);
  
}

void loop() {
  digitalWrite(M1_1,HIGH);
  digitalWrite(M1_2, LOW);
  delay(1000);
  Serial.println('1');
}
