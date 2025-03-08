# Laboratorio de Comunicaciones
## Universidad Industrial de Santander

---
# Práctica 1: GNURADIO Y RECONOCIMIENTO DE LOS EQUIPOS

### Integrantes
- **SANTIAGO HERNANDO POSADA BAYONA** - 2190428
- **NICOLAS ROJAS REYES** - 2210402

Escuela de Ingenierías Eléctrica, Electrónica y de Telecomunicaciones  
Universidad Industrial de Santander

### Fecha
07 de marzo de 2025

---

## Declaración de Originalidad y Responsabilidad
Los autores de este informe certifican que el contenido aquí presentado es original y ha sido elaborado de manera independiente. Se han utilizado fuentes externas únicamente como referencia y han sido debidamente citadas.

Asimismo, los autores asumen plena responsabilidad por la información contenida en este documento. 

Uso de IA: [mencionamos el uso de IA para corroborar la redacción, corroborar que sean correctas las referencias y que esten bien mencionadas en el documento, tambien la usamos para aclarar ciertas falencias teoricas y corroborar caracteristicas de los equipos usados en el laboratorio.]

---
## Contenido

### Resumen
Para esta practica se lleva a cabo la comprensión de lo que es el aplicativo GNURADIO,el realizar actividades para poder modelar espectros de señales y poder visualizar en tiempo real los fenomenos que tienen las señales de radio por medio de los equipos de laboratorio,para que así podamos irnos familiarizando con los equipos de medición pertinentes tales como el radio, osciloscopio y analizador de espectros,tambien el poder comprender los fenomenos fisicos que tienen estas señales al asignarle por medio de la aplicación GNURADIO distintos estimulos para que podamos someter estas señales a ciertas condiciones que podriamos encontrar en la practica en la vida real.

**Palabras clave:** 
GNURADIO,
OSCILOSCOPIO,
ESPECTRO,
RADIO,
SEÑAL.

### Introducción
- PRACTICA 1C:
- ACTIVIDAD 1:
- ¿Cómo se mide el piso de ruido en el analizador de espectros? ¿Cómo afecta la frecuencia central, SPAN y RBW la medida de piso de ruido? ¿Por qué?:
El nivel de ruido se mide en unidades dB (decibelios) o dBm ( decibelios en milivatios ), y es fundamental tener esto en cuenta para detectar cualquier sonido débil que pueda estar presente cerca de este nivel de ruido,la elección entre un RBW estrecho o ancho, así como el ajuste del SPAN, depende de lo que necesites priorizar en tu medición. Un RBW estrecho y un SPAN más amplio pueden hacer que el piso de ruido sea más notorio, mientras que un RBW más ancho y un SPAN reducido pueden ayudar a reducirlo, aunque con la desventaja de perder algo de resolución.
- ¿Cuál es el rango de frecuencia del USRP 2920 y cómo se compara con el del analizador de espectros?:el USRP 2920 ofrece un rango de frecuencia adecuado para una gran variedad de aplicaciones de radio definida por software, llegando hasta los 2.2 GHz. Sin embargo, para un análisis más detallado y preciso, especialmente en cuanto a la resolución de señales y la medición del piso de ruido, un analizador de espectros resulta ser más adecuado. Este tipo de equipo tiene la capacidad de medir frecuencias más altas y proporciona herramientas especializadas para caracterizar señales de manera más exacta.
- ¿Qué parámetros del USRP 2920 se deben configurar para transmitir una señal en una frecuencia específica?:
Para transmitir una señal en una frecuencia específica con un USRP 2920, es necesario configurar varios parámetros clave:

Frecuencia de transmisión (TX Frequency): Se debe establecer la frecuencia en la que se quiere transmitir la señal. Esto se hace configurando el parámetro tx_freq, generalmente en Hertz (Hz).

Tasa de muestreo (Sample Rate): Este parámetro define cuántas muestras por segundo se generan en el proceso de transmisión. Dependiendo del ancho de banda de la señal, se debe ajustar la tasa de muestreo para que sea adecuada al tipo de señal.

Ganancia de transmisión (TX Gain): La ganancia controla la potencia de la señal transmitida. Se ajusta según la necesidad de potencia de salida, y se expresa en decibelios (dB).

Selección de antena (TX Antenna): Si el USRP tiene varias antenas, se debe configurar cuál utilizar para la transmisión de la señal.

