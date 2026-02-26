#include <stdio.h>
#include <stdlib.h>

#define MAX_CARTAS 100

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

typedef struct {
    char estado[50];
    char codigo[20];
    char nomeCidade[100];
    int populacao;
    float pib;
    float area;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

float calcularDensidade(int populacao, float area) {
    if (area == 0) return 0;
    return populacao / area;
}

1
float calcularPIBPerCapita(float pib, int populacao) {
    if (populacao == 0) return 0;
    return (pib * 1000000) / populacao;
}


void cadastrarCarta(Carta *c) {
    printf("\n--- Cadastro de Nova Carta ---\n");
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);
    printf("Código: ");
    scanf(" %[^\n]", c->codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c->nomeCidade);
    printf("População: ");
    scanf("%d", &c->populacao);
    printf("PIB (em milhões): ");
    scanf("%f", &c->pib);
    printf("Área (km²): ");
    scanf("%f", &c->area);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c->pontosTuristicos);
    c->densidadePopulacional = calcularDensidade(c->populacao, c->area);
    c->pibPerCapita = calcularPIBPerCapita(c->pib, c->populacao);
    printf("\nCarta cadastrada com sucesso!\n");
}


void exibirCarta(Carta c) {
    printf("\n===== CARTA DA CIDADE =====\n");
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nomeCidade);
    printf("População: %d habitantes\n", c.populacao);
    printf("PIB: %.2f milhões\n", c.pib);
    printf("Área: %.2f km²\n", c.area);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", c.pibPerCapita);
    printf("=============================\n");
}

int main() {
    Carta cartas[MAX_CARTAS];
    int quantidade = 0;
    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Cadastrar nova carta\n");
        printf("2 - Exibir todas as cartas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {

            case 1:
                if (quantidade < MAX_CARTAS) {
                    cadastrarCarta(&cartas[quantidade]);
                    quantidade++;
                } else {
                    printf("Limite de cartas atingido!\n");
                }
                break;

            case 2:
                if (quantidade == 0) {
                    printf("Nenhuma carta cadastrada.\n");
                } else {
                    for (int i = 0; i < quantidade; i++) {
                        exibirCarta(cartas[i]);
                    }
                }
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
