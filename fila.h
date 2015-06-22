#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fila_FIFO_{
	int chave; //Tipo de conta
	int classe; //Classes
	int valor; //Quantidade de operações
	struct fila_FIFO_ *prox; //Proximo ponteiro
}typedef fila_FIFO;


void start(fila_FIFO **f);
//inicializa a fila.

void insert(fila_FIFO **f, int chave, int classe, int valor);
//Insere um determinado valor inteiro indexado por um valor de chave na fila.

int obter_proxima_chave(fila_FIFO **f);
//Retorna o número de chave do próximo elemento da fila, retirando-o da fila. Retorna -1 se a fila estiver vazia.

int consultar_proxima_chave(fila_FIFO **f);
//Retorna a chave do elemento que está na cabeça da fila, sem retirá-lo da fila.

int consultar_proximo_valor(fila_FIFO **f);
//Retorna o valor armazenado no elemento que está na cabeça da fila, sem retirá-lo da fila.

int num_elementos(fila_FIFO **f);
//Retorna o número de elementos presentes na fila.

int consultar_chave_por_posicao(fila_FIFO **f, int posicao);
//Retorna a chave do posicao-ésimo elemento da fila. Caso não exista a posição desejada, retornar -1.

int consultar_valor_por_posicao(fila_FIFO **f, int posicao);
//Retorna o valor do posicao-ésimo elemento da fila. Caso não exista a posição desejada, retornar -1.

