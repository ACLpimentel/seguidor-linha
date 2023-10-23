#include <HCSR04.h>
HCSR04 hc(3,2);

#define infra_0 A0
#define infra_1 A1
#define infra_2 A2
#define infra_3 A3
#define infra_4 A4
#define infra_5 A5
int infra[2];

#define in1 9
#define in2 8
#define in3 11
#define in4 10
#define mot_l 5
#define mot_r 6


float vel_l = 0x80;
float vel_r = 0x69;

float distancia;


void setup() {


  pinMode(in1 , OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3 , OUTPUT);
  pinMode(in4 , OUTPUT);
  pinMode(mot_l , OUTPUT);
  pinMode(mot_r , OUTPUT);

  pinMode(infra_1,INPUT);
  pinMode(infra_2,INPUT);
  pinMode(infra_3,INPUT);
  pinMode(infra_4,INPUT);
  pinMode(infra_5,INPUT);
  pinMode(infra_0,INPUT);


  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  distancia = hc.dist();

  infra[0] = digitalRead(infra_0);
  infra[1] = digitalRead(infra_1);
  infra[2] = digitalRead(infra_2);
  infra[3] = digitalRead(infra_3);
  infra[4] = digitalRead(infra_4);
  infra[5] = digitalRead(infra_5);

  

  if (infra[5] == 0 && infra[4] == 1 && infra[3] == 1 && infra[2] == 0 && infra[1] == 0 &&infra[0] == 0  )
  {
    Serial.println("curva leve esquerda");
    andar_esquerda(0.55);
  }
  else if ( infra[5] == 0 && infra[4] == 0 && infra[3] == 0 && infra[2] == 1 && infra[1] == 1 && infra[0] == 0 )
  {
     Serial.println("curva leve direita");
    andar_direita(0.55);
  }
  else if ( infra[5] == 1 && infra[4] == 1 && infra[3] == 0 && infra[2] == 0 && infra[1] == 0 && infra[0] == 0)
  {
     Serial.println("curva esquerda");
    andar_esquerda(0.35);
  }
  else if ( infra[5] == 0 && infra[4] == 0 && infra[3] == 0 && infra[2] == 0 && infra[1] == 1 && infra[0] == 1 )
  {
     Serial.println("curva leve direita");
    andar_direita(0.35);
  }
  else if (infra[5] == 0 && infra[4] == 0 && infra[3] == 1 && infra[2] == 1 && infra[1] == 0 && infra[0] == 0)
  {
    Serial.println("reto");
    andar_frente();
  }


  // put your main code here, to run repeatedly:

}

void andar_frente()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(mot_l, vel_l * 1);
  analogWrite(mot_l, vel_l * 0.75);
  analogWrite(mot_r, vel_r * 0.75);
}

void andar_esquerda(float velo)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(mot_l, vel_l);
  analogWrite(mot_l, vel_l * velo);
  analogWrite(mot_r, vel_r * 0.75);
}

void andar_direita(float velo)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(mot_l, vel_l);
  analogWrite(mot_l, vel_l * 0.75);
  analogWrite(mot_r, vel_r * velo);
}

