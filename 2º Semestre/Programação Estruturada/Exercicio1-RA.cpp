//Exemplo 1
#include <stdio.h>
#include <stdlib.h>

//Protótipo das funções
void aloca(int **p, int tam);
void leitura(int *p);
int soma(int *p, int tam, int **ppar, int *qpar);
void mostra(int *p, int tam);

int main()
{
    int *ptr = NULL, *ptrpar = NULL; //Ponteiros inicialmente nulos
    char op; //Variável para ler a opção do usuário
    int cont = 0, qtdpar = 0; //Contadores

    do {
        aloca(&ptr, cont + 1); //Aloca espaço dinamicamente para o próximo número
        leitura(ptr + cont); //Lê o número digitado e o armazena na posição alocada
        cont++; //Incrementa o contador
        printf("\nDeseja continuar <S/N>: ");
        scanf(" %c", &op); //Lê a opção do usuário
        fflush(stdin); //Limpa o buffer do teclado
    } while (op != 'n' && op != 'N'); //Enquanto o usuário não digitar 'n' ou 'N', continua o loop

    printf("\nNumeros digitados:\n");
    mostra(ptr, cont); //Mostra os números digitados

    soma(ptr, cont, &ptrpar, &qtdpar); //Realiza a soma dos pares e aloca espaço para armazenar os resultados

    printf("\nResultados pares:\n");	
    mostra(ptrpar, qtdpar); //Mostra os números pares

    printf("\n");
    system("pause"); //Pausa o programa para o usuário visualizar os resultados
    return 0;
}

//Função para alocar espaço dinamicamente
void aloca(int **p, int tam)
{
    if ((*p = (int*) realloc(*p, tam * sizeof(int))) == NULL) { //Se não conseguir alocar o espaço necessário, o programa encerra
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
}

//Função para ler um número inteiro
void leitura(int *p)
{
    printf("\nNumero: ");
    scanf("%d", p);
    fflush(stdin);
}

//Função para somar os números e armazenar os pares
int soma(int *p, int tam, int **ppar, int *qpar)
{
    int i, resul_soma = 0;

    for (i = 0; i < tam / 2; i++) { //Realiza a soma apenas até a metade dos números digitados
        resul_soma = *(p + i) + *(p + tam - 1 - i); //Soma o número atual com o seu correspondente no final do vetor
        if (resul_soma % 2 == 0) { //Se a soma for par
            aloca(ppar, *qpar + 1); //Aloca espaço para armazenar o número par
            *(*ppar + *qpar) = resul_soma; //Armazena o número par no espaço alocado
            (*qpar)++; //Incrementa o contador de números pares
        }
    }
}

//Função para mostrar os números
void mostra(int *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
        printf("\n%d", *(p + i));
}


/*

Esse código as seguintes operações:
Inclui as bibliotecas padrão stdio.h e stdlib.h;
Define os protótipos das funções aloca(), leitura(), soma() e mostra();
Define a função principal main();
Declara os ponteiros ptr e ptrpar como nulos, bem como a variável op, cont e qtdpar como zero;
Inicia um loop do-while que executa as seguintes ações:
a. Aloca espaço dinamicamente para o próximo número digitado pelo usuário usando a função aloca();
b. Lê o número digitado e armazena na posição alocada usando a função leitura();
c. Incrementa o contador cont;
d. Pergunta ao usuário se ele deseja continuar digitando números;
e. Limpa o buffer do teclado.
Mostra os números digitados usando a função mostra();
Realiza a soma dos pares dos números digitados usando a função soma();
Mostra os números pares usando a função mostra();
Pausa o programa para o usuário visualizar os resultados e retorna 0 para indicar que o programa foi executado com sucesso.
A função aloca() é usada para alocar espaço dinamicamente para um vetor. A função leitura() é usada para ler um número inteiro. 
A função soma() é usada para somar os números digitados e armazenar os pares em outro vetor. A função mostra() é usada para mostrar os números armazenados em um vetor.
*/

