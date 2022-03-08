#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int grille[6][7] = {
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0}
};
int colonne[7] = {0};
int turn = 2;//definie a qui est le tour default(player 2));
void indication(){
  int i;
  printf("\n");
  for(i=1;i<=7;i++){
    printf(" %d ",i);
  }
  printf("\n\n");
}
void convert(int num){
  if(num == 1){
    printf(" x ");
  }
  else if(num == 2){
    printf(" o ");
  }
  else{
    printf(" . ");
  }
}
void affichage(){
  int i;
  int j;
  for(i=5;i>=0;i=i-1){
    for(j=0;j<=6;j++){
      if(j==6){
        convert(grille[i][j]);
        printf("\n");
      }
      else{
        convert(grille[i][j]);
      }
    }
  }
  indication();
}

int checkHeight(int col){
  colonne[col-1] = colonne[col-1] + 1;
  if(col>=7){
    abort();
  }
  else if(colonne[col-1] >= 7)
    abort();
  else
    return colonne[col-1]-1;
}

void play(int player){
  int colonne = 1;
  printf("player: %d\ncolonne: ",turn);
  scanf("%d",&colonne);
  grille[checkHeight(colonne-1)][colonne-1] = player;
  
}
void clear(){
      printf("\e[1;1H\e[2J");
}
int player(int chose){
  if(chose == 1){
    turn = 2;
    return 2; 
  }
  else{
    turn = 1;
    return 1;
}}
int checkWin(){
  return 0;
}
int main(){
  clear();
  affichage();
  while (checkWin() == 0)
  {
    play(player(turn));
    clear();
    affichage();
  }

  return 0;
}

