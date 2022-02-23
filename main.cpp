#include <bits/stdc++.h>
using namespace std;

int grille[9][9] = { {0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0}};
bool presentcol(int col, int nb){ //tester si le chiffre est present dans col
for (int ligne = 0; ligne < 9; ligne++)
if (grille[ligne][col] == nb)
return true;
return false;
}
bool presentligne(int ligne, int nb){ //tester si le chiffre est present dans ligne
for (int col = 0; col < 9; col++)
if (grille[ligne][col] == nb)
return true;
return false;
}
bool presentcarre(int lignedeb, int coldeb, int nb){ //tester si le chiffre est present dans un carrée 3 x 3
for (int ligne = 0; ligne < 3; ligne++)
for (int col = 0; col < 3; col++)
if (grille[ligne+lignedeb][col+coldeb] == nb)
return true;
return false;
}
void affiche(){ //afficher la grille
for (int ligne = 0; ligne < 9; ligne++){
for (int col = 0; col < 9; col++){
if(col == 3 || col == 6)
cout << " | ";
cout << grille[ligne][col] <<" ";
}
if(ligne == 2 || ligne == 5){
cout << endl;
for(int i = 0; i<9; i++)
cout << "---";
}
cout << endl;
}
cout << endl<<endl;
}
bool estvide(int &ligne, int &col){ //obtenir l’emplacement vide
for (ligne = 0; ligne < 9; ligne++)
for (col = 0; col < 9; col++)
if (grille[ligne][col] == 0) //la valeur "0" nous permet de reperer une case est vide
return true;
return false;
}
bool estvalide(int ligne, int col, int nb){  //la grille est valide si nb n'est pas trouvé dans la colonne, ligne et le carrée 3 x 3 de nb 

return !presentligne(ligne, nb) and !presentcol(col, nb) and
!presentcarre(ligne - ligne%3 , col - col%3, nb);
}
bool solve(){
int ligne, col;
if (!estvide(ligne, col))
return true; //si toute les cases ne sont pas vide
for (int nb = 1; nb <= 9; nb++){ //les nombres valides sont entre 1 et 9
if (estvalide(ligne, col, nb)){ //si c'est vrai, on met la valeur dans la case
grille[ligne][col] = nb;
if (solve()) //on parcourt les autres cases vides de maniere recursive
return true;
grille[ligne][col] = 0; //on se tourner vers les autres case vide lorsque les conditions ne sont pas satisfaites
}
}
return false;
}
int main(){
    cout<<"Le sudoku a resoudre est :"<<endl<<endl;
    affiche();
if (solve() == true){
cout<<"La solution est :"<<endl<<endl;
affiche();
}
else
cout << "La solution n'existe pas";
return 0;
}
