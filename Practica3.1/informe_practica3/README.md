# Laboratorio de Comunicaciones
## Universidad Industrial de Santander

---
# Práctica 2A: Modelo de canal

### Integrantes
- **SANTIAGO HERNANDO POSADA BAYONA** - 2190428
- **NICOLAS ROJAS REYES** - 2210402

Escuela de Ingenierías Eléctrica, Electrónica y de Telecomunicaciones  
Universidad Industrial de Santander

### Fecha
21 de marzo de 2025

---

## Declaración de Originalidad y Responsabilidad
Los autores de este informe certifican que el contenido aquí presentado es original y ha sido elaborado de manera independiente. Se han utilizado fuentes externas únicamente como referencia y han sido debidamente citadas.

Asimismo, los autores asumen plena responsabilidad por la información contenida en este documento. 

Uso de IA: [mencionamos el uso de IA para corroborar la redacción, corroborar que sean correctas las referencias y que esten bien mencionadas en el documento, tambien la usamos para aclarar ciertas falencias teoricas y corroborar caracteristicas de los equipos usados en el laboratorio.]

---
## Contenido

### Resumen
Para el presente laboratorio, se utiliza GNU Radio para simular un canal de comunicación, se configura filtros y se analiza los efectos de la variación de las frecuencias de corte sobre la señal, además, se evalúa el impacto del ruido en las señales en el dominio del tiempo y la frecuencia, se realiza un análisis gráfico para identificar el umbral de ruido máximo que permitía recuperar una señal utilizando únicamente el filtrado,se trabaja con el USRP 2920 ,un osciloscopio y un analizador de espectros para observar cómo un canal alámbrico real afecta la transmisión de señales. Se transmite señales a través de cables coaxiales de diferentes longitudes y se varía las frecuencias de portadora, por parte Se analiza cómo el ruido y la desviación de frecuencia impactan la amplitud de la señal y se discutieron posibles métodos para mejorar la relación señal-ruido.

**Palabras clave:** 
RUIDO,
DESFACE,
ESPECTRO,
COMUNICACIÓN,
ANTENAS.

### Introducción
- PRACTICA 2A:
- ACTIVIDAD 1:
- ¿Cuál es el efecto de filtrar las frecuencias altas de una señal?:Filtrar las frecuencias altas de una señal tiene como resultado la atenuación o eliminación de las componentes de mayor frecuencia, lo que puede hacer que la señal se vuelva más suave y libre de ruidos o interferencias no deseadas. Sin embargo, este proceso también puede causar la pérdida de detalles importantes de la señal, especialmente si esas frecuencias altas contienen información relevante.

- ¿Qué sucede al filtrar muy cerca de la frecuencia fundamental de la señal?:Filtrar demasiado cerca de la frecuencia fundamental de la señal puede afectar significativamente su forma y calidad. Al hacerlo, se corre el riesgo de atenuar componentes importantes de la señal, lo que podría distorsionarla o incluso eliminar parte de la información esencial. Esto puede reducir la claridad o precisión de la señal, afectando su interpretación o transmisión.
- ¿Cuál es el efecto de filtrar las frecuencias bajas de una señal?:Filtrar las frecuencias bajas de una señal resulta en la eliminación o atenuación de las componentes de baja frecuencia, lo que puede hacer que la señal se vuelva más nítida al reducir el ruido o las variaciones lentas no deseadas. Sin embargo, esto también puede eliminar partes importantes de la señal si esas frecuencias bajas contienen información clave para su correcta interpretación.

