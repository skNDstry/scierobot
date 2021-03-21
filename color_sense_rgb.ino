#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 2
int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);
  
  Serial.begin(9600);
}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
   redfrequency = pulseIn(sensorOut, LOW);
 
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  greenfrequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
 
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  bluefrequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor

 Serial.print(redfrequency);
 Serial.print(" ");
 Serial.print(bluefrequency);
 Serial.print(" ");
 Serial.println(greenfrequency);
 
}
