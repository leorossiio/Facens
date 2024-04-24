#include <stdio.h>
#include <stdlib.h>

struct trinca {
    int a;
    int b;
    int c;
    int (*calculo)(struct trinca *self);
};

int mediana(struct trinca *self);
int media(struct trinca *self);

void swap(int *a, int *b);
int mediana(struct trinca *self);
int media(struct trinca *self);

int main(int argc, char *argv[]) {

    struct trinca data = {
        .a = 15,
        .b = 10,
        .c = 25
    };

    data.calculo = mediana;
    printf("Call data.calculo -> mediana = %d\n", data.calculo(&data));
    data.calculo = media;
    printf("Call data.calculo -> media = %d\n", data.calculo(&data));

    system("pause");
    return 0;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int mediana(struct trinca *self) {
    int a = self->a;
    int b = self->b;
    int c = self->c;

    if (a > c) swap(&a, &c);
    if (a > b) swap(&a, &b);
    if (b > c) swap(&b, &c);

    return b;
}

int media(struct trinca *self) {
    int soma = self->a + self->b + self->c;

    return soma / 3;
}