- ¿Qué ocurre al eliminar armónicos de una señal?:Eliminar los armónicos de una señal puede hacer que pierda parte de su estructura original, alterando su forma y carácter. Los armónicos son componentes importantes que le dan a la señal su tono y riqueza, por lo que al eliminarlos, la señal puede volverse más simple o distorsionada, perdiendo información relevante o causando una percepción menos precisa de la señal original.
- ¿Qué efecto tiene la reducción de frecuencia en la señal recibida? ¿Qué efecto(s) produce el filtro cuando la señal recibida se ve afectada por la desviación de frecuencia?:La reducción de frecuencia en la señal recibida puede hacer que la señal se vuelva más susceptible a la distorsión, ya que al reducir la frecuencia, es posible que se pierdan detalles importantes de la señal original. Esto puede afectar su calidad y dificultar la correcta interpretación de la información.
Cuando la señal recibida está afectada por la desviación de frecuencia, el filtro puede ayudar a minimizar la distorsión al eliminar o suavizar las variaciones no deseadas en la frecuencia. Sin embargo, si la desviación es significativa, el filtro podría no ser suficiente para recuperar completamente la señal original, lo que podría generar una pérdida de calidad o de información.
- ¿Cómo cuantificar la degradación de la señal al aumentar los niveles de ruido?:La degradación de la señal al aumentar los niveles de ruido se puede cuantificar observando cómo varía la relación señal a ruido (SNR). A medida que el ruido aumenta, la SNR disminuye, lo que indica una mayor interferencia en la señal. También se pueden usar métricas como el error de bit (BER) en señales digitales o el nivel de distorsión en señales analógicas, para medir el impacto del ruido sobre la calidad de la señal. Un aumento en el ruido suele resultar en una pérdida de claridad, lo que se refleja en una mayor dificultad para recuperar la señal original.
- ¿Cómo se puede mejorar la relación señal a ruido en una señal?:Para mejorar la relación señal a ruido en una señal, se pueden emplear varias técnicas. Una opción es aumentar la potencia de la señal transmitida, lo que ayuda a que la señal sea más fuerte en comparación con el ruido. Otra estrategia es utilizar filtros para eliminar las frecuencias no deseadas que contribuyen al ruido. Además, se pueden usar técnicas de modulación y codificación más eficientes que hagan la señal más resistente a las interferencias. También es útil minimizar las fuentes de ruido en el entorno de transmisión, como el uso de cables de buena calidad o la reducción de la distancia entre el transmisor y el receptor.
- ¿Cómo podría cuantificar la calidad de la señal recibida? Considere el caso de señales analógicas y digitales:La calidad de la señal recibida se puede cuantificar de diferentes maneras según el tipo de señal. En el caso de señales analógicas, una forma común es medir la distorsión armónica total (THD) o el error cuadrático medio (MSE), que indican cuánto se ha desviado la señal recibida respecto a la original. También se puede observar la relación señal a ruido (SNR) para ver qué tan clara es la señal en comparación con el ruido presente.
Para señales digitales, se puede utilizar el porcentaje de error de bit (BER), que mide la cantidad de bits erróneos recibidos en comparación con los bits transmitidos. Además, la tasa de símbolos erróneos (SER) también es útil para evaluar la calidad en términos de símbolos transmitidos. En ambos casos, una mayor SNR o menor BER/SER generalmente indica una mejor calidad de la señal recibida.
- ACTIVIDAD 2:

- ¿Cuál es el efecto del ruido sobre la amplitud de las señales medidas en el osciloscopio? ¿Conservan las mismas relaciones que se evidencian en la simulación?:El ruido sobre la amplitud de las señales medidas en el osciloscopio puede causar variaciones y fluctuaciones en la forma de onda observada, lo que hace que la señal aparezca más distorsionada. Estas fluctuaciones pueden afectar la precisión de la medición de la amplitud, causando que los valores observados sean menos estables y más ruidosos.Se evidencian ciertas fluctuaciones respecto a la simulación ya que al ser ideal la simualción obtenemos los valores exactos,en el osciloscopio tiene un poco mas de ruido ya que esto me puede afectar por el canal, la calidad del cable,temperatura, etc.

- ¿La relación señal a ruido creada intencionalmente en el computador se amplifica o se reduce en la señal observada en el osciloscopio?:La relación señal a ruido creada intencionalmente en el computador generalmente se amplifica en la señal observada en el osciloscopio. Esto se debe a que el ruido presente en el ambiente real puede sumarse al ruido intencional generado en el computador, lo que aumenta la interferencia total en la señal medida. Como resultado, la relación señal a ruido en la señal observada en el osciloscopio suele ser menor que la calculada en la simulación del computador, ya que el ruido adicional de factores externos afecta la calidad de la señal recibida.

- Demuestre ¿cómo se puede mejorar la relación señal a ruido en una señal?:Una forma de mejorar la relación señal a ruido es aumentar la potencia de la señal, lo que hace que sea más dominante frente al ruido presente. También se pueden aplicar filtros para eliminar las frecuencias no deseadas que contribuyen al ruido. Utilizar técnicas de modulación y codificación más robustas, que permitan recuperar mejor la señal a pesar de las interferencias, es otra estrategia efectiva. Además, reducir las fuentes de ruido en el entorno de transmisión, como mejorar los cables o disminuir la distancia entre el transmisor y el receptor, también ayuda a obtener una mejor relación señal a ruido.

