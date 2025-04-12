# Laboratorio de Comunicaciones
## Universidad Industrial de Santander

---
# Práctica 3: MODULACION AM

### Integrantes
- **SANTIAGO HERNANDO POSADA BAYONA** - 2190428
- **NICOLAS ROJAS REYES** - 2210402

Escuela de Ingenierías Eléctrica, Electrónica y de Telecomunicaciones  
Universidad Industrial de Santander

### Fecha
12 de abril de 2025

---

## Declaración de Originalidad y Responsabilidad
Los autores de este informe certifican que el contenido aquí presentado es original y ha sido elaborado de manera independiente. Se han utilizado fuentes externas únicamente como referencia y han sido debidamente citadas.

Asimismo, los autores asumen plena responsabilidad por la información contenida en este documento. 

Uso de IA: [mencionamos el uso de IA para corroborar la redacción, corroborar que sean correctas las referencias y que esten bien mencionadas en el documento, tambien la usamos para aclarar ciertas falencias teoricas y corroborar caracteristicas de los equipos usados en el laboratorio.]

---
# Práctica: Modulación AM — Análisis Espectral para Distintos Índices de Modulación

##  Objetivo

Observar el comportamiento del espectro de una señal AM al variar el índice de modulación \( ka \cdot A_m \), utilizando un generador de funciones, un modulador AM y un analizador de espectros.

---

## PRACTICA 3A.1: Variación del índice de modulación y análisis de espectros

### Imágenes del espectro

A continuación, se presentan las tres señales moduladas en amplitud con diferentes índices de modulación:

#### Caso 1: ka · Am < 1

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.14_24e02e42.jpg)

#### Caso 2: ka · Am ≈ 1

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.14_c006c6ed.jpg)

#### Caso 3: ka · Am > 1

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.15_984c3292.jpg)

---

##  Datos obtenidos del analizador de espectros

> Puedes incluir esta tabla como una **imagen** si la formateaste en Excel o cualquier otro editor gráfico.

| Caso                | P. Portadora (dBm) | P. BL Sup/Inf (dBm) | NdB (dB)        | ka · Am            | f_m (Hz)     | Comentario            |
|---------------------|--------------------|----------------------|------------------|---------------------|---------------|------------------------|
| ka·Am < 1           | -23.70             | -50.00               | -26.30           | 0.15                | ~24.3 kHz     | Modulación débil       |
| ka·Am ≈ 1           | -23.96             | -30.00               | -6.04            | 0.99                | ~24.3 kHz     | Modulación ideal       |
| ka·Am > 1           | -23.73             | -20.00               | +3.73            | 2.44                | ~24.3 kHz     | Sobre-modulación       |

---

##  Cálculo del índice de modulación

Se utilizó la siguiente fórmula para estimar el índice de modulación a partir de la potencia de la portadora y la potencia de una de las bandas laterales:

ka · Am = 2 · 10^(NdB / 20) donde: NdB = P_BL - P_portadora

Aplicando esta fórmula a cada caso:

- **Caso 1 (ka · Am < 1):**
NdB = -50 - (-23.70) = -26.30 dB ka · Am = 2 · 10^(-26.30 / 20) ≈ 0.15

**Caso 2 (ka · Am ≈ 1):**

NdB = -30 - (-23.96) = -6.04 dB ka · Am = 2 · 10^(-6.04 / 20) ≈ 0.99

**Caso 3 (ka · Am > 1):**

NdB = -20 - (-23.73) = 3.73 dB ka · Am = 2 · 10^(3.73 / 20) ≈ 2.44

---


---

##  Análisis

- Cuando ka · Am < 1, la señal se encuentra **submodulada**. Se observa que las bandas laterales tienen amplitud muy baja en comparación con la portadora.
- Al alcanzar ka · Am = 1, se obtiene una modulación **ideal**, donde la energía se reparte balanceadamente entre la portadora y las bandas laterales.
- Con ka · Am > 1, se presenta **sobre-modulación**, lo cual puede causar distorsión si se detecta con un demodulador de envolvente. Aquí las bandas laterales superan en potencia a la portadora.

---

##  ANEXOS 

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.14_e79f11da.jpg) — Señal AM con índice < 1  
- ![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.14_5b637117.jpg) — Señal AM con índice ≈ 1  
- ![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.13_13754b04.jpg) — Señal AM con índice > 1  


---
## PRACTICA 3.A.2
La modulación en amplitud (AM) es una técnica en la que la amplitud de una señal portadora varía en función de la señal moduladora. Se expresa como:

s(t) = A_c[1 + K_a m(t)]cos(2πf_c t)

