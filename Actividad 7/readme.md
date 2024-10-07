# Completely Fair Scheduler (CFS) de Linux

El **Completely Fair Scheduler (CFS)** es el planificador de procesos predeterminado en el Kernel de Linux desde la versión 2.6.23. Se diseñó para mejorar la eficiencia del manejo de procesos, ofreciendo una distribución equitativa de los tiempos de CPU entre los procesos de manera justa y precisa. Las principales características y el funcionamiento del CFS son las siguientes:

## Características principales:

1. **Justicia (Fairness):**
   - El objetivo principal del CFS es garantizar que todos los procesos obtengan una proporción justa del tiempo de CPU. A diferencia de los planificadores tradicionales que utilizan prioridades estáticas o dinámicas, el CFS asigna tiempo de CPU basado en la cantidad de tiempo que cada proceso ha consumido en relación con otros procesos.
2. **Estructura de árbol rojo-negro:**

   - El CFS utiliza una estructura de datos **árbol rojo-negro** para almacenar los procesos listos para ejecutarse. Esta estructura permite operaciones eficientes de búsqueda, inserción y eliminación en tiempo logarítmico, lo que mejora el rendimiento en sistemas con muchos procesos.

3. **Tiempo virtual (Virtual Runtime - vruntime):**
   - Cada proceso tiene un valor de tiempo virtual, llamado **vruntime**, que representa el tiempo de CPU que ha recibido. Los procesos con menor vruntime tienen mayor prioridad para ser ejecutados. El CFS selecciona siempre el proceso con el menor vruntime para ejecutarse, lo que asegura que los procesos que menos tiempo de CPU han recibido obtengan más tiempo de ejecución.
4. **No utiliza cuantum fijo:**

   - A diferencia de los planificadores tradicionales que asignan a cada proceso un **quantum de tiempo fijo**, el CFS ajusta dinámicamente la cantidad de tiempo que un proceso puede ejecutar antes de ser interrumpido. Este tiempo se basa en su **vruntime** y en la carga del sistema.

5. **Soporte para carga ponderada (Weighted Fair Scheduling):**

   - El CFS permite asignar diferentes "pesos" a los procesos mediante la **niceness**. Los procesos con mayor prioridad (menor valor de nice) tienen un peso más alto y, por lo tanto, obtienen más tiempo de CPU, mientras que los procesos con menor prioridad (mayor valor de nice) obtienen menos tiempo.

6. **Baja latencia:**
   - CFS está optimizado para proporcionar baja latencia, lo que lo hace adecuado para sistemas de escritorio o interactivos donde se espera que las aplicaciones respondan rápidamente a la entrada del usuario.

## Funcionamiento del CFS:

1. **Selección del proceso a ejecutar:**

   - El CFS selecciona el proceso con el menor valor de **vruntime** en la cola de procesos listos para ejecutarse. Este proceso se ejecuta hasta que su vruntime aumenta lo suficiente como para que otro proceso tenga una prioridad más alta (menor vruntime), momento en el cual se realiza un **cambio de contexto**.

2. **Actualización del vruntime:**

   - Mientras el proceso está en ejecución, su vruntime se incrementa en función del tiempo de CPU que consume. Los procesos de baja prioridad (con un valor de nice alto) acumulan vruntime más rápidamente que los procesos de alta prioridad, lo que garantiza que los procesos menos importantes no acaparen la CPU.

3. **Preempción:**

   - Si un nuevo proceso con un menor vruntime se convierte en elegible para la ejecución (por ejemplo, cuando un proceso se despierta), el proceso actualmente en ejecución puede ser interrumpido (preempted) y se selecciona el proceso con el menor vruntime.

4. **Control de carga de CPU:**
   - El CFS ajusta el tiempo de ejecución de los procesos en función de la carga total de la CPU. Si hay muchos procesos en ejecución, cada uno recibe menos tiempo de CPU para asegurar que todos puedan ejecutarse en un período razonable.

## Ventajas del CFS:

- **Justicia en la distribución de CPU**: Garantiza que todos los procesos reciban tiempo de CPU de manera equitativa, sin favorecer excesivamente a los procesos de alta prioridad.
- **Baja latencia**: Responde rápidamente a eventos de usuario, lo que mejora la experiencia en sistemas interactivos.
- **Escalabilidad**: El uso del árbol rojo-negro permite que el CFS maneje eficientemente grandes cantidades de procesos.

## Desventajas del CFS:

- **Sobrecarga en sistemas ligeros**: En sistemas con pocas tareas, la estructura de árbol rojo-negro puede añadir cierta complejidad innecesaria.
- **No está optimizado para sistemas en tiempo real**: Aunque es adecuado para sistemas de propósito general, el CFS no garantiza plazos estrictos como lo haría un planificador de tiempo real.
