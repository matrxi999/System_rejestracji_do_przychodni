#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Lekarz.h"
#include <sstream>
#include <regex>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cbWyborSpecjalizacji_currentIndexChanged(const QString &arg1)
{
    QString nr_lekarza = "Numer Lekarza: ";
    QString imie_lekarza = "Imie Lekarza: ";
    QString nazwisko_lekarza = "Nazwisko Lekarza: ";
    QString specjalizacja_lekarza = "Specjalizacja: ";
    QString enterek = "";

    ui->pteListaLekarzy->clear();

    for (int i=0; i<80; i++)
    {
        Specjalizacja = arg1.toStdString();

        if(Specjalizacja==L[i].specjalizacja)
        {
            int numer = L[i].nr_lekarza;
            QString numer_qt = QString::number(numer);
            string imie = L[i].imie;
            QString imie_qt = imie.c_str();
            string nazwisko = L[i].nazwisko;
            QString nazwisko_qt = nazwisko.c_str();
            string specjalizacja = L[i].specjalizacja;
            QString specjalizacja_qt = specjalizacja.c_str();

            ui->pteListaLekarzy->appendPlainText(nr_lekarza);
            ui->pteListaLekarzy->insertPlainText(numer_qt);
            ui->pteListaLekarzy->appendPlainText(imie_lekarza);
            ui->pteListaLekarzy->insertPlainText(imie_qt);
            ui->pteListaLekarzy->appendPlainText(nazwisko_lekarza);
            ui->pteListaLekarzy->insertPlainText(nazwisko_qt);
            ui->pteListaLekarzy->appendPlainText(specjalizacja_lekarza);
            ui->pteListaLekarzy->insertPlainText(specjalizacja_qt);
            ui->pteListaLekarzy->appendPlainText(enterek);
        }
    }
}

void MainWindow::on_cbWyborMiesiaca_currentIndexChanged(const QString &arg1)
{
    Miesiac = arg1.toStdString();

    if(Miesiac=="Styczen") MiesiacINT="1";
    else if(Miesiac=="Luty") MiesiacINT="2";
    else if(Miesiac=="Marzec") MiesiacINT="3";
    else if(Miesiac=="Kwiecien") MiesiacINT="4";
    else if(Miesiac=="Maj") MiesiacINT="5";
    else if(Miesiac=="Czerwiec") MiesiacINT="6";
    else if(Miesiac=="Lipiec") MiesiacINT="7";
    else if(Miesiac=="Sierpien") MiesiacINT="8";
    else if(Miesiac=="Wrzesien") MiesiacINT="9";
    else if(Miesiac=="Pazdziernik") MiesiacINT="10";
    else if(Miesiac=="Listopad") MiesiacINT="11";
    else if(Miesiac=="Grudzien") MiesiacINT="12";

    ui->pteListaLekarzy->clear();


    QString sample = MiesiacINT.c_str();
    ui->pteListaLekarzy->appendPlainText(sample);

    QString nr_lekarza = "Numer Lekarza: ";
    QString imie_lekarza = "Imie Lekarza: ";
    QString nazwisko_lekarza = "Nazwisko Lekarza: ";
    QString specjalizacja_lekarza = "Specjalizacja: ";
    QString enterek = "";

    ui->pteListaLekarzy->clear();

    for (int i=0; i<80; i++)
    {
        if(Specjalizacja==L[i].specjalizacja)
        {
            if(L[i].miesiac.find(MiesiacINT) != string::npos)
            {
                int numer = L[i].nr_lekarza;
                QString numer_qt = QString::number(numer);
                string imie = L[i].imie;
                QString imie_qt = imie.c_str();
                string nazwisko = L[i].nazwisko;
                QString nazwisko_qt = nazwisko.c_str();
                string specjalizacja = L[i].specjalizacja;
                QString specjalizacja_qt = specjalizacja.c_str();

                ui->pteListaLekarzy->appendPlainText(nr_lekarza);
                ui->pteListaLekarzy->insertPlainText(numer_qt);
                ui->pteListaLekarzy->appendPlainText(imie_lekarza);
                ui->pteListaLekarzy->insertPlainText(imie_qt);
                ui->pteListaLekarzy->appendPlainText(nazwisko_lekarza);
                ui->pteListaLekarzy->insertPlainText(nazwisko_qt);
                ui->pteListaLekarzy->appendPlainText(specjalizacja_lekarza);
                ui->pteListaLekarzy->insertPlainText(specjalizacja_qt);
                ui->pteListaLekarzy->appendPlainText(enterek);
            }
        }
    }

}

