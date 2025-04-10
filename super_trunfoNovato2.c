#include <stdio.h>
#include <string.h>

// Definição da estrutura para a carta
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

int main() {
    struct Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1\n");
    printf("Estado (letra A-H): ");
    scanf(" %c", &carta1.estado);
    printf("Código (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Estado (letra A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Código (ex: B02): ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Exibição das Cartas
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões\n", carta1.pib);
    printf("Pontos turísticos: %d\n", carta1.pontosTuristicos);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomeCidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões\n", carta2.pib);
    printf("Pontos turísticos: %d\n", carta2.pontosTuristicos);

    // 🆚 COMPARAÇÃO (aqui você escolhe o atributo fixo a ser comparado)
    printf("\n=== COMPARAÇÃO ===\n");
    printf("Comparando pelo PIB...\n");

    if (carta1.pib > carta2.pib) {
        printf("Carta 1 venceu! (%.2f bilhões vs %.2f bilhões)\n", carta1.pib, carta2.pib);
    } else if (carta2.pib > carta1.pib) {
        printf("Carta 2 venceu! (%.2f bilhões vs %.2f bilhões)\n", carta2.pib, carta1.pib);
    } else {
        printf("Empate! Ambas têm o mesmo PIB: %.2f bilhões\n", carta1.pib);
    }

    return 0;
}
