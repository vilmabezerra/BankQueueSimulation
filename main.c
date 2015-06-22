#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./fila.h"
#include "./escalonador.h"

int main(int narg, char *argv[]){
FILE *arq;
FILE *arq2;

int i=0, j=0;
int caixas1=0,chave=0,clientes=0;
int length=0;
char aux[10];
//char txt[5];
int disc1[5];
char disc2[15];
caixas caixas2[10];

char entrada[20];
char saida[20];
length = strlen(argv[1]);
/*printf("oi!\n");
while(i < (4-length)){
		aux[i] ='0';
		i++;
	}
strcat(aux, argv[1]);
strcat(aux, txt);
strcat(entrada, aux);
strcat(saida, aux);*/

	strcpy(entrada,"entrada-");
    if (strlen(argv[1])==1){
    	strcat(strcat(entrada,"000"),argv[1]);}
    else if (strlen(argv[1])==2){
    	strcat(strcat(entrada,"00"),argv[1]);}
    else if (strlen(argv[1])==3){
    	strcat(strcat(entrada,"0"),argv[1]);}
    else if (strlen(argv[1]) == 4){
    	strcat(entrada, argv[1]);}
	else
		strcat(entrada,"0000");
	strcat(entrada, ".txt");

	strcpy(saida,"saida-");
    if (strlen(argv[1])==1){
    	strcat(strcat(saida,"000"),argv[1]);}
    else if (strlen(argv[1])==2){
    	strcat(strcat(saida,"00"),argv[1]);}
    else if (strlen(argv[1])==3){
    	strcat(strcat(saida,"0"),argv[1]);}
    else if (strlen(argv[1]) == 4){
    	strcat(saida, argv[1]);}
	else
		strcat(saida,"0000");
	strcat(saida, ".txt");


arq = fopen(entrada, "r");
arq2 = fopen(saida, "w");
escalonador *e = NULL;

printf("Oi-1\n");

fscanf (arq,"%s %d", aux, &caixas1);
fscanf(arq,"%s %s", aux, disc2);

printf("Oi\n");

escalonador_start(&e,caixas1,disc1, disc2);
insert_por_fila(arq, &e);
clientes = consultar_qtde_clientes(&e);

for(j = 0; j < caixas1; j++){
		caixas2[j].time1 = 0;
		caixas2[j].time2 = 0;
		caixas2[j].valor = 0;
		}

i = 0;
j = 0;

while(clientes > 0){
	while(i < disc1[0]){
		chave = consultar_proxima_chave(&e->f1);
			if(chave != -1){
				if(j == caixas1){
                    j = 0;
				}
				if(caixas2[j].valor == 0){
					caixas2[j].valor = consultar_proximo_valor(&e->f1);
					caixas2[j].chave = consultar_proxima_chave(&e->f1);
					caixas2[j].classe = obter_proxima_chave(&e->f1);
					clientes--;
					fprintf(arq2,"Caixa: %d - Cliente: %d - Tempo: %d min - Espera: %d min.\n", j, caixas2[j].chave, caixas2[j].valor*5, caixas2[j].time1*5);
					caixas2[j].time1 = caixas2[j].time1 + caixas2[j].valor;
					i++;
				}
				if(caixas2[j].valor != 0){
                    caixas2[j].valor--;
                        j++;
				}
			}else{
				i++;
			}
		}
		i = 0;
while(i < disc1[1]){
    if(consultar_proxima_chave(&e->f2) != -1){
			if(j == caixas1){
                    j = 0;
				}
				if(caixas2[j].valor == 0){
					caixas2[j].valor = consultar_proximo_valor(&e->f2);
					caixas2[j].chave = consultar_proxima_chave(&e->f2);
					caixas2[j].classe = obter_proxima_chave(&e->f2);
					clientes--;
					fprintf(arq2,"Caixa: %d - Cliente: %d - Tempo: %d min - Espera: %d min.\n", j, caixas2[j].chave, caixas2[j].valor*5, caixas2[j].time1*5);
					caixas2[j].time1 = caixas2[j].time1 + caixas2[j].valor;
					i++;
				}
				if(caixas2[j].valor != 0){
                    caixas2[j].valor--;
                        j++;
				}
			}else{
				i++;
			}
        }
i = 0;
while(i < disc1[2]){
        if(consultar_proxima_chave(&e->f3) != -1){
				if(j == caixas1){
					j = 0;
				}
				if(caixas2[j].valor == 0){
					caixas2[j].valor = consultar_proximo_valor(&e->f3);
					caixas2[j].chave = consultar_proxima_chave(&e->f3);
					caixas2[j].classe = obter_proxima_chave(&e->f3);
					clientes--;
					fprintf(arq2,"Caixa: %d - Cliente: %d - Tempo: %d min - Espera: %d min.\n", j, caixas2[j].chave, caixas2[j].valor*5, caixas2[j].time1*5);
					caixas2[j].time1 = caixas2[j].time1 + caixas2[j].valor;
					i++;
				}
				if(caixas2[j].valor != 0){
                    caixas2[j].valor--;
                        j++;
				}
			}else{
				i++;
			}
		}
i = 0;
while(i < disc1[3]){
			if(consultar_proxima_chave(&e->f4) != -1){
				if(j == caixas1){
					j = 0;
				}
				if(caixas2[j].valor == 0){
					caixas2[j].valor = consultar_proximo_valor(&e->f4);
					caixas2[j].chave = consultar_proxima_chave(&e->f4);
					caixas2[j].classe = obter_proxima_chave(&e->f4);
					clientes--;
					fprintf(arq2,"Caixa: %d - Cliente: %d - Tempo: %d min - Espera: %d min.\n", j, caixas2[j].chave, caixas2[j].valor*5, caixas2[j].time1*5);
					caixas2[j].time1 = caixas2[j].time1 + caixas2[j].valor;
					i++;
				}
				if(caixas2[j].valor != 0){
                    caixas2[j].valor--;
                        j++;
				}
			}else{
				i++;
			}
		}
i = 0;
while(i < disc1[4]){
        if(consultar_proxima_chave(&e->f5) != -1){
            if(j == caixas1){
                j = 0;
				}
                if(caixas2[j].valor == 0){
					caixas2[j].valor = consultar_proximo_valor(&e->f5);
					caixas2[j].chave = consultar_proxima_chave(&e->f5);
					caixas2[j].classe = obter_proxima_chave(&e->f5);
					clientes--;
					fprintf(arq2,"Caixa: %d - Cliente: %d - Tempo: %d min - Espera: %d min.\n", j, caixas2[j].chave, caixas2[j].valor*5, caixas2[j].time1*5);
					caixas2[j].time1 = caixas2[j].time1 + caixas2[j].valor;
					i++;
				}
				if(caixas2[j].valor != 0){
                    caixas2[j].valor--;
                        j++;
				}
			}else{
				i++;
			}
		}
i = 0;
}

int time2=0;

    for(j = 0; j < caixas1; j++){
		if(time2 < caixas2[j].time1){
        time2 = caixas2[j].time1;
		}
	}
	fprintf(arq2,"Tempo Final: %d min.\n", time2*5);

	fclose(arq);
	fclose(arq2);

	return EXIT_SUCCESS;
}
