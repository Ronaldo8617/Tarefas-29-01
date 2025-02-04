# Clock e Temporizadores
# Projetos de Temporização para Raspberry Pi Pico

Este repositório contém dois projetos desenvolvidos para o microcontrolador Raspberry Pi Pico, utilizando o Pico SDK. Os projetos envolvem o controle de LEDs com temporizadores, sendo eles um semáforo e um sistema de acionamento de LEDs com botão. Abaixo, são descritas as atividades implementadas.

## Atividade 1: Temporizador Periódico - Semáforo

Nesta atividade, foi desenvolvido um sistema de semáforo com LEDs utilizando a função `add_repeating_timer_ms()` do Pico SDK. O semáforo alterna entre três LEDs (vermelho, amarelo e verde), com um atraso de 3 segundos entre cada mudança de sinal.

### Requisitos:
1. O acionamento dos LEDs inicia na cor vermelha, alterando para amarela e, em seguida, para verde.
2. O temporizador é ajustado para um atraso de 3 segundos (3.000ms).
3. A mudança de estado dos LEDs é implementada na função de call-back do temporizador.
4. A rotina principal imprime uma mensagem a cada segundo (1.000 ms).
5. O código foi testado no simulador Wokwi, utilizando o LED RGB nos pinos GPIOs 11, 12 e 13.

---

## Atividade 2: Temporizador de Um Disparo (One Shot) - Acionamento de LEDs com Botão

Nesta atividade, foi implementado um sistema de temporização para o acionamento de LEDs, ativados por um botão (pushbutton). A sequência de LEDs é controlada por callbacks e temporizadores, com um atraso de 3 segundos entre cada estado.

### Requisitos:
1. Ao pressionar o botão, os três LEDs são ligados e, após 3 segundos, a mudança de estado ocorre em três etapas: dois LEDs acesos, depois um LED aceso, e por fim todos os LEDs apagados.
2. O temporizador de alarme é ajustado para 3 segundos entre cada mudança de estado dos LEDs.
3. A mudança de estado dos LEDs é implementada em funções de callback do temporizador, como **`desligar_led1_callback()`**, **`desligar_led2_callback()`**, e **`desligar_led3_callback()`**, que controlam o desligamento sequencial dos LEDs.
4. Durante a execução do temporizador, o botão não pode iniciar uma nova chamada do callback.
5. O código foi testado no simulador Wokwi, utilizando o LEDs Verde, Azul e Vermelho nos pinos GPIOs 11, 12 e 13 e o botão no GPIO 5.

---

## Como Executar

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
2. Em seguida utilizando a extensão da raspberry pi pico pelo VSCode, **você deve exportar o projeto de cada Tarefa individualmente para poder executar os arquivos em seu computador**.

