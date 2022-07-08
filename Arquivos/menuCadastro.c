#include "headers.h"
int menuCadastro()
{
    char nome[100],
         sobrenome[100],
         genero[100],
         email[256],
         senha[100],
         cpf[100],
         idade[100],
         SN,
         sair;
    int dataNascimento;

    do
    {
    printf("Preencha os campos solicitados: \n");
    printf("\tNome: ");
    fgets(nome, 100, stdin);

    printf("\tSobrenome: ");
    fgets(sobrenome, 100, stdin);

    printf("\tGênero (M para Masculino, F para Feminino): ");
    fgets(genero, sizeof genero, stdin);
    fflush(stdin);

    printf("\tCPF: ");
    fgets(cpf, sizeof cpf, stdin);
    fflush(stdin);

    printf("\tData de nascimento (Não utilize espaços e barras -> ddmmaaaa): ");
    scanf("%d", &dataNascimento);
    fflush(stdin);

    printf("\tIdade: ");
    fgets(idade, 4, stdin);
    fflush(stdin);

    printf("\tEmail: ");
    fgets(email, 256, stdin);
    fflush(stdin);

    printf("\tSenha (até 14 caracteres): ");
    fgets(senha, 15, stdin);
    fflush(stdin);

    printf("Suas informações estão corretas? (S/N) ");
    scanf(" %c", &SN);
    fflush(stdin);
    if(SN == 'S' || SN == 's')
    {
        salvarCadastro(nome, sobrenome, genero, email, senha, cpf, idade, dataNascimento);
        printf("\nCadastro realizado com sucesso!");
    }
    printf("\nPressione F para realizar um novo cadastro ou pressione qualquer tecla para sair ");
    scanf(" %c", &sair);
    fflush(stdin);
        if(sair == 'F' || sair == 'f')
        {
            system("cls");
        }
        else
        {
            system("cls");
            printf("\nFim do programa!\n");
            menuEscolha();
        }
    }while(sair == 'F' || sair == 'f');

    return 0;
}