void MainWindow::on_sbWyborDnia_valueChanged(int arg1)
{

    ui->pteListaLekarzy->clear();


    for (int i=0; i<80; i++)
    {
        if(Specjalizacja==L[i].specjalizacja)
        {
            if(L[i].miesiac.find(MiesiacINT) != string::npos)
            {

                Dzien = std::to_string(arg1);

                if(L[i].dzien.find(Dzien) != string::npos)
                {
                    QString nr_lekarza = "Numer Lekarza: ";
                    QString imie_lekarza = "Imie Lekarza: ";
                    QString nazwisko_lekarza = "Nazwisko Lekarza: ";
                    QString specjalizacja_lekarza = "Specjalizacja: ";
                    QString godzina_roz_lekarza = "Godzina rozpoczecia pracy lekarza: ";
                    QString godzina_kon_lekarza = "Godzina konca pracy lekarza: ";
                    QString wizyty_lekarza = "Zajete wizyty: ";
                    QString suffix_godziny = ":00";
                    QString enterek = "";



                    int numer = L[i].nr_lekarza;
                    QString numer_qt = QString::number(numer);
                    string imie = L[i].imie;
                    QString imie_qt = imie.c_str();
                    string nazwisko = L[i].nazwisko;
                    QString nazwisko_qt = nazwisko.c_str();
                    string specjalizacja = L[i].specjalizacja;
                    QString specjalizacja_qt = specjalizacja.c_str();
                    string miesiac = L[i].miesiac;
                    QString miesiac_qt = miesiac.c_str();
                    string dzien = L[i].dzien;
                    QString dzien_qt = dzien.c_str();
                    int godzina_roz = L[i].godzina_roz;
                    QString godzina_roz_qt = QString::number(godzina_roz);
                    int godzina_kon = L[i].godzina_kon;
                    QString godzina_kon_qt = QString::number(godzina_kon);
                    string wizyty = L[i].wizyty;
                    QString wizyty_qt = wizyty.c_str();

                    ui->pteListaLekarzy->appendPlainText(nr_lekarza);
                    ui->pteListaLekarzy->insertPlainText(numer_qt);
                    ui->pteListaLekarzy->appendPlainText(imie_lekarza);
                    ui->pteListaLekarzy->insertPlainText(imie_qt);
                    ui->pteListaLekarzy->appendPlainText(nazwisko_lekarza);
                    ui->pteListaLekarzy->insertPlainText(nazwisko_qt);
                    ui->pteListaLekarzy->appendPlainText(specjalizacja_lekarza);
                    ui->pteListaLekarzy->insertPlainText(specjalizacja_qt);
                    ui->pteListaLekarzy->appendPlainText(godzina_roz_lekarza);
                    ui->pteListaLekarzy->insertPlainText(godzina_roz_qt);
                    ui->pteListaLekarzy->insertPlainText(suffix_godziny);
                    ui->pteListaLekarzy->appendPlainText(godzina_kon_lekarza);
                    ui->pteListaLekarzy->insertPlainText(godzina_kon_qt);
                    ui->pteListaLekarzy->insertPlainText(suffix_godziny);
                    ui->pteListaLekarzy->appendPlainText(wizyty_lekarza);
                    ui->pteListaLekarzy->insertPlainText(wizyty_qt);
                    ui->pteListaLekarzy->appendPlainText(enterek);
                }
            }
        }
    }
}

