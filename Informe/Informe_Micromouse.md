# Informe Versión Micromouse

## Diseño Conceptual

### Dimensiones y peso aproximado
### Inspiración y concepto del robot
https://github.com/elixir7/Micromouse?tab=readme-ov-file
https://medium.com/analytics-vidhya/mm-sensors-and-motors-7fa3a870db67
### Explicar y justificar de que manera el robot se moverá (tracción simple, tracción doble, movimiento omnidireccional, etc.)
### Explicar y justificar de qué manera el robot percibirá el laberinto y sus paredes
### Objetivos del robot (metas realistas para completar competencia robótica)

## Selección de componentes
Precisión y velocidad son dos parametros importantes a considerar al momento de crear un micromouse, lo ideal sería tener ambas, sin embargo existe una compensación entre velocidad y presión y es importante elegir bien los sensores y motores para tener un buen equilibrio.

### Sensores
Los sensores son quienes se ancargan de medir las distancias de los muros en torno al micromouse sin que este las toque. Existen principalmente 3 tipos de sensores para medir distancias: ultra-sonido, infrarojos (IR) y tiempo de vuelo (ToF).
Para decidir qué sensor es mejor usar en el caso de micromouse consideramos 5 parametros: velocidad de respuesta, precisión, rango de distancia, tamaño físico y precio. Considerando que los sensores de ultra-sonido son grandes, voluminosos, más lentos en comparación a los otros dos y de baja precisión a cortas distancias, hemos decidido descartarlo. Por otro lado los sensores infrarojos y de tiempo de vuelo son buenas opciones en general para un micromouse, la principal diferencia entre estos dos es que los sensores ToF miden el tiempo de vuelo de la luz infraroja, y los sensores IR miden la intesnidad de la luz infraroja reflejada, por lo que los sensores IR tienen una respuesta más rápida que los ToF pero a un mayor precio.

[(VL53L3CX ToF Distance Sensor by Pololu (10mm - 500mm)) https://www.pololu.com/product/3416 la única desventaja de este sensor es que tiene un angulo de vision rasonable (25°) por lo que es necesario tener varios] tiene buena velocidad de respuesta (125Hz) además de estar dentro del rango del voltaje para un micro-controlador Arduino (2.2V - 5.5V) 
### Motores
Los motores se encargarán del movimiento y velocidad del micromouse. El tamaño de los motores suele ser determinante para el ancho del robot, y como parte del desafío es hacer el robot pequeño, estos también deben serlo. El motor más comun para proyectos de este tipo y de los más populares es el N-20, al ser un motor tan común existen también mucha variedad de drivers, encoders, y versiones con diferentes valores de RPM por lo que hemos decidido trabajar con él. (Micro Metal Gearmotor HPCB 12V with 12 CPR Encoder, 650 RPM, 0.75A) https://www.pololu.com/product/5212

### Lista de piezas necesarias para el robot (tabla)
    - Nombre del periférico o parte
    - Descripción
    - Justificación de elección
    - Link a la tienda y precio (máx. $300.000 clp)

## Mensajes para el grupo
    - Investigar una inspiración para micromouse, sea un repositorio, informe, documentación o video de youtube
    - Objetivo: al ser un primer diseño para micromouse no buscamos que sea el más rápido ni que tenga soluciónes complejas, buscamos principalmente confiabilidad, es decir, que pueda resolver el laberinto sin problemas.