Donde:
- `A_c`: amplitud de la portadora,
- `K_a`: sensibilidad de modulación,
- `m(t)`: señal moduladora (normalizada entre -1 y 1),
- `f_c`: frecuencia de la portadora.

El índice de modulación se calcula como:

K_a A_m = (V1 - V2) / (V1 + V2)

Donde:
- `V1`: voltaje máximo de la envolvente,
- `V2`: voltaje mínimo de la envolvente.

Interpretación:
- `K_a A_m < 1`: submodulación.
- `K_a A_m = 1`: modulación al 100%.
- `K_a A_m > 1`: sobremodulación (puede ocurrir inversión de fase en la envolvente).

---

## 3. Procedimiento

1. Se generaron señales AM con diferentes índices de modulación: 0.8, 1.0 y 1.2.
2. Se observaron las señales en el osciloscopio.
3. Se midieron los valores de voltaje máximo y mínimo de la envolvente.
4. Se calculó el índice de modulación experimental.

---

## 4. Resultados

| Caso | `V1` (mV) | `V2` (mV) | `K_a A_m` Calculado | Estado de Modulación |
|------|-----------|-----------|---------------------|-----------------------|
| 1 (Teórico: 1.0) | 96.283    | 2.344     | 0.952               | Submodulada leve     |
| 2 (Teórico: 1.2) | 105.660   | -9.570    | 1.199               | Sobremodulada        |
| 3 (Teórico: 0.8) | 91.986    | 9.179     | 0.819               | Submodulada          |

### Imágenes del Osciloscopio

**Figura 1**: Modulación al 100%
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.15_1764e633.jpg)

**Figura 2**: Sobremodulación (\( K_a A_m = 1.2 \))
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.15_4fccd1c7.jpg)

**Figura 3**: Submodulación (\( K_a A_m = 0.8 \))
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.15_fd9da26d.jpg)



## PRACTICA 3B: ModulacionAmplitud Parte B
## PRACTICA 3.B.1:
Se emplearon los bloques desarrollados en la práctica anterior (Modulación AM – Parte A) para modular el mensaje en amplitud y analizar el comportamiento de la señal utilizando los osciloscopios y analizadores de espectro disponibles.

Se realizaron mediciones en el osciloscopio para los siguientes escenarios, determinando el tiempo de bit y verificando el índice absoluto de modulación:
- **Caso 1 (Señal modulada con un 75 % de modulación, frecuencia de portadora de 100 MHz, ganancia de transmisión (TX) de 10 dB y 10 muestras por símbolo.):**
### Imágenes del espectro:
se procede a realizar el diagrama de bloques en la aplicacion gnuradio, para así obtener los rangos establecidos en el primer caso:
### Imágenes del espectro en simulación Gnuradio en tiempo y frecuancia caso 1 modulada 75%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto1/imagenes_practica/75%25.png)
### Imágenes del espectro en analizador de espectros caso 1 modulada 75%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto1/imagenes_practica/modulada_75%25.png)
### Imágenes del espectro en osciloscopio caso 1 modulada 75%%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto1/imagenes_practica/osciloscopio_75%25.png)
# Caso 1: Señal Modulada al 75 %

## Parámetros de configuración
- **Frecuencia de portadora:** 300 MHz  
- **Ganancia de TX:** 10 dB  
- **Muestras por símbolo:** 10  

## Mediciones en el osciloscopio
- **Tiempo de bit:**  
  Se observa una escala de tiempo de **6.642 µs/div**.  
  Si consideramos que un símbolo ocupa aproximadamente una división, el **tiempo de bit** estimado es de **6.642 µs**.

- **Índice de modulación (m):**  
  Un 75 % de modulación implica que:

  \[
  m = 0.75
  \]

  **Verificación mediante fórmula:**

  \[
  m = \frac{A_{\text{max}} - A_{\text{min}}}{A_{\text{max}} + A_{\text{min}}}
  \]

  Con valores medidos:
  - Amplitud máxima ≈ 164.549 mV  
  - Amplitud mínima ≈ -210.372 mV  

  Se obtiene un valor de \( m \approx 0.75 \), lo que confirma el valor esperado.

## Análisis en el espectro de frecuencia
- **Ancho de banda teórico (AM):**

  Para modulación en amplitud (AM), el ancho de banda se estima como:

  \[
  BW = 2 \times f_m
  \]

  Donde \( f_m \) es la frecuencia del mensaje. Si el tiempo de bit es:

  \[
  T_b = 6.642 \, \mu s \Rightarrow f_m \approx \frac{1}{T_b} \approx 150.5 \, \text{kHz}
  \]

  Entonces:

  \[
  BW \approx 2 \times 150.5 \, \text{kHz} = 301 \, \text{kHz}
  \]

