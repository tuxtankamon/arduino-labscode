#include <LiquidCrystal.h>
// Inicializa la libreria con los numeros de pines de la lcd
const int rs = 6, en = 7, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2); // Configura el tamaño de la lcd en columnas y filas
}
void loop() {
  // Corre todas las funciones de demostracion de la lcd
  basicPrintDemo();
  displayOnOffDemo();
  setCursorDemo();
  scrollLeftDemo();
  scrollRightDemo();
  cursorDemo();
  createGlyphDemo();
}

void basicPrintDemo() {
  lcd.clear(); // Limpia Pantalla
  lcd.print("Hola Mundo"); // Imprime el texto
  delay(2000);
}

void displayOnOffDemo() {
  lcd.clear();
  lcd.print("Display On/Off");
  for (int x = 0; x < 3; x++) { // Repite el ciclo 3 veces
    lcd.noDisplay(); // Apaga el display
    delay(1000);
    lcd.display(); // Vuelve a encender el display
    delay(1000);
  }
}

void setCursorDemo() {
  lcd.clear();
  lcd.print("SetCursor Demo");
  delay(1000);
  lcd.clear();
  lcd.setCursor(5, 0); // Ubica el Cursor en la columna 5 y fila 0
  lcd.print("5,0");
  delay(2000);
  lcd.setCursor(10, 1); //Ubica el Cursor en la columna 10 y fila 1
  lcd.print("10,1");
  delay(2000);
  lcd.setCursor(3, 1); // Ubica el Cursor en la columna 3 y fila 1
  lcd.print("3,1");
  delay(2000);
}

void scrollLeftDemo() {
  lcd.clear();
  lcd.print("Scroll Left Demo");
  delay(1000);
  lcd.clear();
  lcd.setCursor(10, 0);
  lcd.print("Hola");
  lcd.setCursor(10, 1);
  lcd.print("Mundo");
  delay(1000);
  for (int x = 0; x < 16; x++) {
    lcd.scrollDisplayLeft(); //Desplaza el texto a la izquierda 16 veces
    delay(250);
  }
}

void scrollRightDemo() {
  lcd.clear();
  lcd.print("Scroll Right");
  lcd.setCursor(0, 1);
  lcd.print("Demo");
  delay(1000);
  lcd.clear();
  lcd.print("Hola");
  lcd.setCursor(0, 1);
  lcd.print("Mundo");
  delay(1000);
  for (int x = 0; x < 16; x++) {
    lcd.scrollDisplayRight(); //Desplaza el texto a la derecha 16 veces
    delay(250);
  }
}

void cursorDemo() {
  lcd.clear();
  lcd.cursor(); // Habilita el cursor visible
  lcd.print("Cursor On");
  delay(3000);
  lcd.clear();
  lcd.noCursor(); //Cursor invisible
  lcd.print("Cursor Off");
  delay(3000);
  lcd.clear();
  lcd.cursor();
  lcd.blink(); // Cursor blinking
  lcd.print("Cursor Blink On");
  delay(3000);
  lcd.noCursor(); // Cursor invisible
  lcd.noBlink(); // Blink off
}

void createGlyphDemo() {
  lcd.clear();
  byte heart[8] = {//Crea un caracter de corazon
    0b00000, 0b01010, 0b11111, 0b11111, 0b11111, 0b01110, 0b00100, 0b00000
  };
  byte happy[8] = {//Crea un caracter de cara feliz
    B00000, B00000, B10001, B00000, B10001, B01110, B00000, B00000
  };
  byte sad[8] = {//Crea un caracter de cara triste
    B00000, B00000, B10001, B00000, B01110, B10001, B00000, B00000
  };

  lcd.createChar(0, heart); // Create custom character 0
  lcd.createChar(1, happy); // Create custom character 1
  lcd.createChar(2, sad); // Create custom character 2

  lcd.setCursor(1, 0);
  lcd.print("I ");
  lcd.write(byte(0)); // escribe el caracter como un byte
  lcd.print(" Arduino! ");
  lcd.write(byte(1));
  delay(1000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Trust Me");
  lcd.setCursor(0, 1);
  lcd.print("I'm an Engineer");
  for (int x = 0; x < 5; x++) { // Loop animation 5 times
    lcd.setCursor(15, 1);
    lcd.write(byte(1)); // Write custom char 1
    delay(1000);
    lcd.setCursor(15, 1);
    lcd.write(byte(2)); // Write custom char 2
    delay(1000);
  }
}
