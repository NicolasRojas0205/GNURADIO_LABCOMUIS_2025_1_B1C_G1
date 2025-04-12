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

#### Caso 1: \( ka \cdot A_m < 1 \)

![Caso 1](ruta/a/tu/imagen1.jpg)

#### Caso 2: \( ka \cdot A_m \approx 1 \)

![Caso 2](ruta/a/tu/imagen2.jpg)

#### Caso 3: \( ka \cdot A_m > 1 \)

![Caso 3](ruta/a/tu/imagen3.jpg)

---

##  Datos obtenidos del analizador de espectros

> Puedes incluir esta tabla como una **imagen** si la formateaste en Excel o cualquier otro editor gráfico.

| Caso                | P. Portadora (dBm) | P. BL Sup/Inf (dBm) | \( NdB \) (dB) | \( ka \cdot A_m \) | f_m (Hz)     | Comentario            |
|---------------------|--------------------|----------------------|----------------|--------------------|---------------|------------------------|
| ka·Am < 1           | -23.70             | -50.00               | -26.30         | ~0.15              | ~24.3 kHz     | Modulación débil       |
| ka·Am ≈ 1           | -23.96             | -30.00               | -6.04          | ~0.99              | ~24.3 kHz     | Modulación ideal       |
| ka·Am > 1           | -23.73             | -20.00               | +3.73          | ~2.44              | ~24.3 kHz     | Sobre-modulación       |

---

##  Cálculo del índice de modulación

Se utilizó la siguiente fórmula para estimar el índice de modulación a partir de la potencia de la portadora y la potencia de una de las bandas laterales:

\[
ka \cdot A_m = 2 \cdot 10^{\frac{NdB}{20}} \quad \text{con } NdB = P_{BL} - P_{portadora}
\]

Aplicando esta fórmula a cada caso:

- **Caso 1**:  
  \( NdB = -50 - (-23.70) = -26.3 \)  
  \( ka \cdot A_m = 2 \cdot 10^{-26.3/20} \approx 0.15 \)

- **Caso 2**:  
  \( NdB = -30 - (-23.96) = -6.04 \)  
  \( ka \cdot A_m = 2 \cdot 10^{-6.04/20} \approx 0.99 \)

- **Caso 3**:  
  \( NdB = -20 - (-23.73) = +3.73 \)  
  \( ka \cdot A_m = 2 \cdot 10^{3.73/20} \approx 2.44 \)

---

## Análisis

- Cuando \( ka \cdot A_m < 1 \), la señal se encuentra **submodulada**. Se observa que las bandas laterales tienen amplitud muy baja en comparación con la portadora.
- Al alcanzar \( ka \cdot A_m = 1 \), se obtiene una modulación **ideal**, donde la energía se reparte balanceadamente entre la portadora y las bandas laterales.
- Con \( ka \cdot A_m > 1 \), se presenta **sobre-modulación**, lo cual puede causar distorsión si se detecta con un demodulador de envolvente. Aquí las bandas laterales superan en potencia a la portadora.

---

## Archivos

- `img/caso1.jpg` — Señal AM con índice < 1  
- `img/caso2.jpg` — Señal AM con índice ≈ 1  
- `img/caso3.jpg` — Señal AM con índice > 1  

---

## Conclusión

Este análisis permitió evidenciar la forma en la que el índice de modulación afecta el espectro de una señal AM. También se confirmó experimentalmente que:
- Las bandas laterales tienen una potencia proporcional a \( (ka \cdot A_m)^2 \).
- Un exceso de modulación genera sobre-modulación que puede comprometer la integridad de la señal demodulada.




Volver al [INICIO](#laboratorio-de-comunicaciones)
