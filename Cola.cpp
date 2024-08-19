#include "Cola.h"

#define ANGULO 10  // �ngulo de rotaci�n
#define NUM_CUBOS 1000  // N�mero total de cubos en la espiral
#define M_PI 3.14159265358979323846


Cola::Cola() {}

void Cola::display() {
    glPushMatrix();

    for (int i = 0; i < NUM_CUBOS; i++) {
        float angle = i * ANGULO; // Calculamos el �ngulo para cada cubo
        float theta = angle * M_PI / 180.0; // Convertimos �ngulo a radianes

        // Calculamos la posici�n en el plano X-Y usando la funci�n coseno y seno
        float x = cos(theta) * 2.0;
        float y = sin(theta) * 2.0;
        float z = i * 0.5; // Desplazamiento en el eje Z

        glPushMatrix();

        glTranslatef(x, y, z); // Movemos el cubo a la posici�n calculada

        glRotatef(angle, 0.0, 0.0, 1.0); // Rotamos el cubo seg�n el �ngulo

        glScalef(2.0, 0.4, 1.0); // Escalamos el cubo

        glutSolidCube(1.0); // Dibujamos el cubo

        glPopMatrix();
    }

    glPopMatrix();
}