Tipo de modulación (si es necesario): Dependiendo de la aplicación, puede ser necesario configurar el tipo de modulación de la señal, como BPSK, QPSK, QAM, entre otras.
- ¿Cómo se configura el osciloscopio para medir la amplitud y la frecuencia de una señal?:Amplitud: Ajusta el control de Volts/Div para una medición precisa de la amplitud.
Frecuencia: Ajusta el control de Time/Div para ver varias oscilaciones y medir la frecuencia.
- ¿Qué diferencia hay entre medir una señal en el dominio del tiempo (osciloscopio) y en el dominio de la frecuencia (analizador de espectros)?:el osciloscopio es adecuado para analizar cómo cambia una señal en el tiempo, mientras que el analizador de espectros es mejor para entender su composición en frecuencia. Ambos son útiles según el tipo de análisis que se necesite realizar.
- ACTIVIDAD 2:

- ¿Cómo se puede explicar matemáticamente la diferencia entre una fuente de tipo flotante y una de tipo complejo?:Una fuente flotante representa una señal que solo tiene una componente real en función del tiempo, y su forma matemática generalmente se describe como una función de la amplitud y la frecuencia. Esta señal es comúnmente representada por una ecuación como 
𝑥(𝑡)=𝐴(𝑡)cos⁡(2𝜋𝑓𝑡+𝜙) x(t)=A(t)cos(2πft+ϕ), donde𝐴(𝑡)A(t) es la amplitud y𝜙ϕ la fase.
En cambio, una fuente compleja se refiere a una señal que tiene tanto una parte real como una parte imaginaria. Su expresión matemática usa la forma exponencial compleja 𝑥(𝑡)=𝐴(𝑡)𝑒𝑗(2𝜋𝑓𝑡+𝜙) x(t)=A(t)ej(2πft+ϕ) , donde la 𝑗 j indica la unidad imaginaria. Esto permite capturar información sobre la amplitud y la fase en una sola fórmula, lo que es útil para representar fenómenos más complejos y analizar señales en el dominio de la frecuencia.
- ¿Cómo afecta la forma de onda a la distribución de energía (potencia) en el dominio de la frecuencia?:la forma de onda determina cómo se distribuye la energía a lo largo del espectro de frecuencias. Las señales con formas más complejas, como las ondas cuadradas, tienen una distribución de energía más ancha y contienen más frecuencias, mientras que las señales simples, como las ondas sinusoidales, concentran su energía en una frecuencia específica.
- ¿Qué sucede con la señal en el dominio del tiempo y la frecuencia si se modifican los diferentes parámetros de la fuente? ¿Lo observado corresponde a lo esperado teóricamente?:cuando se modifican estos parámetros en el dominio del tiempo y la frecuencia está en línea con lo que se espera teóricamente. Las variaciones en la frecuencia, amplitud y fase de la señal se reflejan de manera predecible tanto en el comportamiento temporal de la señal como en su distribución de frecuencia, según los principios de la transformada de Fourier y las características fundamentales de las señales.
- ¿Cómo se relaciona la amplitud de la señal con la potencia observada en el dominio de la frecuencia?:la amplitud de una señal tiene un impacto directo en la potencia observada en el dominio de la frecuencia. A mayor amplitud en el dominio del tiempo, mayor es la potencia en el dominio de la frecuencia, y esto se refleja como un aumento en la magnitud de las componentes espectrales de la señal.
- ¿Qué diferencias se observan entre una señal senoidal y una señal cuadrada en el dominio de la frecuencia?:Señal senoidal: Toda la energía se concentra en una única frecuencia.
Señal cuadrada: La energía se distribuye a través de una serie de frecuencias que incluyen frecuencia fundamental y armónicos impares.
Por lo tanto, en el dominio de la frecuencia, la señal cuadrada tiene un espectro más ancho y complejo que la señal senoidal, la cual es monofrecuencia.

