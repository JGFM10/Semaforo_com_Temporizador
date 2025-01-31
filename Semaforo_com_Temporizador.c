#include "pico/stdlib.h" // Biblioteca padrão do Raspberry Pi Pico para controle de GPIO, temporização e comunicação serial.
#include "pico/time.h"   // Biblioteca para gerenciamento de temporizadores e alarmes.

// Definição dos Botões e RGB
#define BUTTON_A 5       // Pino do botão A
#define BUTTON_B 6       // Pino do botão B
#define LED_VERMELHO 13  // Pino do LED Vermelho
#define LED_VERDE 11     // Pino do LED Verde
#define LED_AMARELO 12      // Pino do LED Amarelo

int estado = 0; // Variável de controle do estado do semáforo

// Função de callback para o temporizador repetitivo
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de mudar o estado
    gpio_put(LED_VERMELHO, false);
    gpio_put(LED_VERDE, false);
    gpio_put(LED_AMARELO, false);

    // Controla os estados do semáforo
    if (estado == 0) {
        gpio_put(LED_VERMELHO, true); // Acende o LED Vermelho
    } else if (estado == 1) {
        gpio_put(LED_AMARELO, true); // Acende o LED Verde
    } else if (estado == 2) {
        gpio_put(LED_VERDE, true); // Acende o LED Amarelp
    } else if (estado == 3) {
        gpio_put(LED_AMARELO, true); // Acende o LED Amarelo novamente
    }

    // Alterna para o próximo estado
    estado++;
    if (estado > 3) {
        estado = 0; // Reinicia o ciclo quando atinge o último estado
    }

    // Retorna true para manter o temporizador repetindo esta função
    return true;
}

// Função para configurar os pinos
void inoutput_init() {
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
}

int main() {
    // Inicializa a comunicação serial e os pinos
    stdio_init_all();
    inoutput_init();

    // Declara e configura um temporizador repetitivo
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal do programa
    while (true) {
    sleep_ms(1000);
    printf("Passou 1 Segundo!\n");
    }

    return 0;
}
