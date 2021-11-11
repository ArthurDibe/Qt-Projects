#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "welcomedialog.h"

HelloWorld::HelloWorld(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HelloWorld)
{
    ui->setupUi(this);
    connect(ui->okButton, &QPushButton::clicked, this, &HelloWorld::onClicked);
}

HelloWorld::~HelloWorld()
{
    delete ui;
    delete welcomeDialog;
}

// Handles click on okButton
void HelloWorld::onClicked()
{
    QPushButton* okButton = qobject_cast<QPushButton*>(sender());

    if(okButton != nullptr)
    {
        okButton->setStyleSheet(QString("#%1 { background-color: red; }").arg(okButton->objectName()));

//        // using the modal approach in order to not let the main
//        // window be accessed while the welcome window is open
//        WelcomeDialog welcomeDialog; // instantiate the welcome dialog window
//        welcomeDialog.setModal(true);//
//        welcomeDialog.exec(); // open the welcome dialog


        // Modal LESS approach of creating another window
        // it will allow the other window to be used at the
        // same time as the main window
        // to make this approach to work, we have to instantiate
        // the dialog box object in the HEAP, meaning that
        // we need to create a pointer of it as a private member
        // and then we need to allocate memory for it and deallocate
        // in the destructor
        welcomeDialog = new WelcomeDialog(this);
        welcomeDialog->show();

//        hide(); // to hide the main window

    }
}
