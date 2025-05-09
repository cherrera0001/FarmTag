![Logo _FarmTag_ con elementos rurales](https://github.com/user-attachments/assets/a4e5a11c-4e26-4d0c-8ad6-e45a29fdb613)


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

Fue entonces cuando me di cuenta de una necesidad profunda y común entre los ganaderos: conocer el estado, ubicación y comportamiento de sus animales, especialmente en terrenos amplios y sin conectividad móvil. Sin embargo, el primer desafío era evidente: la falta de conexión en esas zonas rurales.

FarmTag surgió como una respuesta a esta necesidad, una solución tecnológica que trasciende el mero control visual del ganado. No se trata solo de una etiqueta identificadora, sino de un sistema integral diseñado para monitorear la ubicación, la salud y el comportamiento, incluso en áreas remotas. Es una solución que aspira a transformar la ganadería rural, haciéndola más eficiente, segura y rentable.

FarmTag es una solución IoT concebida para el monitoreo inteligente de ganado en entornos rurales desprovistos de cobertura celular. El producto inicial de esta línea es Cow Tag, un dispositivo IoT para vacas que faculta a los ganaderos para supervisar la ubicación, la salud y el comportamiento de sus animales de manera autónoma y precisa. La visión a largo plazo de FarmTag contempla la expansión de esta solución a otros animales como caballos (HorseTag) y ovejas (SheepTag), adaptando la tecnología a las particularidades de cada especie.



## 🌱 Visión y Familia de Productos

FarmTag es una solución modular que se adapta a diversos tipos de ganado:

![image](https://github.com/user-attachments/assets/5b34b61f-c561-4a51-ab9a-b581854160d7)



* **Cow Tag:** Dispositivo IoT para vacas, optimizado para monitoreo en grandes extensiones rurales.
* **Horse Tag:** Dispositivo IoT para caballos, con monitoreo de actividad y rendimiento (especial para caballos deportivos y de trabajo).
* **Sheep Tag:** Dispositivo IoT para ovejas, enfocado en control de salud y productividad (lana, carne, leche).

El objetivo es construir una plataforma única que permita a los ganaderos gestionar todo su ganado desde una única interfaz.

## 🌐 Problemas Ganaderos y Oportunidad
En Chile, más del 70% de los predios ganaderos se encuentran en zonas rurales sin acceso a señal celular. Los ganaderos enfrentan problemas como:

* **Pérdida de animales:** 12% de pérdida promedio anual por extravío.
* **Falta de control sanitario:** Más del 40% de los ganaderos no tienen registro sanitario constante.
* **Bajo acceso a tecnología:** 80% de los ganaderos pequeños no utilizan soluciones tecnológicas.

FarmTag busca resolver estos problemas, ofreciendo un monitoreo preciso y accesible.


![image](https://github.com/user-attachments/assets/eb81f690-d305-4bf1-a140-ba20dd8f14b6)


## 🚀 Primera Etapa: CowTag

### 🌐 **Seguimiento y Monitoreo Inteligente**
- 📍 **Seguimiento por GPS en tiempo real:** Permite conocer la ubicación del animal en cualquier momento, mejorando la gestión del ganado en grandes extensiones de terreno.
- 🚨 **Alertas de comportamiento anómalo:** Detecta situaciones como inactividad prolongada, movimiento errático o posible escape del animal, enviando notificaciones automáticas al usuario.
- 🧭 **Geocercas configurables:** Configuración de cercas virtuales para definir límites de movimiento sin necesidad de vallas físicas, una solución versátil y adaptable (implementación prevista para fases futuras).
- ☀️ **Operación autónoma:** Alimentación mediante panel solar y batería de larga duración, garantizando un funcionamiento continuo sin intervención humana frecuente.
- 📡 **Conectividad avanzada:** Comunicación a través de LoRaWAN, una tecnología que permite el monitoreo incluso en zonas rurales sin cobertura celular.
- 📲 **Plataforma de gestión web/móvil:** Acceso a través de una aplicación intuitiva y fácil de usar, diseñada para usuarios no técnicos, compatible con cualquier dispositivo.

---

### 🌱 **Visión a Corto y Mediano Plazo**
- 🌡️ **Sensores adicionales:** Integración de sensores de temperatura corporal y frecuencia cardíaca para monitoreo de salud.
- 🍃 **Detección de patrones de alimentación:** Identificación de consumo de alimento y alerta ante falta de movimiento prolongado.
- 🗺️ **Mapas de comportamiento:** Generación de rutas frecuentes y mapas de calor para análisis de desplazamientos del ganado.
- 🔋 **Estado energético del dispositivo:** Monitoreo del nivel de batería del collar y alertas automáticas por bajo rendimiento energético.
- 📊 **Estimaciones predictivas:** Uso de inteligencia artificial para predecir condiciones como preñez, enfermedades o problemas digestivos (detección de rumia).
- 📝 **Reportes automáticos:** Generación de reportes trazables para cumplir con normativas del SAG o para exportación, facilitando la gestión documental del productor.

---

## 🌎 Estado del Arte y Benchmark Global

| Producto     | Empresa    | Tecnología                           | Precio        | Región               | Limitaciones                      |
|--------------|------------|---------------------------------------|----------------|------------------------|-----------------------------------|
| Nofence      | Noruega    | GPS, App, Panel solar, descarga       | USD 289 + subs.| Europa/USA             | Requiere señal celular            |
| eShepherd    | Gallagher  | GPS, estación base, solar             | USD 250–350    | USA, Canadá            | Mínimo 20 collares, base LTE      |
| Halter       | NZ/USA     | GPS, base inteligente, energía solar  | USD 60/año     | NZ, USA                | Requiere infraestructura compleja |
| Vence        | Merck      | GPS + base fija                       | USD 40/año     | USA                   | Limitada autonomía energética     |

CowTag busca posicionarse como una alternativa más económica, con independencia celular (gracias a LoRa) y adaptable al terreno rural latinoamericano.

---

## 🚧 Cercas Virtuales – Enfoque Técnico

### ¿Cómo funcionan?
1. Se configura una cerca virtual desde una app o plataforma web.
2. El collar CowTag monitorea la ubicación del animal vía GPS.
3. Si el animal se acerca a la zona límite:
   - Se emite una alerta sonora.
   - (Fase futura) Se aplicaría un impulso leve.

### Consideraciones técnicas:
- GPS convencional (~2–10 m precisión).
- Posible evolución a GPS RTK para mayor exactitud.
- Cercas dinámicas posibles según estaciones o calidad del forraje.

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

### Tecnologías:
- **Backend:** Firebase (rápido), Supabase (open-source).
- **Frontend:** React / Vue.js (web), Flutter / React Native (móvil).
- **Seguridad:** MQTT + TLS, validación JWT, cifrado en tránsito y en reposo.

---

## ⚙️ Propuesta MVP Técnica

### Lista de materiales (estimado):

- MCU + GPS + LoRa: ~$18.000
- Panel solar: ~$2.500
- Batería + cargador: ~$4.000
- Caja, conectores, extras: ~$3.000

**Costo total por unidad MVP:** ~$28.000–34.000 CLP

### Ciclo de operación:
1. Ciclo de lectura GPS cada 30–60 minutos.
2. Detección de eventos: cruce, inactividad.
3. Envío LoRa → almacenamiento → visualización.

---

## 💰 Evaluación de Costos Iniciales

| Cantidad | Precio unitario estimado | Costo total aprox. |
|----------|---------------------------|---------------------|
| 1        | $34.000 CLP               | $34.000 CLP         |
| 10       | $31.000 CLP               | $310.000 CLP        |
| 100      | $28.000 CLP               | $2.800.000 CLP      |

---

## ✅ Conclusiones y Recomendaciones

- El diseño del MVP es **viable técnica y financieramente**.
- LoRa y energía solar ofrecen autonomía y bajo costo.
- Se sugiere iniciar con pruebas de campo usando gateways comunitarios (TTN).
- La evolución futura incluirá cercas virtuales activas.

**Próximos pasos:**
- Fabricación de prototipos.
- Validación funcional (campo real).
- Iteración de firmware y estructura.
- Preparación de pitch para incubadora/inversionistas.

---

## 📎 Archivos Adjuntos

- [Nofence](https://www.nofence.no/en-us/what-is-nofence)
- [eShepherd (Gallagher)](https://am.gallagher.com/en-US/new-products/eShepherd)
- [Sateliot – IoT Satelital](https://sateliot.space/es/ganaderia/)
- [Basto.io (startup argentina)](https://basto.io)
- [Virtual fencing PDF – Southwest Beef](https://southwestbeef.org/wp-content/uploads/virtual_fencing_spanish_v3.pdf)
