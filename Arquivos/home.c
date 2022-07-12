#include "headers.h"

void home(struct usuario u, char pw[], char buffer[])
{
    if(strcmp(u.senha, pw) == 0)
    {
            if(strcasecmp(u.genero, "M") == 0)
            {
                printf("Bem vindo %s! :)\n\tSelecione uma opção: \n\t1. Exibir seus dados\n\t2. Alterar dados\n\t3. Deletar cadastro\n", u.nome);
            }
            else
            {
              printf("Bem vinda %s! :)\n\tSelecione uma opção: \n\t1. Exibir seus dados\n\t2. Alterar dados\n\t3. Deletar cadastro\n", u.nome); 
            }    
            int opcao;
            scanf("%d", &opcao);
            fflush(stdin);
            switch(opcao)
            {
            case 1:
                printf("Nome: %s %s\n", u.nome, u.sobrenome);
                printf("Gênero: %s\n", u.genero);
                printf("CPF: %s\n", u.cpf);
                calculoIdade(u);
                printf("Email: %s\n", u.email);
                dataFormatada(u);
                //cpfFormatado(users, teste);
            break;
            case 2:
                alterarInfo(buffer);
            break;
            case 3:
                printf("Deseja realmente excluir seu cadastro? (S/N)\n");
                char sn;
                sn = getchar();
                if(sn == 'S' || sn == 's')
                {
                    remove(buffer);
                    if(fopen(buffer, "r") == NULL)
                    {
                        printf("\nSeu usuario %s foi excluido com sucesso!\n", buffer);
                    }
                    else
                    {
                        printf("Erro ao excluir usuario %s", buffer);
                    }
                    
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