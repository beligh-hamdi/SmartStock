
#include <library.h>

SmartStockForm::SmartStockForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmartStockForm)
{
    ui->setupUi(this);

    refreshForm();

}

SmartStockForm::~SmartStockForm()
{
    delete ui;
}

void SmartStockForm::refreshForm()
{
    /* getting Application path: */
    QString path = QDir::currentPath();

    /* setting Backgounds Color and Image for The Application: Body (QWidget), Header (QGraphicsView), Footer (QGraphicsView)*/
    this->setStyleSheet("background-color:#FFFFFF");
    ui->header->setStyleSheet("background-image: url("+path+"/data/header.png);background-repeat: no-repeat;");
    ui->footer->setStyleSheet("background-image: url("+path+"/data/footer.png);background-repeat: no-repeat;");

    remplirStock();

    remplirCategories();

    showHistorique();

    showUtilisateurs();

    /* Tab Categorie */
    ui->pushButton_Cat_Ajouter->setEnabled((true));
    ui->pushButton_Cat_Enregistrer->setEnabled(false);
    ui->pushButton_Cat_Modifier->setEnabled(true);
    //  ui->pushButton_Cat_Supprimer->setEnabled((true));


    /* Tab Produit */
    ui->pushButton_Prod_Ajouter->setEnabled(true);
    ui->pushButton_Prod_Enregistrer->setEnabled(false);
    ui->pushButton_Prod_Modifier->setEnabled(true);
    //  ui->pushButton_Prod_Desactiver->setEnabled(true);
    //   ui->pushButton_Prod_Supprimer->setEnabled(false);
    ui->lineEdit_Prod_Produit->setReadOnly(true);
    ui->lineEdit_Prod_Categorie->setReadOnly(true);

  //  ui->lineEdit_Prod_Categorie->show();
  //  ui->comboBox_Prod_Categorie_2->hide();

    ui->comboBox_Prod_Categorie_2->setLineEdit(ui->lineEdit_Prod_Categorie);
    ui->lineEdit_Prod_Prix->setValidator(new QIntValidator(0,999999, this));
    ui->lineEdit_Prod_Active->setValidator(new QIntValidator(0,1, this));

    ui->lineEdit_Prod_Produit->setStyleSheet("");
    ui->lineEdit_Prod_Active->setStyleSheet("");


    /* Tab Stock */

    ui->label_Stock_MessageErreur->hide();
    QString quantiteActuel =  ui->lineEdit_Stock_QuantiteActuel->text();
    QString produit =  ui->lineEdit_Stock_Produit->text();
    ui->lineEdit_Stock_Quantite->setText("");
    ui->lineEdit_Stock_Quantite->setValidator(new QIntValidator(0, 999999, this));

    if(quantiteActuel=="" || quantiteActuel=="0")
    {
        ui->pushButton_Stock_Sortie->setEnabled((false));
    }
    else
    {
        ui->pushButton_Stock_Sortie->setEnabled((true));
    }

    if(produit=="")
    {
       ui->pushButton_Stock_Entree->setEnabled((false));
    }
    else
    {
      ui->pushButton_Stock_Entree->setEnabled((true));
    }

    /* Tab utilisateur */
    ui->pushButton_User_Ajouter->setEnabled(true);
    ui->pushButton_User_Enregistrer->setEnabled(false);
    ui->pushButton_User_Modifier->setEnabled(true);
    ui->pushButton_User_Supprimer->setEnabled(true);
    ui->pushButton_User_Desactiver->setEnabled(true);

    ui->lineEdit_User_Login->setReadOnly(true);


    /* Tab Statistiques */
    showStatistiques();

}



/* Begin: Tab Statistiques */
void SmartStockForm::showStatistiques()
{

 //  QString dateCourante = QDate::currentDate().toString("dd/MM/yyyy");
   QString thisYear = QDate::currentDate().toString("yyyy");
   QString thisMonth = QDate::currentDate().toString("MM");
 //  QMessageBox::information(this,"Database",thisMonth);


    ConnexionDatabase *cn=new ConnexionDatabase();

    QSqlQueryModel *model =  new QSqlQueryModel();
    model->setQuery("SELECT produit,SUM(quantite) as quantite FROM historique WHERE flux='OUT' AND date_histo LIKE '%/"+thisMonth+"/%' GROUP BY produit ORDER BY SUM(quantite) DESC");
    ui->tableView_Stat_BM->setModel(model);

    QSqlQueryModel *model1 =  new QSqlQueryModel();
    model1->setQuery("SELECT produit,SUM(quantite) as quantite FROM historique WHERE flux='OUT' AND date_histo LIKE '%/"+thisYear+"' GROUP BY produit ORDER BY SUM(quantite) DESC");
    ui->tableView_Stat_BY->setModel(model1);

    QSqlQueryModel *model2 =  new QSqlQueryModel();
    model2->setQuery("SELECT produit,SUM(quantite) as quantite FROM stock GROUP BY produit ORDER BY SUM(quantite) DESC");
    ui->tableView_Stat_WM->setModel(model2);



    cn->~ConnexionDatabase();
}

