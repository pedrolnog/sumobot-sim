#include "../include/robot.h"
#include "../include/tools.h"
#include <stdio.h>

void popular_structs(robot* robo) {
    int decisao;

    while (decisao != 0) {
        printf("MENU DADOS\n");
        printf("Nesse menu, insira os parâmetros do robô.\n");
        printf("\nPARÂMETROS DO ROBÔ:\n");
        printf("1. Nome do robô\n2. Parâmetros do motor\n3. Parâmetros da bateria\n4. Peso\n5. Raio da roda\n0. Sair\n");
        scanf("%d", &decisao);
    }
}

void testar_funcoes(robot* robo) {

}

int main() {
    int decisao;
    robot *robo_teste;

    while(decisao != 0) {
        printf("ROTINA DE TESTES - sumô sim alpha v0.1\n");
        printf("1. Menu Dados (structs, inserir dados)\n");
        printf("2. Menu Funções (ferramentas)\n");
        printf("0. Sair");
        scanf("%d", &decisao);

        switch(decisao) {
            case 1:
                popular_structs(robo_teste);
                break;
            case 2:
                testar_funcoes(robo_teste);
                break;
            case 0:
                break;
            default:
                printf("Erro! Função não encontrada. Tente novamente.\n");
                break;
        }

        system("cls");
    };

    return 0;
}