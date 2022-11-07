#include <ESP8266WiFi.h>

#define ledpin 16 // GPIO1/TXD01
#define MCU_EN 15
#define MCU_CLK 13
#define MCU_DATA 12
#define CLK 80

// Имя и пароль вашей сети WiFi
const char* ssid = "TP-Link_BBD7"; // BLACK WIRE
const char* password = "xxxxxxxx";

// Создаем сервер и порт для прослушки 80
WiFiServer server(80);

// Текст сообщения
byte message = 0b00000000;
byte prevMessage = 0b00000000;

void setup() {

Serial.begin(115200);
  delay(10);
  
pinMode(ledpin, OUTPUT);
pinMode(MCU_EN, OUTPUT);
pinMode(MCU_CLK, OUTPUT);
pinMode(MCU_DATA, OUTPUT);
digitalWrite(ledpin, HIGH);
digitalWrite(MCU_EN, HIGH);
digitalWrite(MCU_CLK, HIGH);
digitalWrite(MCU_DATA, HIGH);

// Подключаемся к сети WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
// Ожидание подключения
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Запуск сервера
  server.begin();
  Serial.println("Server started");

  // Вывод полученного IP адреса
  Serial.println(WiFi.localIP());


}



void loop() {

//  // Проверка подключения
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Ожидание данных
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Чтение первой строки запроса
  String req = client.readStringUntil('\r');
  String value = "1";
  Serial.println(req);
  client.flush();


//   Работа с запросом
  if (req.indexOf("/SmartHouse/ESP32GWC/00000000") != -1)             // Основное освещение (по умолчанию)
    message = 0b00000000;  
//  else if (req.indexOf("/SmartHouse/ESP32GWC/00100000") != -1)        // Общие настройки
//    message = 0b00100000;
//  else if (req.indexOf("/SmartHouse/ESP32GWC/00100001") != -1)        // Влево
//    message = 0b00100001;
//  else if (req.indexOf("/SmartHouse/ESP32GWC/00100010") != -1)        // Вправо
//    message = 0b00100010;
//  else if (req.indexOf("/SmartHouse/ESP32GWC/00100011") != -1)        // Вверх
//    message = 0b00100011;
//  else if (req.indexOf("/SmartHouse/ESP32GWC/00100100") != -1)        // Вниз
//    message = 0b00100100;
//  else if (req.indexOf("/SmartHouse/ESP32GWC/00100101") != -1)        // Ок
//    message = 0b00100101;
//  else if (req.indexOf("/SmartHouse/ESP32GWC/00100110") != -1)        // Обновить данные
//    ;  
//  else if (req.indexOf("/SmartHouse/ESP32GWC/01000000") != -1)        // Стереосистема и основное освещение
//    message = 0b01000000;
//  else if (req.indexOf("/SmartHouse/ESP32GWC/10000000") != -1)        // Отключить все
//    message = 0b10000000;
//  else if (req.indexOf("/SmartHouse/ESP32GWC/10100000") != -1)        // Динамическое или интерьерное освещение
//    message = 0b10100000;
  else if (req.indexOf("/SmartHouse/ESP32GWC/10100001") != -1)        // Случайный режим интерьерного освещение
    message = 0b10100001;
  else if (req.indexOf("/SmartHouse/ESP32GWC/10100010") != -1)        // Постоянный свет
    message = 0b10100010;
  else if (req.indexOf("/SmartHouse/ESP32GWC/10100011") != -1)        // Плавная смена цвета
    message = 0b10100011;
  else if (req.indexOf("/SmartHouse/ESP32GWC/10100100") != -1)        // Бегущая радуга
    message = 0b10100100;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11000000") != -1)        // Стереосистема
    message = 0b11000000;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11100000") != -1)        // Случайный режим динамического освещения
    message = 0b11100000;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11100001") != -1)        // Шкала громкости (градиент)
    message = 0b11100001;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11100010") != -1)        // Шкала громкости (радуга)
    message = 0b11100010;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11100011") != -1)        // Цветомузыка (5 полос)
    message = 0b11100011;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11100100") != -1)        // Цветомузыка (3 полосы)
    message = 0b11100100;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11100101") != -1)        // Цветомузыка (1 полоса - 3 частоты)
    message = 0b11100101;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11100110") != -1)        // Цветомузыка (1 полоса - низкие)
    message = 0b11100110;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11100111") != -1)        // Цветомузыка (1 полоса - средние)
    message = 0b11100111;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11101000") != -1)        // Цветомузыка (1 полоса - высокие)
    message = 0b11101000;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11101001") != -1)        // Стробоскоп
    message = 0b11101001;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11101010") != -1)        // Бегущие частоты (3 частоты)
    message = 0b11101010;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11101011") != -1)        // Бегущие частоты (низкие)
    message = 0b11101011;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11101100") != -1)        // Бегущие частоты (средние)
    message = 0b11101100;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11101101") != -1)        // Бегущие частоты (высокие)
    message = 0b11101101;
  else if (req.indexOf("/SmartHouse/ESP32GWC/11101110") != -1)        // Анализатор спектра
    message = 0b11101110;
  else if (req.indexOf("/SmartHouse/ESP32GWC/001") != -1) {            // Режим изменения цвета
    message = 0b00100000;
    int j = 4;
    for (int i = 29; i < 34; i++) {
      if (req[i] = '0') {
        bitSet(message, j);
      }
      j = j - 1;
    }
  }
  else if (req.indexOf("/SmartHouse/ESP32GWC/011") != -1) {            // Режим изменения скорости;
    message = 0b01100000; 
    int j = 4;
    for (int i = 29; i < 34; i++) {
      if (req[i] == '1') {
        bitSet(message, j);
      }
      j = j - 1;
    }
  }
  else message = 0b00000000;

  

  client.flush();



  // Формирование ответа
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\command is 0b";
  for (int i = 7; i > -1; i--) {
    if (bitRead(message, i)) {
      s += "1";
    } else {
      s += "0";
    }
    
  }   
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");
    
    digitalWrite(MCU_EN, 0);
    
    
    for (int i = 0; i < 8; i++) {
       delay(CLK);
       digitalWrite(MCU_CLK, 0);
       digitalWrite(MCU_DATA, !bitRead(message, i));
       delay(CLK);
       digitalWrite(MCU_CLK, 1);
    }
    delay(CLK);
    digitalWrite(MCU_EN, 1);

}
