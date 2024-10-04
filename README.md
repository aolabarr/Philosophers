# Philosophers
42 cursus - Programación concurrente multihilo

El proyecto **Philosophers** de la Escuela 42 tiene como objetivo abordar uno de los problemas clásicos de la computación concurrente: el **problema de los filósofos comensales**. Este reto sirve para ilustrar las dificultades que pueden surgir cuando varios procesos compiten por recursos compartidos y la importancia de gestionar correctamente la concurrencia.

## El problema de los filósofos comensales

Imaginemos una mesa redonda en la que se sientan **cinco filósofos**. Cada uno de ellos alterna entre dos actividades: **pensar** y **comer**. Sin embargo, para poder comer, cada filósofo necesita **dos tenedores**, uno a su izquierda y otro a su derecha. El desafío surge porque solo hay cinco tenedores disponibles, uno entre cada par de filósofos, lo que significa que los recursos son limitados.

El problema consiste en encontrar una manera de que todos los filósofos puedan comer de manera eficiente sin entrar en situaciones problemáticas como el bloqueo o la inanición. A simple vista, parece fácil: cada filósofo toma los tenedores que necesita, come y los deja para que los otros los usen. Sin embargo, sin una adecuada coordinación, pueden surgir complicaciones importantes.

## Problemas comunes

### 1. **Data Race (condición de carrera)**

Una condición de carrera ocurre cuando varios hilos (en este caso, filósofos) intentan acceder a los mismos recursos compartidos (los tenedores) al mismo tiempo, sin ninguna sincronización.
Esto puede llevar a comportamientos impredecibles o incorrectos en el programa.
Por ejemplo, un filósofo podría "creer" que tiene ambos tenedores, pero en realidad otro filósofo ya ha tomado uno de ellos, lo que crea un conflicto.

### 2. **Deadlock (bloqueo mutuo)**

El **deadlock** es un problema crítico en el que todos los filósofos toman un solo tenedor y se quedan esperando por el segundo, lo que genera una situación en la que ninguno puede continuar.
Cada filósofo está bloqueado, esperando eternamente que su vecino suelte el tenedor que necesita, y como resultado, ninguno puede comer ni seguir adelante.

### 3. **Starvation (inanición)**

Otro posible problema es la **inanición**, que ocurre cuando un filósofo queda sin comer durante un largo periodo porque los otros filósofos acaparan constantemente los tenedores.
Aunque técnicamente el programa no esté bloqueado, un filósofo podría quedar en desventaja indefinidamente, esperando su turno para comer.

## Solución: Exclusión Mutua

Para resolver estos problemas, utilizamos una técnica conocida como **exclusión mutua**, que asegura que solo un filósofo pueda acceder a un tenedor a la vez.
De esta manera, evitamos que varios hilos (filósofos) entren en conflicto al intentar utilizar los mismos recursos al mismo tiempo.

### **Uso de mutex (pthread_mutex)**

En este proyecto, la exclusión mutua se implementa utilizando **mutex** (bloqueos).
Un **mutex** es un mecanismo que permite "bloquear" un recurso para que solo un hilo (filósofo) pueda acceder a él, mientras los demás esperan su turno.
Así, cuando un filósofo toma un tenedor, se asegura de que ningún otro filósofo pueda tomarlo al mismo tiempo.

Además de los **mutex**, es importante definir un orden claro para que los filósofos tomen y dejen los tenedores.
Por ejemplo, podemos asegurarnos de que un filósofo solo tome ambos tenedores si ambos están disponibles, o implementar reglas que reduzcan la probabilidad de **deadlocks**, como permitir que un máximo de cuatro filósofos intenten comer al mismo tiempo.

## Características adicionales

Este proyecto no solo busca resolver el problema del deadlock y la exclusión mutua. También es importante que los filósofos no queden esperando indefinidamente para comer, evitando el problema de la inanición.
Optimizar el acceso a los recursos compartidos es clave para que todos los filósofos tengan oportunidades justas de comer, mientras mantienen un programa eficiente y seguro.

---

En resumen, el proyecto **Philosophers** es una excelente introducción a los desafíos de la programación concurrente y el manejo de recursos compartidos. A través de la implementación de mecanismos como los **mutex** y el diseño cuidadoso de reglas de acceso, podemos asegurar que todos los filósofos tengan la oportunidad de comer sin caer en bloqueos o conflictos.

