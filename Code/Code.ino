 int r1 = 11; int r2 = 6;                                // LED R
int g1 = 10; int g2 = 5;                                // LED G
int b1 = 9; int b2 = 3;                                 // LED B
int buttonR = 47; int buttonG = 45; int buttonB = 43;   // Button RGB
int buttonPattern = 41;                                 // contol
int buttonReset = 35;                                   // 설정 값 초기화
int buttonUp = 39; int buttonDown = 37;                 // 속도 조절
int r = 0; int g = 0; int b = 0;                        // rgb 초기값
int c = 1000;                     // delay 초기값 = 1초                       
int count = 1;                                          // 패턴 번호

float sin_red;
float sin_green;
float sin_blue;
float x = 0;

void setup(){
  pinMode(r1,OUTPUT); pinMode(r2, OUTPUT);
  pinMode(g1,OUTPUT); pinMode(g2, OUTPUT);
  pinMode(b1,OUTPUT); pinMode(b2,OUTPUT);
  pinMode(buttonUp, INPUT); pinMode(buttonDown, INPUT);
  pinMode(buttonR, INPUT); pinMode(buttonG, INPUT); pinMode(buttonB, INPUT);
  pinMode(buttonPattern, INPUT);
  pinMode(buttonReset,INPUT);
}
void loop(){
  int stateR = digitalRead(buttonR);
  int stateG = digitalRead(buttonG);
  int stateB = digitalRead(buttonB);
  int statePattern = digitalRead(buttonPattern);
  int stateReset = digitalRead(buttonReset);
  int stateUp = digitalRead(buttonUp);
  int stateDown = digitalRead(buttonDown);
// 색 및 밝기 조절
if(count == 7)
count = 1;
  if(stateR == 0){
    r += 17;
    if( r >= 255) r = 0;
    delay(400);
  }
  else if(stateG == 0){
    g += 17;
    if( g >= 255) g = 0;
    delay(400);
  }
  else if(stateB == 0){
    b += 17;
    if( b>=255) b = 0;
    delay(400);
  } 
  
// 패턴 (count 변수)
  if(statePattern == 0){
    count ++;
    if(count == 7) count = 1;
    delay(400);
  }
  if(stateReset == 0){
    Reset();
  }

  if(stateDown == 0){
    c += 250;
    delay(400);
  }
  if(stateUp == 0){
    c -= 250;
    if(c < 100) c = 100 ;
    delay(400);
  }   

  if(count == 1)
    RGB1(r,g,b);

  else if(count == 2)
    RGB2(r,g,b,c);

  else if (count == 3)
    RGB3( c);
    
  else if (count == 4)
    RGB4(c);
    
  else if (count == 5)
    RGB5( c);
    
  else if (count== 6)
   RGB6();
}

void RGB1(int r, int g, int b){
  analogWrite(r1, r); analogWrite(r2,r);  
  analogWrite(g1, g); analogWrite(g2,g); 
  analogWrite(b1, b); analogWrite(b2,b);
}
void RGB2(int r, int g, int b, int c){
    
    analogWrite(r1, r); analogWrite(r2,r);  
    analogWrite(g1, g); analogWrite(g2,g); 
    analogWrite(b1, b); analogWrite(b2,b);
   
    if(digitalRead(buttonUp) == 0){
      c -= 250;
    if(c < 100) c = 100 ;
    delay(400);
    }
    
    if(digitalRead(buttonDown) == 0){
      c += 250;
    delay(400);
    }
      delay(c);
    digitalWrite(r1,LOW);digitalWrite(r2,LOW);
    digitalWrite(g1,LOW);digitalWrite(g2,LOW);
    digitalWrite(b1,LOW);digitalWrite(b2,LOW);
    delay(c);
}

void RGB3(int c){
      analogWrite(r1, random(255)); analogWrite(r2,random(255));  
      analogWrite(g1, random(255)); analogWrite(g2,random(255)); 
      analogWrite(b1, random(255)); analogWrite(b2,random(255));
      delay(c);
}

void RGB4(int c){
  
      for(int i=0; i<254; i++){
        analogWrite(r1,i);
        delay(1);
      }
    
   
   //  delay(c);
      
      for(int i=0; i<254; i++){
        analogWrite(g1, i);
        delay(1); 
      }
     
      
      for(int i=0; i<254; i++){
        analogWrite(b1, i);
        delay(1);
      }
      
      for(int  i=0; i<254; i++){
        analogWrite(r2,i);
        delay(1);
      }
   
      
      for(int i=0; i<254; i++){
        analogWrite(g2,i);
        delay(1);
      }
      
      
      for(int i=0; i<254; i++){
        analogWrite(b2,i);
        delay(1);
      }
      
}
void RGB5(int c){
  
    analogWrite(r1, 255); analogWrite(r2,255);  
    analogWrite(g1,0); analogWrite(g2,0); 
    analogWrite(b1, 0); analogWrite(b2,0);
    
    if(digitalRead(buttonReset) == 0)
      Reset();
    delay(c);
      
    analogWrite(r1, 255); analogWrite(r2,255);  
    analogWrite(g1,112); analogWrite(g2,112); 
    analogWrite(b1, 18); analogWrite(b2,18);
    
    if(digitalRead(buttonReset) == 0)
      Reset();
    delay(c);
    
    analogWrite(r1, 255); analogWrite(r2,255);  
    analogWrite(g1,255); analogWrite(g2,255); 
    analogWrite(b1, 36); analogWrite(b2,36);
    if(digitalRead(buttonReset) == 0)
      Reset();
    delay(c);
    
    analogWrite(r1, 0); analogWrite(r2,0);  
    analogWrite(g1,255); analogWrite(g2,255); 
    analogWrite(b1, 0); analogWrite(b2,0);
    if(digitalRead(buttonReset) == 0)
      Reset();
   delay(c);
   
    analogWrite(r1, 0); analogWrite(r2,0);  
    analogWrite(g1,51); analogWrite(g2,51); 
    analogWrite(b1, 153); analogWrite(b2,153);
    if(digitalRead(buttonReset) == 0)
      Reset();
    delay(c);
    
    analogWrite(r1, 0); analogWrite(r2,0);  
    analogWrite(g1,0); analogWrite(g2,0); 
    analogWrite(b1, 255); analogWrite(b2,255);
    if(digitalRead(buttonReset) == 0)
      Reset();
    delay(c);
    
    analogWrite(r1, 164); analogWrite(r2,164);  
    analogWrite(g1,102); analogWrite(g2,102); 
    analogWrite(b1, 255); analogWrite(b2,255);
    if(digitalRead(buttonReset) == 0)
      Reset();
    delay(c);
  }

 void RGB6(){
    if (x >= 0 && x < 255) {
        x += 0.00001;
        sin_red = 255 * abs(sin(x * (180 / 3.14))); 
        sin_green = 255 * abs(sin((x + 3.14 / 3) * (180 / 3.14))); 
        sin_blue = 255 * abs(sin((x + (2 * 3.14) / 3) * (180 / 3.14))); 
        analogWrite(r1, sin_red);analogWrite(r2, sin_red);
        analogWrite(g1, sin_green);analogWrite(g2, sin_green);
        analogWrite(b1, sin_blue);analogWrite(b2, sin_blue);
        delay(1);

      }
    }
  
  void Reset(){
    r = 0; g = 0; b = 0;
    c = 1000;
    count = 1;
    delay(400);
  }
