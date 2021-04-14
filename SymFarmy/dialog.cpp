#include "dialog.h"
#include "ui_dialog.h"
#include "croslina.h"
#include "ctruskawka.h"
#include "cpietruszka.h"
#include "cziemniak.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
   ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::darkGreen);

    QPen blackpen(Qt::black);
    QBrush blueBrush(Qt::darkRed);
    QFont czcionka("Times",10,QFont::Bold);
   item=scene->addRect(0,0,0,0,blackpen,blueBrush);
   ustalBrush();

   Truskawka=scene->addRect(0,0,80,80, blackpen, Btruskawka);
   Ziemniak=scene->addRect(0,80, 80,80,blackpen,Bziemniak);
   Pietruszka=scene->addRect(0,160,80,80,blackpen,Bpietruszka);
   Oprysk=scene->addRect(0,240,80,80,blackpen,Boprysk);
   Nawadniarka=scene->addRect(0,320,80,80,blackpen,Bnawadniarka);
   Ursus=scene->addRect(0,400,80,80,blackpen,Bursus);
   Ursusx=scene->addRect(0,480,80,80,blackpen,BursusX);
    powrot=scene->addText("Powrot",czcionka);
    NBrak=scene->addText("x",czcionka);
    wilgotnosc=scene->addText("Wilgotnosc: "+QString::number(pole.wilgotnosc)+"%",czcionka);
    NTruskawka=scene->addText("Zasiej Truskawkę",czcionka);
     NTruskawka->setPos(-140,40);
    NZiemniak=scene->addText("Zasiej Ziemniaka",czcionka);
    NZiemniak->setPos(-140,120);
    NPietruszka=scene->addText("Zasiej Pietruszkę",czcionka);
    NPietruszka->setPos(-140,200);
    NOprysk=scene->addText("Spryskaj",czcionka);
    NOprysk->setPos(-140,280);
    NNawadniarka=scene->addText("Nawodnij(+20%)", czcionka);
    NNawadniarka->setPos(-140,360);

    NUrsus=scene->addText("Ursus",czcionka);
    NUrsus->setPos(-140,440);
    NUrsusX=scene->addText("UrsusX",czcionka);
    NUrsusX->setPos(-140,520);

    powrot->setPos(490,540);
    wilgotnosc->setPos(400,400);

   QImage i("D:/puste.png");

