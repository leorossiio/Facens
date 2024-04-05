#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct carro {
int reg_carro; // registro do carro
char tipo; // [P]equeno, [M]édio ou [G]rande
char status; // [L]ivre ou [A]lugado
}carro;

typedef struct cliente {
char CPF[13]; // CPF do cliente
char nome[80]; // nome do cliente
int num_reg; // número do carro alugado
int dias; // tempo de permanência - em dias
}cliente;

void aloca_carro(carro **pc, int tam);
void aloca_cliente(cliente **pcli, int tam);
void cadastra_carro(carro *pc, int tam);
void cadastro_cliente(cliente *pcli, carro *pc, int tam);
void mostra_carro(carro *pc, int tam);
int busca_carro(carro *pc, int tam, char tipo);

int main ()
{
	carro *pc = NULL;
	cliente *pcli = NULL;
	
	int cont=0, op;
	
	aloca_carro(&pc,15);
	cadastra_carro(pc,15);
	
	do{
		system("cls");
		printf("\n[1]Alugar\n[2]Devolucao\n[3]Fim\n");
		scanf("%i",&op);
		fflush(stdin);
		switch(op)
		{
		case 1: mostra_carro(pc,15);
				aloca_cliente(&pcli,cont+1);
				cadastro_cliente(pcli+cont,pc,15);
				cont++;
				break;
		}
	}while(op!=3);
	
}

	void aloca_carro(carro **pc,int tam)
	{	
		if((*pc=(carro*)realloc(*pc,tam*sizeof(carro)))==NULL)
		exit(1);
	}
	
	void aloca_cliente(cliente **pcli,int tam)
	{
		if((*pcli=(cliente*)realloc(*pcli, tam*sizeof(cliente)))==NULL)
		exit(1);
	}
	
	void cadastra_carro(carro *pc, int tam)
{
	int i;
	
	for(i=0;i<tam;i++)
	{
		(pc+i)->reg_carro=i+1;
		if(i<5)		
		(pc+i)->tipo='P';
		else
		{
		
		if(i>=5 && i<10)
		{
			(pc+i)->tipo='M';
	    }
	    else
		(pc+i)->tipo='G';
	   } 
		(pc+i)->status='L';
	}
}
	
void cadastro_cliente(cliente *pcli, carro *pc, int tam)
{
    printf("\n\nCPF: ");
    gets(pcli->CPF);
    fflush(stdin);
    printf("Nome: ");
    gets(pcli->nome);
    fflush(stdin);
    printf("Escolha o modelo do carro - [P]pequeno [M]medio [G]grande: ");
    scanf("%c", &pc->tipo);
    pc->tipo = toupper(pc->tipo); 
    fflush(stdin);
    printf("Qtde dias: ");
    scanf("%i", &pcli->dias);
    fflush(stdin);
    pcli->num_reg = busca_carro(pc, 15, pc->tipo);

    if(pcli->num_reg == -1)
        printf("Modelo indisponivel");
    else
        printf("\nCadastro realizado com sucesso! Veiculo: %i Tamanho: %c por %i dias.\n", pcli->num_reg, pc->tipo, pcli->dias);

    system("pause");
}

	
	void mostra_carro(carro *pc, int tam)
	{
		int i;
		for(i=0;i<tam;i++,pc++)
		{
			printf("\nCarro: %i Tamanho: %c Status: %c", pc->reg_carro, pc->tipo, pc->status);
			printf("\n");
		}
	}
	
int busca_carro(carro *pc, int tam, char tipo)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        if ((pc + i)->tipo == tipo && (pc + i)->status == 'L')
        {
            (pc + i)->status = 'O';
            return (pc + i)->reg_carro;
        }
    }

    return -1;
}
