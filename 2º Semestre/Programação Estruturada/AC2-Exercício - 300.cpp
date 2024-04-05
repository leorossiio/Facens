#include <stdio.h>
#include <stdlib.h>

typedef struct carro {
    int reg_carro;
    char tipo;
    char status;
} carro;

typedef struct cliente {
    char CPF[13];
    char nome[80];
    int num_reg;
    int dias;
} cliente;

void aloca_carro(carro **pc, int tam);
void aloca_cliente(cliente **pcli, int tam);
void cadastro_carro(carro *pc, int tam);
void cadastro_cliente(cliente *pcli, carro *pc, int tam);
int busca_carro(carro *pc, int tam, char tipo);
void mostra_carro(carro *pc, int tam);

int main() {
    carro *pc = NULL;
    cliente *pcli = NULL;
    int cont = 0, op, nreg;
    aloca_carro(&pc, 15);
    cadastro_carro(pc, 15);

    do {
        system("cls");
        printf("\n[1]Alugar\n[2]Devolucao\n[3]Fim\n");
        scanf("%i", &op);
        fflush(stdin);

        switch (op) {
            case 1:
                mostra_carro(pc, 15);
                aloca_cliente(&pcli, cont + 1);
                cadastro_cliente(pcli + cont, pc, 15);
                cont++;
                break;
        }
    } while (op != 3);

    free(pc);
    free(pcli);
    return 0;
}

void aloca_carro(carro **pc, int tam) {
    if ((*pc = (carro *) realloc(*pc, tam * sizeof(carro))) == NULL)
        exit(1);
}

void aloca_cliente(cliente **pcli, int tam) {
    if ((*pcli = (cliente *) realloc(*pcli, tam * sizeof(cliente))) == NULL)
        exit(1);
}

void cadastro_carro(carro *pc, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        (pc + i)->reg_carro = i + 1;

        if (i < 5)
            (pc + i)->tipo = 'p';
        else if (i > 5 && i < 11)
            (pc + i)->tipo = 'm';
        else
            (pc + i)->tipo = 'g';

        (pc + i)->status = 'l';
    }
}

void cadastro_cliente(cliente *pcli, carro *pc, int tam) {
    printf("\n\nCPF: ");
    gets(pcli->CPF);
    fflush(stdin);

    printf("Nome: ");
    gets(pcli->nome);
    fflush(stdin);

    printf("Escolha o tamanho do carro [p]pequeno [m]medio [g]grande: ");
    scanf("%c", &pc->tipo);
    fflush(stdin);

    pcli->num_reg = busca_carro(pc, tam, pc->tipo);

    if (pcli->num_reg == -1) {
        printf("Modelo indisponivel");
    } else {
        printf("Qtde dias: ");
        scanf("%i", &pcli->dias);
        fflush(stdin);
        printf("\nCadastro realizado com sucesso!");
    }

    printf("\nVeiculo: %i Tamanho: %c por %i dias.", pc->reg_carro, pc->tipo, pcli->dias);
    system("pause");
}

void mostra_carro(carro *pc, int tam){
int i;
for(i=0;i<tam;i++,pc++){
printf("\nCarro: %i Tamanho: %c Status: %c", pc->reg_carro, pc->tipo, pc->status);
}
}
int busca_carro(carro *pc, int tam, char tipo){
int i;
for(i=0;i<tam;i++,pc++)
if(pc->tipo==tipo && pc->status=='l')
{
pc->status='o';
return pc->reg_carro;
}
return -1;
}
