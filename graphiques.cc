/*#include "graphique.hh"
#include<iostream>

Graphique::Graphique():_grilles(),sdku()
{
      resize(700,500);
       QLabel * titre=new QLabel(this);
                titre->setText("SUDOKU");

       QFrame *_bloc1=new QFrame(this);
             _bloc1->setGeometry(0,70,700,300);
       QPushButton *lancement=new QPushButton("RUN",this);
                    lancement->setGeometry(600,400,70,30);

      QGridLayout *g=new QGridLayout;
     // sdku.initialise_s();
      auto grille=sdku.grille();
      if(sdku.resoudreSudoku())
           grille=sdku.grille();
      QPushButton * b=new QPushButton(this);
                b->setText(QString::fromStdString(std::to_string(grille[0][0])));


                std::cout<<"Ligne "<<sdku.row()<<std::endl;
                std::cout<<"Row"<<sdku.row();
     for(int r(0);r<sdku.row();r++)
      {
          for(int c(0);c<sdku.col();c++)
          {

              QPushButton * b=new QPushButton(this);
                        b->setText(QString::fromStdString(std::to_string(grille[r][c])));
              g->addWidget(b,r,c);
          }

      }





     _bloc1->setLayout(g);


}


*/
