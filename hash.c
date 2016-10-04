// Jonathan Sias
// 10205513

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float fatorCarga = 0.0;
int m = 256;
int numPalavras = 0;
int verifica = 0;

char palavra[100];
char auxWord[100] = "a";

struct hashTable{						//struct hashTable
	char *words;
}*tabelaHash;

typedef struct hashTable hashTable;		//hashTable do tipo hashTable

void minuscula(char *p){				//passar tudo para letras minusculas
   int i = 0;
   while (p[i] != '\0')
   {
      if (p[i] >= 'A' && p[i] <= 'Z')
      {
         p[i] = p[i] + 32;
      }
      i++;
   }
}

int consulta(char* p){
	int i;
	int posicao;
	posicao = calculaIndiceDaTabela(p);		//calcula o indice da string pra verificar
	if (tabelaHash[posicao].words != NULL)	//se o elemento for diferente de null
	{
		if (strcmp(tabelaHash[posicao].words, p) == 0)	//se o elemento é igual ao que se encontra na tabela
		{
			return 0;						//retorna 0 - ok
		} else{
			posicao++;
			for (i = posicao; i < m; ++i)
			{
				if (strcmp(tabelaHash[i].words, p) == 0)
				{
					return 0;
				}
			}
		}
	} else{
		return 1;							//retorna 1 - not found
	}
}

int adiciona(char* p){
	int i;
	int posicao;
	posicao = calculaIndiceDaTabela(p);			//calcula o indice para verificar
	//printf("%d\n", posicao);	//testa com indice pra ver se esta fazendo corretamente
	if(consulta(p) == 1){
		if (tabelaHash[posicao].words == NULL){	//se o elemento for diferente de null
			tabelaHash[posicao].words = p;		//atribui a string a posicao calculada pela funcao hash
			return 0;							//retorna 0 - ok
		} else{
			posicao++;
			for (i = posicao; i < m; ++i)
			{
				if (tabelaHash[i].words == NULL)
				{
					tabelaHash[i].words = p;
					return 0;
				}
			}
			//return 0;
		}
	} else{
		return 1;
	}
}

int remover(char* p){
	int i;
	int posicao;
	posicao = calculaIndiceDaTabela(p);			//calcula o indice pra verificar
	if(tabelaHash[posicao].words != NULL){		//caso a informaçao seja diferente de null
		if (strcmp(tabelaHash[posicao].words, p) == 0){	//se o elemento for igual ao informado
			tabelaHash[posicao].words = NULL;	//atribui null a posicao calculada
			return 0;							//retorna 0 - ok
		} else{
			posicao++;
			for (i = posicao; i < m; ++i)
			{
				if (strcmp(tabelaHash[i].words, p) == 0)
				{
					tabelaHash[i].words = NULL;
					return 0;
				}
			}
			//return 0;
		}
	} else{
		return 1;								//retorna 1 - fail
	}

}

void reHash(){
	hashTable* secondHash;
	hashTable* thirdHash;
	m = (m*2);
	int i;

	//outras duas hashes para auxiliar no rehash
	secondHash = malloc (sizeof(hashTable)*m);
	thirdHash = malloc (sizeof(hashTable)*m);

	for (i = 0; i < m; i++) {
        secondHash[i].words = NULL;
	}

	thirdHash = tabelaHash;
	tabelaHash = secondHash;

	for (i = 0; i < m/2; i++)
	{
		if (thirdHash[i].words != 0)
		{
			adiciona(thirdHash[i].words);
		}
	}
}

//funçao hash
int calculaIndiceDaTabela(char* p){
	int i;
	int h = p[0];
	for (i = 1; p[i] != '\0'; i++)
	{
		h = (h * 251 + p[i]) % m;
	}
	return h;
}

int main(){

	tabelaHash = malloc(sizeof(hashTable)*m);		//cria tabela
	strcpy(auxWord, "");
	do
	{
		do
		{
			scanf("%s", palavra);			//primeira leitura
			minuscula(palavra);				//passa a palavra para minuscula

			if ((strcmp(palavra, "+") != 0) && (strcmp(palavra, "-") != 0) && (strcmp(palavra, "*") != 0))
			{
				strcpy(auxWord, palavra);
				if (consulta(auxWord) == 1)
				{
					printf("not found\n");
				} else{
					printf("ok\n");
				}
			}

		} while (strlen(palavra) != 1);

		if (strlen(auxWord) == 0)
		{
			printf("fail\n");
		} else{
			if (strcmp(palavra, "+") == 0)
			{
				if ((fatorCarga = (numPalavras / m)) >= 0.7)
				{
					reHash();
					if (adiciona(auxWord) == 0)
					{
						numPalavras++;
						printf("ok\n");
					} else{
						printf("fail\n");
					}
				} else{
					if (adiciona(auxWord) == 0)
					{
						numPalavras++;
						printf("ok\n");
					} else{
						printf("fail\n");
					}
				}
			} else{
				if (strcmp(palavra, "-") == 0)
				{
					if (remover(auxWord) == 0)
					{
						numPalavras--;
						printf("ok\n");
					} else{
						printf("fail\n");
					}
				}
			}
		}

	} while ((strcmp(palavra, "*") != 0));

	return 0;
}