/* End tab Statistiques */



/* Begin: Tab Categorie   */

void SmartStockForm::remplirCategories()
{
    ConnexionDatabase *cn=new ConnexionDatabase();

    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("categorie");
    model->select();

    ui->listView_Categorie->setModel(model);
    ui->comboBox_Prod_Categorie->setModel(model);
    ui->comboBox_Prod_Categorie_2->setModel(model);
    ui->comboBox_Stock_Categorie->setModel(model);

    QModelIndex index = model->index(0, 0);
    ui->listView_Categorie->selectionModel()->select(index, QItemSelectionModel::Select);

    QString value = index.data().toString();
    showCategorieInfo(value);
    //QMessageBox::information(this,"Suppression",value);


    cn->~ConnexionDatabase();
}

void SmartStockForm::on_pushButton_Cat_Ajouter_clicked()
{
    ui->pushButton_Cat_Enregistrer->setEnabled(true);
    ui->pushButton_Cat_Modifier->setEnabled(false);
    ui->pushButton_Cat_Ajouter->setEnabled(false);
    ui->pushButton_Cat_Supprimer->setEnabled(false);

    ui->lineEdit_Cat_Categorie->setText("");
    ui->plainTextEdit_Cat_Description->setPlainText("");
    ui->lineEdit_Cat_Photo->setText("");
    ui->graphicsView_Cat_Photo->setStyleSheet("");

    ui->lineEdit_Cat_Categorie->setReadOnly(false);
}

void SmartStockForm::on_pushButton_Cat_Enregistrer_clicked()
{

    QString categorie = ui->lineEdit_Cat_Categorie->text();
    QString description =ui->plainTextEdit_Cat_Description->toPlainText();
    QString photo =ui->lineEdit_Cat_Photo->text();

    QMessageBox msgBox;
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
         ConnexionDatabase *cn=new ConnexionDatabase();
         QSqlQueryModel *model =  new QSqlQueryModel();
         model->setQuery("INSERT INTO categorie (categorie,description,photo) VALUES ('"+categorie+"','"+description+"','"+photo+"');");
         cn->~ConnexionDatabase();
    }
    if(ret == QMessageBox::Cancel )
    {

    }

    refreshForm();
}

void SmartStockForm::on_pushButton_Cat_Modifier_clicked()
{
    QString categorie = ui->lineEdit_Cat_Categorie->text();
    QString description =ui->plainTextEdit_Cat_Description->toPlainText();
    QString photo =ui->lineEdit_Cat_Photo->text();


    QMessageBox msgBox;
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
         ConnexionDatabase *cn=new ConnexionDatabase();
         QSqlQueryModel *model =  new QSqlQueryModel();
         model->setQuery("UPDATE categorie SET description='"+description+"',photo='"+photo+"' WHERE categorie='"+categorie+"';");
         cn->~ConnexionDatabase();
    }
    if(ret == QMessageBox::Cancel )
    {

    }

    refreshForm();
}

void SmartStockForm::on_pushButton_Cat_Supprimer_clicked()
{
    QString categorie = ui->lineEdit_Cat_Categorie->text();

    QMessageBox msgBox;
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
         ConnexionDatabase *cn=new ConnexionDatabase();
         QSqlQueryModel *model =  new QSqlQueryModel();
         model->setQuery("DELETE FROM categorie WHERE categorie='"+categorie+"';");
         cn->~ConnexionDatabase();
    }
    if(ret == QMessageBox::Cancel )
    {

    }

    refreshForm();
}

void SmartStockForm::on_listView_Categorie_clicked(const QModelIndex &index)
{
    QString value = index.data().toString();
    showCategorieInfo(value);
}

void SmartStockForm::on_listView_Categorie_activated(const QModelIndex &index)
{
    QString value = index.data().toString();
    showCategorieInfo(value);
}

