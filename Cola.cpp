#include "Cola.h"

#define ANGULO 10  // Ángulo de rotación
#define NUM_CUBOS 1000  // Número total de cubos en la espiral
#define M_PI 3.14159265358979323846


Cola::Cola() {}

void Cola::display() {
    glPushMatrix();

    for (int i = 0; i < NUM_CUBOS; i++) {
        float angle = i * ANGULO; // Calculamos el ángulo para cada cubo
        float theta = angle * M_PI / 180.0; // Convertimos ángulo a radianes

        // Calculamos la posición en el plano X-Y usando la función coseno y seno
        float x = cos(theta) * 2.0;
        float y = sin(theta) * 2.0;
        float z = i * 0.5; // Desplazamiento en el eje Z

        glPushMatrix();

        glTranslatef(x, y, z); // Movemos el cubo a la posición calculada

        glRotatef(angle, 0.0, 0.0, 1.0); // Rotamos el cubo según el ángulo

        glScalef(2.0, 0.4, 1.0); // Escalamos el cubo

        glutSolidCube(1.0); // Dibujamos el cubo

        glPopMatrix();
    }

    glPopMatrix();
}
