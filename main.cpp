#include<iostream>
#include<QApplication>
#include "form.h"


 /*
int main()

{

  int grid[9][9] = {{0, 1, 0, 0, 2, 0, 0, 6, 0},

                      {0, 0,0, 0, 0, 8, 9, 0, 0},

                      {9, 0, 0, 0, 0, 7, 0, 8, 0},

                      {0, 7, 0, 0, 0, 5, 8, 0, 2},

                      {0, 0, 4, 1, 0, 2, 5, 0, 0},

                      {1, 0, 2, 7, 0, 0, 0, 9, 0},

                      {0, 9, 0, 4, 0, 0, 0, 0, 7},

                      {0, 0, 5, 2, 0, 0, 0, 0, 0},

                      {0, 4, 0, 0, 7, 0, 0, 5, 0}};


    sudoku s(9,9);


    if (s.resoudreSudoku() == true)

         s.afficherGrille();
    else

        std::cout<<"No solution exists"<<endl;



    return 0;

}
*/

int main(int argc,char *argv[])
{
  QApplication p(argc,argv);
    Form window;

       window.show();
    return  p.exec();

}



