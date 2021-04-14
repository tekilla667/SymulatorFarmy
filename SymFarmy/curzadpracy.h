#ifndef CURZADPRACY_H
#define CURZADPRACY_H

#include <QWidget>

namespace Ui {
class CUrzadpracy;
}

class CUrzadpracy : public QWidget
{
    Q_OBJECT

public:
    explicit CUrzadpracy(QWidget *parent = nullptr);
    ~CUrzadpracy();
    int doZatrudnienia;
    void ustalNapisDostepnych();
    void ustalNapisPosiadanych(int liczba);
    int liczbaPracownikow;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void startKlik();
    void DodajPracownikow();

private:
    Ui::CUrzadpracy *ui;
};

#endif // CURZADPRACY_H
