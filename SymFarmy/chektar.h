#ifndef CHEKTAR_H
#define CHEKTAR_H

#include <QWidget>

namespace Ui {
class CHektar;
}

class CHektar : public QWidget
{
    Q_OBJECT

public:
    explicit CHektar(QWidget *parent = nullptr);
    ~CHektar();
void ustalNapisPieniedzy(int liczba);
void ustalNapisPracownikow(int liczba);
void ustalNapisPietruszek(int liczba);
void ustalNapisTruskawek(int liczba);
void ustalNapisZiemniakow(int liczba);
void ustalNapisNawadniarka(int liczba);
void ustalNapisOprysk(int liczba);
void ustalNapisUrsus(int liczba);
void ustalNapisUrsusX(int liczba);
void ustalNapisHektarow(int liczba);
void ustalNapisDzien(int liczba);
int numerHektara;
int ursusNumer;
int ursusXNumer;
private slots:

void on_pushButtonUrzad_clicked();

void on_pushButton_clicked();

void on_przegladajHektar_clicked();

void on_nastepnyDzien_clicked();

void on_naprawUrsus_clicked();

void on_naprawUrsusX_clicked();

signals:
void urzad();
void sklep();
void przegladajHektar();
void nastepnyDzien();
void naprawUrsus();
void naprawUrsusX();
private:
    Ui::CHektar *ui;
};

#endif // CHEKTAR_H