void SmartStockForm::showCategorieInfo(QString vcategorie)
{
    ConnexionDatabase *cn=new ConnexionDatabase();

    QSqlQueryModel *model =  new QSqlQueryModel();
    model->setQuery("SELECT * FROM categorie where categorie='"+vcategorie+"'");

    QString path = QDir::currentPath();

    QString categorie   = model->record(0).value("categorie").toString();
    QString description = model->record(0).value("description").toString();
    QString photo      = model->record(0).value("photo").toString();


    ui->lineEdit_Cat_Categorie->setText(categorie);
    ui->plainTextEdit_Cat_Description->setPlainText(description);
    ui->lineEdit_Cat_Photo->setText(photo);
    ui->graphicsView_Cat_Photo->setStyleSheet("background-image: url("+path+"/data/categories/"+photo+");background-repeat: no-repeat;");

    cn->~ConnexionDatabase();
}

/* End: Tab Categorie   */

/* Begin: Deconnexion, Fermer   */

void SmartStockForm::on_pushButton_clicked()
{
    MainWindow *frm=new MainWindow();
    frm->show();
    this->close();
}

void SmartStockForm::on_pushButton_Fermer_clicked()
{
    this->close();
}

/* End: Deconnexion, Fermer   */

/* Begin: Tab Produit   */

void SmartStockForm::on_comboBox_Prod_Categorie_currentIndexChanged()
{
   QString value = ui->comboBox_Prod_Categorie->currentText();
   ui->lineEdit_Prod_Prix->setValidator(new QIntValidator(0,999999, this));
   ui->lineEdit_Prod_Active->setValidator(new QIntValidator(0,1, this));
   showProduitInfo_ByList(value);
}

void SmartStockForm::on_listView_Prod_Produit_clicked(const QModelIndex &index)
{
    QString value = index.data().toString();
    ui->lineEdit_Prod_Prix->setValidator(new QIntValidator(0,999999, this));
    ui->lineEdit_Prod_Active->setValidator(new QIntValidator(0,1, this));
    showProduitInfo(value);
}

void SmartStockForm::on_listView_Prod_Produit_activated(const QModelIndex &index)
{
    QString value = index.data().toString();
    ui->lineEdit_Prod_Prix->setValidator(new QIntValidator(0,999999, this));
    ui->lineEdit_Prod_Active->setValidator(new QIntValidator(0,1, this));
    showProduitInfo(value);
}

void SmartStockForm::on_comboBox_Prod_Categorie_2_currentIndexChanged()
{
    QString value = ui->comboBox_Prod_Categorie_2->currentText();
    ui->lineEdit_Prod_Categorie->setText(value);
    ui->lineEdit_Prod_Prix->setValidator(new QIntValidator(0,999999, this));
    ui->lineEdit_Prod_Active->setValidator(new QIntValidator(0,1, this));
}

void SmartStockForm::on_pushButton_Prod_Ajouter_clicked()
{

    ui->pushButton_Prod_Ajouter->setEnabled(false);
    ui->pushButton_Prod_Enregistrer->setEnabled(true);
    ui->pushButton_Prod_Modifier->setEnabled(false);
    ui->pushButton_Prod_Supprimer->setEnabled(false);
    ui->pushButton_Prod_Desactiver->setEnabled(false);

    ui->lineEdit_Prod_Produit->setText("");
    ui->plainTextEdit_Prod_Description->setPlainText("");
    ui->lineEdit_Prod_Prix->setText("");
    ui->lineEdit_Prod_Active->setText("");
  //  ui->lineEdit_Prod_Categorie->setText("");
    ui->lineEdit_Prod_Photo->setText("");
    ui->graphicsView_Prod_Photo->setStyleSheet("");

    ui->lineEdit_Prod_Produit->setReadOnly(false);
    ui->lineEdit_Prod_Categorie->setReadOnly(true);


  //  ui->lineEdit_Prod_Categorie->hide();
 //   ui->comboBox_Prod_Categorie_2->show();

    ui->lineEdit_Prod_Prix->setValidator(new QIntValidator(0,999999, this));
    ui->lineEdit_Prod_Active->setValidator(new QIntValidator(0,1, this));
}

