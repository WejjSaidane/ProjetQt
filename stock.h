#ifndef STOCK_H
#define STOCK_H
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>




class stock
{
   int id_s,quantite;
   QString nom,TYPE_PRODUIT,saison;
   QString DATE_CREATION,DATE_VENTE;

public:
    stock(){}
    stock(int,int,QString,QString,QString,QString);
    ~stock(){};
    int getID(){return id_s;}
    QString getNom(){return nom;}
    QString getType(){return TYPE_PRODUIT;}
    QString getSaison(){return saison;}
    QString getDate_de_creation(){return DATE_CREATION;}
    QString getDate_de_vente(){return DATE_VENTE;}

    void setID(int id_s){this->id_s=id_s;}
    void setNom(QString n){nom=n;}
    void setType(QString t){TYPE_PRODUIT=t;}
    void setSaison(QString s){saison=s;}
    void setDate_de_creation(QString dc){DATE_CREATION=dc;}
    void setDate_de_vente(QString dv){DATE_VENTE=dv;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int id_s,int quantite,QString TYPE_PRODUIT,QString saison,QString DATE_CREATION,QString DATE_VENTE);




};

#endif // STOCK_H
