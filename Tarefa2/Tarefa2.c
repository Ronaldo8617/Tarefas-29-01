#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED1 12  // Azul
#define LED2 13  // Vermelho
#define LED3 11  // Verde
#define BUTTON 5 // Botão

volatile bool pode_acionar = true; // Controle para permitir novo acionamento

// Callback para desligar o terceiro LED
int desligar_led3_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED3, 0);
    pode_acionar = true; // Libera o botão para novo acionamento
    return 0;
}

// Callback para desligar o segundo LED
int desligar_led2_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED2, 0);
    add_alarm_in_ms(3000, desligar_led3_callback, NULL, false);
    return 0;
}

// Callback para desligar o primeiro LED
int desligar_led1_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED1, 0);
    add_alarm_in_ms(3000, desligar_led2_callback, NULL, false);
    return 0;
}

// Interrupção do botão
void button_callback(uint gpio, uint32_t events) {
    if (!pode_acionar) return; // Bloqueia se o ciclo ainda estiver rodando
    
    pode_acionar = false; // Bloqueia novas ativações

    // Liga os LEDs
    gpio_put(LED1, 1);
    gpio_put(LED2, 1);
    gpio_put(LED3, 1);

    // Inicia a sequência de desligamento com delay de 3s
    add_alarm_in_ms(3000, desligar_led1_callback, NULL, false);
}

int main() {
    stdio_init_all();

    // Configura os LEDs como saída
    gpio_init(LED1);
    gpio_init(LED2);
    gpio_init(LED3);
    gpio_set_dir(LED1, GPIO_OUT);
    gpio_set_dir(LED2, GPIO_OUT);
    gpio_set_dir(LED3, GPIO_OUT);

    // Configura o botão como entrada com pull-up interno
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    // Ativa a interrupção para detectar borda de descida (pressionado)
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (1) {
        sleep_ms(1000); // Apenas para manter o loop ativo
    }

    return 0;
}
