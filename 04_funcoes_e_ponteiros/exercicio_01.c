/*
 * Escreva um programa, estruturado em diversas funções, para calcular o volume de
 * um peça formada por uma esfera com um furo cilíndrico, conforme ilustrado na
 * Figura 4.6. Sabe-se que o volume de uma calota esférica de altura h é dada por
 * (1/3)pih^2(3R - h), onde R representa o raio da esfera.
 */

#include <stdio.h>

float calcula_volume_esfera(float r_esf)
{
	return 4.0 / 3 * 3.1415 * r_esf * r_esf * r_esf;
}

float calcula_volume_calota(float r_esf, float h_cal)
{
	return 1.0 / 3 * 3.1415 * h_cal * h_cal * (3 * r_esf - h_cal);
}

float calcula_volume_cilindro(float r_cal, float h_cil)
{
	return 3.1415 * r_cal * r_cal * h_cil;
}

float calcula_volume_peca(float d_esf, float d_cal, float h_cal)
{
	float r_esf = d_esf / 2;
	float r_cal = d_cal / 2;
	float h_cil = d_esf - 2 * h_cal;
	float v_esf = calcula_volume_esfera(r_esf);
	float v_cal = calcula_volume_calota(r_esf, h_cal);
	float v_cil = calcula_volume_cilindro(r_cal, h_cil);

	return v_esf - (2 * v_cal + v_cil);
}
