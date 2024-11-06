#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "stock.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int id_s=ui->lineEdit->text().toInt();
    int quantite=ui->lineEdit_Qantiteu->text().toInt();
    QString type=ui->lineEdit_Type->text();
    QString saison=ui->lineEdit_Saison->text();
    QString DC=ui->lineEdit_DC->text();
    QString DV=ui->lineEdit_DV->text();
    stock S(id_s,quantite,type,saison,DV,DC);
    bool test=S.ajouter();
    if(test){ // Si requête executée ==>

        ui->tableView->setModel(etmp.afficher());

    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Ajout effectué\n Click Cancel to exit"),QMessageBox::Cancel);
    }
    else //
    QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                         QObject::tr("Ajout non effectué\n Click Cancel to exit"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
    int id_s=ui->lineEdit_id->text().toInt();
    bool test=etmp.supprimer(id_s);
    if(test){ // Si requête executée ==>
        ui->tableView->setModel(etmp.afficher());


    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("suppression effectué\n Click Cancel to exit"),QMessageBox::Cancel);
    }
    else //
    QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                         QObject::tr("suppression non effectué\n Click Cancel to exit"),QMessageBox::Cancel);

}



void MainWindow::on_pushButton_3_clicked()
{
    int id_s=ui->lineEdit->text().toInt();
    int quantite=ui->lineEdit_Qantiteu->text().toInt();
    QString type=ui->lineEdit_Type->text();
    QString saison=ui->lineEdit_Saison->text();
    QString DC=ui->lineEdit_DC->text();
    QString DV=ui->lineEdit_DV->text();
    stock S(id_s,quantite,type,saison,DV,DC);
    bool test=S.modifier(id_s,quantite,type, saison, DC, DV);
    if(test){ // Si requête executée ==>

        ui->tableView->setModel(etmp.afficher());

    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Ajout effectué\n Click Cancel to exit"),QMessageBox::Cancel);
    }
    else //
    QMessageBox::critical(nullptr, QObject::tr(" not OK"),
                         QObject::tr("Ajout non effectué\n Click Cancel to exit"),QMessageBox::Cancel);
}
