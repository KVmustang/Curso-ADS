#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Funções auxiliares
float calcularDensidade(struct Carta c) {
    return c.populacao / c.area;
}

float calcularPIBperCapita(struct Carta c) {
    return c.pib / c.populacao;
}

// Impressão do menu
void mostrarMenu() {
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("=========================\n");
}

int main() {
    struct Carta carta1, carta2;
    int opcao1, opcao2;

    // Cadastro das cartas
    printf("Cadastro da Carta 1\n");
    printf("Estado (letra A-H): ");
    scanf(" %c", &carta1.estado);
    printf("Código (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    printf("\nCadastro da Carta 2\n");
    printf("Estado (letra A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Código (ex: B02): ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Menu para escolha de dois atributos
    mostrarMenu();
    printf("Escolha o primeiro atributo para comparar (1 a 6): ");
    scanf("%d", &opcao1);
    printf("Escolha o segundo atributo para comparar (1 a 6): ");
    scanf("%d", &opcao2);

    // Função de comparação genérica
    int comparar(int opcao, struct Carta c1, struct Carta c2) {
        float valor1, valor2;

        switch (opcao) {
            case 1: valor1 = c1.populacao; valor2 = c2.populacao; break;
            case 2: valor1 = c1.area; valor2 = c2.area; break;
            case 3: valor1 = c1.pib; valor2 = c2.pib; break;
            case 4: valor1 = c1.pontosTuristicos; valor2 = c2.pontosTuristicos; break;
            case 5: valor1 = calcularDensidade(c1); valor2 = calcularDensidade(c2);
                    return (valor1 < valor2) ? 1 : (valor2 < valor1 ? 2 : 0); // menor vence
            case 6: valor1 = calcularPIBperCapita(c1); valor2 = calcularPIBperCapita(c2); break;
            default: return 0;
        }

        return (valor1 > valor2) ? 1 : (valor2 > valor1 ? 2 : 0); // maior vence
    }

    // Comparar os dois atributos selecionados
    int resultado1 = comparar(opcao1, carta1, carta2);
    int resultado2 = comparar(opcao2, carta1, carta2);

    printf("\nResultado das comparações:\n");

    char* vencedor(int r) {
        return (r == 1) ? "Carta 1" : (r == 2 ? "Carta 2" : "Empate");
    }

    printf("Atributo 1: %s venceu\n", vencedor(resultado1));
    printf("Atributo 2: %s venceu\n", vencedor(resultado2));

    // Decisão final baseada nos dois resultados
    int final = (resultado1 == resultado2) ? resultado1 :
                (resultado1 == 0 || resultado2 == 0) ? (resultado1 != 0 ? resultado1 : resultado2) :
                0; // Empate se cada um venceu um

    printf("\n===> Resultado Final: %s\n", vencedor(final));

    return 0;
}
