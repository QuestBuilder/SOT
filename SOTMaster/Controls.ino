/*
void roomSound(byte wich) {

  //  room 4
  //  digitalWrite(spkONE,HIGH);
  //  digitalWrite(spkTWO,HIGH);

  //  room 3
  //  digitalWrite(spkONE,LOW);
  //  digitalWrite(spkTWO,LOW);

  //  room 1 & 2
  //  digitalWrite(spkONE,HIGH);
  //  digitalWrite(spkTWO,LOW);

  //  room 3 & 4
  //  digitalWrite(spkONE,LOW);
  //  digitalWrite(spkTWO,HIGH);

  if (wich == 1) { //rooms 1 AND 2
    digitalWrite(spkONE, HIGH);
    digitalWrite(spkTWO, LOW);
  }
  if (wich == 2) { //  rooms 3 and 4
    digitalWrite(spkONE, LOW);
    digitalWrite(spkTWO, HIGH);
  }

  if (wich == 3) { //  room 3
    digitalWrite(spkONE, LOW);
    digitalWrite(spkTWO, LOW);
  }

  if (wich == 4 ) { //last room only
    digitalWrite(spkONE, HIGH);
    digitalWrite(spkTWO, HIGH);
  }
}

*/

void lockALL() {

  Serial.println("Closing...");
  lcd.setCursor(0, 0);
  lcd.print("    Closing...   ");

digitalWrite(RVknock, HIGH);


  digitalWrite(aircomp, HIGH);

  relay20.write(0, LOW);   // Animal DOOR
  delay(111);
  relay20.write(1, LOW);   // BED
  delay(111);
  relay20.write(2, HIGH);   // GATOR air valve
  delay(111);
  relay20.write(3, LOW);   // CLOCK -time to die UV sign 
  delay(111);

  digitalWrite(RVstrobe, HIGH);

  
  relay20.write(4, LOW);   // SlingShot closet
  delay(111);
  relay20.write(5, LOW);   // Pike MAGLOCK
  delay(111);
  relay20.write(6, LOW);   // 8 Track MAGLOCK
  delay(111);
  relay20.write(7, LOW);   // Frogs MAGLOCK
  delay(111);




  relay24.write(0, HIGH);  // BIRD LOAD (LOW = DOWN)
  delay(111);
  relay24.write(1, LOW);  // CHAIR glue 
  delay(111);
  relay24.write(2, HIGH); // CATTAILS LIGHT CONTROL
  delay(111);
  relay24.write(3, HIGH); // BEEHIVE AIR CTRL 
  delay(111);

  digitalWrite(RVknock, LOW);
  digitalWrite(RVstrobe, LOW);

  
  relay24.write(4, LOW);  // BABY MAGLOCK
  delay(111);
  relay24.write(5, LOW);  // SLINGSHOT MAP DOOR 
  delay(111);
  relay24.write(6, LOW);  // 
  delay(111);
  relay24.write(7, LOW);  //  BIRD LOAD (LOW = UP) 
  delay(111);


  relay22.write(0, LOW);  // 
  delay(111);
  relay22.write(1, LOW);  // 
  delay(111);
  relay22.write(2, LOW);  // ENTRANCE HEAD
  delay(111);
  relay22.write(3, LOW);   // animals skulls down 
  delay(111);  
  relay22.write(4, HIGH);  // animals skulls up
  delay(111);
  relay22.write(5, HIGH);  //
  delay(111);
  relay22.write(6, LOW);  // 
  delay(111);
  relay22.write(7, HIGH);  // shadowBox transparency  (keep off at startup) 
  delay(111);



  
  relay23.write(0, HIGH); // floor DOWN
  delay(111);
  relay23.write(1, LOW);  // egg CLOSE 
  delay(111);
  relay23.write(2, LOW);  // bird close
  delay(111);
  relay23.write(3, LOW);   // bed up
  delay(111);
  relay23.write(4, HIGH);  // bed down
  delay(111);
  relay23.write(5, HIGH);  // bird open
  delay(111);
  relay23.write(6, HIGH);  // egg OPEN
  delay(111);
  relay23.write(7, HIGH);  // floor UP  
  delay(111);

  Serial.println("all CLOSED");
  lcd.setCursor(0, 0);
  lcd.print("   ALL LOCKED   ");
  lcd.setCursor(0, 1);
  lcd.print("Waiting 4 Start");

}


