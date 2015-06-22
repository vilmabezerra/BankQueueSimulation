#include "./fila.h"
#include "./escalonador.h"

void start(fila_FIFO **f){
(*f) = (fila_FIFO*)malloc(sizeof(fila_FIFO));
(*f)->prox = NULL;
}

void insert(fila_FIFO **f, int chave, int classe, int valor){
fila_FIFO *p = (*f);
fila_FIFO *new;
new = (fila_FIFO*)malloc(sizeof(fila_FIFO));
new->prox = NULL;
new->chave = chave;
new->classe = classe;
new->valor = valor;
	if(p->prox == NULL){
		p->prox = new;
	}
	else{
		while(p->prox != NULL){
			p = p->prox;
		}
		p->prox = new;
	}
}

int obter_proxima_chave(fila_FIFO **f){
fila_FIFO *p = (*f);
fila_FIFO *prox;
prox = (fila_FIFO*)malloc(sizeof(fila_FIFO));
	if(p->prox == NULL){
		return -1;
	}else{
		*prox = *p->prox;
		p->prox = p->prox->prox;
		return prox->classe;
	}
}

int consultar_proxima_chave(fila_FIFO **f){
    if((*f)->prox == NULL){
		return -1;
	}else{
		return (*f)->prox->chave;
	}
}

int consultar_proximo_valor(fila_FIFO **f){
    	if((*f)->prox == NULL){
		return -1;
	}else{
		return (*f)->prox->valor;
	}
}

int num_elementos(fila_FIFO **f){
int num = 0;
fila_FIFO *p = (*f);
	while(p->prox != NULL){
		p = p->prox;
		num++;
	}
	return num;
}

int consultar_chave_por_posicao(fila_FIFO **f, int posicao){
int pos = 0;
fila_FIFO *p = (*f);
	while(pos < posicao){
		p = p->prox;
		pos++;
	}
	return p->classe;
}

int consultar_valor_por_posicao(fila_FIFO **f, int posicao){
int pos = 0;
fila_FIFO *p = (*f);
	while(pos < posicao){
		p = p->prox;
		pos++;
	}
	return p->chave;
}
