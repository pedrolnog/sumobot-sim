#include "../include/robot.h"
#include "../include/tools.h"
#include "../include/ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
# TODO

- Consertar lógica dos "decisao";

*/

void checar_structs(robot* robo) {
    int decisao;
    printf("%lf", robo->params_motor.torque_stall);
    scanf("%d", &decisao);
}

void popular_structs(robot* robo) {
    int decisao = 1, decisao2 = 1;

    while (decisao != 0) {
        printf("MENU DADOS\n");
        printf("Nesse menu, você pode definir os parâmetros do robô.\n");
        printf("\nPARÂMETROS DO ROBÔ:\n");
        printf("1. Nome do robô\n2. Parâmetros do motor\n3. Parâmetros da bateria\n4. Peso\n5. Raio da roda\n0. Sair\n");
        scanf("%d", &decisao);

        limpar_tela();

        switch (decisao) {
            case 1:
                printf("A implementar...\n");
                limpar_tela();
                break;
            case 2:
                while (decisao2 != 0) {
                    printf("PARÂMETROS BASE DO MOTOR\n");
                    printf("1. Definir torque stall\n2. Definir rpm máximo\n3. Definir resistência interna do motor\n4. Definir corrente máxima do motor\n");
                    printf("5. Definir corrente livre\n6. Definir voltagem do motor\n7. Definir razão de eficiência da redução do motor\n");

                    printf("PARÂMETROS DE TESTE DO MOTOR\n");
                    printf("8. Definir torque de teste (torque_atual)\n9. Definir rotação de teste (rotação atual)\n10. Definir voltagem de overvoltage\n0. Sair\n");
                    scanf("%d", &decisao2);
                    limpar_tela;
                    switch(decisao2) {
                        case 1:
                            limpar_tela();
                            t_voltagem novo_valor_voltagem;
                            scanf("%lf", &novo_valor_voltagem);
                            robo->params_motor.torque_stall = novo_valor_voltagem;
                            printf("Novo valor de torque máximo definido!");
                            limpar_tela();
                            break;
                        case 2:
                            limpar_tela();
                            t_rpm novo_valor_rpm;
                            scanf("%lf", &novo_valor_rpm);
                            robo->params_motor.rpm_max = novo_valor_rpm;
                            printf("Novo valor de rotação por minuto (rpm) máximo definido!");
                            limpar_tela();
                            break;
                        case 3:
                            limpar_tela();
                            t_resistencia novo_valor_resistencia;
                            scanf("%lf", &novo_valor_resistencia);
                            robo->params_motor.resistencia_interna = novo_valor_resistencia;
                            printf("Novo valor de resistência interna do motor definido!");
                            limpar_tela;
                            break;
                        case 4:
                            limpar_tela();
                            t_corrente novo_valor_corrente;
                            scanf("%lf", &novo_valor_corrente);
                        case 0:
                            limpar_tela();
                            break;
                        default:
                            limpar_tela();
                            printf("Erro! Comando não encontrado. Tente novamente.\n");
                            break;
                        }
                    }

        }

    }
}

void menu_dados(robot* robo) {
    int decisao = 1;

    while (decisao != 0) {
        printf("MENU DADOS\n");
        printf("1. Definir dados do robô\n2. Visualizar dados do robô\n0. Sair\n");
        scanf("%d", &decisao);

        switch (decisao) {
            case 1:
                popular_structs(robo);
            case 2:
                checar_structs(robo);
            case 0:
                limpar_tela();
                break;
            default:
                printf("Erro! Comando não encontrado. Tente novamente.\n");
                break;
        }
    }   
    
}

void testar_funcoes(robot* robo) {

}

int main() {
    int decisao;
    robot *robo_teste;

    limpar_tela();

    while(decisao != 0) {
        printf("ROTINA DE TESTES - sumô sim alpha v0.1\n");
        printf("1. Menu Dados (structs, inserir dados)\n");
        printf("2. Menu Funções (ferramentas)\n");
        printf("0. Sair\n");
        scanf("%d", &decisao);

        switch(decisao) {
            case 1:
                limpar_tela();
                menu_dados(robo_teste);
                break;
            case 2:
                limpar_tela();
                testar_funcoes(robo_teste);
                break;
            case 0:
                limpar_tela();
                break;
            default:
                limpar_tela();
                printf("Erro! Função não encontrada. Tente novamente.\n");
                break;
        }
    };

    return 0;
}