- ¿Cómo se evidencia el fenómeno de desviación de frecuencia en el osciloscopio? Evidenciar al menos con dos formas de onda.:en el caso del osciloscopio al nosotros desviar la frecuencia obtenemos una modificación en la amplitud o un ensanchamiento o estrechamiento de la señal dependiendo de que valor le estemos modificando.
  
- Usando cables coaxiales de diferentes longitudes, ¿cómo afecta la distancia entre el transmisor y el receptor a la amplitud de la señal medida?afecta en gran medida ya que al estar mas lejos o mas cerca la potencia de la señal transmitida es menor en el caso de los cables largos o es mayor cuando el cable es corto, esto me afecta en la calidad de la señal, el ruido generado por el medio.
- Usando antenas, ¿cómo afecta la distancia entre el transmisor y el receptor a la amplitud de la señal medida? ¿Es posible compensar el fenómeno?:afecta de la misma manera que con los cables coaxiales, entre mas lejos perdemos la señal o es mas tenue y susectible a interferencias generadas por ruido de señales parasitas, cuando esta mas cerca la recepción es mucho mayor, para mitigar este fenomeno de perdida por distancia podriamos generar un amplificador de la señal o un repetidor cada cierta distancia o en el receptor construirlo con una tolerancia de recepción bastante baja y que tenga una ganancia de amplificación bastante alta para así no tener perdidas en la transmisión.
- ¿Qué modelo de canal básico describe mejor las mediciones obtenidas en la práctica?: seria un modelo acoplado a la practica el Canal AWGN ya que al nosotros modificar varios parametros de la misma y cambiar la medida de los cables estamos modificando el entorno de transmisión , por lo cual es suseptible a mucho ruido y al tener este tipo de modelo básico tenemos en consideración estas adiciones de ruido al sistema.

- ACTIVIDAD 3:
- ¿Cuál es el efecto del ruido sobre la respuesta en frecuencia de las señales medidas en el analizador de espectro? ¿Conservan las mismas relaciones que se evidencian en la simulación?puede generar distorsiones que afectan la claridad de las frecuencias presentes en la señal. Esto puede resultar en un ensanchamiento de los picos de frecuencia, haciendo que sea más difícil distinguir las frecuencias individuales y aumentando la amplitud de las componentes no deseadas. Como consecuencia, la respuesta espectral de la señal se vuelve menos precisa, mostrando una dispersión que puede ocultar detalles importantes sobre la señal original.Respecto a si se mantiene lo que tenemos en la señal del simulador respecto a la medida en el analizador varia un poco ya que adquiere un poco de ruido al tener conexiones fisicas, en comparación a la simulación que no tiene estas afectaciónes.
- ¿La relación señal a ruido creada intencionalmente desde el computador se amplifica o se reduce en la señal observada en el analizador de espectro?:La relación señal a ruido creada intencionalmente en el computador generalmente se reduce en la señal observada en el analizador de espectro. Esto se debe a que, además del ruido generado en la simulación, pueden influir otros factores externos, como el ruido ambiental o el ruido adicional introducido por el equipo de medición. Estos factores externos suelen aumentar el nivel de interferencia, lo que disminuye la relación señal a ruido observada en el analizador en comparación con la simulada en el computador.
- ¿Cómo se evidencia el fenómeno de desviación de frecuencia en el analizador de espectro? Evidenciar al menos con dos formas de onda: se evidencia un desplazamiento de manera de espectro de frecuencia para la derecha o izquierda según el valor que le demos para el desplazamiento.
- Usando cables coaxiales de diferentes longitudes, ¿cómo afecta la distancia entre el transmisor y el receptor a la amplitud de la señal medida? afecta de la misma manera que la anterior medida en el osciloscopio me puede disminuir la amplitud cuando está demasiado lejos y aumenta la amplitud cuando esta bastante cerca, gracias a la perdida de potencia por el medio que es el cable, tambien al tener un cable mas largo me genera bastante ruido en el espectro, esto causado por la calidad del cable, calibre que este tenga en su interior y por supuesto la longitud.
- Usando antenas, ¿cómo afecta la distancia entre el transmisor y el receptor a la amplitud de la señal medida? ¿Es posible compensar el fenómeno?afecta de la misma manera que con los cables coaxiales, entre mas lejos perdemos la señal o es mas tenue y susectible a interferencias generadas por ruido de señales parasitas, cuando esta mas cerca la recepción es mucho mayor, para mitigar este fenomeno de perdida por distancia podriamos generar un amplificador de la señal o un repetidor cada cierta distancia o en el receptor construirlo con una tolerancia de recepción bastante baja y que tenga una ganancia de amplificación bastante alta para así no tener perdidas en la transmisión.
- ¿Qué modelo de canal básico describe mejor las mediciones obtenidas en la práctica?:seria un modelo acoplado a la practica el Canal AWGN como en el literal anterior ya que estamos teniendo un sistema de comunicación bastante basico, lo cual nos sirve ya que vamos a introducir ruido, cambios en la amplitud, filtrar la señal y de mas fenomenos que debemos tener en cuenta al momento de hacer las mediciones.
  