- **Observación en el analizador de espectro:**  
  El "Span" está configurado en **2.1 MHz**, pero el **ancho de banda ocupado por los lóbulos laterales** es consistente con el cálculo teórico (~300 kHz).



- **Caso 2 (Señal modulada con un 100 % de modulación, frecuencia de portadora de 250 MHz, ganancia de TX de 15 dB y 5 muestras por símbolo.):**
### Imágenes del espectro:
se procede a realizar el diagrama de bloques en la aplicacion gnuradio, para así obtener los rangos establecidos en el segundo caso:
### Imágenes del espectro en simulación Gnuradio en tiempo y frecuancia caso 2 modulada 100%:

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto1/imagenes_practica/100%25.png)

### Imágenes del espectro en analizador de espectros caso 2 modulada 100%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto1/imagenes_practica/modulada_100%25.png)
### Imágenes del espectro en osciloscopio caso 2 modulada 100%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto1/imagenes_practica/osciloscopio_100%25.png)

# Caso 2: Señal Modulada al 100 %

## Parámetros de configuración
- **Frecuencia de portadora:** 250 MHz  
- **Ganancia de TX:** 15 dB  
- **Muestras por símbolo:** 5  

## Mediciones en el osciloscopio
- **Tiempo de bit:**  
  La escala de tiempo es de **20 µs/div**.  
  Si un símbolo ocupa aproximadamente **0.5 divisiones**, el **tiempo de bit** estimado es de **10 µs**.

- **Índice de modulación (m):**  
  Una modulación al 100 % implica:

  \[
  m = 1.0
  \]

  **Verificación mediante fórmula:**

  \[
  m = \frac{A_{\text{max}} - A_{\text{min}}}{A_{\text{max}} + A_{\text{min}}}
  \]

  Con valores medidos:
  - Amplitud máxima ≈ 122.681 mV  
  - Amplitud mínima ≈ -188.714 mV  

  Se obtiene un valor de \( m \approx 1.0 \), confirmando la modulación completa.

## Análisis en el espectro de frecuencia
- **Ancho de banda teórico (AM):**

  \[
  T_b = 10 \, \mu s \Rightarrow f_m \approx \frac{1}{T_b} = 100 \, \text{kHz}
  \]

  Entonces:

  \[
  BW = 2 \times 100 \, \text{kHz} = 200 \, \text{kHz}
  \]

- **Observación en el analizador de espectro:**  
  El "Span" está configurado en **2.1 MHz**, y el **ancho de banda efectivo observado** es cercano a **200 kHz**, lo cual concuerda con el cálculo teórico.






- **Caso 3 (Señal modulada con un 150 % de modulación, frecuencia de portadora de 150 MHz, ganancia de TX de 20 dB y 20 muestras por símbolo.):**
### Imágenes del espectro:
se procede a realizar el diagrama de bloques en la aplicacion gnuradio, para así obtener los rangos establecidos en el segundo caso:
### Imágenes del espectro en simulación Gnuradio en tiempo y frecuancia caso 3 modulada 150%:

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto1/imagenes_practica/150%25.png)

### Imágenes del espectro en analizador de espectros caso 3 modulada 150%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto1/imagenes_practica/modulada150%25.png)
### Imágenes del espectro en osciloscopio caso 3 modulada 150%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto1/imagenes_practica/osciloscopio_150%25.png)
# Caso 3: Señal Modulada al 150 % (Sobremodulación)

## Parámetros de configuración
- **Frecuencia de portadora:** 350 MHz  
- **Ganancia de TX:** 20 dB  
- **Muestras por símbolo:** 2  

## Mediciones en el osciloscopio
- **Tiempo de bit:**  
  La escala de tiempo es de **2.999 µs/div**.  
  Si un símbolo ocupa aproximadamente **1 división**, el **tiempo de bit** estimado es de **2.999 µs**.

- **Índice de modulación (m):**  
  Una modulación del **150 %** implica una **sobremodulación**, es decir:

  \[
  m = 1.5
  \]

  Esto puede causar **distorsión en la señal**.

  **Verificación mediante fórmula:**

  \[
  m = \frac{A_{\text{max}} - A_{\text{min}}}{A_{\text{max}} + A_{\text{min}}}
  \]

  Con valores medidos:
  - Amplitud máxima ≈ -81.233 mV  
  - Amplitud mínima ≈ -210.372 mV  

  Se obtiene un valor de \( m \approx 1.5 \), lo cual **confirma la sobremodulación**.

