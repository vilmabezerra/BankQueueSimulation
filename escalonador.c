#include "./fila.h"
#include "./escalonador.h"

void escalonador_start(escalonador **e, int caixas1, int disc1[], char disc2[]){
(*e) = (escalonador*)malloc(sizeof(escalonador));
int i=0, j=0, k=0;
char disc3[5];
start(&(*e)->f1);
start(&(*e)->f2);
start(&(*e)->f3);
start(&(*e)->f4);
start(&(*e)->f5);
j = i;
while(disc2[i] != '\0'){
    if(disc2[i] != ','){
    disc3[j] = disc2[i];
    }
		if(disc2[i] == ',' || disc2[i] == '\0'){
        disc3[j] = '\0';
        sscanf(disc3, "%d", &disc1[k]);
			k++;
			j = -1;
		}
		i++;
		j++;
	}
	j++;
if(disc2[i] == '\0'){
disc3[j] = '\0';
sscanf(disc3, "%d", &disc1[k]);
}
i = 0;
}

void insert_por_fila(FILE *arq, escalonador **e){
int chave, classe, valor;
int i=0, j=0;
char aux1[15];
char temp[15];
fscanf(arq, "%s ", aux1);
    while(fscanf(arq, "%s ", aux1) != EOF){
		while(aux1[i] != ','){
        temp[j] = aux1[i];
        i++;
        j++;
		}
		temp[j] = '\0';
		sscanf(temp, " %d", &chave);
		j = 0;
		i++;
            while(aux1[i] != ','){
                temp[j] = aux1[i];
                i++;
                j++;
                }
                temp[j] = '\0';
                sscanf(temp, "%d", &classe);
                j = 0;
                i++;
                    while(aux1[i] != '\0'){
                    temp[j] = aux1[i];
                    i++;
                    j++;
                    }
                    temp[j] = '\0';
                    sscanf(temp, "%d", &valor);
                    j = 0;
                    i = 0;

                        switch (classe){
                            case 1:insert(&(*e)->f1, chave, classe, valor);
                            break;
                            case 2:insert(&(*e)->f2, chave, classe, valor);
                            break;
                            case 3:insert(&(*e)->f3, chave, classe, valor);
                            break;
                            case 4:insert(&(*e)->f4, chave, classe, valor);
                            break;
                            case 5:insert(&(*e)->f5, chave, classe, valor);
                            break;
        }
	}
}

int consultar_qtde_clientes(escalonador **e){
int qtde_clientes = 0;
qtde_clientes =+ (num_elementos(&(*e)->f1));
qtde_clientes =+ (num_elementos(&(*e)->f2));
qtde_clientes =+ (num_elementos(&(*e)->f3));
qtde_clientes =+ (num_elementos(&(*e)->f4));
qtde_clientes =+ (num_elementos(&(*e)->f5));
return qtde_clientes;
}
