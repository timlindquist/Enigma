#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char available[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char pair[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void reindex(int r, int remainder);
void repair(int r, int remainder);
void print_array(int array[]);
void rm(char character, int remainder);

int main(){
  char input[26];
  char output[26];
  int r;
  int i;
  int j;
  int k;
  int remainder=25;
  char char_remove;
  srand(time(NULL));
  for(i=0;i<26;i++){
    output[i]=0;
  }

  //initial
  for(i=25;i>=0;i--){
    r=rand()%(i+1);
    input[i]=available[r];
    reindex(r,i);
  }

  //pair
  for(i=25;i>=0;i--){
    if(output[i]==0){
    r=rand()%(remainder+1);
    if(pair[r]==input[i]){
      i++;
      }
    else{
      output[i]=pair[r];
      repair(r,remainder);
      remainder--;
    }
    for(j=i;j>=0;j--){
      if(input[j]==output[i]){
        output[j]=input[i];
        char_remove=output[j];
      }
    }
    for(j=0;j<remainder;j++){
      if(pair[j]==char_remove){
        repair(j,remainder);
        remainder--;
      }
    }

  }
}


  printf("{");
  for(i=0;i<25;i++){
    printf("'%c',",input[i]);
  }
  printf("'%c'}\n",input[25]);

  printf("{");
  for(i=0;i<25;i++){
    printf("'%c',",output[i]);
  }
  printf("'%c'}\n",output[25]);


  return 0;
}


void reindex(int r, int remainder){
  int i;
  for(i=r;i<remainder;i++){
    available[i]=available[i+1];
  }
}


void repair(int r, int remainder){
  int i;
  for(i=r;i<remainder;i++){
    pair[i]=pair[i+1];
  }
}


void print_array(int array[]){
  int i;
  printf("{");
  for(i=0;i<25;i++){
    printf("'%d',",array[i]);
  }
  printf("'%d'}\n",array[25]);
}


void rm(char character, int remainder){
  int i;
  for(i=0;i<remainder;i++){
    if(pair[i]==character){
      repair(i,remainder);
    }
  }
}
