void monitor() { 
  Serial.print("L = ");
  Serial.print(lightValue);
  Serial.print("\t T = "); // The "\t" character is a tab space to clean up the read out.
  Serial.print(capSense);
  Serial.print("\t state = "); 
  Serial.print(state);
  Serial.print("\t darkLimit = "); 
  Serial.print(darkLimit);
  Serial.print("\t touchTimer = "); 
  Serial.print(touchTimer);
  Serial.println("");
  digitalWrite(aLED, aLEDstate); 
  aLEDstate = !aLEDstate;    
}

void startUp() {
   Serial.println("\n");
//   logo();
//  schematic();
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
/*
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
*/
void schematic() {
Serial.println("");
Serial.println("                                      +--------+  ");
Serial.println("                                      | TOUCH  |  ");
Serial.println("                                      | SENSOR |  ");
Serial.println("                                      |        |  ");
Serial.println("                                      +------  |  ");
Serial.println("                 ARDUINO                       |  ");
Serial.println("              +-----------+                    |  ");
Serial.println("              |        GND|-----------------+  |  ");
Serial.println("              |           |                 |  |  ");
Serial.println("              |         13|                 |  |  ");
Serial.println("              |         12|                 |  |  ");
Serial.println("              |        ~11|-[R220]--[LED>]--O  |  ");
Serial.println("              |        ~10|-[R220]--[LED>]--O  |  ");
Serial.println("  +--[PHOTO]--|5V       ~9|-[R220]--[LED>]--O  |  ");
Serial.println("  |           |GND       8|                 |  |  ");
Serial.println("  O---[R10K]--|GND       7|                 |  |  ");
Serial.println("  |           |         ~6|-[R220]--[LED>]--O  |  ");
Serial.println("  +-----------|A0       ~5|-[R220]--[LED>]--O  |  ");
Serial.println("              |A1        4|----[R1M]--------+--O  ");
Serial.println("              |A2       ~3|-[R220]--[LED>]--+  |  ");
Serial.println("              |A3        2|--------------------+  ");
Serial.println("              |A4        1|                       ");
Serial.println("              +-----------+                       ");
}

