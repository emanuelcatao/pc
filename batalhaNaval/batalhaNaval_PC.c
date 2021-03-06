/**
 * @file batalhaNaval_PC.c
 * @author Emanuel Catao (emanuel.montenegro@mail.uft.edu.br)
 * @brief Jogo de batalha naval:
 * O jogo é realizado em tabuleiros de dimensão 10x10 preenchido com um total de 5 embarcações.
 * As embarcações são de 5 diferentes tipos, cada qual com suas próprias dimensões. Vence
 * quem acertar todas as casas ocupadas por embarcações do adversário.
 * Em razão da implementação empregada, quem tiver em seu tabuleiro embarcações de maior tamanho
 * leva vantagem, uma vez que seriam necessários mais tiros para acertar todas as casas ocupadas pelas embarcações.
 * OBS: NESSA IMPLEMENTAÇÃO JOGA-SE CONTRA O COMPUTADOR QUE, RANDOMICAMENTE, DEFINE SUAS JOGADAS.
 * 
 * Em um jogo é possível: posicionar os tabuleiros dos jogadores; mostrar os tabuleiros de cada jogador; atirar, 
 * gerando um outro tabuleiro para cada jogador (tabuleiro de tiros). A vitória é dada da comparação entre o tabuleiro
 * de tiros e o tabuleiro adversário
 * 
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>									
#include <stdlib.h>
#include <time.h>	

void posiciona(char **nav,int jogador);
void mostratabuleiro(char **nav1);
void atira(char **nav1,char **nav2,char **tir1,char **tir2);
int converteColunas(char *coluna, int *num_coluna);
void escolhePosicionamento(char **nav);
void verificaDestruicao(char **navios, char **tiros, int *navios_afundados);

int main() 														
{
	char **navios1,**navios2,**tiros1,**tiros2;
	int j,k;
	
	printf("Inicia Jogo \n\n");
	
	navios1=(char **)malloc(10*sizeof(char *));
	navios2=(char **)malloc(10*sizeof(char *));
	tiros1=(char **)malloc(10*sizeof(char *));
	tiros2=(char **)malloc(10*sizeof(char *));
	
		
	for(j=0;j<10;j++)
	{
		navios1[j]=(char *)malloc(10*sizeof(char));
		navios2[j]=(char *)malloc(10*sizeof(char));
		tiros1[j]=(char *)malloc(10*sizeof(char));
		tiros2[j]=(char *)malloc(10*sizeof(char));
		
		for(k=0;k<10;k++)
		{
			navios1[j][k]='-';
			navios2[j][k]='-';
			tiros1[j][k]='-';
			tiros2[j][k]='-';
		}
	}
	
	printf("Posiciona navios do Computador\n\n");
	escolhePosicionamento(navios2);

	printf("Posiciona navios Jogador 1\n\n");
	posiciona(navios1,1);
	
	printf("\n");
	
	
	printf("\n\n");
	printf("Inicia os tiros\n");	
	atira(navios1,navios2,tiros1,tiros2);
	
	return 0;
}

/**
 * @brief Embaralhamento para os arrays de inteiros da função de posicionamento
 * 
 * @param array vetor de valores a serem embaralhados
 * @param t tamanho do vetor
 */
void shuffle(int *array, int t) {
    for (int i = t - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
	}
}

/**
 * @brief Embaralhamento para o array de caracteres da função de posicionamento
 * 
 * @param array vetor de caracteres a serem embaralhados
 */
void shuffle1(char *array) {
    for (int i = 4; i > 0; i--) {
        int j = rand() % (i + 1);
        char tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
	}
}

/**
 * @brief Função de posicionamento para o computador, o posicionamento é determinado pelo embaralhamento
 * aleatório dos possíveis valores de linhas, colunas, embarcações e sentido das embarcações.
 * Por padrão, a tentativa falha de inclusão de uma embarcação em determinada posição (aqui delimitada somente
 * ao caso de a posição já estar ocupada), implicará em um novo embaralhamento dos valores e na não contagem
 * do ciclo de repetição, até que se completem 5 posicionamentos válidos, segundo as regras do jogo.
 * 
 * @param nav tabuleiro em matriz que armazenará o posicionamento das embarcações do computador
 */
