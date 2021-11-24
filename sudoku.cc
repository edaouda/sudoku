#include "sudoku.hh"
#include<algorithm>
#include<iostream>
#include<math.h>
sudoku::sudoku(unsigned int ligne,unsigned int colonne):_ligne(ligne),_colonne(colonne)
{
      g=new QGridLayout;
    for (int row(0); row < _ligne; row++)

    {
         typeGrille g;

        for (int col(0); col < _colonne; col++){

               g.push_back(0);

          }
          _grilles.push_back(g);



    }
}


bool sudoku::contientZero(int &row, int &col) const

{

    for ( row=0; row < _ligne; row++){

        for (col = 0; col < _colonne; col++){

            if (_grilles.at(row).at(col) == 0)

                return true;
        }
     }
    return false;

}

bool sudoku::estSurcolonne( int col, int num) const
{

    for (int row(0); row < _ligne; row++){
        if (_grilles.at(row).at(col) == num)
            return true;
    }
    return false;
}

bool sudoku::estsurligne(int row, int num) const
{

    for (int col(0); col < _colonne; col++){
        if (_grilles.at(row).at(col) == num)
            return true;
    }
    return false;
}

bool sudoku::estvalide(int row, int col, int num) const
{
    return !estsurligne(row, num) && !estSurcolonne(col, num) &&
           !estDansRegion(row - row % static_cast<int>(sqrt(_ligne)) , col - col % static_cast<int>(sqrt(_ligne)), num);

}


bool sudoku::estDansRegion(int debutligne, int debutcol, int num) const

{
       int taille=static_cast<int>(sqrt(_ligne));
    for (int row(0); row < taille; row++)
        for (int col(0); col < taille; col++)
            if (_grilles.at(row+debutligne).at(col+debutcol) == num)
                return true;

    return false;

}




bool sudoku::resoudreSudoku()

{

    int row, col;

    if (!contientZero(row, col))

       return true;

    for (int num(1); num <=_ligne; num++)

    {

        if (estvalide(row, col, num))

        {
            QPushButton * b=new QPushButton();
           // b->setStyleSheet("background-color:blue;color:white");
                    b->setText(QString::fromStdString(std::to_string(num)));

                g->addWidget(b,row,col);

            _grilles.at(row).at(col) = num;

            if (resoudreSudoku())

                return true;

            _grilles.at(row).at(col) = 0;

        }

    }
     afficherGrille();


    return false;

}

void sudoku::afficherGrille() const
{
    for (int row (0); row < _ligne; row++){

        for (int col(0); col < _colonne; col++)

            std::cout<<_grilles.at(row).at(col)<<"  ";

               std::cout<<std::endl;
    }


}
std::vector<typeGrille> sudoku::grille() const{
                                               return _grilles;
                                }


