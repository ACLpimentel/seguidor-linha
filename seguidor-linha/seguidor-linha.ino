#include <HCSR04.h>
HCSR04 hc(3,2);

#define infra_0 A0
#define infra_1 A1
#define infra_2 A2
#define infra_3 A3
#define infra_4 A4
#define infra_5 A5
int infra[6];

#define in1 9
#define in2 8
#define in3 11
#define in4 10
#define mot_l 5
#define mot_r 6

int turn = 1270;

float vel_l = 0x80;
float vel_r = 0x65;

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

  if (distancia < 8)
  {
    contornar();
  }

  if (infra[5] == 0 && infra[4] == 1 &&  infra[1] == 0 &&infra[0] == 0  )
  {
    Serial.println("curva leve esquerda");
    andar(0.55, 0.8);
  }
  else if ( infra[5] == 0 && infra[4] == 0 && infra[1] == 1 && infra[0] == 0 )
  {
     Serial.println("curva leve direita");
    andar(0.8, 0.55);
  }
  else if ( infra[5] == 1 && infra[4] == 1 && infra[1] == 0 && infra[0] == 0)
  {
     Serial.println("curva esquerda");
    andar(0.35, 0.8);
  }
  else if ( infra[5] == 0 && infra[4] == 0 && infra[1] == 1 && infra[0] == 1 )
  {
     Serial.println("curva leve direita");
    andar(0.8 , 0.35);
  }
  else if (infra[5] == 0 && infra[4] == 0 && infra[1] == 0 && infra[0] == 0)
  {
    Serial.println("reto");
    andar(0.8, 0.8);
  }


  // put your main code here, to run repeatedly:

}


void andar(float velo1, float velo2)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(mot_l, vel_l);
  analogWrite(mot_l, vel_l * velo1);
  analogWrite(mot_r, vel_r * velo2);
}



void contornar()
{
  int cont = 0;
  do 
  {
   andar(0.0 , 0.6) ;
   delay(turn);
   andar(0.6, 0.6);
   delay(2500);
   andar(0.6 , 0.0);
   delay(turn);

   cont++;

  distancia = hc.dist();
  }while (distancia < 8 );
   
    andar(0.6, 0.6);
   delay(2500);
   andar(0.6 , 0.0);
   delay(turn);

  do 
  {
   
   andar(0.0 , 0.6) ;
   delay(turn);
   andar(0.6,0.6);
   delay(2500);
   andar(0.6 , 0.0);

   cont++;

  distancia = hc.dist();
  }while (distancia < 8 );

  andar(0.6 , 0.6);
  delay(2500 * cont);
  andar(0.0 , 0.6);

}

