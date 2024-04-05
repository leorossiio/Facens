//grupo4
//Nelson Stropa Junior RA:211916
//Leonardo Rossi de Oliveira RA:222410


//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Estrutura
typedef struct produto {
int reg_prod;
char tipo[20];
char descricao[80];
float preco;
}produto;


typedef struct venda{
int reg_venda;
char nome[80];
char CPF[15];
int reg_prod;
int qtde;
float preco;
float total;
char pago;
}venda;


//Funções etapa 1:
void aloca_produto(produto **p, int tam);
int verifica_arquivo();
void cadastro_produto(produto *p);
int busca_produto(produto *p, int n_reg);
int busca_livre(produto *p, int qtde);
void salvamento(produto *p, char *string, int position);
void mostra_produto_total(produto *p);
void mostra_produto_parcial(produto *p);
void altera_or_deleta(produto *p, int op);
void imprimirLinha(char ch, int quantidade);
void exibirMenu();



//Funções etapa 2:
void aloca_venda(venda **v, int tam);
int verifica_arquivo_venda();
void historico_venda(venda *v, produto *p, int num_vendas);
void salvamento_vendas(venda *v, char *str, int pos);
void mostra_venda_pagamento (venda *v);
void mostra_venda_cpf(venda *v);
int busca_preco(produto *p, int reg_prod);
int numero_vendas();
int busca_reg(produto *p, int reg_prod);

//Main
int main() {
produto *ptr = NULL;
aloca_produto(&ptr,1);
venda *ptrvenda = NULL;
aloca_venda(&ptrvenda,1);
int op, opcao, nvendas = 0;

do {
system("cls");
exibirMenu();
scanf("%d", &op);
fflush(stdin);
switch (op)
{
case 1:
cadastro_produto(ptr);
printf("\nProduto cadastrado\n\n");
system("pause");
break;

case 2:
do{
mostra_produto_total(ptr);
printf("\nDeseja voltar? [1] Sim / [2] Nao: ");
scanf("%i", &opcao);
fflush(stdin);
}while(opcao !=1);
break;

case 3:
do{
mostra_produto_parcial(ptr);
printf("\nDeseja tentar novamente? [1] Sim / [2] Nao: ");
scanf("%i", &opcao);
fflush(stdin);
}while(opcao !=2);
break;

case 4:
case 5: altera_or_deleta(ptr,op);
break;

case 6: historico_venda(ptrvenda,ptr,nvendas);
		printf("Venda cadastrada!");
		break;
		
case 7:	mostra_venda_pagamento(ptrvenda);
		system("Pause");
		break;

case 8:	mostra_venda_cpf(ptrvenda);
		system("Pause");
		break;
}
}while (op != 9);

return 0;
}

//Aloca Produto
void aloca_produto(produto **p, int tam)
{
	if ((*p=(produto*)realloc(*p, tam*sizeof(produto))) == NULL)
{
	printf("Erro ao alocar memória.\n");
	exit(1);
	}
}

