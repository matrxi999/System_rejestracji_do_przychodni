#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Lekarz.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_cbWyborMiesiaca_currentIndexChanged(const QString &arg1);

    void on_cbWyborSpecjalizacji_currentIndexChanged(const QString &arg1);

    void on_sbWyborDnia_valueChanged(int arg1);

    void on_sbNumerLekarza_valueChanged(int arg1);

    void on_leWyborGodziny_returnPressed();

    void on_pbUmowWizyte_clicked();

    void on_pbStart_clicked();

private:
    Ui::MainWindow *ui;
    Lekarz L[80];

    string Specjalizacja;
    string Miesiac;
    string MiesiacINT;
    string Dzien;
    string godzina;
    int Numer_l;

    string dopuszczalna_kon1 = ":00";
    string dopuszczalna_kon2 = ":15";
    string dopuszczalna_kon3 = ":30";
    string dopuszczalna_kon4 = ":45";

    void wypiszListe();
};
#endif // MAINWINDOW_H
