//Declaração de variáveis de acordo com as portas que estão conectadas
#define trigger 12
#define echo 11

#define motorD 5
#define motorE 6
#define dirD 7
#define dirE 8

#define Sensor1 A0
#define Sensor2 A1

#define ledVerde 13
#define ledVermelho 10

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

 pinMode(dirD, OUTPUT);
 pinMode(dirE, OUTPUT);
 
 pinMode(Sensor1, INPUT);
 pinMode(Sensor2, INPUT);
  
 pinMode(trigger, OUTPUT);
 pinMode(echo, INPUT);

 //Configuramos as direções dos motores como 0 ou LOW, para o carrinho seguir para frente inicialmente
 digitalWrite(dirD, HIGH);
 digitalWrite(dirE, HIGH);
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
  
 if ((valorSensor1 > 900) && (valorSensor2 > 900)){
     digitalWrite(motorD, velocidade);
     digitalWrite(motorE, velocidade);
 }
 
 if ((valorSensor1 < 900) && (valorSensor2 > 900)){
     digitalWrite(motorD, 0);
     digitalWrite(motorE, velocidade);
 }
 
 if ((valorSensor1 > 900) && (valorSensor2 < 900)){
     digitalWrite(motorD, velocidade);
     digitalWrite(motorE, 0);
 }
    
}
/*O if acima verifica se a distância é superior a 5cm. 
Caso for igual ou inferior, irá executar o comando do else*/
else {
   Serial.println("Objeto detectado");
   digitalWrite(ledVerde, LOW);
   digitalWrite(ledVermelho, HIGH);
   digitalWrite(motorD, 0);
   digitalWrite(motorE, 0);
   delay(5000);
   digitalWrite(motorD, velocidade);
   digitalWrite(motorE, 0);
   delay(2000);
   }
}
