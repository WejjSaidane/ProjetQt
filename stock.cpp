#include "stock.h"
stock::stock(int id,int Q,QString type,QString saison,QString dv,QString dc){
    this->id_s=id;
    this->TYPE_PRODUIT=type;
    this->saison=saison;
    this->quantite=Q;
    this->DATE_CREATION=dv;
    this->DATE_VENTE=dc;
}
bool stock::ajouter(){
    QSqlQuery query;
    QString res = QString::number(id_s);

    query.prepare("insert into STOCK (id_s, quantite,TYPE_PRODUIT,saison, DATE_CREATION, DATE_VENTE)" "values (:id_s, :quantite,:TYPE_PRODUIT, :saison, :DATE_CREATION, :DATE_VENTE)");
    query.bindValue(":id_s",res);
    query.bindValue(":quantite",quantite);
    query.bindValue(":TYPE_PRODUIT",TYPE_PRODUIT);
    query.bindValue(":saison",saison);
    query.bindValue(":DATE_CREATION",DATE_CREATION);
    query.bindValue(":DATE_VENTE",DATE_VENTE);


    return query.exec();
}
QSqlQueryModel * stock::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from STOCK");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("id_s"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TYPE_PRODUIT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("saison"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_CREATION"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("DATE_VENTE"));
    return model;
}
bool stock::supprimer(int id_s){
    QSqlQuery query;
    QString res=QString::number(id_s);
    query.prepare("Delete from STOCK where id_s= :id_s");
    query.bindValue(":id_s",res);
    return query.exec();
}
bool stock::modifier(int id_s,int quantite,QString TYPE_PRODUIT,QString saison,QString DATE_CREATION,QString DATE_VENTE)
{
QSqlQuery query;


query.prepare("UPDATE stock SET quantite=:quantite , TYPE_PRODUIT=:TYPE_PRODUIT, saison=:saison , DATE_CREATION=:DATE_CREATION ,DATE_VENTE=:DATE_VENTE where id_s=:id_s");
query.bindValue(":id_s", id_s);
query.bindValue(":quantite", quantite);
query.bindValue(":TYPE_PRODUIT", TYPE_PRODUIT);
 query.bindValue(":saison",saison);
query.bindValue(":DATE_CREATION",DATE_CREATION);
query.bindValue(":DATE_VENTE", DATE_VENTE);
  if (query.exec()) {
      // Commit the transaction
      QSqlDatabase::database().commit();
      return true;
  } else {
      // Rollback the transaction in case of an error
      QSqlDatabase::database().rollback();
      return false;
  }


}

