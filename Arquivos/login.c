#include "headers.h"
void login()
{
    struct usuario users;
    char login[100],
         pw[100],
         buffer[100],
         *sp,
         linha[1024],
         fPW[100];
    int lineCount=0, teste;

    printf("LOGIN\n\tCPF: ");
    fgets(login, sizeof login, stdin);
    strcpy(buffer, "Usuarios\\");
    strcat(buffer, login);
    buffer[strcspn(buffer, "\n")] = 0;
    strcat(buffer, ".txt");

    FILE *fp;
    fp = fopen(buffer, "r");
    if(fp == NULL)
    {
        printf("\nCPF não cadastrado! \n");
        system("pause");
        system("cls");
        menuCadastro();
    }
    else
    {
        printf("\n\tSenha: ");
        fgets(pw, sizeof pw, stdin);
        pw[strcspn(pw, "\n")] = 0;
        int i=0;
        while(fgets(linha, sizeof linha, fp) != NULL)
        {
            if(i==0)
            {
                strcpy(users.nome, linha);
                users.nome[strcspn(users.nome, "\n")] = 0;
            }
            else if(i==1)
            {
                strcpy(users.sobrenome, linha);
                users.sobrenome[strcspn(users.sobrenome, "\n")] = 0;
            }
            else if(i==2)
            {
                strcpy(users.genero, linha);
                users.genero[strcspn(users.genero, "\n")] = 0;
            }
            else if(i==3)
            {
                strcpy(users.cpf, linha);
                users.cpf[strcspn(users.cpf, "\n")] = 0;
            }
            else if(i==4)
            {
                strcpy(users.dataNascimento, linha);
                users.dataNascimento[strcspn(users.dataNascimento, "\n")] = 0;
            }
            else if(i==5)
            {
                strcpy(users.idade, linha);
                users.idade[strcspn(users.idade, "\n")] = 0;
            }
            else if(i==6)
            {
                strcpy(users.email, linha);
                users.email[strcspn(users.email, "\n")] = 0;
            }
            else 
            {
                strcpy(users.senha, linha);
                users.senha[strcspn(users.senha, "\n")] = 0;
            }
            i++;
        }
        fclose(fp);
    home(users, pw, buffer);    
    }
}