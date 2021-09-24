unsigned long ardTime;
unsigned long timer1 = 0;
unsigned long timer2 = 0;
int stage1 = 0;
int stage2 = 0;
boolean revers1 = false;
boolean revers2 = false;
boolean switchLight = false;
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  Serial.begin(9600);
  light(switchLight,0,revers1);
  light(!switchLight,0,revers2);

  for(int i = 0; i<12;i++){
    pinMode(ledPins[i], OUTPUT);
  }
  
}
void loop() {
  ardTime = millis();
  //digitalWrite(13, LOW);
  if(ardTime-timer1>2000 && stage1 == 0){
    stage1++;
    timer1 = ardTime;
    light(switchLight,stage1, revers1);
  }
  else if(ardTime-timer1>2000 && stage1 == 1){
    stage1++;
    light(switchLight,stage1,revers1);
    timer1= ardTime;
  }
  else if(ardTime-timer1>7000 && stage1 == 2){
    stage1++;
    light(switchLight,stage1,revers1);
    timer1= ardTime;
  }
  else if(ardTime-timer1>3000&& stage1 == 3){
    stage1=0;
    light(switchLight,stage1,revers1);
    timer1= ardTime;
    revers1=!revers1;
  }

  if(ardTime-timer2>2000 && stage2 == 0){
    stage2++;
    timer2 = ardTime;
    light(!switchLight,stage2,revers2);
  }
  else if(ardTime-timer2>2000 && stage2 == 1){
    stage2++;
    light(!switchLight,stage2,revers2);
    timer2= ardTime;
  }
  else if(ardTime-timer2>5000 && stage2 == 2){
    stage2++;
    light(!switchLight,stage2,revers2);
    timer2= ardTime;
  }
  else if(ardTime-timer2>2000&& stage2 == 3){
    stage2=0;
    light(!switchLight,stage2,revers2);
    timer2= ardTime;
    revers2=!revers2;
  }

}

void light(boolean switchLight, int stage, boolean revers){

  int ledPin;

  switch(stage){
    case 0:
      RR(switchLight);
      break;
    case 1:
      RYR(switchLight,revers);
      break;
    case 2:
      RG(switchLight,revers);
      break;
    case 3:
      RY(switchLight,revers);
      break;
  }

}

void RR(boolean switchLight){
  int led =2;
  if(switchLight==true) led+=6;
  digitalWrite(led,HIGH);
  digitalWrite(led+1,LOW);
  digitalWrite(led+3,HIGH);
  digitalWrite(led+4,LOW);
}

void RYR(boolean switchLight,boolean lastLight){
  int led =3;
  if(switchLight)led+=6;
  if(lastLight)led+=3;
  digitalWrite(led,HIGH);
}

void RG(boolean switchLight,boolean lastLight){
  int led = 4;
  if(switchLight)led+=6;
  if(lastLight)led+=3;
  digitalWrite(led,HIGH);
  digitalWrite(led-1,LOW);
  digitalWrite(led-2,LOW);
}

void RY(boolean switchLight,boolean lastLight){
  int led =3;
  if(switchLight)led+=6;
  if(lastLight)led+=3;
  digitalWrite(led,HIGH);
  digitalWrite(led+1,LOW);
}
