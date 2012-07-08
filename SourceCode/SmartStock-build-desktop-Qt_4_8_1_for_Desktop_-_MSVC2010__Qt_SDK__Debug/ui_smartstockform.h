/********************************************************************************
** Form generated from reading UI file 'smartstockform.ui'
**
** Created: Sun 8. Jul 10:39:14 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTSTOCKFORM_H
#define UI_SMARTSTOCKFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmartStockForm
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *header;
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    QWidget *Stock;
    QListView *listView_Stock__Produit;
    QLabel *label_Stock_Categorie_2;
    QComboBox *comboBox_Stock_Categorie;
    QGroupBox *groupBox_Stock_Produit;
    QLabel *label_Stock_Produit;
    QLineEdit *lineEdit_Stock_Produit;
    QGraphicsView *graphicsView_Stock_Photo;
    QPushButton *pushButton_Stock_Entree;
    QPushButton *pushButton_Stock_Sortie;
    QLineEdit *lineEdit_Stock_Prix;
    QLabel *label_Stock_Prix;
    QLabel *label_Stock_Categorie;
    QLineEdit *lineEdit_Stock_Categorie;
    QLineEdit *lineEdit_Stock_Quantite;
    QLabel *label_Stock_Quantite;
    QLineEdit *lineEdit_Stock_QuantiteActuel;
    QLabel *label_Stock_QuantiteActuel;
    QLabel *label_Stock_MessageErreur;
    QGroupBox *groupBox_Stock;
    QTableView *tableView_Stock;
    QWidget *Historique;
    QGroupBox *groupBox_Historique_IN;
    QTableView *tableView_Historique_IN;
    QGroupBox *groupBox_Historique_IN_2;
    QTableView *tableView_Historique_OUT;
    QWidget *Produits;
    QListView *listView_Prod_Produit;
    QGroupBox *groupBox_Prod_Produit;
    QLabel *label_Prod_Produit;
    QLabel *label_Prod_Photo;
    QLabel *label_Prod_Description;
    QPlainTextEdit *plainTextEdit_Prod_Description;
    QLineEdit *lineEdit_Prod_Produit;
    QLineEdit *lineEdit_Prod_Photo;
    QGraphicsView *graphicsView_Prod_Photo;
    QPushButton *pushButton_Prod_Ajouter;
    QPushButton *pushButton_Prod_Enregistrer;
    QPushButton *pushButton_Prod_Modifier;
    QPushButton *pushButton_Prod_Supprimer;
    QLineEdit *lineEdit_Prod_Prix;
    QLabel *label_Prod_Prix;
    QLineEdit *lineEdit_Prod_Active;
    QLabel *label_Prod_Active;
    QLabel *label_Prod_Categorie_2;
    QLineEdit *lineEdit_Prod_Categorie;
    QPushButton *pushButton_Prod_Desactiver;
    QComboBox *comboBox_Prod_Categorie_2;
    QPushButton *pushButton_Prod_ParcourirPhoto;
    QComboBox *comboBox_Prod_Categorie;
    QLabel *label_Prod_Categorie;
    QWidget *Categories;
    QListView *listView_Categorie;
    QGroupBox *groupBox_Cat_Categorie;
    QLabel *label_Cat_Categorie;
    QLabel *label_Cat_Photo;
    QLabel *label_Cat_Description;
    QPlainTextEdit *plainTextEdit_Cat_Description;
    QLineEdit *lineEdit_Cat_Categorie;
    QLineEdit *lineEdit_Cat_Photo;
    QGraphicsView *graphicsView_Cat_Photo;
    QPushButton *pushButton_Cat_Ajouter;
    QPushButton *pushButton_Cat_Enregistrer;
    QPushButton *pushButton_Cat_Modifier;
    QPushButton *pushButton_Cat_Supprimer;
    QWidget *Statistiques;
    QGroupBox *groupBox_Stat_BM;
    QTableView *tableView_Stat_BM;
    QGroupBox *groupBox_Stat_BY;
    QTableView *tableView_Stat_BY;
    QGroupBox *groupBox_Stat_WM;
    QTableView *tableView_Stat_WM;
    QWidget *MonCompte;
    QLabel *label_Login;
    QLabel *label_Password;
    QLabel *label_Nom;
    QLabel *label_Active;
    QLabel *label_Droits;
    QLabel *label_Photo;
    QGraphicsView *graphicsView_PhotoUser;
    QLabel *label_Photo_2;
    QLabel *label_Nom_2;
    QLabel *label_Droits_2;
    QLabel *label_Password_2;
    QLabel *label_Login_2;
    QLabel *label_Active_2;
    QWidget *Utilisateurs;
    QListView *listView_Utilisateur;
    QGroupBox *groupBox_User_Utilisateur;
    QLabel *label_User_Login;
    QLabel *label_User_Photo;
    QLineEdit *lineEdit_User_Login;
    QLineEdit *lineEdit_User_Photo;
    QGraphicsView *graphicsView_User_Photo;
    QPushButton *pushButton_User_Ajouter;
    QPushButton *pushButton_User_Enregistrer;
    QPushButton *pushButton_User_Modifier;
    QPushButton *pushButton_User_Supprimer;
    QPushButton *pushButton_User_Desactiver;
    QLabel *label_User_Password;
    QLineEdit *lineEdit_User_Password;
    QLabel *label_User_Nom;
    QLineEdit *lineEdit_User_Nom;
    QLabel *label_User_Active;
    QLineEdit *lineEdit_User_Active;
    QLabel *label_User_Droits;
    QLineEdit *lineEdit_User_Droits;
    QWidget *APropos;
    QPushButton *pushButton_Fermer;
    QPushButton *pushButton;
    QGraphicsView *footer;

    void setupUi(QWidget *SmartStockForm)
    {
        if (SmartStockForm->objectName().isEmpty())
            SmartStockForm->setObjectName(QString::fromUtf8("SmartStockForm"));
        SmartStockForm->resize(920, 655);
        gridLayout = new QGridLayout(SmartStockForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        header = new QGraphicsView(SmartStockForm);
        header->setObjectName(QString::fromUtf8("header"));
        header->setMinimumSize(QSize(900, 100));
        header->setMaximumSize(QSize(900, 100));

        gridLayout->addWidget(header, 0, 0, 1, 1);

        groupBox = new QGroupBox(SmartStockForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(902, 475));
        groupBox->setMaximumSize(QSize(902, 475));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 881, 451));
        Stock = new QWidget();
        Stock->setObjectName(QString::fromUtf8("Stock"));
        listView_Stock__Produit = new QListView(Stock);
        listView_Stock__Produit->setObjectName(QString::fromUtf8("listView_Stock__Produit"));
        listView_Stock__Produit->setGeometry(QRect(10, 60, 256, 351));
        label_Stock_Categorie_2 = new QLabel(Stock);
        label_Stock_Categorie_2->setObjectName(QString::fromUtf8("label_Stock_Categorie_2"));
        label_Stock_Categorie_2->setGeometry(QRect(10, 20, 51, 20));
        comboBox_Stock_Categorie = new QComboBox(Stock);
        comboBox_Stock_Categorie->setObjectName(QString::fromUtf8("comboBox_Stock_Categorie"));
        comboBox_Stock_Categorie->setGeometry(QRect(70, 20, 200, 20));
        groupBox_Stock_Produit = new QGroupBox(Stock);
        groupBox_Stock_Produit->setObjectName(QString::fromUtf8("groupBox_Stock_Produit"));
        groupBox_Stock_Produit->setGeometry(QRect(310, 10, 311, 401));
        label_Stock_Produit = new QLabel(groupBox_Stock_Produit);
        label_Stock_Produit->setObjectName(QString::fromUtf8("label_Stock_Produit"));
        label_Stock_Produit->setGeometry(QRect(20, 30, 70, 20));
        lineEdit_Stock_Produit = new QLineEdit(groupBox_Stock_Produit);
        lineEdit_Stock_Produit->setObjectName(QString::fromUtf8("lineEdit_Stock_Produit"));
        lineEdit_Stock_Produit->setGeometry(QRect(90, 30, 200, 20));
        lineEdit_Stock_Produit->setReadOnly(true);
        graphicsView_Stock_Photo = new QGraphicsView(groupBox_Stock_Produit);
        graphicsView_Stock_Photo->setObjectName(QString::fromUtf8("graphicsView_Stock_Photo"));
        graphicsView_Stock_Photo->setGeometry(QRect(200, 60, 100, 100));
        pushButton_Stock_Entree = new QPushButton(groupBox_Stock_Produit);
        pushButton_Stock_Entree->setObjectName(QString::fromUtf8("pushButton_Stock_Entree"));
        pushButton_Stock_Entree->setGeometry(QRect(30, 290, 75, 23));
        pushButton_Stock_Sortie = new QPushButton(groupBox_Stock_Produit);
        pushButton_Stock_Sortie->setObjectName(QString::fromUtf8("pushButton_Stock_Sortie"));
        pushButton_Stock_Sortie->setGeometry(QRect(120, 290, 75, 23));
        lineEdit_Stock_Prix = new QLineEdit(groupBox_Stock_Produit);
        lineEdit_Stock_Prix->setObjectName(QString::fromUtf8("lineEdit_Stock_Prix"));
        lineEdit_Stock_Prix->setGeometry(QRect(90, 90, 100, 20));
        lineEdit_Stock_Prix->setReadOnly(true);
        label_Stock_Prix = new QLabel(groupBox_Stock_Produit);
        label_Stock_Prix->setObjectName(QString::fromUtf8("label_Stock_Prix"));
        label_Stock_Prix->setGeometry(QRect(20, 90, 70, 20));
        label_Stock_Categorie = new QLabel(groupBox_Stock_Produit);
        label_Stock_Categorie->setObjectName(QString::fromUtf8("label_Stock_Categorie"));
        label_Stock_Categorie->setEnabled(true);
        label_Stock_Categorie->setGeometry(QRect(20, 60, 70, 20));
        lineEdit_Stock_Categorie = new QLineEdit(groupBox_Stock_Produit);
        lineEdit_Stock_Categorie->setObjectName(QString::fromUtf8("lineEdit_Stock_Categorie"));
        lineEdit_Stock_Categorie->setEnabled(true);
        lineEdit_Stock_Categorie->setGeometry(QRect(90, 60, 100, 20));
        lineEdit_Stock_Categorie->setReadOnly(true);
        lineEdit_Stock_Quantite = new QLineEdit(groupBox_Stock_Produit);
        lineEdit_Stock_Quantite->setObjectName(QString::fromUtf8("lineEdit_Stock_Quantite"));
        lineEdit_Stock_Quantite->setGeometry(QRect(90, 250, 100, 20));
        label_Stock_Quantite = new QLabel(groupBox_Stock_Produit);
        label_Stock_Quantite->setObjectName(QString::fromUtf8("label_Stock_Quantite"));
        label_Stock_Quantite->setGeometry(QRect(20, 250, 70, 20));
        lineEdit_Stock_QuantiteActuel = new QLineEdit(groupBox_Stock_Produit);
        lineEdit_Stock_QuantiteActuel->setObjectName(QString::fromUtf8("lineEdit_Stock_QuantiteActuel"));
        lineEdit_Stock_QuantiteActuel->setGeometry(QRect(90, 140, 100, 20));
        lineEdit_Stock_QuantiteActuel->setReadOnly(true);
        label_Stock_QuantiteActuel = new QLabel(groupBox_Stock_Produit);
        label_Stock_QuantiteActuel->setObjectName(QString::fromUtf8("label_Stock_QuantiteActuel"));
        label_Stock_QuantiteActuel->setGeometry(QRect(20, 140, 70, 20));
        label_Stock_MessageErreur = new QLabel(groupBox_Stock_Produit);
        label_Stock_MessageErreur->setObjectName(QString::fromUtf8("label_Stock_MessageErreur"));
        label_Stock_MessageErreur->setGeometry(QRect(20, 200, 281, 20));
        label_Stock_MessageErreur->setAlignment(Qt::AlignCenter);
        groupBox_Stock = new QGroupBox(Stock);
        groupBox_Stock->setObjectName(QString::fromUtf8("groupBox_Stock"));
        groupBox_Stock->setGeometry(QRect(630, 10, 241, 401));
        tableView_Stock = new QTableView(groupBox_Stock);
        tableView_Stock->setObjectName(QString::fromUtf8("tableView_Stock"));
        tableView_Stock->setGeometry(QRect(10, 20, 221, 371));
        tabWidget->addTab(Stock, QString());
        Historique = new QWidget();
        Historique->setObjectName(QString::fromUtf8("Historique"));
        groupBox_Historique_IN = new QGroupBox(Historique);
        groupBox_Historique_IN->setObjectName(QString::fromUtf8("groupBox_Historique_IN"));
        groupBox_Historique_IN->setGeometry(QRect(10, 10, 420, 401));
        tableView_Historique_IN = new QTableView(groupBox_Historique_IN);
        tableView_Historique_IN->setObjectName(QString::fromUtf8("tableView_Historique_IN"));
        tableView_Historique_IN->setGeometry(QRect(10, 20, 401, 371));
        groupBox_Historique_IN_2 = new QGroupBox(Historique);
        groupBox_Historique_IN_2->setObjectName(QString::fromUtf8("groupBox_Historique_IN_2"));
        groupBox_Historique_IN_2->setGeometry(QRect(450, 10, 420, 401));
        tableView_Historique_OUT = new QTableView(groupBox_Historique_IN_2);
        tableView_Historique_OUT->setObjectName(QString::fromUtf8("tableView_Historique_OUT"));
        tableView_Historique_OUT->setGeometry(QRect(10, 20, 401, 371));
        tabWidget->addTab(Historique, QString());
        Produits = new QWidget();
        Produits->setObjectName(QString::fromUtf8("Produits"));
        listView_Prod_Produit = new QListView(Produits);
        listView_Prod_Produit->setObjectName(QString::fromUtf8("listView_Prod_Produit"));
        listView_Prod_Produit->setGeometry(QRect(10, 60, 256, 351));
        groupBox_Prod_Produit = new QGroupBox(Produits);
        groupBox_Prod_Produit->setObjectName(QString::fromUtf8("groupBox_Prod_Produit"));
        groupBox_Prod_Produit->setGeometry(QRect(310, 10, 550, 401));
        label_Prod_Produit = new QLabel(groupBox_Prod_Produit);
        label_Prod_Produit->setObjectName(QString::fromUtf8("label_Prod_Produit"));
        label_Prod_Produit->setGeometry(QRect(20, 30, 70, 20));
        label_Prod_Photo = new QLabel(groupBox_Prod_Produit);
        label_Prod_Photo->setObjectName(QString::fromUtf8("label_Prod_Photo"));
        label_Prod_Photo->setGeometry(QRect(20, 190, 70, 20));
        label_Prod_Description = new QLabel(groupBox_Prod_Produit);
        label_Prod_Description->setObjectName(QString::fromUtf8("label_Prod_Description"));
        label_Prod_Description->setGeometry(QRect(20, 110, 70, 16));
        plainTextEdit_Prod_Description = new QPlainTextEdit(groupBox_Prod_Produit);
        plainTextEdit_Prod_Description->setObjectName(QString::fromUtf8("plainTextEdit_Prod_Description"));
        plainTextEdit_Prod_Description->setGeometry(QRect(90, 60, 200, 121));
        plainTextEdit_Prod_Description->setReadOnly(false);
        lineEdit_Prod_Produit = new QLineEdit(groupBox_Prod_Produit);
        lineEdit_Prod_Produit->setObjectName(QString::fromUtf8("lineEdit_Prod_Produit"));
        lineEdit_Prod_Produit->setGeometry(QRect(90, 30, 200, 20));
        lineEdit_Prod_Produit->setReadOnly(true);
        lineEdit_Prod_Photo = new QLineEdit(groupBox_Prod_Produit);
        lineEdit_Prod_Photo->setObjectName(QString::fromUtf8("lineEdit_Prod_Photo"));
        lineEdit_Prod_Photo->setGeometry(QRect(90, 190, 200, 20));
        lineEdit_Prod_Photo->setReadOnly(false);
        graphicsView_Prod_Photo = new QGraphicsView(groupBox_Prod_Produit);
        graphicsView_Prod_Photo->setObjectName(QString::fromUtf8("graphicsView_Prod_Photo"));
        graphicsView_Prod_Photo->setGeometry(QRect(340, 30, 200, 200));
        pushButton_Prod_Ajouter = new QPushButton(groupBox_Prod_Produit);
        pushButton_Prod_Ajouter->setObjectName(QString::fromUtf8("pushButton_Prod_Ajouter"));
        pushButton_Prod_Ajouter->setGeometry(QRect(70, 360, 75, 23));
        pushButton_Prod_Enregistrer = new QPushButton(groupBox_Prod_Produit);
        pushButton_Prod_Enregistrer->setObjectName(QString::fromUtf8("pushButton_Prod_Enregistrer"));
        pushButton_Prod_Enregistrer->setGeometry(QRect(160, 360, 75, 23));
        pushButton_Prod_Modifier = new QPushButton(groupBox_Prod_Produit);
        pushButton_Prod_Modifier->setObjectName(QString::fromUtf8("pushButton_Prod_Modifier"));
        pushButton_Prod_Modifier->setGeometry(QRect(250, 360, 75, 23));
        pushButton_Prod_Supprimer = new QPushButton(groupBox_Prod_Produit);
        pushButton_Prod_Supprimer->setObjectName(QString::fromUtf8("pushButton_Prod_Supprimer"));
        pushButton_Prod_Supprimer->setGeometry(QRect(340, 360, 75, 23));
        lineEdit_Prod_Prix = new QLineEdit(groupBox_Prod_Produit);
        lineEdit_Prod_Prix->setObjectName(QString::fromUtf8("lineEdit_Prod_Prix"));
        lineEdit_Prod_Prix->setGeometry(QRect(90, 220, 200, 20));
        lineEdit_Prod_Prix->setReadOnly(false);
        label_Prod_Prix = new QLabel(groupBox_Prod_Produit);
        label_Prod_Prix->setObjectName(QString::fromUtf8("label_Prod_Prix"));
        label_Prod_Prix->setGeometry(QRect(20, 220, 70, 20));
        lineEdit_Prod_Active = new QLineEdit(groupBox_Prod_Produit);
        lineEdit_Prod_Active->setObjectName(QString::fromUtf8("lineEdit_Prod_Active"));
        lineEdit_Prod_Active->setGeometry(QRect(90, 250, 200, 20));
        lineEdit_Prod_Active->setReadOnly(false);
        label_Prod_Active = new QLabel(groupBox_Prod_Produit);
        label_Prod_Active->setObjectName(QString::fromUtf8("label_Prod_Active"));
        label_Prod_Active->setGeometry(QRect(20, 250, 70, 20));
        label_Prod_Categorie_2 = new QLabel(groupBox_Prod_Produit);
        label_Prod_Categorie_2->setObjectName(QString::fromUtf8("label_Prod_Categorie_2"));
        label_Prod_Categorie_2->setEnabled(true);
        label_Prod_Categorie_2->setGeometry(QRect(20, 280, 70, 20));
        lineEdit_Prod_Categorie = new QLineEdit(groupBox_Prod_Produit);
        lineEdit_Prod_Categorie->setObjectName(QString::fromUtf8("lineEdit_Prod_Categorie"));
        lineEdit_Prod_Categorie->setEnabled(true);
        lineEdit_Prod_Categorie->setGeometry(QRect(90, 280, 200, 20));
        lineEdit_Prod_Categorie->setReadOnly(true);
        pushButton_Prod_Desactiver = new QPushButton(groupBox_Prod_Produit);
        pushButton_Prod_Desactiver->setObjectName(QString::fromUtf8("pushButton_Prod_Desactiver"));
        pushButton_Prod_Desactiver->setGeometry(QRect(430, 360, 75, 23));
        comboBox_Prod_Categorie_2 = new QComboBox(groupBox_Prod_Produit);
        comboBox_Prod_Categorie_2->setObjectName(QString::fromUtf8("comboBox_Prod_Categorie_2"));
        comboBox_Prod_Categorie_2->setEnabled(true);
        comboBox_Prod_Categorie_2->setGeometry(QRect(90, 280, 200, 20));
        pushButton_Prod_ParcourirPhoto = new QPushButton(groupBox_Prod_Produit);
        pushButton_Prod_ParcourirPhoto->setObjectName(QString::fromUtf8("pushButton_Prod_ParcourirPhoto"));
        pushButton_Prod_ParcourirPhoto->setEnabled(false);
        pushButton_Prod_ParcourirPhoto->setGeometry(QRect(390, 250, 75, 23));
        comboBox_Prod_Categorie = new QComboBox(Produits);
        comboBox_Prod_Categorie->setObjectName(QString::fromUtf8("comboBox_Prod_Categorie"));
        comboBox_Prod_Categorie->setGeometry(QRect(70, 20, 200, 20));
        label_Prod_Categorie = new QLabel(Produits);
        label_Prod_Categorie->setObjectName(QString::fromUtf8("label_Prod_Categorie"));
        label_Prod_Categorie->setGeometry(QRect(10, 20, 51, 20));
        tabWidget->addTab(Produits, QString());
        Categories = new QWidget();
        Categories->setObjectName(QString::fromUtf8("Categories"));
        listView_Categorie = new QListView(Categories);
        listView_Categorie->setObjectName(QString::fromUtf8("listView_Categorie"));
        listView_Categorie->setGeometry(QRect(10, 20, 256, 391));
        groupBox_Cat_Categorie = new QGroupBox(Categories);
        groupBox_Cat_Categorie->setObjectName(QString::fromUtf8("groupBox_Cat_Categorie"));
        groupBox_Cat_Categorie->setGeometry(QRect(310, 10, 550, 300));
        label_Cat_Categorie = new QLabel(groupBox_Cat_Categorie);
        label_Cat_Categorie->setObjectName(QString::fromUtf8("label_Cat_Categorie"));
        label_Cat_Categorie->setGeometry(QRect(20, 30, 70, 20));
        label_Cat_Photo = new QLabel(groupBox_Cat_Categorie);
        label_Cat_Photo->setObjectName(QString::fromUtf8("label_Cat_Photo"));
        label_Cat_Photo->setGeometry(QRect(20, 190, 70, 20));
        label_Cat_Description = new QLabel(groupBox_Cat_Categorie);
        label_Cat_Description->setObjectName(QString::fromUtf8("label_Cat_Description"));
        label_Cat_Description->setGeometry(QRect(20, 110, 70, 16));
        plainTextEdit_Cat_Description = new QPlainTextEdit(groupBox_Cat_Categorie);
        plainTextEdit_Cat_Description->setObjectName(QString::fromUtf8("plainTextEdit_Cat_Description"));
        plainTextEdit_Cat_Description->setGeometry(QRect(90, 60, 200, 121));
        lineEdit_Cat_Categorie = new QLineEdit(groupBox_Cat_Categorie);
        lineEdit_Cat_Categorie->setObjectName(QString::fromUtf8("lineEdit_Cat_Categorie"));
        lineEdit_Cat_Categorie->setGeometry(QRect(90, 30, 200, 20));
        lineEdit_Cat_Photo = new QLineEdit(groupBox_Cat_Categorie);
        lineEdit_Cat_Photo->setObjectName(QString::fromUtf8("lineEdit_Cat_Photo"));
        lineEdit_Cat_Photo->setGeometry(QRect(90, 190, 200, 20));
        graphicsView_Cat_Photo = new QGraphicsView(groupBox_Cat_Categorie);
        graphicsView_Cat_Photo->setObjectName(QString::fromUtf8("graphicsView_Cat_Photo"));
        graphicsView_Cat_Photo->setGeometry(QRect(340, 30, 200, 200));
        pushButton_Cat_Ajouter = new QPushButton(groupBox_Cat_Categorie);
        pushButton_Cat_Ajouter->setObjectName(QString::fromUtf8("pushButton_Cat_Ajouter"));
        pushButton_Cat_Ajouter->setGeometry(QRect(70, 260, 75, 23));
        pushButton_Cat_Enregistrer = new QPushButton(groupBox_Cat_Categorie);
        pushButton_Cat_Enregistrer->setObjectName(QString::fromUtf8("pushButton_Cat_Enregistrer"));
        pushButton_Cat_Enregistrer->setGeometry(QRect(160, 260, 75, 23));
        pushButton_Cat_Modifier = new QPushButton(groupBox_Cat_Categorie);
        pushButton_Cat_Modifier->setObjectName(QString::fromUtf8("pushButton_Cat_Modifier"));
        pushButton_Cat_Modifier->setGeometry(QRect(250, 260, 75, 23));
        pushButton_Cat_Supprimer = new QPushButton(groupBox_Cat_Categorie);
        pushButton_Cat_Supprimer->setObjectName(QString::fromUtf8("pushButton_Cat_Supprimer"));
        pushButton_Cat_Supprimer->setGeometry(QRect(340, 260, 75, 23));
        tabWidget->addTab(Categories, QString());
        Statistiques = new QWidget();
        Statistiques->setObjectName(QString::fromUtf8("Statistiques"));
        groupBox_Stat_BM = new QGroupBox(Statistiques);
        groupBox_Stat_BM->setObjectName(QString::fromUtf8("groupBox_Stat_BM"));
        groupBox_Stat_BM->setGeometry(QRect(10, 10, 241, 411));
        tableView_Stat_BM = new QTableView(groupBox_Stat_BM);
        tableView_Stat_BM->setObjectName(QString::fromUtf8("tableView_Stat_BM"));
        tableView_Stat_BM->setGeometry(QRect(10, 20, 221, 381));
        groupBox_Stat_BY = new QGroupBox(Statistiques);
        groupBox_Stat_BY->setObjectName(QString::fromUtf8("groupBox_Stat_BY"));
        groupBox_Stat_BY->setGeometry(QRect(320, 10, 241, 411));
        tableView_Stat_BY = new QTableView(groupBox_Stat_BY);
        tableView_Stat_BY->setObjectName(QString::fromUtf8("tableView_Stat_BY"));
        tableView_Stat_BY->setGeometry(QRect(10, 20, 221, 381));
        groupBox_Stat_WM = new QGroupBox(Statistiques);
        groupBox_Stat_WM->setObjectName(QString::fromUtf8("groupBox_Stat_WM"));
        groupBox_Stat_WM->setGeometry(QRect(630, 10, 241, 411));
        tableView_Stat_WM = new QTableView(groupBox_Stat_WM);
        tableView_Stat_WM->setObjectName(QString::fromUtf8("tableView_Stat_WM"));
        tableView_Stat_WM->setGeometry(QRect(10, 20, 221, 381));
        tabWidget->addTab(Statistiques, QString());
        MonCompte = new QWidget();
        MonCompte->setObjectName(QString::fromUtf8("MonCompte"));
        label_Login = new QLabel(MonCompte);
        label_Login->setObjectName(QString::fromUtf8("label_Login"));
        label_Login->setGeometry(QRect(300, 40, 171, 21));
        label_Password = new QLabel(MonCompte);
        label_Password->setObjectName(QString::fromUtf8("label_Password"));
        label_Password->setGeometry(QRect(300, 70, 171, 21));
        label_Password->setTextFormat(Qt::AutoText);
        label_Nom = new QLabel(MonCompte);
        label_Nom->setObjectName(QString::fromUtf8("label_Nom"));
        label_Nom->setGeometry(QRect(300, 100, 171, 21));
        label_Active = new QLabel(MonCompte);
        label_Active->setObjectName(QString::fromUtf8("label_Active"));
        label_Active->setGeometry(QRect(300, 130, 171, 21));
        label_Droits = new QLabel(MonCompte);
        label_Droits->setObjectName(QString::fromUtf8("label_Droits"));
        label_Droits->setGeometry(QRect(300, 160, 171, 21));
        label_Photo = new QLabel(MonCompte);
        label_Photo->setObjectName(QString::fromUtf8("label_Photo"));
        label_Photo->setGeometry(QRect(300, 190, 171, 21));
        graphicsView_PhotoUser = new QGraphicsView(MonCompte);
        graphicsView_PhotoUser->setObjectName(QString::fromUtf8("graphicsView_PhotoUser"));
        graphicsView_PhotoUser->setGeometry(QRect(10, 20, 200, 200));
        label_Photo_2 = new QLabel(MonCompte);
        label_Photo_2->setObjectName(QString::fromUtf8("label_Photo_2"));
        label_Photo_2->setGeometry(QRect(230, 190, 55, 21));
        label_Nom_2 = new QLabel(MonCompte);
        label_Nom_2->setObjectName(QString::fromUtf8("label_Nom_2"));
        label_Nom_2->setGeometry(QRect(230, 100, 55, 21));
        label_Droits_2 = new QLabel(MonCompte);
        label_Droits_2->setObjectName(QString::fromUtf8("label_Droits_2"));
        label_Droits_2->setGeometry(QRect(230, 160, 55, 21));
        label_Password_2 = new QLabel(MonCompte);
        label_Password_2->setObjectName(QString::fromUtf8("label_Password_2"));
        label_Password_2->setGeometry(QRect(230, 70, 55, 21));
        label_Login_2 = new QLabel(MonCompte);
        label_Login_2->setObjectName(QString::fromUtf8("label_Login_2"));
        label_Login_2->setGeometry(QRect(230, 40, 55, 21));
        label_Active_2 = new QLabel(MonCompte);
        label_Active_2->setObjectName(QString::fromUtf8("label_Active_2"));
        label_Active_2->setGeometry(QRect(230, 130, 55, 21));
        tabWidget->addTab(MonCompte, QString());
        Utilisateurs = new QWidget();
        Utilisateurs->setObjectName(QString::fromUtf8("Utilisateurs"));
        listView_Utilisateur = new QListView(Utilisateurs);
        listView_Utilisateur->setObjectName(QString::fromUtf8("listView_Utilisateur"));
        listView_Utilisateur->setGeometry(QRect(10, 20, 256, 391));
        groupBox_User_Utilisateur = new QGroupBox(Utilisateurs);
        groupBox_User_Utilisateur->setObjectName(QString::fromUtf8("groupBox_User_Utilisateur"));
        groupBox_User_Utilisateur->setGeometry(QRect(310, 10, 550, 300));
        label_User_Login = new QLabel(groupBox_User_Utilisateur);
        label_User_Login->setObjectName(QString::fromUtf8("label_User_Login"));
        label_User_Login->setGeometry(QRect(20, 30, 70, 20));
        label_User_Photo = new QLabel(groupBox_User_Utilisateur);
        label_User_Photo->setObjectName(QString::fromUtf8("label_User_Photo"));
        label_User_Photo->setGeometry(QRect(20, 190, 70, 20));
        lineEdit_User_Login = new QLineEdit(groupBox_User_Utilisateur);
        lineEdit_User_Login->setObjectName(QString::fromUtf8("lineEdit_User_Login"));
        lineEdit_User_Login->setGeometry(QRect(90, 30, 200, 20));
        lineEdit_User_Login->setReadOnly(true);
        lineEdit_User_Photo = new QLineEdit(groupBox_User_Utilisateur);
        lineEdit_User_Photo->setObjectName(QString::fromUtf8("lineEdit_User_Photo"));
        lineEdit_User_Photo->setGeometry(QRect(90, 190, 200, 20));
        graphicsView_User_Photo = new QGraphicsView(groupBox_User_Utilisateur);
        graphicsView_User_Photo->setObjectName(QString::fromUtf8("graphicsView_User_Photo"));
        graphicsView_User_Photo->setGeometry(QRect(340, 30, 200, 200));
        pushButton_User_Ajouter = new QPushButton(groupBox_User_Utilisateur);
        pushButton_User_Ajouter->setObjectName(QString::fromUtf8("pushButton_User_Ajouter"));
        pushButton_User_Ajouter->setGeometry(QRect(30, 260, 75, 23));
        pushButton_User_Enregistrer = new QPushButton(groupBox_User_Utilisateur);
        pushButton_User_Enregistrer->setObjectName(QString::fromUtf8("pushButton_User_Enregistrer"));
        pushButton_User_Enregistrer->setGeometry(QRect(120, 260, 75, 23));
        pushButton_User_Modifier = new QPushButton(groupBox_User_Utilisateur);
        pushButton_User_Modifier->setObjectName(QString::fromUtf8("pushButton_User_Modifier"));
        pushButton_User_Modifier->setGeometry(QRect(210, 260, 75, 23));
        pushButton_User_Supprimer = new QPushButton(groupBox_User_Utilisateur);
        pushButton_User_Supprimer->setObjectName(QString::fromUtf8("pushButton_User_Supprimer"));
        pushButton_User_Supprimer->setGeometry(QRect(300, 260, 75, 23));
        pushButton_User_Desactiver = new QPushButton(groupBox_User_Utilisateur);
        pushButton_User_Desactiver->setObjectName(QString::fromUtf8("pushButton_User_Desactiver"));
        pushButton_User_Desactiver->setGeometry(QRect(390, 260, 75, 23));
        label_User_Password = new QLabel(groupBox_User_Utilisateur);
        label_User_Password->setObjectName(QString::fromUtf8("label_User_Password"));
        label_User_Password->setGeometry(QRect(20, 60, 70, 20));
        lineEdit_User_Password = new QLineEdit(groupBox_User_Utilisateur);
        lineEdit_User_Password->setObjectName(QString::fromUtf8("lineEdit_User_Password"));
        lineEdit_User_Password->setGeometry(QRect(90, 60, 200, 20));
        label_User_Nom = new QLabel(groupBox_User_Utilisateur);
        label_User_Nom->setObjectName(QString::fromUtf8("label_User_Nom"));
        label_User_Nom->setGeometry(QRect(20, 90, 70, 20));
        lineEdit_User_Nom = new QLineEdit(groupBox_User_Utilisateur);
        lineEdit_User_Nom->setObjectName(QString::fromUtf8("lineEdit_User_Nom"));
        lineEdit_User_Nom->setGeometry(QRect(90, 90, 200, 20));
        label_User_Active = new QLabel(groupBox_User_Utilisateur);
        label_User_Active->setObjectName(QString::fromUtf8("label_User_Active"));
        label_User_Active->setGeometry(QRect(20, 120, 70, 20));
        lineEdit_User_Active = new QLineEdit(groupBox_User_Utilisateur);
        lineEdit_User_Active->setObjectName(QString::fromUtf8("lineEdit_User_Active"));
        lineEdit_User_Active->setGeometry(QRect(90, 120, 200, 20));
        label_User_Droits = new QLabel(groupBox_User_Utilisateur);
        label_User_Droits->setObjectName(QString::fromUtf8("label_User_Droits"));
        label_User_Droits->setGeometry(QRect(20, 150, 70, 20));
        lineEdit_User_Droits = new QLineEdit(groupBox_User_Utilisateur);
        lineEdit_User_Droits->setObjectName(QString::fromUtf8("lineEdit_User_Droits"));
        lineEdit_User_Droits->setGeometry(QRect(90, 150, 200, 20));
        tabWidget->addTab(Utilisateurs, QString());
        APropos = new QWidget();
        APropos->setObjectName(QString::fromUtf8("APropos"));
        tabWidget->addTab(APropos, QString());
        pushButton_Fermer = new QPushButton(groupBox);
        pushButton_Fermer->setObjectName(QString::fromUtf8("pushButton_Fermer"));
        pushButton_Fermer->setGeometry(QRect(820, 10, 75, 23));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(740, 10, 75, 23));

        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        footer = new QGraphicsView(SmartStockForm);
        footer->setObjectName(QString::fromUtf8("footer"));
        footer->setMinimumSize(QSize(900, 50));
        footer->setMaximumSize(QSize(900, 50));

        gridLayout->addWidget(footer, 2, 0, 1, 1);


        retranslateUi(SmartStockForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SmartStockForm);
    } // setupUi

    void retranslateUi(QWidget *SmartStockForm)
    {
        SmartStockForm->setWindowTitle(QApplication::translate("SmartStockForm", "Smart-Stock", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_Stock_Categorie_2->setText(QApplication::translate("SmartStockForm", "Categorie:", 0, QApplication::UnicodeUTF8));
        groupBox_Stock_Produit->setTitle(QApplication::translate("SmartStockForm", "Produit:", 0, QApplication::UnicodeUTF8));
        label_Stock_Produit->setText(QApplication::translate("SmartStockForm", "Produit:", 0, QApplication::UnicodeUTF8));
        pushButton_Stock_Entree->setText(QApplication::translate("SmartStockForm", "Entr\303\251e", 0, QApplication::UnicodeUTF8));
        pushButton_Stock_Sortie->setText(QApplication::translate("SmartStockForm", "Sortie", 0, QApplication::UnicodeUTF8));
        label_Stock_Prix->setText(QApplication::translate("SmartStockForm", "Prix:", 0, QApplication::UnicodeUTF8));
        label_Stock_Categorie->setText(QApplication::translate("SmartStockForm", "Cat\303\251gorie:", 0, QApplication::UnicodeUTF8));
        lineEdit_Stock_Categorie->setText(QString());
        label_Stock_Quantite->setText(QApplication::translate("SmartStockForm", "Quanti\303\251:", 0, QApplication::UnicodeUTF8));
        label_Stock_QuantiteActuel->setText(QApplication::translate("SmartStockForm", "Quanti\303\251:", 0, QApplication::UnicodeUTF8));
        label_Stock_MessageErreur->setText(QApplication::translate("SmartStockForm", "MessageErreur", 0, QApplication::UnicodeUTF8));
        groupBox_Stock->setTitle(QApplication::translate("SmartStockForm", "Stock", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Stock), QApplication::translate("SmartStockForm", "Stock", 0, QApplication::UnicodeUTF8));
        groupBox_Historique_IN->setTitle(QApplication::translate("SmartStockForm", "Entre\303\251", 0, QApplication::UnicodeUTF8));
        groupBox_Historique_IN_2->setTitle(QApplication::translate("SmartStockForm", "Sortie", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Historique), QApplication::translate("SmartStockForm", "Historique", 0, QApplication::UnicodeUTF8));
        groupBox_Prod_Produit->setTitle(QApplication::translate("SmartStockForm", "Produit:", 0, QApplication::UnicodeUTF8));
        label_Prod_Produit->setText(QApplication::translate("SmartStockForm", "Produit:", 0, QApplication::UnicodeUTF8));
        label_Prod_Photo->setText(QApplication::translate("SmartStockForm", "Photo:", 0, QApplication::UnicodeUTF8));
        label_Prod_Description->setText(QApplication::translate("SmartStockForm", "Description:", 0, QApplication::UnicodeUTF8));
        pushButton_Prod_Ajouter->setText(QApplication::translate("SmartStockForm", "Ajouter", 0, QApplication::UnicodeUTF8));
        pushButton_Prod_Enregistrer->setText(QApplication::translate("SmartStockForm", "Enregistrer", 0, QApplication::UnicodeUTF8));
        pushButton_Prod_Modifier->setText(QApplication::translate("SmartStockForm", "Modifier", 0, QApplication::UnicodeUTF8));
        pushButton_Prod_Supprimer->setText(QApplication::translate("SmartStockForm", "Supprimer", 0, QApplication::UnicodeUTF8));
        label_Prod_Prix->setText(QApplication::translate("SmartStockForm", "Prix:", 0, QApplication::UnicodeUTF8));
        label_Prod_Active->setText(QApplication::translate("SmartStockForm", "Active:", 0, QApplication::UnicodeUTF8));
        label_Prod_Categorie_2->setText(QApplication::translate("SmartStockForm", "Cat\303\251gorie:", 0, QApplication::UnicodeUTF8));
        lineEdit_Prod_Categorie->setText(QString());
        pushButton_Prod_Desactiver->setText(QApplication::translate("SmartStockForm", "D\303\251sactiver", 0, QApplication::UnicodeUTF8));
        pushButton_Prod_ParcourirPhoto->setText(QApplication::translate("SmartStockForm", "Parcourir", 0, QApplication::UnicodeUTF8));
        label_Prod_Categorie->setText(QApplication::translate("SmartStockForm", "Categorie:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Produits), QApplication::translate("SmartStockForm", "Produits", 0, QApplication::UnicodeUTF8));
        groupBox_Cat_Categorie->setTitle(QApplication::translate("SmartStockForm", "Categorie:", 0, QApplication::UnicodeUTF8));
        label_Cat_Categorie->setText(QApplication::translate("SmartStockForm", "Categorie:", 0, QApplication::UnicodeUTF8));
        label_Cat_Photo->setText(QApplication::translate("SmartStockForm", "Photo:", 0, QApplication::UnicodeUTF8));
        label_Cat_Description->setText(QApplication::translate("SmartStockForm", "Description:", 0, QApplication::UnicodeUTF8));
        pushButton_Cat_Ajouter->setText(QApplication::translate("SmartStockForm", "Ajouter", 0, QApplication::UnicodeUTF8));
        pushButton_Cat_Enregistrer->setText(QApplication::translate("SmartStockForm", "Enregistrer", 0, QApplication::UnicodeUTF8));
        pushButton_Cat_Modifier->setText(QApplication::translate("SmartStockForm", "Modifier", 0, QApplication::UnicodeUTF8));
        pushButton_Cat_Supprimer->setText(QApplication::translate("SmartStockForm", "Supprimer", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Categories), QApplication::translate("SmartStockForm", "Categories", 0, QApplication::UnicodeUTF8));
        groupBox_Stat_BM->setTitle(QApplication::translate("SmartStockForm", "Meilleurs Produits pour ce mois", 0, QApplication::UnicodeUTF8));
        groupBox_Stat_BY->setTitle(QApplication::translate("SmartStockForm", "Meilleurs Produits de l'ann\303\251e", 0, QApplication::UnicodeUTF8));
        groupBox_Stat_WM->setTitle(QApplication::translate("SmartStockForm", "Toujours En Stock", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Statistiques), QApplication::translate("SmartStockForm", "Statistiques", 0, QApplication::UnicodeUTF8));
        label_Login->setText(QApplication::translate("SmartStockForm", "Login", 0, QApplication::UnicodeUTF8));
        label_Password->setText(QApplication::translate("SmartStockForm", "Password", 0, QApplication::UnicodeUTF8));
        label_Nom->setText(QApplication::translate("SmartStockForm", "Nom", 0, QApplication::UnicodeUTF8));
        label_Active->setText(QApplication::translate("SmartStockForm", "Active", 0, QApplication::UnicodeUTF8));
        label_Droits->setText(QApplication::translate("SmartStockForm", "Droits", 0, QApplication::UnicodeUTF8));
        label_Photo->setText(QApplication::translate("SmartStockForm", "Photos", 0, QApplication::UnicodeUTF8));
        label_Photo_2->setText(QApplication::translate("SmartStockForm", "Photos:", 0, QApplication::UnicodeUTF8));
        label_Nom_2->setText(QApplication::translate("SmartStockForm", "Nom:", 0, QApplication::UnicodeUTF8));
        label_Droits_2->setText(QApplication::translate("SmartStockForm", "Droits:", 0, QApplication::UnicodeUTF8));
        label_Password_2->setText(QApplication::translate("SmartStockForm", "Password:", 0, QApplication::UnicodeUTF8));
        label_Login_2->setText(QApplication::translate("SmartStockForm", "Login:", 0, QApplication::UnicodeUTF8));
        label_Active_2->setText(QApplication::translate("SmartStockForm", "Active:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(MonCompte), QApplication::translate("SmartStockForm", "Mon Compte", 0, QApplication::UnicodeUTF8));
        groupBox_User_Utilisateur->setTitle(QApplication::translate("SmartStockForm", "Utilisateur:", 0, QApplication::UnicodeUTF8));
        label_User_Login->setText(QApplication::translate("SmartStockForm", "Login:", 0, QApplication::UnicodeUTF8));
        label_User_Photo->setText(QApplication::translate("SmartStockForm", "Photo:", 0, QApplication::UnicodeUTF8));
        pushButton_User_Ajouter->setText(QApplication::translate("SmartStockForm", "Ajouter", 0, QApplication::UnicodeUTF8));
        pushButton_User_Enregistrer->setText(QApplication::translate("SmartStockForm", "Enregistrer", 0, QApplication::UnicodeUTF8));
        pushButton_User_Modifier->setText(QApplication::translate("SmartStockForm", "Modifier", 0, QApplication::UnicodeUTF8));
        pushButton_User_Supprimer->setText(QApplication::translate("SmartStockForm", "Supprimer", 0, QApplication::UnicodeUTF8));
        pushButton_User_Desactiver->setText(QApplication::translate("SmartStockForm", "D\303\251sactiver", 0, QApplication::UnicodeUTF8));
        label_User_Password->setText(QApplication::translate("SmartStockForm", "Password:", 0, QApplication::UnicodeUTF8));
        label_User_Nom->setText(QApplication::translate("SmartStockForm", "Nom:", 0, QApplication::UnicodeUTF8));
        label_User_Active->setText(QApplication::translate("SmartStockForm", "Active:", 0, QApplication::UnicodeUTF8));
        label_User_Droits->setText(QApplication::translate("SmartStockForm", "Droits:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Utilisateurs), QApplication::translate("SmartStockForm", "Utilisateurs", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(APropos), QApplication::translate("SmartStockForm", "A Propos", 0, QApplication::UnicodeUTF8));
        pushButton_Fermer->setText(QApplication::translate("SmartStockForm", "Fermer", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SmartStockForm", "D\303\251connexion", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SmartStockForm: public Ui_SmartStockForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTSTOCKFORM_H