- ACTIVIDAD 4:
- ¿Cómo se evidencian los diferentes fenómenos de canal en la señal recibida?:en la practica realizamos las mediciones con dos tipologias de señal,tipo sierra y tipo triangular,para el canal establecido coaxial al probar con ambos cables uno de 64 pies y otro de 4 pies aproximadamente, se evidencian la perdida de potencia por distancia, se evidencia un poco de ruido al transimitir por el cable en sus diferentes longitudes,a diferencia de la transimisión inhalambrica por las antenas que tienen un poco mas de ruido y que estas pierden bastante potencia a comparación del coaxial que al tener un cable de 64 pies sigue teniendo llegando mas potencia al receptor que las antenas a pocos metros de distancia del receptor.
- ¿Cómo se pueden mitigar los efectos del canal en la señal recibida?:para el tipo inhalambrico optaria por tener o repetidores cada cierta distancia o que el transmisor de radio tenga mas potencia para que el receptor le pueda llegar la señal a mas distancia,redireccionar las antenas lo mejor posible que se vean fijamente y evitar obstaculos para que su comunicación sea lo mas precisa posible, para la comunicación por el canal de coaxial, mejoraria el tipo de aislante o optaria por un calibre de material mas puro o 100% cobre para que no me genere tanto ruido o evitar perdidas por el tipo de material del cable, que el emisor envie la señal con mas potencia para que no se caiga tan rapido por la longitud del cable.


  

### Procedimiento
### Practica 2_A Actividad 1:
En la Práctica 1A, se llevaron a cabo diversas simulaciones en GNU Radio con el propósito de familiarizarse con su interfaz y funcionalidades. Durante la práctica, se modificaron parámetros como la frecuencia de muestreo, la frecuencia de la señal y el tipo de onda introducida, analizando la respuesta del sistema tras su paso por distintos bloques de procesamiento de señales tal y como se muestra a continuación:

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencia_pregunta_1/FiltradoAlto.png)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencia_pregunta_1/FiltradoBajas.png)

Posteriormente, se realizó un análisis comparativo entre el límite de Nyquist y una frecuencia de muestreo mayor, estableciendo una relación de muestreo de 5:1 para evaluar las ventajas de operar con frecuencias superiores al límite teórico. Para este análisis, se empleó al menos una señal distinta a la senoidal, permitiendo observar de manera práctica los efectos del muestreo sobre distintas formas de onda.

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencia_pregunta_1/Filtradofrecfundamental.png)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencia_pregunta_1/FrecuenciaDesviada.png)

A lo largo de la Práctica 1A, se logró una comprensión fundamental del entorno de GNU Radio, permitiendo la familiarización con su interfaz y la configuración de parámetros esenciales para el procesamiento de señales. Se experimentó con distintos valores de frecuencia de muestreo y frecuencia de la señal, así como con diferentes tipos de ondas, observando cómo cada ajuste impactaba en la señal procesada. Un aspecto clave fue la exploración del límite de Nyquist y la comparación con una frecuencia de muestreo mayor, demostrando la importancia de una correcta selección de la relación de muestreo para evitar efectos como el aliasing. A través de estos experimentos, se evidenció cómo una tasa de muestreo superior al límite de Nyquist permite una representación más fiel de la señal original, garantizando una mejor calidad en su procesamiento, en la carpeta dejada a continuacion se puede ver todo el proceso completo de esta practica y que se hizo paso a paso:

