#include <library.h>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

ConnexionDatabase::ConnexionDatabase()
{
    QString path = QDir::currentPath();

    QSettings settings(path+"/data/config.ini", QSettings::IniFormat);
    QString DatabaseType = settings.value("Database/DatabaseType","config").toString();
    QString DatabaseName = settings.value("Database/DatabaseName","config").toString();
    QString DataBaseHost = settings.value("Database/DataBaseHost","config").toString();
    QString DataBaseUser = settings.value("Database/DataBaseUser","config").toString();
    QString DataBasePassword = settings.value("Database/DataBasePassword","config").toString();
    int DataBasePort = settings.value("Database/DataBasePort","config").toInt();



    if(DatabaseType == "QSQLITE")
    {
       this->db = QSqlDatabase::addDatabase(DatabaseType);
       this->db.setDatabaseName(path+DatabaseName);
       this->db.open();
    }
    else
    {
        this->db = QSqlDatabase::addDatabase(DatabaseType);
        this->db.setHostName(DatabaseName);
        this->db.setDatabaseName(DataBaseHost);
        this->db.setUserName(DataBaseUser);
        this->db.setPassword(DataBasePassword);
        this->db.setPort(DataBasePort);
        this->db.open();
    }



   /*

    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(path+"/data/smart_stock");


    this->db = QSqlDatabase::addDatabase("QMYSQL");
    this->db.setHostName("localhost");
    this->db.setDatabaseName("smart_stock");
    this->db.setUserName("root");
    this->db.setPassword("");
    this->db.setPort(3306);
    this->db.open();
    */


}

ConnexionDatabase::~ConnexionDatabase()
{
    this->db.close();
}