q.setTextureImage(i);
   for (int i =0; i<18; i++)
    {
        pole.segmenty[i]->guiSegment->setRect(pole.segmenty[i]->guiSegment->x,pole.segmenty[i]->guiSegment->y,80, 80);
        pole.segmenty[i]->guiSegment->setBrush(q);
        scene->addItem(pole.segmenty[i]->guiSegment);
    }

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::akcjaSegment(CSegment* akcja)
{
    qDebug()<<"farmer ma Pieniedzy:"<<Dfarmer->ilePieniedzy();
    qDebug()<<"ID POLA: "<<ID;
    CRoslina *wskaznik ;
    if(akcja->ziemniak!=NULL)
    wskaznik=akcja->ziemniak;
    if(akcja->truskawka!=NULL)
    wskaznik=akcja->truskawka;
    if(akcja->pietruszka!=NULL)
    wskaznik=akcja->pietruszka;




    if(!akcja->posiane)
   {
      if((wybrane==1&&Dfarmer->ileTruskawek()>0)||(wybrane==2&&Dfarmer->ileZiemniakow()>0)||(wybrane==3&&Dfarmer->ilePietruszek()>0))
    {   akcja->posiej(wybrane);
        zmienBrush(akcja);
        akcja->posiane=true;
        if(wybrane==1)
            Dfarmer->sprzedajTruskawki(1);
        if(wybrane==2)
            Dfarmer->sprzedajZiemniaki(1);
        if(wybrane==3)
            Dfarmer->sprzedajPietruszki(1);
      }




    }
  if(akcja->ziemniak!=NULL)
  {

      if(akcja->ziemniak->czyMaSzkodnika()&&wybrane==4)
            {
                   if(Dfarmer->ileOpryskow()>=ID+1)
                   { qDebug()<<" szkodnika z ziemniaka: "<<akcja->ziemniak->czyMaSzkodnika();
                    pole.uzyjOprysku();
                   akcja->ziemniak->usunietoSzkodnika();
                   zmienGrafike();
                   qDebug()<<" szkodnika z ziemniaka: "<<akcja->ziemniak->czyMaSzkodnika();}
             }
      if(akcja->posiane&&akcja->ziemniak->zwrocDni()>=CZiemniak::wzrost&&!(akcja->ziemniak->czyMaSzkodnika()))
    {
        if(wybrane!=6&&wybrane!=7)
        {
        ziemniakiDlaFarmera+=CZiemniak::plon;
        qDebug()<<ziemniakiDlaFarmera;

        }
        else if(wybrane==6)
         {
            if(Dfarmer->ileUrsus()>=ID+1)
           { ziemniakiDlaFarmera+=CZiemniak::plon*pole.wydajnoscUrsus();
            pole.zbierajUrsus();}
        }
        else if(wybrane==7)
        {
                if(Dfarmer->ileUrsusx()>=ID+1)
               { ziemniakiDlaFarmera+=CZiemniak::plon*pole.wydajnoscUrsusX();
                 pole.zbierajUrsusX();}
      }
        akcja->posiane=false;

        wskaznik=NULL;
        akcja->guiSegment->setBrush(q);
    }}
  if(akcja->pietruszka!=NULL)
  {

      if(akcja->pietruszka->czyMaSzkodnika()&&wybrane==4)
            {
                    if(Dfarmer->ileOpryskow()>=ID+1){
                    pole.uzyjOprysku();
                   akcja->pietruszka->usunietoSzkodnika();
                   zmienGrafike();

                    }
             }
      if(akcja->posiane&&akcja->pietruszka->zwrocDni()>=CPietruszka::wzrost&&!(akcja->pietruszka->czyMaSzkodnika()))
    {

          if(wybrane!=6&&wybrane!=7)
         { pietruszkiDlaFarmera=CPietruszka::plon;

          }
          else if(wybrane==6)
          {
             if(Dfarmer->ileUrsus()>=ID+1)
            {  pietruszkiDlaFarmera=CPietruszka::plon*pole.wydajnoscUrsus();
              pole.zbierajUrsus();}
          }
          else if(wybrane==7)
          {
             if(Dfarmer->ileUrsusx()>=ID+1)
            {  pietruszkiDlaFarmera=CPietruszka::plon*pole.wydajnoscUrsusX();
              pole.zbierajUrsusX();}
          }
          akcja->posiane=false;

          wskaznik=NULL;
          akcja->guiSegment->setBrush(q);


    }}
  if(akcja->truskawka!=NULL)
  {

      if(akcja->truskawka->czyMaSzkodnika()&&wybrane==4)
            {
                   if(Dfarmer->ileOpryskow()>=ID+1){
                  //  qDebug()<<"szkodnika z truskawki: "<<akcja->truskawka->czyMaSzkodnika();
                    pole.uzyjOprysku();
                   akcja->truskawka->usunietoSzkodnika();
                   zmienGrafike();
                //   qDebug()<<" szkodnika z truskawki: "<<akcja->truskawka->czyMaSzkodnika();
                   }
             }
      if(akcja->posiane&&akcja->truskawka->zwrocDni()>=CTruskawka::wzrost&&!(akcja->truskawka->czyMaSzkodnika()))
    {
        if(wybrane!=6&&wybrane!=7)
     {     truskawkiDlaFarmera+=CTruskawka::plon;

        }
        else if(wybrane==6)
        {
            if(Dfarmer->ileUrsus()>=ID+1){
            truskawkiDlaFarmera+=CTruskawka::plon*pole.wydajnoscUrsus();
           // qDebug()<<truskawkiDlaFarmera;
            pole.zbierajUrsus();}
        }
        else if(wybrane==7)
        {
            if(Dfarmer->ileUrsusx()>=ID+1){
            truskawkiDlaFarmera+=CTruskawka::plon*pole.wydajnoscUrsusX();
            pole.zbierajUrsusX();}
        }
        akcja->posiane=false;

        wskaznik=NULL;
        akcja->guiSegment->setBrush(q);
    }}

}

void Dialog::zmienBrush(CSegment *akcja)
{

    if(wybrane==1)
        akcja->guiSegment->setBrush(Btruskawka1);
    if(wybrane==2)
        akcja->guiSegment->setBrush(Bziemniak1);
    if(wybrane==3)
        akcja->guiSegment->setBrush(Bpietruszka1);


}

