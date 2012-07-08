/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 8. Jul 00:54:46 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *footer;
    QGraphicsView *header;
    QGroupBox *groupBox;
    QGroupBox *groupBox_Authentification;
    QLineEdit *lineEdit_Login;
    QLineEdit *lineEdit_Password;
    QLabel *label_Login;
    QLabel *label_Password;
    QPushButton *pushButton_Connexion;
    QProgressBar *progressBar;
    QLabel *label_Erreur;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(920, 655);
        MainWindow->setDockNestingEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        footer = new QGraphicsView(centralWidget);
        footer->setObjectName(QString::fromUtf8("footer"));
        footer->setMinimumSize(QSize(900, 50));
        footer->setMaximumSize(QSize(900, 50));

        gridLayout->addWidget(footer, 2, 0, 1, 1);

        header = new QGraphicsView(centralWidget);
        header->setObjectName(QString::fromUtf8("header"));
        header->setMinimumSize(QSize(900, 100));
        header->setMaximumSize(QSize(900, 100));

        gridLayout->addWidget(header, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(902, 475));
        groupBox->setMaximumSize(QSize(902, 475));
        groupBox_Authentification = new QGroupBox(groupBox);
        groupBox_Authentification->setObjectName(QString::fromUtf8("groupBox_Authentification"));
        groupBox_Authentification->setGeometry(QRect(350, 130, 300, 191));
        lineEdit_Login = new QLineEdit(groupBox_Authentification);
        lineEdit_Login->setObjectName(QString::fromUtf8("lineEdit_Login"));
        lineEdit_Login->setGeometry(QRect(20, 50, 250, 25));
        lineEdit_Password = new QLineEdit(groupBox_Authentification);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(20, 100, 250, 25));
        label_Login = new QLabel(groupBox_Authentification);
        label_Login->setObjectName(QString::fromUtf8("label_Login"));
        label_Login->setGeometry(QRect(20, 30, 100, 13));
        label_Password = new QLabel(groupBox_Authentification);
        label_Password->setObjectName(QString::fromUtf8("label_Password"));
        label_Password->setGeometry(QRect(20, 80, 100, 13));
        pushButton_Connexion = new QPushButton(groupBox_Authentification);
        pushButton_Connexion->setObjectName(QString::fromUtf8("pushButton_Connexion"));
        pushButton_Connexion->setGeometry(QRect(110, 140, 75, 25));
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(330, 200, 371, 23));
        progressBar->setValue(0);
        label_Erreur = new QLabel(groupBox);
        label_Erreur->setObjectName(QString::fromUtf8("label_Erreur"));
        label_Erreur->setGeometry(QRect(350, 80, 301, 20));
        label_Erreur->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Smart-Stock", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        groupBox_Authentification->setTitle(QApplication::translate("MainWindow", "Authentification", 0, QApplication::UnicodeUTF8));
        label_Login->setText(QApplication::translate("MainWindow", "Login:", 0, QApplication::UnicodeUTF8));
        label_Password->setText(QApplication::translate("MainWindow", "Mot de passe:", 0, QApplication::UnicodeUTF8));
        pushButton_Connexion->setText(QApplication::translate("MainWindow", "Se connecter", 0, QApplication::UnicodeUTF8));
        label_Erreur->setText(QApplication::translate("MainWindow", "Identifiez-Vous", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