void SmartStockForm::on_pushButton_Prod_Enregistrer_clicked()
{

    QString produit = ui->lineEdit_Prod_Produit->text();
    QString description =  ui->plainTextEdit_Prod_Description->toPlainText();
  //  QString categorie = ui->lineEdit_Prod_Categorie->text();
    QString categorie = ui->comboBox_Prod_Categorie_2->currentText();
    int prix = ui->lineEdit_Prod_Prix->text().toInt();;
    QString photo =  ui->lineEdit_Prod_Photo->text();
    int active = ui->lineEdit_Prod_Active->text().toInt();

    if(produit=="")
    {
       ui->lineEdit_Prod_Produit->setStyleSheet("background-color:red;");

    }
    else if(ui->lineEdit_Prod_Active->text()=="")
    {
       ui->lineEdit_Prod_Active->setStyleSheet("background-color:red;");
    }
    else
    {

        QMessageBox msgBox;
        msgBox.setText("Produit:");
        msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Save )
        {
             ConnexionDatabase *cn=new ConnexionDatabase();
             QSqlQueryModel *model =  new QSqlQueryModel();
             model->setQuery("INSERT INTO produits (produit,description,prix,categorie,photo,active) VALUES ('"+produit+"','"+description+"',"+QString::number(prix)+",'"+categorie+"','"+photo+"',"+QString::number(active)+");");
             cn->~ConnexionDatabase();
        }
        if(ret == QMessageBox::Cancel )
        {

        }
    }

    refreshForm();
}

void SmartStockForm::on_pushButton_Prod_Modifier_clicked()
{
    QString produit = ui->lineEdit_Prod_Produit->text();
    QString description =  ui->plainTextEdit_Prod_Description->toPlainText();
  //  QString categorie = ui->lineEdit_Prod_Categorie->text();
    QString categorie = ui->comboBox_Prod_Categorie_2->currentText();
    int prix = ui->lineEdit_Prod_Prix->text().toInt();;
    QString photo =  ui->lineEdit_Prod_Photo->text();
    int active = ui->lineEdit_Prod_Active->text().toInt();


    QMessageBox msgBox;
    msgBox.setText("Produit:");
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
         ConnexionDatabase *cn=new ConnexionDatabase();
         QSqlQueryModel *model =  new QSqlQueryModel();
         model->setQuery("UPDATE produits SET description='"+description+"',prix="+QString::number(prix)+",categorie='"+categorie+"',photo='"+photo+"',active="+QString::number(active)+" WHERE produit='"+produit+"';");
         cn->~ConnexionDatabase();
    }
    if(ret == QMessageBox::Cancel )
    {

    }

    refreshForm();

}

void SmartStockForm::on_pushButton_Prod_Supprimer_clicked()
{
    QString produit = ui->lineEdit_Prod_Produit->text();

    QMessageBox msgBox;
    msgBox.setText("Produit:");
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
         ConnexionDatabase *cn=new ConnexionDatabase();
         QSqlQueryModel *model =  new QSqlQueryModel();
         model->setQuery("DELETE FROM produits WHERE produit='"+produit+"';");
         cn->~ConnexionDatabase();
    }
    if(ret == QMessageBox::Cancel )
    {

    }

    refreshForm();


}

void SmartStockForm::on_pushButton_Prod_Desactiver_clicked()
{
    QString produit = ui->lineEdit_Prod_Produit->text();

    QMessageBox msgBox;
    msgBox.setText("Produit:");
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
         ConnexionDatabase *cn=new ConnexionDatabase();
         QSqlQueryModel *model =  new QSqlQueryModel();
         model->setQuery("UPDATE produits SET active=0 WHERE produit='"+produit+"';");
         cn->~ConnexionDatabase();
    }
    if(ret == QMessageBox::Cancel )
    {

    }

    refreshForm();

}





void SmartStockForm::showProduitInfo(QString vproduit)
{
    ConnexionDatabase *cn=new ConnexionDatabase();

    QSqlQueryModel *model =  new QSqlQueryModel();
    model->setQuery("SELECT * FROM produits where produit='"+vproduit+"'");

    QString path = QDir::currentPath();

    QString produit   = model->record(0).value("produit").toString();
    QString description = model->record(0).value("description").toString();
    QString prix   = model->record(0).value("prix").toString();
    QString categorie   = model->record(0).value("categorie").toString();
    QString photo   = model->record(0).value("photo").toString();
    QString active      = model->record(0).value("active").toString();


    // tab Produit
    ui->lineEdit_Prod_Produit->setText(produit);
    ui->plainTextEdit_Prod_Description->setPlainText(description);
    ui->lineEdit_Prod_Prix->setText(prix);
    ui->lineEdit_Prod_Categorie->setText(categorie);
    ui->lineEdit_Prod_Photo->setText(photo);
    ui->lineEdit_Prod_Active->setText(active);
    ui->graphicsView_Prod_Photo->setStyleSheet("background-image: url("+path+"/data/produits/"+photo+");background-repeat: no-repeat;");


   // tab Stock
    ui->lineEdit_Stock_Produit->setText(produit);
    ui->lineEdit_Stock_Prix->setText(prix);
    ui->lineEdit_Stock_Categorie->setText(categorie);

    QGraphicsScene *scn = new QGraphicsScene( ui->graphicsView_Stock_Photo );
    ui->graphicsView_Stock_Photo->setScene( scn );
    QPixmap pix(path+"/data/produits/"+photo);
    scn->addPixmap( pix );
    ui->graphicsView_Stock_Photo->fitInView(scn->itemsBoundingRect() ,Qt::KeepAspectRatio);

    /* Tab Stock */
    model->setQuery("SELECT * FROM stock where produit='"+vproduit+"'");
    QString quantiteActuel = model->record(0).value("quantite").toString();
    ui->lineEdit_Stock_QuantiteActuel->setText(quantiteActuel);

    cn->~ConnexionDatabase();
}

