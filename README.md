
![image](https://github.com/user-attachments/assets/e8fb235c-995f-4377-9a0e-29809f81be18)


# FarmTag: Dispositivo IoT para monitoreo ganadero en zonas rurales de Chile

**Responsable:** Cristóbal Herrera Jara (C4A SpA)  
**Fecha:** 6 de mayo de 2025

---

## 📘 Índice

- [Resumen Ejecutivo](#resumen-ejecutivo)
- [Estado del Arte y Benchmark Global](#estado-del-arte-y-benchmark-global)
- [Cercas Virtuales – Enfoque Técnico](#cercas-virtuales--enfoque-técnico)
- [Tecnologías Emergentes](#tecnologías-emergentes)
- [Comparativa de Hardware](#comparativa-de-hardware)
- [Infraestructura de Datos y Plataforma](#infraestructura-de-datos-y-plataforma)
- [Propuesta MVP Técnica](#propuesta-mvp-técnica)
- [Evaluación de Costos Iniciales](#evaluación-de-costos-iniciales)
- [Conclusiones y Recomendaciones](#conclusiones-y-recomendaciones)
- [📎 Archivos Adjuntos](#archivos-adjuntos)

---

## 🧭 Resumen Ejecutivo

***¿Cómo nació la idea de FarmTag?***
La idea de FarmTag nació en un momento de introspección y conexión con la naturaleza. Recuerdo que, tras una situación difícil en mi vida personal, decidí pasar unos días en el sur de Chile junto a mi padre. Durante esa estadía, tuve la oportunidad de conocer a mi familia paterna, la familia Palacios, especialmente a mi tío Queño y a mi primo Jaime. Queño ha sido veterinario toda su vida, y juntos se dedican a la crianza de ganado. Fue ahí, en su predio, donde observé una práctica que me llamó profundamente la atención: antes de ir a una feria a vender su ganado, ellos perforaban la oreja de las vacas para colocarles una etiqueta, un "tag" simple exigido por el SAG (Servicio Agrícola y Ganadero).

Aquella escena, aparentemente rutinaria, despertó en mí una pregunta: ¿Qué más se podría controlar en el ganado? ¿Qué información adicional se podría obtener para ayudar realmente a los ganaderos? No se trataba solo de identificarlos, sino de ofrecerles datos útiles para su gestión diaria.

Poco después, conocí a Gabriel, un hombre mayor que también trabajaba con ganado. Una tarde, su esposa le pidió que fuera a buscar a su buey, un animal viejo que solía pastar libremente. Gabriel miró al horizonte y, con una certeza impresionante, dijo: "A esta hora el animal está echado, no lo voy a encontrar". Esa escena me dejó pensando. ¿Y si él pudiera saber con precisión dónde estaba su buey, sin depender solo de su intuición?

Fue entonces cuando entendí que los ganaderos no solo necesitan identificar a sus animales, sino que también requieren información para protegerlos y optimizar su gestión. Y el desafío era evidente: la falta de conectividad en esas zonas rurales.

## 🌟 Propósito

FarmTag busca democratizar el acceso a tecnología ganadera inteligente en zonas rurales de Chile y América Latina, permitiendo a pequeños y medianos ganaderos tomar decisiones basadas en datos, reducir pérdidas y mejorar el bienestar animal, integrando tecnologías como IoT, IA y energías limpias.

**Visión:** Ser la solución de monitoreo animal más accesible y adaptable del Cono Sur para el año 2030.

**Misión:** Implementar tecnología ganadera eficiente, ética y sostenible en cada campo chileno con necesidades reales.


## 🧠 Inspiración Profunda: Gabriel AI y un Legado Chileno

Lo increíble es que, mientras investigaba estas necesidades a raíz de las recomendaciones de mi tío Queño, descubrí que mi elección intuitiva de llamar **"Gabriel AI"** a nuestra inteligencia artificial no era solo una coincidencia. El nombre resonó profundamente con la historia del **Dr. Gabriel Vivallo Pinare**, un visionario investigador chileno que ya en 2007 lideraba el proyecto **"Campero Electrónico"** en la Universidad Católica de Temuco —una de las primeras propuestas para modernizar la ganadería nacional mediante tecnología.

Este hallazgo nos emocionó profundamente y le dio un propósito aún más simbólico a FarmTag. Conectar con este legado pionero chileno reafirma nuestra misión: continuar la senda de quienes soñaron con una ganadería más inteligente, humana y sostenible. Hoy, **Gabriel AI** no solo representa un modelo de análisis predictivo, sino también un homenaje a esa visión temprana de transformación rural que hoy buscamos concretar con IoT, IA y tecnología aplicada en terreno.

🔗 Más información sobre el legado del Dr. Vivallo: [Campero Electrónico - UCT](https://3w.uct.cl/boletin/index.php?op=ver_noticia&idn=1362)


---

## 📊 **Datos Duros del Sector Ganadero en Chile**


# **🔎 Chile pierde aproximadamente 8.000 cabezas de ganado al año debido a robo y depredación**, una cifra que se traduce en millones de dólares en pérdidas para pequeños y medianos productores (Abigeato).

- **🐂 Abigeato:** Según el Servicio Agrícola y Ganadero (SAG), el abigeato es una preocupación constante para los productores ganaderos en Chile. La implementación de sistemas de trazabilidad, como los Dispositivos de Identificación Individual Oficial (DIIO), busca mitigar este problema al facilitar el seguimiento y control del ganado.  
  🔗 [SAG - Programa Oficial de Trazabilidad Animal](https://www.sag.gob.cl/ambitos-de-accion/programa-oficial-de-trazabilidad-animal)
  🔗 [2012: Ley de abigateo según Fucoa.cl](https://fucoa.cl/2012/11/07/ley-de-abigeato-fortalece-el-combate-de-la-delincuencia-en-el-campo/)
  🔗 [Octubre-2023 - BCN ](https://www.bcn.cl/historiadelaley/fileadmin/file_ley/4431/HLD_4431_37a6259cc0c1dae299a7866489dff0bd.pdf)
  

- **🌡️ Enfermedades Relacionadas con el Calor:** El Instituto de Investigaciones Agropecuarias (INIA) ha destacado que las variaciones de temperatura incrementan las enfermedades respiratorias en el ganado, especialmente durante olas de calor. Estas enfermedades pueden reducir la productividad lechera en un **20%**.  
  🔗 [INIA - Boletín Nacional de Análisis de Riesgos Agroclimáticos](https://riesgoclimatico.inia.cl/public/resumenPDF/107)
  🔗 [Versión en ResearchGate](https://www.researchgate.net/publication/370546384_Estimation_of_the_economic_impact_of_heat_stress_on_dairy_production_systems_in_Chile/fulltext/64550ab94af78873525e95a0/Estimation_of_the-economic-impact-of-heat-stress-on-dairy-production-systems-in-Chile.pdf)
  https://www.researchgate.net/publication/370546384_Estimation_of_the_economic_impact_of_heat_stress_on_dairy_production_systems_in_Chile/fulltext/64550ab94af78873525e95a0/Estimation-of-the-economic-impact-of-heat-stress-on-dairy-production-systems-in-Chile.pdf

- **📶 Conectividad en Zonas Rurales:** En regiones rurales de Chile, más del **60% de las fincas** carecen de conectividad estable, lo que dificulta la gestión eficiente del ganado y la implementación de tecnologías avanzadas para su monitoreo.  
  🔗 [INIA - Estrategias Innovadoras en Genética y Sanidad Ganadera](https://www.inia.cl/2024/06/11/estrategias-innovadoras-en-genetica-y-sanidad-ganadera-marcan-jornada-de-inia-en-aysen/)
  Para más detalles sobre la iniciativa conjunta del Gobierno de Chile y la ONU para lanzar un proyecto de conectividad rural innovador, puedes consultar el artículo completo aquí:

 🔗 [Transformación Digital en Zonas Rurales: Gobierno de Chile y ONU lanzan un proyecto innovador de conectividad](https://www.jointsdgfund.org/article/digital-transformation-rural-areas-government-chile-and-un-launch-innovative-connectivity)

- **📉 Pérdida de Animales por Extravío:** Los ganaderos enfrentan una pérdida promedio anual del **12% de su ganado** debido al extravío, lo que representa una pérdida económica significativa para pequeños y medianos productores.  
  🔗 [SAG - Programa Nacional de Control del Abigeato](https://www.sag.gob.cl/programa/programa-nacional-de-control-del-abigeato)

- **🩺 Falta de Control Sanitario:** Más del **40% de los ganaderos** no mantienen un registro sanitario constante de sus animales, lo que incrementa el riesgo de enfermedades y reduce la productividad del rebaño.  
  🔗 [ODEPA - Informe de Gestión Ganadera](https://www.odepa.gob.cl/wp-content/uploads/2024/04/informe-gestion-ganadera.pdf)

- **💻 Bajo Acceso a Tecnología:** El **80% de los pequeños ganaderos** no utilizan soluciones tecnológicas para la gestión de sus predios, limitando su capacidad para optimizar procesos y mejorar la eficiencia productiva.  
  🔗 [INIA - Diagnóstico del Uso de Tecnología en Ganadería](https://www.inia.cl/diagnostico-tecnologia-ganaderia)

---

### 🌱 **Estos datos subrayan la necesidad de soluciones como FarmTag, que integran tecnología IoT para mejorar la trazabilidad, salud y productividad del ganado, especialmente en zonas rurales con desafíos de conectividad y gestión.** 🚀

---
## 🚀 **FarmTag: Innovación Inteligente para la Ganadería**

FarmTag es una solución avanzada de monitoreo inteligente para ganado, diseñada para transformar la gestión ganadera. No es solo un dispositivo, es una red inteligente que combina tecnología IoT, inteligencia artificial y conectividad avanzada para mejorar la eficiencia, seguridad y productividad en la ganadería.

---

### 🛠️ **Innovación y Expansión**
- **🔬 Investigación Continua:** FarmTag evoluciona constantemente. Estamos desarrollando un **chip subcutáneo inteligente**, que permitirá un monitoreo aún más preciso de la salud animal, sin afectar su bienestar.  
- **🌐 Expansión Global:** Desde Chile hacia el mundo. FarmTag es una solución adaptable que puede implementarse en cualquier región, especialmente en zonas rurales sin conectividad.  
- **🌍 Diversificación de Especies:** FarmTag no se limita a vacas. Ofrecemos dispositivos especializados para caballos (HorseTag), ovejas (SheepTag) y proyectamos su uso para otras especies como cabras y cerdos.  
- **🚀 Producto Competitivo:** Con tecnología avanzada y diseño sostenible, FarmTag está listo para competir en mercados internacionales, destacando frente a marcas como Nofence, Gallagher y Halter.  

---

### 🌱 **Familia de Productos FarmTag**
FarmTag ofrece soluciones personalizadas para diferentes tipos de ganado, adaptándose a las necesidades específicas de cada especie:

![image](https://github.com/user-attachments/assets/5b34b61f-c561-4a51-ab9a-b581854160d7)

- **🐄 CowTag:**  
  - 📍 Monitoreo de ubicación en tiempo real.  
  - 🩺 Control de salud mediante sensores de temperatura y actividad.  
  - 🌿 Ideal para vacas lecheras y de carne.  

- **🐎 HorseTag:**  
  - 📊 Monitoreo de rendimiento y actividad.  
  - ❤️ Control de frecuencia cardíaca para caballos deportivos.  
  - 🚀 Optimizado para caballos de carreras, equitación y trabajo agrícola.  

- **🐑 SheepTag:**  
  - 🌡️ Monitoreo de salud y detección temprana de enfermedades.  
  - 🐏 Control de productividad (lana, carne y leche).  
  - 📍 Ubicación en tiempo real para gestión de rebaños.  

---

### 🌐 **¿Qué hace única a la familia FarmTag?**
- **🌐 Conectividad sin Límites:** Opera en zonas rurales sin señal celular gracias a LoRaWAN y conectividad satelital.  
- **🔋 Eficiencia Energética:** Dispositivos de bajo consumo, con opción de energía solar para mayor autonomía.  
- **🌿 Sostenibilidad Inteligente:** Monitoreo de salud y bienestar animal para una gestión ganadera responsable.  
- **📊 Inteligencia Predictiva (Gabriel AI):** Nuestro sistema usa inteligencia artificial para analizar el comportamiento y salud del ganado, enviando alertas automáticas al ganadero.  
- **🔒 Seguridad de Datos:** Todos los datos están protegidos con encriptación avanzada, garantizando privacidad y seguridad.  

---

## 🚀 **Primera Etapa: CowTag**
### 🌐 **Monitoreo Inteligente y Autonomía**
- 📍 **GPS en Tiempo Real:** Ubicación precisa del ganado en cualquier momento.  
- 🚨 **Alertas Automáticas:** Notificaciones de comportamiento anómalo (inactividad, movimiento errático, escape).  
- 🧭 **Geocercas Virtuales:** Definición de límites de movimiento sin necesidad de cercas físicas.  
- ☀️ **Energía Solar y Batería de Larga Duración:** Funcionamiento continuo sin intervención frecuente.  
- 📡 **Conectividad LoRaWAN:** Monitoreo en zonas sin señal celular.  
- 📲 **Plataforma Web y Móvil:** Acceso intuitivo para gestionar el ganado desde cualquier lugar.  
- 🚧 **Cercas Virtuales** – Enfoque Técnico

### ¿Cómo funcionan?
1. Se configura una cerca virtual desde una app o plataforma web.
2. El collar CowTag monitorea la ubicación del animal vía GPS/LoraWan
3. Si el animal se acerca a la zona límite:
   - Se emite una alerta sonora.
   - (Fase futura) Se aplicaría un impulso leve.

### Consideraciones técnicas:
- GPS convencional (~2–10 m precisión).
- Posible evolución a GPS RTK para mayor exactitud.
- Cercas dinámicas posibles según estaciones o calidad del forraje.
---

## 🌱 **Visión a Corto y Mediano Plazo**
- 🌡️ **Sensores Adicionales:** Monitoreo de temperatura corporal y frecuencia cardíaca para una salud animal precisa.  
- 🍃 **Detección de Patrones de Alimentación:** Identificación de consumo de alimento y alertas por falta de movimiento.  
- 🗺️ **Mapas de Comportamiento:** Visualización de rutas frecuentes y análisis de desplazamiento.  
- 🔋 **Monitoreo Energético:** Notificaciones de bajo rendimiento de la batería para garantizar operación continua.  
- 📊 **IA Predictiva (Gabriel AI):** Identificación de condiciones como preñez, enfermedades o problemas digestivos.  
- 📝 **Reportes Automáticos:** Documentación trazable para cumplir normativas del SAG y facilitar exportaciones.  

---

🚀 **FarmTag no es solo tecnología, es una solución que permite a los ganaderos tomar decisiones informadas, anticipar problemas y maximizar la productividad de su ganado.** 🌱

---

### 🌿 **Impacto en la Producción Ganadera**
- **📈 Mejora de la Productividad:** Al monitorear la salud y el bienestar del ganado, FarmTag permite a los ganaderos y lecheros (técnicamente conocidos como productores ganaderos y productores lecheros) tomar decisiones a tiempo, mejorando la calidad de la carne y la leche producida.
- **🐄 Optimización de la Producción Láctea:** Detectar tempranamente enfermedades como mastitis o estrés térmico en las vacas mejora la calidad y cantidad de leche.
- **🥩 Mayor Calidad de la Carne:** Al monitorear la actividad y la alimentación del ganado, se puede garantizar una mejor calidad de la carne producida.


## 🌱 Impacto Social y Ambiental de FarmTag

### 🌿 Sostenibilidad Circular
FarmTag adopta un enfoque sostenible al utilizar **materiales reciclados** y tecnologías de **impresión 3D** para la fabricación de sus collares inteligentes. En una estimación de producción de solo **100 collares a partir de materiales reciclados**, logramos:
- 🌍 **Reducir 34.8 kg de CO₂** en emisiones, equivalente a evitar el uso de plásticos vírgenes.
- 🚫 **Evitar que 12 kg de residuos plásticos** lleguen a vertederos o al mar, contribuyendo a la protección del medio ambiente.

### 🐮 Protección del Patrimonio Ganadero
Al reducir el robo de ganado y mejorar la salud de los animales, FarmTag protege la **fuente de ingresos de miles de familias rurales**.

### 🌱 Bienestar Animal y Gestión Responsable
FarmTag permite detectar enfermedades tempranas y optimizar el uso de pastos, promoviendo un **manejo más responsable y saludable del ganado**.

### 🌍 Reducción de Huella de Carbono
Mediante el monitoreo eficiente del ganado y el uso de materiales reciclados, FarmTag contribuye a la **mitigación del impacto ambiental**, reduciendo las **emisiones de metano** y ahorrando recursos naturales.

### 💧 Conservación del Agua
En regiones afectadas por la sequía, FarmTag facilita una **gestión inteligente de los recursos hídricos**, priorizando la hidratación de animales en riesgo.


---

## 🌎 Estado del Arte y Benchmark Global

| Producto     | Empresa    | Tecnología                           | Precio        | Región               | Limitaciones                      |
|--------------|------------|---------------------------------------|----------------|------------------------|-----------------------------------|
| Nofence      | Noruega    | GPS, App, Panel solar, descarga       | USD 289 + subs.| Europa/USA             | Requiere señal celular            |
| eShepherd    | Gallagher  | GPS, estación base, solar             | USD 250–350    | USA, Canadá            | Mínimo 20 collares, base LTE      |
| Halter       | NZ/USA     | GPS, base inteligente, energía solar  | USD 60/año     | NZ, USA                | Requiere infraestructura compleja |
| Vence        | Merck      | GPS + base fija                       | USD 40/año     | USA                   | Limitada autonomía energética     |

FarmTag busca posicionarse como una alternativa más económica, con independencia celular (gracias a LoRa) y adaptable al terreno rural latinoamericano.


---

## 📡 Tecnologías Emergentes

| Tecnología     | Alcance         | Energía       | Costo      | Observación                    |
|----------------|------------------|---------------|------------|-------------------------------|
| **LoRaWAN**    | 2–15 km           | Muy bajo      | Bajo/Medio | Ideal para zonas rurales      |
| Sigfox         | 10–40 km          | Bajo          | Bajo       | Cobertura limitada            |
| Satelital NB-IoT| Global           | Alto          | Alto       | Ideal en lugares extremos     |

- **MQTT** será el protocolo base (por su bajo overhead y soporte en IoT).
- **Energía solar** + batería Li-Ion/LiFePO4 permitirá operación continua.
- El firmware utilizará *deep sleep* y eventos por movimiento.

---

## 🧱 Comparativa de Hardware

| Componente       | Modelo                 | Precio CLP | Justificación breve                                  |
|------------------|------------------------|------------|------------------------------------------------------|
| Microcontrolador | LilyGO TTGO T-Beam     | $18.000    | GPS + LoRa integrados, ideal para MVP                |
| GPS              | u-blox Neo-6M          | $4.000     | Precisión aceptable, bajo consumo                    |
| LoRa             | SX1276 integrado       | Incluido   | Probado y eficiente para redes privadas              |
| Panel solar      | 5V 1.2W genérico       | $2.500     | Recarga básica en días soleados                     |
| Batería          | 18650 Li-Ion 2600mAh   | $2.000     | Alta densidad energética                             |
| Cargador         | TP4056 con BMS         | $1.200     | Control de carga básico y económico                  |
| Caja estanca     | IP65 ABS               | $2.500     | Protección contra polvo y agua                       |
| Gateway LoRaWAN  | RAK7246 / Dragino      | $70k–$120k | Necesario para pruebas reales, posible TTN gratuito  |

---

## ☁️ Infraestructura de Datos y Plataforma
### Arquitectura:

![Diagrama 1 Arquitectura General del Sistema CowTag (1)](https://github.com/user-attachments/assets/88c4856a-4c15-4e7e-926a-d6cc576a5a7f)

```
CowTag (GPS+LoRa)
     ↓
LoRa Gateway
     ↓
MQTT Broker
     ↓
Firebase/Supabase (Backend + DB)
     ↓
App Web o Móvil
```
## Flujo de datos

![Diagrama 2 Flujo de Datos del Sistema Cow Tag (1)](https://github.com/user-attachments/assets/7ed0cdc4-1d2e-4323-9db5-48aafa06ff7f)


### Tecnologías:
- **Backend:** Firebase (rápido), Supabase (open-source).
- **Frontend:** React / Vue.js (web), Flutter / React Native (móvil).
- **Seguridad:** MQTT + TLS, validación JWT, cifrado en tránsito y en reposo.

---

# ⚙️ Propuesta MVP Técnica

## 📋 Lista de materiales (estimado):
- **MCU + GPS + LoRa** (ESP32 GPS LoRa + Slot 18650): ~$44.950 CLP  
- **Panel solar**: ~$2.500 CLP *(no cotizado)*  
- **Batería + cargador** (TP4056 Micro USB): ~$1.205 CLP  
- **Caja, conectores, extras** (Caja Plástica IP65): ~$1.952 CLP  
- **Sensor de Humedad y Temperatura** (DHT11): ~$2.072 CLP  
- **Acelerómetro y Giroscopio** (MPU6050): ~$4.033 CLP  
- **Envío Chilexpress** (Chillán): ~$5.085 CLP  

**Costo total por unidad MVP**: ~$67.675 CLP *(sin IVA)*  

---

## 🔄 Ciclo de operación:
1. **Ciclo de lectura GPS**: cada 30–60 minutos.  
2. **Detección de eventos**: cruce, inactividad.  
3. **Envío LoRa** → almacenamiento → visualización.  

---

# 💰 Evaluación de Costos Iniciales

| **Cantidad** | **Precio unitario estimado** | **Costo total aprox.** |
|--------------|------------------------------|------------------------|
| 1            | $67.675 CLP                  | $67.675 CLP            |
| 10           | $64.000 CLP                  | $640.000 CLP           |
| 100          | $60.000 CLP                  | $6.000.000 CLP         |

---

# ✅ Conclusiones y Recomendaciones
- El diseño del MVP es viable **técnica y financieramente**, considerando precios reales.  
- **LoRa y energía solar** ofrecen autonomía y bajo costo operativo.  
- Se sugiere iniciar con pruebas de campo usando gateways comunitarios *(TTN)*.  
- La evolución futura incluirá **cercas virtuales activas**.  

---

## 🚀 Próximos pasos:
1. Fabricación de prototipos.  
2. Validación funcional *(campo real)*.  
3. Iteración de firmware y estructura.  
4. Preparación de pitch para incubadora/inversionistas.  

---

# 📞 Contacto  
**Cristóbal Herrera**  
📧 *Email*: crherrera@c4a.cl  

___

## 📎 Archivos Adjuntos

- [Nofence](https://www.nofence.no/en-us/what-is-nofence)
- [eShepherd (Gallagher)](https://am.gallagher.com/en-US/new-products/eShepherd)
- [Sateliot – IoT Satelital](https://sateliot.space/es/ganaderia/)
- [Basto.io (startup argentina)](https://basto.io)
- [Virtual fencing PDF – Southwest Beef](https://southwestbeef.org/wp-content/uploads/virtual_fencing_spanish_v3.pdf)
