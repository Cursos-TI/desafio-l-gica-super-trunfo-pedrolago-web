#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura da carta
struct Carta {
    char estado[3];
    char codigo[4];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

// Função para exibir o menu
void exibirMenu() {
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("0 - Sair\n");
    printf("Digite sua opção: ");
}

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *carta, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero);
    printf("Estado (sigla): ");
    scanf("%2s", carta->estado);
    printf("Código da carta (3 letras): ");
    scanf("%3s", carta->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->cidade);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (bilhões): ");
    scanf("%f", &carta->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

int main() {
    struct Carta carta1, carta2;
    int opcao;
    char continuar;
    
    // Cadastro das duas cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Cálculos para as cartas
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 0:
                printf("Saindo do programa...\n");
                break;
                
            case 1: // População
                printf("\n--- Comparação por POPULAÇÃO ---\n");
                printf("Carta 1 - %s (%s): %d habitantes\n", 
                       carta1.cidade, carta1.estado, carta1.populacao);
                printf("Carta 2 - %s (%s): %d habitantes\n", 
                       carta2.cidade, carta2.estado, carta2.populacao);
                
                if(carta1.populacao > carta2.populacao) {
                    printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
                } 
                else if(carta2.populacao > carta1.populacao) {
                    printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
                }
                else {
                    printf("\nResultado: Empate!\n");
                }
                break;
                
            case 2: // Área
                printf("\n--- Comparação por ÁREA ---\n");
                printf("Carta 1 - %s (%s): %.2f km²\n", 
                       carta1.cidade, carta1.estado, carta1.area);
                printf("Carta 2 - %s (%s): %.2f km²\n", 
                       carta2.cidade, carta2.estado, carta2.area);
                
                if(carta1.area > carta2.area) {
                    printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
                } 
                else if(carta2.area > carta1.area) {
                    printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
                }
                else {
                    printf("\nResultado: Empate!\n");
                }
                break;
                
            case 3: // PIB
                printf("\n--- Comparação por PIB ---\n");
                printf("Carta 1 - %s (%s): %.2f bilhões\n", 
                       carta1.cidade, carta1.estado, carta1.pib);
                printf("Carta 2 - %s (%s): %.2f bilhões\n", 
                       carta2.cidade, carta2.estado, carta2.pib);
                
                if(carta1.pib > carta2.pib) {
                    printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
                } 
                else if(carta2.pib > carta1.pib) {
                    printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
                }
                else {
                    printf("\nResultado: Empate!\n");
                }
                break;
                
            case 4: // Pontos Turísticos
                printf("\n--- Comparação por PONTOS TURÍSTICOS ---\n");
                printf("Carta 1 - %s (%s): %d pontos\n", 
                       carta1.cidade, carta1.estado, carta1.pontos_turisticos);
                printf("Carta 2 - %s (%s): %d pontos\n", 
                       carta2.cidade, carta2.estado, carta2.pontos_turisticos);
                
                if(carta1.pontos_turisticos > carta2.pontos_turisticos) {
                    printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
                } 
                else if(carta2.pontos_turisticos > carta1.pontos_turisticos) {
                    printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
                }
                else {
                    printf("\nResultado: Empate!\n");
                }
                break;
                
            case 5: // Densidade Demográfica
                printf("\n--- Comparação por DENSIDADE DEMOGRÁFICA ---\n");
                printf("Carta 1 - %s (%s): %.2f hab/km²\n", 
                       carta1.cidade, carta1.estado, densidade1);
                printf("Carta 2 - %s (%s): %.2f hab/km²\n", 
                       carta2.cidade, carta2.estado, densidade2);
                
                // Regra invertida: menor densidade vence
                if(densidade1 < densidade2) {
                    printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
                } 
                else if(densidade2 < densidade1) {
                    printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
                }
                else {
                    printf("\nResultado: Empate!\n");
                }
                break;
                
            default:
                printf("\nOpção inválida! Por favor, escolha uma opção entre 0 e 5.\n");
                break;
        }
        
        // Perguntar se deseja continuar (apenas se não escolheu sair)
        if(opcao != 0) {
            printf("\nDeseja fazer outra comparação? (s/n): ");
            scanf(" %c", &continuar);
            continuar = tolower(continuar);
        }
        
    } while(opcao != 0 && continuar == 's');
    
    printf("Obrigado por jogar!\n");
    return 0;
}