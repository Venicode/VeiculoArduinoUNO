//importando a biblioteca para utilizar o sensor ultrassonico
#include <Ultrasonic.h>

//trigger: sinal enviado
#define pino_trigger 4 
//echo: sinal retornado
#define pino_echo 5

//gravar no sensor os pinos definidos (trigger e echo)
Ultrasonic ultrasonic(pino_trigger,pino_echo);

/*criando as variaveis indicando em quais portas
estão conectadas na placa */
const int motorD =  5;
const int motorE = 6;

const int dirD = 7;
const int dirE = 8;

const int Sensor1 = 3;
const int valorSensor1 = 0;
const int Sensor2 = 4;
const int valorSensor2 = 0;

const int ledVerde = 13;
const int ledVermelho = 12;

//Configurações iniciais
void setup() {
  
    Serial.begin(9600);
    //Acender o led verde ao iniciar depois de 5 segundos
    pinMode(ledVerde, OUTPUT);
    delay(5000);
    digitalWrite(ledVerde,HIGH);

    //Configuração das portas onde estão os motores e os sentidos de rotação
    pinMode(motorD, OUTPUT);
    pinMode(motorE, OUTPUT);
    pinMode(dirD, OUTPUT);
    pinMode(dirE, OUTPUT);

}

void loop() {

    //ler a distancia do obstaculo em cm
    float distCm;
    long microsec = ultrasonic.timing();
    distCm = ultrasonic.convert(microsec, Ultrasonic::CM);

    //leitura dos sensores infravermelhos
    valorSensor1 = analogRead(Sensor1);
    valorSensor2 = analogRead(Sensor2);

    //validacoes para o carrinho seguir a linha branca
    if ((valorSensor1 < 700) && (valorSensor2 < 700)){
        analogWrite(motorD, 150);
        analogWrite(motorE, 150);
    }

    if ((valorSensor1 > 700) && (valorSensor2 < 700)){
        analogWrite(motorD, 0);
        analogWrite(motorE, 200);
    }

    if ((valorSensor1 < 700) && (valorSensor2 > 700)){
        analogWrite(motorD, 200);
        analogWrite(motorE, 0);
    }

    /*parar e acender o led vermelho ao identificar o obstáculo
    com 5cm de distancia */
    if (distCm <=5){
        analogWrite(motorD, 0);
        analogWrite(motorE, 0);
        pinMode(ledVermelhor, OUTPUT);
        digitalWrite(ledVermelho,HIGH);
    }
}

/*TO DO:
desviar do obstáculo
voltar ao curso em até 5 segundos
testes de bugs na linha branca */
