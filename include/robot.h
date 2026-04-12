#ifndef ROBOT_H
#define ROBOT_H

typedef double t_torque;
typedef double t_rpm;
typedef double t_voltagem;
typedef double t_corrente;
typedef double t_resistencia;
typedef double t_capacidade_mah;

typedef struct motor {
    // Parâmetros de máximo
    t_torque torque_stall; // Torque máximo atingido pelo motor.
    t_rpm rpm_max; // Rotação do motor sem carga.
    
    // Parâmetros atuais
    t_torque torque_atual; // Torque no momento x atual.
    t_rpm rpm_atual; // Rotação no momento x atual.

    // Parâmetros específicos
    t_resistencia resistencia_interna; // Resistência interna do motor.
    t_corrente corrente_stall; // Corrente em máxima. Voltagem recebida sobre resistência motor.
    t_corrente corrente_free_run; // Corrente em vazio.
    t_voltagem voltagem_motor; // Voltagem recebida pelo motor
    t_voltagem overvoltage_motor; // Voltagem fora de especificação. Usada em comparação com a base para calcular novos valores.
    double eficiencia_reducao; // Eficiência de transmissão do torque pela redução.
} motor;

typedef struct bateria {

    // Parâmetros gerais
    t_capacidade_mah capacidade;
    t_voltagem voltagem;
    double taxa_descarga;
    int config_s;

    // Parâmetros específicos
    t_resistencia res_interna_bat;
} bateria;

typedef struct ponte_h {
    t_corrente corrente_limite;
} ponte_h;

typedef struct robot {
    motor params_motor;
    bateria params_bateria;
    double peso;
    double raio_roda;
} robot;

#endif
