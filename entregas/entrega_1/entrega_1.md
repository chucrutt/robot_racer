# Entrega 1

## Diseño Conceptual del Robot
- Dimensiones y peso aproximado
    Insertar dibujo del diseño del robot
- Inspiración y concepto del robot
    Basado en el diseño de FujitoraBot: https://github.com/OPRobots/FujitoraBot
- Explicar y justificar de qué manera el robot se moverá
    - Muy rápido
- Objetivos del robot
    - Ganar

## Selección de Componentes
- Hardware
    - Sensores: 
        - Delanteros: QTR-8A (entrada analogica) https://www.pololu.com/product/960 otras opciones https://www.pololu.com/category/123/pololu-qtr-reflectance-sensors
        - Laterales: QTR-1A https://www.pololu.com/product/2458 o QRE1113 (¿Necesita controlador adicional para interpretar la señal?) https://www.mouser.cl/ProductDetail/onsemi-Fairchild/QRE1113?qs=ne66E0WZ%2FFkJiYCW1J5zEw%3D%3D
    - Motores: Micro Metal Gear Motors (¿6V o 12V? depende de bateria) (encoder opcional) https://www.pololu.com/category/60/micro-metal-gearmotors
    - Driver: Acorde a las características del motor https://www.pololu.com/category/11/brushed-dc-motor-drivers
    - Ruedas: Llantas impresas en 3D con PLA o PETG y goma o silicona para el neumático
    - Chasis: PCB
    - MicroControlador: ArduinoNano
    - Bateria: Litio recargable (por investigar)
    - Otros:
        - Pulsador/es para Arduino
        - Power switch
        - Resistencias
        - Capacitor
- Descripción
- Justificación de elección
    - Sensores: Dado que la línea es blanca y la pista negra, queremos usar fototransistores, creemos que un arreglo de 8 es suficiente, idealmente con entrada analógica, en caso de no tener suficientes entradas analogicas, podríamos considerar usar sensores con entrada digital o cambiar el microcontrolador a uno de mayor capacidad. Para poder detectar las marcas laterales de la pista (marcas para curvas y de inicio/fin del circuito) usaremos sensores laterales exactamente iguales a los delanteros pero individuales. (El QRE1113 necesita una resistencia pull-up y montaje personalizado, pero permite ahorrar espacio y peso.)
    - Motores: Los Micro Metal Gear Motors son una opción probada en robots de competencia. Ofrecen buena relación peso/potencia, tamaños compactos y existen diferentes opciones de relación de engranaje según la necesidad de torque vs velocidad.
    - Driver: Se seleccionará un driver que soporte la corriente pico de los motores (especialmente durante la aceleración o cambios bruscos de dirección)
    - Ruedas: Las llantas impresas en 3D permiten personalizar el diámetro y diseño. El uso de PLA o PETG aporta resistencia y bajo peso, mientras que la cubierta de goma o TPU garantiza el agarre necesario para soportar maniobras rápidas sin derrapes, mejorando la tracción.
    - Chasis: Utilizar una PCB como chasis nos permite eliminar cables sueltos, reduciendo peso y permitiendo conexiones mucho más estables. Esto también facilita el diseño compacto y el mantenimiento. Además, un chasis PCB permite fabricar múltiples copias si se necesita.
    - MicroControlador: El Arduino Nano es compacto, económico, fácil de programar y compatible con muchos sensores y drivers. Si no se cuenta con suficientes pines analógicos, podría considerarse un microcontrolador superior como el Arduino Nano Every.
    - Bateria: Eligiremos una batería de litio recargable que pueda entregar suficiente corriente para los motores. El voltaje nominal de la batería influirá directamente en la elección final de los motores y el driver.
    - Otros: Pulsador: permite poder controlar el robot para darle inicio y calibrarlo antes de la carrera; Switch: es una opción adicional de seguiridad para la bateria, permite tener mayor control sobre ella; Resistencias: Para proteger y controlar los componentes como los sensores; Capacitor: Para estabilizar el voltaje entregado por la bateria hacia el microcontrolador y los motores.

- Link a la tienda y el precio (límite 100k clp): Cada componente tiene su link correspondiente a su derecha.