int trig = 10;
int echo = 11;
int led[] = {5, 6, 7, 8, 9};
int m; int n; //정수형 변수로 출력되도록 하여 값의 변화가 없도록 한다.
int ave = 0; //평균값을 측정할 변수 ave
float result[3];
float a; float b; float c;
void setup() {
 Serial.begin(9600);
 pinMode(trig, OUTPUT);
 pinMode(echo,INPUT);
 for(int i = 0; i < 5; i++){
 pinMode(led[i], OUTPUT);
 }
}

void loop() {

 Serial.println("센서의 평균값을 측정중입니다 ...");
 for(int i = 0; i<3; i++){
   digitalWrite(trig,HIGH);  
   delayMicroseconds(10);
   digitalWrite(trig,LOW);
   result[i] = pulseIn(echo,HIGH);
   delay(1000);                //3초가량의 딜레이 시간을 줌
 }
 a = result[0] / 29 / 2;
 b = result[1] / 29 / 2;
 c = result[2] / 29 / 2;
 (a > b ? (a > c ? (m = a):(m = c)):(b > c ?(m = b): m = c));  //최소값과 최댓값 계산
 (a < b ? (a < c ? (n = a):(n = c)):(b < c ?(n = b): n = c));
 
 if( n >=190)
   Serial.println("error!");
 if( m - n < 5 ){          //값이 튀는것을 방지하기 위해 보낸 센서값 최댓값과 최솟값 차이가 
                                         //5센티 이상으로 차이가 날 경우 출력을 수행하지 않는다.
   ave = (a + b + c) /3;
   if(ave > 15 && ave<=25)          //길이 범위마다의 오차 평균값을 구해서 calibration 수행
     ave += 0.5;
   else if(ave > 25 && ave<=45)
     ave += 1;
   else if(ave > 45 && ave<=60)
     ave += 1.5;
   else if(ave > 60 && ave<=100)
     ave += 2;
   else if(ave > 100 && ave<=150)
     ave += 2.5;
   else if(ave > 150)
     ave += 3;
     
     Serial.print(ave);
     Serial.println("cm");
 }

 if(ave<15)
   digitalWrite(led[0],HIGH);
 else
   digitalWrite(led[0], LOW);
 if(ave<12)
   digitalWrite(led[1],HIGH);
 else
   digitalWrite(led[1], LOW);
 if(ave<9)
   digitalWrite(led[2],HIGH);
 else
   digitalWrite(led[2], LOW);
 if(ave<6)
   digitalWrite(led[3],HIGH);
 else
   digitalWrite(led[3], LOW);
 if(ave<3)
   digitalWrite(led[4],HIGH);
 else
   digitalWrite(led[4], LOW);
}
