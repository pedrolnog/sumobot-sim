#ifndef UI_H
#define UI_H

#include <stdlib.h>

/*
Usando macros:

_WIN32: É uma macro que praticamente todos os compiladores de Windows (GCC/MinGW, MSVC, Clang) definem por padrão.

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
*/

void limpar_tela() {
    // \033[H move o cursor para o topo
    // \033[J limpa a tela a partir dali
    printf("\033[H\033[J");
}

#endif