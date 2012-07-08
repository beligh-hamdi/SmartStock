#ifndef CONNEXIONDATABASE_H
#define CONNEXIONDATABASE_H

#include<library.h>

class ConnexionDatabase
{
    QSqlDatabase db;
public:
    ConnexionDatabase();
    ~ConnexionDatabase();
};

#endif // CONNEXIONDATABASE_H
