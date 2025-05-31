# EdgeDetector Library

## Beschreibung
Diese Library erkennt steigende und fallende Flanken an digitalen Eingängen mit optionaler Entprellung. Sie verwendet direkten Registerzugriff, um besonders schnell und zuverlässig zu arbeiten.

## Funktionen

### Konstruktor
```cpp
EdgeDetector(uint8_t pin, uint16_t debounceMs = 50);
```
- `pin`: Arduino-Digitalpin
- `debounceMs`: optionale Entprellzeit in Millisekunden (Standard: 50 ms)

### Methoden
```cpp
void update();
bool rising();
bool falling();
```
- `update()`: liest den Pin und erkennt Flanken
- `rising()`: true, wenn eine positive Flanke erkannt wurde
- `falling()`: true, wenn eine negative Flanke erkannt wurde

## Beispiel
Siehe `examples/FlankenDemo/FlankenDemo.ino`.

## Anwendung
1. ZIP in Arduino IDE über „Sketch > Bibliothek einbinden > ZIP-Bibliothek hinzufügen“ importieren.
2. `#include <EdgeDetector.h>` im Sketch verwenden.
3. `update()` regelmäßig in `loop()` aufrufen.
