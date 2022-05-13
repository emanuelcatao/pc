#include <stdio.h>									
#include <stdlib.h>	

void posiciona(char **nav,int jogador);		
void mostratabuleiro(char **nav1);
void atira(char **nav1,char **nav2,char **tir1,char **tir2);

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
	
	printf("Posiciona navios Jogador 1\n\n");
	posiciona(navios1,1);
	
	printf("\n");
	printf("Posiciona navios Jogador 2\n\n");
	posiciona(navios2,2);
	
	printf("\n\n");
	printf("Inicia os tiros\n");	
	atira(navios1,navios2,tiros1,tiros2);
	
	return 0;
}

/**
 * @brief Posiciona as 5 embarcações no tabuleiro do jogador repassado no parâmetro
 * 
 * @param nav : matriz de caracteres que representa o tabuleiro do jogador
 * @param jogador : jogador, representado por inteiro, que irá posicionar suas embarcações 
 */
void posiciona(char **nav,int jogador)
{
	int linha = 0,lin,col,i=0,j,l,c,flag,sinal,sinal1,sinal2;
	char coluna,direcao,tiponav;
	
	printf("Entre com as coordenadas para posicionamento dos navios: Linha->1-10 Coluna->A-J");
	
	printf("Jogador %d\n",jogador);	
	mostratabuleiro(nav);
	
	while(i<5)
	{
		sinal=0;
		while(sinal!=1)
		{
			printf("Entre com a linha=");
			scanf("%d", &linha);

			if(linha<=10 && linha>=1)
				sinal=1;
			else
				printf("Linha invalida - Entre linha novamente\n");
		}
		
		sinal1=0;
		while(sinal1!=1)
		{
			printf("Entre com a coluna=");
            getchar();
			scanf("%c",&coluna);
			printf("\n");

            switch(coluna){
		        case 'A':
		        case 'a':
                    col=0;
                    sinal1=1;
                    break;
		        case 'B':
		        case 'b': 
                    col=1;
                    sinal1=1; 
                    break;
		        case 'C':
		        case 'c': 
                    col=2; 
                    sinal1=1;
                    break;
		        case 'D':
		        case 'd': 
                    col=3;
                    sinal1=1;
                    break;
		        case 'E':
		        case 'e': 
                    col=4;
                    sinal1=1;
                    break;
		        case 'F':
		        case 'f': 
                    col=5;
                    sinal1=1;
                    break;
                case 'G':
		        case 'g': 
                    col=6;
                    sinal1=1; 
                    break;
                case 'H':
		        case 'h': 
                    col=7;
                    sinal1=1;
                    break;
                case 'I':
		        case 'i':  
                    col=8; 
                    sinal1=1;
                    break;
                case 'J':
		        case 'j': 
                    col=9;
                    sinal1=1; 
                    break;
                default:
                    printf("Coluna invalida - Entre coluna novamente\n");
                    break;
            }
	    }
	
		
		lin=linha-1;
										
		printf("Entre com a direcao: h-horizontal v-vertical\n");
		scanf("%s",&direcao);
		printf("\n");
		
		if(direcao=='h'||direcao=='H')				
		{
			flag=0;//Posicao horizontal
			
			sinal2=0;
			while(sinal2!=1)
			{
				printf("Entre com o tipo de navio: P-porta aviao G-navio de guerra C-cruzador S-submarino D-destruidor\n");
				scanf("%s",&tiponav);
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
                        printf("%d\n", lin);
                        printf("%d\n", col);
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
				printf("Entre com o tipo de navio: P-porta aviao G-navio de guerra C-cruzador S-submarino D-destruidor\n");
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
 * @brief Imprime o tabuleiro repassado como parâmetro
 * 
 * @param navio : tabuleiro a ser impresso
 */
void mostratabuleiro(char **navio)
{
	int l,c;
	printf("   A B C D E F G H I J\n");
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
 * @brief 
 * 
 * @param nav1 
 * @param nav2 
 * @param tir1 
 * @param tir2 
 */
void atira(char **nav1,char **nav2,char **tir1,char **tir2)
{
	int linha11,linha21,linha31,lin11,lin21,lin31,col11,col21,col31,lin,col,cont,teste;
	int linha12,linha22,linha32,lin12,lin22,lin32,col12,col22,col32,sinal,sinal1;
	int afundoutudo=0,navafund1=0,navafund2=0;
	char coluna11,coluna21,coluna31,coluna12,coluna22,coluna32;
	
	while(afundoutudo!=1)
	{
		printf("jogador 1\n");
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

                switch(coluna11){
		        case 'A':
		        case 'a':
                    col11=0;
                    sinal1=1;
                    break;
		        case 'B':
		        case 'b': 
                    col11=1;
                    sinal1=1; 
                    break;
		        case 'C':
		        case 'c': 
                    col11=2; 
                    sinal1=1;
                    break;
		        case 'D':
		        case 'd': 
                    col11=3;
                    sinal1=1;
                    break;
		        case 'E':
		        case 'e': 
                    col11=4;
                    sinal1=1;
                    break;
		        case 'F':
		        case 'f': 
                    col11=5;
                    sinal1=1;
                    break;
                case 'G':
		        case 'g': 
                    col11=6;
                    sinal1=1; 
                    break;
                case 'H':
		        case 'h': 
                    col11=7;
                    sinal1=1;
                    break;
                case 'I':
		        case 'i':  
                    col11=8; 
                    sinal1=1;
                    break;
                case 'J':
		        case 'j': 
                    col11=9;
                    sinal1=1; 
                    break;
                default:
                    printf("Coluna invalida - Entre coluna novamente\n");
                    break;
                }
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

                switch(coluna21){
                    case 'A':
                    case 'a':
                        col21=0;
                        sinal1=1;
                        break;
                    case 'B':
                    case 'b': 
                        col21=1;
                        sinal1=1; 
                        break;
                    case 'C':
                    case 'c': 
                        col21=2; 
                        sinal1=1;
                        break;
                    case 'D':
                    case 'd': 
                        col21=3;
                        sinal1=1;
                        break;
                    case 'E':
                    case 'e': 
                        col21=4;
                        sinal1=1;
                        break;
                    case 'F':
                    case 'f': 
                        col21=5;
                        sinal1=1;
                        break;
                    case 'G':
                    case 'g': 
                        col21=6;
                        sinal1=1; 
                        break;
                    case 'H':
                    case 'h': 
                        col21=7;
                        sinal1=1;
                        break;
                    case 'I':
                    case 'i':  
                        col21=8; 
                        sinal1=1;
                        break;
                    case 'J':
                    case 'j': 
                        col21=9;
                        sinal1=1; 
                        break;
                    default:
                        printf("Coluna invalida - Entre coluna novamente\n");
                        break;
                }
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

                switch(coluna31){
                    case 'A':
                    case 'a':
                        col31=0;
                        sinal1=1;
                        break;
                    case 'B':
                    case 'b': 
                        col31=1;
                        sinal1=1; 
                        break;
                    case 'C':
                    case 'c': 
                        col31=2; 
                        sinal1=1;
                        break;
                    case 'D':
                    case 'd': 
                        col31=3;
                        sinal1=1;
                        break;
                    case 'E':
                    case 'e': 
                        col31=4;
                        sinal1=1;
                        break;
                    case 'F':
                    case 'f': 
                        col31=5;
                        sinal1=1;
                        break;
                    case 'G':
                    case 'g': 
                        col31=6;
                        sinal1=1; 
                        break;
                    case 'H':
                    case 'h': 
                        col31=7;
                        sinal1=1;
                        break;
                    case 'I':
                    case 'i':  
                        col31=8; 
                        sinal1=1;
                        break;
                    case 'J':
                    case 'j': 
                        col31=9;
                        sinal1=1; 
                        break;
                    default:
                        printf("Coluna invalida - Entre coluna novamente\n");
                        break;
                }
			}
					
			lin31=linha31-1;
													
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
		
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='P'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==5)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='P')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
		
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='G'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==4)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='G')
						tir1[lin][col]='A';		
			navafund1=navafund1+1;
		}
		
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='C'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==3)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='C')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
		
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='S'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==3)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='S')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
						
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='D'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==2)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='D')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
		
		printf("jogador 1\n");
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
			printf("jogador 2\n");
			mostratabuleiro(nav2);
			printf("\n");
			mostratabuleiro(tir2);
			printf("Navios Afundados = %d\n\n",navafund2);
			
			printf("Marque o tiro da seguinte forma: O-agua X-fogo A-afundou\n");
			
			printf("Entre com as coordenadas dos tres tiros\n");
			
			teste=0;
			while(teste==0)
			{
				sinal=0;
				while(sinal==0)
				{
					printf("Entre com a linha e a coluna do primeiro tiro\n");
					printf("linha12=");
					scanf("%d",&linha12);
					if(linha12>=1&&linha12<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					printf("coluna12=");
                    getchar();
					scanf("%c",&coluna12);
					printf("\n");

                    switch(coluna12){
                        case 'A':
                        case 'a':
                            col12=0;
                            sinal1=1;
                            break;
                        case 'B':
                        case 'b': 
                            col12=1;
                            sinal1=1; 
                            break;
                        case 'C':
                        case 'c': 
                            col12=2; 
                            sinal1=1;
                            break;
                        case 'D':
                        case 'd': 
                            col12=3;
                            sinal1=1;
                            break;
                        case 'E':
                        case 'e': 
                            col12=4;
                            sinal1=1;
                            break;
                        case 'F':
                        case 'f': 
                            col12=5;
                            sinal1=1;
                            break;
                        case 'G':
                        case 'g': 
                            col12=6;
                            sinal1=1; 
                            break;
                        case 'H':
                        case 'h': 
                            col12=7;
                            sinal1=1;
                            break;
                        case 'I':
                        case 'i':  
                            col12=8; 
                            sinal1=1;
                            break;
                        case 'J':
                        case 'j': 
                            col12=9;
                            sinal1=1; 
                            break;
                        default:
                            printf("Coluna invalida - Entre coluna novamente\n");
                            break;    
                    }
                }
				
				lin12=linha12-1;
															
				if((tir2[lin12][col12]=='A')||(tir2[lin12][col12]=='X')||(tir2[lin12][col12]=='O'))											
					printf("Posicao ocupada - tente novamente\n");
				else
				{
					if(nav1[lin12][col12]=='-')
						tir2[lin12][col12]='O';
					else
						tir2[lin12][col12]='X';
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
					printf("linha22=");
					scanf("%d",&linha22);
					if(linha22>=1&&linha22<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					printf("coluna22=");
                    getchar();
					scanf("%c",&coluna22);
					printf("\n");

                    switch(coluna22){
                        case 'A':
                        case 'a':
                            col22=0;
                            sinal1=1;
                            break;
                        case 'B':
                        case 'b': 
                            col22=1;
                            sinal1=1; 
                            break;
                        case 'C':
                        case 'c': 
                            col22=2; 
                            sinal1=1;
                            break;
                        case 'D':
                        case 'd': 
                            col22=3;
                            sinal1=1;
                            break;
                        case 'E':
                        case 'e': 
                            col22=4;
                            sinal1=1;
                            break;
                        case 'F':
                        case 'f': 
                            col22=5;
                            sinal1=1;
                            break;
                        case 'G':
                        case 'g': 
                            col22=6;
                            sinal1=1; 
                            break;
                        case 'H':
                        case 'h': 
                            col22=7;
                            sinal1=1;
                            break;
                        case 'I':
                        case 'i':  
                            col22=8; 
                            sinal1=1;
                            break;
                        case 'J':
                        case 'j': 
                            col22=9;
                            sinal1=1; 
                            break;
                        default:
                            printf("Coluna invalida - Entre coluna novamente\n");
                            break;
                    }
				}
				
				lin22=linha22-1;
														
				if((tir2[lin22][col22]=='A')||(tir2[lin22][col22]=='X')||(tir2[lin22][col22]=='O'))											
					printf("Posicao ocupada - tente novamente\n");
				else
				{
					if(nav1[lin22][col22]=='-')
						tir2[lin22][col22]='O';
					else
						tir2[lin22][col22]='X';
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
					printf("linha32=");
					scanf("%d",&linha32);
					if(linha32>=1&&linha32<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					printf("coluna32=");
                    getchar();			
					scanf("%c",&coluna32);
					printf("\n");

                    switch(coluna32){
                        case 'A':
                        case 'a':
                            col32=0;
                            sinal1=1;
                            break;
                        case 'B':
                        case 'b': 
                            col32=1;
                            sinal1=1; 
                            break;
                        case 'C':
                        case 'c': 
                            col32=2; 
                            sinal1=1;
                            break;
                        case 'D':
                        case 'd': 
                            col32=3;
                            sinal1=1;
                            break;
                        case 'E':
                        case 'e': 
                            col32=4;
                            sinal1=1;
                            break;
                        case 'F':
                        case 'f': 
                            col32=5;
                            sinal1=1;
                            break;
                        case 'G':
                        case 'g': 
                            col32=6;
                            sinal1=1; 
                            break;
                        case 'H':
                        case 'h': 
                            col32=7;
                            sinal1=1;
                            break;
                        case 'I':
                        case 'i':  
                            col32=8; 
                            sinal1=1;
                            break;
                        case 'J':
                        case 'j': 
                            col32=9;
                            sinal1=1; 
                            break;
                        default:
                            printf("Coluna invalida - Entre coluna novamente\n");
                            break;
                    }
				}
						
				lin32=linha32-1;
														
				if((tir2[lin32][col32]=='A')||(tir2[lin32][col32]=='X')||(tir2[lin32][col32]=='O'))											
					printf("Posicao ocupada - tente novamente\n");
				else
				{
					if(nav1[lin32][col32]=='-')
						tir2[lin32][col32]='O';
					else
						tir2[lin32][col32]='X';
					teste=1;
				}
			}
						
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='P'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==5)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='P')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}
			
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='G'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==4)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='G')
							tir2[lin][col]='A';		
				navafund2=navafund2+1;
			}
			
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='C'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==3)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='C')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}
			
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='S'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==3)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='S')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}
							
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='D'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==2)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='D')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}
			
			printf("jogador 2\n");
			mostratabuleiro(nav2);
			printf("\n");			
			mostratabuleiro(tir2);
			printf("Navios Afundados = %d\n\n",navafund2);
			
			if(navafund2==5)
			{
				afundoutudo=1;
				printf("O jogador 2 e o vencedor\n");
			}		
		}	
	}
}