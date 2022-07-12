#include "headers.h"
void menuCadastro()
{
    char nome[100],
         sobrenome[100],
         genero[100],
         email[256],
         senha[100],
         cpf[100],
         SN,
         escolha,
         dataNascimento[100];

    do
    {
    printf("Preencha os campos solicitados: \n");
    printf("\tNome: ");
    fgets(nome, 100, stdin);

    printf("\tSobrenome: ");
    fgets(sobrenome, 100, stdin);

    printf("\tGênero (M para Masculino / F para Feminino): ");
    fgets(genero, sizeof genero, stdin);
    fflush(stdin);
        if((strcasecmp(genero, "M") != 0) || (strcasecmp(genero, "F") != 0))  
        {
            printf("Gênero inválido! Digite novamente\n");
        }
    while(strlen(cpf) != 12 == true)
    {
    printf("\tCPF: ");
    fgets(cpf, sizeof cpf, stdin);
    fflush(stdin);
        if(strlen(cpf) != 12)
        {
            printf("CPF inválido! Digite novamente.\n");
        }
    }
    while(strlen(dataNascimento) != 9 == true)
    { 
    printf("\tData de nascimento (Não utilize espaços e barras -> ddmmaaaa): ");
    fgets(dataNascimento, sizeof dataNascimento, stdin);
    fflush(stdin);
        if(strlen(dataNascimento) != 9)
        {
            printf("Data de nascimento inválida! Digite no formato dd mm aaaa.\n");
        }
    }
    printf("\tEmail: ");
    fgets(email, 256, stdin);
    fflush(stdin);

    printf("\tSenha (max 14 caracteres): ");
    fgets(senha, 15, stdin);
    fflush(stdin);
    while(strlen(senha) > 15 == true)
    {
        if(strlen(senha) > 15)
        {
            printf("\nSenha inválida! Digite novamente.\n");
        }
    }
    printf("Suas informações estão corretas? (S/N) ");
    SN = getchar();
    if(SN == 'S' || SN == 's')
    {
        salvarCadastro(nome, sobrenome, genero, email, senha, cpf, dataNascimento);
        printf("\nCadastro realizado com sucesso!");
    }
    printf("\nPressione F para realizar um novo cadastro ou pressione M para ir para o menu ");
    escolha = getchar();
        if(escolha == 'F' || escolha == 'f')
        {
            system("cls");
            menuCadastro();
        }
        else
        {
            system("cls");
            menuEscolha();
        }
    }while(escolha == 'F' || escolha == 'f');
}