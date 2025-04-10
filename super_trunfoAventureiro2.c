#include <stdio.h>
#include <string.h>

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
    int opcao;

    // Cadastro Carta 1
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

    // Cadastro Carta 2
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

    // Menu de comparação
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1 - Comparar População\n");
    printf("2 - Comparar Área\n");
    printf("3 - Comparar PIB\n");
    printf("4 - Comparar Pontos Turísticos\n");
    printf("5 - Comparar Densidade Populacional\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    printf("\nResultado da comparação:\n");

    switch (opcao) {
        case 1:
            if (carta1.populacao > carta2.populacao) {
                printf("Carta 1 venceu com maior população (%d > %d)\n", carta1.populacao, carta2.populacao);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Carta 2 venceu com maior população (%d > %d)\n", carta2.populacao, carta1.populacao);
            } else {
                printf("Empate na população: %d habitantes\n", carta1.populacao);
            }
            break;

        case 2:
            if (carta1.area > carta2.area) {
                printf("Carta 1 venceu com maior área (%.2f > %.2f km²)\n", carta1.area, carta2.area);
            } else if (carta2.area > carta1.area) {
                printf("Carta 2 venceu com maior área (%.2f > %.2f km²)\n", carta2.area, carta1.area);
            } else {
                printf("Empate na área: %.2f km²\n", carta1.area);
            }
            break;

        case 3:
            if (carta1.pib > carta2.pib) {
                printf("Carta 1 venceu com maior PIB (%.2f > %.2f bilhões)\n", carta1.pib, carta2.pib);
            } else if (carta2.pib > carta1.pib) {
                printf("Carta 2 venceu com maior PIB (%.2f > %.2f bilhões)\n", carta2.pib, carta1.pib);
            } else {
                printf("Empate no PIB: %.2f bilhões\n", carta1.pib);
            }
            break;

        case 4:
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Carta 1 venceu com mais pontos turísticos (%d > %d)\n", carta1.pontosTuristicos, carta2.pontosTuristicos);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Carta 2 venceu com mais pontos turísticos (%d > %d)\n", carta2.pontosTuristicos, carta1.pontosTuristicos);
            } else {
                printf("Empate nos pontos turísticos: %d\n", carta1.pontosTuristicos);
            }
            break;

        case 5:
            {
                float dens1 = carta1.populacao / carta1.area;
                float dens2 = carta2.populacao / carta2.area;
                if (dens1 < dens2) {
                    printf("Carta 1 venceu com menor densidade populacional (%.2f < %.2f hab/km²)\n", dens1, dens2);
                } else if (dens2 < dens1) {
                    printf("Carta 2 venceu com menor densidade populacional (%.2f < %.2f hab/km²)\n", dens2, dens1);
                } else {
                    printf("Empate na densidade populacional: %.2f hab/km²\n", dens1);
                }
            }
            break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
