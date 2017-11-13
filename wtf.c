#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// fator de carga para rehash
float fatorDeCarga = 0.0;
// numero posiçoes da hash
int posicoes = 0;
// numero de chaves da hash
int chaves = 0;
// vetor char contendo palavra
char palavra[99];
// tamanho inicial da hash
int tamanho = 1021;
// tabela hash
struct tabela
{
	char *dado;
}*tabelaHash;
typedef struct tabela hash;

// inicializaçao da hash
void inicializar(){
	tabelaHash = malloc(sizeof(hash)*tamanho);
	int i;
	for (i = 0; i < tamanho; ++i)
	{
		tabelaHash[i].dado = NULL;
	}
}

// inserçao
int insercao(){
	//
	return 0;
}

// remoçao
int remocao(){
	//
	return 0;
}

// busca
int busca(){
	//
	return 0;
}

// listar elementos
void listar(){
	int i;
	for (int i = 0; i < tamanho; ++i)
	{
		printf("%s\n", tabelaHash[i]);
	}
}

// funçao hash
int dispercao(char *word){
	int i;
	int h = 0;
	for (i = 0; word[i] != '\0'; ++i)
	{
		h = (h + word[i]);
	}
	h = (h % tamanho);
	return h;
}

// tratando colisao
int sondagemLinear(){
	//
	return 0;
}

// funçao rehash
void rehash(){
	//
}

// para letras minusculas
void minusculas(char *word){
	int i = 0;
	while(word[i] != '\0')
	{
		if (word[i] >= 'A' && word[i] <= 'Z')
		{
			word[i] = word[i] + 32;
		}
		i++;
	}
}

// corrige palavra
void correcao(){
	//
}

int main(){
	inicializar();
	scanf("%s", palavra);
	int x = 0;

	/*
	do{
		// primaira leitura
		scanf("%s", palavra);
		// passando caracteres maiusculos para minusculos
		minusculas(palavra);
		// comparando tamanho da entrada
		if (strlen(palavra) == 0)
		{
			printf("fail");
		}else{
			if (strlen(palavra) == 1)
			{
				if ((strcmp(palavra, "+") != 0) && (strcmp(palavra, "-") != 0) && (strcmp(palavra, "*") != 0))
				{
					printf("fail");
				}
			}else{
				if (strcmp(palavra, "+") == 0)
				{
					//
				}
				if (strcmp(palavra, "-") == 0)
				{
					//
				}
				if (strcmp(palavra, "*"))
				{
					//
				}
			}
		}
	}while((strcmp(palavra, "*") != 0));
	*/
	return 0;
}