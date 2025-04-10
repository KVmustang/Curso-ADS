#include <stdio.h>

int main() {
    // Carta 1
    char codigo1[4];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1, superPoder1;

    // Carta 2
    char codigo2[4];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2, superPoder2;

    // Entrada carta 1
    printf("Cadastro da Carta 1\n");
    printf("Código (ex: A01): ");
    scanf("%s", codigo1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos carta 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = pib1 * 1000000000 / populacao1;
    superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0 / densidade1);

    // Entrada carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Código (ex: B02): ");
    scanf("%s", codigo2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = pib2 * 1000000000 / populacao2;
    superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0 / densidade2);

    // Exibição
    printf("\n=== Comparação das Cartas ===\n");

    printf("\nPopulação: %s vence\n", (populacao1 > populacao2 ? "Carta 1" : "Carta 2"));
    printf("Área: %s vence\n", (area1 > area2 ? "Carta 1" : "Carta 2"));
    printf("PIB: %s vence\n", (pib1 > pib2 ? "Carta 1" : "Carta 2"));
    printf("Pontos Turísticos: %s vence\n", (pontosTuristicos1 > pontosTuristicos2 ? "Carta 1" : "Carta 2"));
    printf("Densidade Populacional: %s vence\n", (densidade1 < densidade2 ? "Carta 1" : "Carta 2")); // menor vence
    printf("PIB per Capita: %s vence\n", (pibPerCapita1 > pibPerCapita2 ? "Carta 1" : "Carta 2"));
    printf("Super Poder: %s vence\n", (superPoder1 > superPoder2 ? "Carta 1" : "Carta 2"));

    // Valores dos Super Poderes (só para visualização)
    printf("\nSuper Poder Carta 1: %.2f\n", superPoder1);
    printf("Super Poder Carta 2: %.2f\n", superPoder2);

    return 0;
}
