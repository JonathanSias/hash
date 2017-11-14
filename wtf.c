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

// funçao hash
int dispersao(char *word){
	int i;
	int h = 0;
	for (i = 0; word[i] != '\0'; ++i)
	{
		h = (h + word[i]);
	}
	h = (h % tamanho);
	return h;
}

// inserçao
int insercao(char *word){
	int posicao = 0;
	posicao = dispersao(word);
	if (busca(word) == 0)
	{
		if (tabelaHash[posicao].dado == NULL)
		{
			tabelaHash[posicao].dado = word;
			return 1;
		}else{
			//
		}
	}
}

// remoçao
int remocao(){
	//
	return 0;
}

// busca
int busca(char *word){
	int posicao = 0;
	posicao = dispersao(word);
	if (tabelaHash[posicao].dado != NULL)
	{
		if (strcmp(word, tabelaHash[posicao].dado) == 0)
		{
			return 1;
		}else{
			posicao++;
			for (int i = posicao; i < tamanho; ++i)
			{
				if (strcmp(word, tabelaHash[posicao].dado) == 0)
				{
					return 1;
				}
			}
		}
	}else{
		return 0;
	}
}

// listar elementos
void listar(){
	int i;
	for (int i = 0; i < tamanho; ++i)
	{
		printf("%s\n", tabelaHash[i]);
	}
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
	//
	/*
	do{
		// primaira leitura
		scanf("%s", palavra);
		// passando caracteres maiusculos para minusculos
		minusculas(palavra);
		// comparando tamanho da entrada
		if (strlen(palavra) < 1)
		{
			printf("fail\n");
		}else{
			if (strlen(palavra) == 1)
			{
				if (strcmp(palavra, "+") == 0)
				{
					if ((posicoes/tamanho) >= 0.7)
					{
						//rehash
					}else{
						//add
						//posicoes++;
					}
				}else{
					if (strcmp(palavra, "-") == 0)
					{
						//
					}else{
						//
					}
				}
			}
		}
	}while((strcmp(palavra, "*") != 0));
	*/
	return 0;
}