void SmartStockForm::showProduitInfo_ByList(QString vcategorie)
{
    ConnexionDatabase *cn=new ConnexionDatabase();

    QSqlQueryModel *model =  new QSqlQueryModel();
    model->setQuery("SELECT * FROM produits where categorie='"+vcategorie+"'");

    ui->listView_Prod_Produit->setModel(model);
    ui->listView_Stock__Produit->setModel(model);

    QModelIndex index = model->index(0, 0);
    ui->listView_Prod_Produit->selectionModel()->select(index, QItemSelectionModel::Select);

    QString value = index.data().toString();
    showProduitInfo(value);


    cn->~ConnexionDatabase();
}

/* End: Tab Produit */



/* Begin: Tab Stock */
void SmartStockForm::remplirStock()
{
    ConnexionDatabase *cn=new ConnexionDatabase();

    QSqlQueryModel *model =  new QSqlQueryModel();
    model->setQuery("SELECT * FROM stock where quantite>0");

    ui->tableView_Stock->setModel(model);

    cn->~ConnexionDatabase();
}

void SmartStockForm::on_comboBox_Stock_Categorie_currentIndexChanged()
{
    QString value = ui->comboBox_Stock_Categorie->currentText();
    showProduitInfo_ByList(value);

    QString quantiteActuel =  ui->lineEdit_Stock_QuantiteActuel->text();
    QString produit =  ui->lineEdit_Stock_Produit->text();
    ui->lineEdit_Stock_Quantite->setText("");
    ui->lineEdit_Stock_Quantite->setValidator(new QIntValidator(0, 999999, this));

    if(quantiteActuel=="" || quantiteActuel=="0")
    {
        ui->pushButton_Stock_Sortie->setEnabled((false));
    }
    else
    {
        ui->pushButton_Stock_Sortie->setEnabled((true));
    }

    if(produit=="")
    {
       ui->pushButton_Stock_Entree->setEnabled((false));
    }
    else
    {
      ui->pushButton_Stock_Entree->setEnabled((true));
    }


}

void SmartStockForm::on_listView_Stock__Produit_activated(const QModelIndex &index)
{
    QString value = index.data().toString();
    showProduitInfo(value);

    QString quantiteActuel =  ui->lineEdit_Stock_QuantiteActuel->text();
    QString produit =  ui->lineEdit_Stock_Produit->text();
    ui->lineEdit_Stock_Quantite->setText("");
    ui->lineEdit_Stock_Quantite->setValidator(new QIntValidator(0, 999999, this));

    if(quantiteActuel=="" || quantiteActuel=="0")
    {
        ui->pushButton_Stock_Sortie->setEnabled((false));
    }
    else
    {
        ui->pushButton_Stock_Sortie->setEnabled((true));
    }

    if(produit=="")
    {
       ui->pushButton_Stock_Entree->setEnabled((false));
    }
    else
    {
      ui->pushButton_Stock_Entree->setEnabled((true));
    }
}

void SmartStockForm::on_listView_Stock__Produit_clicked(const QModelIndex &index)
{
    QString value = index.data().toString();
    showProduitInfo(value);

    QString quantiteActuel =  ui->lineEdit_Stock_QuantiteActuel->text();
    QString produit =  ui->lineEdit_Stock_Produit->text();
    ui->lineEdit_Stock_Quantite->setText("");
    ui->lineEdit_Stock_Quantite->setValidator(new QIntValidator(0, 999999, this));

    if(quantiteActuel=="" || quantiteActuel=="0")
    {
        ui->pushButton_Stock_Sortie->setEnabled((false));
    }
    else
    {
        ui->pushButton_Stock_Sortie->setEnabled((true));
    }

    if(produit=="")
    {
       ui->pushButton_Stock_Entree->setEnabled((false));
    }
    else
    {
      ui->pushButton_Stock_Entree->setEnabled((true));
    }
}

