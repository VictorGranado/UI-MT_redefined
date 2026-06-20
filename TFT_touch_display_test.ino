#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

TFT_eSPI tft = TFT_eSPI();

// Touch (XPT2046)
#define TOUCH_CS   15
#define TOUCH_IRQ  27   // optional; if not wired, you can still read touch
XPT2046_Touchscreen ts(TOUCH_CS, TOUCH_IRQ);

// Screen size for ILI9488 in TFT_eSPI is typically 320x480 (portrait)
// We'll use tft.width()/tft.height() so rotation is handled.

void drawTestScreen() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("ILI9488 + XPT2046 Test");
  tft.println("Touch to draw dots");
  tft.println("Watch Serial for X/Y");
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_DARKGREY);
}

void setup() {
  Serial.begin(115200);
  delay(200);

  // SPI bus init happens inside libraries, but touch library needs SPI begin sometimes:
  SPI.begin(18, 19, 23); // SCK, MISO, MOSI (VSPI pins)

  // TFT
  tft.init();
  tft.setRotation(1); // 0/1/2/3 try as needed
  drawTestScreen();

  // Touch
  ts.begin();
  // IMPORTANT: XPT2046 often needs the same rotation sense as the display.
  // We'll start with matching rotation and you can tweak with setRotation(0-3).
  ts.setRotation(1);

  Serial.println("Ready. Touch the screen.");
}

void loop() {
  // Simple color wipe every few seconds (optional quick visual check)
  static uint32_t last = 0;
  static int phase = 0;

  if (millis() - last > 2500) {
    last = millis();
    phase = (phase + 1) % 4;
    if (phase == 0) tft.fillRect(0, 70, tft.width(), 40, TFT_RED);
    if (phase == 1) tft.fillRect(0, 70, tft.width(), 40, TFT_GREEN);
    if (phase == 2) tft.fillRect(0, 70, tft.width(), 40, TFT_BLUE);
    if (phase == 3) tft.fillRect(0, 70, tft.width(), 40, TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setCursor(10, 80);
    tft.print("Color phase: ");
    tft.print(phase);
  }

  if (ts.touched()) {
    TS_Point p = ts.getPoint();

    // Raw values from XPT2046 are ~0-4095, not pixel coordinates.
    // We'll print raw first, and also do a quick mapping that you can calibrate.
    Serial.printf("RAW touch: x=%d y=%d z=%d\n", p.x, p.y, p.z);

    // QUICK mapping (needs calibration per panel!)
    // These min/max guesses might be off; we'll refine after you see Serial values.
    int16_t xMin = 300, xMax = 3800;
    int16_t yMin = 300, yMax = 3800;

    int16_t x = map(p.x, xMin, xMax, 0, tft.width());
    int16_t y = map(p.y, yMin, yMax, 0, tft.height());

    // clamp
    if (x < 0) x = 0;
    if (x >= tft.width()) x = tft.width() - 1;
    if (y < 0) y = 0;
    if (y >= tft.height()) y = tft.height() - 1;

    // Draw a dot where touched
    tft.fillCircle(x, y, 3, TFT_YELLOW);

    delay(20); // debounce-ish
  }
}
