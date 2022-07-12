#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

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

void menuEscolha();
void menuCadastro();
int salvarCadastro(char[], char[], char[], char[], char[], char[], char[]);
void login();
void cpfFormatado(struct usuario u, int n);
void dataFormatada(struct usuario u);
void alterarInfo(char[]);
void home(struct usuario u, char[], char[]);
void calculoIdade(struct usuario u);