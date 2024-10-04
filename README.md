# Philosophers

## Descripción. El problema de los filósofos comensales

El proyecto tiene como objetivo abordar uno de los problemas clásicos de la computación concurrente: el **problema de los filósofos comensales**. Este reto sirve para ilustrar las dificultades que pueden surgir cuando varios hilos compiten por recursos compartidos y la importancia de gestionar correctamente la concurrencia multihilo.

El problema se describe de la siguiente forma: En una mesa redonda se sientan una cantidad específica de filósofos. Cada uno de ellos alterna entre 3 actividades de comer, dormir y pensar. Cada uno trae un tenedor a la mesa, sin embargo, para poder comer cada filósofo necesita 2 tenedores, uno a su izquierda y otro a su derecha. El desafío surge porque solo hay la misma cantidad tenedores que filósofos, lo que significa que los recursos son limitados. Todos no pueden comer a la vez. El problema consiste en encontrar una manera de que todos los filósofos puedan comer de manera eficiente sin entrar en situaciones problemáticas.

## Problemas comunes en la programación concurrente y la solución

### 1. **Data Race (condición de carrera)**

Una condición de carrera ocurre cuando varios hilos (en este caso, filósofos) intentan acceder a los mismos recursos compartidos (los tenedores) al mismo tiempo, sin ninguna sincronización.
Esto puede llevar a comportamientos impredecibles o incorrectos en el programa. Por ejemplo, se debe proteger que un hilo pueda cambiar el valor de una variable y otro lo consulte mientras el anterior lo está cambiando. 
Es decir, si un filósofo toma un tenedor, hay que asegurar que ningún otro lo pueda tomar hasta que los suelta.

### 2. **Deadlock (bloqueo mutuo)**

El deadlock es un problema crítico en el que todos los filósofos toman un solo tenedor y se quedan esperando por el segundo, lo que genera una situación en la que ninguno puede continuar.
Cada filósofo está bloqueado, esperando eternamente que su vecino suelte el tenedor que necesita, y como resultado, ninguno puede comer ni seguir adelante.

### 3. **Starvation (inanición)**

Otro posible problema es la inanición, que ocurre cuando un filósofo queda sin comer durante un largo periodo porque los otros filósofos acaparan constantemente los tenedores.
Aunque técnicamente el programa no esté bloqueado, un filósofo podría quedar en desventaja indefinidamente, esperando su turno para comer.

### Solución: Exclusión Mutua

Para resolver estos problemas, se utiliza una técnica conocida como **exclusión mutua**, que asegura que solo un filósofo pueda acceder a un tenedor a la vez.
De esta manera, evitamos que varios hilos (filósofos) entren en conflicto al intentar utilizar los mismos recursos al mismo tiempo. En este proyecto, la exclusión mutua se implementa utilizando mutex (bloqueos).
Un mutex es un mecanismo que permite "bloquear" un recurso para que solo un hilo (filósofo) pueda acceder a él, mientras los demás esperan su turno.
Así, cuando un filósofo toma un tenedor, se asegura de que ningún otro filósofo pueda tomarlo al mismo tiempo.

Además de los mutex, es importante definir un orden claro para que los filósofos tomen y dejen los tenedores. Por ejemplo, podemos asegurarnos de que un filósofo solo tome ambos tenedores si ambos están disponibles, o implementar reglas que reduzcan la probabilidad de deadlocks, como permitir que un máximo de cuatro filósofos intenten comer al mismo tiempo.

Para mas detalle se recomienda consultar el subject del proyecto que se adjunta.