void MainWindow::on_sbNumerLekarza_valueChanged(int arg1)
{
    Numer_l = arg1;

    ui->pteListaLekarzy->clear();

    for (int i=0; i<80; i++)
    {
        if(Specjalizacja==L[i].specjalizacja)
        {
            if(L[i].miesiac.find(MiesiacINT) != string::npos)
            {
                if(L[i].dzien.find(Dzien) != string::npos)
                {
                    if(Numer_l==L[i].nr_lekarza)
                    {
                        QString nr_lekarza = "Numer Lekarza: ";
                        QString imie_lekarza = "Imie Lekarza: ";
                        QString nazwisko_lekarza = "Nazwisko Lekarza: ";
                        QString specjalizacja_lekarza = "Specjalizacja: ";
                        QString godzina_roz_lekarza = "Godzina rozpoczecia pracy lekarza: ";
                        QString godzina_kon_lekarza = "Godzina konca pracy lekarza: ";
                        QString wizyty_lekarza = "Zajete wizyty: ";
                        QString suffix_godziny = ":00";
                        QString enterek = "";

                        int numer = L[i].nr_lekarza;
                        QString numer_qt = QString::number(numer);
                        string imie = L[i].imie;
                        QString imie_qt = imie.c_str();
                        string nazwisko = L[i].nazwisko;
                        QString nazwisko_qt = nazwisko.c_str();
                        string specjalizacja = L[i].specjalizacja;
                        QString specjalizacja_qt = specjalizacja.c_str();
                        string miesiac = L[i].miesiac;
                        QString miesiac_qt = miesiac.c_str();
                        string dzien = L[i].dzien;
                        QString dzien_qt = dzien.c_str();
                        int godzina_roz = L[i].godzina_roz;
                        QString godzina_roz_qt = QString::number(godzina_roz);
                        int godzina_kon = L[i].godzina_kon;
                        QString godzina_kon_qt = QString::number(godzina_kon);
                        string wizyty = L[i].wizyty;
                        QString wizyty_qt = wizyty.c_str();

                        ui->pteListaLekarzy->appendPlainText(nr_lekarza);
                        ui->pteListaLekarzy->insertPlainText(numer_qt);
                        ui->pteListaLekarzy->appendPlainText(imie_lekarza);
                        ui->pteListaLekarzy->insertPlainText(imie_qt);
                        ui->pteListaLekarzy->appendPlainText(nazwisko_lekarza);
                        ui->pteListaLekarzy->insertPlainText(nazwisko_qt);
                        ui->pteListaLekarzy->appendPlainText(specjalizacja_lekarza);
                        ui->pteListaLekarzy->insertPlainText(specjalizacja_qt);
                        ui->pteListaLekarzy->appendPlainText(godzina_roz_lekarza);
                        ui->pteListaLekarzy->insertPlainText(godzina_roz_qt);
                        ui->pteListaLekarzy->insertPlainText(suffix_godziny);
                        ui->pteListaLekarzy->appendPlainText(godzina_kon_lekarza);
                        ui->pteListaLekarzy->insertPlainText(godzina_kon_qt);
                        ui->pteListaLekarzy->insertPlainText(suffix_godziny);
                        ui->pteListaLekarzy->appendPlainText(wizyty_lekarza);
                        ui->pteListaLekarzy->insertPlainText(wizyty_qt);
                        ui->pteListaLekarzy->appendPlainText(enterek);
                    }
                }
            }
        }
    }
}

