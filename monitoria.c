#define minas 10
#define size 20

void colocar(char tabuleiro[size][size]){
	int cont = 0;
	while (cont < minas)
	{
        //gerador aleatorio de valores para add as bombas
		int l = rand( ) % 10;
		int c = rand( ) % 10;
        //verificação para ver ser já tem uma bomba naquela posição gerada
		if (tabuleiro[l][c] != '-')
		{
			tabuleiro[l][c] = '-';
			cont ++;
		}
		
	}
	
}