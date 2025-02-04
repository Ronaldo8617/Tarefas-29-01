#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos GPIOs para os LEDs
#define LED_VERMELHO 13
#define LED_AMARELO  12
#define LED_VERDE    11

// Estado atual do semáforo
volatile int estado_semaforo = 0;

// Callback do temporizador, chamado a cada 3 segundos
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de mudar de estado
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);

    // Alterna o estado do semáforo
    switch (estado_semaforo) {
        case 0:
            gpio_put(LED_VERMELHO, 1); // Vermelho
            break;
        case 1:
            gpio_put(LED_AMARELO, 1);  // Amarelo
            break;
        case 2:
            gpio_put(LED_VERDE, 1);    // Verde
            break;
    }

    // Avança para o próximo estado (cíclico)
    estado_semaforo = (estado_semaforo + 1) % 3;

    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all();

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicializa o temporizador periódico para alternar o semáforo a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal exibindo mensagens a cada segundo
    while (true) {
        printf("Semáforo operando. Estado atual: %d\n", estado_semaforo);
        sleep_ms(1000);
    }

    return 0;
}
