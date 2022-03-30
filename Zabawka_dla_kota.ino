#include <Servo.h> 
#define Laser 7//deifniowanie laseru na pinie 7
#define Button 2// przycisk włacz wyłacz. Korzystamy z przerwania. W poźniejszej wersji przełączenie na różne tryby pracy
#define PIR 3 //czujnik ruchu
#define PIRled 4//zielony led informujacy o właczeniu trybu PIR
  
Servo SerwoY; //serwo poruszajace się w osi Y
Servo SerwoX; //serwo poruszajace się w osi X

unsigned long aktualnyCzas=0;
unsigned long zapamietanyCzasSerwoY=0;
unsigned long czestotliwoscSerwoY=300; //czestotliwosc przerwy dla Serwa Y
unsigned long zapamietanyCzasSerwoX=0;
unsigned long czestotliwoscSerwoX=100; //czestotliwosc przerwy dla Serwa X

int pozycjaSerwoY=0; //zapamietana pozycja serwo Y 0-90
int pozycjaSerwoX=0;//zapamietana pozycja serwo X 0-181
int losowaZmiana=0;//o jaka wartosc ma sie zmienic pozycja serwo
int zwrot=0;// zwrot lewo/prawo
int stanPracy=0; //informacja o trybie pracy urzadzenia

void setup() {
  Serial.begin(9600);
  SerwoY.attach(5); //Pin przypiecia serwa Y
  SerwoX.attach(6);//Pin przypiecia serwa X
  randomSeed(analogRead(A0)); //Ziarno z szumu na A0
  
  pinMode(Laser,OUTPUT); //Laser jako wyjście
  digitalWrite(Laser,LOW);// lasera

  pinMode(Button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Button), przerwanie, RISING); //Przerwanie na pinie Button 

  pinMode(PIR, INPUT);
  pinMode(PIRled, OUTPUT);

}

void loop() {
  SerwoX.detach();
 

           
}  
void przerwanie(){//funkcja przerwania
  stanPracy++; //zmiana parametru stanPracy
    if(stanPracy>3){//Zmienić na wiekszą wartosc w ramach jak dodam nowe stany
        stanPracy=0;
        delay(250);
          }
         }
