#include "headers.h"
int login()
{
    struct usuario
    {
        char nome[100];
        char sobrenome[100];
        char genero[100];
        char cpf[100];
        char dataNascimento[100];
        char idade[100];
        char email[100];
        char senha[100];
    };
    struct usuario users;
    char login[100],
         pw[100],
         buffer[100],
         *sp,
         linha[1024],
         fPW[100];
    int lineCount=0;

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
        printf("\nCPF não cadastrado!\n");
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
            if(i==1)
            {
                strcpy(users.sobrenome, linha);
                users.sobrenome[strcspn(users.sobrenome, "\n")] = 0;
            }if(i==2)
            {
                strcpy(users.genero, linha);
                users.genero[strcspn(users.genero, "\n")] = 0;
            }if(i==3)
            {
                strcpy(users.cpf, linha);
                users.dataNascimento[strcspn(users.dataNascimento, "\n")] = 0;
            }if(i==4)
            {
                strcpy(users.dataNascimento, linha);
                users.dataNascimento[strcspn(users.dataNascimento, "\n")] = 0;
            }if(i==5)
            {
                strcpy(users.idade, linha);
                users.idade[strcspn(users.idade, "\n")] = 0;
            }if(i==6)
            {
                strcpy(users.email, linha);
                users.email[strcspn(users.email, "\n")] = 0;
            }if(i==7)
            {
                strcpy(users.senha, linha);
                users.senha[strcspn(users.senha, "\n")] = 0;
            }
            i++;
        }
        if(strcmp(users.senha, pw) == 0)
        {
           if(strcasecmp(users.genero, "M") == 0)
            {
                printf("Bem vindo %s! :)\nSelecione uma opção: \n1.Exibir seus dados\n2. Deletar cadastro\n", users.nome);
            }
            else
            {
              printf("Bem vinda %s! :)\nSelecione uma opção: \n1.Exibir seus dados\n2. Deletar cadastro\n", users.nome); 
            }    
            fclose(fp);
            int opcao;
            fflush(stdin);
            scanf("%d", &opcao);
            switch(opcao)
            {
                case 1:
                    printf("Nome: %s %s\n", users.nome, users.sobrenome);
                    printf("Gênero: %s\n", users.genero);
                    printf("CPF: %s", users.cpf);
                    printf("Idade: %s\n", users.idade);
                    printf("Email: %s\n", users.email);
                break;
                case 2:
                    printf("Deseja realmente excluir seu cadastro? (S/N)\n");
                    char sn;
                    fflush(stdin);
                    scanf(" %c", &sn);
                    if(sn == 'S' || sn == 's')
                    {
                        printf("%s", buffer);
                        remove(buffer);
                        printf("\nSeu usuario foi excluido com sucesso!\n");
                    }
                break;
            }
        }
        else
        {
            printf("Senha inválida!\n");
        }
        system("pause");
    }
    return 0;
}