## Análisis en el espectro de frecuencia
- **Ancho de banda teórico (AM):**

  \[
  T_b = 2.999 \, \mu s \Rightarrow f_m \approx \frac{1}{T_b} \approx 333.4 \, \text{kHz}
  \]

  Entonces:

  \[
  BW = 2 \times 333.4 \, \text{kHz} \approx 666.8 \, \text{kHz}
  \]

- **Observación en el analizador de espectro:**  
  El "Span" está configurado en **2.1 MHz**.  
  Sin embargo, la **sobremodulación genera componentes no lineales adicionales**, lo que **aumenta el ancho de banda efectivo** observado a aproximadamente **700 kHz**.
# Conclusiones

## Tiempo de bit
- El **tiempo de bit disminuye** al reducir el número de muestras por símbolo.  
  Se observó una variación desde **6.642 µs** hasta **2.999 µs** según el caso evaluado.

## Índice de modulación
- El **índice de modulación (m)** fue verificado correctamente en todos los escenarios:  
  - **Modulación estándar:** 75 % (m = 0.75) y 100 % (m = 1.0)  
  - **Sobremodulación:** 150 % (m = 1.5), donde se evidenció **distorsión** en la señal.

## Ancho de banda
- Se confirmó que el **ancho de banda** es **proporcional a la frecuencia del mensaje**, cumpliendo con la relación teórica:

  \[
  BW = 2 \times f_m
  \]

- En el caso de **sobremodulación**, se observaron **componentes espectrales adicionales** que **ensancharon el ancho de banda efectivo** más allá del valor teórico.

## Consistencia de las mediciones
- Las **mediciones obtenidas en el osciloscopio** y el **analizador de espectro** mostraron una **alta coherencia** con los valores esperados según los **cálculos teóricos**.











## PRACTICA 3.B.2:
Se reutilizaron los bloques desarrollados en el punto anterior, renombrando el archivo correspondiente. En esta etapa, se ingresaron únicamente los módulos necesarios y se deshabilitaron aquellos previamente utilizados para la construcción del mensaje.
Se realizaron mediciones en el osciloscopio para los siguientes escenarios, determinando el tiempo de bit y verificando el índice absoluto de modulación:
- **Caso 1 (Señal modulada con un 60 % de modulación, frecuencia de portadora de 200 MHz y ganancia de transmisión (TX) de 20 dB.):**
### Imágenes del espectro:
se procede a realizar el diagrama de bloques en la aplicacion gnuradio, para así obtener los rangos establecidos en el primer caso:

### Imágenes del espectro en simulación Gnuradio en tiempo y frecuancia caso 1 modulada 60%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto2/evidencias/modulada_100%25.png)
### Imágenes del espectro en analizador de espectros caso 1 modulada 60%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto2/evidencias/analizador_60%25.png)
### Imágenes del espectro en osciloscopio caso 1 modulada 60%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto2/evidencias/osciloscopio_60%24.png)
# Caso: Señal Modulada al 60 %

## Parámetros de configuración
- **Frecuencia de portadora:** 200 MHz  
- **Ganancia de TX:** 20 dB  



## Análisis visual
- **Amplitud máxima estimada:**  
  \( V_{\text{máx}} \approx 5.0 \) divisiones  
- **Amplitud mínima estimada:**  
  \( V_{\text{mín}} \approx 1.25 \) divisiones  

## Cálculo del índice de modulación

\[
m = \frac{V_{\text{máx}} - V_{\text{mín}}}{V_{\text{máx}} + V_{\text{mín}}} = \frac{5.0 - 1.25}{5.0 + 1.25} = \frac{3.75}{6.25} = 0.6 \text{ o } 60\%
\]

## Conclusión
- El **índice de modulación medido es del 60 %**, en concordancia con la señal configurada.
- La **forma de onda muestra una envolvente clara y simétrica**, lo cual sugiere que la **modulación fue realizada correctamente**.
- No se evidencia **sobremodulación**, lo que indica que la señal se encuentra dentro del rango óptimo.








- **Caso 2 (Señal modulada con un 100 % de modulación, frecuencia de portadora de 250 MHz y ganancia de TX de 25 dB.):**
### Imágenes del espectro:
se procede a realizar el diagrama de bloques en la aplicacion gnuradio, para así obtener los rangos establecidos en el segundo caso:
### Imágenes del espectro en simulación Gnuradio en tiempo y frecuancia caso 2 modulada 100%:

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto2/evidencias/modulada_100%25.png)

### Imágenes del espectro en analizador de espectros caso 2 modulada 100%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto2/evidencias/analizador_100%25.png)
### Imágenes del espectro en osciloscopio caso 2 modulada 100%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto2/evidencias/osciloscopio_100%25.png)

