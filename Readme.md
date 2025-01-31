Resumo do código:
Este código implementa um controle de semáforo utilizando um Raspberry Pi Pico, com três LEDs (vermelho, amarelo e verde) que alternam de acordo com um temporizador repetitivo.

Definições de pinos: Os botões e LEDs são mapeados para pinos específicos do Pico. O LED vermelho está no pino 13, o LED verde no pino 11 e o LED amarelo no pino 12.
Função repeating_timer_callback: Controla a alternância entre os LEDs, ligando um de cada vez em sequência a cada 3 segundos. O estado do semáforo é controlado por uma variável estado, que alterna entre 4 valores, e a cada ciclo reinicia.
Função inoutput_init: Configura os pinos dos LEDs como saída.
Função main: Inicializa a comunicação serial e os pinos, cria um temporizador que chama a função de alternância dos LEDs a cada 3 segundos, e entra em um loop principal que imprime uma mensagem a cada segundo.
O código simula um semáforo em que os LEDs alternam em intervalos fixos, controlados por um temporizador repetitivo.
