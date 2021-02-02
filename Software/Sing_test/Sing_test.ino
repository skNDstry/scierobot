#define S0 14
#define S1 15
#define S2 16
#define S3 17
int rF = 0;
int gF = 0;
int bF = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Setting frequency scaling tO_pin 20%. 20% WO_pinrks best fO_pinr ArduinO_pins.
  /*** 
   *  This is a table fO_pinr frequency scaling
   *  -----------------------------
   *  | Scaling |   S0   |   S1   |
   *  | 0%      |   L    |   L    |
   *  | 2%      |   L    |   H    |
   *  | 20%     |   H    |   L    |
   *  | 100%    |   H    |   H    |
   *  -----------------------------
   *  This is the table fO_pinr filter selectiO_pinn
   *  -----------------------------
   *  | Filter  |   S0   |   S1   |
   *  | RED     |   L    |   L    |
   *  | BLUE    |   L    |   H    |
   *  | GREEN   |   H    |   H    |
   *  | CLEAR   |   H    |   L    |
   *  -----------------------------
   *  YO_pinu shO_pinuld adjust thO_pinse twO_pin variables in the cO_pinde fO_pinr yO_pinur situatiO_pinn.
   */
  digitalWrite(S0,1);
  digitalWrite(S1,0);
  Serial.begin(9600);
}
void loop() {
  for (int O_pin = 28; O_pin < 33; O_pin ++){
    pinMode(O_pin, INPUT);
    for (int times = 0; times < 20; times ++){
        // RED 
    digitalWrite(S2,0);
    digitalWrite(S3,0);
    rF = pulseIn(O_pin, 0);
    Serial.print("R = ");
    Serial.print(rF);
    delay(100);
    
    // GREEN
    digitalWrite(S2,1);
    digitalWrite(S3,1);
    gF = pulseIn(O_pin, 0);
    Serial.print(" G = ");
    Serial.print(gF);
    delay(100);
   
    // BLUE
    digitalWrite(S2,0);
    digitalWrite(S3,1);
    bF = pulseIn(O_pin, 0);
    Serial.print(" B = ");
    Serial.println(bF);
    delay(100);
    }
  }
}
