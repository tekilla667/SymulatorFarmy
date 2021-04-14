#ifndef CSKLEP_H
#define CSKLEP_H

#include <QWidget>

namespace Ui {
class CSklep;
}

class CSklep : public QWidget
{
    Q_OBJECT

public:
    explicit CSklep(QWidget *parent = nullptr);
    ~CSklep();
    int ziemniakiKupno;
    int ziemniakiSprzedaz;
    int truskawkiKupno;
    int truskawkiSprzedaz;
    int pietruszkaKupno;
    int pietruszkaSprzedaz;
    int nawadniarkaKupno;
    int nawadniarkaSprzedaz;
    int opryskKupno;
    int opryskSprzedaz;
    int ursusKupno;
    int ursusSprzedaz;
    int ursusxKupno;
    int ursusxSprzedaz;
private slots:
    void on_pushButton_clicked();
    void on_ZatZiemniaki_clicked();

    void on_zatPietruszki_clicked();

    void on_zatTruskawki_clicked();

    void on_zatOprysk_clicked();

    void on_zatNawadniarka_clicked();

    void on_zatUrsus_clicked();

    void on_zatUrsusX_clicked();

    void on_pushButton_2_clicked();

signals:
    void powrotHektar();
    void zatZiemniaki();
    void zatPietruszki();
    void zatTruskawki();
    void zatNawadniarka();
    void zatOprysk();
    void zatUrsus();
    void zatUrsusX();
    void kupHektar();
private:
    Ui::CSklep *ui;
};

#endif // CSKLEP_H
