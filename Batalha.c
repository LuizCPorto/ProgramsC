#include <stdio.h>									
#include <stdlib.h>	
#include <time.h>	
#define MAX 5 																			
void posiciona(char **nav,int jogador);			
void mostratabuleiro(char **nav1);
void atira(char **nav1,char **nav2,char **tir1,char **tir2);

int main(){
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
	posiciona(navios2,2);
	
	printf("\n\n");
	printf("Inicia os tiros\n");	
	atira(navios1,navios2,tiros1,tiros2);
	
	return 0;
}

void posiciona(char **nav,int jogador){
	int linha,lin,col,i=0,j,l,c,flag,sinal,sinal1,sinal2,tnav,d;
	char coluna,direcao,tiponav,mod_nav[MAX];
	
	if (jogador == 1){ 
		printf("Entre com as coordenadas para posicionamento dos navios: Linha->1-10 Coluna->A-J");
		printf("Jogador 1\n");	
		mostratabuleiro(nav);
	while(i<MAX){
		sinal=0;
		while(sinal!=1)
		{
			printf("Entre com a linha=");
			scanf("%d",&linha);
			if(linha<=10&&linha>=1){
				sinal=1;
			}
			else{
				printf("Linha invalida - Entre linha novamente\n");
			}
		}
		
		sinal1=0;
		while(sinal1!=1)
		{
			printf("Entre com a coluna=");
			fflush(stdin);
			scanf("%c", &coluna);
			putchar('\n');
			if(coluna=='A'||coluna=='a'||coluna=='B'||coluna=='b'||coluna=='C'||coluna=='c'||coluna=='D'||coluna=='d'||coluna=='E'||coluna=='e'||coluna=='F'||coluna=='f'||coluna=='G'||coluna=='g'||coluna=='H'||coluna=='h'||coluna=='I'||coluna=='i'||coluna=='J'||coluna=='j'){
				sinal1=1;
			}else{
				printf("Coluna invalida - Entre coluna novamente\n");
			}
		}

		lin=linha-1;	

		if(coluna=='A'||coluna=='a'){
			col=0;
		}else
			if(coluna=='B'||coluna=='b'){
				col=1;
			}else
				if(coluna=='C'||coluna=='c'){
					col=2;
				}else
					if(coluna=='D'||coluna=='d'){
						col=3;
					}else
						if(coluna=='E'||coluna=='e'){
							col=4;
						}else
							if(coluna=='F'||coluna=='f'){
								col=5;
							}else
								if(coluna=='G'||coluna=='g'){
									col=6;
								}else
									if(coluna=='H'||coluna=='h'){
										col=7;
									}else
										if(coluna=='I'||coluna=='i'){
											col=8;
										}else
											if(coluna=='J'||coluna=='j'){
												col=9;
											}
		d = 0;
		while (d != 1){
			printf("Entre com a direcao: h-horizontal v-vertical\n");
			fflush(stdin);
			scanf("%c",&direcao);
			if (direcao=='H'||direcao=='h'||direcao=='V'||direcao=='v'){
				d=1;
			}else {
				printf("Essa direcao nao existe, por favor entre apenas com H ou V.\n");
			}
			
			
		}

		if(direcao=='H'||direcao=='h'){
			
			flag=0;
			
			sinal2=0;
			 while(!sinal2){   
            	printf("Lembre-se de escolher tipos diferentes de navios.\n");
                printf("Entre com o tipo de navio: P-porta aviao G-navio de guerra C-cruzador S-submarino D-destruidor\n");
                fflush(stdin);
                scanf("%c",&tiponav);
                printf("\n");
                if(i>=1){
                    for(j=0;j<i;){
                        if ( mod_nav[j]!=tiponav){
                            j++;
                        }else{
                           j=i+1; 
                        } 
                            
                    }
                        if(j==i){
                            mod_nav[i] = tiponav;
                            sinal2=1;
                        }
                        else if(j>i){
                            printf("Esse navio já foi escolhido por favor escolha outro navio.\n");
                            sinal2=0;
                        }
                    }
				
                    else{
                        if(tiponav=='P'||tiponav=='p'||tiponav=='G'||tiponav=='g'||tiponav=='C'||tiponav=='c'||tiponav=='S'||tiponav=='s'||tiponav=='D'||tiponav=='d'){
                            mod_nav[i] = tiponav;
                            sinal2=1;
                        }
                        else{
                            printf("Navio invalido - Entre navio novamente\n");
                        }
				    }
                }
                        
                        
                if(tiponav=='P'||tiponav=='p'){
                    if(col>5){
                        printf("Porta aviao ficou fora do tabuleiro so pode usar A-F\n");
                    }else{
                        for(j=0;j<5;j++)
                        {
                            if(nav[lin][col+j]!='-')
                                flag=1;
                        }
                            
                        if(flag==1){
                            printf("posicao ocupada por Navio\n");
                        }else{
                            for(j=0;j<5;j++){
                                nav[lin][col+j]='P';
                            }     
                            i=i+1;
                            printf("Jogador %d\n",jogador);
                            mostratabuleiro(nav);
                            
                        }
                    }
                }
                else if(tiponav=='G'||tiponav=='g'){
                        if(col>6){
                            printf("Navio de Guerra ficou fora do tabuleiro so pode usar A-G\n");
                        }else{
                            for(j=0;j<4;j++){
                                if(nav[lin][col+j]!='-'){
									flag=1;
                                }
                            }
                            
                            if(flag==1){
                                printf("posicao ocupada por Navio\n");
                            }else{
                                for(j=0;j<4;j++){
                                    nav[lin][col+j]='G';
                                }            
                                i=i+1;
                                
                                printf("Jogador %d\n",jogador);
                                mostratabuleiro(nav);
                            }
                        }
                }
                else if(tiponav=='C'||tiponav=='c'){
                    if(col>7){
                        printf("Cruzador ficou fora do tabuleiro so pode usar A-H\n");
                    }
                    else{
                        for(j=0;j<3;j++){
                            if(nav[lin][col+j]!='-'){
                            	flag=1;
							}
                        }
                                
                        if(flag==1){
                            printf("posicao ocupada por Navio\n");
                        }else{
                            for(j=0;j<3;j++){
                                nav[lin][col+j]='C';
                            }           
                            i=i+1;
                                    
                            printf("Jogador %d\n",jogador);
                            mostratabuleiro(nav);
                                    
                        }
                    }
                }
                else if(tiponav=='S'||tiponav=='s'){
                    if(col>7){
                        printf("Submarino ficou fora do tabuleiro so pode usar A-H\n");
                    }else{
                        for(j=0;j<3;j++){
                            if(nav[lin][col+j]!='-'){
                                flag=1;
                            }
                        }
                                        
                        if(flag==1){
                            printf("posicao ocupada por Navio\n");
                        }else{
                            for(j=0;j<3;j++){
                            nav[lin][col+j]='S';
                            }               
                            i=i+1;
                                            
                            printf("Jogador %d\n",jogador);
                            mostratabuleiro(nav);
                                           
                        }
                    }
                }
                    else if(tiponav=='D'||tiponav=='d'){
                        if(col==9){
                            printf("Destruidor ficou fora do tabuleiro so pode usar A-I\n");
                        }else{
                            for(j=0;j<2;j++){
                                if(nav[lin][col+j]!='-'){
                                    flag=1;
                                }
                            }
                                            
                            if(flag==1){
                                printf("posicao ocupada por Navio\n");
                            }else{
                                for(j=0;j<2;j++){
                                    nav[lin][col+j]='D';
                                }    

                                i=i+1;
                                printf("Jogador %d\n",jogador);
                                mostratabuleiro(nav);
                                
                            }
                        }
                    }
		}
		else if (direcao=='V'||direcao=='v'){
				
				flag=0;
				
				sinal2=0;
				while(sinal2!=1){
            		printf("Lembre-se de escolher tipos diferentes de navios.\n");
					printf("Entre com o tipo de navio: P-porta aviao G-navio de guerra C-cruzador S-submarino D-destruidor\n");
					fflush(stdin);
					scanf("%c",&tiponav);
					printf("\n");
					if(i>=1){
                    	for(j=0;j<i;){
                        	if ( mod_nav[j]!=tiponav){
                            	j++;
                        }else{
                           j=i+1; 
                        } 
                            
                    }
                        if(j==i){
                            mod_nav[i] = tiponav;
                            sinal2=1;
                        }
                        else if(j>i){
                            printf("Esse navio já foi escolhido por favor escolha outro navio.\n");
                            sinal2=0;
                        }
                    }else{
                        if(tiponav=='P'||tiponav=='p'||tiponav=='G'||tiponav=='g'||tiponav=='C'||tiponav=='c'||tiponav=='S'||tiponav=='s'||tiponav=='D'||tiponav=='d'){
                            mod_nav[i] = tiponav;
                            sinal2=1;
                        }else{
                            printf("Navio invalido - Entre navio novamente\n");
                        }
                    }
				}

                if(tiponav=='P'||tiponav=='p'){
                    if(col>5){
                        printf("Porta aviao ficou fora do tabuleiro so pode usar A-F\n");
                    }else{
                        for(j=0;j<5;j++){
                            if(nav[lin+j][col]!='-'){
                                flag=1;
							}
                        }
                            
                        if(flag==1){
                            printf("posicao ocupada por Navio\n");
                        }else{
                            for(j=0;j<5;j++){
                                nav[lin+j][col]='P';
                            }     
                            i=i+1;
                            printf("\n\tJogador %d\n\n",jogador);
                            mostratabuleiro(nav);
                            
                        }
                    }
                }
                else if(tiponav=='G'||tiponav=='g'){
                        if(col>6){
                            printf("Navio de Guerra ficou fora do tabuleiro so pode usar A-G\n");
                        }
                        else{

                            for(j=0;j<4;j++)
                            {
                                if(nav[lin+j][col]!='-')
                                    {flag=1;
                                }
                            }
                            
                            if(flag==1){
                                printf("posicao ocupada por Navio\n");
                            }
                            else
                            {
                                for(j=0;j<4;j++){
                                    nav[lin+j][col]='G';
                                }            
                                i=i+1;
                                
                                printf("\n\tJogador %d\n\n",jogador);
                                mostratabuleiro(nav);
                            }
                        }
                }
                else if(tiponav=='C'||tiponav=='c'){
                    if(col>7){
                        printf("Cruzador ficou fora do tabuleiro so pode usar A-H\n");
                    }
                    else
                    {
                        for(j=0;j<3;j++)
                        {
                            if(nav[lin+j][col]!='-')
                            flag=1;
                        }
                                
                        if(flag==1){
                            printf("posicao ocupada por Navio\n");
                        }
                        else
                        {
                            for(j=0;j<3;j++){
                                nav[lin+j][col]='C';
                            }           
                            i=i+1;
                                    
                            printf("\n\tJogador %d\n\n",jogador);
                            mostratabuleiro(nav);
                                    
                        }
                    }
                }
                else if(tiponav=='S'||tiponav=='s'){
                    if(col>7){
                        printf("Submarino ficou fora do tabuleiro so pode usar A-H\n");
                    }else{
                        for(j=0;j<3;j++)
                        {
                            if(nav[lin+j][col]!='-'){
                                flag=1;
                            }
                        }
                                        
                        if(flag==1){
                            printf("posicao ocupada por Navio\n");
                        }else{
                            for(j=0;j<3;j++){
                            nav[lin+j][col]='S';
                            }               
                            i=i+1;
                                            
                            printf("\n\tJogador %d\n\n",jogador);
                            mostratabuleiro(nav);
                                           
                        }
                    }
                }
                    else if(tiponav=='D'||tiponav=='d'){
                        if(col==9){
                            printf("Destruidor ficou fora do tabuleiro so pode usar A-I\n");
                        }
                        else{
                            for(j=0;j<2;j++)
                            {
                                if(nav[lin+j][col]!='-'){
                                    flag=1;
                                }
                            }
                                            
                            if(flag==1){
                                printf("posicao ocupada por Navio\n");
                            }else{
                                for(j=0;j<2;j++){
                                    nav[lin+j][col]='D';
                                }                
                                i=i+1;
                                printf("\n\tJogador %d\n\n",jogador);
                                mostratabuleiro(nav);
                                
                            }
                        }
                    }
			}
		
	
	}
	}
	else if (jogador == 2){	
		mostratabuleiro(nav);
		srand(time(NULL));
		int n=0;
		i=0;
		while (i<MAX){
			sinal = 0;
			while (sinal!=1){
				while (n == 0){
					n = rand()%10;
				}
				linha = n;
				n = 0;
				sinal=1;
			}

		sinal1=0;
		while(sinal1!=1)
		{
			coluna = 'a' + (char)(rand()%10);
			putchar('\n');
			if(coluna=='a'||coluna=='b'||coluna=='c'||coluna=='d'||coluna=='e'||coluna=='f'||coluna=='g'||coluna=='h'||coluna=='i'||coluna=='j'){
				sinal1=1;
			}
		}

		lin=linha-1;	

		if(coluna=='a'){
			col=0;
		}else
			if(coluna=='b'){
				col=1;
			}else
				if(coluna=='c'){
					col=2;
				}else
					if(coluna=='d'){
						col=3;
					}else
						if(coluna=='e'){
							col=4;
						}else
							if(coluna=='f'){
								col=5;
							}else
								if(coluna=='g'){
									col=6;
								}else
									if(coluna=='h'){
										col=7;
									}else
										if(coluna=='i'){
											col=8;
										}else
											if(coluna=='j'){
												col=9;
											}
		d = 0;
		while (d != 1){
			direcao = 'a' + (char)(rand()%2);
			if (direcao=='a'||direcao=='b'){
				d=1;
			}		
		}

		if(direcao=='a'){
			
			flag=0;
			
			sinal2=0;
			 while(!sinal2){   
				tiponav = 'a' + (char)(rand()%5);
                printf("\n");
                if(i>=1){
                    for(j=0;j<i;){
                        if ( mod_nav[j]!=tiponav){
                            j++;
                        }else{
                           j=i+1; 
                        } 
                            
                    }
                        if(j==i){
                            mod_nav[i] = tiponav;
                            sinal2=1;
                        }
                        else if(j>i){
                           sinal2=0;
                        }
                    }
				
                    else{
                        if(tiponav=='a'||tiponav=='b'||tiponav=='c'||tiponav=='d'||tiponav=='e'){
                            mod_nav[i] = tiponav;
                            sinal2=1;
                        }
				    }
                }
                        
                        
                if(tiponav=='a'){
                    if(col>5){
                        printf("\n");
                    }else{
                        for(j=0;j<5;j++)
                        {
                            if(nav[lin][col+j]!='-')
                                flag=1;
                        }
                            
                        if(flag==1){
                            printf("\n");
                        }else{
                            for(j=0;j<5;j++){
                                nav[lin][col+j]='P';
                            }     
                            i=i+1;
                            printf("Jogador %d\n",jogador);
                            mostratabuleiro(nav);
                            
                        }
                    }
                }
                else if(tiponav=='b'){
                        if(col>6){
                            printf("\n");
                        }else{
                            for(j=0;j<4;j++){
                                if(nav[lin][col+j]!='-'){
									flag=1;
                                }
                            }
                            
                            if(flag==1){
                                printf("\n");
                            }else{
                                for(j=0;j<4;j++){
                                    nav[lin][col+j]='G';
                                }            
                                i=i+1;
                                
                                printf("Jogador %d\n",jogador);
                                mostratabuleiro(nav);
                            }
                        }
                }
                else if(tiponav=='c'){
                    if(col>7){
                        printf("\n");
                    }
                    else{
                        for(j=0;j<3;j++){
                            if(nav[lin][col+j]!='-'){
                            	flag=1;
							}
                        }
                                
                        if(flag==1){
                            printf("\n");
                        }else{
                            for(j=0;j<3;j++){
                                nav[lin][col+j]='C';
                            }           
                            i=i+1;
                                    
                            printf("Jogador %d\n",jogador);
                            mostratabuleiro(nav);
                                    
                        }
                    }
                }
                else if(tiponav=='d'){
                    if(col>7){
                        printf("\n");
                    }else{
                        for(j=0;j<3;j++){
                            if(nav[lin][col+j]!='-'){
                                flag=1;
                            }
                        }
                                        
                        if(flag==1){
                            printf("\n");
                        }else{
                            for(j=0;j<3;j++){
                            nav[lin][col+j]='S';
                            }               
                            i=i+1;
                                            
                            printf("Jogador %d\n",jogador);
                            mostratabuleiro(nav);
                                           
                        }
                    }
                }
                    else if(tiponav=='e'){
                        if(col==9){
                            printf("\n");
                        }else{
                            for(j=0;j<2;j++){
                                if(nav[lin][col+j]!='-'){
                                    flag=1;
                                }
                            }
                                            
                            if(flag==1){
                                printf("\n");
                            }else{
                                for(j=0;j<2;j++){
                                    nav[lin][col+j]='D';
                                }    

                                i=i+1;
                                printf("Jogador %d\n",jogador);
                                mostratabuleiro(nav);
                                
                            }
                        }
                    }
		}
		else if (direcao=='b'){
				
				flag=0;
				
				sinal2=0;
				while(sinal2!=1){
					tiponav = 'a' + (char)(rand()%5);
					printf("\n");
					if(i>=1){
                    	for(j=0;j<i;){
                        	if ( mod_nav[j]!=tiponav){
                            	j++;
                        }else{
                           j=i+1; 
                        } 
                            
                    }
                        if(j==i){
                            mod_nav[i] = tiponav;
                            sinal2=1;
                        }
                        else if(j>i){
                            sinal2=0;
                        }
                    }else{
                        if(tiponav=='a'||tiponav=='b'||tiponav=='c'||tiponav=='d'||tiponav=='e'){
                            mod_nav[i] = tiponav;
                            sinal2=1;
                        }
                    }
				}

                if(tiponav=='a'){
                    if(col>5){
                        printf("\n");
                    }else{
                        for(j=0;j<5;j++){
                            if(nav[lin+j][col]!='-'){
                                flag=1;
							}
                        }
                            
                        if(flag==1){
                            printf("\n");
                        }else{
                            for(j=0;j<5;j++){
                                nav[lin+j][col]='P';
                            }     
                            i=i+1;
                            printf("\n\tJogador %d\n\n",jogador);
                            mostratabuleiro(nav);
                            
                        }
                    }
                }
                else if(tiponav=='b'){
                        if(col>6){
                            printf("\n");
                        }
                        else{

                            for(j=0;j<4;j++)
                            {
                                if(nav[lin+j][col]!='-')
                                    {flag=1;
                                }
                            }
                            
                            if(flag==1){
                                printf("\n");
                            }
                            else
                            {
                                for(j=0;j<4;j++){
                                    nav[lin+j][col]='G';
                                }            
                                i=i+1;
                                
                                printf("\n\tJogador %d\n\n",jogador);
                                mostratabuleiro(nav);
                            }
                        }
                }
                else if(tiponav=='c'){
                    if(col>7){
                        printf("\n");
                    }
                    else
                    {
                        for(j=0;j<3;j++)
                        {
                            if(nav[lin+j][col]!='-')
                            flag=1;
                        }
                                
                        if(flag==1){
                            printf("\n");
                        }
                        else
                        {
                            for(j=0;j<3;j++){
                                nav[lin+j][col]='C';
                            }           
                            i=i+1;
                                    
                            printf("\n\tJogador %d\n\n",jogador);
                            mostratabuleiro(nav);
                                    
                        }
                    }
                }
                else if(tiponav=='d'){
                    if(col>7){
                        printf("\n");
                    }else{
                        for(j=0;j<3;j++)
                        {
                            if(nav[lin+j][col]!='-'){
                                flag=1;
                            }
                        }
                                        
                        if(flag==1){
                            printf("\n");
                        }else{
                            for(j=0;j<3;j++){
                            nav[lin+j][col]='S';
                            }               
                            i=i+1;
                                            
                            printf("\n\tJogador %d\n\n",jogador);
                            mostratabuleiro(nav);
                                           
                        }
                    }
                }
                    else if(tiponav=='e'){
                        if(col==9){
                            printf("\n");
                        }
                        else{
                            for(j=0;j<2;j++)
                            {
                                if(nav[lin+j][col]!='-'){
                                    flag=1;
                                }
                            }
                                            
                            if(flag==1){
                                printf("\n");
                            }else{
                                for(j=0;j<2;j++){
                                    nav[lin+j][col]='D';
                                }                
                                i=i+1;
                                printf("\n\tJogador %d\n\n",jogador);
                                mostratabuleiro(nav);
                                
                            }
                        }
                    }
			}
		}
	
	}
}

