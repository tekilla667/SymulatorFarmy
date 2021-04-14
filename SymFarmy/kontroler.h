
#ifndef KONTROLER_H
#define KONTROLER_H

#include <QMainWindow>
#include <cpoczatek.h>
#include <chektar.h>
#include <cfarmer.h>
#include <curzadpracy.h>
#include <csklep.h>
#include <ctruskawka.h>
#include <dialog.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Kontroler; }
QT_END_NAMESPACE

class Kontroler : public QMainWindow
{
    Q_OBJECT

public:
    Kontroler(QWidget *parent = nullptr);
    ~Kontroler();

private slots:

    void idzHektar_zero();
    void idzUrzad();
    void DodajPracownikowFarmerowi();
    void idzSklep();
    void sklepTruskawki();
    void sklepPietruszki();
    void sklepZiemniaki();
    void sklepNawadniarka();
    void sklepOprysk();
    void sklepUrsus();
    void sklepUrsusX();
    void podgladHektar();
    void nastepnyDzien();
    void kupHektar();
    void naprawUrsus();
    void naprawUrsusX();
private:
Ui::Kontroler *ui;
   CPoczatek poczatek;
   CHektar hektar_zero;
   CFarmer farmer;
   CUrzadpracy urzad;
   CSklep sklep;
  // Dialog podglad;
  // Dialog podglad2;
   QVector <Dialog*> pola;
   int pieniadzeStart;
   int ktoryDzien=0;
void kasaPoczatek();
    bool wplacono=false;
};
#endif // KONTROLER_H