void openALL() {

  Serial.println("Opening...");

  lcd.setCursor(0, 0);
  lcd.print("Opening...");

  relay20.write(0, HIGH);  //
  delay(333);
  relay20.write(1, HIGH);  //
  delay(333);
  relay20.write(2, HIGH);  //
  delay(333);
  relay20.write(3, HIGH);  //
  delay(333);
  relay20.write(4, HIGH);  //
  delay(333);
  relay20.write(5, HIGH);  //
  delay(333);
  relay20.write(6, HIGH);  //
  delay(333);
  relay20.write(7, HIGH);  //
  delay(333);

  //------------------------------------------------------

  relay24.write(0, HIGH);  //
  delay(333);
  relay24.write(1, HIGH);  //
  delay(333);
  relay24.write(2, HIGH);  //
  delay(333);
  relay24.write(3, HIGH);  //
  delay(333);
  relay24.write(4, HIGH);  //
  delay(333);
  relay24.write(5, HIGH);  // LOW to open gate lock
  delay(333);
  relay24.write(6, HIGH);  //
  delay(333);
  relay24.write(7, HIGH);  //
  delay(333);

  //------------------------------------------------------

  relay22.write(0, HIGH);  //
  delay(333);
  relay22.write(1, HIGH);  //
  delay(333);
  relay22.write(2, HIGH);  //
  delay(333);
  relay22.write(3, HIGH);  //
  delay(333);
  relay22.write(4, HIGH);  //
  delay(333);
  relay22.write(5, HIGH);  //
  delay(333);
  relay22.write(6, HIGH);  //
  delay(333);
  relay22.write(7, HIGH);  //
  delay(333);

  //------------------------------------------------------

  relay23.write(0, HIGH);  //
  delay(333);
  relay23.write(1, HIGH);  //
  delay(333);
  relay23.write(2, HIGH);  //
  delay(333);
  relay23.write(3, HIGH);  //
  delay(333);
  relay23.write(4, HIGH);  //
  delay(333);
  relay23.write(5, HIGH);  //
  delay(333);
  relay23.write(6, HIGH);  //
  delay(333);
  relay23.write(7, HIGH);  //
  delay(333);

  //------------------------------------------------------

  Serial.println("all OPEN");
  lcd.setCursor(0, 0);
  lcd.print("all OPEN");
}


void checkStart() {
  while (digitalRead(StartBut) == HIGH) {
    //MP3A.play(5);
    //   while (digitalRead(StartBut) == LOW) {
    //     delay(100);
    //   }
  }
  //Serial.print("START activated");
  delay(700);
}

/*
  boolean checkGateDoor()  // fireSen = HIGH is closed
  {
  boolean door_closed = digitalRead(fireSen);
  if(door_closed)
  {
    delay(15);
    door_closed = digitalRead(fireSen);
  }
  return door_closed;
  }

  void gateDoorOpen()
  {
  relay20.write(7, HIGH);  // FIREPLACE MAGLOCK
  }

  void gateDoorClose()
  {
  relay20.write(7, LOW);  // FIREPLACE MAGLOCK
  }

  boolean checkGateMotion() // movSen = LOW if movement detected
  {
  boolean motion = !digitalRead(movSen);
  if(motion)
  {
    delay(15);
    motion = !digitalRead(movSen);
  }
  return motion;
  }
*/


/*
  void testALL() {

  Serial.println("Testing...");
  lcd.setCursor(0, 0);
  lcd.print("Testing...");


  for (int x = 0; x < 8; x++) {

    checkStart();
    MP3A.play(x);

    digitalWrite(52, HIGH);

    relay20.write(x, LOW);  //
    lcd.setCursor(0, 0);
    lcd.print("20 = ");
    lcd.print(x);

    delay(333);

  }

  WhiteLightDim();

  //------------------------------------------------------

  for (int x = 0; x < 8; x++) {
    checkStart();
    MP3A.play(x);

    relay24.write(x, LOW);  //
    lcd.setCursor(0, 0);
    lcd.print("21 = ");
    lcd.print(x);


    delay(333);
  }

  WhiteLightBri();

  //------------------------------------------------------

  for (int t = 0; t < 8; t++) {

    checkStart();
    MP3A.play(t);

    relay22.write(t, LOW);  //
    lcd.setCursor(0, 0);
    lcd.print("22 = ");
    lcd.print(t);


    delay(333);
    if (t == 0) relay22.write(t, HIGH);  // release VCR lock WR
    if (t == 5) relay22.write(t, HIGH);  // release VCR lock DR

                                    cx               }

  //------------------------------------------------------

  for (int x = 0; x < 8; x++) {

    checkStart();
    MP3A.play(x);

    relay23.write(x, LOW);  //
    lcd.setCursor(0, 0);
    lcd.print("23 = ");
    lcd.print(x);


    if (x == 3 ) relay23.write(3, HIGH);  //
    delay(333);
    if (x == 1 ) relay23.write(1, HIGH);  // light test
    if (x == 2 ) relay23.write(2, HIGH);  //
    if (x == 4 ) relay23.write(4, HIGH);  //

  }

  //------------------------------------------------------

  digitalWrite(52, LOW);


  Serial.println("all TESTED");
  lcd.setCursor(0, 0);
  lcd.print("all TESTED");
  }
*/




