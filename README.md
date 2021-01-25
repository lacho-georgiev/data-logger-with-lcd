# WiFi-data-logger
WiFi configurable data logger - logs temperature and 2 channel voltage to InfluxDB server

### TO COMPILE IN ARDUINO
1. open Arudnino Preferences
2. in `Additional Boards Manager URL's` paste "https://arduino.esp8266.com/stable/package_esp8266com_index.json"
3. From Tools bar choose Node mcu 1.0
4. Sketch -> Include Library -> RTClib by Adafruit
5. Sketch -> Include Library -> ADS1X15 by Adafruit

### TO COMPILE IN VisualStudioCode
Follow the steps in https://docs.platformio.org/en/latest/integration/ide/vscode.html#quick-start
