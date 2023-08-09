#define message "SOT_Master_tester_v5.6  28/JUL/2023 8/AUG"

// WITH SWITCHER of 5 GADGETS"

#include <Wire.h>
#include "PCF8574.h"            // expansions x4
#include <LiquidCrystal_I2C.h>  // i2c 16x2 LCD display 
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 0x27, 0x3F

#include <DFPlayerMini_Fast.h>

#define RSTXCNTRL 9
#define REPIN     13 //32 is used as an output


//------------------
#define SPIKE     0
#define BEES      1
#define GATOR     2
#define EGG       3
#define LOG       4
#define FROGS     5
//------------------
#define DEER      6
#define TRACK8    7
#define BANJOS    8
#define CLOSET    9
#define ANIMAL    10
//------------------
#define BED       11
#define BABY      12
#define BLOCKS    13
#define WHEEL     14
#define SSHOT     15
#define FUSE      16
//------------------
#define CALL911   17
//------------------
#define RV_SINK   18
#define RV_FAN    19
#define RV_AC     20
#define RV_CAN    21
#define RV_MICRO  22
//------------------
#define BREAKER   23
//------------------

#define GCOUNT    24

DFPlayerMini_Fast MP3A;
DFPlayerMini_Fast MP3B;

PCF8574 relay20(0x20);
PCF8574 relay24(0x24);
PCF8574 relay22(0x22);
PCF8574 relay23(0x26);

byte led      = A7;
byte players  = 0;
int  input    = 0;
int  incomingByte;

// ADD INPUTS    ---main board----        -----expansion-----
byte ins[12]  = { 2, 3, 4, 5, 6, 7,       22, 24, 26, 28, 30, 32 };

//   !!!  pin 6 is shorted !!!

byte StartBut  = 2;  // Start Button   // scary_mode mode // boy
byte StartBut2 = 3;  // Start2 Button  // norm mode  // girl

byte logIn    = 28;  // signal from log sensor
byte deerEye  = 32; // deer eye

// signals from RV
byte RVsink   = 4;
byte RVfan    = 5;
byte RVair    = 7;
byte RVcan    = 22;
byte RVmic    = 24;
byte RVbrk    = 26;
bool RVDone = false;

byte stepSen  = 30;
bool chairDONE = false;

// ADD OUTPUTS   --main board--               ---------expansion--------
byte out[15]  = { 8, 10, 11, 12,      34, 34, 36, 38, 40, 42, 44, 46 , 48 , 50, 52 };

// JUNE/2023
byte aircomp  = 44;
byte sunCtrl  = 46;
byte shadowL  = 52;

byte RVstrobe = 8;
byte RVknock  = 10;

//  gadgets - PROPS
//               A   B    C    D    E    F    G    H   I   J   K    L   M   N   O   P
byte insA[16] = { A8, A9, A10, A11, A12, A13, A14, A15, 53, 51, 49, 47, 31, 29, 27, 25 };
byte outA[16] = { A0, A1, A2,  A3,   A4,  A5,  A6,  15, 45, 43, 41,  6, 37, 35, 33, 14 }; // 39 = 6

byte propAin  = A8;  //  (B-13) BEEHIVE
byte propAout = A0;

byte propBin  = A9;  //  (   ) SLINGSHOT
byte propBout = A1;

byte propCin  = A10;  // (B-7) ANIMAL TROLLEY
byte propCout = A2;

byte propDin  = A11;  // (B-18) FROGS / planter
byte propDout = A3;

byte propEin  = A12;  // (B-10) 8TRACK - radio
byte propEout = A4;

byte propFin  = A13;   // (B-2) BED - BABY
byte propFout = A5;

byte propGin  = A14;  // (B-9) BANJO
byte propGout = A6;

byte propHin  = A15;  // Gator Bowl [pike-gator-log]

byte propIin  = 53;   // (NEST) BIRD / NEST
byte propIout = 45;

