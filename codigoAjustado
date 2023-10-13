const int motorD =  5;
const int motorE = 6;
const int Sensor1 = A0;
const int Sensor2 = A1;
int valorSensor1 = 0;
int valorSensor2 = 0;

void setup() {
 pinMode(13, OUTPUT);
 delay(5000);
 digitalWrite(13,HIGH);
  
 pinMode(motorD, OUTPUT);
 pinMode(motorE, OUTPUT);
 
 pinMode(Sensor1, INPUT);
 pinMode(Sensor2, INPUT);
  
 Serial.begin(9600);
}

void loop() {
 digitalWrite(motorD, HIGH);
 digitalWrite(motorE, HIGH);
 valorSensor1 = analogRead(Sensor1);
 valorSensor2 = analogRead(Sensor2);
 Serial.print("Leitura do Sensor1: ");
 Serial.println(valorSensor1);
 Serial.print("Leitura do Sensor2: ");
 Serial.println(valorSensor2);
  
   if ((valorSensor1 > 900) && (valorSensor2 > 900)){
        digitalWrite(motorD, HIGH);
        digitalWrite(motorE, HIGH);
    }

    if ((valorSensor1 < 900) && (valorSensor2 > 900)){
        digitalWrite(motorD, LOW);
        digitalWrite(motorE, HIGH);
    }

    if ((valorSensor1 > 900) && (valorSensor2 < 900)){
        digitalWrite(motorD, HIGH);
        digitalWrite(motorE, LOW);
    }
  	
  	if ((valorSensor1 < 900) && (valorSensor2 < 900)){
        digitalWrite(motorD, LOW);
        digitalWrite(motorE, LOW);
    }
  
 delay(1000);
}
