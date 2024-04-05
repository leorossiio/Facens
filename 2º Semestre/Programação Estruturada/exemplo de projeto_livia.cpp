#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct composto{
	char sigla;
	int num;
}composto;

typedef struct hospede{
	numreg;
	char nome[80];
	int acompanhante;
	char categoria;
	int dias;
}hospede;

typedef struct quarto{
	int num;
	char categoria;
}quarto;

void aloca_quarto(quarto **pq, int qq);
void aloca_hospede(hospede **ph, int qh);
int verifica_arq_quarto();
int verifica_arq_hospede();
void cadastro_quarto(quarto *pq, int qq);
void cadastro_hospede(hospede *ph, quarto *pq);
void grava_hospede(hospede *ph);
int busca_quarto(quarto *pq, char letra, int qq, int numreg);
void busca_hospede(hospede *ph, int numreg);
void encerra_quarto(hospede *ph, quarto *pq, int qq, int n_quarto);
void mostra_hospede(hospede *ph, int n_quarto);
void mostra_quarto(quarto *pq, int qq);


main()
{
	quarto *q=NULL;
	hospede *hosp=NULL;
	int op, n_quarto, qq;
	
	
	aloca_quarto(&q, 1);
	qq=verifica_arq_quarto();
	
	if(qq==0)
		cadastro_quarto(q,15);
		aloca_hospede(&hosp,1);
	do{
		system("cls");
		printf("[1]Check-in\n[2]Check-out\n[3]Mostra Hospedes\n[4]Mostra Quarto\n[5]");
		scanf("%i", &op);
		fflush(stdin);
		
		switch(op)
		{
			case 1: castro_hospede(hosp,q); //passa o ponteiro de hospede e de quarto, porque teremos que buscar quarto vago
			system("pause");
			break;
			case 2: printf("\nQuarto a ser encerradp: ").
					scanf("%i", &n_quarto);
					fflush(stdin);
					mostra_hospede(hosp,n_quarto);
					encerra_quarto(hosp,q,15,n_quarto);
					break;
			case 3: mostra_hospede(hosp,0); //0 para indicar TODOS
					system("pause");
					break;
			case 4: mostra_quarto(q,15);
					system("pause");
					break;
		}
	}while(op!=5);
	
system("pause");
}//main

void aloca_quarto(quarto **pq, int qq)
{
	if(((*pq=(quarto*)realloc(*pq,qq*sizeof(quarto)))==NULL))
	exit(1);
}

void aloca_hospede(hospede **ph, int qh)
{
	if(((*ph=(hospede*)realloc(*ph,qh*sizeof(hospede)))==NULL))
	exit(1);
}

int verifica_arq_quarto()
{
	long int cont=0;
	FILE *fquarto=NULL;
	if((fquarto=fopen("quarto.bin", "rb"))==NULL) //VERIFICA SE O ARQUIVO JÁ EXISTE
	return cont;
	
	else
	{
		fseek(fquarto,0,2); //posiciona no fim do arquivo
		cont=ftell(fquarto)/sizeof(quarto); //Qtde de elementos
		fclose(fquarto); //dentro do ELSE por conta do rb
		return cont;
	}
}

int verifica_arq_hospede()
{
	long int cont=0;
	FILE *fhosp=NULL;
	if((fhosp=fopen("hospede.bin","rb"))==NULL)
	 return cont;
	else
	{
		fseek(fhosp,0,2); //posiciona no fim do arquivo
		cont=ftell(fhosp)/sizeof(hospede); //qtde de elementos
		fclose(fhosp); //dentro do else por conta do rb
		return cont;
	}//else
}//verifica_arq_hospede

void cadastro_quarto(quarto *pq, int qq)
{
	FILE *fquarto=NULL;
	int i;
	if((fquarto=fopen("quarto.bin", "ab"))==NULL)
	printf("Erro");
	else
		for(i=0;i<qq;i++)
		{
		if(i<5)
			pq->categoria='S';
		else
			pq->categoria='F';
		
		pq->num=i+1;
		pq->status.sigla='L';
		fseek(fquarto, i*sizeof(quarto),0);//FSEKK POSICIONA O CURSOR 
		fwrite(pq,sizeof(quarto),1,fquarto);
		}//for
	fclose(fquarto); //fora do ELSE por conta do ab
}//cadastra_quarto

void cadastro_hospede(hospede *ph, quarto *pq)
{
	int qh, aux_quarto;
	
	qh=verifica_arq_hospede(); //descobre quantos hospedes tem no arquivo
	system("cls");
	ph->numreg=++qh; //1 a mais que a qtde de hospedes
	printf("\nRegistro: %i\n", ph->numreg);
	printf("\nNome: ");
	gets(ph->nome);
	fflush(stdin);
	
	do{
		printf("\nQtde de acompanhantes - max.3: ");
		scanf("%i", &(ph->acompanhante));
		fflush(stdin);
	}while(ph->acompanhante<0 || ph->acompanhante>3);
	
	if(ph->acompanhante==0)
	{
		aux_quarto=busca_quarto(pq,'S', 15,ph->numreg);
		ph->categoria='S';
	}
	else
	{
		aux_quarto=busca_quarto(pq,'F', 15,ph->numreg);
		ph->categoria='F';
	}
	
	if(aux_quarto==-1)
		printf("\nHotel Lotado\n\n");
	else
	
}
