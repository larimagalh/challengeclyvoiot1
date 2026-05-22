# 🐾 Clyvo Vet IoT

Projeto desenvolvido para a disciplina de IoT com foco em monitoramento preventivo da saúde de pets utilizando sensores, ESP32, MQTT e dashboard em tempo real.

Larissa Juvenal de Magalhães RM566457
Matheus Gianolli RM565258
Júlia Kauane Menezes Farias RM565568
Gustavo Ribeiro Permagnani RM564995
Enzo Xavier Coelho RM563379

---

# 📌 Sobre o Projeto

O projeto **Clyvo Vet IoT** tem como objetivo solucionar um dos principais problemas do mercado veterinário:

> A falta de acompanhamento contínuo e preventivo da saúde dos animais.

Muitos pets chegam às clínicas apenas em estados críticos, aumentando:
- custos de tratamento
- sofrimento do animal
- desgaste emocional do tutor
- baixa recorrência de consultas preventivas

Nossa solução utiliza IoT para monitorar indicadores básicos do pet em tempo real, permitindo:
- acompanhamento contínuo
- geração de alertas
- monitoramento remoto
- suporte preventivo ao veterinário e tutor

---

# 🎯 Objetivos do Projeto

- Monitorar dados básicos do pet utilizando sensores
- Simular coleta de dados em tempo real
- Enviar informações via protocolo MQTT
- Exibir dashboard inteligente em Node-RED
- Demonstrar viabilidade técnica da solução

---

# 🧠 Tecnologias Utilizadas

## Hardware / Simulação
- ESP32
- Sensor DHT22
- Sensor PIR
- Wokwi Simulator

## Comunicação
- MQTT
- HiveMQ Broker

## Software
- Node-RED
- Dashboard Node-RED
- Arduino IDE (compatível)

## Linguagens
- C++
- JSON

---

# ⚙️ Componentes Utilizados

| Componente | Função |
|---|---|
| ESP32 | Microcontrolador principal |
| DHT22 | Monitoramento de temperatura e umidade |
| PIR Motion Sensor | Detecção de movimento |
| MQTT | Comunicação em tempo real |
| Node-RED Dashboard | Interface visual |

---

# 🏗️ Arquitetura da Solução

```text
Sensores → ESP32 → MQTT → Node-RED → Dashboard