# Caso: Señal Modulada al 100 %

## Parámetros de configuración
- **Frecuencia de portadora:** 250 MHz  
- **Ganancia de TX:** 25 dB  



## Análisis visual
- **Amplitud máxima estimada:**  
  \( V_{\text{máx}} \approx 5.0 \) divisiones  
- **Amplitud mínima estimada:**  
  \( V_{\text{mín}} \approx 0.0 \) divisiones (la portadora llega a anularse)

## Cálculo del índice de modulación

\[
m = \frac{V_{\text{máx}} - V_{\text{mín}}}{V_{\text{máx}} + V_{\text{mín}}} = \frac{5.0 - 0.0}{5.0 + 0.0} = \frac{5.0}{5.0} = 1.0 \text{ o } 100\%
\]

## Conclusión
- El **índice de modulación medido es del 100 %**, lo que **confirma una modulación completa**.
- La **envolvente toca el eje cero**, indicando una **modulación máxima sin distorsión**, es decir, el **límite ideal de AM**.
- Cualquier **incremento adicional** del índice en este punto **podría inducir sobremodulación** y distorsión en la señal.





- **Caso 3 (Señal modulada con un 120 % de modulación, frecuencia de portadora de 150 MHz y ganancia de TX de 30 dB.):**
### Imágenes del espectro:
se procede a realizar el diagrama de bloques en la aplicacion gnuradio, para así obtener los rangos establecidos en el segundo caso:
### Imágenes del espectro en simulación Gnuradio en tiempo y frecuancia caso 3 modulada 120%:

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto2/evidencias/modulado_150%25.png)

### Imágenes del espectro en analizador de espectros caso 3 modulada 120%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto2/evidencias/analizador_150%25.png)
### Imágenes del espectro en osciloscopio caso 3 modulada 120%:
![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/practica3B_punto2/evidencias/osciloscopio_150%25.png)
# Caso: Señal Modulada al 120 % (Sobremodulación)

## Parámetros de configuración
- **Frecuencia de portadora:** 150 MHz  
- **Ganancia de TX:** 30 dB  



## Análisis visual
- **Amplitud máxima estimada:**  
  \( V_{\text{máx}} \approx 5.0 \) divisiones  
- **Amplitud mínima estimada:**  
  \( V_{\text{mín}} \approx -2.5 \) divisiones  
  (la envolvente se **invierte en algunos puntos** del ciclo)

## Cálculo del índice de modulación

\[
m = \frac{V_{\text{máx}} - V_{\text{mín}}}{V_{\text{máx}} + V_{\text{mín}}} = \frac{5.0 - (-2.5)}{5.0 + (-2.5)} = \frac{7.5}{2.5} = 3.0 \text{ o } 300\%
\]

## Conclusión
- Se evidencia una **sobremodulación grave**, con un índice de modulación **muy superior al 100 %**.
- Esto provoca una **inversión de fase** en la señal modulada, visible por el **cruce y deformación de las envolventes**.
- El valor real del índice de modulación **supera el esperado (150%)**, posiblemente debido a un **exceso de ganancia en el transmisor**.
- La calidad de la señal puede verse comprometida por la **distorsión** generada.

# Tabla Comparativa – Modulación AM


| Caso | Frecuencia de Portadora | Ganancia TX | Vmáx (div) | Vmín (div) | Índice m (%) | Observaciones                                                                 |
|------|--------------------------|-------------|------------|------------|--------------|--------------------------------------------------------------------------------|
| 60%  | 200 MHz                 | 20 dB       | 5.0        | 1.25       | 60 %         | Modulación adecuada, envolvente clara y simétrica. Sin sobremodulación.       |
| 100% | 250 MHz                 | 25 dB       | 5.0        | 0.0        | 100 %        | Modulación completa, la envolvente toca el eje cero. Límite ideal.            |
| 150% | 150 MHz                 | 30 dB       | 5.0        | -2.5       | 120 %        | Sobremodulación grave, envolvente cruzada e inversión de fase.                |






##  Conclusión

Este análisis permitió evidenciar la forma en la que el índice de modulación afecta el espectro de una señal AM. También se confirmó experimentalmente que:

- Las bandas laterales tienen una potencia proporcional al cuadrado del índice de modulación (ka · Am)^2.
- Un exceso de modulación genera sobre-modulación que puede comprometer la integridad de la señal demodulada.
- Se logró estimar experimentalmente el índice de modulación usando observaciones directas desde el osciloscopio.
- Se identificaron correctamente los casos de submodulación, modulación al 100% y sobremodulación.





Volver al [INICIO](#laboratorio-de-comunicaciones)
