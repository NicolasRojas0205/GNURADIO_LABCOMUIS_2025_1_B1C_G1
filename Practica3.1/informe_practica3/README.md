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
# Práctica: Modulación AM — Análisis Espectral para Distintos Índices de Modulación

##  Objetivo

Observar el comportamiento del espectro de una señal AM al variar el índice de modulación \( ka \cdot A_m \), utilizando un generador de funciones, un modulador AM y un analizador de espectros.

---

## Punto 1: Variación del índice de modulación y análisis de espectros

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

##  Archivos

![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.14_e79f11da.jpg) — Señal AM con índice < 1  
- ![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.14_5b637117.jpg) — Señal AM con índice ≈ 1  
- ![GNU Radio logo](https://github.com/NicolasRojas0205/GNURADIO_LABCOMUIS_2025_1_B1C_G1/blob/Practica3/Practica3.1/IMAGENES%20PRACTIA%201/Imagen%20de%20WhatsApp%202025-04-12%20a%20las%2000.25.13_13754b04.jpg) — Señal AM con índice > 1  


---

##  Conclusión

Este análisis permitió evidenciar la forma en la que el índice de modulación afecta el espectro de una señal AM. También se confirmó experimentalmente que:

- Las bandas laterales tienen una potencia proporcional al cuadrado del índice de modulación (ka · Am)^2.
- Un exceso de modulación genera sobre-modulación que puede comprometer la integridad de la señal demodulada.





Volver al [INICIO](#laboratorio-de-comunicaciones)
