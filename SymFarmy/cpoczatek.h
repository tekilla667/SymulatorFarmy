#ifndef CPOCZATEK_H
#define CPOCZATEK_H

#include <QWidget>

namespace Ui {
class CPoczatek;
}

class CPoczatek : public QWidget
{
    Q_OBJECT

public:
    explicit CPoczatek(QWidget *parent = nullptr);
    ~CPoczatek();
    int kasa;
private:
    Ui::CPoczatek *ui;
signals:
    void startKlik();
private slots:
    void on_pushButton_clicked();
};

#endif // CPOCZATEK_H
