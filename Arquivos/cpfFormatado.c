#include "headers.h"

void cpfFormatado(struct usuario u, int teste)
{
    int cpf;
    char str[100];

    printf("CPF TESTE: %d\n", teste);

    strcpy(str, u.cpf);
    printf("CPF STR: %s\n", str);

    cpf = atoi(u.cpf);
    printf("CPF FORMATADO: %d\n", cpf);
}