void Dialog::aktualizujBrush()
{
    pole.nastepnyDzien();

    scene->removeItem(wilgotnosc);

    QFont czcionka("Times",10,QFont::Bold);
    wilgotnosc=scene->addText("Wilgotnosc: "+QString::number(pole.wilgotnosc)+"%",czcionka);
     wilgotnosc->setPos(400,400);
    zmienGrafike();
}
void Dialog::on_Dialog_windowIconChanged(const QIcon &icon)
{

}

void Dialog::on_S1_1_clicked()
{
    aktywnyX=1;
    aktywnyY=1;
    wskazanySegment=pole.segmenty[0];
    akcjaSegment(wskazanySegment);
    emit S1_1();
}

void Dialog::on_S1_2_clicked()
{
    aktywnyX=2;
    aktywnyY=1;
    wskazanySegment=pole.segmenty[1];
    akcjaSegment(wskazanySegment);
    emit S1_2();
}

void Dialog::on_S1_3_clicked()
{
    aktywnyX=3;
    aktywnyY=1;
    wskazanySegment=pole.segmenty[2];
    akcjaSegment(wskazanySegment);
    emit S1_3();
}

void Dialog::on_S1_4_clicked()
{
    aktywnyX=4;
    aktywnyY=1;
    wskazanySegment=pole.segmenty[3];
    akcjaSegment(wskazanySegment);
    emit S1_4();
}

void Dialog::on_S1_5_clicked()
{
    aktywnyX=5;
    aktywnyY=1;
    wskazanySegment=pole.segmenty[4];
    akcjaSegment(wskazanySegment);
    emit S1_5();
}

void Dialog::on_S1_6_clicked()
{
    aktywnyX=6;
    aktywnyY=1;
    wskazanySegment=pole.segmenty[5];
    akcjaSegment(wskazanySegment);
    emit S1_6();
}

void Dialog::on_S2_1_clicked()
{
    aktywnyX=1;
    aktywnyY=2;
    wskazanySegment=pole.segmenty[6];
    akcjaSegment(wskazanySegment);
    emit S2_1();
}

void Dialog::on_S2_2_clicked()
{
    aktywnyX=2;
    aktywnyY=2;
    wskazanySegment=pole.segmenty[7];
    akcjaSegment(wskazanySegment);
    emit S2_2();
}

void Dialog::on_S2_3_clicked()
{
    aktywnyX=3;
    aktywnyY=2;
    wskazanySegment=pole.segmenty[8];
    akcjaSegment(wskazanySegment);
    emit S2_3();
}

void Dialog::on_S2_4_clicked()
{
    aktywnyX=4;
    aktywnyY=2;
    wskazanySegment=pole.segmenty[9];
    akcjaSegment(wskazanySegment);
    emit S2_4();
}

void Dialog::on_S2_5_clicked()
{
    aktywnyX=5;
    aktywnyY=2;
    wskazanySegment=pole.segmenty[10];
    akcjaSegment(wskazanySegment);
    emit S2_5();
}

void Dialog::on_S2_6_clicked()
{
    aktywnyX=6;
    aktywnyY=2;
    wskazanySegment=pole.segmenty[11];
    akcjaSegment(wskazanySegment);
    emit S2_6();
}

void Dialog::on_S3_1_clicked()
{
    aktywnyX=1;
    aktywnyY=3;
    wskazanySegment=pole.segmenty[12];
    akcjaSegment(wskazanySegment);
    emit S3_1();
}

void Dialog::on_S3_2_clicked()
{
    aktywnyX=2;
    aktywnyY=3;
    wskazanySegment=pole.segmenty[13];
    akcjaSegment(wskazanySegment);
    emit S3_2();
}

void Dialog::on_S3_3_clicked()
{
    aktywnyX=3;
    aktywnyY=3;
    wskazanySegment=pole.segmenty[14];
    akcjaSegment(wskazanySegment);
    emit S3_3();
}

void Dialog::on_S3_4_clicked()
{
    aktywnyX=4;
    aktywnyY=3;
    wskazanySegment=pole.segmenty[15];
    akcjaSegment(wskazanySegment);
    emit S3_4();
}

void Dialog::on_S3_5_clicked()
{
    aktywnyX=5;
    aktywnyY=3;
    wskazanySegment=pole.segmenty[16];
    akcjaSegment(wskazanySegment);
    emit S3_5();
}

void Dialog::on_S3_6_clicked()
{
    aktywnyX=6;
    aktywnyY=3;
    wskazanySegment=pole.segmenty[17];
    akcjaSegment(wskazanySegment);
    emit S3_6();
}

