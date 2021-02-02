#define S0 14
#define S1 15
#define S2 16
#define S3 17
#define O1 A6
#define O2 A7
#define O3 A8
#define O4 A9
#define O5 A10
// OUTPUT ports: 28-32 
int RGB_O[5][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}}; // {R,G,B}
//int hahaha[4] = {1,2,3,4};
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  
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
  for (int i = 0; i < 5; i++){
    RGB_O[i][0]= pulseIn(i+27, 0);
  }
  
  // GREEN
  digitalWrite(S2,1);
  digitalWrite(S3,1);
  for (int i = 0; i < 5; i++){
    RGB_O[i][1]= pulseIn(i+27, 0);
  }
 
  // BLUE
  digitalWrite(S2,0);
  digitalWrite(S3,1);
  for (int i = 0; i < 5; i++){
    RGB_O[i][2]= pulseIn(i+27, 0);
  }
  for ( int i=0; i<5; i++){
      Serial.println();
      Serial.print(i+1);
      Serial.print("  ");
    for ( int j=0; j<3; j++){
      Serial.print(RGB_O[i][j]);
      Serial.print("  ");
      
    } 
  }
  delay(5000);
}
