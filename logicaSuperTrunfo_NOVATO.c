#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    struct Carta {
        char estado[3];
        char codigo[4];
        char cidade[50];
        int populacao;
        float area;
        float pib;
        int pontos_turisticos;
    };

    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio
    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    printf("Estado (sigla): ");
    scanf("%2s", carta1.estado);
    printf("Código da carta (3 letras): ");
    scanf("%3s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.cidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    printf("\nCadastro da Carta 2:\n");
    printf("Estado (sigla): ");
    scanf("%2s", carta2.estado);
    printf("Código da carta (3 letras): ");
    scanf("%3s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.cidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;
    float pib_per_capita1 = (carta1.pib * 1e9) / carta1.populacao;
    float pib_per_capita2 = (carta2.pib * 1e9) / carta2.populacao;

    printf("\n--- Dados Calculados ---\n");
    printf("Carta 1 - Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("Carta 1 - PIB per capita: R$ %.2f\n", pib_per_capita1);
    printf("Carta 2 - Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("Carta 2 - PIB per capita: R$ %.2f\n", pib_per_capita2);

    const char* atributo = "PIB";
    
    printf("\n--- Comparação de Cartas ---\n");
    printf("Atributo escolhido: %s\n\n", atributo);
    printf("Carta 1 - %s (%s): %.2f bilhões\n", 
           carta1.cidade, carta1.estado, carta1.pib);
    printf("Carta 2 - %s (%s): %.2f bilhões\n", 
           carta2.cidade, carta2.estado, carta2.pib);

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.
    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);
    
    if(carta1.pib > carta2.pib) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    }
    else if(carta2.pib > carta1.pib) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    }
    else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}


    // Declaração das duas cartas
    
    
    // Cadastro da primeira carta
    
    // Cálculos para as cartas
    

    // Lógica de comparação

