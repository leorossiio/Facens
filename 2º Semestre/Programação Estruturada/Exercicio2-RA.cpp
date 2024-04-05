//Exemplo 2
#include <stdio.h>
#include <stdlib.h>

//Protótipo das funções
void aloca(int **p, int tam);
void leitura(int *p);
int soma(int *p, int tam, int **pimpar, int *qimpar);
void mostra(int *p, int tam);

int main()
{
    int *ptr = NULL, *ptrimpar = NULL; 
    char op; 
    int cont = 0, qtdimpar = 0; 

    do {
        aloca(&ptr, cont + 1); 
        leitura(ptr + cont); 
        cont++; 
        printf("\nDeseja continuar <S/N>: ");
        scanf(" %c", &op); 
        fflush(stdin); 
    } while (op != 'n' && op != 'N'); 

    printf("\nNumeros digitados:\n");
    mostra(ptr, cont); 

    soma(ptr, cont, &ptrimpar, &qtdimpar); 

    printf("\nResultados impares:\n\n");
    mostra(ptrimpar, qtdimpar); 

    printf("\n");
    system("pause"); 
    return 0;
}


void aloca(int **p, int tam)
{
    if ((*p = (int*) realloc(*p, tam * sizeof(int))) == NULL) {
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

//Função para somar os números e armazenar os impares
int soma(int *p, int tam, int **pimpar, int *qimpar)
{
    int i, resul_soma = 0;

    for (i = 0; i < tam / 2; i++) { 
        resul_soma = *(p + i) + *(p + tam - 1 - i); 
        if (resul_soma % 2 != 0) { 
            aloca(pimpar, *qimpar + 1); 
            *(*pimpar + *qimpar) = resul_soma; 
            (*qimpar)++; 
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
