#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <cpole.h>
#include "cfarmer.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    CFarmer * Dfarmer;
    CSegment segment,segmencik;
    CSegment * wskazanySegment;
    CPole pole;
    QGraphicsRectItem * Truskawka,*Ziemniak,*Pietruszka,*Oprysk,*Nawadniarka,*Ursus,*Ursusx, *item;
    QGraphicsTextItem * powrot, *wilgotnosc, *NTruskawka,*NZiemniak,*NPietruszka,*NOprysk,*NNawadniarka,*NUrsus,*NUrsusX,*NBrak;

   // QGraphicsSceneMouseEvent klik;
    void akcjaSegment(CSegment *akcja);
    void zmienBrush(CSegment *akcja);
    int aktywnyX=0,aktywnyY=0;
    int wybrane = 0;
    void aktualizujBrush();
    int ziemniakiDlaFarmera=0;
    int pietruszkiDlaFarmera=0;
    int truskawkiDlaFarmera=0;
    int ID=0;
private slots:
    void on_Dialog_windowIconChanged(const QIcon &icon);

    void on_S1_1_clicked();

    void on_S1_2_clicked();

    void on_S1_3_clicked();

    void on_S1_4_clicked();

    void on_S1_5_clicked();

    void on_S1_6_clicked();

    void on_S2_1_clicked();

    void on_S2_2_clicked();

    void on_S2_3_clicked();

    void on_S2_4_clicked();

    void on_S2_5_clicked();

    void on_S2_6_clicked();

    void on_S3_1_clicked();

    void on_S3_2_clicked();

    void on_S3_3_clicked();

    void on_S3_4_clicked();

    void on_S3_5_clicked();

    void on_S3_6_clicked();

    void on_ButTruskawka_clicked();

    void on_ButZiemniak_clicked();

    void on_ButPietruszka_clicked();

    void on_pushButton_clicked();

    void on_ButOprysk_clicked();

    void on_ButNawadniarka_clicked();

    void on_ButUrsus_clicked();

    void on_ButUrsusX_clicked();

private:
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    void ustalBrush();
    QBrush q,Btruskawka,Btruskawka1,Btruskawka2,Btruskawka3,Bziemniak,Bziemniak1,Bziemniak2,Bziemniak3,Bpietruszka,Bpietruszka1,Bpietruszka2,Bpietruszka3,Brobak,Boprysk,Bnawadniarka,Bursus,BursusX;

    void zmienGrafike();
    void ustalKolory();
signals:
    void kliknieto();
    void S1_1();
    void S1_2();
    void S1_3();
    void S1_4();
    void S1_5();
    void S1_6();
    void S2_1();
    void S2_2();
    void S2_3();
    void S2_4();
    void S2_5();
    void S2_6();
    void S3_1();
    void S3_2();
    void S3_3();
    void S3_4();
    void S3_5();
    void S3_6();
    void wracaj();
};

#endif // DIALOG_H
