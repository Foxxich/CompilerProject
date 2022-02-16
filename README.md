# Autor

Vadym Liss, 257264

# Uruchomienie

W celu uruchomienia należy wpisać do terminalu: `make`,
a po kompilowaniu: `./compiler <plik wejściowy> <plik wyjściowy>`

# Pliki

- `Logic.hpp` - klasa w której mamy implementacje najważniejszych algorytmów
  wykorzystywanych do generacji kodu w assamblerze, tzn algorytmy
  dzielenia, mnożenia, modulo i proste dodawanie/odejmowanie
- `Defs.hpp` - klasa potrzebna do ustalenia mapy z rejestrami,
  zdefinowania struktur instrukcji, var, zmiennej, iteratorów oraz labelów for
- `Data.hpp` - klasa w której tworzymy, modyfikujemy tablicę symboli, identyfikatory,
  iterator oraz wartości. Także w podanej klasie inicjalizujemy symboli korzystając
  z pewnej definicji symboli
- `Memory.hpp` - klasa w której są wszystkie operacje powiązane z generacją kodu, który odpowiada
  za dodanie elementów do pamięci czy ich pobranie, wczytanie czy nawet proste wypisywanie, tzn operacje 'read' i 'write',
  lub 'assign' i 'load var'
- `Loops.hpp` - klasa w której mamy definicje instrukcji warunkowych oraz pętli
- `Lexer.l` - lekser języka wejściowego
- `Parser.ypp` - parser języka wejściowego
- `Parser.tab.cpp` - wygenerowany parser za pomocą Bisona
- `Parser.tab.hpp` - wygenerowany parser za pomocą Bisona
