#include<stdio.h>
#include<stdlib.h>

typedef struct aluno{
	char nome[15];
	int mat;
	float nota1, nota2, nota3, media; 
}aluno;


int quantidade();
aluno *alocamento(int tam );
void endereco(aluno *alunos, int tam);
void imprime(aluno *alunos, int tam); 
int buscaalunos(int tam , aluno* alunos, int dados);
void ordena(aluno *alunos, int tam);
int buscabinary(aluno *alunos, int tam, int dados);

int main(){
	
	int i, op, op2, op3 = 0,aux = 0;
	int pos,pos2 = 0;
	
	int tam;
	tam = quantidade();
	
	aluno *alunos;
	alunos = alocamento(tam); 
	
	printf("\n\n");
	endereco(alunos, tam);
	
	printf("\n\n");
	imprime(alunos, tam);
	printf("\n\n");
	
	do{
		printf("\n1-busca sequencial\n2-busca binaria\n3-imprimir todos os alunos");
		scanf("%d",&op);
		printf("\n");
		
		switch (op){
			
			case 1:
				
				printf("Busca sequencial:\n");
				printf("Digite a matricula do aluno desejado:");
				scanf("%d",&op2);
				
				pos = buscaalunos(tam , alunos, op2);
				
				if(pos == -1){
					printf("aluno nao matriculado");
				}else{
					printf("aluno matriculado na posicao %d\n", pos);
				}
				printf("aluno '%s'\nmatricula: %d\nnota 1: %f\nnota 2: %f\nnota 3: %f\n",alunos[pos].nome, alunos[pos].mat, alunos[pos].nota1, alunos[pos].nota2, alunos[pos].nota3);
				system("pause");
				system("cls");
				break;
				
			case 2:
				
				printf("Busca Binaria:\n");
				
				ordena(alunos, tam);
			
				printf("Busca Binaria pela matricula:");
				scanf("%d",&op3);
				
				pos2 =  buscabinary(alunos, tam, op3);
				
				if(pos2 == -1){
					printf("aluno nao matriculado");
				}
				else{
					printf("aluno matriculado na posicao %d\n", pos2);
					printf("aluno '%s'\nmatricula: %d\nnota 1: %f\nnota 2: %f\nnota 3: %f\n",alunos[pos2].nome, alunos[pos2].mat, alunos[pos2].nota1, alunos[pos2].nota2, alunos[pos2].nota3);
				}
				
				imprime(alunos, tam);
				
				system("pause");
				system("cls");
				break;

			case 3:
				
				imprime(alunos, tam);
				system("pause");
				system("cls");
				break;
				
				
				
		}
	}while(op!=0);
	
	
	return 0;
}

int quantidade(){
	int tam;
	printf("Digite a quantidade de alunos do vetor: ");
	scanf("%d",&tam);
	return tam;
}

aluno *alocamento(int tam ){
	aluno *alunos;
	alunos = (aluno*) malloc( tam *sizeof(aluno));
	return alunos;
}

void endereco(aluno *alunos, int tam ){
	int i;
	for(i=0;i<tam;i++){
		printf("Nome do aluno: ");
		scanf("%s",&alunos[i].nome);
		printf("matricula do aluno( %s ): ",alunos[i].nome);
		scanf("%d",&alunos[i].mat);
		printf("nota1, nota2 e nota3 do aluno ( %s ): ",alunos[i].nome);
		scanf("%f %f %f",&alunos[i].nota1, &alunos[i].nota2, &alunos[i].nota3);
	}
}

void imprime(aluno *alunos, int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("%s %d %f %f %f\n\n",alunos[i].nome, alunos[i].mat, alunos[i].nota1, alunos[i].nota2, alunos[i].nota3);
	}
}

int buscaalunos(int tam , aluno* alunos, int dados){
	int i;
	for(i=0 ; i<tam ;i++){
		if(dados==alunos[i].mat){
			return i;
		}
	}
	return -1;
}

void ordena(aluno *alunos, int tam){
	
	int cont,i;
	aluno troca;
	
	for (cont=0;cont<tam;cont ++){
		for(i=cont+1;i<tam;i++){							
			if(alunos[cont].mat > alunos[i].mat ){
				troca = alunos[i];
				alunos[i] = alunos[cont];
				alunos[cont] = troca;
			}
		}
	}
}

int buscabinary(aluno *alunos, int tam, int dados){
	
	int i;
	int inicio = 0;
	int ponta = tam - 1;

	do{
		 i = (inicio + ponta) / 2;
		 
		 if(dados > alunos[i].mat){
		 	 inicio = i + 1;
		 }
		 else{
		 	ponta = i - 1;
		 }
		
	}while( dados != alunos[i].mat && inicio<=ponta);
	
	if(dados == alunos[i].mat){
		return i;
	}
	else{
		return -1;
	}
}
