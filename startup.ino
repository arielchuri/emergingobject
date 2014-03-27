void monitor() { 
  Serial.print("light = ");
  Serial.print(lightValue);
  Serial.print("\t touch = "); // The "\t" character is a tab space to clean up the read out.
  Serial.print(capSense);
  Serial.println("");
  digitalWrite(aLED, aLEDstate); 
  aLEDstate = !aLEDstate;    
}

void startUp() {
   Serial.println("\n");
//   logo();
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
    digitalWrite(ledPins[thisPin], HIGH);   
    delay(30);              
    digitalWrite(ledPins[thisPin], LOW);
Serial.print(thisPin);    
  }
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) { 
    digitalWrite(ledPins[thisPin], HIGH);
    delay(30);
    digitalWrite(ledPins[thisPin], LOW);
    Serial.print(thisPin);
  }
   Serial.println(" STARTUP!");
}

void logo() {
Serial.println("                                    -----  ");
Serial.println("                       -----       (     )  ");
Serial.println("            -------   (     )       -----   ");
Serial.println("          -/       \\-  |    ------             -------------  -+  ");
Serial.println("         /     *     \\/           \\---    ----/             \\/  \\+   ");
Serial.println(" _       |        *                   \\--/                        \\-+");
Serial.println("( )     -\\      *  *                                                 \\ ");
Serial.println(" `   --/      *                                                       \\");
Serial.println("    /        +-+                        _   _       _      _           \\");
Serial.println("    |        | |      ____ __  __ _ _ _| |_| |___  | |__ _| |__ ___TM   \\");
Serial.println("    \\       /   \\    (_-< '_ \\/ _` | '_| / / / -_) | / _` | '_ (_-<      \\");
Serial.println("    -+     / ^_^ \\   /__/ .__/\\__,_|_| |_\\_\\_\\___| |_\\__,_|_.__/__/      |");
Serial.println("   /       \\_____/      |_|                                              /");
Serial.println("  (                                                                     / ");
Serial.println("   \\                   f e e l   r e a c t   t h i n k   s e n d       / ");
Serial.println("    \\-+                                                               /");
Serial.println("       \\-----+                                                      /");
Serial.println("             |                         +-+                       /-/");
Serial.println("             \\                  +-----/   \\---\\             /---/");
Serial.println("              -+               /               \\-----------/");
Serial.println("                \\-+         +-/");
Serial.println("                   \\-------/");
Serial.println("");
delay(10);
}

