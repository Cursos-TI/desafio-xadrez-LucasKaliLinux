#include <stdio.h>

/*
Desafio de Xadrez - MateCheck - Nível Mestre
Este código explora técnicas avançadas de programação em C para simular movimentos de peças de xadrez,
utilizando recursividade, loops complexos, múltiplas variáveis, condições, break e continue.
*/

void moverTorre(int casasRestantes) {
    // Função recursiva para a Torre movendo para a direita
    if (casasRestantes == 0) return;
    printf("Direita - Casa %d\n", casasRestantes);
    moverTorre(casasRestantes - 1);
}

void moverRainha(int casasRestantes) {
    // Função recursiva para a Rainha movendo para a esquerda
    if (casasRestantes == 0) return;
    printf("Esquerda - Casa %d\n", casasRestantes);
    moverRainha(casasRestantes - 1);
}

void moverBispoRecursivo(int casasRestantes) {
    // Função recursiva para o Bispo com loops aninhados dentro da recursividade
    if (casasRestantes == 0) return;
    
    printf("Cima Direita - Movimento Recursivo Casa %d\n", casasRestantes);

    // Loops aninhados representando o movimento diagonal dentro da recursão
    for (int i = 1; i <= casasRestantes; i++) {
        for (int j = 1; j <= i; j++) {
            printf("Passo Diagonal: Vertical %d, Horizontal %d\n", i, j);
        }
    }
    moverBispoRecursivo(casasRestantes - 1);
}

void moverCavaloComplexo() {
    // Movimento do Cavalo em L: 2 para cima, 1 para a direita
    // Usando loops aninhados com múltiplas variáveis e condições

    const int movimentosVerticais = 2;
    const int movimentosHorizontais = 1;
    
    printf("\nMovimento do Cavalo:\n");

    for (int v = 1, h = 0; v <= movimentosVerticais; v++) {
        printf("Cima - Passo %d\n", v);

        // Dentro de cada movimento vertical, verifica se atingiu o segundo passo
        if (v == movimentosVerticais) {
            while (h < movimentosHorizontais) {
                printf("Direita - Passo %d\n", h + 1);

                // Condição extra para mostrar o uso do continue
                if (h == 0) {
                    printf("Preparando salto final do Cavalo\n");
                    h++;
                    continue; // Continua imediatamente, evitando código abaixo neste loop
                }

                // Apenas uma simulação de condição complexa
                if (h > 1) {
                    printf("Erro: Cavalo não pode passar de 1 casa na horizontal!\n");
                    break;
                }

                h++;
            }
        }
    }
}

int main() {
    const int casasTorre = 5;
    const int casasBispo = 3;
    const int casasRainha = 4;

    // Movimentação da Torre com recursão
    printf("\nMovimento da Torre:\n");
    moverTorre(casasTorre);

    // Movimentação da Rainha com recursão
    printf("\nMovimento da Rainha:\n");
    moverRainha(casasRainha);

    // Movimentação do Bispo com recursão e loops aninhados
    printf("\nMovimento do Bispo:\n");
    moverBispoRecursivo(casasBispo);

    // Movimentação do Cavalo com loops aninhados, múltiplas variáveis e condições
    moverCavaloComplexo();

    return 0;
}