-[`GNURADIO_LABCOMUIS_2025_1_B1C_G1/`](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/tree/Practica2/practica_2A%20imagenes/punto1/evidencia_pregunta_1)



### Practica 2_A Actividad 2:
Para esta practica el objetivo es familiarizarse con los elementos de medición tales como el osciloscopio, analizador de espectros y el radio, lo que se propone es la comprensión de como el computador se comunica con el radio, se analiza las caracteristicas de cada equipo de medición , tambien que pueden hacer o que capacidad se alcanza el analizador de espectros y el osciloscopio, tomamos como referencia del manual de ususario de cada elemento las caracteristicas como que el analizador de espectros puede analizar desde un rango de frecuencia de 5Khz a 1Ghz, que este quipo por si solo tiene cierto ruido como se evidencia en las imagenes y medimos estos valores de tolerancia, la forma que tenia el ruido en el analizador de espectros, tambien como el radio tiene su propio ruido de interferencia(se aclara que tuvimos un equipo un poco defectuoso ya que al momento de tomar los valores de tolerancia del equipo al conectarse al osciloscopio se aprecia un ruido en la señal y no se vé bien definida como se evidencia en la primera imagen.

En la primera parte de esta actividad realizamos unas mediciones de amplitud en el osciloscopio con una señal generada gracias a GNU RADIO, como se puede evidenciar en la siguiente conexion
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/Evidencia%20actividad%202/Imagen%20de%20WhatsApp%202025-03-04%20a%20las%2019.28.33_d8186ebf.jpg)
Y con este se fueron variando los parametros de ganancia GTX a diferentes frecuencias, en lo cual se obtuvo lo siguiente:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/Evidencia%20actividad%202/Imagen%20de%20WhatsApp%202025-03-04%20a%20las%2019.28.33_f5c0e0d2.jpg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/Evidencia%20actividad%202/Imagen%20de%20WhatsApp%202025-03-04%20a%20las%2019.30.12_6fe1abdd.jpg)
Con este se lograron medir los siguientes datos:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/Evidencia%20actividad%202/Imagen%20de%20WhatsApp%202025-03-04%20a%20las%2019.30.12_9b401d5c.jpg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/Evidencia%20actividad%202/Imagen%20de%20WhatsApp%202025-03-04%20a%20las%2019.31.08_8574c24b.jpg)

Y para la segunda parte de esta practica se exploro que medida de atenuacion se tiene cuando se somete esta señal a un cable coaxial, que en el caso que se estudio, este tiene una medida de 64 pies o de 19,50 metros. 

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/Evidencia%20actividad%202/Imagen%20de%20WhatsApp%202025-03-04%20a%20las%2019.31.32_b7d03f8a.jpg)

Luego de esto se procede a tomar los datos en el analizador de espectro para analizar que atenuacion tiene un cable coaxial, en la cual se obtienen los siguientes datos para un cable coaxial de una longitud de 19.50 metros.

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/Evidencia%20actividad%202/Imagen%20de%20WhatsApp%202025-03-04%20a%20las%2019.41.19_d4a6add1.jpg)

Como se evidencia anteriormente por medio del osciloscopio y analizador de espectros podemos evidenciar de mejor manera las componentes de la señal tales como frecuencia, amplitud, como esta cambia su forma gracias al ruido y empezar a jugar con los parametros por medio de la configuración de GNURADIO, como dice el profesor en clase :"es importante saber manejar los equipos ya que son nuestros ojos", cabe aclarar que el osciloscopio es nuestros ojos para tomar mediciones en tiempo , el analizador de espectros son nuestros ojos para analizar en el area de la frecuencia, como sucede la convolución, que pasa cuando agregamos ruido y demas.

Se puede ver toda la evidencia en la siguiente ruta:
-[`GNURADIO_LABCOMUIS_2025_1_B1C_G1/`](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/tree/Practica2/practica_2A%20imagenes/punto1/Evidencia%20actividad%202)

