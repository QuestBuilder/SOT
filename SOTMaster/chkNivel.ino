void chknivel() {


  if (nivel == 1 && nextEvent != 0) { // head drop event started
    if (nextEvent < millis()) {
      if (!girl) MP3A.play(1); else MP3A.play(2);
      relay22.write(2, HIGH);  // ENTRANCE HEAD RELEASE
      Serial.print("Head Release started, ");
      relay24.write(7, HIGH);  //  BIRD LOAD (LOW = UP) // just to stop it and release the relay
      nextEvent = 0;
      nivel = 0;
    }
  }


  if (nivel == 2 && nextEvent != 0) { // gator started
    if (nextEvent < millis()) {
      Serial.println("Gator Released");

      relay20.write(2, LOW);    // GATOR air valve
      delay(600);
      relay20.write(2, HIGH);   // GATOR air valve

      nextEvent = 0;
      nivel = 0;
    }
  }



  if (nivel == 3 && nextEvent != 0) { // HOOKAH ended
    if (nextEvent < millis()) {

      //sendHLms(propBout, 250); //start signal for MICE
      nextEvent = 0;
      nivel = 0;
    }
  }


  if (nivel == 4 && nextEvent != 0) { // QUEEN start after KEY is done
    if (nextEvent < millis()) {

      //      sendHLms(propLout, 120); //start signal for QUEEN --- disabled

      //     relay23.write(6, LOW);  // QUEEN start - skip signal output
      delay(180);
      //     relay23.write(6, HIGH);  // QUEEN start - skip signal output

      //nextEvent = millis() + 300;
      nextEvent = 0;
      nivel = 5;
    }
  }

  if (nivel == 5 && nextEvent != 0) { // turn off compressor
    if (nextEvent < millis()) {
      //      digitalWrite(compress, LOW);
      nextEvent = 0;
      nivel = 6;
    }
  }


  if (nivel == 8 && nextEvent != 0) { // memories and  key are done
    // turn on the door light after 28 sec
    if (nextEvent < millis()) {

      //     relay22.write(4, LOW);  // MIRROR DOOR AMBIANCE FX - ON
      //     relay23.write(0, LOW);  // power control KEY
      nextEvent = 0;
      nivel = 9;
    }
  }

  if (nivel == 9 && nextEvent != 0) { // SOUNDTRACK
    if (nextEvent < millis()) {

      //      roomSound(2);
      MP3B.play(4);
      //      MP3A.play(15);

      relay23.write(1, HIGH);  // light THIRD Room (LOW = ON)
      //    sendHLms(propMout, 100); //starts JACK



      nextEvent = 0;
      nivel = 10;
    }
  }


  if (nivel == 10 && nextEvent != 0)  // JACK is done sequence begin
  {
    if (nextEvent < millis()) {
      //     digitalWrite(mirrorRT, HIGH);
      delay(333);
      //      digitalWrite(mirrorRT, LOW);
      relay23.write(5, LOW);  // BOAT LIGHT HIGH = ON
      nivel = 12;
      nextEvent = millis() + 3500;
    }
  }



  if (nivel == 14 && nextEvent != 0) { // JACK is done sequence end
    if (nextEvent < millis()) {
      //      sendHLms(video5, 120); //videoBeam signal
      nextEvent = millis() + 24000;
      nivel = 15;
    }
  }

  if (nivel == 15 && nextEvent != 0) { // JACK is done sequence end
    if (nextEvent < millis()) {
      //    sendHLms(propNout, 250); //starts CATs RFID reader sequence
      nextEvent = 0;
      nivel = 16;
    }
  }



}
