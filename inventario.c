#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constante para o tamanho máximo do inventário (Requisito: até 10 itens)
#define MAX_ITENS 10

// Requisito: Criação da struct Item
// A struct armazena o nome, tipo e quantidade de um item.
typedef struct {
    char nome[30];      // Nome do item (máximo 29 caracteres + \0)
    char tipo[20];      // Tipo do item (ex: arma, munição, cura)
    int quantidade;     // Quantidade do item
} Item;

// Variáveis globais para o inventário e o contador de itens
Item mochila[MAX_ITENS];
int total_itens = 0;

// Protótipos das funções obrigatórias
void inserirItem();
void removerItem();
void listarItens();
void buscarItem();

// Funções auxiliares para usabilidade e robustez
void limpar_buffer();
void limpar_nova_linha(char *str);
void exibir_menu();

// Implementação das funções auxiliares

// Função para limpar o buffer de entrada após scanf
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para limpar o caractere de nova linha do fgets
void limpar_nova_linha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Função para exibir o menu de opções
void exibir_menu() {
    printf("\n--- Mochila de Loot ---\n");
    printf("1. Cadastrar novo item\n");
    printf("2. Remover item\n");
    printf("3. Listar todos os itens\n");
    printf("4. Buscar item por nome\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

// Implementação das funções principais

// Requisito: Listar Itens
// Lista todos os itens registrados na mochila com seus dados.
void listarItens() {
    int i;
    printf("\n--- Inventário Atual (Total: %d/%d) ---\n", total_itens, MAX_ITENS);

    if (total_itens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    // Formatação clara para exibição dos dados (Requisito: Usabilidade)
    printf("+------------------------------+--------------------+------------+\n");
    printf("| Nome do Item                 | Tipo               | Quantidade |\n");
    printf("+------------------------------+--------------------+------------+\n");

    for (i = 0; i < total_itens; i++) {
        printf("| %-28s | %-18s | %10d |\n", 
               mochila[i].nome, 
               mochila[i].tipo, 
               mochila[i].quantidade);
    }
    
    printf("+------------------------------+--------------------+------------+\n");
}

// Requisito: Inserir Item
// Permite que o jogador cadastre um novo item na mochila.
void inserirItem() {
    if (total_itens >= MAX_ITENS) {
        printf("\n[ERRO] A mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n--- Cadastro de Novo Item ---\n");

    // Entrada do Nome (Requisito: Leitura de dados com fgets)
    printf("  Nome do Item (máx. 29 caracteres): ");
    if (fgets(mochila[total_itens].nome, sizeof(mochila[total_itens].nome), stdin) == NULL) {
        printf("[ERRO] Falha na leitura do nome.\n");
        return;
    }
    limpar_nova_linha(mochila[total_itens].nome);

    // Entrada do Tipo
    printf("  Tipo do Item (ex: arma, munição, cura, máx. 19 caracteres): ");
    if (fgets(mochila[total_itens].tipo, sizeof(mochila[total_itens].tipo), stdin) == NULL) {
        printf("[ERRO] Falha na leitura do tipo.\n");
        return;
    }
    limpar_nova_linha(mochila[total_itens].tipo);

    // Entrada da Quantidade (Requisito: Leitura de dados com scanf)
    printf("  Quantidade: ");
    if (scanf("%d", &mochila[total_itens].quantidade) != 1) {
        printf("[ERRO] Entrada de quantidade inválida.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer(); // Limpa o buffer após a leitura do inteiro

    total_itens++;
    printf("\n[SUCESSO] Item '%s' adicionado à mochila.\n", mochila[total_itens - 1].nome);
    listarItens(); // Requisito: Listagem após cada operação
}

// Requisito: Busca Sequencial
// Localiza um item na mochila com base no nome e exibe seus dados.
int buscarItemPorNome(const char *nome_busca) {
    int i;
    for (i = 0; i < total_itens; i++) {
        // Compara o nome do item na mochila com o nome de busca (case-sensitive, para simplificar)
        if (strcmp(mochila[i].nome, nome_busca) == 0) {
            return i; // Retorna o índice do item encontrado
        }
    }
    return -1; // Retorna -1 se o item não for encontrado
}

void buscarItem() {
    char nome_busca[30];
    int indice;

    if (total_itens == 0) {
        printf("\n[INFO] A mochila está vazia. Nada para buscar.\n");
        return;
    }

    printf("\n--- Busca de Item ---\n");
    printf("  Digite o nome do item que deseja buscar: ");
    
    if (fgets(nome_busca, sizeof(nome_busca), stdin) == NULL) {
        printf("[ERRO] Falha na leitura do nome.\n");
        return;
    }
    limpar_nova_linha(nome_busca);

    indice = buscarItemPorNome(nome_busca);

    if (indice != -1) {
        printf("\n[SUCESSO] Item encontrado:\n");
        printf("  Nome: %s\n", mochila[indice].nome);
        printf("  Tipo: %s\n", mochila[indice].tipo);
        printf("  Quantidade: %d\n", mochila[indice].quantidade);
    } else {
        printf("\n[INFO] Item '%s' não encontrado na mochila.\n", nome_busca);
    }
}

// Requisito: Remoção de Itens
// Permite que o jogador exclua um item da mochila, informando seu nome.
void removerItem() {
    char nome_remover[30];
    int indice, i;

    if (total_itens == 0) {
        printf("\n[INFO] A mochila está vazia. Nada para remover.\n");
        return;
    }

    printf("\n--- Remoção de Item ---\n");
    printf("  Digite o nome do item que deseja remover: ");
    
    if (fgets(nome_remover, sizeof(nome_remover), stdin) == NULL) {
        printf("[ERRO] Falha na leitura do nome.\n");
        return;
    }
    limpar_nova_linha(nome_remover);

    indice = buscarItemPorNome(nome_remover);

    if (indice != -1) {
        // Desloca os itens subsequentes para preencher o espaço (simulação de remoção em lista sequencial)
        for (i = indice; i < total_itens - 1; i++) {
            mochila[i] = mochila[i + 1];
        }
        total_itens--;
        printf("\n[SUCESSO] Item '%s' removido da mochila.\n", nome_remover);
        listarItens(); // Requisito: Listagem após cada operação
    } else {
        printf("\n[INFO] Item '%s' não encontrado na mochila. Nenhuma remoção realizada.\n", nome_remover);
    }
}

// Função principal
int main() {
    int opcao;
    
    // Requisito: Usabilidade - Interface do sistema clara e orientativa
    printf("Bem-vindo ao Sistema de Inventário da Mochila de Loot!\n");

    do {
        exibir_menu();
        
        // Leitura da opção do menu
        if (scanf("%d", &opcao) != 1) {
            printf("\n[ERRO] Opção inválida. Por favor, digite um número.\n");
            limpar_buffer();
            opcao = 0; // Força a repetição do loop
            continue;
        }
        limpar_buffer(); // Limpa o buffer após a leitura do inteiro

        // Fluxo de execução
        switch (opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 5:
                printf("\n[INFO] Salvando inventário e saindo do jogo. Até a próxima!\n");
                break;
            default:
                printf("\n[ERRO] Opção desconhecida. Por favor, escolha uma opção de 1 a 5.\n");
                break;
        }
        
        // Requisito: Desempenho - O sistema deve responder rapidamente.
        // O loop é simples e as operações são diretas, garantindo o requisito de tempo de resposta.

    } while (opcao != 5);

    return 0;
}
