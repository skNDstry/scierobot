#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define O 2
int rF = 0;
int gF = 0;
int bF = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(O, INPUT);
  
  // Setting frequency scaling to 20%. 20% Works best for Arduinos.
  /*** 
   *  This is a table for frequency scaling
   *  -----------------------------
   *  | Scaling |   S0   |   S1   |
   *  | 0%      |   L    |   L    |
   *  | 2%      |   L    |   H    |
   *  | 20%     |   H    |   L    |
   *  | 100%    |   H    |   H    |
   *  -----------------------------
   *  This is the table for filter selection
   *  -----------------------------
   *  | Filter  |   S0   |   S1   |
   *  | RED     |   L    |   L    |
   *  | BLUE    |   L    |   H    |
   *  | GREEN   |   H    |   H    |
   *  | CLEAR   |   H    |   L    |
   *  -----------------------------
   *  You should adjust those two variables in the code for your situation.
   */
  digitalWrite(S0,1);
  digitalWrite(S1,0);
  Serial.begin(9600);
}
void loop() {
  // RED 
  digitalWrite(S2,0);
  digitalWrite(S3,0);
  rF = pulseIn(O, 0);
  Serial.print("R = ");
  Serial.print(rF);
  delay(100);
  
  // GREEN
  digitalWrite(S2,1);
  digitalWrite(S3,1);
  gF = pulseIn(O, 0);
  Serial.print(" G = ");
  Serial.print(gF);
  delay(100);
 
  // BLUE
  digitalWrite(S2,0);
  digitalWrite(S3,1);
  bF = pulseIn(O, 0);
  Serial.print(" B = ");
  Serial.println(bF);
  delay(100);
}