void Dialog::ustalBrush()
{
    Bziemniak.setTextureImage(QImage("pjcgrafika/ziemniak.png"));
    Bziemniak1.setTextureImage(QImage("pjcgrafika/ziemniak1.png"));
    Bziemniak2.setTextureImage(QImage("pjcgrafika/ziemniak2.png"));
    Bziemniak3.setTextureImage(QImage("pjcgrafika/ziemniak3.png"));
    Btruskawka.setTextureImage(QImage("pjcgrafika/truskawka.png"));
    Btruskawka1.setTextureImage(QImage("pjcgrafika/truskawka1.png"));
    Btruskawka2.setTextureImage(QImage("pjcgrafika/truskawka2.png"));
    Btruskawka3.setTextureImage(QImage("pjcgrafika/truskawka3.png"));
    Bpietruszka.setTextureImage(QImage("pjcgrafika/pietruszka.png"));
    Bpietruszka1.setTextureImage(QImage("pjcgrafika/pietruszka1.png"));
    Bpietruszka2.setTextureImage(QImage("pjcgrafika/pietruszka2.png"));
    Bpietruszka3.setTextureImage(QImage("pjcgrafika/pietruszka3.png"));
    Brobak.setTextureImage(QImage("pjcgrafika/robak.png"));
    Boprysk.setTextureImage(QImage("pjcgrafika/oprysk.png"));
    Bnawadniarka.setTextureImage(QImage("pjcgrafika/nawadniarka.png"));
    Bursus.setTextureImage(QImage("pjcgrafika/ursus.png"));
    BursusX.setTextureImage(QImage("pjcgrafika/ursusx.png"));


}



void Dialog::zmienGrafike()
{
    for(int i=0; i < 18; i++)
    {
        if(pole.segmenty[i]->ziemniak!=NULL)
        {
          //  qDebug()<<pole.segmenty[i]->ziemniak->zwrocDni();
            switch(pole.segmenty[i]->ziemniak->zwrocDni()){
            case 1:
            case 2:
                pole.segmenty[i]->guiSegment->setBrush(Bziemniak2);
                break;
            case 3:
                pole.segmenty[i]->guiSegment->setBrush(Bziemniak3);
                break;
            }
            if(pole.segmenty[i]->ziemniak->czyMaSzkodnika())
                pole.segmenty[i]->guiSegment->setBrush(Brobak);
        }
        if(pole.segmenty[i]->pietruszka!=NULL)
        {
            switch(pole.segmenty[i]->pietruszka->zwrocDni()){
            case 1:
            case 2:
                pole.segmenty[i]->guiSegment->setBrush(Bpietruszka1);
                break;
            case 3:
            case 4:
            case 5:
                pole.segmenty[i]->guiSegment->setBrush(Bpietruszka2);
                break;
            case 6:
                pole.segmenty[i]->guiSegment->setBrush(Bpietruszka3);
                break;
            }
            if(pole.segmenty[i]->pietruszka->czyMaSzkodnika())
                pole.segmenty[i]->guiSegment->setBrush(Brobak);
        }
        if(pole.segmenty[i]->truskawka!=NULL)
        {
            switch(pole.segmenty[i]->truskawka->zwrocDni()){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                pole.segmenty[i]->guiSegment->setBrush(Btruskawka1);
                break;
            case 6:
            case 7:
            case 8:
                pole.segmenty[i]->guiSegment->setBrush(Btruskawka2);
                break;
            case 9:
                pole.segmenty[i]->guiSegment->setBrush(Btruskawka3);
                break;
        }
            if(pole.segmenty[i]->truskawka->czyMaSzkodnika())
                pole.segmenty[i]->guiSegment->setBrush(Brobak);
    }
    if(!pole.segmenty[i]->posiane)
        pole.segmenty[i]->guiSegment->setBrush(q);
    }
}

void Dialog::ustalKolory()
{
    NTruskawka->setDefaultTextColor(Qt::black);
    NZiemniak->setDefaultTextColor(Qt::black);
    NPietruszka->setDefaultTextColor(Qt::black);
    NOprysk->setDefaultTextColor(Qt::black);
    NNawadniarka->setDefaultTextColor(Qt::black);
    NUrsus->setDefaultTextColor(Qt::black);
    NUrsusX->setDefaultTextColor(Qt::black);
    if(wybrane==1)
        NTruskawka->setDefaultTextColor(Qt::red);
    if(wybrane==2)
        NZiemniak->setDefaultTextColor(Qt::red);
    if(wybrane==3)
        NPietruszka->setDefaultTextColor(Qt::red);
    if(wybrane==4)
        NOprysk->setDefaultTextColor(Qt::red);
    if(wybrane==5)
        NNawadniarka->setDefaultTextColor(Qt::red);
    if(wybrane==6)
        NUrsus->setDefaultTextColor(Qt::red);
    if(wybrane==7)
        NUrsusX->setDefaultTextColor(Qt::red);

}

