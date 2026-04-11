/*
# TODO

1. Simplificar os parâmetros das funções (aumenta legibilidade).
2. Melhorar consistência da tipagem.
3. 

*/

#include "robot.h"
#include <stdio.h>

#define PI 3.14159265
#define GRAVIDADE 9.80665

typedef double t_veloc;

double valores_teoricos_veloc[5];


static inline double rpm_para_rad(t_rpm rpm) {
    return rpm * (2.0 * PI / 60.0);
}

static inline double kgfcm_para_nm(t_torque torque) {
    return torque * 0.098;
}

// Retorna o torque em função da rotação [T(w)]. 
static inline double torque_x_rotacao(t_torque torque_stall, t_rpm rpm_atual, t_rpm rpm_max) {
    return kgfcm_para_nm(torque_stall) * (1 - (rpm_para_rad(rpm_atual) / rpm_para_rad(rpm_max))); 
}

// Retorna a velocidade linear teórica (w_roda * r_roda)
static inline t_veloc velocidade_lin_teorica(t_rpm rpm_atual, double raio_roda) {
    return (rpm_para_rad(rpm_atual) * raio_roda);
}

// Cálculo de velocidade levando em conta o escorregamento.
static inline void velocidade_real(robot *params_robo, double *vetor_destino) {
    double slip_ratio = 0.05;
    int i;

    for (i = 0; i < 5; i++) {
        vetor_destino[i] = velocidade_lin_teorica(params_robo->params_motor.rpm_atual, params_robo->raio_roda) * (1 - slip_ratio);
        slip_ratio += 0.02;
    }
} 

static inline double forca_motor(t_torque torque_motor, double raio_roda, double eficiencia_red) {
    return (kgfcm_para_nm(torque_motor) * eficiencia_red)/raio_roda;
}

static inline double limite_tracao(double coef_atrito, double massa_robo, double forca_motor) {
    // Calcula a força de atrito no chão. Se o motor tiver 50N e o chão só aguentar 30N, temos apenas 30N.
    double f_atrito = coef_atrito * massa_robo * GRAVIDADE;

    if (forca_motor > f_atrito) {
        /*
        Isso deve estar no .c

        printf("\nATENÇÃO!\n A força do motor excede a força de atrito.\n");
        */
        return f_atrito;
    } else {
        return forca_motor;
    }

}

static inline double corrente_stall_motor(t_voltagem voltagem, t_resistencia res_interna, t_corrente limite_ponteh) {
    double corrente = voltagem / res_interna;
    /*

    Isso deve estar no .c

    if (corrente > limite_ponteh) {
        printf("\n\nATENÇÃO!\nA corrente do motor excede o limite da ponte-h.\n");
    }
    */
    return corrente;
}

static inline double runtime_bateria(bateria *params_bateria, t_corrente corrente_stall, t_corrente corrente_livre) {
    double corrente_media = (corrente_stall * 0.6) + (corrente_livre * 0.4); // Robô 60% do tempo em stall, 40% em movimento livre.
    return (((params_bateria->capacidade/1000) * 0.8) / corrente_media) * 60; // Considerando 80% da capacidade para não rodar o robô abaixo dos 20% de bateria. Retorna em minutos
};

static inline t_voltagem queda_tensao(t_corrente corrente_total, t_resistencia res_interna_bat) {
    return corrente_total * res_interna_bat;
}

