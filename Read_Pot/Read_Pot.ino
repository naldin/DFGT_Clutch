//https://github.com/naldin/DFGT_Clutch

const int Pot = A0;
int valPot;

void setup() {
  Serial.begin(9600);
  pinMode (Pot, INPUT);
}

void loop() {
  valPot = analogRead(Pot);
  Serial.println(valPot);
  delay(1000);
}
