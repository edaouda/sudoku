#include "form.h"
#include "ui_form.h"
#include<iostream>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),
    taille(9),
    //taille(ui->taille_16->isChecked()? 16 : 9),
    sdku(taille,taille)
{
    ui->setupUi(this);
    connect(ui->quitter,&QPushButton::clicked,this,&QApplication::quit);


}

Form::~Form()
{
    delete ui;
}




void Form::on_generer_clicked()
{
    sdku.initialise_s();

    ui->_bloc1->setLayout(sdku.layout1());

}


void Form::on_resoudre_clicked()
{

    if(sdku.resoudreSudoku())
        ui->_bloc1->setLayout(sdku.layout1());


}


void Form::on_effacer_clicked()
{
     sdku.reunitialiser();
     ui->_bloc1->setLayout(sdku.layout1());


}

void Form::on_taille_16_stateChanged(int arg1)
{  /* taille=16;
    sdku.setLigne(16);
    sdku.setColonne(16);
    sdku.initialise_s1();
    ui->_bloc1->setLayout(sdku.layout1());
    */

}

void Form::on_aleatoire_clicked()
{
    sdku.reunitialiser();
    sdku.initialise_s1();

    ui->_bloc1->setLayout(sdku.layout1());
}
