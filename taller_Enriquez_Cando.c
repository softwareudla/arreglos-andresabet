#include <stdio.h>

int main() {
    // Declaramos la matriz de 5 estudiantes y 3 materias
    float calificaciones[5][3];
    float promedio[5];  
    float promedioM[3];  
    char resultado[5][3];
    float notaA_est[5];
    float notaB_est[5];
    float notaA_mat[3];
    float notaB_mat[3];

    // Pedir al usuario que ingrese las calificaciones
    printf("Ingresa las calificaciones para 5 estudiantes y 3 materias (solo entre 0 y 10):\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            do {
                // Modificar el nombre de las materias en la entrada
                if (j == 0) printf("Estudiante %d, Matemáticas: ", i + 1);
                if (j == 1) printf("Estudiante %d, Lenguaje: ", i + 1);
                if (j == 2) printf("Estudiante %d, Física: ", i + 1);

                scanf("%f", &calificaciones[i][j]);

                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("Calificación inválida. Debe ser un número entre 0 y 10. Inténtalo nuevamente.\n");
                }
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }

    // Calcular el promedio de cada estudiante y si aprobaron o reprobaron 
    for (int i = 0; i < 5; i++) {
        float suma = 0;
        notaB_est[i] = calificaciones[i][0];  // Inicializar con la primera calificación
        notaA_est[i] = calificaciones[i][0];  // Inicializar con la primera calificación

        for (int j = 0; j < 3; j++) {
            if (notaA_est[i] < calificaciones[i][j]) {
                notaA_est[i] = calificaciones[i][j];  // Actualizar la nota mayor
            }
            if (notaB_est[i] > calificaciones[i][j]) {
                notaB_est[i] = calificaciones[i][j];  // Actualizar la nota menor
            }
            suma += calificaciones[i][j];

            if (calificaciones[i][j] >= 7) {
                resultado[i][j] = 'A'; // Aprobado
            } else {
                resultado[i][j] = 'R'; // Reprobado
            }
        }
        promedio[i] = suma / 3;  // Calcular el promedio
    }

    // Calcular el promedio y las notas mayor/menor de cada materia
    for (int i = 0; i < 3; i++) {
        float suma = 0;
        notaB_mat[i] = calificaciones[0][i];  // Inicializar con la primera calificación
        notaA_mat[i] = calificaciones[0][i];  // Inicializar con la primera calificación

        for (int j = 0; j < 5; j++) {
            if (notaA_mat[i] < calificaciones[j][i]) {
                notaA_mat[i] = calificaciones[j][i];  // Actualizar la nota mayor
            }
            if (notaB_mat[i] > calificaciones[j][i]) {
                notaB_mat[i] = calificaciones[j][i];  // Actualizar la nota menor
            }
            suma += calificaciones[j][i];
        }
        promedioM[i] = suma / 5;  // Calcular el promedio
    }

    // Imprimir las calificaciones, promedios y resultados
    printf("\nEstudiante\tMatemáticas\tLenguaje\tFísica\t\tPromedio\n");
    for (int i = 0; i < 5; i++) {
        printf("\t%d\t\t", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t\t", calificaciones[i][j]);
        }
        printf("%.2f\n", promedio[i]);  // Imprimir el promedio del estudiante
    }

    // Imprimir el promedio de cada materia
    printf("\nPromedios por Materia\n");
    printf("\tMatemáticas: %.2f\n", promedioM[0]);
    printf("\tLenguaje: %.2f\n", promedioM[1]);
    printf("\tFísica: %.2f\n", promedioM[2]);

    // Imprimir la tabla de aprobación o reprobación por materia para cada estudiante
    printf("\nEstudiante\tMatemáticas\tLenguaje\tFísica\n");
    for (int i = 0; i < 5; i++) {
        printf("\t%d\t\t", i + 1);
        for (int j = 0; j < 3; j++) {
            if (resultado[i][j] == 'A') {
                printf("Aprobado\t");
            } else {
                printf("Reprobado\t");
            }
        }
        printf("\n");
    }

    // Imprimir las notas mayor y menor de cada estudiante
    printf("\nEstudiante\tNota Mayor\tNota Menor\n");
    for (int i = 0; i < 5; i++) {
        printf("\t%d\t\t%.2f\t\t%.2f\n", i + 1, notaA_est[i], notaB_est[i]);
    }

    // Imprimir las notas mayor y menor de cada materia
    printf("\nMaterias\tNota Mayor\tNota Menor\n");
    printf("\tMatemáticas\t%.2f\t\t%.2f\n", notaA_mat[0], notaB_mat[0]);
    printf("\tLenguaje\t%.2f\t\t%.2f\n", notaA_mat[1], notaB_mat[1]);
    printf("\tFísica\t\t%.2f\t\t%.2f\n", notaA_mat[2], notaB_mat[2]);

    return 0;
}
