void testBeforeA()
{

  if (digitalRead(RVsink) == LOW) {
    MP3B.play(1);
    delay(2000);
  }
  
  if (digitalRead(RVfan ) == LOW) {
    MP3B.play(2);
    delay(2000);
  }
  
  if (digitalRead(RVair ) == LOW) {
    MP3B.play(3);
    delay(2000);
  }
  
  if (digitalRead(RVcan ) == LOW) {
    MP3B.play(4);
    delay(2000);
  }
  
  if (digitalRead(RVmic ) == LOW) {
    MP3B.play(5);
    delay(2000);
  }
  
  if (digitalRead(RVbrk ) == LOW) {
    MP3B.play(6);
    delay(2000);
  }


}


void wait4start() {
  while (digitalRead(StartBut) == HIGH) {
    delay(100);
  }
  while (digitalRead(StartBut) == LOW) {
    delay(100);
  }
  Serial.println("\nSTART pressed\n");
  delay(100);
}


void TESTlockALL() {

  Serial.println("Closing...");
  lcd.setCursor(0, 0);
  lcd.print("Closing...");

  relay20.write(0, LOW);   //
  wait4start();
  relay20.write(1, LOW);   //
  wait4start();
  relay20.write(2, LOW);   //
  wait4start();
  relay20.write(3, LOW);   //
  wait4start();
  relay20.write(4, LOW);   //
  wait4start();
  relay20.write(5, LOW);   //
  wait4start();
  relay20.write(6, LOW);   //
  wait4start();
  relay20.write(7, LOW);   //
  wait4start();

  relay24.write(0, LOW);  //
  wait4start();
  relay24.write(1, LOW);  //
  wait4start();
  relay24.write(2, LOW);  //
  wait4start();
  relay24.write(3, LOW);  //
  wait4start();
  relay24.write(4, LOW);  //
  wait4start();
  relay24.write(5, LOW);  //
  wait4start();
  relay24.write(6, LOW);  //
  wait4start();
  relay24.write(7, LOW);  //
  wait4start();

  relay22.write(0, LOW);  //
  wait4start();
  relay22.write(1, LOW);  //
  wait4start();
  relay22.write(2, LOW);  //
  wait4start();
  relay22.write(3, LOW);  //
  wait4start();
  relay22.write(4, LOW);  //
  wait4start();
  relay22.write(5, LOW);  //
  wait4start();
  relay22.write(6, LOW);  //
  wait4start();
  relay22.write(7, LOW);  //
  wait4start();

  relay23.write(0, LOW);  //
  wait4start();
  relay23.write(1, LOW);  //
  wait4start();
  relay23.write(2, LOW);  //
  wait4start();
  relay23.write(3, LOW);  //
  wait4start();
  relay23.write(4, LOW);  //
  wait4start();
  relay23.write(5, LOW);  //
  wait4start();
  relay23.write(6, LOW);  //
  wait4start();
  relay23.write(7, LOW);  //

  Serial.println("all CLOSED");
  lcd.setCursor(0, 0);
  lcd.print("all CLOSED");

  delay(555);

}