void SmartStockForm::on_pushButton_Stock_Entree_clicked()
{

    QString produit  = ui->lineEdit_Stock_Produit->text();
    QString quantite = ui->lineEdit_Stock_Quantite->text();
    QString quantiteActuel = ui->lineEdit_Stock_QuantiteActuel->text();
    QString flux = "IN";
    QString today = QDate::currentDate().toString("dd/MM/yyyy");

    int quantiteFinal = quantite.toInt()+quantiteActuel.toInt();

    QMessageBox msgBox;
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
        ConnexionDatabase *cn=new ConnexionDatabase();
        QSqlQueryModel *model =  new QSqlQueryModel();
        if(quantite != "")
        {
            if(quantiteActuel =="")
            {
                model->setQuery("INSERT INTO stock(produit,quantite) VALUES('"+produit+"',"+quantite+");");
                model->setQuery("INSERT INTO historique(produit,quantite,date_histo,flux)VALUES('"+
                                            produit+"',"+quantite+",'"+today+"','"+flux+"');");
                refreshForm();
            }
            else
            {
                model->setQuery("UPDATE stock SET quantite="+QString::number(quantiteFinal)+" WHERE produit='"+produit+"';");
                model->setQuery("INSERT INTO historique(produit,quantite,date_histo,flux)VALUES('"+
                                            produit+"',"+quantite+",'"+today+"','"+flux+"');");
                refreshForm();
            }

        }
        else
        {
            ui->label_Stock_MessageErreur->show();
            ui->label_Stock_MessageErreur->setText("La quantité saisie est nulle");
            ui->label_Stock_MessageErreur->setStyleSheet("color:#FF0000;");
        }


        cn->~ConnexionDatabase();

    }
    if(ret == QMessageBox::Cancel )
    {

    }

}

void SmartStockForm::on_pushButton_Stock_Sortie_clicked()
{
    QString produit  = ui->lineEdit_Stock_Produit->text();
    QString quantite = ui->lineEdit_Stock_Quantite->text();
    QString quantiteActuel = ui->lineEdit_Stock_QuantiteActuel->text();
    QString flux = "OUT";
    QString today = QDate::currentDate().toString("dd/MM/yyyy");

    int quantiteFinal = quantiteActuel.toInt()- quantite.toInt();

    QMessageBox msgBox;
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
        ConnexionDatabase *cn=new ConnexionDatabase();
        QSqlQueryModel *model =  new QSqlQueryModel();
        if(quantiteActuel =="")
        {
           // Stock Vide
            ui->label_Stock_MessageErreur->show();
            ui->label_Stock_MessageErreur->setText("Le Stock est Vide");
            ui->label_Stock_MessageErreur->setStyleSheet("color:#FF0000;");
            refreshForm();
        }
        else
        {
            if(quantiteFinal >0)
            {
                model->setQuery("UPDATE stock SET quantite="+QString::number(quantiteFinal)+" WHERE produit='"+produit+"';");
                model->setQuery("INSERT INTO historique(produit,quantite,date_histo,flux)VALUES('"+
                                            produit+"',"+quantite+",'"+today+"','"+flux+"');");
                refreshForm();
            }
            else if(quantiteFinal ==0)
            {
                model->setQuery("DELETE FROM stock WHERE produit='"+produit+"';");
                model->setQuery("INSERT INTO historique(produit,quantite,date_histo,flux)VALUES('"+
                                            produit+"',"+quantite+",'"+today+"','"+flux+"');");
                refreshForm();
            }
            else
            {
                ui->label_Stock_MessageErreur->show();
                ui->label_Stock_MessageErreur->setText("La quantié saisie n'est pas disponible");
                ui->label_Stock_MessageErreur->setStyleSheet("color:#FF0000;");
                // Quantite Sup
            }
        }
        cn->~ConnexionDatabase();

    }
    if(ret == QMessageBox::Cancel )
    {

    }

}
/* End: Tab Stock */


/* Begin: Tab Historique */
void SmartStockForm::showHistorique()
{
    ConnexionDatabase *cn=new ConnexionDatabase();

    QSqlQueryModel *model =  new QSqlQueryModel();
    model->setQuery("SELECT produit,quantite,date_histo FROM historique where flux='IN' ORDER BY date_histo ASC");
    ui->tableView_Historique_IN->setModel(model);

    QSqlQueryModel *model1 =  new QSqlQueryModel();
    model1->setQuery("SELECT produit,quantite,date_histo FROM historique where flux='OUT' ORDER BY date_histo ASC");
    ui->tableView_Historique_OUT->setModel(model1);

    cn->~ConnexionDatabase();
}


/* End: Tab Historique */


