//Exemplo 1
#include <stdio.h>
#include <stdlib.h>

//Prot�tipo das fun��es
void aloca(int **p, int tam);
void leitura(int *p);
int soma(int *p, int tam, int **ppar, int *qpar);
void mostra(int *p, int tam);

int main()
{
    int *ptr = NULL, *ptrpar = NULL; //Ponteiros inicialmente nulos
    char op; //Vari�vel para ler a op��o do usu�rio
    int cont = 0, qtdpar = 0; //Contadores

    do {
        aloca(&ptr, cont + 1); //Aloca espa�o dinamicamente para o pr�ximo n�mero
        leitura(ptr + cont); //L� o n�mero digitado e o armazena na posi��o alocada
        cont++; //Incrementa o contador
        printf("\nDeseja continuar <S/N>: ");
        scanf(" %c", &op); //L� a op��o do usu�rio
        fflush(stdin); //Limpa o buffer do teclado
    } while (op != 'n' && op != 'N'); //Enquanto o usu�rio n�o digitar 'n' ou 'N', continua o loop

    printf("\nNumeros digitados:\n");
    mostra(ptr, cont); //Mostra os n�meros digitados

    soma(ptr, cont, &ptrpar, &qtdpar); //Realiza a soma dos pares e aloca espa�o para armazenar os resultados

    printf("\nResultados pares:\n");	
    mostra(ptrpar, qtdpar); //Mostra os n�meros pares

    printf("\n");
    system("pause"); //Pausa o programa para o usu�rio visualizar os resultados
    return 0;
}

//Fun��o para alocar espa�o dinamicamente
void aloca(int **p, int tam)
{
    if ((*p = (int*) realloc(*p, tam * sizeof(int))) == NULL) { //Se n�o conseguir alocar o espa�o necess�rio, o programa encerra
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
}

//Fun��o para ler um n�mero inteiro
void leitura(int *p)
{
    printf("\nNumero: ");
    scanf("%d", p);
    fflush(stdin);
}

//Fun��o para somar os n�meros e armazenar os pares
int soma(int *p, int tam, int **ppar, int *qpar)
{
    int i, resul_soma = 0;

    for (i = 0; i < tam / 2; i++) { //Realiza a soma apenas at� a metade dos n�meros digitados
        resul_soma = *(p + i) + *(p + tam - 1 - i); //Soma o n�mero atual com o seu correspondente no final do vetor
        if (resul_soma % 2 == 0) { //Se a soma for par
            aloca(ppar, *qpar + 1); //Aloca espa�o para armazenar o n�mero par
            *(*ppar + *qpar) = resul_soma; //Armazena o n�mero par no espa�o alocado
            (*qpar)++; //Incrementa o contador de n�meros pares
        }
    }
}

//Fun��o para mostrar os n�meros
void mostra(int *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
        printf("\n%d", *(p + i));
}


/*

Esse c�digo as seguintes opera��es:
Inclui as bibliotecas padr�o stdio.h e stdlib.h;
Define os prot�tipos das fun��es aloca(), leitura(), soma() e mostra();
Define a fun��o principal main();
Declara os ponteiros ptr e ptrpar como nulos, bem como a vari�vel op, cont e qtdpar como zero;
Inicia um loop do-while que executa as seguintes a��es:
a. Aloca espa�o dinamicamente para o pr�ximo n�mero digitado pelo usu�rio usando a fun��o aloca();
b. L� o n�mero digitado e armazena na posi��o alocada usando a fun��o leitura();
c. Incrementa o contador cont;
d. Pergunta ao usu�rio se ele deseja continuar digitando n�meros;
e. Limpa o buffer do teclado.
Mostra os n�meros digitados usando a fun��o mostra();
Realiza a soma dos pares dos n�meros digitados usando a fun��o soma();
Mostra os n�meros pares usando a fun��o mostra();
Pausa o programa para o usu�rio visualizar os resultados e retorna 0 para indicar que o programa foi executado com sucesso.
A fun��o aloca() � usada para alocar espa�o dinamicamente para um vetor. A fun��o leitura() � usada para ler um n�mero inteiro. 
A fun��o soma() � usada para somar os n�meros digitados e armazenar os pares em outro vetor. A fun��o mostra() � usada para mostrar os n�meros armazenados em um vetor.
*/

