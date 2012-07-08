#ifndef SMARTSTOCKFORM_H
#define SMARTSTOCKFORM_H


#include <library.h>

namespace Ui {
class SmartStockForm;
}

class SmartStockForm : public QWidget
{
    Q_OBJECT
public:
    explicit SmartStockForm(QWidget *parent = 0);
    ~SmartStockForm();
    void refreshForm();
    void remplirCategories();
    void showCategorieInfo(QString);
    void showProduitInfo(QString);
    void showProduitInfo_ByList(QString);

    void remplirStock();
    void showHistorique();
    void showUtilisateurs();

    void showUtilisateurInfo_ByNom(QString);
    void showStatistiques();

    bool CopyFile(const QString& sourceFile, const QString& destinationDir);
    
public:
    Ui::SmartStockForm *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_Fermer_clicked();
    void on_listView_Categorie_clicked(const QModelIndex &index);
    void on_pushButton_Cat_Ajouter_clicked();
    void on_pushButton_Cat_Enregistrer_clicked();
    void on_pushButton_Cat_Modifier_clicked();
    void on_pushButton_Cat_Supprimer_clicked();
    void on_comboBox_Prod_Categorie_currentIndexChanged();
    void on_listView_Prod_Produit_clicked(const QModelIndex &index);

    void on_listView_Prod_Produit_activated(const QModelIndex &index);
    void on_listView_Categorie_activated(const QModelIndex &index);
    void on_pushButton_Prod_Ajouter_clicked();
    void on_comboBox_Prod_Categorie_2_currentIndexChanged();
    void on_comboBox_Stock_Categorie_currentIndexChanged();
    void on_listView_Stock__Produit_activated(const QModelIndex &index);
    void on_listView_Stock__Produit_clicked(const QModelIndex &index);
    void on_pushButton_Stock_Entree_clicked();
    void on_pushButton_Stock_Sortie_clicked();
    void on_listView_Utilisateur_activated(const QModelIndex &index);
    void on_listView_Utilisateur_clicked(const QModelIndex &index);
    void on_pushButton_User_Ajouter_clicked();
    void on_pushButton_User_Enregistrer_clicked();
    void on_pushButton_User_Modifier_clicked();
    void on_pushButton_User_Supprimer_clicked();
    void on_pushButton_User_Desactiver_clicked();
    void on_pushButton_Prod_Enregistrer_clicked();
    void on_pushButton_Prod_Modifier_clicked();
    void on_pushButton_Prod_Supprimer_clicked();
    void on_pushButton_Prod_Desactiver_clicked();
    void on_pushButton_Prod_ParcourirPhoto_clicked();
};

#endif // SMARTSTOCKFORM_H














