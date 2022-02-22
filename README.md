# Autor

Vadym Liss, 257264

Zaliczyłem dany projekt i otrzymiałem 34 miejsce

Wszystkie szczegóły dotyczące technicznych warunków projektu są w podanym pliku https://github.com/Foxxich/CompilerProject/blob/master/instructions.pdf

# Uruchomienie

W celu uruchomienia należy wpisać do terminalu: `make`,
a po kompilowaniu: `./compiler <plik wejściowy> <plik wyjściowy>`

# Technologie
Do napisania kompilatora zostały użyte następujące narzędzia:

- <b>Flex</b> w wersji 2.6.4,
- <b>Bison</b> w wersji 3.0.4,
- <b>g++</b> w wersji 8.2.0,
- <b>GNU Make</b> w wersji 4.2.1.

Kompilator został napisany i przetestowany pod systemem `Ubuntu `. Wykorzystano język `C++` w standardzie <b>`C++17`</b>.

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

# Foldery

- maszyna_wirtualna umieszcza w sobie maszynę wirtualną, którą trzeba skompilować poleceniem `make` i dalej dodać do folderu 
`<plik wyjściowy>` i skompilować poleceniem `./maszyna_wirtualna <plik wyjściowy>`
- testy umieszcza w sobie wszystkie testy potrzebne do zaliczenia kompilatora (szczególnie uwaga jest zwracana na te zwykłe testy, 
a nie dodatkowe)

# Gramatyka dla danego języka

program      -> VAR declarations BEGIN commands END
| BEGIN commands END

declarations -> declarations, pidentifier
| declarations, pidentifier[num:num]
| pidentifier
| pidentifier[num:num]

commands     -> commands command
| command

command      -> identifier ASSIGN expression;
| IF condition THEN commands ELSE commands ENDIF
| IF condition THEN commands ENDIF
| WHILE condition DO commands ENDWHILE
| REPEAT commands UNTIL condition;
| FOR pidentifier FROM value TO value DO commands ENDFOR
| FOR pidentifier FROM value DOWNTO value DO commands ENDFOR
| READ identifier;
| WRITE value;

expression   -> value
| value PLUS value
| value MINUS value
| value TIMES value
| value DIV value
| value MOD value

condition    -> value EQ value
| value NEQ value
| value LE value
| value GE value
| value LEQ value
| value GEQ value

value        -> num
| identifier

identifier   -> pidentifier
| pidentifier[pidentifier]
| pidentifier[num]

# Przykładowy program

    1 [ Rozkład liczby na czynniki pierwsze ]
    2 DECLARE
    3 n, m, reszta , potega , dzielnik
    4 BEGIN
    5 READ n;
    6 dzielnik := 2;
    7 m := dzielnik * dzielnik ;
    8 WHILE n >= m DO
    9 potega := 0;
    10 reszta := n % dzielnik ;
    11 WHILE reszta = 0 DO
    12 n := n / dzielnik ;
    13 potega := potega + 1;
    14 reszta := n % dzielnik ;
    15 ENDWHILE
    16 IF potega > 0 THEN [ czy znaleziono dzielnik ]
    17 WRITE dzielnik ;
    18 WRITE potega ;
    19 ELSE
    20 dzielnik := dzielnik + 1;
    21 m := dzielnik * dzielnik ;
    22 ENDIF
    23 ENDWHILE
    24 IF n != 1 THEN [ ostatni dzielnik ]
    25 WRITE n;
    26 WRITE 1;
    27 ENDIF
    28 END

# Szczegóły

- W danym projekcie obowiązkołym warunkiem jest skorzystanie z 8 rejestrów
- Czas wykorzystany na napisane - 5 tygodni
- To kosztowało dużo nerwów i czasu, ale zaliczenie danego legendarnego przedmiotu opłaca się
- Jeżeli wybierać prowadzącego - tylko dr. Gębala albo dr. Gotfryd