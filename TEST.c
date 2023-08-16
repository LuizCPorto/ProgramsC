#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta (int *aposta,int n){
printf("digite a quantidade de apostas\n");
scanf("%d",&n);
FILE * arquivo; 
arquivo=fopen("aposta.txt","w");
aposta=(int *)malloc(n*sizeof(int));
printf("digite quais valores quer apostar\n");
for(int i=0;i<n;i++){
    scanf("%d",&aposta[i]);
    
fprintf(arquivo,"%d\n",aposta);  
}
rewind (arquivo);
fclose(arquivo);  

    
}


void sorteia_valores (int *sorteio,int n){
printf("sera sorteado 20 numeros:\n");
srand(time(NULL));
sorteio=(int*)malloc(20*sizeof(int));
for(n=0;n<20;n++){
sorteio[n]=rand()%100;

printf("%d\t",rand()%100);}

}

int compara_aposta (int *aposta, int *sorteio,int *val_certos,int na, int ns){
int cont;
cont=0;
sorteio=(int*)malloc(20*sizeof(int));
aposta=(int*)malloc(20*sizeof(int));
for(na=0;na<20;na++){
    for(ns=0;ns<20;ns++){
        if(aposta[na]==sorteio[ns]){
            
            val_certos++;
            }}}
printf("\nnumeros certos %d\n",cont);

}

void main (void){;
    
int *ap,*sort,*val,*arq;
int np,n,l;
char *p;
ler_aposta (ap,np);
sorteia_valores (sort,np);
compara_aposta(ap,sort,val,n,np);

}