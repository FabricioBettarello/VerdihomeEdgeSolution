# VerdiHome - Plataforma Inteligente de Gestão Energética

VerdiHome é uma solução IoT inteligente que combina automação residencial com um sistema de monitoramento de consumo energético. Com integração MQTT e conectividade WiFi, este projeto fornece alertas em tempo real sobre consumo elevado e permite controle remoto de dispositivos, contribuindo para um uso mais eficiente e sustentável de energia.

---

## 🚀 **Principais Funcionalidades**
- **Monitoramento de Consumo**: Mede o consumo energético em tempo real através de um sensor LDR e publica os dados via MQTT.
- **Alertas de Consumo Elevado**: Envia notificações quando o consumo excede o limite configurado.
- **Controle Remoto de Dispositivos**: Recebe comandos para ligar ou desligar um LED, simulando o controle de dispositivos.
- **Integração MQTT**: Publica e subscreve mensagens para comunicação eficiente.

---

## 🛠️ **Requisitos do Sistema**
### Hardware
- ESP32 
- Resistor LDR (sensor de luz)
- LED e resistor para controle
- Protoboard e fios de conexão

### Software
- Wokiwi
- Bibliotecas:
  - `WiFi.h` (embarcada no ESP32/ESP8266)
  - `PubSubClient.h` (disponível no gerenciador de bibliotecas da Arduino IDE)

---

## 📦 **Como Configurar e Executar**
### 1️⃣ **Configuração do Ambiente**
1. Instale a **Arduino IDE**.
2. Adicione suporte ao ESP32 ou ESP8266 no gerenciador de placas da IDE:
   - Vá em **Arquivo > Preferências** e adicione a URL: 
     `https://dl.espressif.com/dl/package_esp32_index.json`
   - Em **Ferramentas > Placas > Gerenciador de Placas**, instale o pacote ESP32.

### 2️⃣ **Bibliotecas Necessárias**
Instale a biblioteca **PubSubClient**:
- Vá em **Sketch > Incluir Biblioteca > Gerenciar Bibliotecas**.
- Pesquise por `PubSubClient` e clique em **Instalar**.

### 3️⃣ **Configuração do Código**
1. Insira as credenciais da sua rede WiFi no código:
   ```cpp
   const char* ssid = "Wokiwi-GUEST";
   const char* password = "";


## 📚 **Como Usar**

### **Monitoramento de Consumo**
- O consumo energético é monitorado pelo sensor LDR e os valores são enviados para o tópico MQTT:
  - **Tópico**: `verdiHome/consumo`
  - **Descrição**: Publica os dados do consumo energético em tempo real.

### **Alertas de Consumo Elevado**
- Quando o consumo ultrapassa o limite configurado no código (valor padrão: `800`), um alerta é enviado para o seguinte tópico MQTT:
  - **Tópico**: `verdiHome/alerta`
  - **Descrição**: Envia uma mensagem notificando o consumo elevado.

### **Controle de Dispositivos**
- Comandos MQTT podem ser enviados para controlar dispositivos (simulado por um LED no projeto):
  - **Tópico**: `verdiHome/comando`
  - **Mensagens**:
    - `"ligar"`: Liga o LED.
    - `"desligar"`: Desliga o LED.

---

## 📡 **Tópicos MQTT**

### **Publicações**
1. **Tópico**: `verdiHome/consumo`  
   **Descrição**: Publica os dados do consumo energético.
2. **Tópico**: `verdiHome/alerta`  
   **Descrição**: Notifica quando o consumo ultrapassa o limite configurado.
### **Assinaturas**
1. **Tópico**: `verdiHome/comando`  
   **Descrição**: Recebe comandos para ligar ou desligar dispositivos (LED no exemplo).


## Informações dos Alunos
- Fabricio Bettarello Heluani - RM 554638
- Thamiris Almeida Soares da Silva - RM 559155
- Eric Yuji Ito - RM 554869
