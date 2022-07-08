#include "headers.h"

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    //setlocale(LC_ALL, "Portuguese");
    menuEscolha();
    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}