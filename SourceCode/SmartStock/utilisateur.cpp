
#include <library.h>
Utilisateur::Utilisateur()
{
    login    = "";
    password = "";
    nom      = "";
    active   = 0;
    droits   = 0;
    photo    = "";
}

Utilisateur::Utilisateur(QString vlogin,QString vpassword,QString vnom,int vactive,int vdroits,QString vphoto)
{
    login     = vlogin;
    password  = vpassword;
    nom       = vnom;
    active    = vactive;
    droits    = vdroits;
    photo     = vphoto;
}

Utilisateur::~Utilisateur()
{

}

QString Utilisateur::getLogin(){ return login; }

QString Utilisateur::getPassword(){ return password; }

QString Utilisateur::getNom(){ return nom; }

int Utilisateur::getActive(){ return active; }

int Utilisateur::getDroits(){ return droits; }

QString Utilisateur::getPhoto(){ return photo; }


int Utilisateur::existe(QString vlogin,QString vpassword)
{
        ConnexionDatabase *cn=new ConnexionDatabase();
        this->model =  new QSqlQueryModel();
        model->setQuery("SELECT * FROM utilisateur WHERE login='"+vlogin+"' AND password ='"+vpassword+"'");

        QString activeUser = model->record(0).value("active").toString();
        if (activeUser == "1")
        {
           return 1;

        }
        else if (activeUser == "0")
        {
            return 0;
        }
        else
        {
            return -1;
        }
        cn->~ConnexionDatabase();
}

QList<QString> Utilisateur::getUserInfo(QString vlogin)
{
    ConnexionDatabase *cn=new ConnexionDatabase();

    this->model =  new QSqlQueryModel();
    model->setQuery("SELECT * FROM utilisateur WHERE login='"+vlogin+"';");

    QString loginUser  = model->record(0).value("login").toString();
    QString passwordUser  = model->record(0).value("password").toString();
    QString nomUser    = model->record(0).value("nom").toString();
    QString activeUser = model->record(0).value("active").toString();
    QString droitsUser = model->record(0).value("droits").toString();
    QString photoUser  = model->record(0).value("photo").toString();

    QList<QString> list;
     list.append(loginUser);
     list.append(passwordUser);
     list.append(nomUser);
     list.append(activeUser);
     list.append(droitsUser);
     list.append(photoUser);

     return list;

     cn->~ConnexionDatabase();
}










































