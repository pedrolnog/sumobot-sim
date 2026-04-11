/*
# TODO

1. Simplificar os parâmetros das funções (aumenta legibilidade).
2. Implementar perdas de transmissão na redução.

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
static inline double torque_x_rotacao(motor* motor) {
    return kgfcm_para_nm(motor->torque_stall) * (1 - (rpm_para_rad(motor->rpm_atual) / rpm_para_rad(motor->rpm_max))); 
}

// Retorna a velocidade linear teórica (w_roda * r_roda)
static inline t_veloc velocidade_lin_teorica(robot* params_robo) {
    return (rpm_para_rad(params_robo->params_motor->rpm_atual) * params_robo->raio_roda);
}

// Cálculo de velocidade levando em conta o escorregamento.
static inline t_veloc velocidade_real(robot *params_robo, double *valores_teoricos[5]) {
    double slip_ratio = 0.05;
    int i;

    for (i = 0; i < 5; i++) {
        *valores_teoricos[i] = velocidade_lin_teorica(params_robo) * (1 - slip_ratio);
        slip_ratio += 0.02;
    }
} 

static inline double forca_motor(t_param_motor torque_motor, double raio_roda) {
    return (torque_motor * 0.8)/raio_roda; // Torque_motor foi multiplicado por 0.8 para levar em conta as perdas de eficiência da transmissão (redução).
}

static inline double limite_tracao(double coef_atrito, double massa_robo, double forca_motor) {
    // Calcula a força de atrito no chão. Se o motor tiver 50N e o chão só aguentar 30N, temos apenas 30N.
    f_atrito = coef_atrito * massa_robo * GRAVIDADE;

    if (forca_motor > f_atrito) {
        printf("\nATENÇÃO!\n A força do motor excede a força de atrito.\n")
        return f_atrito;
    } else {
        return forca_motor;
    }

}

static inline double corrente_stall_motor(t_voltagem voltagem, t_resistencia res_interna, t_corrente limite_ponteh) {
    double corrente = voltagem / res_interna;
    if (corrente > limite_ponteh) {
        printf("\n\nATENÇÃO!\nA corrente do motor excede o limite da ponte-h.\n");
    }
    return corrente;
}

static inline double runtime_bateria(bateria *params_bateria, t_corrente corrente_stall, t_corrente corrente_livre) {
    double corrente_media = (corrente_stall * 0.6) + (corrente_livre * 0.4);
    return ((params_bateria->capacidade * 0.8) / corrente_media) * 60;
};

static inline t_voltagem queda_tensao(t_corrente corrente_total, t_resistencia res_interna_bat) {
    return corrente_total * res_interna_bat;
}

