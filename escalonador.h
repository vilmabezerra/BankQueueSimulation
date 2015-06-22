#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct caixas_{
	int time1;
	int time2;
	int chave;
	int classe;
	int valor;
}typedef caixas;
struct escalonador_{
	struct fila_FIFO_ *f1;
	struct fila_FIFO_ *f2;
	struct fila_FIFO_ *f3;
	struct fila_FIFO_ *f4;
	struct fila_FIFO_ *f5;
}typedef escalonador;

void escalonador_start(escalonador **e, int caixas1, int disc1[], char disc2[]);
//Inicializa o escalonador.

void insert_por_fila(FILE *arq, escalonador **e);
//Insere na fila classe o cliente de número num_conta, que pretende realizar qtde_operacoes operações bancárias.

int obter_prox_num_conta(escalonador **e);
//Retorna o número da conta do próximo cliente a ser atendido de acordo com a Disciplina de Atendimento,retirando-o da sua respectiva fila.

int consultar_prox_num_conta(escalonador **e);
//Retorna o número da conta do próximo cliente a ser atendido de acordo com a Disciplina de Atendimento, sem retirá-lo da sua respectiva fila.

int consultar_prox_qtde_oper(escalonador **e);
//Retorna a quantidade de operações bancárias que o próximo cliente das filas pretende realizar com o caixa, sem retirá-lo da sua respectiva fila.

int consultar_prox_fila(escalonador **e);
//Retorna a próxima fila que será atendida de acordo com a Disciplina de Atendimento.

int consultar_qtde_clientes(escalonador **e);
//Retorna a quantidade total (soma) de clientes esperando atendimento em todas as filas.

int consultar_tempo_prox(escalonador **e);
//Retorna o tempo necessário para que o próximo cliente a ser atendido realize todas as operações financeiras que deseja, sem retirá-lo da sua respectiva fila.

void rodar(escalonador *e, FILE *arq);
//Executar a simulação do atendimento, escrevendo o resultado de acordo com o padrão estabelecido observado nos casos de teste no ponteiro para arquivo arq.
