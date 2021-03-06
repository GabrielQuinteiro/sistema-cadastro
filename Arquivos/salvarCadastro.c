#include "headers.h"

int salvarCadastro(char nome[], char sobrenome[], char genero[], char email[], char senha[], char cpf[], char dataNascimento[])
{
    char usuarios[10],
         dt[10],
         line[1024];

    FILE * saidaCad;

    strcpy(usuarios, "Usuarios\\");
    strcat(usuarios, cpf);
    usuarios[strcspn(usuarios, "\n")] = 0;
    strcat(usuarios, ".txt");

    saidaCad = fopen(usuarios, "w");
    if(saidaCad == NULL)
    {
        perror("\tErro ao abrir o arquivo de saida!\n");
        exit(1);
    }
    else
    {
        strcpy(line, nome);
        strcat(line, sobrenome);
        strcat(line, genero);
        strcat(line, cpf);
        strcat(line, dataNascimento);
        strcat(line, "\n");
        strcat(line, email);
        strcat(line, senha);
        fputs(line, saidaCad);
    }
    fclose(saidaCad);
    return 0;
}