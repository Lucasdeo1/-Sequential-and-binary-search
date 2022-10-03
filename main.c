#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int tamanho();
int *aloca(int*x, int tam);
int buscase(int *x, int tam, int chave);
void ordena( int *x, int tam );
int buscabinary( int *x, int tam, int dados );

int main(){
	
	int *vetor;
	int i, op, op2, op3, achou, tam;
	tam = tamanho();
	vetor = aloca(vetor, tam);
	
	printf("\n\n");
	
	for(i=0;i<tam;i++){
		printf("Vetor %d: ",i);
		scanf("%d",&vetor[i]);
	}
	
	do{
		printf("\n\nBusque:\n1-sequencial\n2-binaria");
		scanf("%d",&op);
		
		switch (op){
			
			case 1:
				printf("Busque: ");
				scanf("%d",&op2);
				int pos = buscase(vetor,tam,op2);
				
				if(pos == -1){
					printf("\n\nVetor nao encontrado.");
				}
				else{
					printf("\n\nVetor encontrado na posicao %d ", pos);
				}
				
				break;
				case 2:
					printf("Busque: ");
					ordena( vetor, tam );
					scanf("%d",&op3);
					int pos2 =  buscabinary( vetor, tam, op3 );
					
					if(pos == -1){
						printf("\n\nVetor nao encontrado.");
					}
					else{
						printf("\n\nVetor encontrado na posicao %d\n", pos2);
					}
					printf("vetor [%d] = %d\n",pos2,vetor[pos2]);
					break;			
		}
	}while(op!=0);
		
	
	return 0;
}

int tamanho(){
	int a;
	printf("Digite um tamanho do vetor:");
	scanf("%d",&a);
	return a;
}

int *aloca(int *x, int tam){
	x = (int*) malloc(tam * sizeof(int));
	return x;
}

int buscase(int *x,int tam, int chave){
	int i;
	for(i=0;i<tam;i++){
		if(x[i] == chave){
			return i;
		}
	}
	return -1;	
}

void ordena( int *x, int tam ){
	int cont,i;
	int troca;
	for (cont=0;cont<tam;cont ++){
		for(i=cont+1;i<tam;i++){							
			if(x[cont]> x[i] ){
				troca = x[i];
				x[i] = x[cont];
				x[cont] = troca;
			}
		}
	}
}

int buscabinary( int *x, int tam, int dados ){
	int i;
	int e = 0;
	int d = tam - 1;
	
	do {
		i = ( e + d)/2;
		if( dados > x[i]){
			e = i+1;	
		}
		else{
			d = i-1;
		}
	}while( dados != x[i] && e <= d); 
	
	if( dados == x[i]){
		return i;
	}
	else{
		return -1;
	}
}
