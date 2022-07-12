#include "headers.h"

void dataFormatada(struct usuario u)
{
    int data, dia, mes, ano;

    data = atoi(u.dataNascimento);

    ano = data % 10000;
    mes = (data % 1000000) / 10000;
    dia = data / 1000000;

    printf("Data de nascimento: %02d/%02d/%02d\n", dia, mes, ano);
} 