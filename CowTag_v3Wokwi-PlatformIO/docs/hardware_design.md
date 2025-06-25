# CowTag V1 - Diseño de Hardware

## Componentes Principales

### TTGO T-Beam (ESP32 + LoRa + GPS)
- Microcontrolador principal
- Comunicación LoRaWAN integrada
- GPS integrado
- Gestión de energía

### Sensores Adicionales
- **MPU6050**: Acelerómetro y giroscopio para detección de movimiento
- **Sensor de temperatura**: Monitoreo ambiental
- **Sensor de batería**: Nivel de carga

### Indicadores
- **LED Verde**: Estado normal/GPS fix
- **LED Rojo**: Alarma/batería baja

## Consumo de Energía

| Modo | Corriente | Duración |
|------|-----------|----------|
| Activo | 250mA | 5 min/hora |
| Sleep | 10µA | 55 min/hora |
| Deep Sleep | 2µA | Modo nocturno |

## Especificaciones Técnicas

- **Alimentación**: Batería Li-Ion 3.7V 2500mAh
- **Autonomía**: 30-45 días (modo normal)
- **Rango LoRaWAN**: 2-5 km (campo abierto)
- **Resistencia**: IP65 (resistente al agua)
- **Temperatura**: -20°C a +60°C