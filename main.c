#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

bool Existe(int *aposta, int tan, int valor){
     for (int i = 0; i < tan; i++){
          if (aposta[i]==valor)
               return true;
     }
  return false;
}

void ler_aposta(int *aposta, int n){
     int i, x;
     printf("Informe os %d valores (0-100)", n);
     for ( i = 0; i < n; i++){   
          scanf("%d" ,&aposta[i]);             
     }
     for ( i = 0; i <= n; i++){
          for (x = i+1; x < n; x++){
               if (aposta[i]==aposta[x]){
                    printf ("Possui valores repedidos na aposta, refaça a posta sem repetir valores!");
                    exit(0);
               }
          }
          
     }
     
}

void sorteia_valores(int *sorteio, int n){
    int i = 0, j, igual;
    srand(time(NULL));
    do{ 
        sorteio[i] = rand() % 100;
        igual = 0;
        for(j = 0; j < i; j++){
            if(sorteio[j] == sorteio[i])
                igual = 1;
        }
        if(igual == 0) 
            i++;
    }while(i < n); 

}

int compara_aposta(int *aposta, int * sorteio, int *val_certos, int na, int ns){
     int i, j, n = 0;
     for ( i = 0; i < na; i++){
          for ( j = 0; j < ns; j++){
               if (aposta[i] == sorteio[j]){
                    if (n==0){
                         val_certos[n]=aposta[i];
                         n++;
                    }else{
                         val_certos = realloc(val_certos,(n+1)*sizeof(int));
                         val_certos[n]=aposta[i];
                         n++;
                    } 
             }
          }
     }
     return n;
}

int main(){
     FILE *pont_arq;
     pont_arq = fopen("dados_de_aposta.txt", "w"); 
     int nap, i, *aposta, sorteio[20], *val_certos, qtd_acertos, cont = 0, j = 1; 
     printf ("Informe a quantidade de valores que deseja apostar(1-20): \n");
     scanf ("%d" ,&nap);
     fprintf(pont_arq,"Valor de apostas:%d\n", nap);
     aposta = (int*) malloc(nap*sizeof(int));
     val_certos = (int*) malloc(1*sizeof(int));
     ler_aposta(aposta, nap); 
     sorteia_valores(sorteio,20);
     qtd_acertos = compara_aposta(aposta,sorteio,val_certos,nap,20);
     printf("Valores sorteados: \n");
     for (i = 0; i < 20; i++)
     {
          fprintf(pont_arq,"Valor sorteado %d: %d\n", j, sorteio[i]);
          printf("%d\n", sorteio[i]);  
          j++;  
     }
     if (qtd_acertos==0)
          {
               printf("Não acertou nada!");
          }else{
               printf("O usuário acertou %d valores: \n" ,qtd_acertos);
               for ( i = 0; i < qtd_acertos; i++)
                    printf("%d\n", val_certos[i]);    
          }
     free (aposta);
     free (val_certos);
     fclose(pont_arq);
     return 0;
}