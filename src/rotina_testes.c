#include "../include/robot.h"
#include "../include/tools.h"
#include "../include/ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
# TODO

- Consertar lógica dos "decisao";

*/

void checar_structs(robot* robo) {
    int decisao = -1;
    
    while (decisao != 0) {
        printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Visualização de dados\n\n");


        printf("VISUALIZAR DADOS DO ROBÔ\n");
        printf("Nesse menu, você pode visualizar os parâmetros do robô.\n");
        printf("\nPARÂMETROS DO ROBÔ:\n");
        printf("1. Nome do robô\n2. Parâmetros do motor\n3. Parâmetros da bateria\n4. Peso\n5. Raio da roda\n0. Sair\n");
        scanf("%d", &decisao);

        limpar_buffer();
        limpar_tela();
    }
}

void popular_structs(robot* robo) {
    int decisao = -1, decisao2;

    while (decisao != 0) {
        printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de dados\n\n");

        printf("DEFINIR DADOS\n");
        printf("Nesse menu, você pode definir os parâmetros do robô.\n");
        printf("\nPARÂMETROS DO ROBÔ:\n");
        printf("1. Nome do robô\n2. Parâmetros do motor\n3. Parâmetros da bateria\n4. Peso\n5. Raio da roda\n0. Sair\n");
        scanf("%d", &decisao);

        limpar_buffer();
        limpar_tela();

        // Definição de parâmetros dos robôs
        switch (decisao) {
            case 1: // Nome
                printf("A implementar...\n");
                limpar_tela();
                break;
            case 2: // Motor
                decisao2 = -1;
;
                while (decisao2 != 0) {
                    printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor\n\n");

                    printf("PARÂMETROS BASE DO MOTOR\n");
                    printf("1. Definir torque stall\n2. Definir rpm máximo\n3. Definir resistência interna do motor\n4. Definir corrente máxima do motor\n");
                    printf("5. Definir corrente livre\n6. Definir voltagem do motor\n7. Definir razão de eficiência da redução do motor\n");

                    printf("\nPARÂMETROS DE TESTE DO MOTOR\n");
                    printf("8. Definir torque de teste (torque_atual)\n9. Definir rotação de teste (rotação atual)\n10. Definir voltagem de overvoltage\n\n0. Voltar\n");
                    scanf("%d", &decisao2);
                    limpar_tela();

                    switch(decisao2) {
                        case 1:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor > Torque stall\n\n");

                            t_torque novo_valor_torque;
                            scanf("%lf", &novo_valor_torque);
                            robo->params_motor.torque_stall = novo_valor_torque;
                            printf("Novo valor de torque máximo definido!");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 2:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor > RPM máximo\n\n");

                            t_rpm novo_valor_rpm;
                            scanf("%lf", &novo_valor_rpm);
                            robo->params_motor.rpm_max = novo_valor_rpm;
                            printf("Novo valor de rotação por minuto (rpm) máximo definido!");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 3:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor > Resistência interna\n\n");

                            t_resistencia novo_valor_resistencia;
                            scanf("%lf", &novo_valor_resistencia);
                            robo->params_motor.resistencia_interna = novo_valor_resistencia;
                            printf("Novo valor de resistência interna do motor definido!");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 4:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor > Corrente máxima\n\n");

                            t_corrente novo_valor_corrente;
                            scanf("%lf", &novo_valor_corrente);
                            robo->params_motor.corrente_stall = novo_valor_corrente;
                            printf("Novo valor da corrente máxima do motor definido!");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 5:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor > Corrente livre\n\n");

                            t_corrente novo_valor_corrente_livre;
                            scanf("%lf", &novo_valor_corrente_livre);
                            robo->params_motor.corrente_free_run = novo_valor_corrente_livre;
                            printf("Novo valor de corrente livre definido!");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 6:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor > Voltagem\n\n");

                            t_voltagem novo_valor_voltagem;
                            scanf("%lf", &novo_valor_voltagem);
                            robo->params_motor.voltagem_motor = novo_valor_voltagem;
                            printf("Novo valor de voltagem do motor definido!\n");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 7:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor > Eficiência da redução\n\n");

                            double novo_valor_eficiencia;
                            scanf("%lf", &novo_valor_eficiencia);
                            robo->params_motor.eficiencia_reducao = novo_valor_eficiencia;
                            printf("Novo valor de eficiência mecânica da redução definido!\n");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 8:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor > Torque teste\n\n");

                            t_torque novo_valor_torque_atual;
                            scanf("%lf", &novo_valor_torque_atual);
                            robo->params_motor.torque_atual = novo_valor_torque_atual;
                            printf("Novo valor instantâneo de torque definido!\n");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 9:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor > RPM teste\n\n");

                            t_rpm novo_valor_rpm_atual;
                            scanf("%lf", &novo_valor_rpm_atual);
                            robo->params_motor.rpm_atual = novo_valor_rpm_atual;
                            printf("Novo valor instantâneo de RPM definido!\n");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 10:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Motor > Overvoltage\n\n");

                            t_voltagem novo_valor_overvoltage;
                            scanf("%lf", &novo_valor_overvoltage);
                            robo->params_motor.overvoltage_motor = novo_valor_overvoltage;
                            printf("Novo valor de sobrevoltagem do motor definido!\n");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 0:
                            limpar_tela();
                            break;
                        default:
                            limpar_tela();
                            printf("Erro! Comando não encontrado. Tente novamente.\n");
                            limpar_buffer();
                            sleep(2);
                            break;
                        }
                    }
                    break;
            case 3: // Bateria
                decisao2 = -1;
                while (decisao2 != 0) {
                    printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Bateria\n\n");

                    printf("PARÂMETROS DA BATERIA\n");
                    printf("1. Definir capacidade da bateria\n2. Definir voltagem da bateria\n3. Definir taxa de descarga da bateria\n4. Definir configuração de células da bateria (2S, 3S, 4S, ...)\n5. Definir resistência interna da bateria\n\n0. Voltar\n");
                    scanf("%d", &decisao2);
                    
                    limpar_buffer();
                    limpar_tela();

                    switch(decisao2) {
                        case 1:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Bateria > Capacidade\n\n");

                            t_capacidade_mah nova_capacidade;
                            scanf("%lf", &nova_capacidade);
                            robo->params_bateria.capacidade = nova_capacidade;
                            printf("Nova capacidade da bateria definida.\n");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 2:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Bateria > Voltagem\n\n");

                            t_voltagem nova_voltagem;
                            scanf("%lf", &nova_voltagem);
                            robo->params_bateria.voltagem = nova_voltagem;
                            printf("Nova voltagem da bateria definida.\n");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 3:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Bateria > Taxa de descarga\n\n");

                            double nova_taxa;
                            scanf("%lf", &nova_taxa);
                            robo->params_bateria.taxa_descarga = nova_taxa;
                            printf("Nova taxa de descarga da bateria definida.\n");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 4:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Bateria > Configuração de células\n\n");

                            int nova_conf_celulas;
                            scanf("%d", &nova_conf_celulas);
                            robo->params_bateria.config_s = nova_conf_celulas;
                            printf("Nova configuração de células da bateria definida.\n");
                            sleep(2);
                            limpar_tela();
                            break;
                        case 5:
                            printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Bateria > Resistência interna\n\n");

                            t_resistencia nova_resistencia;
                            scanf("%lf", &nova_resistencia);
                            robo->params_bateria.res_interna_bat = nova_resistencia;
                            printf("Nova resistência interna da bateria definida.\n");
                            sleep(2);
                            limpar_tela();
                            break;
                        }
                    }
                    break;
            case 4: // Peso
                printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Peso\n\n");

                double novo_peso;
                scanf("%lf", &novo_peso);
                robo->peso = novo_peso;
                printf("Novo peso definido.\n");
                sleep(2);
                limpar_tela();
                break;
            case 5: // Raio da roda
                printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados > Definição de parâmetros > Raio da roda\n\n");

                double raio_roda;
                scanf("%lf", &raio_roda);
                robo->raio_roda = raio_roda;
                printf("Novo raio da roda definido.\n");
                sleep(2);
                limpar_tela();
                break;
            case 0:
                limpar_tela();
                break;
            default:
                limpar_tela();
                printf("Erro! Comando não encontrado. Tente novamente.\n");
                limpar_buffer();
                sleep(2);
                break;
        }
    }
}

void menu_dados(robot* robo) {
    int decisao = -1;

    while (decisao != 0) {
        printf("ROTINA DE TESTES - sumô sim alpha v0.1\nMenu inicial > Menu Dados\n\n");

        printf("MENU DADOS\n");
        printf("1. Definir dados do robô\n2. Visualizar dados do robô\n0. Sair\n");
        scanf("%d", &decisao);
        
        limpar_tela();
        limpar_buffer();

        switch (decisao) {
            case 1:
                popular_structs(robo);
                break;
            case 2:
                checar_structs(robo);
                break;
            case 0:
                limpar_tela();
                break;
            default:
                printf("Erro! Comando não encontrado. Tente novamente.\n");
                limpar_buffer();
                break;
        }
    }   
    
}

void testar_funcoes(robot* robo) {

}

int main() {
    int decisao = -1;
    robot *robo_teste = criar_robo();

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
                limpar_buffer();
                break;
        }
    };

    return 0;
}