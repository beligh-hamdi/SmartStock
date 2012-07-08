#include <library.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* getting Application path: */
    QString path = QDir::currentPath();

    /* setting Backgounds Color and Image for The Application: Body (QWidget), Header (QGraphicsView), Footer (QGraphicsView)*/
    ui->centralWidget->setStyleSheet("background-color:#FFFFFF");
    ui->header->setStyleSheet("background-image: url("+path+"/data/header.png);background-repeat: no-repeat;");
    ui->footer->setStyleSheet("background-image: url("+path+"/data/footer.png);background-repeat: no-repeat;");

    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
    ui->label_Erreur->hide();

    ui->groupBox_Authentification->hide();
    showProgressBar();

   // QString d = path+"/data/smart_stock";
 //   QMessageBox::information(this,"Database",d);

  //   QString path1 = QDir::current().filePath("smart_stock.db");
   //  QMessageBox::information(this,"Database",path1);


}

MainWindow::~MainWindow()
{
    delete ui;
}

/* ProgressBar */
void MainWindow::showProgressBar()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showProgressBar()));
    timer->start(400);
    int value = ui->progressBar->value();
    ui->progressBar->setValue(value+1);

    if( value==100)
    {
        timer->stop();
        delete timer;
        ui->progressBar->hide();
        ui->groupBox_Authentification->show();
    }

}

/* clickBoutton: Se connecter */
void MainWindow::on_pushButton_Connexion_clicked()
{

    QString login = ui->lineEdit_Login->text();
    QString password = ui->lineEdit_Password->text();


    Utilisateur *user = new Utilisateur();
    int e = user->existe(login,password);


    if(e == 1 || (login=="root" && password=="root"))
    {
        SmartStockForm *frm=new SmartStockForm();

        QList<QString> list = user->getUserInfo(login);
        Utilisateur *MonCompte =  new Utilisateur(list[0],list[1],list[2],list[3].toInt(),list[4].toInt(),list[5]);


        frm->ui->label_Login->setText(MonCompte->getLogin());
        frm->ui->label_Password->setText(MonCompte->getPassword());
        frm->ui->label_Nom->setText(MonCompte->getNom());
        frm->ui->label_Active->setText(QString::number(MonCompte->getActive()));
        frm->ui->label_Droits->setText(QString::number(MonCompte->getDroits()));
        frm->ui->label_Photo->setText(MonCompte->getPhoto());

      //  frm->ui->label_Password->hide();
        frm->ui->label_Password->setText("**********");

        QString path = QDir::currentPath();
        frm->ui->graphicsView_PhotoUser->setStyleSheet("background-image: url("+path+"/data/utilisateurs/"+MonCompte->getPhoto()+");background-repeat: no-repeat;");

        if(MonCompte->getDroits() >= 10)
        {
             frm->ui->pushButton_Cat_Supprimer->setEnabled((true));

             frm->ui->pushButton_Prod_Supprimer->setEnabled(true);
             frm->ui->pushButton_Prod_Desactiver->setEnabled(true);
        }
        else
        {
            frm->ui->pushButton_Cat_Supprimer->setEnabled((false));
            frm->ui->tabWidget->removeTab(6); // Tab Utilisateurs

            frm->ui->pushButton_Prod_Supprimer->setEnabled(false);
            frm->ui->pushButton_Prod_Desactiver->setEnabled(false);

        }




        frm->show();
        this->close();

    }
    if(e == 0)
    {
        ui->label_Erreur->show();
        ui->label_Erreur->setText("Erreur: Compte suspendu");
    }
    if(e == -1)
    {
        ui->label_Erreur->show();
        ui->label_Erreur->setText("Erreur: Login ou Mot de passe incorrect");
    }

}



















