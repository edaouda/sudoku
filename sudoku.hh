#include<array>
//#define N 9
#include<QtWidgets>
#include<vector>

using typeGrille=std::vector<int >;

class sudoku
{
public:
    sudoku(unsigned int ligne,unsigned int colonne);
    void initialise_s();
     void initialise_s1();
    bool estvalide(int row, int col, int num) const;
    bool contientZero(int &row,int &col) const;
    bool estsurligne( int row, int num)const ;
    bool estSurcolonne( int col, int num) const;
    bool estDansRegion(int debutligne, int debutcol, int num) const;
    bool resoudreSudoku();
    void afficherGrille() const;
 QGridLayout * layout1() const{ return g;}
     int colonne()const ;
     int ligne()const ;
     void setLigne(int l);
     void setColonne(int c);
     void reunitialiser();
     void parcours(int grille[9][9]);
      void parcours(int grille[16][16]);



private:

      std::vector<typeGrille>grille() const;
private:
    int _ligne;
    int _colonne;
    std::vector<typeGrille>_grilles;
    QGridLayout * g;

};