/*
  relay20.write(0, LOW);  // BOOKSHELF MAGLOCK
  delay(333);
  relay20.write(1, LOW);  // WHITE ROOM LEAVING DOOR MAGLOCK
  delay(333);
  relay20.write(2, LOW);  // FREEZER / SAFE MAGLOCK
  delay(333);
  relay20.write(3, LOW);  // CAPSULE DOOR #2 MAGLOCKS A41 A40
  delay(333);
  relay20.write(4, LOW);  // CASSETE WHITE ROOM MAGLOCK A6
  delay(333);
  relay20.write(5, LOW);  // HBOX MAGLOCK A51
  delay(333);
  relay20.write(6, LOW);  // CENTRIFUGE MAGLOCK
  delay(333);
  relay20.write(7, LOW);  // FIREPLACE MAGLOCK
  delay(333);

  //------------------------------------------------------

  relay24.write(0, LOW);  // last door ML
  delay(333);
  relay24.write(1, LOW);  // lab ceiling fx light
  delay(333);
  relay24.write(2, LOW);  //
  delay(333);
  relay24.write(3, LOW);  // sound dir LOW = LAB, HIGH = CENTER
  delay(333);
  relay24.write(4, LOW);  // sound dir LOW = LAB, HIGH = CENTER
  delay(333);
  relay24.write(5, LOW);  //
  delay(333);
  delay(333);
  relay24.write(6, LOW);  // first door ML
  relay24.write(7, LOW);  // DEFIBRILATOR MAGLOCK
  delay(333);

  //------------------------------------------------------
  relay22.write(0, LOW);  // CASSETE VCR WHITE ROOM RELEASE (SHORT SIGNAL)
  delay(333);
  relay22.write(0, HIGH); // (!!!!!)
  delay(333);
  relay22.write(1, LOW);  // FOOTLAMP LIGHT WHITE ROOM A48
  delay(333);
  relay22.write(2, LOW);  // PICTURE FALL MAGLOCK A24
  delay(333);
  relay22.write(3, LOW);  // PROJECTOR LAB
  delay(333);
  relay22.write(4, LOW);  // MIRROR LIGHT LAB / 12v BRIGHT POWER FOR W+D ROOMS (if HIGH)
  delay(333);
  relay22.write(5, LOW);  // CASSETE VCR DARK ROOM RELEASE (SHORT SIGNAL)
  delay(333);
  relay22.write(5, HIGH);  // (!!!!!)
  delay(333);
  relay22.write(6, LOW);  // CAPSULE DOOR #1 MAGLOCKS A42 A43
  delay(333);
  relay22.write(7, LOW);  // LABYRINTH LAST DOOR
  delay(333);

  //------------------------------------------------------
  relay23.write(0, LOW);  // 3RD FAN
  delay(333);
  relay23.write(1, LOW);  // 1ST FAN
  delay(333);
  relay23.write(2, LOW);  // MOVING WALL DARK ROOM LIGHT
  delay(333);
  relay23.write(3, LOW);  // BOTH ROOMS CORNER (NEAR DOOR) LIGHTS
  delay(333);
  relay23.write(4, LOW);  // FOOTLAMP DARK ROOM LIGHT
  delay(333);
  //relay23.write(5, LOW);  // out of service - permanent DAMAGE !!!!!!!!!!!!!
  delay(333);
  relay23.write(6, LOW);  // 2ND FAN
  delay(333);
  relay23.write(7, LOW);  // LAB LIGHT CEILING
  delay(333);




*/
