#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <functional>
#include <regex>
#include "Lekarz.h"

using namespace std;

void Lekarz::wczytaj()
{

    ifstream Lekarze;
    Lekarze.open("../System_rejestracji_przychodni_GUI/Lekarze.txt", ios::in);

    int nr_linii=(nr_lekarza-1)*8+1;
    int aktualny_nr=1;
    string linia;

    while(getline(Lekarze, linia))
    {
        if(aktualny_nr==nr_linii) imie=linia;
        if(aktualny_nr==nr_linii+1) nazwisko=linia;
        if(aktualny_nr==nr_linii+2) specjalizacja=linia;
        if(aktualny_nr==nr_linii+3) miesiac=linia;
        if(aktualny_nr==nr_linii+4) dzien=linia;
        if(aktualny_nr==nr_linii+5) godzina_roz=atoi(linia.c_str());
        if(aktualny_nr==nr_linii+6) godzina_kon=atoi(linia.c_str());
        if(aktualny_nr==nr_linii+7) wizyty=linia;
        aktualny_nr++;
    }
    Lekarze.close();
}

void Lekarz::zapisz()
{

    if(nr_lekarza==1)
    {
        ofstream Lekarze;
        Lekarze.open("../System_rejestracji_przychodni_GUI/Lekarze.txt", ios::out);

        int nr_linii=(nr_lekarza-1)*8+1;
        int aktualny_nr=1;

        for(int i=0; i<8; i++)
        {
            if(aktualny_nr==nr_linii) Lekarze <<imie << "\n";
            if(aktualny_nr==nr_linii+1) Lekarze <<nazwisko<< "\n";
            if(aktualny_nr==nr_linii+2) Lekarze <<specjalizacja<< "\n";
            if(aktualny_nr==nr_linii+3) Lekarze <<miesiac<< "\n";
            if(aktualny_nr==nr_linii+4) Lekarze <<dzien<< "\n";
            if(aktualny_nr==nr_linii+5) Lekarze <<godzina_roz<< "\n";
            if(aktualny_nr==nr_linii+6) Lekarze <<godzina_kon<< "\n";
            if(aktualny_nr==nr_linii+7) Lekarze <<wizyty<< "\n";
            aktualny_nr++;
        }

        Lekarze.close();
    }
    else if(nr_lekarza>1)
    {
        ofstream Lekarze;
        Lekarze.open("../System_rejestracji_przychodni_GUI/Lekarze.txt", ios::out | ios::app);

        int nr_linii=(1-1)*8+1;
        int aktualny_nr=1;
        string linia;

        for(int i=0; i<8; i++)
        {
            if(aktualny_nr==nr_linii) Lekarze <<imie << "\n";
            if(aktualny_nr==nr_linii+1) Lekarze <<nazwisko<< "\n";
            if(aktualny_nr==nr_linii+2) Lekarze <<specjalizacja<< "\n";
            if(aktualny_nr==nr_linii+3) Lekarze <<miesiac<< "\n";
            if(aktualny_nr==nr_linii+4) Lekarze <<dzien<< "\n";
            if(aktualny_nr==nr_linii+5) Lekarze <<godzina_roz<< "\n";
            if(aktualny_nr==nr_linii+6) Lekarze <<godzina_kon<< "\n";
            if(aktualny_nr==nr_linii+7) Lekarze <<wizyty<< "\n";
            aktualny_nr++;
        }

        Lekarze.close();
    }
}

void Lekarz::wyswietl()
{
    cout << "Numer Lekarza: " << nr_lekarza << endl;
    cout << "Imie Lekarza: " <<imie << endl;
    cout << "Nazwisko Lekarza: " <<nazwisko << endl;
    cout << "Specjalizacja Lekarza: " <<specjalizacja << endl;
    cout << endl;
}

void Lekarz::wyswietlGodz(string Dzien, string MiesiacINT)
{
    cout << "Numer Lekarza: " << nr_lekarza << endl;
    cout << "Imie Lekarza: " <<imie << endl;
    cout << "Nazwisko Lekarza: " <<nazwisko << endl;
    cout << "Specjalizacja Lekarza: " <<specjalizacja << endl;
    cout << "Godzina rozpoczecia pracy lekarza: " << godzina_roz << ":00" << endl;
    cout << "Godzina zakoczenia pracy lekarza: " << godzina_kon << ":00" << endl;
    if(wizyty=="")
        cout << "Wszystkie wizyty sa wolne" << endl;
    else
        cout << "Zajete wizyty: ";

    regex reg(Dzien + "." +MiesiacINT + ".\\d\\d\\d\\d.\\d*.\\d\\d");

        sregex_iterator currentMatch(wizyty.begin(), wizyty.end(), reg);
        sregex_iterator lastMatch;
        while(currentMatch!= lastMatch)
        {
            smatch match = *currentMatch;
            cout << match.str() << "  ;  ";
            currentMatch++;
        }

    cout << endl << endl;
}

void Lekarz::zapisNaWizyte(string Dzien, string Miesiac)
{
    cout << "Prosze podac godzine na ktora chcialby sie Pan"
            "/Pani zapisac (Zapisy prowadzimy jedynie w godzinach x:00 - x:15 - x:30 - x:45): ";

    string godzina;
    string dopuszczalna_kon1 = ":00";
    string dopuszczalna_kon2 = ":15";
    string dopuszczalna_kon3 = ":30";
    string dopuszczalna_kon4 = ":45";

    cin >> godzina;

    cout << "--------------------------------------------------------------------------------------" << endl << endl;


    if((godzina.find(dopuszczalna_kon1) != string ::npos) || (godzina.find(dopuszczalna_kon2) != string ::npos) || (godzina.find(dopuszczalna_kon3) != string ::npos) || (godzina.find(dopuszczalna_kon4) != string ::npos))
    {
        string AktualnyZapis = Dzien + "." + Miesiac + ".2020" + "-" + godzina + "  ;  ";

        int pozycja = wizyty.find(AktualnyZapis);

        if(pozycja==string::npos)
        {

            int godzinaINT = std::stoi (godzina,nullptr,0);
            if(godzinaINT >= godzina_roz && godzinaINT <= godzina_kon)
            {
                wizyty = wizyty + AktualnyZapis;
            }
            else
            {
                cout << "Niestety lekarz nie przyjmuje o tej godzinie" << endl << endl;
            }
        }
        else
        {
            cout << "Niestety ta godzina jest już zajeta" << endl << endl;
        }
    }
    else
    {
        cout << "Niestety ta godzina nie jest zgodna z naszym formatem zapisow." << endl << endl;
    }
}