//Aloca venda
void aloca_venda(venda **v, int tam) {
    if ((*v=(venda*)realloc(*v, tam*sizeof(venda))) == NULL) 
	{
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
}

/*
aloca_produto: Aloca memória dinamicamente para a estrutura produto com base em um tamanho especificado.
*/

//Verifica_arquivo
int verifica_arquivo()
{
long int cont=0;
FILE *fileptr=NULL;
if((fileptr=fopen("produtos.bin", "rb"))==NULL)
return cont;

else
{
fseek(fileptr,0,2);
cont=ftell(fileptr)/sizeof(produto);
fclose(fileptr);
return cont;
}
}

int verifica_arquivo_venda()
{
	long int cont=0;
	FILE *ptrfile=NULL;
	
if((ptrfile=fopen("vendas.bin", "rb"))==NULL)
return cont;

else
{
fseek(ptrfile,0,2);
cont=ftell(ptrfile)/sizeof(venda);
fclose(ptrfile);
return cont;
}
}

/*
verifica_arquivo: Verifica o número de registros existentes em um arquivo de dados (produtos.bin).
*/

//Cadastra Produto
void cadastro_produto(produto *p)
{
int qverif, id;
qverif=verifica_arquivo(); //verifica o numero de registros
id=busca_livre(p,qverif);

if(id!=-1) //livre
qverif=id;
p->reg_prod=qverif+1;
printf("\nNumero de Registro: %i", p->reg_prod);
printf("\n\nTipo do produto: ");
gets(p->tipo);
fflush(stdin);
printf("\nDescricao: ");
gets(p->descricao);
fflush(stdin);
printf("\nPreco: ");
scanf("%f", &p->preco);
fflush(stdin);

if(id==-1)
salvamento(p, "ab",1);

else
salvamento(p, "rb+",qverif);
}

/*
cadastro_produto: Permite o cadastro de um novo produto, solicitando informações ao usuário e salvando os dados no arquivo.
*/

//Salvamento/grava
void salvamento(produto *p, char *string, int position)
{
FILE *fileptr=NULL;

if((fileptr=fopen("produtos.bin", string))==NULL)
printf("Erro ao gravar arquivo!");

else
{
if(strcmp(string,"rb+")==0)
fseek(fileptr, position*sizeof(produto),0);
fwrite(p, sizeof(produto),1,fileptr);
}
fclose(fileptr); //Fora do else (Pois usa-se ab ou rb+)
}

/*
salvamento: Salva os dados de um produto no arquivo, em uma posição especificada.
*/

//Mostra Produto Total
void mostra_produto_total(produto *p)
{
int opcao;
int i,qverif;
FILE *fileptr=NULL;
qverif=verifica_arquivo(); //quantidade de registros
system("cls");
printf("\n\t[Produtos cadastrados]\n\n");
imprimirLinha('-', 50);
if((fileptr=fopen("produtos.bin","rb"))==NULL)
printf("\nErro na abertura do arquivo");
else
{

for(i=0;i<qverif;i++)
{
fseek(fileptr,i*sizeof(produto),0);
fread(p,sizeof(produto),1,fileptr);
if(p->preco!=-1)
printf("\nRegistro: %i\nTipo de Produto: %s\nDescricao: %s\nPreco: %.2f\n",p->reg_prod,p->tipo,p->descricao,p->preco);
}

fclose(fileptr);
}
}

/*
mostra_produto_total: Mostra todos os produtos cadastrados no arquivo.
*/

//Mostra Produto Parcial
void mostra_produto_parcial(produto *p)
{
int i, qverif, comparacao;
char tipo[20];
FILE *fileptr = NULL;
qverif=verifica_arquivo();
system("cls");

printf("| Consulta Pelo Tipo do Produto |\n\nDigite o tipo do produto: ");
gets(tipo);
fflush(stdin);

if((fileptr=fopen("produtos.bin", "rb"))==NULL)
printf("ERRO ENCONTRADO!");

else
{

for(i=0;i<qverif;i++)
{
fseek(fileptr, i*sizeof(produto), 0);
fread(p, sizeof(produto), 1, fileptr);
comparacao=strcasecmp(tipo, p->tipo);
if(comparacao == 0)
printf("\nRegistro: %i\nTipo de produto: %s\nDescricao: %s\nPreco: %.2f\n\n",p->reg_prod, p->tipo, p->descricao, p->preco);
}
}
}

/*
mostra_produto_parcial: Mostra os produtos filtrados por tipo, com base na entrada fornecida pelo usuário.
*/

//Busca Produto
int busca_produto(produto *p, int n_reg)
{
FILE *fileptr=NULL;
int qverif, encontrou=-1, i;
qverif=verifica_arquivo();
system("cls");
if((fileptr=fopen("produtos.bin", "rb"))==NULL)
printf("\nErro!");
else
{
for(i=0;i<qverif;i++)
{
fseek(fileptr,i*sizeof(produto),0);
fread(p,sizeof(produto),1,fileptr);
if(p->reg_prod==n_reg)
{
encontrou=i;
i=qverif;
}
}
fclose(fileptr);
}
return encontrou;
}

/*
busca_produto: Busca um produto no arquivo com base no número de registro.
*/

//Busca livre/vago
int busca_livre(produto *p, int qtde)
{
FILE *fileptr=NULL;
int encontrou=-1,i;
system("cls");
if((fileptr=fopen("produtos.bin", "rb"))==NULL)
return encontrou;

else
{
for(i=0;i<qtde;i++)
{
fseek(fileptr,i*sizeof(produto),0);
fread(p,sizeof(produto),1,fileptr);
if(p->preco==-1)
{
encontrou=i;
i=qtde;
}
}
fclose(fileptr);
return encontrou;
}
}

/*
busca_livre: Verifica se há algum registro livre no arquivo para adicionar um novo produto.
*/


void altera_or_deleta(produto *p, int op)
{
int n_reg,position;
mostra_produto_total(p);

if(op==4)
{
printf("\nRegistro do produto a ser ALTERADO: ");
scanf("%i",&n_reg);
fflush(stdin);
}
else{
printf("\nRegistro do produto a ser DELETADO: ");
scanf("%i",&n_reg);
fflush(stdin);
}

position=busca_produto(p,n_reg);
if(position==-1)
printf("\nRegistro não encontrado\n\n");

else
{
printf("\nRegistro: %i\nTipo: %s\nDescricao: %s\nPreco atual: %.2f\n",p->reg_prod,p->tipo,p->descricao,p->preco);

if(op==4) //altera
{
printf("\nNovo preco para o produto selecionado: ");
scanf("%f",&(p->preco));
fflush(stdin);
}
else
p->preco=-1;
salvamento(p,"rb+",position);
printf("\nPreco ALTERADO/DELETADO com sucesso\n\n");
system("pause");
}
}//altera/deleta







void historico_venda(venda *v, produto *p, int num_vendas) 
{
int i,reg_venda,rp;
int num_vendass = numero_vendas()+1;

for(i=0;i<num_vendass;i++){
v->reg_venda = num_vendass;

	printf("\nNumero do Registro da venda: %i", v->reg_venda);
	printf("\n\nNome do comprador: ");
	gets(v->nome);
	fflush(stdin);
	printf("\nCPF: ");
	gets(v->CPF);
	fflush(stdin);	
	//do{
		printf("\nRegistro do produto: ");
		scanf("%d", &v->reg_prod);
		rp = busca_reg(p,v->reg_prod);
		fflush(stdin);
		if (rp == -1){
			printf("Produto inexistente\n");
			system("Pause");
			break;
		} else{

		//printf("%d",rp);
	//}while(rp == -1);
	fflush(stdin);
	printf("\nQuantidade: ");
	scanf("%d", &v->qtde);
	fflush(stdin);
	//Código para buscar o preço
	v->preco = busca_preco(p,v->reg_prod);
	//Calculo total
	
	v->total = v->preco * v->qtde;
	v->pago='N';
	
	
	salvamento_vendas(v, "ab",1);
	
	printf("Cadastrado com sucesso\n");
	system("Pause");
	break;
}}
fflush(stdin);
}




	void salvamento_vendas(venda *v, char *str, int pos)
	{
		FILE *ptrfile=NULL;
		
		if((ptrfile=fopen("vendas.bin", str))==NULL)
		printf("Erro!");
		
		else
		{
			if(strcmp(str, "rb+")==0)
			fseek(ptrfile, pos*sizeof(venda),0);
			fwrite(v,sizeof(venda),1,ptrfile);
		}
		fclose(ptrfile);
	}







//Mostra venda pagamento
void mostra_venda_pagamento(venda *v)
{
int i, qverif, comparacao;
char tipo;
FILE *ptrfile = NULL;
qverif=verifica_arquivo_venda();
system("cls");

printf("| Consulta Pelo pagamento |\n\n Esta pago [S] Sim [N] Nao ");
scanf("%c",&tipo);
fflush(stdin);

//tipo[20] = toupper(tipo[20]);

if((ptrfile=fopen("vendas.bin", "rb"))==NULL)
printf("ERRO ENCONTRADO!");

else
{

for(i=0;i<qverif;i++)
{
fseek(ptrfile, i*sizeof(venda), 0);
fread(v, sizeof(venda), 1, ptrfile);
if(tipo == 'N' || tipo=='n')
printf("\nRegistro: %i\nNome: %s\nCPF: %s\nRegistro do produto: %d\nQuantidade: %i\nPreco: %.2f\nTotal: %.2f\n",v->reg_venda, v->nome, v->CPF,v->reg_prod, v->qtde, v->preco, v->total);
}
}
}

//Busca preco
int busca_preco(produto *p, int reg_prod)
{
FILE *fileptr=NULL;
int qverif, i;
float preco=0;
qverif=verifica_arquivo();
system("cls");
if((fileptr=fopen("produtos.bin", "rb"))==NULL)
printf("\nErro!");
else
{
for(i=0;i<qverif;i++)
{
fseek(fileptr,i*sizeof(produto),0);
fread(p,sizeof(produto),1,fileptr);
if(p->reg_prod==reg_prod)
{
preco=p->preco;
i=qverif;
}
}
fclose(fileptr);
}
return preco;
}

//Busca reg
int busca_reg(produto *p, int reg_prod)
{
FILE *fileptr=NULL;
int qverif, i;
float preco=0;
qverif=verifica_arquivo();
system("cls");
if((fileptr=fopen("produtos.bin", "rb"))==NULL)
printf("\nErro!");
else
{
for(i=0;i<qverif;i++)
{
fseek(fileptr,i*sizeof(produto),0);
fread(p,sizeof(produto),1,fileptr);
if(p->reg_prod==reg_prod)
{
preco= 1;
i=qverif;
} else {
	preco = -1;
}
}
fclose(fileptr);
}
return preco;

}

//Mostra venda CPF
void mostra_venda_cpf(venda *v)
{
int i, qverif, comparacao;
char tipo[20];
FILE *ptrfile = NULL;
qverif=verifica_arquivo_venda();
system("cls");

printf("| Consulta por CPF |\n\nDigite o CPF: ");
gets(tipo);
fflush(stdin);

if((ptrfile=fopen("vendas.bin", "rb"))==NULL)
printf("ERRO ENCONTRADO!");

else
{

for(i=0;i<qverif;i++)
{
fseek(ptrfile, i*sizeof(venda), 0);
fread(v, sizeof(venda), 1, ptrfile);
comparacao=strcasecmp(tipo, v->CPF);
if(comparacao == 0)
printf("\nRegistro: %i\nNome: %s\nCPF: %s\nRegistro do produto: %d\nQuantidade: %i\nPreco: %.2f\nTotal: %.2f\n",v->reg_venda, v->nome, v->CPF,v->reg_prod, v->qtde, v->preco, v->total);
}
}
}

int numero_vendas()
{
	FILE *ptrfile = NULL;
	venda v;
	long int num_vendas = 0;
	
	if((ptrfile = fopen("vendas.bin","rb")) == NULL){
		printf("ERRO AO ABRIR!");
	} else {
		fseek(ptrfile, 0 ,SEEK_END);
		num_vendas=ftell(ptrfile)/sizeof(venda);
		fclose(ptrfile);
	}
	
	return num_vendas;
}



//Funções para estética do projeto:


void imprimirLinha(char ch, int quantidade)
{
for (int i = 0; i < quantidade; i++) {
printf("%c", ch);
}
printf("\n");
}//ImprimirLinha

void exibirMenu()
{
imprimirLinha('=', 50);
printf(" SISTEMA DE GERENCIAMENTO DE PRODUTOS\n");
imprimirLinha('=', 50);
printf("[1] Cadastrar Produto\n[2] Consulta total\n[3] Consulta parcial\n[4] Alterar o preco\n[5] Deletar produto\n[6] Vendas \n[7] Consultar vendas\n[8] Consultar por CPF\n[9] Fechar\n");
imprimirLinha('=', 50);
printf("Opcao: ");
}//exibirMenu