/* Begin: Tab Utilisateurs */
void SmartStockForm::showUtilisateurs()
{
    ConnexionDatabase *cn=new ConnexionDatabase();

    QSqlQueryModel *model =  new QSqlQueryModel();
    model->setQuery("SELECT nom FROM utilisateur ORDER BY nom ASC");
    ui->listView_Utilisateur->setModel(model);

    QModelIndex index = model->index(0, 0);
    ui->listView_Utilisateur->selectionModel()->select(index, QItemSelectionModel::Select);

    QSqlQueryModel *model1 =  new QSqlQueryModel();
    model1->setQuery("SELECT * FROM utilisateur ORDER BY nom ASC");

    QString path = QDir::currentPath();

    QString login   = model1->record(0).value("login").toString();
    QString password = model1->record(0).value("password").toString();
    QString nom   = model1->record(0).value("nom").toString();
    QString active   = model1->record(0).value("active").toString();
    QString droits   = model1->record(0).value("droits").toString();
    QString photo      = model1->record(0).value("photo").toString();

    ui->lineEdit_User_Password->setEchoMode(QLineEdit::Password);

    ui->lineEdit_User_Login->setText(login);
    ui->lineEdit_User_Password->setText(password);
    ui->lineEdit_User_Nom->setText(nom);
    ui->lineEdit_User_Active->setText(active);
    ui->lineEdit_User_Droits->setText(droits);
    ui->lineEdit_User_Photo->setText(photo);
    ui->graphicsView_User_Photo->setStyleSheet("background-image: url("+path+"/data/utilisateurs/"+photo+");background-repeat: no-repeat;");

    cn->~ConnexionDatabase();
}

void SmartStockForm::showUtilisateurInfo_ByNom(QString vnom)
{
    ConnexionDatabase *cn=new ConnexionDatabase();

    QSqlQueryModel *model =  new QSqlQueryModel();
    model->setQuery("SELECT * FROM utilisateur where nom='"+vnom+"'");


    QString path = QDir::currentPath();

    QString login   = model->record(0).value("login").toString();
    QString password = model->record(0).value("password").toString();
    QString nom   = model->record(0).value("nom").toString();
    QString active   = model->record(0).value("active").toString();
    QString droits   = model->record(0).value("droits").toString();
    QString photo      = model->record(0).value("photo").toString();

    ui->lineEdit_User_Password->setEchoMode(QLineEdit::Password);

    ui->lineEdit_User_Login->setText(login);
    ui->lineEdit_User_Password->setText(password);
    ui->lineEdit_User_Nom->setText(nom);
    ui->lineEdit_User_Active->setText(active);
    ui->lineEdit_User_Droits->setText(droits);
    ui->lineEdit_User_Photo->setText(photo);
    ui->graphicsView_User_Photo->setStyleSheet("background-image: url("+path+"/data/utilisateurs/"+photo+");background-repeat: no-repeat;");

    cn->~ConnexionDatabase();
}



void SmartStockForm::on_listView_Utilisateur_activated(const QModelIndex &index)
{
    QString value = index.data().toString();
    showUtilisateurInfo_ByNom(value);
}

void SmartStockForm::on_listView_Utilisateur_clicked(const QModelIndex &index)
{
    QString value = index.data().toString();
    showUtilisateurInfo_ByNom(value);
}

void SmartStockForm::on_pushButton_User_Ajouter_clicked()
{
   ui->pushButton_User_Ajouter->setEnabled(false);
   ui->pushButton_User_Enregistrer->setEnabled(true);
   ui->pushButton_User_Modifier->setEnabled(false);
   ui->pushButton_User_Supprimer->setEnabled(false);
   ui->pushButton_User_Desactiver->setEnabled(false);

   ui->lineEdit_User_Password->setEchoMode(QLineEdit::Password);

   ui->lineEdit_User_Active->setValidator(new QIntValidator(0, 1, this));
   ui->lineEdit_User_Droits->setValidator(new QIntValidator(0, 100, this));

   ui->lineEdit_User_Login->setReadOnly(false);

   ui->lineEdit_User_Login->setText("");
   ui->lineEdit_User_Password->setText("");
   ui->lineEdit_User_Nom->setText("");
   ui->lineEdit_User_Active->setText("");
   ui->lineEdit_User_Droits->setText("");
   ui->lineEdit_User_Photo->setText("");
   ui->graphicsView_User_Photo->setStyleSheet("");

}

