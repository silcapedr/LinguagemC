#include <stdio.h>
#include <stdlib.h>

char jogo[3][3];
char player1[50], player2[50];

void start(){
  int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			jogo [i][j] = 'a';
		}
	}
	
}
int eValido(char letra){
	if(letra == 'x' || letra == '0')
		return 1;
	else
		return 0;
}
int coordValida(int x, int y){
   if(x >= 0 && x < 3){
		if(y >= 0 && y < 3);
			return 1;
   }
   return 0;
}
int posVazia(int x, int y){
	if(jogo[x][y] != 'x' && jogo[x][y] != '0')
		return 1;
	return 0;
}
int ganhouLinha(){
	int i, j, igual = 1;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 2; j++){
			if(eValido(jogo[i][j]) && jogo[i][j] == jogo[i][j+1])
				igual++;
		}
		if(igual == 3)
			return 1;
		igual = 1;
	}
	return 0;
}
int ganhouColunas(){
	int i, j, igual = 1;
	for (i = 0; i < 3; i++){
		for (j= 0; j < 2  ; j++){
			if(eValido(jogo[j][i]) && jogo[j][i] == jogo[j+1][i])
				igual++;
		}
		if(igual == 3)
			return 1;
		igual = 1;
	}
	return 0;
}
int ganhouDiagonalPrin(){
	int i, igual = 1;
	for (i = 0; i < 2; i++){
		if (eValido (jogo[i][i]) && jogo [i][i] == jogo [i+1][i+1])
			igual++;
	}
	if(igual == 3)
		return 1;
	else
		return 0;
}
int ganhouDiagonalSec(){
	int i, igual = 1;
	for (i = 0; i < 2; i++){
		if (eValido (jogo[i][3-i-1]) && jogo [i][3-i-1] == jogo [i+1][3-i-2])
			igual++;
	}
	if(igual == 3)
		return 1;
	else
		return 0;
}
void imprimir(){
	int l, c;
	
	printf("\t   0   1   2\n");
	
	for(l = 0; l < 3; l++){
		printf("\t%d ", l);
		
		for(c = 0; c < 3; c++){
			if(eValido (jogo[l][c])){
				if(c < 2)
					printf(" %c | ", jogo[l][c]);
				else
					printf(" %c ", jogo[l][c]);
			}
			else{
				if(c < 2)
					printf("   | ");
				else
					printf("   ");
			}
		}
		if(l < 2)
			printf("\n\t   ----------\n");
	}
}
void jogar(){
	int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1;
	
	do{
		do{
			imprimir();
			printf("\n\ndigite onde deseja jogar: ");
			scanf("%d%d", &x, &y);
			valida = coordValida(x, y);
			if(valida == 1)
			valida += posVazia(x, y);
	
	}
		while(valida != 2);
		if(ordem == 1)
			jogo[x][y] = 'x';
		else
			jogo[x][y] = '0';
			
		jogadas++;
		ordem++;
		
		if(ordem == 3)
			ordem = 1;
		ganhou += ganhouLinha();
		ganhou += ganhouColunas();
		ganhou += ganhouDiagonalPrin();
		ganhou += ganhouDiagonalSec();
	}
	while(ganhou == 0 && jogadas < 9);
	
	if(ganhou != 0){
		if(ordem - 1 == 1)
			printf("\nParabens %s, vc venceu!:D \n", player1);
		else
			printf("\nParabens %s, vc venceu!:D \n", player2);
	}
	else
		printf("\nDeu velha... :( \n\n");
}
int main(){
	
	int opcao;
	
	printf("Jogador 1 informe seu nome: ");
	fgets(player1, 20, stdin);
	printf("Jogador 2 informe seu nome: ");
	fgets(player2, 20, stdin);
	
	do{
		start();
		jogar();
		printf("deseja jogar novamente? \n1 - Sim\n2 - Nao\n");
		scanf("%d", &opcao);
	}
	while(opcao == 1);
	

return 0;
}