- ACTIVIDAD 3:
- ¿Cómo se configura el USRP 2920 para transmitir una señal en una frecuencia específica?:1.Conectar el USRP al sistema.
2.Instalar y configurar el software necesario (como UHD, GNU Radio, etc.).
3.Configurar el dispositivo USRP en el software.
4.Establecer la frecuencia de transmisión en el bloque correspondiente.
5.Ajustar parámetros como ganancia y tasa de muestreo.
6.Generar la señal a transmitir.
7.Iniciar la transmisión y verificar con un analizador de espectro.
- ¿Qué parámetros del flujograma afectan la potencia de la señal transmitida?:Los parámetros clave que afectan la potencia de la señal transmitida en un flujograma son la amplitud de la señal, la ganancia del amplificador, la impedancia de carga, el tipo de modulación, el ancho de banda, la tasa de transmisión, las condiciones del canal y la eficiencia de la antena. Todos estos factores deben ser cuidadosamente ajustados y optimizados para garantizar una transmisión eficiente y efectiva de la señal.
- ¿Cómo se mide el ancho de banda de la señal transmitida en el analizador de espectros?:El ancho de banda de la señal transmitida se mide observando el espectro de la señal en el analizador de espectros. Se determina identificando el rango de frecuencias donde la energía de la señal está presente, y típicamente se mide entre los puntos donde la potencia de la señal cae a -3 dB respecto al pico máximo. Es importante configurar correctamente el analizador para observar todo el espectro relevante y asegurarse de que el rango de frecuencias seleccionado incluya la totalidad de la señal transmitida.
- ¿Cómo se calcula la relación señal a ruido (SNR) a partir de las mediciones de potencia y piso de ruido?:La relación señal a ruido (SNR) se calcula tomando el cociente de la potencia de la señal y el piso de ruido, y luego aplicando una conversión logarítmica en dB.
- ¿Qué diferencias se observan en las mediciones de potencia cuando se varía la ganancia del USRP?:Mayor ganancia: Aumento de la potencia de salida, mejora de la SNR, pero riesgo de saturación y distorsión si la ganancia es demasiado alta.
Menor ganancia: Reducción de la potencia de salida, posible deterioro de la SNR, pero menor riesgo de distorsión y sobrecarga del sistema.
- ¿Es posible medir o estimar la potencia de la señal observada en el osciloscopio? ¿Por qué?Sí, se puede medir o estimar la potencia de la señal observada en un osciloscopio, principalmente a partir de la amplitud de la señal medida. Sin embargo, la precisión de esta estimación depende de la forma de la onda y de la configuración del sistema. El osciloscopio no es una herramienta especializada para mediciones directas de potencia, por lo que, aunque es posible hacer estimaciones razonables, la medición exacta de la potencia generalmente requiere un dispositivo dedicado como un medidor de potencia o un analizador de espectros.
  