void MainWindow::on_leWyborGodziny_returnPressed()
{
    ui->pteListaLekarzy->clear();
    godzina = ui->leWyborGodziny->text().toStdString();

    for (int i=0; i<80; i++)
    {
        if(Specjalizacja==L[i].specjalizacja)
        {
            if(L[i].miesiac.find(MiesiacINT) != string::npos)
            {
                if(L[i].dzien.find(Dzien) != string::npos)
                {
                    if(Numer_l==L[i].nr_lekarza)
                    {

                        if((godzina.find(dopuszczalna_kon1) != string ::npos) || (godzina.find(dopuszczalna_kon2) != string ::npos) || (godzina.find(dopuszczalna_kon3) != string ::npos) || (godzina.find(dopuszczalna_kon4) != string ::npos))
                        {
                            string AktualnyZapis = Dzien + "." + MiesiacINT + ".2020" + "-" + godzina + "  ;  ";

                            QString akt = AktualnyZapis.c_str();

                            int pozycja = L[i].wizyty.find(AktualnyZapis);

                            if(pozycja==string::npos)
                            {

                                int godzinaINT = std::stoi (godzina,nullptr,0);
                                if(godzinaINT >= L[i].godzina_roz && godzinaINT <= L[i].godzina_kon)
                                {
                                    L[i].wizyty = L[i].wizyty + AktualnyZapis;
                                }
                            }
                        }
                        QString nr_lekarza = "Numer Lekarza: ";
                        QString imie_lekarza = "Imie Lekarza: ";
                        QString nazwisko_lekarza = "Nazwisko Lekarza: ";
                        QString specjalizacja_lekarza = "Specjalizacja: ";
                        QString godzina_roz_lekarza = "Godzina rozpoczecia pracy lekarza: ";
                        QString godzina_kon_lekarza = "Godzina konca pracy lekarza: ";
                        QString wizyty_lekarza = "Zajete wizyty: ";
                        QString suffix_godziny = ":00";
                        QString oddzielnik = "  ;   ";
                        QString enterek = "";

                        int numer = L[i].nr_lekarza;
                        QString numer_qt = QString::number(numer);
                        string imie = L[i].imie;
                        QString imie_qt = imie.c_str();
                        string nazwisko = L[i].nazwisko;
                        QString nazwisko_qt = nazwisko.c_str();
                        string specjalizacja = L[i].specjalizacja;
                        QString specjalizacja_qt = specjalizacja.c_str();
                        string miesiac = L[i].miesiac;
                        QString miesiac_qt = miesiac.c_str();
                        string dzien = L[i].dzien;
                        QString dzien_qt = dzien.c_str();
                        int godzina_roz = L[i].godzina_roz;
                        QString godzina_roz_qt = QString::number(godzina_roz);
                        int godzina_kon = L[i].godzina_kon;
                        QString godzina_kon_qt = QString::number(godzina_kon);

                        string wizyty = L[i].wizyty;
                        QString wizyty_qt = wizyty.c_str();

                        ui->pteListaLekarzy->appendPlainText(nr_lekarza);
                        ui->pteListaLekarzy->insertPlainText(numer_qt);
                        ui->pteListaLekarzy->appendPlainText(imie_lekarza);
                        ui->pteListaLekarzy->insertPlainText(imie_qt);
                        ui->pteListaLekarzy->appendPlainText(nazwisko_lekarza);
                        ui->pteListaLekarzy->insertPlainText(nazwisko_qt);
                        ui->pteListaLekarzy->appendPlainText(specjalizacja_lekarza);
                        ui->pteListaLekarzy->insertPlainText(specjalizacja_qt);
                        ui->pteListaLekarzy->appendPlainText(godzina_roz_lekarza);
                        ui->pteListaLekarzy->insertPlainText(godzina_roz_qt);
                        ui->pteListaLekarzy->insertPlainText(suffix_godziny);
                        ui->pteListaLekarzy->appendPlainText(godzina_kon_lekarza);
                        ui->pteListaLekarzy->insertPlainText(godzina_kon_qt);
                        ui->pteListaLekarzy->insertPlainText(suffix_godziny);
                        ui->pteListaLekarzy->appendPlainText(wizyty_lekarza);

                        regex reg(Dzien + "." +MiesiacINT + ".\\d\\d\\d\\d.\\d*.\\d\\d");
                        sregex_iterator currentMatch(L[i].wizyty.begin(), L[i].wizyty.end(), reg);
                        sregex_iterator lastMatch;
                        while(currentMatch!= lastMatch)
                        {
                            smatch match = *currentMatch;
                            string matchstr = match.str();

                            QString match_qt = matchstr.c_str();

                            ui->pteListaLekarzy->insertPlainText(match_qt);
                            ui->pteListaLekarzy->insertPlainText(oddzielnik);
                            currentMatch++;
                        }

                        ui->pteListaLekarzy->appendPlainText(enterek);
                    }
                }
            }
        }
    }
}

void MainWindow::on_pbUmowWizyte_clicked()
{
    for (int i=0; i<80; i++)
    {
        L[i].zapisz();
    }
}

void MainWindow::on_pbStart_clicked()
{
    for (int i=0; i<80; i++)
    {
        L[i].nr_lekarza=i+1;
        L[i].wczytaj();
    }
    wypiszListe();
}

void MainWindow::wypiszListe()
{
    QString nr_lekarza = "Numer Lekarza: ";
    QString imie_lekarza = "Imie Lekarza: ";
    QString nazwisko_lekarza = "Nazwisko Lekarza: ";
    QString specjalizacja_lekarza = "Specjalizacja: ";
    QString enterek = "";

    ui->pteListaLekarzy->clear();

    for (int i=0; i<80; i++)
    {
        int numer = L[i].nr_lekarza;
        QString numer_qt = QString::number(numer);
        string imie = L[i].imie;
        QString imie_qt = imie.c_str();
        string nazwisko = L[i].nazwisko;
        QString nazwisko_qt = nazwisko.c_str();
        string specjalizacja = L[i].specjalizacja;
        QString specjalizacja_qt = specjalizacja.c_str();

        ui->pteListaLekarzy->appendPlainText(nr_lekarza);
        ui->pteListaLekarzy->insertPlainText(numer_qt);
        ui->pteListaLekarzy->appendPlainText(imie_lekarza);
        ui->pteListaLekarzy->insertPlainText(imie_qt);
        ui->pteListaLekarzy->appendPlainText(nazwisko_lekarza);
        ui->pteListaLekarzy->insertPlainText(nazwisko_qt);
        ui->pteListaLekarzy->appendPlainText(specjalizacja_lekarza);
        ui->pteListaLekarzy->insertPlainText(specjalizacja_qt);
        ui->pteListaLekarzy->appendPlainText(enterek);
    }
}
