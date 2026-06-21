# UI-MT Official Pin Mapping v1

**ESP32 DevKit V1 / ESP32-WROOM-32**

---

## TFT Display + Touch Module

| Display Pin | ESP32 Pin |
| ----------- | --------- |
| VCC         | 3.3V      |
| GND         | GND       |
| CS          | GPIO5     |
| RESET       | GPIO4     |
| DC / RS     | GPIO2     |
| SDI (MOSI)  | GPIO23    |
| SCK         | GPIO18    |
| LED         | 3.3V      |
| SDO (MISO)  | GPIO19    |
| T_CLK       | GPIO18    |
| T_CS        | GPIO15    |
| T_DIN       | GPIO23    |
| T_DO        | GPIO19    |
| T_IRQ       | GPIO34    |

---

## SD Card Module

| SD Pin | ESP32 Pin |
| ------ | --------- |
| VCC    | 3.3V      |
| GND    | GND       |
| SCK    | GPIO18    |
| MOSI   | GPIO23    |
| MISO   | GPIO19    |
| CS     | GPIO13    |

---

## AD9833 Waveform Generator

| AD9833 Pin | ESP32 Pin               |
| ---------- | ----------------------- |
| VCC        | 3.3V                    |
| GND        | GND                     |
| SCLK       | GPIO18                  |
| SDATA      | GPIO23                  |
| FSYNC      | GPIO14                  |
| OUT        | Signal Output Connector |

---

## CardKB Keyboard

| CardKB Pin | ESP32 Pin |
| ---------- | --------- |
| VCC        | 3.3V      |
| GND        | GND       |
| SDA        | GPIO21    |
| SCL        | GPIO22    |

---

## RTC Module (DS3231)

| RTC Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 3.3V      |
| GND     | GND       |
| SDA     | GPIO21    |
| SCL     | GPIO22    |

---

## External I²C Sensor Port

| Connector Pin | Signal | ESP32 Pin |
| ------------- | ------ | --------- |
| 1             | 3.3V   | 3.3V      |
| 2             | GND    | GND       |
| 3             | SDA    | GPIO21    |
| 4             | SCL    | GPIO22    |

---

## UART Terminal Port

| Connector Pin | Signal         | ESP32 Pin |
| ------------- | -------------- | --------- |
| 1             | GND            | GND       |
| 2             | TX             | GPIO17    |
| 3             | RX             | GPIO16    |
| 4             | 3.3V Reference | 3.3V      |

---

## GPIO Logic Probe Port

| Connector Pin | Signal         | ESP32 Pin |
| ------------- | -------------- | --------- |
| 1             | GND            | GND       |
| 2             | Probe 1        | GPIO35    |
| 3             | Probe 2        | GPIO36    |
| 4             | Probe 3        | GPIO39    |
| 5             | 3.3V Reference | 3.3V      |

---

## PWM Output Port

| Connector Pin | Signal         | ESP32 Pin |
| ------------- | -------------- | --------- |
| 1             | GND            | GND       |
| 2             | PWM OUT 1      | GPIO25    |
| 3             | PWM OUT 2      | GPIO26    |
| 4             | 3.3V Reference | 3.3V      |

---

## Buzzer

| Buzzer Pin | ESP32 Pin |
| ---------- | --------- |
| Signal     | GPIO27    |
| GND        | GND       |

---

## Battery Monitor

| Function    | ESP32 Pin |
| ----------- | --------- |
| Battery ADC | GPIO32    |

Recommended:

```text
Battery +
    |
   100k
    |
GPIO32
    |
   100k
    |
   GND
```

---

## Reserved Expansion

| ESP32 Pin | Purpose                      |
| --------- | ---------------------------- |
| GPIO33    | Extra ADC / Future Expansion |

---

## Shared SPI Bus

| Signal | ESP32 Pin |
| ------ | --------- |
| SCK    | GPIO18    |
| MOSI   | GPIO23    |
| MISO   | GPIO19    |

### SPI Device Selects

| Device           | CS / Control Pin |
| ---------------- | ---------------- |
| TFT Display      | GPIO5            |
| Touch Controller | GPIO15           |
| SD Card          | GPIO13           |
| AD9833           | GPIO14           |

---

## Shared I²C Bus

| Signal | ESP32 Pin |
| ------ | --------- |
| SDA    | GPIO21    |
| SCL    | GPIO22    |

### I²C Devices

* CardKB Keyboard
* DS3231 RTC
* External I²C Sensor Port

---

## GPIO Usage Summary

| GPIO   | Function      |
| ------ | ------------- |
| GPIO2  | TFT DC        |
| GPIO4  | TFT RESET     |
| GPIO5  | TFT CS        |
| GPIO13 | SD CS         |
| GPIO14 | AD9833 FSYNC  |
| GPIO15 | Touch CS      |
| GPIO16 | UART RX       |
| GPIO17 | UART TX       |
| GPIO18 | SPI SCK       |
| GPIO19 | SPI MISO      |
| GPIO21 | I²C SDA       |
| GPIO22 | I²C SCL       |
| GPIO23 | SPI MOSI      |
| GPIO25 | PWM OUT 1     |
| GPIO26 | PWM OUT 2     |
| GPIO27 | Buzzer        |
| GPIO32 | Battery ADC   |
| GPIO33 | Reserved      |
| GPIO34 | Touch IRQ     |
| GPIO35 | Logic Probe 1 |
| GPIO36 | Logic Probe 2 |
| GPIO39 | Logic Probe 3 |

This leaves **GPIO33 available for future UI-MT expansion** while supporting all currently locked project objectives.
