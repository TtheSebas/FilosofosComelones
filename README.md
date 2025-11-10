# FilosofosComelones
# Problema de los Filósofos Comelones (Solución Asimétrica)

Este repositorio contiene la implementación en C del clásico problema de concurrencia de los Filósofos Comelones, resuelto con la estrategia de **Adquisición Asimétrica de Recursos** para prevenir el interbloqueo (Deadlock).

## Estrategia de Solución

La solución implementada utiliza **Mutexes** (`pthread_mutex_t`) para representar los palillos, garantizando la exclusión mutua. Para evitar el *deadlock*, se rompe la condición de espera circular forzando una jerarquía en la adquisición de recursos:

* **Filósofos Pares (0, 2, 4):** Toman el palillo **Izquierdo**, luego el **Derecho**.
* **Filósofos Impares (1, 3):** Toman el palillo **Derecho**, luego el **Izquierdo**.

##Compilación y Ejecución

El código requiere la librería POSIX Threads (`-pthread`).

1.  **Compilar:**
    ```bash
    gcc filosofos_comelones.c -o filosofos -pthread
    ```

2.  **Ejecutar:**
    ```bash
    ./filosofos
    ```

## Reporte de Análisis

El documento `Reporte_Filosofos_Comelones.pdf` contiene el análisis detallado de cómo esta solución previene las condiciones de:
* **Race Condition** (Exclusión Mutua con Mutexes)
* **Deadlock** (Ruptura de la Espera Circular)
* **Starvation** (Uso de políticas de justicia del S.O. y tiempos aleatorios)