void escolhePosicionamento(char **nav)
{
	int linha[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int coluna[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char embarc[5] = {'P', 'G', 'C', 'D', 'S'};
	int pos[2] = {0, 1}; //0 para horizontal, 1 para vertical

	
	int i = 0, j, tam;
	srand(time(NULL));
	while(i<5)
	{	
		shuffle(linha, 10);
		shuffle(coluna, 10);
		shuffle1(embarc);
		shuffle(pos, 2);

		int lin = linha[0], col = coluna[0];
		char caracter = embarc[0];
		switch(caracter)
		{
			case 'P':
				tam=5;
				break;
			case 'G':
				tam=4;
				break;
			case 'D':
				tam=2;
				break;
			case 'S':
				tam=3;
				break;
			case 'C':
				tam=3;
				break;
			default:
				break;
        }
		
		if(pos[0] == 0) 
		{	
			int flag = 0;
			if(col<= (10 - tam))
			{	
				for(j=0;j<tam;j++)
				{	
					if(nav[lin][col+j]!='-') {
						flag=1;
					}
				}
					
				if(flag!=1)
				{
					for(j=0;j<tam;j++) {
						nav[lin][col+j]=caracter;
					}
					i=i+1;
					printf("Computador \n");								
					mostratabuleiro(nav);
				}
			}
		}
		else 
		{
			int flag = 0;
			if(lin<= (10 - tam))
			{
				for(j=0;j<tam;j++)
				{	
					if(nav[lin+j][col]!='-') {
						flag=1;
					}
				}
					
				if(flag!=1)
				{
					for(j=0;j<tam;j++) {
						nav[lin+j][col]=caracter;
					}
					i=i+1;
					printf("Computador \n");								
					mostratabuleiro(nav);
				}
			}
		}
	}
}

/**
 * @brief Escolhe randomicamente os tiros para o computador, recebendo como parâmetros
 * o tabuleiro de embarcações do adversário e o tabuleiro de tiros do computador, repassados da função
 * atira. Altera o tabuleiro de tiros e retorna o número de navios afundados por meio do ponteiros
 * passado como parâmetro.
 * 
 * @param nav2 tabuleiro de embarcações do adversário
 * @param tir1 tabuleiro de tiros do computador
 * @param afund ponteiro para o número de navios afundados pelo computador
 */
void escolheTiro(char **nav2,char **tir1, int *afund) {
	int linha[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int coluna[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i = 0;
	srand(time(NULL));
	while(i < 3) {
		shuffle(linha, 10);
		shuffle(coluna, 10);

		int lin = linha[0], col = coluna[0];
		if((tir1[lin][col]!='A')&&(tir1[lin][col]!='X')&&(tir1[lin][col]!='O'))	{									
			if(nav2[lin][col]=='-')
				tir1[lin][col]='O';
			else
				tir1[lin][col]='X';
			i++;
		}
	}

	verificaDestruicao(nav2, tir1, afund);
}



/**
 * @brief Posiciona as 5 embarcações no tabuleiro de embarcações do jogador repassado no parâmetro.
 * Função sem retorno pois preza apenas por modificar a matriz do tabuleiro já recebida por meio de
 * referência como parâmetro da função.
 * 
 * @param nav : matriz de caracteres que representa o tabuleiro do jogador
 * @param jogador : jogador, representado por inteiro, que irá posicionar suas embarcações 
 */
void posiciona(char **nav,int jogador)
{
	int linha,lin,col,i=0,j,l,c,flag,sinal,sinal1,sinal2;
	char coluna,direcao,tiponav;
	
	printf("Entre com as coordenadas para posicionamento dos navios: \nLinhas -> 1-10 \nColunas ->A-J\n");
	puts("");
	printf("-------------- Jogador %d --------------\n",jogador);
    puts("");	
	mostratabuleiro(nav);
	
	while(i<5)
	{
		sinal=0;
		while(sinal!=1)
		{
			printf("Linha = \n");
			scanf("%d", &linha);

			if(linha<=10 && linha>=1)
				sinal=1;
			else
				printf("Linha invalida - Entre linha novamente\n");
		}
		
		sinal1=0;
		while(sinal1!=1)
		{
			printf("Coluna = \n");
			getchar();
			scanf("%c",&coluna);
			printf("\n");

            sinal1 = converteColunas(&coluna, &col);
	    }
	
		
		lin=linha-1;
										
		printf("Entre com a direcao: h-horizontal v-vertical\n");
		getchar();
		scanf("%c",&direcao);
		printf("\n");
		
		if(direcao=='h'||direcao=='H')				
		{
			flag=0;//Posicao horizontal
			
			sinal2=0;
			while(sinal2!=1)
			{
				printf("Entre com o tipo de navio:\nP-porta aviao\nG-navio de guerra\nC-cruzador\nS-submarino\nD-destruidor\nOpcao> ");
				getchar();
                scanf("%c",&tiponav);
				printf("\n");
				if(tiponav=='P'||tiponav=='p'||tiponav=='G'||tiponav=='g'||tiponav=='C'||tiponav=='c'||tiponav=='S'||tiponav=='s'||tiponav=='D'||tiponav=='d')
					sinal2=1;
				else
					printf("Navio invalido - Entre navio novamente\n");
			}	
					
			if(tiponav=='P'||tiponav=='p') {
				if(col>5)
					printf("Porta aviao ficou fora do tabuleiro so pode usar A-F\n");
				else
				{
					for(j=0;j<5;j++)
					{
						if(nav[lin][col+j]!='-') {
							flag=1;
                        }
					}
						
					if(flag==1)
						printf("posicao ocupada por Navio\n");
					else
					{
						for(j=0;j<5;j++) {
							nav[lin][col+j]='P';
                        }
						i=i+1;
						printf("Jogador %d\n",jogador);								
						mostratabuleiro(nav);
					}
				}
            }
			else
				if(tiponav=='G'||tiponav=='g') {
					if(col>6)
						printf("Navio de Guerra ficou fora do tabuleiro so pode usar A-G\n");
				
                    else
				    {
					    for(j=0;j<4;j++)
					    {
						    if(nav[lin][col+j]!='-')
							    flag=1;
					    }
						
					    if(flag==1)
						    printf("posicao ocupada por Navio\n");
					
                        else
					    {
						    for(j=0;j<4;j++)
							    nav[lin][col+j]='G';
										
						    i=i+1;
						    printf("Jogador %d\n",jogador);	
						    mostratabuleiro(nav);
					    }
				    }
                }
				else
					if(tiponav=='C'||tiponav=='c') {
						if(col>7)
							printf("Cruzador ficou fora do tabuleiro so pode usar A-H\n");
						else
						{
							for(j=0;j<3;j++)
							{
								if(nav[lin][col+j]!='-')
									flag=1;
							}
							
							if(flag==1)
								printf("posicao ocupada por Navio\n");
							else
							{
								for(j=0;j<3;j++)
							  		nav[lin][col+j]='C';
									
								i=i+1;
								printf("Jogador %d\n",jogador);
								mostratabuleiro(nav);
							}
						}
					}
					else
						if(tiponav=='S'||tiponav=='s') {
							if(col>7)
								printf("Submarino ficou fora do tabuleiro so pode usar A-H\n");
							else
								{
									for(j=0;j<3;j++)
									{
										if(nav[lin][col+j]!='-')
											flag=1;
									}
									
									if(flag==1)
										printf("posicao ocupada por Navio\n");
									else
									{
										for(j=0;j<3;j++)
											nav[lin][col+j]='S';
										
										i=i+1;
										printf("Jogador %d\n",jogador);
										mostratabuleiro(nav);
									}
								}
                        }
						else
							if(tiponav=='D'||tiponav=='d') {
								if(col==9)
									printf("Destruidor ficou fora do tabuleiro so pode usar A-I\n");
								else
									{
										for(j=0;j<2;j++)
										{
											if(nav[lin][col+j]!='-')
												flag=1;
										}
										
										if(flag==1)
											printf("posicao ocupada por Navio\n");
										else
										{
											for(j=0;j<2;j++)
												nav[lin][col+j]='D';
											
											i=i+1;
											printf("Jogador %d\n",jogador);
											mostratabuleiro(nav);
										}
									}
                            }
		}
		else
		{
			flag=0;//Posicao vertical
				
			sinal2=0;
			while(sinal2!=1)
			{
				printf("Entre com o tipo de navio:\nP-porta aviao\nG-navio de guerra\nC-cruzador\nS-submarino\nD-destruidor\nOpcao> ");
				scanf("%s",&tiponav);
				printf("\n");
				if(tiponav=='P'||tiponav=='p'||tiponav=='G'||tiponav=='g'||tiponav=='C'||tiponav=='c'||tiponav=='S'||tiponav=='s'||tiponav=='D'||tiponav=='d')
					sinal2=1;
				else
					printf("Navio invalido - Entre navio novamente \n");
			}
				
			if(tiponav=='P'||tiponav=='p')
				if(lin>5)
					printf("Porta aviao ficou fora do tabuleiro so pode usar linha de 1-6\n");
				else
				{
				    for(j=0;j<5;j++)
					{
						if(nav[lin+j][col]!='-')
							flag=1;
					}
								
					if(flag==1)
						printf("posicao ocupada por Navio\n");
					else
					{
						for(j=0;j<5;j++)
							nav[lin+j][col]='P';
								
						i=i+1;
						printf("Jogador %d\n",jogador);
						mostratabuleiro(nav);
					}
				}
				
				else
					if(tiponav=='G'||tiponav=='g')
						if(lin>6)
							printf("Navio de Guerra ficou fora do tabuleiro so pode usar linha 1=7\n");
					
                    else
					{
						for(j=0;j<4;j++)
						{
							if(nav[lin+j][col]!='-')
								flag=1;
						}
								
						if(flag==1)
							printf("posicao ocupada por Navio\n");
						
                        else
						{
							for(j=0;j<4;j++)
								nav[lin+j][col]='G';
									
							i=i+1;
							printf("Jogador %d\n",jogador);
							mostratabuleiro(nav);
						}
					}
                    else
						if(tiponav=='C'||tiponav=='c')
							if(lin>7)
								printf("Cruzador ficou fora do tabuleiro so pode usar linha de 1-8\n");
							else
							{
								for(j=0;j<3;j++)
								{
									if(nav[lin+j][col]!='-')
										flag=1;
								}
								
								if(flag==1)
									printf("posicao ocupada por Navio\n");
								else
								{
									for(j=0;j<3;j++)
										nav[lin+j][col]='C';
										
									i=i+1;
									printf("Jogador %d\n",jogador);
									mostratabuleiro(nav);
								}
							}
						else
							if(tiponav=='S'||tiponav=='s')
								if(lin>7)
									printf("Submarino ficou fora do tabuleiro so pode usar linha de 1-8\n");
								else
								{
									for(j=0;j<3;j++)
									{
										if(nav[lin+j][col]!='-')
											flag=1;
									}
								
									if(flag==1)
										printf("posicao ocupada por Navio\n");
									else
									{
										for(j=0;j<3;j++)
											nav[lin+j][col]='S';
											
										i=i+1;
										printf("Jogador %d\n",jogador);
										mostratabuleiro(nav);
									}
								}
							else
								if(tiponav=='D'||tiponav=='d')
									if(lin==9)
										printf("Destruidor ficou fora do tabuleiro so pode usar linha de 1-9\n");
									else
									{
										for(j=0;j<2;j++)
										{
											if(nav[lin+j][col]!='-')
												flag=1;
										}
								
										if(flag==1)
											printf("posicao ocupada por Navio\n");
										else
										{
											for(j=0;j<2;j++)
												nav[lin+j][col]='D';
												
											i=i+1;
											printf("Jogador %d\n",jogador);
											mostratabuleiro(nav);
										}
                                    }
		}
    }
}


/**
 * @brief Imprime o tabuleiro repassado por referência no parâmetro da função
 * 
 * @param navio : tabuleiro a ser impresso
 */
void mostratabuleiro(char **navio)
{
	int l,c;
	printf("\n   A B C D E F G H I J\n");
	for(l=0;l<10;l++)
	{
		printf("%d",l+1);
												
		if((l+1)!=10)
			printf("  ");
		else
			printf(" ");
													
		for(c=0;c<10;c++)
			printf("%c ",navio[l][c]);
											
		printf("\n");
	}
}


/**
 * @brief Verifica se uma embarcação foi destruída, assinala as 
 * embarcações destruídas em A no tabuleiro de tiros e contabiliza a quantidade de navios afundados,
 * repassando o valor no endereço recebido como parâmetro
 * 
 * @param navios : tabuleiro de embarcações
 * @param tiros : tabuleiro de tiros
 * @param navios_afundados : contador de navios afundados 
 */
void verificaDestruicao(char **navios, char **tiros, int *navios_afundados) {
        int cont, lin, col;
        //verifica as linhas para P
		cont=0;
		for(lin=0;lin<10;lin++)	{
            cont = 0;	
			for(col=0;col<10;col++) {
				if(navios[lin][col]=='P'&&tiros[lin][col]=='X') {
					cont=cont+1;
                }
                else if(cont > 0 && cont < 5) {
                    cont = 0;
                }
                if(cont == 5) {
                    tiros[lin][col]='A';
                    tiros[lin][col-1]='A';
                    tiros[lin][col-2]='A';
                    tiros[lin][col-3]='A';
                    tiros[lin][col-4]='A';
                    *navios_afundados=*navios_afundados+1;
                    cont = 0;
                }
            }
        }
        
        //verifica as colunas para P
        cont=0;
		for(col=0;col<10;col++)	{
            cont = 0;
			for(lin=0;lin<10;lin++) {
				if(navios[lin][col]=='P'&&tiros[lin][col]=='X') {
					cont=cont+1;
                }
                else if(cont > 0 && cont < 5) {
                    cont = 0;
                }
                if(cont == 5) {
                    tiros[lin][col]='A';
                    tiros[lin-1][col]='A';
                    tiros[lin-2][col]='A';
                    tiros[lin-3][col]='A';
                    tiros[lin-4][col]='A';
                    *navios_afundados=*navios_afundados+1;
                    cont = 0;
                }
            }
        }
		
		//verifica as linhas para G
		cont=0;
		for(lin=0;lin<10;lin++)	{
            cont = 0;	
			for(col=0;col<10;col++) {
				if(navios[lin][col]=='G'&&tiros[lin][col]=='X') {
					cont=cont+1;
                }
                else if(cont > 0 && cont < 4) {
                    cont = 0;
                }
                if(cont == 4) {
                    tiros[lin][col]='A';
                    tiros[lin][col-1]='A';
                    tiros[lin][col-2]='A';
                    tiros[lin][col-3]='A';
                    *navios_afundados=*navios_afundados+1;
                    cont = 0;
                }
            }
        }
        
        //verifica as colunas para G
        cont=0;
		for(col=0;col<10;col++)	{
            cont = 0;	
			for(lin=0;lin<10;lin++) {
				if(navios[lin][col]=='G'&&tiros[lin][col]=='X') {
					cont=cont+1;
                }
                else if(cont > 0 && cont < 4) {
                    cont = 0;
                }
                if(cont == 4) {
                    tiros[lin][col]='A';
                    tiros[lin-1][col]='A';
                    tiros[lin-2][col]='A';
                    tiros[lin-3][col]='A';
                    *navios_afundados=*navios_afundados+1;
                    cont = 0;
                }
            }
        }

        //verifica as linhas para C
		cont=0;
		for(lin=0;lin<10;lin++)	{	
            cont = 0;
			for(col=0;col<10;col++) {
				if(navios[lin][col]=='C'&&tiros[lin][col]=='X') {
					cont=cont+1;
                }
                else if(cont > 0 && cont < 3) {
                    cont = 0;
                }
                if(cont == 3) {
                    tiros[lin][col]='A';
                    tiros[lin][col-1]='A';
                    tiros[lin][col-2]='A';
                    *navios_afundados=*navios_afundados+1;
                    cont = 0;
                }
            }
        }
        
        //verifica as colunas para C
        cont=0;
		for(col=0;col<10;col++)	{
            cont = 0;
			for(lin=0;lin<10;lin++) {
				if(navios[lin][col]=='C'&&tiros[lin][col]=='X') {
					cont=cont+1;
                }
                else if(cont > 0 && cont < 3) {
                    cont = 0;
                }
                if(cont == 3) {
                    tiros[lin][col]='A';
                    tiros[lin-1][col]='A';
                    tiros[lin-2][col]='A';
                    *navios_afundados=*navios_afundados+1;
                    cont = 0;
                }
            }
        }

        //verifica as linhas para S
		cont=0;
		for(lin=0;lin<10;lin++)	{
            cont = 0;
			for(col=0;col<10;col++) {
				if(navios[lin][col]=='S'&&tiros[lin][col]=='X') {
					cont=cont+1;
                }
                else if(cont > 0 && cont < 3) {
                    cont = 0;
                }
                if(cont == 3) {
                    tiros[lin][col]='A';
                    tiros[lin][col-1]='A';
                    tiros[lin][col-2]='A';
                    *navios_afundados=*navios_afundados+1;
                    cont = 0;
                }
            }
        }
        
        //verifica as colunas para S
        cont=0;
		for(col=0;col<10;col++)	{
            cont = 0;
			for(lin=0;lin<10;lin++) {
				if(navios[lin][col]=='S'&&tiros[lin][col]=='X') {
					cont=cont+1;
                }
                else if(cont > 0 && cont < 3) {
                    cont = 0;
                }
                if(cont == 3) {
                    tiros[lin][col]='A';
                    tiros[lin-1][col]='A';
                    tiros[lin-2][col]='A';
                    *navios_afundados=*navios_afundados+1;
                    cont = 0;
                }
            }
        }
		
        //verifica as linhas para D
		cont=0;
		for(lin=0;lin<10;lin++)	{
            cont = 0;	
			for(col=0;col<10;col++) {
				if(navios[lin][col]=='D'&&tiros[lin][col]=='X') {
					cont=cont+1;
                }
                else if(cont > 0 && cont < 2) {
                    cont = 0;
                }
                if(cont == 2) {
                    tiros[lin][col]='A';
                    tiros[lin][col-1]='A';
                    *navios_afundados=*navios_afundados+1;
                    cont = 0;
                }
            }
        }
        
        //verifica as colunas para D
        cont=0;
		for(col=0;col<10;col++)	{
            cont = 0;	
			for(lin=0;lin<10;lin++) {
				if(navios[lin][col]=='D'&&tiros[lin][col]=='X') {
					cont=cont+1;
                }
                else if(cont > 0 && cont < 2) {
                    cont = 0;
                }
                if(cont == 2) {
                    tiros[lin][col]='A';
                    tiros[lin-1][col]='A';
                    *navios_afundados=*navios_afundados+1;
                    cont = 0;
                }
            }
        }

}


/**
 * @brief converte a coluna representada em caractere para o seu respectivo valor em inteiro,
 * repassando esse valor por meio do ponteiro *num_coluna. A função retorna 1 para sucesso e 0 para
 * falha;
 * 
 * @param coluna : char que representa a coluna de um tabuleiro
 * @param num_coluna : inteiro correspondente a coluna indicada em char nos parâmetros
 * @return int : 0 para falha e 1 para sucesso
 */
int converteColunas(char *coluna, int *num_coluna) {
    switch(*coluna){
        case 'A':
        case 'a':
            *num_coluna=0;
            break;
        case 'B':
        case 'b': 
            *num_coluna=1; 
            break;
        case 'C':
        case 'c': 
            *num_coluna=2; 
            break;
        case 'D':
        case 'd': 
            *num_coluna=3;
            break;
        case 'E':
        case 'e': 
            *num_coluna=4;
            break;
        case 'F':
        case 'f': 
            *num_coluna=5;
            break;
        case 'G':
        case 'g': 
            *num_coluna=6;
            break;
        case 'H':
        case 'h': 
            *num_coluna=7;
            break;
        case 'I':
        case 'i':  
            *num_coluna=8; 
            break;
        case 'J':
        case 'j': 
            *num_coluna=9; 
            break;
        default:
            printf("Coluna invalida - Entre coluna novamente\n");
            return 0;    
    }
    return 1;
}


/**
 * @brief executa os tiros de cada jogador, iniciando pelo jogador 1. 
 * Cada jogador tem 3 tiros por rodada. Os tiros na água são assinalados em O, no tabuleiro de tiros do jogador;
 * os tiros certeiros são assinados em X, no tabuleiro de tiros do jogador; embarcações destruídas são assinaladas
 * em A, no tabuleiro de tiros do jogador
 * 
 * @param nav1 : tabuleiro de embarcações do jogador 1
 * @param nav2 : tabuleiro de embarcações do jogador 2
 * @param tir1 : tabuleiro de tiros do jogador 1
 * @param tir2 : tabuleiro de tiros do jogador 2
 */
void atira(char **nav1,char **nav2,char **tir1,char **tir2)
{
	int linha11,linha21,linha31,lin11,lin21,lin31,col11,col21,col31,lin,col,teste;
	int sinal,sinal1;
	int afundoutudo=0,navafund1=0,navafund2=0;
	char coluna11,coluna21,coluna31;
	
	while(afundoutudo!=1)
	{
		printf("jogador 1 - tiros:\n");
		mostratabuleiro(nav1);
		printf("\n");
		mostratabuleiro(tir1);
		printf("Navios Afundados = %d\n\n",navafund1);
		
		printf("Marque o tiro da seguinte forma: O-agua X-fogo A-afundou\n");
		
		printf("Entre com as coordenadas dos tres tiros\n\n");
		
		teste=0;
		while(teste==0)
		{
			sinal=0;
			while(sinal==0)
			{
				printf("Entre com a linha e a coluna do primeiro tiro\n");
				printf("linha11=");
				scanf("%d",&linha11);
				if(linha11>=1&&linha11<=10)
					sinal=1;
				else
					printf("linha invalida - Entre linha novamente\n");
			}
				
			sinal1=0;
			while(sinal1==0)	
			{
				printf("coluna11=");
                getchar();
				scanf("%c",&coluna11);
				printf("\n");

                sinal1 = converteColunas(&coluna11, &col11);
			}
			
			lin11=linha11-1;
																	
			if((tir1[lin11][col11]=='A')||(tir1[lin11][col11]=='X')||(tir1[lin11][col11]=='O'))											
				printf("Posicao ocupada - tente novamente\n");
			else
			{
				if(nav2[lin11][col11]=='-')
					tir1[lin11][col11]='O';
				else
					tir1[lin11][col11]='X';
				teste=1;
			}
															
		}
		
		teste=0;
		while(teste==0)
		{
			sinal=0;
			while(sinal==0)
			{
				printf("Entre com a linha e a coluna do segundo tiro\n");
				printf("linha21=");
				scanf("%d",&linha21);
				if(linha21>=1&&linha21<=10)
					sinal=1;
				else
					printf("linha invalida - Entre linha novamente\n");
			}
			
			sinal1=0;
			while(sinal1==0)	
			{
				printf("coluna21=");
                getchar();
				scanf("%c",&coluna21);
				printf("\n");

                sinal1 = converteColunas(&coluna21, &col21);
			}
			
			lin21=linha21-1;
													
			if((tir1[lin21][col21]=='A')||(tir1[lin21][col21]=='X')||(tir1[lin21][col21]=='O'))											
				printf("Posicao ocupada - tente novamente\n");
			else
			{
				if(nav2[lin21][col21]=='-')
					tir1[lin21][col21]='O';
				else
					tir1[lin21][col21]='X';
				teste=1;
			}
		}
		
		teste=0;
		while(teste==0)
		{
			sinal=0;
			while(sinal==0)
			{
				printf("Entre com a linha e a coluna do terceiro tiro\n");
				printf("linha31=");
				scanf("%d",&linha31);
				if(linha31>=1&&linha31<=10)
					sinal=1;
				else
					printf("linha invalida - Entre linha novamente\n");
			}
			
			sinal1=0;
			while(sinal1==0)	
			{
				printf("coluna31=");
                getchar();
				scanf("%c",&coluna31);
				printf("\n");

                sinal1 = converteColunas(&coluna31, &col31);
			}
			
			lin31=linha31-1;

            printf("%d", lin31);
            printf("%d", col31);										
			if((tir1[lin31][col31]=='A')||(tir1[lin31][col31]=='X')||(tir1[lin31][col31]=='O'))											
				printf("Posicao ocupada - tente novamente\n");
			else
			{
				if(nav2[lin31][col31]=='-')
					tir1[lin31][col31]='O';
				else
					tir1[lin31][col31]='X';
				teste=1;
			}
		}

        verificaDestruicao(nav2, tir1, &navafund1);

		printf("jogador 1 - result\n");
		mostratabuleiro(nav1);
		printf("\n");			
		mostratabuleiro(tir1);
		printf("Navios Afundados = %d\n\n",navafund1);
		
		if(navafund1==5)
		{
			afundoutudo=1;
			printf("O jogador 1 e o vencedor\n");
		}	
		
		if(afundoutudo!=1)
		{
			escolheTiro(nav1, tir2, &navafund2);
			
			printf("Computador - result\n");
			mostratabuleiro(nav2);
			printf("\n");			
			mostratabuleiro(tir2);
			printf("Navios Afundados = %d\n\n",navafund2);
			
			if(navafund2==5)
			{
				afundoutudo=1;
				printf("Computador e o vencedor\n");
			}		
		}	
	}
}