byte propJin  = 51;   // (B-16 gator )PIKE [pike-gator-log] ( LOG )
byte propJout = 43;

byte propKin  = 49;   // (N/A)CLOSET
byte propKout = 41;

byte propLin  = 47;   // (B-4) BLOCKS
byte propLout = 39;

byte propMin  = 31;   // RV(1) - Y
byte propMout = 37;   // RV(1) - BL

byte propNin  = 29;   // empty
byte propNout = 35;   //

byte propOin  = 27;   //
byte propOout = 33;   // not used - empty - damaged

byte propPin  = 25;   // empty

byte level = 0;
int gameTime = 0;
byte start_level = 0;
byte gadget_states[GCOUNT];  // States: 0 (wait) :: 1 (passed\skip)->(first command) :TIMER1: 2 (second command) :TIMER2: 3 (done\wait else skip)
boolean capsule_addons[2] = {false, false};
boolean game = false;
boolean Point = false;
//boolean drips = false;
boolean bridgeConnected = false;
boolean oper_skips[GCOUNT];
boolean start_btn_states[2] = { false, false };
boolean start_btn2_states[2] = { false, false };
unsigned long lastSyncTime = 0;
unsigned long startTimer = 0;
unsigned long gameOver = 0;
//unsigned long gate_empty_start = 0;
//unsigned long motor_start = 0;
long          start_delay = 0;
//unsigned long capsule3_start = 0;
//boolean       capMvState = false;
//unsigned long capMvStart = 0;
unsigned long pass_times[GCOUNT];
//                                   head  bee  gator bird  log   frogs  deer  8track banjo close anim bed   baby  block wheel sling fuse  911     sink  fan   a/c    can   mw    breakr
//                                      0    1     2     3     4    5      6      7     8     9    10    11    12    13     14     15    16    17    18    19    20    21    22    23 ||
unsigned int post_delays1[GCOUNT] = { 100, 501, 1102,  103, 4104, 105,   106,  2007, 1008, 1009, 2110,  111, 1012,  113,  1114,  1015, 1116,  517,  3118, 1119,  220,  221, 222,   23 };
unsigned int post_delays2[GCOUNT] = {3100, 501, 3102, 2103, 4104, 105,   106,  2007, 1008, 2109,   10,  111, 4012, 1313,  1114,  1115, 1116,  317, 10618, 1119, 3120,  2221,  222, 23 };
unsigned int done_starts[GCOUNT];
bool         done[GCOUNT];

int  rev = 0;
long howLong = 0;

bool TestMode = false;
bool debug = false;
bool ahora = false;

//bool shockSound = false;

long nextEvent;
byte nivel  = 0;


bool CatDone  = false;
bool MapDone  = false;
bool TextDone = false;
bool BoxDone  = false;
bool TimeIsOn = false;
bool gatorDONE = false;

bool TheEND   = false;
bool gameStarted = false;

bool scary_mode = false;    // true if started with red button (StartBut) , false if started with green button (StartBut2)

bool headFalled = false;   // to know if head if rolled out already

bool girl = false;

