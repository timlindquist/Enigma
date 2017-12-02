#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char available[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


void reindex(int r, int remainder);

int main(){
  int i;
  int r;
  srand(time(NULL));

  printf("{");
  for(i=25;i>=0;i--){
    r=rand()%(i+1);
    printf("'%c'",available[r]);
    reindex(r,i);
    if(i>0){
      printf(",");
    }
  }
  printf("}");
  printf("\n");
  return 0;
}

void reindex(int r, int remainder){
  int i;
  for(i=r;i<remainder;i++){
    available[i]=available[i+1];
  }
}
