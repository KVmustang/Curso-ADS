#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constante para o tamanho da fila de peças (Requisito: número fixo de elementos, ex: 5)
#define TAMANHO_FILA 5

// Requisito: Atributos das peças
// Struct para representar uma peça do jogo
typedef struct {
    char nome;  // Tipo da peça ('I', 'O', 'T', 'L', etc.)
    int id;     // Identificador numérico único
} Peca;

// Estrutura para a Fila Circular
typedef struct {
    Peca itens[TAMANHO_FILA]; // Vetor de structs para armazenar as peças
    int frente;               // Índice da frente da fila (dequeue)
    int tras;                 // Índice da traseira da fila (enqueue)
    int contador;             // Número atual de elementos na fila
} FilaPecas;

// Variável global para o ID da próxima peça a ser criada
int proximo_id = 0;

// Protótipos das funções
void inicializarFila(FilaPecas *fila);
int filaVazia(FilaPecas *fila);
int filaCheia(FilaPecas *fila);
Peca gerarPeca();
void enqueue(FilaPecas *fila, Peca nova_peca);
Peca dequeue(FilaPecas *fila);
void exibirFila(FilaPecas *fila);
void exibirMenu();
void limpar_buffer();

// Implementação das funções auxiliares (serão detalhadas na próxima fase)

// Função para limpar o buffer de entrada após scanf
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\n--- Tetris Stack: Fila de Peças Futuras ---\n");
    printf("Código\tAção\n");
    printf("1\tJogar peça (dequeue)\n");
    printf("2\tInserir nova peça (enqueue)\n");
    printf("0\tSair\n");
    printf("Escolha uma opção: ");
}

// Implementação das funções principais (serão detalhadas na próxima fase)

// Inicializa a fila
void inicializarFila(FilaPecas *fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->contador = 0;
}

// Verifica se a fila está vazia
int filaVazia(FilaPecas *fila) {
    return fila->contador == 0;
}

// Verifica se a fila está cheia
int filaCheia(FilaPecas *fila) {
    return fila->contador == TAMANHO_FILA;
}

// Requisito: As peças são geradas automaticamente
// Gera uma nova peça com um tipo aleatório e um ID único
Peca gerarPeca() {
    Peca nova_peca;
    char tipos[] = {'I', 'O', 'T', 'L', 'J', 'S', 'Z'}; // Tipos comuns de peças de Tetris
    int num_tipos = sizeof(tipos) / sizeof(tipos[0]);
    
    // Inicializa o gerador de números aleatórios (apenas na primeira vez)
    if (proximo_id == 0) {
        srand(time(NULL));
    }

    // Atribui um tipo aleatório
    nova_peca.nome = tipos[rand() % num_tipos];
    
    // Atribui o ID único e incrementa
    nova_peca.id = proximo_id++;
    
    return nova_peca;
}

// Requisito: Inserir nova peça ao final da fila (enqueue)
void enqueue(FilaPecas *fila, Peca nova_peca) {
    if (filaCheia(fila)) {
        printf("\n[ERRO] Fila cheia! Não é possível adicionar mais peças.\n");
        return;
    }

    // Lógica da Fila Circular: avança o índice da traseira
    fila->tras = (fila->tras + 1) % TAMANHO_FILA;
    fila->itens[fila->tras] = nova_peca;
    fila->contador++;
    
    printf("\n[SUCESSO] Peça %c (ID: %d) adicionada à fila.\n", nova_peca.nome, nova_peca.id);
}

// Requisito: Jogar uma peça, isto é, remove a peça da frente da fila (dequeue)
Peca dequeue(FilaPecas *fila) {
    Peca peca_removida = {'\0', -1}; // Peça nula para erro

    if (filaVazia(fila)) {
        printf("\n[ERRO] Fila vazia! Nenhuma peça para jogar.\n");
        return peca_removida;
    }

    peca_removida = fila->itens[fila->frente];
    
    // Lógica da Fila Circular: avança o índice da frente
    fila->frente = (fila->frente + 1) % TAMANHO_FILA;
    fila->contador--;
    
    printf("\n[SUCESSO] Peça %c (ID: %d) jogada (removida da frente).\n", peca_removida.nome, peca_removida.id);
    return peca_removida;
}

// Requisito: Exibir o estado atual da fila após cada ação
void exibirFila(FilaPecas *fila) {
    int i, j;
    
    printf("\n--- Fila de Peças Futuras (Tamanho: %d/%d) ---\n", fila->contador, TAMANHO_FILA);

    if (filaVazia(fila)) {
        printf("[VAZIA]\n");
        return;
    }

    printf("Fila de peças\n");
    
    // Exibe os elementos da fila na ordem correta (da frente para a traseira)
    for (i = 0; i < fila->contador; i++) {
        j = (fila->frente + i) % TAMANHO_FILA;
        printf("[%c %d] ", fila->itens[j].nome, fila->itens[j].id);
    }
    printf("\n");
    printf("Tabela: Visualização da fila de peças.\n");
}

// Função principal
int main() {
    FilaPecas fila;
    int opcao;
    Peca peca_jogada;

    // Inicializa a fila e preenche com as 5 peças iniciais
    inicializarFila(&fila);
    
    // Requisito: Inicializar a fila de peças com um número fixo de elementos (5)
    printf("Inicializando a fila de peças com %d elementos...\n", TAMANHO_FILA);
    for (int i = 0; i < TAMANHO_FILA; i++) {
        enqueue(&fila, gerarPeca());
    }
    
    exibirFila(&fila);

    do {
        exibirMenu();
        
        // Leitura da opção do menu
        if (scanf("%d", &opcao) != 1) {
            printf("\n[ERRO] Opção inválida. Por favor, digite um número.\n");
            limpar_buffer();
            opcao = -1; // Força a repetição do loop
            continue;
        }
        limpar_buffer(); // Limpa o buffer após a leitura do inteiro

        // Fluxo de execução
        switch (opcao) {
            case 1: // Jogar peça (dequeue)
                peca_jogada = dequeue(&fila);
                if (peca_jogada.id != -1) {
                    // A peça jogada não é usada neste simulador, mas a operação é realizada.
                    // Requisito: Exibir o estado atual da fila após cada ação
                    exibirFila(&fila);
                }
                break;
            case 2: // Inserir nova peça (enqueue)
                enqueue(&fila, gerarPeca());
                // Requisito: Exibir o estado atual da fila após cada ação
                exibirFila(&fila);
                break;
            case 0: // Sair
                printf("\n[INFO] Encerrando o simulador de fila de peças. Até a próxima!\n");
                break;
            default:
                printf("\n[ERRO] Opção desconhecida. Por favor, escolha uma opção válida.\n");
                break;
        }
        
        // Requisito: Usabilidade - a saída do programa deve ser clara e fácil de entender.

    } while (opcao != 0);

    return 0;
}