- ACTIVIDAD 4:
- ¿Qué conclusiones se pueden obtener sobre la relación entre la potencia de la señal y la calidad de la comunicación?:La potencia de la señal juega un papel crítico en la calidad de la comunicación. Una señal con potencia adecuada mejora la relación señal a ruido y la fiabilidad de la transmisión, lo que resulta en una mejor calidad. Sin embargo, tanto la potencia excesiva como la potencia insuficiente pueden afectar negativamente la calidad de la comunicación. Por lo tanto, el ajuste preciso de la potencia, junto con el uso de técnicas de modulación y codificación, es esencial para mantener un sistema de comunicación eficiente y de alta calidad.
Mayor potencia generalmente mejora la calidad,Exceso de potencia puede causar distorsiones,Potencia adecuada para evitar interferencias,Potencia baja puede reducir la calidad,Equilibrio entre potencia y calidad,Calidad influenciada por otros factores.
- ¿Cómo afecta el piso de ruido a la capacidad de detectar señales débiles?:El piso de ruido tiene un impacto directo en la capacidad de detectar señales débiles. Si el piso de ruido es alto, la señal puede perderse entre el ruido, reduciendo la fiabilidad de la detección. Para mejorar esta capacidad, es esencial reducir el piso de ruido o aumentar la potencia de la señal para asegurar una mejor relación señal a ruido (SNR) y una detección más efectiva de las señales débiles.
- ¿Qué limitaciones tienen los equipos utilizados en términos de ancho de banda y precisión en las mediciones?:Las limitaciones de los equipos de medición en cuanto a ancho de banda y precisión son principalmente consecuencia de las capacidades técnicas de cada dispositivo, como su rango de frecuencias, resolución de medición, y precisión en la calibración. Además, factores como el ruido de fondo, la resolución de la señal y la frecuencia de muestreo también afectan las mediciones. Estas limitaciones pueden hacer que las mediciones de señales débiles o rápidas no sean completamente exactas si no se cuenta con equipos adecuados para esas condiciones específicas.
- ¿Cómo se pueden mejorar las mediciones de señal en un entorno con alto nivel de ruido?:ara mejorar las mediciones de señales en un entorno con alto nivel de ruido, se pueden emplear diversas estrategias, como el uso de filtros, el promediado de mediciones, la mejora de la relación señal a ruido (SNR), técnicas de corrección de errores, y el aislamiento de fuentes de interferencia. Además, utilizar equipos con alta resolución de frecuencia y tiempo, así como sistemas de diversidad, puede ayudar a mejorar la calidad y precisión de las mediciones. Adaptar las técnicas de medición al entorno y a las condiciones del canal es clave para obtener resultados confiables y precisos.
- ¿Qué aplicaciones prácticas tienen las mediciones de potencia y ancho de banda en sistemas de comunicaciones reales?:Las mediciones de potencia y ancho de banda son esenciales en una amplia gama de aplicaciones prácticas dentro de los sistemas de comunicaciones reales. Estas mediciones permiten optimizar el rendimiento, gestionar el espectro de frecuencias, controlar interferencias, y garantizar la calidad y fiabilidad de las comunicaciones en redes móviles, satelitales, de radar y de datos. Además, son cruciales en la prueba y calibración de equipos, el desarrollo de nuevos sistemas y la implementación de soluciones en entornos de emergencia.
- ¿Cómo se puede medir la respuesta en frecuencia de un canal alámbrico?:Medir la respuesta en frecuencia de un canal alámbrico implica transmitir señales de prueba a través del canal y luego analizar cómo el canal afecta estas señales en función de la frecuencia. Se pueden utilizar herramientas como generadores de señales, analizadores de espectros y analizadores de redes vectoriales (VNA) para obtener información detallada sobre la atenuación y el desfase en función de la frecuencia. Estos métodos son cruciales para entender el comportamiento del canal y optimizar el diseño de sistemas de comunicaciones.
- ¿Cómo se puede obtener un modelo sencillo de las pérdidas (pathloss) en un canal inalámbrico?:Propagación en espacio libre: En este modelo, la señal se atenúa según la distancia y la frecuencia. La fórmula básica es 𝐿(𝑑)=20log10(𝑑)+20log⁡10(𝑓)+𝐾 L(d)=20log10​(d)+20log10(f)+K, donde 𝑑 d es la distancia y 𝑓 f es la frecuencia.
Ley de Potencia: Basado en la relación de la potencia con la distancia, este modelo establece que la pérdida de señal varía con el cuadrado de la distancia. La fórmula es 𝐿(𝑑)=𝐿0+10𝑛log⁡10(𝑑/𝑑0) L(d)=L0 +10nlog10(d/d0), donde 𝑛 n es el exponente de propagación, que depende del entorno.
Modelo Hata (para entornos urbanos): Este modelo ajusta las pérdidas según la altura de las antenas y la frecuencia. Es más complejo y tiene en cuenta el entorno urbano o suburbano para estimar la propagación de la señal.
Entornos interiores: En espacios cerrados, como oficinas, se utiliza el modelo log-normal, que tiene en cuenta las variaciones causadas por paredes y obstáculos. Se expresa como 𝐿(𝑑)=𝐿0+𝑛log⁡10(𝑑)+𝑋𝜎 L(d)=L0​+nlog10(d)+Xσ , donde 𝑋𝜎 Xσ​
  es un término aleatorio que modela la variabilidad del canal.

  

### Procedimiento
### Practica 1_A
En la Práctica 1A, se llevaron a cabo diversas simulaciones en GNU Radio con el propósito de familiarizarse con su interfaz y funcionalidades. Durante la práctica, se modificaron parámetros como la frecuencia de muestreo, la frecuencia de la señal y el tipo de onda introducida, analizando la respuesta del sistema tras su paso por distintos bloques de procesamiento de señales tal y como se muestra a continuación:

![GNU Radio logo]()
![GNU Radio logo]()

Posteriormente, se realizó un análisis comparativo entre el límite de Nyquist y una frecuencia de muestreo mayor, estableciendo una relación de muestreo de 5:1 para evaluar las ventajas de operar con frecuencias superiores al límite teórico. Para este análisis, se empleó al menos una señal distinta a la senoidal, permitiendo observar de manera práctica los efectos del muestreo sobre distintas formas de onda.

