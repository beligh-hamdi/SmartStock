#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <library.h>

class Utilisateur
{
private:
    QString login;
    QString password;
    QString nom;
    int active;
    int droits;
    QString photo;

    QSqlQueryModel *model;
    QSqlDatabase db;

public:
    Utilisateur();
    Utilisateur(QString,QString,QString,int,int,QString);
    ~Utilisateur();
    QString getLogin();
    QString getPassword();
    QString getNom();
    int getActive();
    int getDroits();
    QString getPhoto();

    int existe(QString vlogin, QString vpassword);
    QList<QString> getUserInfo(QString vlogin);
};

#endif // UTILISATEUR_H
