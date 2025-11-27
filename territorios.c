#include <stdio.h>
#include <string.h>

// Requisito: Criação da struct Territorio
// A struct armazena o nome do território, a cor do exército e a quantidade de tropas.
typedef struct {
    char nome[30];  // Nome do território (máximo 29 caracteres + \0)
    char cor[10];   // Cor do exército (máximo 9 caracteres + \0)
    int tropas;     // Quantidade de tropas
} Territorio;

// Constante para o número de territórios a serem cadastrados
#define NUM_TERRITORIOS 5

// Função para limpar o caractere de nova linha do fgets
void limpar_nova_linha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Função para limpar o buffer de entrada após scanf
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Requisito: Declaração de vetor de structs
    // Cria um vetor com capacidade para armazenar 5 estruturas do tipo Territorio.
    Territorio territorios[NUM_TERRITORIOS];
    int i;

    // Requisito: Usabilidade - Interface de entrada clara
    printf("--- Cadastro de Territórios ---\n");
    printf("Por favor, insira os dados para %d territórios.\n\n", NUM_TERRITORIOS);

    // Requisito: Entrada dos dados - Utiliza um laço for para preencher os dados
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Território %d de %d:\n", i + 1, NUM_TERRITORIOS);

        // Entrada do Nome
        printf("  Nome do Território (máx. 29 caracteres): ");
        // Uso de fgets para leitura de string, mais seguro.
        if (fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin) == NULL) {
            printf("Erro na leitura do nome. Encerrando.\n");
            return 1;
        }
        limpar_nova_linha(territorios[i].nome);

        // Entrada da Cor do Exército
        printf("  Cor do Exército (máx. 9 caracteres): ");
        if (fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin) == NULL) {
            printf("Erro na leitura da cor. Encerrando.\n");
            return 1;
        }
        limpar_nova_linha(territorios[i].cor);

        // Entrada da Quantidade de Tropas
        printf("  Quantidade de Tropas: ");
        // Uso de scanf para ler o inteiro.
        if (scanf("%d", &territorios[i].tropas) != 1) {
            printf("Erro na leitura das tropas. Encerrando.\n");
            return 1;
        }
        limpar_buffer(); // Limpa o buffer após a leitura do inteiro

        printf("\n");
    }

    // Requisito: Exibição dos dados - Percorre o vetor e exibe os dados
    printf("--- Dados dos Territórios Cadastrados ---\n");
    printf("+------------------------------+------------+---------+\n");
    printf("| Nome do Território           | Cor Exército | Tropas  |\n");
    printf("+------------------------------+------------+---------+\n");

    for (i = 0; i < NUM_TERRITORIOS; i++) {
        // Formatação clara para exibição dos dados.
        printf("| %-28s | %-10s | %7d |\n", 
               territorios[i].nome, 
               territorios[i].cor, 
               territorios[i].tropas);
    }
    
    printf("+------------------------------+------------+---------+\n");

    // Requisito: Desempenho - O sistema apresenta os dados logo após o cadastro.
    // O código é simples e a exibição é imediata, garantindo o requisito de tempo de resposta.

    return 0;
}