![GNU Radio logo]()
![GNU Radio logo]()

A lo largo de la Práctica 1A, se logró una comprensión fundamental del entorno de GNU Radio, permitiendo la familiarización con su interfaz y la configuración de parámetros esenciales para el procesamiento de señales. Se experimentó con distintos valores de frecuencia de muestreo y frecuencia de la señal, así como con diferentes tipos de ondas, observando cómo cada ajuste impactaba en la señal procesada. Un aspecto clave fue la exploración del límite de Nyquist y la comparación con una frecuencia de muestreo mayor, demostrando la importancia de una correcta selección de la relación de muestreo para evitar efectos como el aliasing. A través de estos experimentos, se evidenció cómo una tasa de muestreo superior al límite de Nyquist permite una representación más fiel de la señal original, garantizando una mejor calidad en su procesamiento, en la carpeta dejada a continuacion se puede ver todo el proceso completo de esta practica y que se hizo paso a paso:

-[`practica_1A/`](practica1/practica_1A/)



### Practica 1_B
Para esta practica el objetivo es familiarizarse con los elementos de medición tales como el osciloscopio, analizador de espectros y el radio, lo que se propone es la comprensión de como el computador se comunica con el radiose analiza las caracteristicas de cada equipo de medición , tambien familiarizarse que pueden o que capacidad se alcanza el analizador de espectros y el osciloscopio, tomamos como referencia del manual de ususario de cada elemento las caracteristicas como que el analizador de espectros puede analizar desde un rango de frecuencia de 5Khz a 1Ghz, que este quipo por si solo tiene cierto ruido como se evidencia en las imagenes y medimos estos valores de tolerancia, la forma que tenia el ruido en el analizador de espectros, tambien como el radio tiene su propio ruido de interferencia(se aclara que tuvimos un equipo un poco defectuoso ya que al momento de tomar los valores de tolerancia del equipo al conectarse al osciloscopio se aprecia un ruido en la señal y no se vé bien definida como se evidencia en la primera imagen.
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_practica1_Alab/WhatsApp%20Image%202025-03-03%20at%2012.12.05%20AM.jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_b_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM%20(1).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_b_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM%20(2).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_b_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM.jpeg)
Como se evidencia anteriormente por medio del osciloscopio podemos evidenciar de mejor manera las componentes de la señal tales como frecuencia, amplitud, como esta cambia su forma gracias al ruido y empezar a jugar con los parametros por medio de la configuración de GNURADIO, como dice el profesor en clase :"es importante saber manejar los equipos ya que son nuestros ojos", cabe aclarar que el osciloscopio es nuestros ojos para tomar mediciones en tiempo , el analizador de espectros son nuestros ojos para analizar en el area de la frecuencia, como sucede la convolución, que pasa cuando agregamos ruido y de mas.

### Practica 1_C
Para esta practica mayoritariamente usamos el analizador de espectros, ya que por medio de la aplicación de GNURADIO caracterizamos una señal por medio del radio, le asignamos valores y comenzamos a ajustar las mediciones del analizador de espectros para ver la forma de la señal en el area de la frecuencia como se ve acontinuación, le asignamos valores de offset y ruido para poder evidenciar que en el dominio de la frecuancia estos parametros lo que me hacen es o modificar su amplitud o desplazar el espectro en frecuancia
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_practica1_Alab/WhatsApp%20Image%202025-03-03%20at%2012.12.05%20AM%20(6).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_practica1_Alab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM%20(4).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_practica1_Alab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM%20(3).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_practica1_Alab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM%20(2).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_practica1_Alab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM%20(1).jpeg)

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_practica1_Alab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM.jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM%20(1).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM%20(2).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.06%20AM.jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(1).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(10).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(11).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(2).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(3).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(4).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(5).jpeg)
Para esta parte de la practica se nos solicita por medio de la antena sintonizar una señal de radio para poder visualizar la forma del espectro que contiene cada señal de estación de radio y en que ancho de banda operan para poder sintonizarla, como se muestra en las miganes adaptamos las mediciones para seleccionar una estación de radio y ver de manera grafica como es su forma de espectro, cabe aclarar que las estaciones de radio FM se sintonizan en un rango de 80Khz y 110 Khz, a su vez sintonizamos la emisora de la uis y la dejamos en su ancho de banda, pudimos ver como tenia ruido a medida que moviamos la antena.
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(6).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(7).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(8).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM%20(9).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/practica1/practica1/imagenes_1_C_lab/WhatsApp%20Image%202025-03-03%20at%2012.12.07%20AM.jpeg)


