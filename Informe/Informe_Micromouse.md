# Informe Versión Micromouse

## Diseño Conceptual

### Dimensiones y peso aproximado
### Inspiración y concepto del robot
https://github.com/elixir7/Micromouse?tab=readme-ov-file
https://medium.com/analytics-vidhya/mm-sensors-and-motors-7fa3a870db67
https://deesblog.fyi/getting-started-in-the-micromouse-journey-1/
### Explicar y justificar de que manera el robot se moverá (tracción simple, tracción doble, movimiento omnidireccional, etc.)
### Explicar y justificar de qué manera el robot percibirá el laberinto y sus paredes
### Objetivos del robot (metas realistas para completar competencia robótica)

## Selección de componentes

### Microcontrolador
Para el control de nuestro micromouse hemos elegido la plataforma Arduino, en particular el microcontrolador Arduino Nano. Escogimos Arduino considerando que no tenemos tanta experiencia en cuanto a microcontroladores, buscamos un formato de tamaño reducido, es una excelente opción para proyectos compactos de robótica, tiene un bajo consumo de energía, es fácil de programar y es compatible con una gran variedad de sensores y controladores. Además ante cualquier problema Arduino tiene una gran variedad de información en internet, buena documentación y soporte de la comunidad.

### Motores
Precisión y velocidad son dos parametros importantes a considerar al momento de crear un micromouse, lo ideal sería tener ambas, sin embargo existe una compensación entre velocidad y precision y es importante elegir bien los sensores y motores para tener un buen equilibrio.
Los motores se encargarán del movimiento y velocidad del micromouse. El tamaño de los motores suele ser determinante para el ancho del robot, y como parte del desafío es hacer el robot pequeño, estos también deben serlo. El motor más comun para proyectos de este tipo y de los más populares es el N-20, al ser un motor tan común existen también mucha variedad de drivers, encoders, y versiones con diferentes valores de RPM. Hemos decidido trabajar con motores con escobillas de carbón (brushed carbon) pues son más economicos y simples de controlar, además del uso de encoders para tener mayor precisión en las distancias recorridas, eligiremos un motor con una velocidad de 1100RPM, 6V y corriente máxima de 1.5A, esto nos permite tener una buena relación entre velocidad y torque manteniendo al motor dentro de las limitaciones de una bateria LiPo 2S 25C. https://www.pololu.com/product/5184

### Giroscopio/Acelerometro
https://mcielectronics.cl/shop/product/modulo-sensor-de-giroscopio-acelerometro-de-3-ejes-gy-521-mpu-6050-compatible-con-arduino-30161/

### Driver
https://www.pololu.com/product/1213

### Bateria
https://es.aliexpress.com/item/1005008556601041.html?spm=a2g0o.productlist.main.3.5859vbyqvbyqxx&algo_pvid=4135cdb9-26fa-43a1-a62d-3a7607751e3f&algo_exp_id=4135cdb9-26fa-43a1-a62d-3a7607751e3f-2&pdp_ext_f=%7B%22order%22%3A%221112%22%2C%22eval%22%3A%221%22%2C%22orig_sl_item_id%22%3A%221005008556601041%22%2C%22orig_item_id%22%3A%221005007169904578%22%7D&pdp_npi=4%40dis%21CLP%2121122%2110561%21%21%21157.06%2178.53%21%402101d9ee17462205903266831ee138%2112000045696564616%21sea%21CL%213475073591%21X&curPageLogUid=tfQ7AqHsuoe0&utparam-url=scene%3Asearch%7Cquery_from%3A

### Sensores
Los sensores son quienes se ancargan de medir las distancias de los muros en torno al micromouse sin que este las toque. Existen principalmente 3 tipos de sensores para medir distancias: ultra-sonido, infrarojos (IR) y tiempo de vuelo (ToF).
Para decidir qué sensor es mejor usar en el caso de micromouse consideramos 5 parametros: velocidad de respuesta, precisión, rango de distancia, tamaño físico y precio. Considerando que los sensores de ultra-sonido son grandes, voluminosos, más lentos en comparación a los otros dos y de baja precisión a cortas distancias, hemos decidido descartarlo. Por otro lado los sensores infrarojos y de tiempo de vuelo son buenas opciones en general para un micromouse, la principal diferencia entre estos dos es que los sensores ToF miden el tiempo de vuelo de la luz infraroja, y los sensores IR miden la intensidad de la luz infraroja reflejada, por lo que los sensores IR tienen una respuesta más rápida que los ToF pero a un mayor precio.

[(VL53L3CX ToF Distance Sensor by Pololu (10mm - 500mm)) https://www.pololu.com/product/3416 la única desventaja de este sensor es que tiene un angulo de vision rasonable (25°) por lo que es necesario tener varios] tiene buena velocidad de respuesta (125Hz) además de estar dentro del rango del voltaje para un micro-controlador Arduino (2.2V - 5.5V) 

Alternativas IR (si van dentro del presupuesto): https://www.pololu.com/product/2450 https://www.pololu.com/product/2464

### Otros
Buzzer 5V
Pulsador
Regulador de voltaje 5V




### Lista de piezas necesarias para el robot (tabla)
    - Nombre del periférico o parte
    - Descripción
    - Justificación de elección
    - Link a la tienda y precio (máx. $300.000 clp)

## Mensajes para el grupo
    - Investigar una inspiración para micromouse, sea un repositorio, informe, documentación o video de youtube
    - Objetivo: al ser un primer diseño para micromouse no buscamos que sea el más rápido ni que tenga soluciónes complejas, buscamos principalmente confiabilidad, es decir, que pueda resolver el laberinto sin problemas.



