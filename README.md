![PROJECT_PHOTO](https://github.com/StanislavSokolov/SmartHouse/blob/main/ColorMusic-master/schemes/USsmarthouse.png)
# Устройство управления светомузыкой на ESP32 и Arduino NANO

ColorMusic-master для Arduino Nano.
SmartHouseESP32GWC для Node MCU ESP32.

За основу проекта для Nano взят проект от AlexGyver (версия прошивки colorMusic_v2.10), за что ему огромное спасибо. Дополнительную информацию о возможностях и настройках исходного проекта можно узнать у разработчика. В код добавлен протокол сериального интерфейса между Nano и ESP32, в котором реализована передача команд управления режимами работы ленты от ESP32 к Nano.

Проект для ESP32 основан на примере использования WiFi сетей для Node MCU. Команды для ESP32 формируются приложением https://github.com/StanislavSokolov/SmartHouseMA с пользовательским интерфейсом и через глобальную сеть доставляются к устройству.

Оба модуля установлены на плате согласования, подготовленной в рамках разработки универсального модуля управления "умный дом". На стойках "вторым" этажом установлен четырехканальный модуль  SRD-05VDC-SL-C для переключения основного освещения на светодиодную ленту.

![PROJECT_PHOTO](https://github.com/StanislavSokolov/SmartHouse/blob/main/ColorMusic-master/schemes/4-channels-relay-4.jpg)
