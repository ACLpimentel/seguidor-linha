#define infra_0 A0
#define infra_1 A1
#define infra_2 A2
#define infra_3 A3
#define infra_4 A4
#define infra_5 A5

void setup() {
   pinMode(infra_1,INPUT);
  pinMode(infra_2,INPUT);
  pinMode(infra_3,INPUT);
  pinMode(infra_4,INPUT);
  pinMode(infra_5,INPUT);
  pinMode(infra_0,INPUT);
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(infra_0));
   Serial.print("\t");
   Serial.print(digitalRead(infra_1) );
   Serial.print("\t");
   Serial.print(digitalRead(infra_2) );
   Serial.print("\t");
   Serial.print(digitalRead(infra_3) );
   Serial.print("\t");
   Serial.print(digitalRead(infra_4) );
   Serial.print("\t");
   Serial.println(digitalRead(infra_5) );

}
