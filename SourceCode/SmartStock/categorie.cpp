
#include <library.h>


Categorie::Categorie()
{
    ConnexionDatabase *cn=new ConnexionDatabase();
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("categorie");
    model->select();

 //   cn->~ConnexionDatabase();
}


