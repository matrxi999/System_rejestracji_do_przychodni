#ifndef LEKARZ_H
#define LEKARZ_H
#include <iostream>

using namespace std;


class Lekarz
{
    public:

    string imie, nazwisko, specjalizacja, miesiac, dzien, wizyty;
    int godzina_roz, godzina_kon, nr_lekarza;

    void wczytaj();
    void zapisz();
    void wyswietl();
    void wyswietlGodz(string Dzien, string MiesiacINT);
    void zapisNaWizyte(string Dzien, string Miesiac);
};

#endif // LEKARZ_H
