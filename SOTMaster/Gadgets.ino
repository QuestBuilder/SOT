// С обратной связью для 5 гаджетов


void checkSPIKE() {   ///   000
  if (gadget_states[SPIKE] == 0) {
    if (oper_skips[SPIKE] || !digitalRead(propJin)) {
      gadget_states[SPIKE] = 1;
      Serial.println("SPIKE Timer START by " + String(oper_skips[SPIKE] ? "Operator" : "Player"));
      pass_times[SPIKE] = millis();
      if (!oper_skips[SPIKE]) {
        sendGadgetPassed(SPIKE);
      } else sendHLms(propJout, 250);  //skips SPIKE
    }
  } else if (gadget_states[SPIKE] == 2 && millis() - pass_times[SPIKE] > post_delays1[SPIKE] + post_delays2[SPIKE]) {
    gadget_states[SPIKE] = 3;
    relay23.write(1, HIGH);  // egg CLOSE
    delay(100);
    relay23.write(6, LOW);  // egg OPEN

    sendHLms(propFout, 150);  // starts bed prop

    Serial.println("SPIKE Second Command Executed");
    Serial.print("SPIKE Done ");
    if (oper_skips[SPIKE]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[SPIKE] == 1 && millis() - pass_times[SPIKE] > post_delays1[SPIKE]) {
    gadget_states[SPIKE] = 2;
    relay20.write(5, HIGH);   // Pike MAGLOCK
    Serial.println("SPIKE First Command Executed");
  }
}

void checkBEES() {    //   111
  if (gadget_states[BEES] == 0) {
    if (oper_skips[BEES] || !digitalRead(propAin)) {
      gadget_states[BEES] = 1;
      relay24.write(3, LOW); // BEEHIVE AIR CTRL OPEN

      Serial.println("BEES Timer START by " + String(oper_skips[BEES] ? "Operator" : "Player"));
      pass_times[BEES] = millis();
      if (!oper_skips[BEES]) {
        sendGadgetPassed(BEES);
      } else sendHLms(propAout, 250);  //skips BEES
    }
  } else if (gadget_states[BEES] == 2 && millis() - pass_times[BEES] > post_delays1[BEES] + post_delays2[BEES]) {
    gadget_states[BEES] = 3;

    relay24.write(3, HIGH); // BEEHIVE AIR CTRL CLOSED

    Serial.println("BEES Second Command Executed");
    Serial.print("BEES Done ");
    if (oper_skips[BEES]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[BEES] == 1 && millis() - pass_times[BEES] > post_delays1[BEES]) {
    gadget_states[BEES] = 2;
    //    relay20.write(5, HIGH);   // Pike MAGLOCK
    Serial.println("BEES First Command Executed");
  }
}

void checkGATOR() {  // if scary_mode   222

  if (gadget_states[GATOR] == 0) {
    if (oper_skips[GATOR] || !digitalRead(propHin)) {
      gadget_states[GATOR] = 1;
      Serial.println("GATOR Timer START by " + String(oper_skips[GATOR] ? "Operator" : "Player"));
      pass_times[GATOR] = millis();
      nivel = 2;
      nextEvent = millis() + 100;
      if (!oper_skips[GATOR]) {
        sendGadgetPassed(GATOR);
      } else sendHLms(propIout, 250);  //skips GATOR
    }
  } else if (gadget_states[GATOR] == 2 && millis() - pass_times[GATOR] > post_delays1[GATOR] + post_delays2[GATOR]) {
    gadget_states[GATOR] = 3;
    Serial.println("GATOR Second Command Executed");
    Serial.print("GATOR Done ");
    if (oper_skips[GATOR]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[GATOR] == 1 && millis() - pass_times[GATOR] > post_delays1[GATOR]) {
    gadget_states[GATOR] = 2;
    relay23.write(2, HIGH);  // bird close
    delay(100);
    relay23.write(5, LOW);  // bird open
    Serial.println("GATOR First Command Executed");
  }

}

/*
  if (gatorDONE == false) {
    if (!digitalRead(propHin)) {
      nivel = 1;
      nextEvent = millis() + 100;
      gatorDONE = true;
      Serial.println("Gator done");
    }
  }
  }
*/

void checkCHAIR() {
  if (chairDONE == false) {
    if (!digitalRead(stepSen)) {
      relay24.write(1, HIGH);  // CHAIR falls
      //nivel = 1;
      //nextEvent = millis() + 100;
      chairDONE = true;
      Serial.println("Chair done");
    }
  }
}


void checkEGG() { // BIRD/NEST   333
  if (gadget_states[EGG] == 0) {
    if (oper_skips[EGG] || !digitalRead(propIin)) {
      gadget_states[EGG] = 1;
      Serial.println("EGG Timer START by " + String(oper_skips[EGG] ? "Operator" : "Player"));
      pass_times[EGG] = millis();
      if (!oper_skips[EGG]) {
        sendGadgetPassed(EGG);
      } else sendHLms(propIout, 250);  //skips EGG
    }
  } else if (gadget_states[EGG] == 2 && millis() - pass_times[EGG] > post_delays1[EGG] + post_delays2[EGG]) {
    gadget_states[EGG] = 3;
    Serial.println("EGG Second Command Executed");
    Serial.print("EGG Done ");
    if (oper_skips[EGG]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[EGG] == 1 && millis() - pass_times[EGG] > post_delays1[EGG]) {
    gadget_states[EGG] = 2;
    relay23.write(2, HIGH);  // bird close
    delay(100);
    relay23.write(5, LOW);  // bird open
    Serial.println("EGG First Command Executed");
  }
}



void checkLOG() { //LOG  (turns on Cattails)  4444444444444444444444444444
  if (gadget_states[LOG] == 0) {
    if (oper_skips[LOG] || !digitalRead(logIn)) {
      gadget_states[LOG] = 1;
      Serial.println("LOG Timer START by " + String(oper_skips[LOG] ? "Operator" : "Player"));
      pass_times[LOG] = millis();
      if (!oper_skips[LOG]) {
        sendGadgetPassed(LOG);
      }
    }
  } else if (gadget_states[LOG] == 2 && millis() - pass_times[LOG] > post_delays1[LOG] + post_delays2[LOG]) {
    gadget_states[LOG] = 3;
    Serial.println("LOG Second Command Executed");
    Serial.print("LOG Done ");
    if (oper_skips[LOG]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[LOG] == 1 && millis() - pass_times[LOG] > post_delays1[LOG]) {
    gadget_states[LOG] = 2;
    relay24.write(2, LOW);  // CATTAILS LIGHTS ON
    Serial.println("LOG First Command Executed");
  }
}


void checkFROGS() { // FROGS (opens FROGS maglock)  5555555555555555555555555555
  if (gadget_states[FROGS] == 0) {
    if (oper_skips[FROGS] || !digitalRead(propDin)) {
      gadget_states[FROGS] = 1;
      Serial.println("FROGS Timer START by " + String(oper_skips[FROGS] ? "Operator" : "Player"));
      pass_times[FROGS] = millis();
      if (!oper_skips[FROGS]) {
        sendGadgetPassed(FROGS);
      } else sendHLms(propDout, 250);  //skips FROGS
    }
  } else if (gadget_states[FROGS] == 2 && millis() - pass_times[FROGS] > post_delays1[FROGS] + post_delays2[FROGS]) {
    gadget_states[FROGS] = 3;
    Serial.println("FROGS Second Command Executed");
    Serial.print("FROGS Done ");
    if (oper_skips[FROGS]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[FROGS] == 1 && millis() - pass_times[FROGS] > post_delays1[FROGS]) {
    gadget_states[FROGS] = 2;
    relay20.write(7, HIGH);   // Frogs MAGLOCK OPEN
    Serial.println("FROGS First Command Executed");
  }
}



void checkDEER() { //   66666666666666666666666666
  if (gadget_states[DEER] == 0) {
    if (oper_skips[DEER] || !digitalRead(deerEye)) {
      gadget_states[DEER] = 1;
      Serial.println("DEER Timer START by " + String(oper_skips[DEER] ? "Operator" : "Player"));
      pass_times[DEER] = millis();
      if (!oper_skips[DEER]) {
        sendGadgetPassed(DEER);
      } // else sendHLms(propXout, 250);  //skips DEER
          MP3A.play(3); // deer runing after shot

    }
  } else if (gadget_states[DEER] == 2 && millis() - pass_times[DEER] > post_delays1[DEER] + post_delays2[DEER]) {
    gadget_states[DEER] = 3;
    Serial.println("DEER Second Command Executed");
    Serial.print("DEER Done ");
    if (oper_skips[DEER]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[DEER] == 1 && millis() - pass_times[DEER] > post_delays1[DEER]) {
    gadget_states[DEER] = 2;
    relay20.write(6, HIGH);   // 8 Track MAGLOCK OPENS
    Serial.println("DEER First Command Executed");
  }
}


void checkTRACK8() { //TRACK8 (OPENS CLOSET DOOR     777777777777777777777777
  if (gadget_states[TRACK8] == 0) {
    if (oper_skips[TRACK8] || gadget_states[BANJOS] > 2  ) { // !digitalRead(propEin)) {
      gadget_states[TRACK8] = 1;
      Serial.println("TRACK8 Timer START by " + String(oper_skips[TRACK8] ? "Operator" : "Player"));
      pass_times[TRACK8] = millis();
      if (!oper_skips[TRACK8]) {
        sendGadgetPassed(TRACK8);
      } else sendHLms(propEout, 250);  //skips TRACK8
    }
  } else if (gadget_states[TRACK8] == 2 && millis() - pass_times[TRACK8] > post_delays1[TRACK8] + post_delays2[TRACK8]) {
    gadget_states[TRACK8] = 3;
    Serial.println("TRACK8 Second Command Executed");
    Serial.print("TRACK8 Done ");
    if (oper_skips[TRACK8]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[TRACK8] == 1 && millis() - pass_times[TRACK8] > post_delays1[TRACK8]) {
    gadget_states[TRACK8] = 2;
    Serial.println("TRACK8 First Command Executed");
  }
}


void checkBANJOS() { //BANJOS (OPENS CLOSET DOOR     88888888888888888888888888
  if (gadget_states[BANJOS] == 0) {
    if (oper_skips[BANJOS] || !digitalRead(propGin)) {
      gadget_states[BANJOS] = 1;
      Serial.println("BANJOS Timer START by " + String(oper_skips[BANJOS] ? "Operator" : "Player"));
      pass_times[BANJOS] = millis();
      if (!oper_skips[BANJOS]) {
        sendGadgetPassed(BANJOS);
      } else sendHLms(propGout, 250);  //skips BANJOS
    }
  } else if (gadget_states[BANJOS] == 2 && millis() - pass_times[BANJOS] > post_delays1[BANJOS] + post_delays2[BANJOS]) {
    gadget_states[BANJOS] = 3;
    Serial.println("BANJOS Second Command Executed");
    Serial.print("BANJOS Done ");
    if (oper_skips[BANJOS]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[BANJOS] == 1 && millis() - pass_times[BANJOS] > post_delays1[BANJOS]) {
    gadget_states[BANJOS] = 2;

    sendHLms(propKout, 250);  //opens/start CLOSET

    // turn off lights and sun in 1st room

    Serial.println("BANJOS First Command Executed");
  }
}

void checkCLOSET() { //CLOSET SEQUENCE    9999999999999999999999999
  if (gadget_states[CLOSET] == 0) {
    if (oper_skips[CLOSET] || !digitalRead(propKin)) {
      gadget_states[CLOSET] = 1;
      Serial.println("CLOSET Timer START by " + String(oper_skips[CLOSET] ? "Operator" : "Player"));
      pass_times[CLOSET] = millis();
      if (!oper_skips[CLOSET]) {
        sendGadgetPassed(CLOSET);
      } else sendHLms(propKout, 250);  //skips CLOSET
    }
  } else if (gadget_states[CLOSET] == 2 && millis() - pass_times[CLOSET] > post_delays1[CLOSET] + post_delays2[CLOSET]) {
    gadget_states[CLOSET] = 3;
    Serial.println("CLOSET Second Command Executed");
    Serial.print("CLOSET Done ");
    if (oper_skips[CLOSET]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[CLOSET] == 1 && millis() - pass_times[CLOSET] > post_delays1[CLOSET]) {
    gadget_states[CLOSET] = 2;

    // tuen off the light in the closet
    // send signal to 8TRACK to start video
    // mp3 play in main room
    // mp3 play in RV (steps and cought)
    // activates/send signal to ANIMAL
    relay22.write(3, HIGH);   // animals skulls down
    relay22.write(4,  LOW);  // animals skulls up started

    Serial.println("CLOSET First Command Executed");
  }
}


void checkANIMAL() { //ANIMAL DOOR   10 - 10 - 10 - 10 - 10
  if (gadget_states[ANIMAL] == 0) {
    if (oper_skips[ANIMAL] || !digitalRead(propCin)) {
      gadget_states[ANIMAL] = 1;
      Serial.println("ANIMAL Timer START by " + String(oper_skips[ANIMAL] ? "Operator" : "Player"));
      pass_times[ANIMAL] = millis();
      if (!oper_skips[ANIMAL]) {
        sendGadgetPassed(ANIMAL);
      } else sendHLms(propCout, 250);  //skips ANIMAL
    }
  } else if (gadget_states[ANIMAL] == 2 && millis() - pass_times[ANIMAL] > post_delays1[ANIMAL] + post_delays2[ANIMAL]) {
    gadget_states[ANIMAL] = 3;
    Serial.println("ANIMAL Second Command Executed");
    Serial.print("ANIMAL Done ");
    if (oper_skips[ANIMAL]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[ANIMAL] == 1 && millis() - pass_times[ANIMAL] > post_delays1[ANIMAL]) {
    gadget_states[ANIMAL] = 2;
    relay20.write(0, HIGH);   // Animal DOOR OPENS
    relay22.write(4, HIGH);  // animals skulls up ENDS

    //activates Movement sensor for Chair
    //activates/ send signal to BED

    Serial.println("ANIMAL First Command Executed");
  }
}



void checkBED() { //BED FIRST SIGNAL (moving sensor)    11 - 11 - 11 - 11 - 11 - 11 - 11
  if (gadget_states[BED] == 0) {
    if (oper_skips[BED] || !digitalRead(propFin)) {
      gadget_states[BED] = 1;
      Serial.println("BED Timer START by " + String(oper_skips[BED] ? "Operator" : "Player"));
      pass_times[BED] = millis();
      if (!oper_skips[BED]) {
        sendGadgetPassed(BED);
      } else sendHLms(propFout, 250);  //skips BED
    }
  } else if (gadget_states[BED] == 2 && millis() - pass_times[BED] > post_delays1[BED] + post_delays2[BED]) {
    gadget_states[BED] = 3;
    Serial.println("BED Second Command Executed");
    Serial.print("BED Done ");
    if (oper_skips[BED]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[BED] == 1 && millis() - pass_times[BED] > post_delays1[BED]) {
    gadget_states[BED] = 2;
    relay20.write(1, HIGH);   // BED FALLS
    Serial.println("BED First Command Executed");
  }
}



void checkBABY() { //BED SECOND SIGNAL (RFID)   12 - 12 - 12 - 12 - 12 - 12
  if (gadget_states[BABY] == 0 && gadget_states[BED] > 2) {
    if (oper_skips[BABY] || !digitalRead(propFin)) {
      gadget_states[BABY] = 1;
      Serial.println("BABY Timer START by " + String(oper_skips[BABY] ? "Operator" : "Player"));
      pass_times[BABY] = millis();
      if (!oper_skips[BABY]) {
        sendGadgetPassed(BABY);
      } else sendHLms(propFout, 250);  //skips BABY
    }
  } else if (gadget_states[BABY] == 2 && millis() - pass_times[BABY] > post_delays1[BABY] + post_delays2[BABY]) {
    gadget_states[BABY] = 3;
    Serial.println("BABY Second Command Executed");
    Serial.print("BABY Done ");
    if (oper_skips[BABY]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[BABY] == 1 && millis() - pass_times[BABY] > post_delays1[BABY]) {
    gadget_states[BABY] = 2;
    relay24.write(4, HIGH);  // BABY MAGLOCK OPENS
    Serial.println("BABY First Command Executed");
  }
}


void checkBLOCKS() { //BLOCKS   13 - 13 - 13 - 13 - 13 - 13
  if (gadget_states[BLOCKS] == 0) {
    if (oper_skips[BLOCKS] || !digitalRead(propLin)) {
      gadget_states[BLOCKS] = 1;
      Serial.println("BLOCKS Timer START by " + String(oper_skips[BLOCKS] ? "Operator" : "Player"));
      pass_times[BLOCKS] = millis();
      if (!oper_skips[BLOCKS]) {
        sendGadgetPassed(BLOCKS);
      } else sendHLms(propLout, 250);  //skips BLOCKS

      // turns on SHADOW_BOX
      digitalWrite(shadowL, HIGH); //  shadowbox backlight ON
    }
  } else if (gadget_states[BLOCKS] == 2 && millis() - pass_times[BLOCKS] > post_delays1[BLOCKS] + post_delays2[BLOCKS]) {
    gadget_states[BLOCKS] = 3;
    relay22.write(7, LOW);  // shadowBox transparency ON (delyed 1000mSec)
    Serial.println("BLOCKS Second Command Executed");
    Serial.print("BLOCKS Done ");
    if (oper_skips[BLOCKS]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[BLOCKS] == 1 && millis() - pass_times[BLOCKS] > post_delays1[BLOCKS]) {
    gadget_states[BLOCKS] = 2;

    Serial.println("BLOCKS First Command Executed");
  }
}


void checkWHEEL() { //WHEEL_SLINGSHOT_FUSE (first signal)    14 - 14 - 14 - 14 - 14
  if (gadget_states[WHEEL] == 0) {
    if (oper_skips[WHEEL] || !digitalRead(propBin)) {
      gadget_states[WHEEL] = 1;
      Serial.println("WHEEL Timer START by " + String(oper_skips[WHEEL] ? "Operator" : "Player"));
      pass_times[WHEEL] = millis();
      if (!oper_skips[WHEEL]) {
        sendGadgetPassed(WHEEL);
      } else sendHLms(propBout, 250);  //skips WHEEL
    }
  } else if (gadget_states[WHEEL] == 2 && millis() - pass_times[WHEEL] > post_delays1[WHEEL] + post_delays2[WHEEL]) {
    gadget_states[WHEEL] = 3;
    Serial.println("WHEEL Second Command Executed");
    Serial.print("WHEEL Done ");
    if (oper_skips[WHEEL]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[WHEEL] == 1 && millis() - pass_times[WHEEL] > post_delays1[WHEEL]) {
    gadget_states[WHEEL] = 2;

    // OPENS THE MAP/SLINGSHOT DOOR

    Serial.println("WHEEL First Command Executed");
  }
}


void checkSSHOT() { //WHEEL_SLINGSHOT_FUSE (second signal)    15 - 15 - 15 - 15 - 15
  if (gadget_states[SSHOT] == 0 && gadget_states[WHEEL] > 2 ) {
    if (oper_skips[SSHOT] || !digitalRead(propBin)) {
      gadget_states[SSHOT] = 1;
      Serial.println("SSHOT Timer START by " + String(oper_skips[SSHOT] ? "Operator" : "Player"));
      pass_times[SSHOT] = millis();
      if (!oper_skips[SSHOT]) {
        sendGadgetPassed(SSHOT);
      } else sendHLms(propBout, 250);  //skips SSHOT
    }
  } else if (gadget_states[SSHOT] == 2 && millis() - pass_times[SSHOT] > post_delays1[SSHOT] + post_delays2[SSHOT]) {
    gadget_states[SSHOT] = 3;
    Serial.println("SSHOT Second Command Executed");
    Serial.print("SSHOT Done ");
    if (oper_skips[SSHOT]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[SSHOT] == 1 && millis() - pass_times[SSHOT] > post_delays1[SSHOT]) {
    gadget_states[SSHOT] = 2;
    relay20.write(4, HIGH);   // SlingShot SSHOT
    Serial.println("SSHOT First Command Executed");
  }
}


void checkFUSE() { // WHEEL_SLINGSHOT_FUSE (third  signal)    16 - 16 - 16 - 16 - 16
  if (gadget_states[FUSE] == 0 && gadget_states[SSHOT] > 2) {
    if (oper_skips[FUSE] || !digitalRead(propBin)) {
      gadget_states[FUSE] = 1;
      Serial.println("FUSE Timer START by " + String(oper_skips[FUSE] ? "Operator" : "Player"));
      pass_times[FUSE] = millis();
      if (!oper_skips[FUSE]) {
        sendGadgetPassed(FUSE);
      } else sendHLms(propBout, 250);  //skips FUSE
    }
  } else if (gadget_states[FUSE] == 2 && millis() - pass_times[FUSE] > post_delays1[FUSE] + post_delays2[FUSE]) {
    gadget_states[FUSE] = 3;

    digitalWrite(shadowL, LOW); // shadowbox backlight OFF
    relay22.write(7, HIGH);  // shadowBox transparency OFF

    Serial.println("FUSE Second Command Executed");
    Serial.print("FUSE Done ");
    if (oper_skips[FUSE]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[FUSE] == 1 && millis() - pass_times[FUSE] > post_delays1[FUSE]) {
    gadget_states[FUSE] = 2;

    //OPENS THE FLOOR
    //SIGNAL TO RV
    //LIGHTS

    Serial.println("FUSE First Command Executed");
  }
}


void checkCALL911() { // RV (first SIGNAL)    17 - 17 - 17 - 17 - 17
  if (gadget_states[CALL911] == 0) {
    if (oper_skips[CALL911] || !digitalRead(propMin)) {
      gadget_states[CALL911] = 1;
      Serial.println("CALL911 Timer START by " + String(oper_skips[CALL911] ? "Operator" : "Player"));
      pass_times[CALL911] = millis();
      if (!oper_skips[CALL911]) {
        sendGadgetPassed(CALL911);
      } else sendHLms(propMout, 250);  //skips CALL911
    }
  } else if (gadget_states[CALL911] == 2 && millis() - pass_times[CALL911] > post_delays1[CALL911] + post_delays2[CALL911]) {
    gadget_states[CALL911] = 3;
    Serial.println("CALL911 Second Command Executed");
    Serial.print("CALL911 Done ");
    if (oper_skips[CALL911]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[CALL911] == 1 && millis() - pass_times[CALL911] > post_delays1[CALL911]) {
    gadget_states[CALL911] = 2;
    Serial.println("CALL911 First Command Executed");
  }
}

//------------------
// RV_SINK   18 // byte RVsink   = 4;
// RV_FAN    19 // byte RVfan    = 5;
// RV_AC     20 // byte RVair    = 7;
// RV_CAN    21 // byte RVcan    = 22;
// RV_MICRO  22 // byte RVmic    = 24;
//------------------
// BREAKER   23 //byte RVbrk    = 26;
//------------------

//  MP3A.play(7);  // LIGHT GOES ON SOUND AND SOUNDTRACK



void checkRV_SINK() {
  if (gadget_states[RV_SINK] == 0 && !digitalRead(RVsink))
  {
    gadget_states[RV_SINK] = 3;
    sendGadgetState(RV_SINK, 3);
  }
  if (gadget_states[RV_SINK] == 3 && digitalRead(RVsink))
  {
    gadget_states[RV_SINK] = 0;
    sendGadgetState(RV_SINK, 0);
  }
}

void checkRV_FAN() {
  if (gadget_states[RV_FAN] == 0 && !digitalRead(RVfan))
  {
    gadget_states[RV_FAN] = 3;
    sendGadgetState(RV_FAN, 3);
  }
  if (gadget_states[RV_FAN] == 3 && digitalRead(RVfan))
  {
    gadget_states[RV_FAN] = 0;
    sendGadgetState(RV_FAN, 0);
  }
}

void checkRV_AC() {
  if (gadget_states[RV_AC] == 0 && !digitalRead(RVair))
  {
    gadget_states[RV_AC] = 3;
    sendGadgetState(RV_AC, 3);
  }
  if (gadget_states[RV_AC] == 3 && digitalRead(RVair))
  {
    gadget_states[RV_AC] = 0;
    sendGadgetState(RV_AC, 0);
  }
}


void checkRV_CAN() {
  if (gadget_states[RV_CAN] == 0 && !digitalRead(RVcan))
  {
    gadget_states[RV_CAN] = 3;
    sendGadgetState(RV_CAN, 3);
  }
  if (gadget_states[RV_CAN] == 3 && digitalRead(RVcan))
  {
    gadget_states[RV_CAN] = 0;
    sendGadgetState(RV_CAN, 0);
  }
}


void checkRV_MICRO() {
  if (gadget_states[RV_MICRO] == 0 && !digitalRead(RVmic))
  {
    gadget_states[RV_MICRO] = 3;
    sendGadgetState(RV_MICRO, 3);
  }
  if (gadget_states[RV_MICRO] == 3 && digitalRead(RVmic))
  {
    gadget_states[RV_MICRO] = 0;
    sendGadgetState(RV_MICRO, 0);
  }
}

void checkBREAKER() { // RV (second SIGNAL)    23 - 23 - 23 - 23 - 23
  if (gadget_states[BREAKER] == 0 && gadget_states[CALL911] > 2) {
    if (oper_skips[BREAKER] || !digitalRead(propMin)) {
      gadget_states[BREAKER] = 1;
      Serial.println("BREAKER Timer START by " + String(oper_skips[BREAKER] ? "Operator" : "Player"));
      pass_times[BREAKER] = millis();
      if (!oper_skips[BREAKER]) {
        sendGadgetPassed(BREAKER);
      } else sendHLms(propMout, 250);  //skips BREAKER
    }
  } else if (gadget_states[BREAKER] == 2 && millis() - pass_times[BREAKER] > post_delays1[BREAKER] + post_delays2[BREAKER]) {
    gadget_states[BREAKER] = 3;
    Serial.println("BREAKER Second Command Executed");
    Serial.print("BREAKER Done ");
    if (oper_skips[BREAKER]) {
      Serial.println("by Skip");
    } else Serial.println("by Player");
  } else if (gadget_states[BREAKER] == 1 && millis() - pass_times[BREAKER] > post_delays1[BREAKER]) {
    gadget_states[BREAKER] = 2;
    Serial.println("BREAKER First Command Executed");
  }
}



void waitStart() {
  start_btn_states[0] = readButt(StartBut, start_btn_states[1]);
  start_btn2_states[0] = readButt(StartBut2, start_btn2_states[1]);
  boolean butt1_pressed = !start_btn_states[0] && start_btn_states[1];
  boolean butt2_pressed = !start_btn2_states[0] && start_btn2_states[1];
  if (butt1_pressed || butt2_pressed) {

    if (start_level == 1)  // START
    {
      delay(100);
      //MP3A.stop();
      delay(500);
      start_delay = 200;
      game = true;
      level = 1;
      sendByte(0xAA);
      startTimer = millis();
      delay(200);
      // debug only after this line

      relay23.write(3, HIGH);   //  down
      delay(111);
      relay23.write(4, LOW);  // bed up
      delay(100);
      relay23.write(2, HIGH);  // bird close stops
      relay23.write(1, HIGH);  // egg CLOSE
      relay23.write(6, HIGH);  // egg OPEN
      digitalWrite(aircomp, LOW); // stops compressor
      digitalWrite(shadowL, LOW); // tuen off shadowbox backlight
      //relay22.write(7, LOW);  // shadowBox transparency OFF
      delay(100);
      relay22.write(3, HIGH);   // animals skulls down OFF

      Serial.println("Started.");
      //nextEvent = millis() + 12000;
      nextEvent = 0;
      lcd.setCursor(0, 0);
      lcd.print("    Started     ");
      MP3B.play(1); // soundtrack
      gameStarted = true;
      if (butt1_pressed) {
            scary_mode = true;
            lcd.setCursor(0, 1);
            lcd.print("    Scary ...  ");

      } else {
            scary_mode = false;
            lcd.setCursor(0, 1);
            lcd.print("    Regular ...  ");
        
      }
    }

    else if (start_level == 0)  // PRE-START

    {
      start_level++;
      lockALL();
      relay23.write(7, HIGH);  // floor UP
      relay23.write(0, LOW); // floor DOWN
      Serial.println("PreStarted.");
      //      digitalWrite(compress, HIGH);
      
    }


  }
  start_btn_states[1] = start_btn_states[0];
  start_btn2_states[1] = start_btn2_states[0];
}


void sendPlayersToCave()
{
  if (players < 2) players = 2;
  for (int i = 0; i < players; i++) {
    sendHLms(propEout, 500); //was 500
    delay(100);
  }
  sendHLms(propEout, 3000); // was3000);
  Serial.print  ("Players sent to Cave = ");
  Serial.println(players);

}
