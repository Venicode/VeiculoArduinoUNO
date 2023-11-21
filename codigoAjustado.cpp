//Declaração de variáveis de acordo com as portas que estão conectadas
#define trigger 8
#define echo 9

#define motorD 6
#define motorE 5

#define Sensor1 A1
#define Sensor2 A2

#define ledVerde 1
#define ledVermelho 11

//Porta para acelerar os motores
int acelerar = 3;

/*Declarando as variaveis que irão armazenar valores 
de acordo com a leitura dos sensores */
int valorSensor1 = 0;
int valorSensor2 = 0;
int duracao = 0;
int distancia = 0;
int velocidade = 150;

//Configurações iniciais
//O input significa que o valor será obtido a partir da leitura, usado para os sensores.
//O Output significa que as variaveis irão apenas retornar um valor, sem obter nada do externo.
void setup() {
 pinMode(ledVermelho, OUTPUT);
 pinMode(ledVerde, OUTPUT);
 delay(5000);
  
 pinMode(motorD, OUTPUT);
 pinMode(motorE, OUTPUT);
  
 pinMode(acelerar, OUTPUT);
 
 pinMode(Sensor1, INPUT);
 pinMode(Sensor2, INPUT);
  
 pinMode(trigger, OUTPUT);
 pinMode(echo, INPUT);

 //é usado para definir uma frequencia dos dados expostos no print (9600).
 Serial.begin(9600); 
}

void loop() {
  //Leitura dos valores dos sensores infravermelhos
  valorSensor1 = analogRead(Sensor1);
  valorSensor2 = analogRead(Sensor2);

  //Exibição dos dados no prompt da IDE
  Serial.print("Leitura do Sensor1: ");
  Serial.println(valorSensor1);
  Serial.print("Leitura do Sensor2: ");
  Serial.println(valorSensor2);

  //O trigger emite o pulso de onda a cada 10 microssegundos
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  //O echo recebe o pulso retornado e armazena da duracao
  duracao = pulseIn(echo, HIGH);
  //Calculo para encontrar a distância, o valor fixo é definido pelo cálculo da velocidade da onda ultrassônica
  distancia = duracao*0.017175;

/*Os sensores infravermelhos retornam valores dependendo da luz refletida.
Se for branco, retorna menos de 900. Se for preto, retorna superior. */
if (distancia>5){ 
   digitalWrite(ledVerde,HIGH);
   digitalWrite(ledVermelho, LOW);
   digitalWrite(acelerar, HIGH);
  
  
 if ((valorSensor1 > 900) && (valorSensor2 > 900)){
     analogWrite(motorD, velocidade);
     analogWrite(motorE, velocidade);
   	
 }
 
 if ((valorSensor1 < 900) && (valorSensor2 > 900)){
     analogWrite(motorD, 0);
     analogWrite(motorE, velocidade);
 }
 
 if ((valorSensor1 > 900) && (valorSensor2 < 900)){
     analogWrite(motorD, velocidade);
     analogWrite(motorE, 0);
 }
    
else {
     analogWrite(motorD, 0);
     analogWrite(motorE, 0);
 }
} 
else {
  	Serial.println("Objeto detectado");
  	digitalWrite(ledVerde, LOW);
  	digitalWrite(ledVermelho, HIGH);
  	digitalWrite(acelerar, LOW);
    analogWrite(motorD, 0);
    analogWrite(motorE, 0);
 }
}
