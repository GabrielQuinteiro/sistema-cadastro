#include "headers.h"

void calculoIdade(struct usuario u)
{
    int anoNascimento, mesNascimento, diaNascimento,
        anoAtual, mesAtual, diaAtual,
        idade, dataNasc, dataAtual;

    dataNasc = atoi(u.dataNascimento);

    anoNascimento = dataNasc % 10000;
    mesNascimento = (dataNasc / 10000) % 100;
    diaNascimento = dataNasc / 1000000;

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    //printf("Data: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    anoAtual = (tm.tm_year + 1900);
    mesAtual = tm.tm_mon;
    diaAtual = tm.tm_mday;

    idade = anoAtual - anoNascimento;

    if(mesAtual < mesNascimento)
    {
        idade = idade - 1;
    }
    else if(mesAtual == mesNascimento)
    {
        if(diaAtual < diaNascimento) 
        {
            idade-= 1;
        }  
    }
 printf("Idade: %d\n", idade);
}