void setup() {

  Serial.begin(9600);
  Serial1.begin(38400);  // RS
  Serial2.begin(9600);
  Serial3.begin(9600);
  Serial.println(message);

  MP3A.begin(Serial2, false);
  MP3B.begin(Serial3, false);

  delay(100);
  MP3A.volume(26);
  delay(100);
  MP3B.volume(29);
  delay(100);
  MP3A.stop(); // soundtrack
  //MP3A.play(7);
  delay(100);
  //MP3B.play(1);
  MP3B.stop(); // effetcs

  pinMode(RSTXCNTRL, OUTPUT);
  pinMode(REPIN, OUTPUT);
  digitalWrite(REPIN, LOW);
  digitalWrite(RSTXCNTRL, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SOT v5.4  28/JUL ");
  lcd.setCursor(0, 1);
  lcd.print(" Setup Complete ");

  pinMode(led, OUTPUT);

  Serial.print("Init relay20...");
  if (relay20.begin()) Serial.println("OK ");
  else Serial.println("--");

  Serial.print("Init relay24...");
  if (relay24.begin()) Serial.println("OK");
  else Serial.println("--");

  Serial.print("Init relay22...");
  if (relay22.begin()) Serial.println("OK");
  else Serial.println("--");

  Serial.print("Init relay23...");
  if (relay23.begin()) Serial.println("OK");
  else Serial.println("--");

  for (int x = 0; x < 12; x++) {  // optional INPUTS on MAINBOARD  {
    pinMode(ins[x], INPUT_PULLUP);
  }

  for (int x = 0; x < 15; x++) {  // optional OUTPUTS on MAINBOARD  {
    pinMode(out[x], OUTPUT);
    digitalWrite(out[x], LOW);
  }

  for (int x = 0; x < 16; x++)  // PROPS INs and OUTs
  {
    pinMode(insA[x], INPUT_PULLUP);
    pinMode(outA[x], OUTPUT);
    digitalWrite(outA[x], LOW);
  }


  //---------TESTS BEGIN------------

  // Serial.println("testBeforA runing");
  //  while(true) {
  //    testBeforeA();
  //  }


   //while(true){
  //  if ( !digitalRead(propPin)) digitalWrite(mirrorRT, HIGH); else digitalWrite(mirrorRT,LOW);
  //}

  //-------TESTS END ---------------

  Serial.print("Setup DONE. \n");

  if (digitalRead(StartBut) == LOW) {
    delay(700);
   // MP3A.play(5);
    while (digitalRead(StartBut) == LOW) {
      delay(100);
    }
    debug = true;
    Serial.println("\nDebug MODE activated\n");
  }

  //  testBefore();

  digitalWrite(12, HIGH); //light control ssr DC relay
  digitalWrite(sunCtrl, HIGH); //Sun control ssr AC relay

  connectToBridge();  //TURN OFF TO DEBUG !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//  MP3B.play(2);

  relay23.write(6, LOW);  // egg OPEN
  delay(200);
  relay23.write(7, LOW);  // floor UP
  delay(200);
  relay24.write(7, HIGH);  //  BIRD LOAD (LOW = UP) 
  relay24.write(0, LOW);   // BIRD LOAD (LOW = DOWN)

  //  testAfter();

  Serial.print("Ready. \n");

}  //eof_setup



void readKey() {
  while (digitalRead(StartBut) == HIGH) {
    if (digitalRead(StartBut) == LOW) {
      while (digitalRead(StartBut) == LOW) {
        Serial.println("start");
        delay(100);
      }
    }
  }
}


// formely loopX (loop for test only)
void loopX() {

  if (digitalRead(led) == LOW) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);

  // readKey();

  for (int w = 0; w < 16; w++)  //PROPS
  {
    if (digitalRead(insA[w]) == LOW ) {
      if (done[w] == false) {
        done[w] = true;
        lcd.setCursor(w, 1);
        lcd.print("X");
        delay(100);
        //      MP3A.play(w + 1); //tell the input number
        delay(1000);
        Serial.println(w);
        Serial.println("from prop " + String(w) + " pin # " + String(insA[w]));
      } else {
        lcd.setCursor(w, 1);
        lcd.print("O");
      }
    }

  }
  /*
    if (w < 6 && digitalRead(ins[w]) == LOW) {
      digitalWrite(led, HIGH);
      Serial.println("from IN " + String(w) + " pin # " + String(ins[w]));
      delay(500);
    }
  */

  /*
        if (digitalRead(insA[t]) == LOW ) {
          digitalWrite(led, HIGH);
          Serial.println("from PROP " + String(t) + " pin # " + String(insA[t]));
          digitalWrite(outA[t], HIGH);
          delay(500);
          digitalWrite(outA[t], LOW);
          delay(100);
        }
  */

  delay(100);
}  // eof_loopX
