void loop()
{
  unsigned long tick = millis();
  // StartButtons run HeadFall and MP3 File
  start_btn_states[0] = readButt(StartBut, start_btn_states[1]);
  start_btn2_states[0] = readButt(StartBut2, start_btn2_states[1]);
  boolean butt1_pressed = !start_btn_states[0] && start_btn_states[1];
  boolean butt2_pressed = !start_btn2_states[0] && start_btn2_states[1];


  if (level == 0) {
    waitStart();
    //    if (nextEvent < millis()) checkKEYs();
  }
  else if (level == 1)
  {

    if ( !headFalled ) {
      if (gameStarted && nivel == 0 && (startTimer + 3000 < millis())) { // head release
        if (butt1_pressed || butt2_pressed) {
          Serial.print(" by ");
          if (butt1_pressed) {
            girl = false;
            Serial.println("boy");
          }
          if (butt2_pressed) {
            girl = true;
            Serial.println("girl");
          }
          nivel = 1;
          nextEvent = millis() + 5000;
          headFalled = true;
        }
      }
    }

    checkSPIKE();       // 0

    checkBEES();        // 1

    checkGATOR();       // 2     // scary_mode mode

    checkEGG();         // 3

    checkLOG();         // 4

    checkFROGS();       // 5

    checkDEER();        // 6

    checkTRACK8();      // 7

    checkBANJOS();      // 8

    checkCLOSET();      // 9  ****

    checkANIMAL();      // 10

    checkBED();         // 11
    checkBABY();        // 12

    checkCHAIR();       // No prop // scary_mode Mode

    checkBLOCKS();      // 13

    checkWHEEL();       // 14
    checkSSHOT();       // 15
    checkFUSE ();       // 16

    checkCALL911();     // 17

    if (!RVDone)
    {
      checkRV_SINK();     // 18
      checkRV_FAN();      // 19
      checkRV_AC();       // 20
      checkRV_CAN();      // 21
      checkRV_MICRO();    // 22
    }
    if (gadget_states[RV_MICRO] == 3 && gadget_states[RV_CAN] == 3 && gadget_states[RV_AC] == 3 && gadget_states[RV_FAN] == 3 && gadget_states[RV_SINK] == 3)
    {
      RVDone = true;
    }

    checkBREAKER();     // 23

  }

  checkGadgets(); // проверка на прохождение

  if (tick - lastSyncTime > 10000)
  {
    sendByte(0xA9);
    lastSyncTime = tick;
    // printEvent("Send Sync signal", true);
  }

  getBridgeData(); // На время тестов отключу прием данных от моста

  chknivel();

  start_btn_states[1] = start_btn_states[0];
  start_btn2_states[1] = start_btn2_states[0];
}

void sendHLms(int _pin, unsigned long _delay)
{
  digitalWrite(_pin, HIGH);
  delay(_delay);
  digitalWrite(_pin, LOW);
  delay(50);
}

boolean readButt(int pin, boolean prevState)
{
  boolean currState = digitalRead(pin);
  if (currState != prevState)
  {
    delay(5);
    currState = digitalRead(pin);
  }
  return currState;
}

void checkGadgets()
{
  boolean all_done = true;
  //printEvent("CHECK_STATUS:", false);
  //  for (int i = 0; i < GCOUNT - 1; i++)
  for (int i = 0; i < GCOUNT ; i++)
  {
    if (gadget_states[i] < 3) all_done = false;
    //Serial.print(String(gadget_states[i]) + "|");
  }

  //  if (gadget_states[LETER] == 3 && gadget_states[DEFIB] == 3) all_done = true;

  if (all_done && TheEND) {
    //printEvent("SEND END GAME", true);
    sendByte(0xBB);
    resetStates();
    gameOver = millis();
  }
}

void printEvent(String e, boolean endline)
{
  unsigned long t = millis() / 1000;
  String h_str = String(hours(t));
  if (h_str.length() < 2) h_str = "0" + h_str;
  String m_str = String(minutes(t));
  if (m_str.length() < 2) m_str = "0" + m_str;
  String s_str = String(seconds(t));
  if (s_str.length() < 2) s_str = "0" + s_str;
  if (endline) Serial.println(String(h_str + ":" + m_str + ":" + s_str) + ": " + e);
  else Serial.print(String(h_str + ":" + m_str + ":" + s_str) + ": " + e);
}

int seconds(unsigned long t) {
  return int(t % 60);
}

int minutes(unsigned long t) {
  return int((t / 60) % 60);
}

int hours(unsigned long t) {
  return int((t / 3600) % 24);
}
