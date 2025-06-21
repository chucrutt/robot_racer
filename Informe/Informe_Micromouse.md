# Informe Versión Micromouse

## Diseño Conceptual
(diseño de micrmouse, ya sea dibujo o modelo 3d)

### Dimensiones y peso aproximado
Las dimensiones aproximadas del micromouse son las siguientes:
- 9.9 cm de largo
- 9.9 cm de ancho
- 5 cm de altura
- El peso aproximado del robot es 200g

### Inspiración y concepto del robot
[Repositorio GitHub - elixir7/Micromouse](https://github.com/elixir7/Micromouse?tab=readme-ov-file)

[MM Sensors and Motors - Medium](https://medium.com/analytics-vidhya/mm-sensors-and-motors-7fa3a870db67)

[Dee's Blog - Getting Started in the Micromouse Journey](https://deesblog.fyi/getting-started-in-the-micromouse-journey-1/)

[Repositorio GitHub - ISmillex/SpeedMicroMouse](https://github.com/ISmillex/SpeedMicroMouse)

[](https://www.researchgate.net/publication/267394680_DISENO_Y_CONSTRUCCION_DE_MICROMOUSE_DE_ALTO_DESEMPENO)

[](https://kswichit.net/micromouse/micromouse.html)

[Peter Harrison - Micromouse Book](https://micromouseonline.com/micromouse-book/introduction/)


### Explicar y justificar de que manera el robot se moverá (tracción simple, tracción doble, movimiento omnidireccional, etc.)
Para el movimiento del micromouse usaremos un sistema de tracción simple, es decir, tendrá dos ruedas independientes a cada lado que le permitirán avanzar, retroceder y girar sobre su propio eje. Esta configuración no es omnidireccional, pero ofrece un buen control de dirección y velocidad.

### Explicar y justificar de qué manera el robot percibirá el laberinto y sus paredes
El micromouse utilizará sensores infrarrojos o sensores ToF para detectar las paredes del laberinto. Con esta información y con ayuda de un microcontrolador, ejecutaremos un algoritmo (Flood Fill o A* Search) que nos permitirá explorar y trazar el camino más corto hasta la meta.

### Objetivos del robot (metas realistas para completar competencia robótica)
Es común en este tipo de competencias tener soluciones complejas, optimización del camino más corto o eficiente hasta la meta, trazado de diagonales, altas velocidades, etc.
Sin embargo, al ser nuestra primera versión de micromouse, queremos comenzar con objetivos más realistas: crear un robot confiable, capaz de resolver el laberinto en un tiempo razonable, realizar algún tipo de optimización del recorrido (por mínima que sea) y que sea barato de construir.

## Selección de componentes

### Microcontrolador
Para el control de nuestro micromouse hemos elegido la plataforma Arduino, en particular el microcontrolador Arduino Nano. Escogimos Arduino considerando que no tenemos tanta experiencia con microcontroladores. Buscamos un formato de tamaño reducido, con bajo consumo de energía, fácil de programar y compatible con una gran variedad de sensores y controladores. Además, Arduino cuenta con abundante documentación y soporte en línea.

### Motores
Precisión y velocidad son dos parametros importantes a considerar al momento de crear un micromouse, lo ideal sería tener ambas, sin embargo existe una compensación entre velocidad y precision y es importante elegir bien los sensores y motores para tener un buen equilibrio.

Los motores se encargarán del movimiento y velocidad del micromouse. El tamaño de los motores suele ser determinante para el ancho del robot, y como parte del desafío es hacer el robot pequeño, estos también deben serlo. El motor más comun para proyectos de este tipo y de los más populares es el N-20, al ser un motor tan común existen también mucha variedad de drivers, encoders, y versiones con diferentes valores de RPM. Hemos decidido trabajar con motores con escobillas de carbón (brushed carbon) pues son más economicos y simples de controlar, además del uso de encoders para tener mayor precisión en las distancias recorridas, eligiremos un motor con una velocidad de 1100RPM, 6V y corriente máxima de 1.5A, esto nos permite tener una buena relación entre velocidad y torque manteniendo al motor dentro de las limitaciones de una bateria LiPo 2S 25C.
[Motor Pololu N20 1100RPM](https://www.pololu.com/product/5184)

### Giroscopio/Acelerometro
Usaremos el módulo MPU-6050 (GY-521), un sensor de giroscopio y acelerómetro de 3 ejes compatible con Arduino. Nos permitirá detectar giros y cambios de orientación del micromouse, mejorando la navegación y corrección de trayectoria.

[GY-521 MPU-6050](https://mcielectronics.cl/shop/product/modulo-sensor-de-giroscopio-acelerometro-de-3-ejes-gy-521-mpu-6050-compatible-con-arduino-30161/)

### Driver
[Controlador 2 Motores Dc - Driver Tb6612fng](https://triacs.cl/lamborghino/903-controlador-2-motor-tb6612fng-.html)

### Bateria
Usaremos una batería LiPo 2S 7.4V con capacidad suficiente para alimentar los motores, sensores y el microcontrolador por un tiempo adecuado.

[Batería LiPo 2S 7.4V 3000mAh](https://es.aliexpress.com/item/1005002003065955.html)

### Sensores
Los sensores son quienes se ancargan de medir las distancias de los muros en torno al micromouse sin que este las toque. Existen principalmente 3 tipos de sensores para medir distancias: ultra-sonido, infrarojos (IR) y tiempo de vuelo (ToF).
Para decidir qué sensor es mejor usar en el caso de micromouse consideramos 5 parametros: velocidad de respuesta, precisión, rango de distancia, tamaño físico y precio. Considerando que los sensores de ultra-sonido son grandes, voluminosos, más lentos en comparación a los otros dos y de baja precisión a cortas distancias, hemos decidido descartarlo. Por otro lado los sensores infrarojos y de tiempo de vuelo son buenas opciones en general para un micromouse, la principal diferencia entre estos dos es que los sensores ToF miden el tiempo de vuelo de la luz infraroja, y los sensores IR miden la intensidad de la luz infraroja reflejada, por lo que los sensores IR tienen una respuesta más rápida que los ToF pero a un mayor precio.

[VL53L4CD ToF Distance Sensor Carrier 1mm-120cm](https://www.pololu.com/product/3692) Fov 18°, 100Hz sample rate, 1mm resolution, consumption 25mA-40mA

[Alternativa IR] (https://www.pololu.com/product/2450 https://www.pololu.com/product/2464)

### Otros
Buzzer 5V: Para señales acústicas

[Buzzer Activo 5V]([https://www.pololu.com/product/1485](https://triacs.cl/modulos/690-buzzer-activo-5v-.html))

Pulsador: Para iniciar manualmente el robot

[Pulsador MCIElectronics 6,5x6,5x4 mm^3 g 50mA](https://mcielectronics.cl/shop/product/pulsador-9799/)

Regulador de voltaje 5V: Para alimentar el ArduinoNano

[Step-Down Voltage Regulator Pololu 17.8×17.8×8 mm^3 max 2.5A](https://www.pololu.com/product/2858)

Capacitor: Para estabilizar la enería que entrega la batería, especialmente cuando hay picos en el voltaje por cambios bruscos en el consumo.

[Capacitores 200 0.1uF-100uF -10x220uF 10V](https://mcielectronics.cl/shop/product/pack-de-capacitores-electroliticos-200-piezas-mci-electronics-28055/)

[Capacitores 300](https://es.aliexpress.com/item/1005001910209320.html)

### Lista de piezas necesarias para el robot (tabla)
- Nombre del periférico o parte
- Descripción
- Justificación de elección
- Link a la tienda y precio (máx. $300.000 clp)


## Diseño conceptual de programación

### Plan de hitos

### Mapa de estados del robot

### Funciones clave en loop
