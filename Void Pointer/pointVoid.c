#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[50];
	int idade;
}pessoa;


void apagaEnter(char *str){
	int i=0;
	while(str[i] != '\0' && str[i] != '\n' )
	    i++;
	str[i] = '\0';
}


pessoa criaPessoa(){
	pessoa p;
	
	puts("Nome:");
	fgets(p.nome, 50, stdin);
	apagaEnter(p.nome);
	puts("Idade");
	scanf("%d", &p.idade);
	
	return p;
}


void imprime(pessoa p){
	printf("%s\n", p.nome);
	printf("%d\n", p.idade);
	puts("");
}


void salvaBin(pessoa p){
	FILE *fp = fopen("salvar.txt", "wb");
	fwrite(p.nome, sizeof(p.nome), 1, fp);
	fwrite(&p.idade, sizeof(p.idade), 1, fp);
	
	fclose(fp);
}

void salvaTxt(pessoa p){
	FILE *fp = fopen("salvar.txt", "w");
	fwrite(p.nome, sizeof(p.nome), 1, fp);
	fwrite(&p.idade, sizeof(p.idade), 1, fp);
	
	fclose(fp);
}

void salva(pessoa p, void(*func)(pessoa)){
	func(p);
}


int main(int argc, char *argv[]) {
	pessoa a = criaPessoa();
	imprime(a);
	
	void (*bin)(pessoa) = salvaBin;
	void (*txt)(pessoa) = salvaTxt;
	
	salva(a, txt);
	//salva(a, bin);
	
	
	return 0;
}
