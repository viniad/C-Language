#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int somar(int a, int b){
	return a+b;
}

int subtrair(int a, int b){
	return a-b;
}

int operacao(int x, int y, int(*funcao)(int, int)){
	int num;
	num = funcao(x,y);
	return num;

}

void salvar(int a, int b, int(*func)(int, int)){
	func(a, b);
}

int salvatxt(int a, int b){
	FILE* fp = fopen("salvar.txt", "w");
	fprintf(fp, "%d\n", a);
	fprintf(fp, "%d\n", b);
	
	fclose(fp);
}

int salvabin(int a, int b){
	FILE* fp = fopen("salvar.txt", "wb");
	fwrite(&b, sizeof(int), 1, fp);
	fwrite(&a, sizeof(int), 1, fp);
	
	fclose(fp);
}

int fatRec(int n){
	if(n <= 1){
		return n;
	}else{
		return n * fatRec(n-1);
	}
	
}

int fatIte(int n){
	int i, res = 1;
	while(n>0){
		res *= n--; 
	}
	return res;
}

int fatorial(int n, int(*func)(int)){
	int op;
	op = func(n);
	return op;

}

int main(int argc, char *argv[]) {
	int i, j;
	
	
	int (*sub)(int, int);
	sub = subtrair;
	int (*soma)(int, int);
	soma = somar;
		
	i = operacao(5, 5, soma);
	j = operacao(5, 5, sub);

	//                       salvando em binario e texto e depois lendo em binario e texto com ponteiro de funcao
	int(*bin)(int, int);
	bin = salvabin;
	int(*txt)(int, int);
	txt = salvatxt;
	
	salvar(i, j, bin);
	//salvar(i, j, txt);
	
	int p, k;
	FILE *le = fopen("salvar.txt", "rb");
	fread(&p, sizeof(int), 1, le);
	fread(&k, sizeof(int), 1, le);
	printf("%d\n", p);
	printf("%d\n", k);
	
	
	//                          fatorial iterativo e recursivo com ponteiro de funcao
	int (*iter)(int) = fatIte;
	int (*rec)(int) = fatRec;
	
	printf(" Fatorial recursivo = %d\n", fatorial(5, rec));
	printf(" Fatorial iterativo = %d\n", fatorial(5, iter));
	
	
	
	/*printf("Soma = %d\n", i);
	printf("Sub = %d\n", j);*/

	
	
	return 0;
}
