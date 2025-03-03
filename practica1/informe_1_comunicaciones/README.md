# Laboratorio de Comunicaciones
## Universidad Industrial de Santander

---
# Práctica 1: GNURADIO Y RECONOCIMIENTO DE LOS EQUIPOS

### Integrantes
- **SANTIAGO HERNANDO POSADA BAYONA** - 2190428
- **NICOLAS ROJAS** - Código

Escuela de Ingenierías Eléctrica, Electrónica y de Telecomunicaciones  
Universidad Industrial de Santander

### Fecha
04 de marzo de 2025

---

## Declaración de Originalidad y Responsabilidad
Los autores de este informe certifican que el contenido aquí presentado es original y ha sido elaborado de manera independiente. Se han utilizado fuentes externas únicamente como referencia y han sido debidamente citadas.

Asimismo, los autores asumen plena responsabilidad por la información contenida en este documento. 

Uso de IA: [Por el momento no se ha usado ia.]

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
- ¿Qué parámetros del USRP 2920 se deben configurar para transmitir una señal en una frecuencia específica?
- ¿Cómo se configura el osciloscopio para medir la amplitud y la frecuencia de una señal?
- ¿Qué diferencia hay entre medir una señal en el dominio del tiempo (osciloscopio) y en el dominio de la frecuencia (analizador de espectros)?
- ACTIVIDAD 2:

- ¿Cómo se puede explicar matemáticamente la diferencia entre una fuente de tipo flotante y una de tipo complejo?
- ¿Cómo afecta la forma de onda a la distribución de energía (potencia) en el dominio de la frecuencia?
- ¿Qué sucede con la señal en el dominio del tiempo y la frecuencia si se modifican los diferentes parámetros de la fuente? ¿Lo observado corresponde a lo esperado teóricamente?
- ¿Cómo se relaciona la amplitud de la señal con la potencia observada en el dominio de la frecuencia?
- ¿Qué diferencias se observan entre una señal senoidal y una señal cuadrada en el dominio de la frecuencia?

- ACTIVIDAD 3:
- ¿Cómo se configura el USRP 2920 para transmitir una señal en una frecuencia específica?
- ¿Qué parámetros del flujograma afectan la potencia de la señal transmitida?
- ¿Cómo se mide el ancho de banda de la señal transmitida en el analizador de espectros?
- ¿Cómo se calcula la relación señal a ruido (SNR) a partir de las mediciones de potencia y piso de ruido?
- ¿Qué diferencias se observan en las mediciones de potencia cuando se varía la ganancia del USRP?
- ¿Es posible medir o estimar la potencia de la señal observada en el osciloscopio? ¿Por qué?
  
- ACTIVIDAD 4:
- ¿Qué conclusiones se pueden obtener sobre la relación entre la potencia de la señal y la calidad de la comunicación?
- ¿Cómo afecta el piso de ruido a la capacidad de detectar señales débiles?
- ¿Qué limitaciones tienen los equipos utilizados en términos de ancho de banda y precisión en las mediciones?
- ¿Cómo se pueden mejorar las mediciones de señal en un entorno con alto nivel de ruido?
- ¿Qué aplicaciones prácticas tienen las mediciones de potencia y ancho de banda en sistemas de comunicaciones reales?
- ¿Cómo se puede medir la respuesta en frecuencia de un canal alámbrico?
- ¿Cómo se puede obtener un modelo sencillo de las pérdidas (pathloss) en un canal inalámbrico?

  

### Procedimiento
Debe basarse en las acciones efectivamente realizadas durante el laboratorio, describiendo los procesos realizados y los resultados obtenidos. Para cada práctica se pueden brindar preguntas orientadoras o pasos a seguir para establecer lo que se espera lograr/estudiar/analizar/obtener/comparar. Por ejemplo:
- Describa los procesos realizados en el laboratorio  y los resultados obtenidos.
- ¿Cómo se alcanza el límite de Nyquist y que pasa cuando se disminuye de este?
- ¿Por qué al interpolar una señal en GNURADIO su frecuencia disminuye?
- ¿Por qué al diezmar una señal en GNURADIO su frecuencia aumenta?
- ¿Cómo se puede determinar la frecuencia máxima de una señal desde lo experimental?
- ¿Qué le sucede a una señal de audio cuando no se respeta el teorema de Nyquist?
- Describa las funciones logradas con el Ecualizador desarrollado con GNURadio.

### Conclusiones
Se sintetizan los principales aportes y puntos relevantes de la práctica, evitando repetir lo ya consignado en las otras secciones del informe. 

### Referencias
Ejemplo de referencia:

- [Proakis, 2014] J. Proakis, M. Salehi. Fundamentals of communication systems. 2 ed. England: Pearson Education Limited, 2014. p. 164-165, 346. Chapter 5 In: [Biblioteca UIS](https://uis.primo.exlibrisgroup.com/permalink/57UIDS_INST/63p0of/cdi_askewsholts_vlebooks_9781292015699)

---
# Ejemplos usando Markdown

Volver al [INICIO](#laboratorio-de-comunicaciones)

## Inclusión de Imágenes
### Imagen de referencia dentro del repositorio:
![Networking](my%20file/test.png)

### Imagen de fuente externa
![GNU Radio logo](https://kb.ettus.com/images/thumb/5/50/gnuradio.png/600px-gnuradio.png)

### Uso de html para cambiar escala de la imagen
<img src="https://kb.ettus.com/images/thumb/5/50/gnuradio.png/600px-gnuradio.png" alt="GNU Radio Logo" width="300">

## Creación de hipevínculos 
- [Aprende Markdown](https://markdown.es/)
- [Más acerca de Markdown](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
- [Abrir documento en el repositorio](my%20file/test_file.txt). Si hay espacios en la ruta de su archivo, reemplácelos por `%20`.
- Ir a una sección de este documento. Por ejemplo: [Ir a Contenido](#contenido) Tenga en cuenta escribir el título de la sección en minúsculas y los espacios reemplazarlos por guiones.
## Uso de Expresiones Matemáticas
Se pueden incluir ecuaciones en el archivo `README.md` utilizando sintaxis similar a [LaTeX](https://manualdelatex.com/tutoriales/ecuaciones):

### Ecuaciones en Línea
```
La energía de una señal exponencial es $E = \int_0^\infty A^2 e^{-2t/\tau} dt$.
```
**Salida renderizada:**
La energía de una señal exponencial es $E = \int_0^\infty A^2 e^{-2t/\tau} dt$.

### Ecuaciones en Bloque
```
$$E = \int_0^\infty A^2 e^{-2t/\tau} dt = \frac{A^2 \tau}{2}$$
```
**Salida renderizada**
$$E = \int_0^\infty A^2 e^{-2t/\tau} dt = \frac{A^2 \tau}{2}$$

## Creación de Tablas

**Tabla 1.** Ejemplo de tabla en Markdown.

| Parámetro | Valor |
|-----------|-------|
| Frecuencia (Hz) | 1000 |
| Amplitud (V) | 5 |
| Ciclo útil (%) | 50 |

## Inclusión de código

```python
def hello_world():
    print("Hello, World!")
```

También es posible resaltar texto tipo código como `print("Hello, World!")`.

---

Volver al [INICIO](#laboratorio-de-comunicaciones)