void Dialog::on_ButTruskawka_clicked()
{

    NBrak->setVisible(false);
    wybrane=1;
    ustalKolory();
    QFont czcionka("Times",10,QFont::Bold);
    if(Dfarmer->ileTruskawek()<1)
    {
     NBrak=scene->addText("Brak truskawek do posiania",czcionka);
     NBrak->setDefaultTextColor(Qt::darkRed);
     NBrak->setPos(300,450);
     NBrak->setVisible(true);
    }

}

void Dialog::on_ButZiemniak_clicked()
{
    NBrak->setVisible(false);
    wybrane=2;
    ustalKolory();
    if(Dfarmer->ileZiemniakow()<1)
    {
    QFont czcionka("Times",10,QFont::Bold);
        NBrak=scene->addText("Brak ziemniaków do posiania",czcionka);
     NBrak->setDefaultTextColor(Qt::darkRed);
     NBrak->setPos(300,450);
     NBrak->setVisible(true);
    }
}

void Dialog::on_ButPietruszka_clicked()
{
    NBrak->setVisible(false);
    wybrane=3;
    ustalKolory();
    if(Dfarmer->ilePietruszek()<1)
    {
    QFont czcionka("Times",10,QFont::Bold);
        NBrak=scene->addText("Brak pietruszek do posiania",czcionka);
     NBrak->setDefaultTextColor(Qt::darkRed);
     NBrak->setPos(300,450);
     NBrak->setVisible(true);
    }
}

void Dialog::on_pushButton_clicked()
{
    emit wracaj();

}

void Dialog::on_ButOprysk_clicked()
{
    NBrak->setVisible(false);
    wybrane=4;
    ustalKolory();
    if(Dfarmer->ileOpryskow()<ID+1)
    {
    QFont czcionka("Times",10,QFont::Bold);
        NBrak=scene->addText("Brak oprysków na tym polu",czcionka);
     NBrak->setDefaultTextColor(Qt::darkRed);
     NBrak->setPos(300,450);
     NBrak->setVisible(true);
    }
}

void Dialog::on_ButNawadniarka_clicked()
{
   NBrak->setVisible(false);
    wybrane=5;
   ustalKolory();
    if(Dfarmer->ileNawadniarek()>=ID+1)
   { pole.uzyjNawadniarki();
    scene->removeItem(wilgotnosc);

    QFont czcionka("Times",10,QFont::Bold);
    wilgotnosc=scene->addText("Wilgotnosc: "+QString::number(pole.wilgotnosc)+"%",czcionka);
     wilgotnosc->setPos(400,400);

    }
    else
    {
    QFont czcionka("Times",10,QFont::Bold);
        NBrak=scene->addText("Brak Nawadniarki na tym polu",czcionka);
     NBrak->setDefaultTextColor(Qt::darkRed);
     NBrak->setPos(300,450);
     NBrak->setVisible(true);
    }
}

void Dialog::on_ButUrsus_clicked()
{
    NBrak->setVisible(false);
    wybrane=6;
    ustalKolory();
    if(Dfarmer->ileUrsus()<ID+1)
    {
    QFont czcionka("Times",10,QFont::Bold);
        NBrak=scene->addText("Brak Ursus'a na tym polu",czcionka);
     NBrak->setDefaultTextColor(Qt::darkRed);
     NBrak->setPos(300,450);
     NBrak->setVisible(true);
    }

}

void Dialog::on_ButUrsusX_clicked()
{
    NBrak->setVisible(false);
    wybrane=7;
    ustalKolory();
    if(Dfarmer->ileUrsusx()<ID+1)
    {
    QFont czcionka("Times",10,QFont::Bold);
        NBrak=scene->addText("Brak UrsusaX na tym polu",czcionka);
     NBrak->setDefaultTextColor(Qt::darkRed);
     NBrak->setPos(300,450);
     NBrak->setVisible(true);
    }
}
