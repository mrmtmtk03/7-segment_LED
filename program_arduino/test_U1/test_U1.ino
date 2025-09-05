#include <MsTimer2.h>
#define pin_A 13
#define pin_B 12
#define pin_C 11
#define pin_D 10
#define pin_dot 9
#define VDD 8
#define U1 7
#define U2 6
#define U3 5
#define U4 4
#define DT 2    // ダイナミック点灯の間隔(ms)

// 関数のプロトタイプ宣言
void initinal_pins();
void TruthTable(int num,int unit);
void display4();

// グローバル変数定義
int display_num=0000;     // 0から9999までの整数
int display_array[4]={0};
int display_input[4][4]={0};

void setup() {
  Serial.begin(9600);
  initinal_pins();
  Serial.print("SYSTEM START!!!\n");
  // タイマー割り込みを開始
  MsTimer2::set(1000, digitToDisplayData);
  MsTimer2::start();
}

void loop() {
  display4();
}

void digitToDisplayData(){
  display_num++;
  if(display_num<0 && display_num>9999){
    display_num=0;
  }
  // display_numを各桁の要素に分解
  display_array[0]=display_num/1000;
  display_array[1]=(display_num/100)%10;
  display_array[2]=(display_num/10)%10;
  display_array[3]=display_num%10;
  // 真理値表に代入
  TruthTable(display_array[0],1);
  TruthTable(display_array[1],2);
  TruthTable(display_array[2],3);
  TruthTable(display_array[3],4);
}

void display4(){
  // ユニット1
  digitalWrite(U1,LOW);
  digitalWrite(pin_A,display_input[0][0]);
  digitalWrite(pin_B,display_input[0][1]);
  digitalWrite(pin_C,display_input[0][2]);
  digitalWrite(pin_D,display_input[0][3]);
  delay(DT);
  digitalWrite(U1,HIGH);
  // ユニット2
  digitalWrite(U2,LOW);
  digitalWrite(pin_A,display_input[1][0]);
  digitalWrite(pin_B,display_input[1][1]);
  digitalWrite(pin_C,display_input[1][2]);
  digitalWrite(pin_D,display_input[1][3]);
  delay(DT);
  digitalWrite(U2,HIGH);
  // ユニット3
  digitalWrite(U3,LOW);
  digitalWrite(pin_A,display_input[2][0]);
  digitalWrite(pin_B,display_input[2][1]);
  digitalWrite(pin_C,display_input[2][2]);
  digitalWrite(pin_D,display_input[2][3]);
  delay(DT);
  digitalWrite(U3,HIGH);
  // ユニット4
  digitalWrite(U4,LOW);
  digitalWrite(pin_A,display_input[3][0]);
  digitalWrite(pin_B,display_input[3][1]);
  digitalWrite(pin_C,display_input[3][2]);
  digitalWrite(pin_D,display_input[3][3]);
  delay(DT);
  digitalWrite(U4,HIGH);
}

void TruthTable(int num,int unit){
  if(num%2==0){
    display_input[unit-1][0]=0;
  }
  else{
    display_input[unit-1][0]=1;
  }
  if(num%4<2){
    display_input[unit-1][1]=0;
  }
  else{
    display_input[unit-1][1]=1;
  }
  if(num%8<4){
    display_input[unit-1][2]=0;
  }
  else{
    display_input[unit-1][2]=1;
  }
   if(num<8){
    display_input[unit-1][3]=0;
  }
  else{
    display_input[unit-1][3]=1;
  }
}

void initinal_pins(){
  pinMode(pin_A,OUTPUT);
  pinMode(pin_B,OUTPUT);
  pinMode(pin_C,OUTPUT);
  pinMode(pin_D,OUTPUT);
  pinMode(pin_dot,OUTPUT);
  pinMode(VDD,OUTPUT);
  pinMode(U1,OUTPUT);
  pinMode(U2,OUTPUT);
  pinMode(U3,OUTPUT);
  pinMode(U4,OUTPUT);
  digitalWrite(pin_A,LOW);
  digitalWrite(pin_B,LOW);
  digitalWrite(pin_C,LOW);
  digitalWrite(pin_D,LOW);
  digitalWrite(pin_dot,LOW);
  digitalWrite(VDD,HIGH);
  digitalWrite(U1,HIGH);
  digitalWrite(U2,HIGH);
  digitalWrite(U3,HIGH);
  digitalWrite(U4,HIGH);
}
