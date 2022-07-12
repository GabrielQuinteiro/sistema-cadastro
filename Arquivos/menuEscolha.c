#include "headers.h"

void menuEscolha()
{
    int opcoes=0;

    printf("Seja bem vindo! Escolha uma opção abaixo: \n\t1. Cadastrar\n\t2. Login\n\t3. Sair\n");
    scanf("%d", &opcoes);
    fflush(stdin);
    //do
    //{
        switch(opcoes)
        {
            case 1:
                system("cls");
                menuCadastro();
            break;
            case 2:
                system("cls");
                login();
            break;
            default:
                system("cls");
                printf("Programa finalizado!\n");
            exit(1);
            break;
        }
    //}while(opcoes!=3);
}