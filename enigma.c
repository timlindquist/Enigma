#include <stdio.h>
#include <string.h>

char rotor1[2][26]={{'O','L','J','H','K','E','U','Y','B','I','S','A','Q','D','W','Z','T','F','P','N','X','G','R','M','V','C'},
										{'C','J','N','O','L','X','Y','Z','M','W','S','P','D','I','F','K','B','U','T','A','H','Q','E','R','G','V'}};
char rotor2[2][26]={{'J','I','A','F','N','T','E','P','H','W','L','U','B','G','C','M','Y','D','Z','Q','V','K','O','S','X','R'},
										{'M','D','K','B','F','N','G','C','W','Z','Y','O','T','J','I','E','L','X','H','Q','V','U','A','R','S','P'}};
char rotor3[2][26]={{'X','C','U','J','M','I','K','P','S','Y','L','F','R','O','N','V','D','T','E','W','G','B','Q','Z','A','H'},
										{'I','E','G','N','W','J','Q','A','S','X','B','R','P','C','V','K','H','O','L','F','Y','U','Z','D','T','M'}};
int reflector[2][26]={{'O','Y','C','R','E','U','B','Z','N','X','S','V','H','W','A','K','Q','I','D','J','M','P','L','F','T','G'},
										{'U','G','H','A','N','O','I','Q','E','K','J','L','C','M','R','X','Z','B','P','S','W','D','V','T','F','Y'}};

int position(char input);


int main(){
	int r1_pos;
	int r2_pos;
	int r3_pos;
	int i,j,k;
	char input[10];
	char word[10];
	printf("Rotor Placement\n");
	printf("Rotor 1: ");
	fgets(input,10,stdin);
	r1_pos=position(input[0]);
	printf("Rotor 2: ");
	fgets(input,10,stdin);
	r2_pos=position(input[0]);
	printf("Rotor 3: ");
	fgets(input,10,stdin);
	r3_pos=position(input[0]);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Key:%d,%d,%d\n",r3_pos,r2_pos,r1_pos);
 int length;
	for(;;){
		int letter=0;
		scanf("%s",word);
		//length=strlen(word);
		//printf("%s  %d",word,length);
		for(k=r3_pos;k<26;k++){		//rotor3
			for(j=r2_pos;j<26;j++){		//rotor2
				for(i=r1_pos;i<26;i++){		//rotor1
					position(word[letter]);
					letter++;
				}
				r1_pos=0;
			}
			r2_pos=0;
		}
		r3_pos=0;
	}


return 0;
}



int position(char input){
	if(input>96){	//lowercase
		input=input-32;
	}
	input=input-65;	//position in array

return input;
}