void atira(char **nav1,char **nav2,char **tir1,char **tir2){
	int linha11,linha21,linha31,lin11,lin21,lin31,col11,col21,col31,lin,col,cont,teste;
	int linha12,linha22,linha32,lin12,lin22,lin32,col12,col22,col32,sinal,sinal1;
	int afundoutudo=0,navafund1=0,navafund2=0,n=0;
	char coluna11,coluna21,coluna31,coluna12,coluna22,coluna32;
	srand(time(NULL));
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
				scanf("%s",&coluna11);
				printf("\n");
				if(coluna11=='A'||coluna11=='a'||coluna11=='B'||coluna11=='b'||coluna11=='C'||coluna11=='c'||coluna11=='D'||coluna11=='d'||coluna11=='E'||coluna11=='e'||coluna11=='F'||coluna11=='f'||coluna11=='G'||coluna11=='g'||coluna11=='H'||coluna11=='h'||coluna11=='I'||coluna11=='i'||coluna11=='J'||coluna11=='j')
					sinal1=1;
				else
					printf("Coluna invalida - Entre coluna novamente\n");
			}
			
			lin11=linha11-1;
			if(coluna11=='A'||coluna11=='a')
				col11=0;
			else
				if(coluna11=='B'||coluna11=='b')
					col11=1;
				else
					if(coluna11=='C'||coluna11=='c')
						col11=2;
					else
						if(coluna11=='D'||coluna11=='d')
							col11=3;
						else
							if(coluna11=='E'||coluna11=='e')
								col11=4;
							else
								if(coluna11=='F'||coluna11=='f')
									col11=5;
								else
									if(coluna11=='G'||coluna11=='g')
										col11=6;
									else
										if(coluna11=='H'||coluna11=='h')
											col11=7;
										else
											if(coluna11=='I'||coluna11=='i')
												col11=8;
											else
												if(coluna11=='J'||coluna11=='j')
													col11=9;

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
				scanf("%s",&coluna21);
				printf("\n");
				if(coluna21=='A'||coluna21=='a'||coluna21=='B'||coluna21=='b'||coluna21=='C'||coluna21=='c'||coluna21=='D'||coluna21=='d'||coluna21=='E'||coluna21=='e'||coluna21=='F'||coluna21=='f'||coluna21=='G'||coluna21=='g'||coluna21=='H'||coluna21=='h'||coluna21=='I'||coluna21=='i'||coluna21=='J'||coluna21=='j')
					sinal1=1;
				else
					printf("Coluna invalida - Entre coluna novamente\n");
			}
			
			lin21=linha21-1;
			if(coluna21=='A'||coluna21=='a')
				col21=0;
			else
				if(coluna21=='B'||coluna21=='b')
					col21=1;
				else
					if(coluna21=='C'||coluna21=='c')
						col21=2;
					else
						if(coluna21=='D'||coluna21=='d')
							col21=3;
						else
							if(coluna21=='E'||coluna21=='e')
								col21=4;
							else
								if(coluna21=='F'||coluna21=='f')
									col21=5;
								else
									if(coluna21=='G'||coluna21=='g')
										col21=6;
									else
										if(coluna21=='H'||coluna21=='h')
											col21=7;
										else
											if(coluna21=='I'||coluna21=='i')
												col21=8;
											else
												if(coluna21=='J'||coluna21=='j')
													col21=9;
													
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
				scanf("%s",&coluna31);
				printf("\n");
				if(coluna31=='A'||coluna31=='a'||coluna31=='B'||coluna31=='b'||coluna31=='C'||coluna31=='c'||coluna31=='D'||coluna31=='d'||coluna31=='E'||coluna31=='e'||coluna31=='F'||coluna31=='f'||coluna31=='G'||coluna31=='g'||coluna31=='H'||coluna31=='h'||coluna31=='I'||coluna31=='i'||coluna31=='J'||coluna31=='j')
					sinal1=1;
				else
					printf("Coluna invalida - Entre coluna novamente\n");
			}
					
			lin31=linha31-1;
			if(coluna31=='A'||coluna31=='a')
				col31=0;
			else
				if(coluna31=='B'||coluna31=='b')
					col31=1;
				else
					if(coluna31=='C'||coluna31=='c')
						col31=2;
					else
						if(coluna31=='D'||coluna31=='d')
							col31=3;
						else
							if(coluna31=='E'||coluna31=='e')
								col31=4;
							else
								if(coluna31=='F'||coluna31=='f')
									col31=5;
								else
									if(coluna31=='G'||coluna31=='g')
										col31=6;
									else
										if(coluna31=='H'||coluna31=='h')
											col31=7;
										else
											if(coluna31=='I'||coluna31=='i')
												col31=8;
											else
												if(coluna31=='J'||coluna31=='j')
													col31=9;

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
					n = rand() % 10;
					linha12 = n;
					n=0;
					if(linha12>=1&&linha12<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					coluna12 = 'a' + (char)(rand()%10);
					printf("\n");
					if(coluna12=='A'||coluna12=='a'||coluna12=='B'||coluna12=='b'||coluna12=='C'||coluna12=='c'||coluna12=='D'||coluna12=='d'||coluna12=='E'||coluna12=='e'||coluna12=='F'||coluna12=='f'||coluna12=='G'||coluna12=='g'||coluna12=='H'||coluna12=='h'||coluna12=='I'||coluna12=='i'||coluna12=='J'||coluna12=='j')
						sinal1=1;
				}
				
				lin12=linha12-1;
				if(coluna12=='A'||coluna12=='a')
					col12=0;
				else
					if(coluna12=='B'||coluna12=='b')
						col12=1;
					else
						if(coluna12=='C'||coluna12=='c')
							col12=2;
						else
							if(coluna12=='D'||coluna12=='d')
								col12=3;
							else
								if(coluna12=='E'||coluna12=='e')
									col12=4;
								else
									if(coluna12=='F'||coluna12=='f')
										col12=5;
									else
										if(coluna12=='G'||coluna12=='g')
											col12=6;
										else
											if(coluna12=='H'||coluna12=='h')
												col12=7;
											else
												if(coluna12=='I'||coluna12=='i')
													col12=8;
												else
													if(coluna12=='J'||coluna12=='j')
														col12=9;
														
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
					n = rand() % 10;
					linha22 = n;
					n = 0;
					if(linha22>=1&&linha22<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					
					coluna22 = 'a' + (char)(rand()%10);
					printf("\n");
					if(coluna22=='A'||coluna22=='a'||coluna22=='B'||coluna22=='b'||coluna22=='C'||coluna22=='c'||coluna22=='D'||coluna22=='d'||coluna22=='E'||coluna22=='e'||coluna22=='F'||coluna22=='f'||coluna22=='G'||coluna22=='g'||coluna22=='H'||coluna22=='h'||coluna22=='I'||coluna22=='i'||coluna22=='J'||coluna22=='j')
						sinal1=1;
					else
						printf("Coluna invalida - Entre coluna novamente\n");
				}
				
				lin22=linha22-1;
				if(coluna22=='A'||coluna22=='a')
					col22=0;
				else
					if(coluna22=='B'||coluna22=='b')
						col22=1;
					else
						if(coluna22=='C'||coluna22=='c')
							col22=2;
						else
							if(coluna22=='D'||coluna22=='d')
								col22=3;
							else
								if(coluna22=='E'||coluna22=='e')
									col22=4;
								else
									if(coluna22=='F'||coluna22=='f')
										col22=5;
									else
										if(coluna22=='G'||coluna22=='g')
											col22=6;
										else
											if(coluna22=='H'||coluna22=='h')
												col22=7;
											else
												if(coluna22=='I'||coluna22=='i')
													col22=8;
												else
													if(coluna22=='J'||coluna22=='j')
														col22=9;
																												
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
					n = rand() % 10;
					linha32 = n;
					n = 0;
					if(linha32>=1&&linha32<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
								
					coluna32 = 'a' + (char)(rand()%10);
					printf("\n");
					if(coluna32=='A'||coluna32=='a'||coluna32=='B'||coluna32=='b'||coluna32=='C'||coluna32=='c'||coluna32=='D'||coluna32=='d'||coluna32=='E'||coluna32=='e'||coluna32=='F'||coluna32=='f'||coluna32=='G'||coluna32=='g'||coluna32=='H'||coluna32=='h'||coluna32=='I'||coluna32=='i'||coluna32=='J'||coluna32=='j')
						sinal1=1;
					else
						printf("Coluna invalida - Entre coluna novamente\n");
				}
						
				lin32=linha32-1;
				if(coluna32=='A'||coluna32=='a')
					col32=0;
				else
					if(coluna32=='B'||coluna32=='b')
						col32=1;
					else
						if(coluna32=='C'||coluna32=='c')
							col32=2;
						else
							if(coluna32=='D'||coluna32=='d')
								col32=3;
							else
								if(coluna32=='E'||coluna32=='e')
									col32=4;
								else
									if(coluna32=='F'||coluna32=='f')
										col32=5;
									else
										if(coluna32=='G'||coluna32=='g')
											col32=6;
										else
											if(coluna32=='H'||coluna32=='h')
												col32=7;
											else
												if(coluna32=='I'||coluna32=='i')
													col32=8;
												else
													if(coluna32=='J'||coluna32=='j')
														col32=9;
																												
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

void mostratabuleiro(char **navio)
{
	int l,c;
	printf("   1 2 3 4 5 6 7 8 9 10\n");
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