### Practica 2_A Actividad 3:
Para esta practica mayoritariamente usamos el analizador de espectros, ya que por medio de la aplicación de GNURADIO caracterizamos una señal por medio del radio, le asignamos valores y comenzamos a ajustar las mediciones del analizador de espectros para ver la forma de la señal en el area de la frecuencia como se ve acontinuación, le asignamos valores de offset y ruido para poder evidenciar que en el dominio de la frecuancia estos parametros lo que me hacen es o modificar su amplitud o desplazar el espectro en frecuencia

A continuacion un poco de los parametros que se midieron como las mediciones verticales y horizontales, la resolucion de la pantalla, etc. de cada uno de los equipos.
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencias_Actividad_3/WhatsApp%20Image%202025-03-21%20at%201.42.28%20PM%20(1).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencias_Actividad_3/WhatsApp%20Image%202025-03-21%20at%201.42.28%20PM%20(2).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencias_Actividad_3/WhatsApp%20Image%202025-03-21%20at%201.42.28%20PM%20(3).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencias_Actividad_3/WhatsApp%20Image%202025-03-21%20at%201.42.28%20PM%20(4).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencias_Actividad_3/WhatsApp%20Image%202025-03-21%20at%201.42.28%20PM%20(5).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencias_Actividad_3/WhatsApp%20Image%202025-03-21%20at%201.42.28%20PM.jpeg)
Se puede ver toda la evidencia en la siguiente ruta:
-[`GNURADIO_LABCOMUIS_2025_1_B1C_G1/`](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/tree/Practica2/practica_2A%20imagenes/punto1/evidencias_Actividad_3)
### Practica 2_A Actividad 4:
Se puede ver toda la evidencia en la siguiente ruta:

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencias_actividad_4/WhatsApp%20Image%202025-03-21%20at%201.46.44%20PM%20(1).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencias_actividad_4/WhatsApp%20Image%202025-03-21%20at%201.46.44%20PM.jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencias_actividad_4/WhatsApp%20Image%202025-03-21%20at%201.46.45%20PM%20(1).jpeg)
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica2/practica_2A%20imagenes/punto1/evidencias_actividad_4/WhatsApp%20Image%202025-03-21%20at%201.46.45%20PM%20(2).jpeg)

-[`GNURADIO_LABCOMUIS_2025_1_B1C_G1/`](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/tree/Practica2/practica_2A%20imagenes/punto1/evidencias_actividad_4)

### Conclusiones
- Efecto de la distancia y el medio de transmisión en la señal: La distancia entre el transmisor y el receptor, ya sea usando cables coaxiales o antenas, afecta directamente la calidad de la señal. A medida que aumenta la distancia, ya sea con cables largos o antenas, la señal pierde potencia y se vuelve más susceptible a interferencias. Esto puede mitigarse utilizando amplificadores de señal o repetidores para reforzar la transmisión.
- Influencia del ruido en la señal: El ruido tiene un impacto significativo tanto en la forma de la señal como en su espectro. En el dominio del tiempo, provoca variaciones en la amplitud, mientras que en el dominio de la frecuencia genera distorsiones que dificultan la identificación de las frecuencias originales. La relación señal-ruido medida en un entorno real suele ser peor que en la simulación, ya que factores como el ruido ambiental o la interferencia del equipo afectan la señal.
- Papel de los filtros en la mejora de la señal: Los filtros son esenciales para mejorar la calidad de la señal al eliminar las frecuencias no deseadas que generan ruido. Sin embargo, es importante tener cuidado al ajustar las frecuencias de corte, ya que filtrar demasiado cerca de la frecuencia principal o eliminar armónicos importantes puede alterar la señal y reducir su precisión.
- Modelos de canal y su relación con las mediciones: El modelo AWGN (ruido blanco gaussiano aditivo) es el más adecuado para describir las mediciones realizadas en este laboratorio, ya que refleja de manera precisa los efectos del ruido y las pérdidas de señal que se producen en un canal de comunicación simple. Este modelo ayuda a entender cómo el ruido y la atenuación afectan la transmisión de señales en condiciones reales.
- Mejoras en la relación señal-ruido (SNR): Para optimizar la relación señal-ruido, es recomendable aumentar la potencia de la señal transmitida, usar técnicas de modulación y codificación más eficaces, aplicar filtros que eliminen las frecuencias indeseadas y reducir las fuentes de ruido en el entorno. Estas acciones son cruciales tanto en canales alámbricos como inalámbricos para asegurar una transmisión más clara y eficiente.

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



Volver al [INICIO](#laboratorio-de-comunicaciones)
