int duracao = 0;
int distancia = 0;

float trigger = 12;
float echo = 11;

const int motorD =  5;
const int motorE = 6;
const int Sensor1 = A0;
const int Sensor2 = A1;

int valorSensor1 = 0;
int valorSensor2 = 0;

const int ledVerde = 13;

void setup() {
 pinMode(ledVerde, OUTPUT);
 delay(5000);
 digitalWrite(ledVerde,HIGH);
  
 pinMode(motorD, OUTPUT);
 pinMode(motorE, OUTPUT);
 
 pinMode(Sensor1, INPUT);
 pinMode(Sensor2, INPUT);
  
 pinMode(trigger, OUTPUT);
 pinMode(echo, INPUT);
  
 Serial.begin(9600);
}

void loop() {
  
  digitalWrite(motorD, HIGH);
  digitalWrite(motorE, HIGH);
  valorSensor1 = analogRead(Sensor1);
  valorSensor2 = analogRead(Sensor2);
  
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  duracao = pulseIn(echo, HIGH);
  distancia = duracao*0.017175;
  
if (distancia>5){
 
 if ((valorSensor1 > 900) && (valorSensor2 > 900)){
     digitalWrite(motorD, HIGH);
     digitalWrite(motorE, HIGH);
 }
 
 else if ((valorSensor1 < 900) && (valorSensor2 > 900)){
     digitalWrite(motorD, LOW);
     digitalWrite(motorE, HIGH);
 }
 
 else if ((valorSensor1 > 900) && (valorSensor2 < 900)){
     digitalWrite(motorD, HIGH);
     digitalWrite(motorE, LOW);
 }
  	
 else {
     digitalWrite(motorD, LOW);
     digitalWrite(motorE, LOW);
 }
} 
else {
    digitalWrite(motorD, LOW);
    digitalWrite(motorE, LOW);
    Serial.println("Objeto detectado");
 }
}
