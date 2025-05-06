
# 🐄 Cow Tag: Dispositivo IoT para Monitoreo Ganadero en Zonas Rurales de Chile

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

La actividad ganadera en zonas rurales de Chile se enfrenta a múltiples retos: terrenos amplios, pérdida de animales, cercas costosas, ausencia de conectividad móvil y baja eficiencia operativa.

**Cow Tag** surge como una solución tecnológica integral. Es un dispositivo IoT que se fija al ganado y permite monitorear su ubicación, movimientos y comportamiento, incluso en lugares sin señal celular. Utiliza tecnologías probadas como **LoRaWAN**, **GPS**, **acelerómetros** y **energía solar**, con el objetivo de operar de forma autónoma por meses.

### Solución:
- Seguimiento del ganado con GPS en tiempo real.
- Alerta ante posibles escapes o situaciones de riesgo.
- Futuras cercas virtuales configurables desde una app.
- Plataforma de gestión accesible vía web y móvil.

---

## 🌎 Estado del Arte y Benchmark Global

| Producto     | Empresa    | Tecnología                           | Precio        | Región               | Limitaciones                      |
|--------------|------------|---------------------------------------|----------------|------------------------|-----------------------------------|
| Nofence      | Noruega    | GPS, App, Panel solar, descarga       | USD 289 + subs.| Europa/USA             | Requiere señal celular            |
| eShepherd    | Gallagher  | GPS, estación base, solar             | USD 250–350    | USA, Canadá            | Mínimo 20 collares, base LTE      |
| Halter       | NZ/USA     | GPS, base inteligente, energía solar  | USD 60/año     | NZ, USA                | Requiere infraestructura compleja |
| Vence        | Merck      | GPS + base fija                       | USD 40/año     | USA                   | Limitada autonomía energética     |

Cow Tag busca posicionarse como una alternativa más económica, con independencia celular (gracias a LoRa) y adaptable al terreno rural latinoamericano.

---

## 🚧 Cercas Virtuales – Enfoque Técnico

### ¿Cómo funcionan?
1. Se configura una cerca virtual desde una app o plataforma web.
2. El collar Cow Tag monitorea la ubicación del animal vía GPS.
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
Cow Tag (GPS+LoRa)
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
