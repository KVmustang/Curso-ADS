#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Requisito: Structs - Criação de um tipo personalizado (Sala)
// Struct para representar um cômodo da mansão (nó da árvore binária)
typedef struct Sala {
    char nome[50];          // Nome da sala (por exemplo: Sala de estar, Cozinha)
    struct Sala *esquerda;  // Ponteiro para o cômodo à esquerda (filho esquerdo)
    struct Sala *direita;   // Ponteiro para o cômodo à direita (filho direito)
} Sala;

// Protótipos das funções
Sala* criarSala(const char *nome);
void explorarSalas(Sala *sala_atual);
void liberarMapa(Sala *sala);

// Requisito: criarSala() – cria, de forma dinâmica, uma sala com nome.
// Função para criar uma nova sala (nó) com alocação dinâmica (malloc)
Sala* criarSala(const char *nome) {
    // Alocação dinâmica: uso de malloc para criação de nós da árvore.
    Sala *nova_sala = (Sala *)malloc(sizeof(Sala));
    
    if (nova_sala == NULL) {
        perror("Erro ao alocar memória para a sala");
        exit(EXIT_FAILURE);
    }
    
    // Inicializa os campos da nova sala
    strncpy(nova_sala->nome, nome, sizeof(nova_sala->nome) - 1);
    nova_sala->nome[sizeof(nova_sala->nome) - 1] = '\0'; // Garante terminação nula
    nova_sala->esquerda = NULL;
    nova_sala->direita = NULL;
    
    return nova_sala;
}

// Função para liberar a memória alocada para o mapa (percurso pós-ordem)
void liberarMapa(Sala *sala) {
    if (sala != NULL) {
        liberarMapa(sala->esquerda);
        liberarMapa(sala->direita);
        free(sala);
    }
}

// Requisito: explorarSalas() – permite a navegação do jogador pela árvore.
// Requisito: explorarSalas() – permite a navegação do jogador pela árvore.
// Permite a exploração interativa da mansão
void explorarSalas(Sala *sala_atual) {
    char escolha[10];
    
    // Loop de exploração
    while (sala_atual != NULL) {
        printf("\nVocê está em: %s\n", sala_atual->nome);
        
        // Verifica se é um nó-folha (cômodo sem caminhos)
        if (sala_atual->esquerda == NULL && sala_atual->direita == NULL) {
            printf("Fim da linha! Você chegou a um cômodo sem mais caminhos.\n");
            printf("Exploração encerrada.\n");
            return; // Sai da função
        }
        
        // Requisito: Usabilidade - a saída do programa deve ser clara e direta
        printf("Para onde deseja ir? (e: Esquerda, d: Direita, s: Sair): ");
        
        // Leitura da escolha do usuário
        if (scanf("%9s", escolha) != 1) {
            printf("\n[ERRO] Entrada inválida.\n");
            // Limpa o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        
        // Operadores condicionais: controle das decisões do jogador (if, else).
        if (strcmp(escolha, "e") == 0) {
            if (sala_atual->esquerda != NULL) {
                sala_atual = sala_atual->esquerda;
            } else {
                printf("Não há caminho para a Esquerda nesta sala.\n");
            }
        } else if (strcmp(escolha, "d") == 0) {
            if (sala_atual->direita != NULL) {
                sala_atual = sala_atual->direita;
            } else {
                printf("Não há caminho para a Direita nesta sala.\n");
            }
        } else if (strcmp(escolha, "s") == 0) {
            printf("Você decidiu sair da mansão. Exploração encerrada.\n");
            return;
        } else {
            printf("Escolha inválida. Por favor, digite 'e', 'd' ou 's'.\n");
        }
    }
}

// Requisito: main() – monta o mapa inicial e dá início à exploração.
int main() {
    Sala *hall_entrada = NULL;

    // Montagem manual da árvore (Simplificação para o nível novato)
    // Nível 0: Raiz
    hall_entrada = criarSala("Hall de Entrada");

    // Nível 1
    hall_entrada->esquerda = criarSala("Sala de Estar");
    hall_entrada->direita = criarSala("Cozinha");

    // Nível 2
    hall_entrada->esquerda->esquerda = criarSala("Biblioteca");
    hall_entrada->esquerda->direita = criarSala("Sala de Jantar");
    hall_entrada->direita->esquerda = criarSala("Despensa");
    hall_entrada->direita->direita = criarSala("Jardim de Inverno");

    // Nível 3 (Nós-folha)
    hall_entrada->esquerda->esquerda->direita = criarSala("Escritório Secreto"); // Folha
    hall_entrada->esquerda->direita->esquerda = criarSala("Quarto de Hóspedes"); // Folha
    hall_entrada->direita->esquerda->esquerda = criarSala("Porão"); // Folha
    hall_entrada->direita->direita->direita = criarSala("Estufa"); // Folha
    
    // Nível 4 (Nó-folha)
    hall_entrada->esquerda->esquerda->esquerda = criarSala("Corredor Norte");
    hall_entrada->esquerda->esquerda->esquerda->esquerda = criarSala("Quarto Principal"); // Folha

    printf("--- Detective Quest: Mapa da Mansão ---\n");
    printf("O mapa da mansão foi montado com sucesso (Árvore Binária).\n");
    printf("Iniciando a exploração a partir do Hall de Entrada...\n");

    // Inicia a exploração interativa
    explorarSalas(hall_entrada);

    // Libera a memória alocada para a árvore
    liberarMapa(hall_entrada);

    return 0;
}
