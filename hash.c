/********************
*	Jonathan Sias
*		AEDII
*	Tabelas Hash
********************/

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

// tratando colisao
int sondagemLinear(char *word, int position){
	int i;
	for (i = position; i < tamanho; ++i)
	{
		if (tabelaHash[i].dado == NULL)
		{
			tabelaHash[i].dado = word;
			return 1;
		}
	}
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

// inserçao
int insercao(char *word){
	int posicao = 0;
	posicao = dispersao(word);
	if (busca(word) == 0)
	{
		if (tabelaHash[posicao].dado == NULL)
		{
			tabelaHash[posicao].dado = word;
			posicoes++;
			return 1;
		}else{
			if (sondagemLinear(word, posicao) == 1)
			{
				posicoes++;
				return 1;
			}
		}
	}else{
		return 0;
	}
}

// remoçao
int remocao(char *word){
	int i;
	int posicao = (dispersao(word));
	if ((tabelaHash[posicao].dado != NULL) && (strcmp(tabelaHash[posicao].dado, word) == 0))
	{
		tabelaHash[posicao].dado = NULL;
		posicoes--;
		return 1;
	}else{
		for (i = posicao++; i < tamanho; ++i)
		{
			if ((tabelaHash[i].dado != NULL) && (strcmp(tabelaHash[i].dado, word) == 0))
			{
				tabelaHash[i].dado = NULL;
				posicoes--;
				return 1;
			}
		}
	}
}

// funçao rehash
void rehash(){
	hash* hashAuxiliar;
	int tam = 0;
	tam = (tamanho*2);
	int i;
	hashAuxiliar = malloc (sizeof(hash)*tam);
	// atribuindo NULL ao hash auxiliar
	for (i = 0; i < tam; ++i)
	{
		hashAuxiliar[i].dado = NULL;
	}
	// copiando valores para hash auxiliar
	for (i = 0; i < tamanho; ++i)
	{
		hashAuxiliar[i].dado = tabelaHash[i].dado;
	}
	tamanho = (tamanho*2);
	// hash principal recebe NULL
	for (i = 0; i < tamanho; ++i)
	{
		tabelaHash[i].dado = NULL;
	}
	// devolve valores pra hash principal
	for (i = 0; i < tamanho; ++i)
	{
		tabelaHash[i].dado = hashAuxiliar[i].dado;
	}
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

void correcao(char *word){
	int localiza = dispersao(word);
	int acertos = 0;
	for (int i = localiza; tabelaHash[i].dado == NULL; ++i)
	{
		for (int j = 0; j < (strlen(word)+1); ++j)
		{
			if (tabelaHash[i].dado[j] == word[j])
			{
				acertos++;
			}
		}
		if (acertos < (strlen(word)-1))
		{
			printf("%s\n", word);
		}
		acertos = 0;
	}
}

int main(){
	inicializar();
	// auxiliar de leitura
	char palavraAuxiliar[99];
	strcpy(palavraAuxiliar, "");
	do
	{
		do
		{
			scanf("%s", palavra);
			if ((strcmp(palavra, "+") != 0) && (strcmp(palavra, "-") != 0) && (strcmp(palavra, "*") != 0))
			{
				strcpy(palavraAuxiliar, palavra);
				if (busca(palavraAuxiliar) == 1)
				{
					printf("ok %s\n", palavraAuxiliar);
					correcao(palavraAuxiliar);
				}else{
					printf("not found\n");
				}
			}else{
				//
			}
		} while (strlen(palavra) > 1);
		// se leitura nao for uma palavra
		if (strlen(palavraAuxiliar) == 0)
		{
			printf("fail\n");
		}else{
			if (strcmp(palavra, "+") == 0)
			{
				if ((fatorDeCarga = (posicoes/tamanho)) >= 0.85)
				{
					rehash();
					if (busca(palavra) == 0)
					{
						if (insercao(palavraAuxiliar) == 1)
						{
							printf("ok %s\n", palavraAuxiliar);
						}else{
							printf("fail %s\n", palavraAuxiliar);
						}
					}
				}else{
					if (busca(palavra) == 0)
					{
						if (insercao(palavraAuxiliar) == 1)
						{
							printf("ok %s\n", palavraAuxiliar);
						}else{
							printf("fail %s\n", palavraAuxiliar);
						}
					}
				}
			}else{
				if (strcmp(palavra, "-") == 0)
				{
					if (remocao(palavraAuxiliar) == 1)
					{
						printf("ok %s\n", palavraAuxiliar);
					}else{
						printf("fail %s\n", palavraAuxiliar);
					}
				}
			}
		}
	} while (strcmp(palavra, "*") != 0);
	return 0;
}