void SmartStockForm::on_pushButton_User_Enregistrer_clicked()
{
    QString login    = ui->lineEdit_User_Login->text();
    QString password = ui->lineEdit_User_Password->text();
    QString nom      = ui->lineEdit_User_Nom->text();
    int active   = ui->lineEdit_User_Active->text().toInt();
    int droits   = ui->lineEdit_User_Droits->text().toInt();;
    QString photo    = ui->lineEdit_User_Photo->text();


    QMessageBox msgBox;
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {

        if(login=="" || password=="")
        {

        }
        else
        {
         ConnexionDatabase *cn=new ConnexionDatabase();
         QSqlQueryModel *model =  new QSqlQueryModel();
         model->setQuery("INSERT INTO utilisateur(login,password,nom,active,droits,photo) VALUES ('"+login+"','"+password+"','"+nom+"',"+QString::number(active)+","+QString::number(droits)+",'"+photo+"');");
         cn->~ConnexionDatabase();
        }
    }
    if(ret == QMessageBox::Cancel )
    {

    }

    refreshForm();


}

void SmartStockForm::on_pushButton_User_Modifier_clicked()
{

    QString login    = ui->lineEdit_User_Login->text();
    QString password = ui->lineEdit_User_Password->text();
    QString nom      = ui->lineEdit_User_Nom->text();
    int active   = ui->lineEdit_User_Active->text().toInt();
    int droits   = ui->lineEdit_User_Droits->text().toInt();
    QString photo    = ui->lineEdit_User_Photo->text();


    QMessageBox msgBox;
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
         ConnexionDatabase *cn=new ConnexionDatabase();
         QSqlQueryModel *model =  new QSqlQueryModel();
         model->setQuery("UPDATE utilisateur SET nom='"+nom+"',password='"+password+"',active="+QString::number(active)+",droits="+QString::number(droits)+",photo='"+photo+"' WHERE login='"+login+"';");
         cn->~ConnexionDatabase();
    }
    if(ret == QMessageBox::Cancel )
    {

    }

    refreshForm();
}

void SmartStockForm::on_pushButton_User_Supprimer_clicked()
{
    QString vlogin = ui->lineEdit_User_Login->text();

    QMessageBox msgBox;
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
         ConnexionDatabase *cn=new ConnexionDatabase();
         QSqlQueryModel *model =  new QSqlQueryModel();
         model->setQuery("DELETE FROM utilisateur WHERE login='"+vlogin+"';");
         cn->~ConnexionDatabase();
    }
    if(ret == QMessageBox::Cancel )
    {

    }

    refreshForm();
}

void SmartStockForm::on_pushButton_User_Desactiver_clicked()
{
    QString vlogin = ui->lineEdit_User_Login->text();

    QMessageBox msgBox;
    msgBox.setInformativeText("Vous voulez enrgistrer ces modifications ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save )
    {
         ConnexionDatabase *cn=new ConnexionDatabase();
         QSqlQueryModel *model =  new QSqlQueryModel();
         model->setQuery("UPDATE utilisateur SET active=0 WHERE login='"+vlogin+"';");
         cn->~ConnexionDatabase();
    }
    if(ret == QMessageBox::Cancel )
    {

    }

    refreshForm();
}


/* End: Tab Utilisateurs */



bool CopyFile(const QString& sourceFile, const QString& destinationDir)
{
    QFileInfo fileInfo(sourceFile);
    QString destinationFile = destinationDir + "/" + fileInfo.fileName();
    bool result = QFile::copy(sourceFile, destinationFile);
    return result;
}



void SmartStockForm::on_pushButton_Prod_ParcourirPhoto_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.jpg *.gif *.);; Tous les fichiers (*.*)"));
  //  dialog.setViewMode(QFileDialog::List);
  //  dialog.setAcceptMode(QFileDialog::AcceptSave);
  //  dialog.setLabelText(QFileDialog::LookIn, "Regardez dans :");
  //  dialog.setLabelText(QFileDialog::FileName, "Nom de fichier :");
  //  dialog.setLabelText(QFileDialog::FileType, "Type de fichiers :");
 //   dialog.setLabelText(QFileDialog::Accept, "Ouvrir");
  //  dialog.setLabelText(QFileDialog::Reject, "Annuler");

    if(dialog.exec())
    {
        QString myOpenFile = dialog.getOpenFileName();
        if(myOpenFile.isEmpty())
        {
           // false;
        }
        else
        {
            // true
          QFileInfo fileInfo(myOpenFile);
          QDir dir = fileInfo.dir(); // Dossier du fichier
          QString dirPath = fileInfo.filePath(); // Path vers le fichier
          QString fileName = fileInfo.fileName(); // Nom du fichier (sans le path)
          ui->lineEdit_Prod_Photo->setText(fileName);
        }

    }
    else
        dialog.reject();


}









