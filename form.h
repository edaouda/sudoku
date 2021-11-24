#ifndef FORM_H
#define FORM_H
#include "sudoku.hh"
#include <QtWidgets>

namespace Ui {
class Form;
}

class Form : public QWidget
{
     Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_generer_clicked();
    void on_resoudre_clicked();
    void on_effacer_clicked();

    void on_taille_16_stateChanged(int arg1);

    void on_aleatoire_clicked();

private:
    Ui::Form *ui;

    unsigned int taille;
    sudoku sdku;
};

#endif // FORM_H
