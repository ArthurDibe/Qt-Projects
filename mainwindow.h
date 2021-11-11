#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "welcomedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HelloWorld; }
QT_END_NAMESPACE

class HelloWorld : public QMainWindow
{
    Q_OBJECT

public:
    HelloWorld(QWidget *parent = nullptr);
    ~HelloWorld();
    void onClicked();

private:
    Ui::HelloWorld *ui;
    WelcomeDialog *welcomeDialog;
};
#endif // MAINWINDOW_H