### Conclusiones
- Las mediciones de señales son fundamentales para comprender cómo las señales de comunicación se propagan a través de diversos entornos. El uso de herramientas como el osciloscopio y el analizador de espectros permite obtener información precisa sobre características clave como la amplitud, la frecuencia, el ancho de banda y la potencia de la señal.
- Existen varios modelos para estimar las pérdidas de trayectoria (pathloss) en un canal inalámbrico, cada uno adecuado para diferentes escenarios. El modelo de propagación en espacio libre es sencillo y útil en condiciones ideales sin obstáculos, pero en entornos más complejos, como áreas urbanas o interiores, modelos como el de Hata o el modelo log-normal ofrecen estimaciones más precisas al considerar la interferencia de obstáculos y las características específicas del entorno.
- La potencia de la señal tiene una relación directa con la calidad de la comunicación.
- os parámetros de la fuente, como la frecuencia y la amplitud, tienen un impacto directo en la señal transmitida.
- ara obtener mediciones más precisas en entornos con alto nivel de ruido, es crucial utilizar técnicas y equipos que ayuden a reducir la interferencia y a mejorar la relación señal-ruido.
- El osciloscopio son nuestros ojos en el dominio del tiempo y el analizador de espectros son nuestros ojos en el dominio de la frecuencia.
- Todo equipo de medición tiene cierto valor de tolerancia ya que no todo es perfecto, por ende debemos tener en cuenta los margenes establecidos por el fabricante.

### Referencias

- [Ettus Research USRP 2920 ManualEttus Research, "USRP 2920 User Manual," [Enlace], disponible en: https://www.ettus.com/all-products/usrp-2920/
- Ettus Research, "USRP 2920 User Manual," [Enlace], disponible en: https://www.ettus.com/all-products/usrp-2920/
- GNU Radio DocumentationGNU Radio, "GNU Radio Documentation," [Enlace], disponible en: https://gnuradio.org/documentation/
- Ettus Research WikiEttus Research, "Ettus Research Wiki," [Enlace], disponible en: https://kb.ettus.com/Main_Page
- T. S. Rappaport, Wireless Communications: Principles and Practice, 2nd ed. Upper Saddle River, NJ, USA: Prentice-Hall, 2002.
- A. Goldsmith, Wireless Communications, 1st ed. Cambridge, UK: Cambridge University Press, 2005.
- H. L. Van Trees, Optimum Array Processing, 1st ed. New York, NY, USA: Wiley, 2002.
- J. G. Proakis, Digital Communications, 5th ed. New York, NY, USA: McGraw-Hill, 2007.
- M. K. Simon, S. M. Hinedi, and W. C. Lindsey, Digital Communication Techniques: Signal Design and Detection, 1st ed. Englewood Cliffs, NJ, USA: Prentice-Hall, 1995.
- T. S. Rappaport, Wireless Communications: Principles and Practice, 2nd ed. Upper Saddle River, NJ, USA: Prentice Hall, 2002.
- M. Okumura, T. Ohmori, T. Kawano, and K. Fukuda, "Field strength and its variability in VHF and UHF land-mobile radio service," Review of the Electrical Communications Laboratory, vol. 16, no. 9, pp. 825–873, 1968.
- Hata, M., "Empirical formula for propagation loss in land mobile radio services," IEEE Transactions on Vehicular Technology, vol. 29, no. 3, pp. 317-325, Aug. 1980.
- M. P. Hata, "A generalized model for propagation loss in urban areas," IEEE Transactions on Communications, vol. 29, pp. 730–735, 1981.
- A. J. Viterbi and J. K. Omura, Principles of Digital Communication and Coding, 1st ed. New York, NY, USA: McGraw-Hill, 1979.





---




## Creación de Tablas

**Tabla 1.** Ejemplo de tabla en Markdown.

| Parámetro | Valor |
|-----------|-------|
| Frecuencia (Hz) | 1000 |
| Amplitud (V) | 5 |
| Ciclo útil (%) | 50 |



Volver al [INICIO](#laboratorio-de-comunicaciones)