void testBeforeB()
{

  //  sendHLms(propAout, 250);   //turn on soundtrack on DEFIB (and pre-start it)

  //  relay24.write(3, LOW);  // sound dir LOW = LAB, HIGH = CENTER
  //  relay24.write(4, LOW);  // sound dir LOW = LAB, HIGH = CENTER

  while (true) {
    while (digitalRead(StartBut) == HIGH) {
      //      Serial.print("third motorIn = ");
      //      Serial.println(digitalRead(motorIn));
      delay(100);
    }
    //labLightOn();
    Serial.println(" SENT on /  motor start ");
    //      sendHLms(propFout, 250);   //turn on soundtrack on DEFIB (and pre-start it)
    //      sendHLms(propAout, 250);   //turn on soundtrack on DEFIB (and pre-start it)
    lcd.setCursor(0, 0);
    lcd.print(" motor start ");

    //   sendHLms(motorOut, 250);   //motor start

    //        freeWall();

    delay(700);

    while (digitalRead(StartBut) == HIGH) {
      delay(100);
    }
    Serial.println(" SENT off ");

    //labLightOff();

    Serial.println(" UNLOCK / motor sig 18 seconds ");
    //      sendHLms(propAout, 250);   //turn on soundtrack on DEFIB (and pre-start it)
    //     lockWall();

    lcd.setCursor(0, 0);
    lcd.print(" motor move ");

    //    Serial.print("motorIn = ");
    //    Serial.println(digitalRead(motorIn));

    //    digitalWrite(motorOut, HIGH);   //motor ssignal
    delay(27000);
    //   digitalWrite(motorOut, LOW);   //motor ssignal
    delay(500);

    //   Serial.print("first motorIn = ");
    //   Serial.println(digitalRead(motorIn));

    lcd.setCursor(0, 0);
    lcd.print(" motor done tmr ");
    delay(5000);
    //   Serial.print("second motorIn = ");
    //   Serial.println(digitalRead(motorIn));

    openALL();

    //   Serial.print("third motorIn = ");
    //   Serial.println(digitalRead(motorIn));
    //   Serial.println(" done ");

  }
}



void testAfter() {
  /*
    relay23.write(0, HIGH);  // 3RD fan HIGH = ON    DEPENDS ON 7 RELAY
    relay23.write(1, HIGH);  // 1ST fan HIGH = ON
    relay23.write(6, HIGH);  // 2ND fan HIGH = ON

    relay23.write(7, HIGH);  // lab ceiling light HIGH = ON

    //  relay22.write(7, LOW);  // labyrinth door ok

    relay20.write(5, LOW);   //
    relay20.write(6, HIGH);  // centrifuge

    relay24.write(1, LOW);  // lab ceiling fx light
    relay24.write(0, LOW);  // last door ml

    relay24.write(3, HIGH);  // sound dir LOW = LAB, HIGH = CENTER
    relay24.write(4, HIGH);  // sound dir LOW = LAB, HIGH = CENTER

    relay24.write(5, LOW);  // WALL LOCK LOW = LAB, HIGH = CENTER
  */
  //  +  relay22.write(4, LOW);  // MIRROR/LIGHTS  = darkness in both rooms


  // relay23.write(3, HIGH);  // ?

  //  relay23.write(5, LOW);  //

  //  testALL();
  //  openALL();


  //   relay23.write(5, LOW);  // out of service - permanent DAMAGE !!!!!!!!!!!!!
  //   delay(2000);

  /*
    while (true) {

    relay22.write(2, LOW);  // PIC on
    relay20.write(0, LOW);  //book lock
    relay20.write(7, LOW);  //fireplace lock



      while (digitalRead(StartBut) == HIGH) {
        while (digitalRead(StartBut) == LOW) {
          delay(20);
        }
      }

    relay22.write(4, LOW);  // lights off
    delay(250);
    relay22.write(4, HIGH);  // lights on
    delay(250);
    relay22.write(4, LOW);  // lights off
    delay(300);
    relay22.write(4, HIGH);  // lights on
    delay(100);
    relay22.write(4, LOW);  // lights off
    delay(200);
    relay22.write(4, HIGH);  // lights on

      while (digitalRead(StartBut) == HIGH) {
        while (digitalRead(StartBut) == LOW) {
          delay(20);
        }
      }

    relay22.write(2, HIGH);  // PIC fall
    delay(1000);

      while (digitalRead(StartBut) == HIGH) {
        while (digitalRead(StartBut) == LOW) {
          delay(20);
        }
      }

    relay20.write(0, HIGH);  //book fall
    delay(1000);
    }
  */

  /*
    while (true) {

        Serial.print(" capsuMv = ");
        Serial.print(digitalRead(capsuMv));
        Serial.print(" capsuIn = ");
        Serial.println(digitalRead(capsuIn));
        delay(1000);

        sendHLms(propNout, 1000); // turn on PC

    }


    // * 4 x 200ms to cave (as 4 players)
    for (int t = 0; t < 4; t++) {
      sendHLms(propEout, 200);
      delay(500);
    }
  */
}