int sudoku::colonne()const {
             return _colonne;
  }

 int sudoku::ligne()const {
             return _ligne;
  }

 void sudoku::setLigne(int l)
 {
     _ligne=l;
 }
 void sudoku::setColonne(int c)
 {
     _colonne=c;
 }
 void sudoku::initialise_s()
 {
         std :: random_device rd ;
         std :: mt19937 gen ( rd ( ) ) ;
         std :: uniform_int_distribution <> distrib (0,_ligne-1);

               if(resoudreSudoku())
               {
                for(int row(0);row<_ligne;row++)
                {
                      for(int i(0);i<_colonne;i++)
                      {
                          auto v=distrib(gen);

                             _grilles.at(row).at(v)=0;

                          QPushButton * b=new QPushButton();
                            b->setStyleSheet("background-color:black;color:white");
                                  b->setText(QString::fromStdString(std::to_string(0)));

                              g->addWidget(b,row,v);
                          }

                      }
                  }



}

 void sudoku::reunitialiser()
 {
     for(int row(0);row<_ligne;row++)
     {
           for(int i(0);i<_colonne;i++)
           {
                _grilles.at(row).at(i)=0;
                QPushButton *b=new QPushButton();
                b->setStyleSheet("background-color:black;color:white");
                         b->setText(QString::fromStdString(std::to_string(_grilles.at(row).at(i))));


               g->addWidget(b,row,i);

           }
     }

 }

 void sudoku::initialise_s1()
 {
         std :: random_device rd ;
         std :: mt19937 gen ( rd ( ) ) ;
         std :: uniform_int_distribution <> distrib (0,7);



         int grid[8][9][9] = {{{0, 1, 0, 0, 2, 0, 0, 6, 0},

                             {0, 0,0, 0, 0, 8, 9, 0, 0},

                             {9, 0, 0, 0, 0, 7, 0, 8, 0},

                             {0, 7, 0, 0, 0, 5, 8, 0, 2},

                             {0, 0, 4, 1, 0, 2, 5, 0, 0},

                             {1, 0, 2, 7, 0, 0, 0, 9, 0},

                             {0, 9, 0, 4, 0, 0, 0, 0, 7},

                             {0, 0, 5, 2, 0, 0, 0, 0, 0},

                             {0, 4, 0, 0, 7, 0, 0, 5, 0}},
                             {{2, 0, 0, 5, 0, 0, 7, 0, 0},

                             {0, 3, 9, 7, 2, 1, 0, 0, 0},

                             {4, 1, 7, 9, 6, 8, 2, 5, 0},

                             {0, 2, 0, 6, 7, 4, 5, 0, 8},

                             {8, 7, 0, 1, 5, 9, 3, 6, 0},

                             {0, 0, 0, 3, 0, 2, 9, 7, 4},

                             {3, 0, 5, 2, 1, 7, 6, 0, 0},

                             {0, 9, 6, 0, 0, 5, 4, 0, 0},

                             {0, 8, 2, 4, 9, 0, 1, 3, 0}},
                              { {5, 0, 0, 0, 9, 0, 0, 0, 1},

                             {4, 3, 8, 0, 1, 5, 6, 0, 7},

                             {1, 0, 0, 3, 6, 0, 2, 0, 5},

                             {2, 6, 0, 0, 7, 3, 9, 5, 8},

                             {0, 0, 0, 0, 0, 4, 1, 0, 6},

                             {0, 5, 0, 6, 0, 9, 3, 2, 4},

                             {0, 7, 9, 8, 4, 6, 0, 0, 2},

                             {0, 4, 2, 0, 5, 1, 7, 6, 3},

                             {0, 1, 0, 7, 3, 2, 0, 8, 9}},

                             { {7, 6, 2, 0, 9, 1, 8, 4, 5},

                             {9, 0, 5, 0, 0, 7, 2, 0, 0},

                             {1, 8, 3, 2, 0, 0, 0, 6, 0},

                             {0, 0, 7, 5, 0, 0, 4, 1, 3},

                             {0, 0, 0, 0, 0, 0, 0, 0, 0},

                             {5, 0, 0, 0, 1, 4, 6, 0, 0},

                             {0, 0, 0, 0, 2, 8, 0, 7, 6},

                             {6, 2, 4, 0, 7, 3, 5, 8, 9},

                             {8, 0, 0, 6, 0, 0, 3, 0, 4}},

                             { {0, 2, 0, 3, 0, 0, 8, 0, 0},

                             {3, 1, 0, 0, 0, 0, 0, 4, 9},

                             {4, 5, 0, 2, 9, 8, 7, 1, 0},

                             {0, 0, 2, 5, 8, 4, 1, 0, 7},

                             {6, 8, 0, 7, 1, 0, 9, 2, 4},

                             {0, 0, 4, 0, 0, 6, 0, 0, 5},

                             {2, 6, 7, 8, 3, 5, 4, 0, 1},

                             {0, 4, 0, 1, 0, 0, 5, 0, 0},

                             {0, 9, 0, 0, 0, 0, 0, 0, 0}},

                            { {0, 0, 0, 0, 0, 0, 0, 4, 5},

                             {2, 0, 4, 0, 0, 0, 3, 8, 7},

                             {0, 5, 7, 8, 0, 0, 6, 0, 2},

                             {4, 0, 0, 1, 7, 0, 2, 6, 9},

                             {1, 2, 9, 6, 0, 0, 0, 0, 0},

                             {8, 0, 0, 3, 9, 0, 0, 5, 4},

                             {0, 8, 0, 0, 0, 0, 0, 3, 6},

                             {5, 6, 0, 4, 2, 3, 7, 0, 8},

                             {0, 0, 0, 9, 0, 0, 0, 0, 0}},

                             { {0, 0, 8, 6, 0, 0, 0, 0, 9},

                             {4, 7, 0, 3, 0, 0, 0, 0, 0},

                             {0, 0, 0, 0, 0, 0, 4, 1, 3},

                             {0, 0, 0, 0, 8, 4, 7, 0, 0},

                             {7, 0, 0, 1, 0, 6, 0, 0, 2},

                             {0, 0, 6, 7, 9, 0, 0, 0, 0},

                             {1, 9, 7, 0, 0, 0, 0, 0, 0},

                             {0, 0, 0, 0, 0, 3, 0, 2, 7},

                             {2, 0, 0, 0, 0, 1, 8, 0, 0}},

                            { {0, 0, 1, 8, 7, 0, 0, 0, 0},

                             {0, 0, 0, 0, 0, 1, 3, 0, 2},

                             {0, 0, 0, 3, 0, 0, 0, 0, 7},

                             {0, 9, 0, 0, 0, 8, 0, 1, 5},

                             {7, 0, 0, 1, 0, 5, 0, 0, 9},

                             {3, 1, 0, 9, 0, 0, 0, 6, 0},

                             {5, 0, 0, 0, 0, 7, 0, 0, 0},

                             {6, 0, 2, 5, 0, 0, 0, 0, 0},

                             {0, 0, 0, 0, 8, 9, 5, 0, 0}}

                             };





    int grid16[2][16][16]={{{5, 12, 0, 14, 8, 10, 4, 0, 6, 13, 0, 0, 3, 0, 1, 9},

                        {0, 0, 0, 0, 0, 6, 0, 16, 0, 7, 0, 0, 0, 2, 4, 0},

                        {11, 0, 13, 2, 3, 15, 0, 9, 8, 0, 16, 4, 10, 0, 0, 12},

                        {0, 0, 0, 7, 0, 0, 2, 0, 0, 3, 0, 14, 8, 5, 0 ,16},

                        {14, 0, 11, 12, 5, 0, 16, 0, 13, 0, 0, 0, 0, 0, 10, 15},

                        {1, 0, 2, 0, 11, 0, 7, 0, 0, 0, 9, 0, 6, 0, 5, 14},

                        {0, 0, 6, 0, 0, 0, 10, 0, 15, 11, 4, 5, 0, 3, 16, 0},

                        {3, 0, 10, 15, 1, 9, 12, 0, 0, 0, 14, 6, 7, 11, 0, 0},

                        {0, 0, 15, 3, 10, 0, 11, 0, 0, 8, 7, 12, 0, 0, 9, 0},




                         {6, 0, 0, 10, 0, 8, 0, 0, 0, 0, 3, 0, 11, 0, 0, 0},

                          {0, 0, 0, 1, 0, 0, 6, 0, 4, 16, 0, 9, 13, 0, 15 ,10},

                          {0, 16, 8, 0, 0, 2, 15, 12, 5, 0, 6, 0, 0, 4, 14, 0},

                          {12, 3, 0, 5, 0, 11, 1, 0, 0, 14, 13, 0, 16, 10, 2, 6},

                          {8, 0, 7, 13, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0},

                           {10, 11, 14, 6, 16, 0, 0, 0, 12, 9, 0, 0, 4, 0, 3, 13},

                           {0, 0, 1, 0, 14, 0, 9, 10, 0, 0, 0, 3, 0, 12, 7,0}
                          },


                           {{0, 0, 0, 6, 0, 8, 3, 0, 0, 0, 0, 16, 0, 0, 5, 14},

                            {0, 0, 0, 10, 0, 0, 0, 4, 9, 13, 0, 0, 0, 0, 2, 16},

                            {2, 3, 13, 15, 0, 5, 0, 14, 0, 0, 10, 12, 4, 11, 1, 0},

                            {4, 16, 5, 14, 12, 0, 2, 0, 15, 1, 0, 6, 8, 13, 0 ,0},

                            {0, 13, 0, 0, 14, 0, 0, 1, 6, 0, 0, 10, 0, 4, 0, 0},

                            {0, 12, 11, 9, 0, 3, 0, 16, 14, 2, 15, 8, 10, 1, 0, 13},

                            {1, 2, 0, 3, 13, 0, 0, 6, 0, 7, 12, 5, 0, 0, 0, 0},

                            {6, 0, 0, 16, 0, 0, 0, 15, 0, 3, 1, 13, 0, 0, 0, 11},

                            {0, 0, 3, 2, 15, 14, 0, 0, 10, 4, 16, 0, 12, 0, 0, 0},




                             {0, 0, 0, 1, 11, 7, 0, 0, 0, 0, 6, 0, 5, 0, 0, 0},

                              {8, 0, 15, 0, 9, 16, 6, 12, 0, 14, 2, 0, 0, 10, 0, 0},
                            {0, 0, 6, 0, 1, 0, 10, 3, 8, 12, 13, 0, 9, 0 ,0, 2},


                              {3, 6, 0, 0, 16, 11, 0, 10, 13, 5, 7, 2, 14, 0, 9, 8},

                              {9, 0, 0, 11, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 4, 12},

                               {0, 8, 10, 0, 2, 15, 1, 0, 16, 0, 14, 0, 11, 7, 3, 0},

                               {14, 15, 0, 7, 0, 13, 4, 0, 0, 0, 0, 0, 2, 0, 0,0}
                        }
                          };




      if(_ligne==9)
             parcours( grid[distrib(gen)]);
      else
              parcours(grid16[1]);


}

 void sudoku::parcours(int grille[9][9])
 {

     for(int row(0);row<_ligne;row++)
     {
           for(int i(0);i<_colonne;i++)
           {
                _grilles.at(row).at(i)=grille[row][i];
                QPushButton *b=new QPushButton();
                b->setStyleSheet("background-color:black;color:white");
                         b->setText(QString::fromStdString(std::to_string(_grilles.at(row).at(i))));


               g->addWidget(b,row,i);

           }
     }
 }

 void sudoku::parcours(int grille[16][16])
 {

     for(int row(0);row<_ligne;row++)
     {
           for(int i(0);i<_colonne;i++)
           {
                _grilles.at(row).at(i)=grille[row][i];
                QPushButton *b=new QPushButton();
                b->setStyleSheet("background-color:black;color:white");
                         b->setText(QString::fromStdString(std::to_string(_grilles.at(row).at(i))));


               g->addWidget(b,row,i);

           }
     }
 }
