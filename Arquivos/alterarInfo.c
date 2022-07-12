#include "headers.h"

void alterarInfo(char buffer[])
{
    int opt=0, lineCount=0;
    char novoEmail[100], linha[1024];
    FILE *fAlt;

    printf("Escolha a opção a ser alterada: \n\t1. E-Mail\n\t2. Senha\n");
    scanf("%d", &opt);

    do
    {
        switch(opt)
        {
            case 1:
                printf("Digite seu novo email: ");
                fflush(stdin);
                fgets(novoEmail, sizeof novoEmail, stdin);

                fAlt = fopen(buffer, "r+");
                while(fgets(linha, sizeof linha, fAlt) != NULL)
                {
                    lineCount++;
                    if(fAlt == NULL)
                    {
                        perror("\tErro ao abrir o arquivo de saida!\n");
                        printf("Verifique se o arquivo existe ou se você possui permissão para altera-lo.\n");
                        exit(EXIT_SUCCESS);
                    }
                    else
                    {
                        if(lineCount == 7)
                        {
                            fputs(novoEmail, fAlt);
                            printf("Seu email foi alterado com sucesso!\n");
                        }
                    }
                }
                fclose(fAlt);
            break;
            case 2:
            break;
            case 3:
                login();
            break;
            default:
                printf("Opção inválida! Digite novamente!\n");
            break;
        }      
    }while(opt!= 3);
}