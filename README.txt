Witam w moim projekcie, systemie do rejestracji w przychodni.

Otwierając projekt jesteśmy witani przez okno w którym widzimy:
-Przycisk "Start", służący do załadowania z pliku listy lekarzy, z której 
będziemy mogli potem wybrać interesującego nas lekarza.

-Pole tekstowe "Lista lekarzy", w którym program wyświetla lekarzy pasujących do wybranych przez
nas atrybutów (specjalizacja, miesiąc, dzień, numer lekarza)

-Wybór specjalizacji, gdzie możemy wybrać specjalizacje która nas interesuje

-Wybór miesiąca, gdzie wybieramy miesiąc w którym chcemy się zapisać do lekarza

-Wybór dnia, gdzie wybieramy dzień w którym chcemy się zapisać do lekarza

-Wybór numeru lekarza, gdzie wybieramy numer konkretnego lekarza do którego chcemy się zapisać.

-Wybór godziny, gdzie wpisujemy godzine na którą chcemy się zapisać.

-Przycisk "Umów wizytę", który zatwierdza wybraną przez nas wizytę i zapisuje ją do pliku tekstowego w celu jej potwierdzenia.


Korzystanie z programu należy rozpocząć oczywiście od kliknięcia przycisku start, który załaduje listę lekarzy z pliku tekstowego
do naszego programu (Tablicy Lekarz L). Wyświetli się ona od razu w polu tekstowym "lista lekarzy".

Następnie z pola typu comboBox należy wybrać interesującą nas specjalizacje. Po wybraniu specjalizacji, w polu "Lista lekarzy", wyświetlają
się tylko lekarze, ze specjalizacją, która nas interesuje.

Ten sam proces należy powtórzyć dla wyboru miesiąca oraz dnia.

Jedyna różnica polega na tym, że po wyborze odpowiedniego dnia, lista lekarzy jest rozszerzana o pola : "Godzina rozpoczecia pracy lekarza",
"Godzina konca pracy lekarza" oraz "Zajęte wizyty", co pozwoli nam łatwiej wybrać konkretną godzinę na którą chcemy się zapisać.

Kiedy już wszystko wybierzemy, program wyświetli nam tylko lekarzy, pasujących do naszych kretyriów. musimy wybrać numer lekarza do którego się chcemy zapisać,
oraz wpisać jego numer w polu "Numer lekarza"

Powinien wyświetlić się nam tylko ten jeden, wybrany przez nas lekarz.

Teraz należy wybrać godzinę na którą się chcemy zapisać, po czym trzeba wpisać ją w pole "wybór godziny"
Jako że interwały wizyt są 15-minutowe, jedynie można zapisać się na godziny x:00 ; x:15 ; x:30 i x:45
Próba zapisania się na jakąkolwiek inną godzinę (np x:36) zakończy się niepowodzeniem.
Należy zwrócić również uwagę na to aby nasza godzina mieściła się między godziną rozpoczącia pracy lekarza a godziną końca pracy lekarza, w przeciwnym razie 
nie uda się nam zapisać na wiztę.

Kiedy wpisaliśmy już odpowiednią godzinę, klikamy enter i zostaje ona dodana w polu "Zajęte wizyty" naszego lekarza.

Przycisk "Umów wizytę" służy do zapisu naszej wizyty spowrotem do pliku tekstowego.
Przy następnym odpaleniu programu, lekarz ten będzie miał tą wizytę zajętą i nie będzie się dało ponownie na nią zapisać



