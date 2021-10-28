#include "DigiKeyboard.h"

void setup() {
    DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.println("cmd.exe");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(0,KEY_ENTER);
}
void loop() {
}
