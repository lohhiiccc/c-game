#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
int tab[3][3] = {//table de jeux 0=vide 1=player 1(x) 2=player2(o);
  {0,0,0},
  {0,0,0},
  {0,0,0}};
int turn = 2;//definie a qui est le tour default(player 2));
int i,j;
int lastTurn =0;
int player(int chose){
  lastTurn++;
  if(chose == 1){
    turn = 2;
    return 2; 
  }
  else{
    turn = 1;
    return 1;
}}
void affichage(){
  for(i=0;i<=2;i++){
    for(j=0;j<=2;j++){
      //printf("i = %d, j = %d\n",j,i);
      if(j==2){
        //printf("%3d\n",tab[i][j]);
        if(tab[i][j]==0)
          printf(" . \n");
        else if(tab[i][j]==1)
          printf(" x \n");
        else if(tab[i][j]==20)
          printf(" o \n");
      }
      else{
        //printf("%3d",tab[i][j]);
        if(tab[i][j]==0)
          printf(" . ");
        else if(tab[i][j]==1)
          printf(" x ");
        else if(tab[i][j]==20)
          printf(" o ");
      }
    }
  }
  //printf("%4d",tab[3][0]);
}
void play(int player){//demande une ligne et une collone et met la matrice a jour
  int tempcolonne;
  int templigne;
  printf("player: %d\n", player);
  printf(" \n");
  printf("ligne: ");
  scanf("%d", &tempcolonne);
  printf("colonne: ");
  scanf("%d", &templigne);
  if(tempcolonne > 3 ||templigne > 3 ||tempcolonne == 0 ||templigne == 0){//verify les valeur
    printf("erreur");
    abort();
  }
  else{
    if(tab[tempcolonne-1][templigne-1] != 0){
      abort();
    }
    else{
      if(player == 1)
        tab[tempcolonne-1][templigne-1] = 1;
      else if(player ==2)
        tab[tempcolonne-1][templigne-1] = 20;
    printf("turn: %d",player);}
  }

}
void clear(){
      printf("\e[1;1H\e[2J");
}
int checkWin(){
  int x;
  int diagonaleA = tab[0][0] + tab[1][1] + tab[2][2];
  int diagonaleB = tab[2][0] + tab[1][1] + tab[0][2];
  if(lastTurn == 9)
    return 2;
  else{
    for(x=0;x<=2;x++){
      int horizontale = tab[x][0] + tab[x][1] + tab[x][2];
      int verticale = tab[0][x] + tab[1][x] + tab[2][x];
      if(horizontale == 3 || verticale == 3|| diagonaleA == 3 || diagonaleB == 3)
        return 1;
      else if(horizontale > 41 || verticale > 41 || diagonaleA > 41 ||diagonaleB > 41)
        return 1;
    }
  }
    return 0;
}

int main(){
  while(checkWin()==0){
    clear();
    affichage();
    play(player(turn));
  }
  clear();
  affichage();
  printf("\nfin de partie\n");
  if(checkWin()==2)
    printf("egalite\n");
   return 0;
}
