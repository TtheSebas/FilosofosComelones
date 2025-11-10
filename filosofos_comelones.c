#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 
#define N 5 // Número de Filósofos y Palillos

pthread_mutex_t palillos[N]; 

int filosofo_ids[N] = {0, 1, 2, 3, 4}; 

void *filosofo_accion(void *arg) {
    int id = *(int *)arg;
    int palillo_izquierdo = id;
    int palillo_derecho = (id + 1) % N;

    while (1) {
        printf("Filósofo %d está pensando.\n", id);
        sleep(rand() % 3 + 1); 

        printf("Filósofo %d tiene Hambre.\n", id);

        if (id % 2 == 0) { 
            pthread_mutex_lock(&palillos[palillo_izquierdo]);
            printf("Filósofo %d toma palillo %d (Izquierdo).\n", id, palillo_izquierdo);

            pthread_mutex_lock(&palillos[palillo_derecho]);
            printf("Filósofo %d toma palillo %d (Derecho).\n", id, palillo_derecho);
        } else { 
            pthread_mutex_lock(&palillos[palillo_derecho]);
            printf("Filósofo %d toma palillo %d (Derecho).\n", id, palillo_derecho);

            pthread_mutex_lock(&palillos[palillo_izquierdo]);
            printf("Filósofo %d toma palillo %d (Izquierdo).\n", id, palillo_izquierdo);
        }

        printf("Filósofo %d está COMIENDO. \n", id);
        sleep(rand() % 3 + 1); 

        printf("Filósofo %d termina de comer y suelta los palillos.\n", id);
        pthread_mutex_unlock(&palillos[palillo_derecho]);
        pthread_mutex_unlock(&palillos[palillo_izquierdo]);
    }

    return NULL;
}

int main() {
    pthread_t filosofos[N];
    int i;

    for (i = 0; i < N; i++) {
        pthread_mutex_init(&palillos[i], NULL);
    }

    for (i = 0; i < N; i++) {
        pthread_create(&filosofos[i], NULL, filosofo_accion, &filosofo_ids[i]);
    }

    for (i = 0; i < N; i++) {
        pthread_join(filosofos[i], NULL);
    }

    for (i = 0; i < N; i++) {
        pthread_mutex_destroy(&palillos[i]);
    }

    return 0;
}
