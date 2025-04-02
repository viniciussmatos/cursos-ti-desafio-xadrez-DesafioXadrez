#include <stdio.h>

void m_torre(int c, int d){
    if (c > 0) {
        switch (d){
            case 1: printf("Torre - Esquerda\n"); break;
            case 2: printf("Torre - Direta\n"); break;
            case 3: printf("Torre - Cima\n"); break;
            case 4: printf("Torre - Baixo\n"); break;
        }
        m_torre(c - 1, d);
    }
}

void m_bispo(int c, int d){
    if (c > 0) {
        switch (d) {
            case 1: printf("Bispo - Cima/Esquerda\n"); break;
            case 2: printf("Bispo - Cima/Direita\n"); break;
            case 3: printf("Bispo - Baixo/Esquerda\n"); break;
            case 4: printf("Bispo - Baixo/Direita\n"); break;
        }
        m_bispo(c - 1, d);
    }
}

void m_rainha(int c, int d){
    if (c > 0) {
        switch (d) {
            case 1: printf("Rainha - Esquerda\n"); break;
            case 2: printf("Rainha - Direita\n"); break;
            case 3: printf("Rainha - Cima\n"); break;
            case 4: printf("Rainha - Baixo\n"); break;
            case 5: printf("Rainha - Cima/Esquerda\n"); break;
            case 6: printf("Rainha - Cima/Direita\n"); break;
            case 7: printf("Rainha - Baixo/Esquerda\n"); break;
            case 8: printf("Rainha - Baixo/Direita\n"); break;
        }
        m_rainha(c - 1, d);
    }
}

void m_cavalo(int direcao){ 
    
    //Enquanto i for menor que 2 imprime o primeiro movimento (um para 0 e um para 1). Quando atinge 2, imprime o segundo movimento.

    switch (direcao) {
        case 1:
            for (int i = 0; i < 2; i++) {
                printf("Cavalo: Cima\n");
            }
            printf("Cavalo: Esquerda\n\n");
            break;
        case 2:
            for (int i = 0; i < 2; i++) {
                printf("Cavalo: Cima\n");
            }
            printf("Cavalo: Direita\n\n");
            break;
        case 3:
            for (int i = 0; i < 2; i++) {
                printf("Cavalo: Baixo\n");
            }
            printf("Cavalo: Esquerda\n\n");
            break;
        case 4:
            for (int i = 0; i < 2; i++) {
                printf("Cavalo: Baixo\n");
            }
            printf("Cavalo: Direita\n\n");
            break;
        case 5:
            printf("Cavalo: Cima\n");
            for (int i = 0; i < 2; i++) {
                printf("Cavalo: Esquerda\n");
            }
            printf("\n");
            break;
        case 6:
            printf("Cavalo: Cima\n");
            for (int i = 0; i < 2; i++) {
                printf("Cavalo: Direita\n");
            }
            printf("\n");
            break;
        case 7:
            printf("Cavalo: Baixo\n");
            for (int i = 0; i < 2; i++) {
                printf("Cavalo: Esquerda\n");
            }
            printf("\n");
            break;
        case 8:
            printf("Cavalo: Baixo\n");
            for (int i = 0; i < 2; i++) {
                printf("Cavalo: Direita\n");
            }
            printf("\n");
            break;
    }
}

int main(){

    char torre[] = "Torre", bispo[] = "Bispo", rainha[] = "Rainha", cavalo[] = "Cavalo";
    int peca, casas, direcao;
    char* nome_peca;

    printf("** JOGO DE XADREZ **\n\n");

    while(1) { //Loop infito, para permitir ao usuário a movimentação de outra peça, até que ele escolha a opção 5.

        printf("Selecione a peça que deseja movimentar.\n");
        printf("1. %s.\n", torre);
        printf("2. %s.\n", bispo);
        printf("3. %s.\n", rainha);
        printf("4. %s.\n", cavalo);
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &peca);

        //Como coloquei um case para cada movimentação de peça, ficou desnecessária essa variável.
        switch (peca){
            case 1: nome_peca = torre; break;
            case 2: nome_peca = bispo; break;
            case 3: nome_peca = rainha; break;
            case 4: nome_peca = cavalo; break;
            case 5: printf("Saindo...\n"); return 0;
        }

    printf("\n");

        while (peca < 1 || peca > 5){
            printf("Opção inválida. Escolha um número de 1 a 5.\n");
            printf("Escolha: ");
            scanf("%d", &peca);
        }

        // Se a peça não for o cavalo, solicita ao usuário escolher a quantidade de casas que peça movimentará
        if (peca != 4){
            printf("Quantas casas a peça '%s' deve se mover? ", nome_peca);
            scanf("%d", &casas);
        }

    printf("\n");

        switch (peca){
            case 1: 
                printf("Em qual direção você deseja mover a peça '%s' em '%d' casas?\n", nome_peca, casas);
                printf("1. Esquerda.\n");
                printf("2. Direita.\n");
                printf("3. Cima.\n");
                printf("4. Baixo\n");
                printf("Escolha: ");
                scanf("%d", &direcao);
                m_torre(casas, direcao); 
            break;

            case 2: 
                printf("Em qual direção você deseja mover a peça '%s' em '%d' casas?\n", nome_peca, casas);
                printf("1. Cima/Esquerda.\n");
                printf("2. Cima/Direita.\n");
                printf("3. Baixo/Esquerda.\n");
                printf("4. Baixo/Direita\n");
                printf("Escolha: ");
                scanf("%d", &direcao);
                m_bispo(casas, direcao); 
            break;

            case 3: 
                printf("Em qual direção você deseja mover a peça '%s' em '%d' casas?\n", nome_peca, casas);
                printf("1. Esquerda.\n");
                printf("2. Direita.\n");
                printf("3. Cima.\n");
                printf("4. Baixo\n");
                printf("5. Cima/Esquerda\n");
                printf("6. Cima/Direita\n");
                printf("7. Baixo/Esquerda\n");
                printf("8. Baixo/Direita\n");
                printf("Escolha: ");
                scanf("%d", &direcao);
                m_rainha(casas, direcao); 
            break;

            case 4: 
                printf("Em qual direção você deseja mover a peça '%s'?\n", nome_peca);
                printf("1. 2 Cima, 1 Esquerda\n");
                printf("2. 2 Cima, 1 Direita\n");
                printf("3. 2 Baixo, 1 Esquerda\n");
                printf("4. 2 Baixo, 1 Direita\n");
                printf("5. 1 Cima, 2 Esquerda\n");
                printf("6. 1 Cima, 2 Direita\n");
                printf("7. 1 Baixo, 2 Esquerda\n");
                printf("8. 1 Baixo, 2 Direita\n");
                printf("Escolha: ");
                scanf("%d", &direcao);
                m_cavalo(direcao);
            break;

            default:
                printf("Opção inválida.");
        }
    }
}
