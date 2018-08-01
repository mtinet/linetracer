const int SensorLeft = A0;
const int SensorRight = A1;   
int SL;    //Left Line Follower
int SR;    //Right Line Follower

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  
  pinMode(SensorLeft, INPUT);
  pinMode(SensorRight, INPUT);
  Serial.begin(9600); 
}

void loop() {
  while(1){
    SL = analogRead(SensorLeft);
    SR = analogRead(SensorRight);

    if (SL < 500 && SR < 500) {
      bothMotorStart();  
    } else if (SL > 500 & SR < 500) {
      turnRight();  
    } else if (SL < 500 & SR > 500) {
      turnLeft();        
    } else {
      stopAllMotor();
    }
  }
}

void bothMotorStart() {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    Serial.println("Forward");
}

void bothMotorBack() {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    }

 
//모터A,B Stop
void stopAllMotor(){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A 역회전, 모터B 정회전
void turnLeft(){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    Serial.println("Turn Left");
}
 
//모터A 정회전, 모터B 역회전
void turnRight(){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    Serial.println("Turn Right");
}
 
//모터A 정회전, 모터B Stop
void motorA_Rotation(){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A Stop, 모터B 정회전
void motorB_Rotation()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    Serial.println("STOP");
}
 
//모터A 역회전, 모터B Stop
void motorA_Reverse(){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A Stop, 모터B 역회전
void motorB_Reverse() {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}
