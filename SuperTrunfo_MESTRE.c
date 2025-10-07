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

// Função para exibir menu de atributos disponíveis
void exibirMenuAtributos(int atributoExcluido) {
    printf("\n=== ESCOLHA DO ATRIBUTO ===\n");
    printf("Atributos disponíveis:\n");
    
    if (atributoExcluido != 1) printf("1 - População\n");
    if (atributoExcluido != 2) printf("2 - Área\n");
    if (atributoExcluido != 3) printf("3 - PIB\n");
    if (atributoExcluido != 4) printf("4 - Número de Pontos Turísticos\n");
    if (atributoExcluido != 5) printf("5 - Densidade Demográfica\n");
    
    printf("Digite o número do atributo: ");
}

// Função para obter valor do atributo com regra de comparação
float obterValorComparacao(struct Carta carta, float densidade, int atributo, int *regraInvertida) {
    *regraInvertida = 0; // 0 = maior vence, 1 = menor vence
    
    switch(atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: 
            *regraInvertida = 1; // Densidade: menor vence
            return densidade;
        default: return 0;
    }
}

// Função para obter nome do atributo
char* obterNomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função para formatar e exibir valor do atributo
void exibirValorAtributo(int atributo, float valor) {
    switch(atributo) {
        case 1: printf("%.0f habitantes", valor); break;
        case 2: printf("%.2f km²", valor); break;
        case 3: printf("%.2f bilhões", valor); break;
        case 4: printf("%.0f pontos", valor); break;
        case 5: printf("%.2f hab/km²", valor); break;
    }
}

// Função para cadastrar carta
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
    int opcao, atributo1, atributo2;
    char continuar;
    
    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Cálculo das densidades
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;
    
    do {
        printf("\n=== COMPARAÇÃO DE CARTAS - DOIS ATRIBUTOS ===\n");
        
        // Escolha do primeiro atributo
        atributo1 = 0;
        while(atributo1 < 1 || atributo1 > 5) {
            exibirMenuAtributos(0);
            scanf("%d", &atributo1);
            
            if(atributo1 < 1 || atributo1 > 5) {
                printf("Opção inválida! Escolha entre 1 e 5.\n");
            }
        }
        
        // Escolha do segundo atributo (excluindo o primeiro)
        atributo2 = 0;
        while(atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
            exibirMenuAtributos(atributo1);
            scanf("%d", &atributo2);
            
            if(atributo2 < 1 || atributo2 > 5) {
                printf("Opção inválida! Escolha entre as opções disponíveis.\n");
            } else if(atributo2 == atributo1) {
                printf("Você já escolheu este atributo! Escolha um diferente.\n");
            }
        }
        
        // Obter valores e regras de comparação
        int regraInvertida1, regraInvertida2;
        float valor1_atrib1 = obterValorComparacao(carta1, densidade1, atributo1, &regraInvertida1);
        float valor2_atrib1 = obterValorComparacao(carta2, densidade2, atributo1, &regraInvertida1);
        float valor1_atrib2 = obterValorComparacao(carta1, densidade1, atributo2, &regraInvertida2);
        float valor2_atrib2 = obterValorComparacao(carta2, densidade2, atributo2, &regraInvertida2);
        
        // Comparação individual dos atributos
        int vitorias_carta1 = 0, vitorias_carta2 = 0;
        
        // Comparação do primeiro atributo usando operador ternário
        if(valor1_atrib1 == valor2_atrib1) {
            // Empate no primeiro atributo
        } else {
            (regraInvertida1 ? (valor1_atrib1 < valor2_atrib1) : (valor1_atrib1 > valor2_atrib1)) 
                ? vitorias_carta1++ : vitorias_carta2++;
        }
        
        // Comparação do segundo atributo usando operador ternário
        if(valor1_atrib2 == valor2_atrib2) {
            // Empate no segundo atributo
        } else {
            (regraInvertida2 ? (valor1_atrib2 < valor2_atrib2) : (valor1_atrib2 > valor2_atrib2)) 
                ? vitorias_carta1++ : vitorias_carta2++;
        }
        
        // Cálculo das somas (considerando regras invertidas para densidade)
        float soma_carta1, soma_carta2;
        
        // Para atributos com regra normal: maior é melhor, usamos o valor normal
        // Para densidade (regra invertida): menor é melhor, usamos o inverso para a soma
        if(regraInvertida1) {
            soma_carta1 = (1.0/valor1_atrib1) + (regraInvertida2 ? (1.0/valor1_atrib2) : valor1_atrib2);
            soma_carta2 = (1.0/valor2_atrib1) + (regraInvertida2 ? (1.0/valor2_atrib2) : valor2_atrib2);
        } else {
            soma_carta1 = valor1_atrib1 + (regraInvertida2 ? (1.0/valor1_atrib2) : valor1_atrib2);
            soma_carta2 = valor2_atrib1 + (regraInvertida2 ? (1.0/valor2_atrib2) : valor2_atrib2);
        }
        
        // Exibição dos resultados
        printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
        printf("Atributos escolhidos: %s e %s\n", 
               obterNomeAtributo(atributo1), obterNomeAtributo(atributo2));
        
        printf("\n--- Carta 1: %s (%s) ---\n", carta1.cidade, carta1.estado);
        printf("%s: ", obterNomeAtributo(atributo1));
        exibirValorAtributo(atributo1, valor1_atrib1);
        printf("\n%s: ", obterNomeAtributo(atributo2));
        exibirValorAtributo(atributo2, valor1_atrib2);
        printf("\nSoma dos atributos: %.2f pontos\n", soma_carta1);
        
        printf("\n--- Carta 2: %s (%s) ---\n", carta2.cidade, carta2.estado);
        printf("%s: ", obterNomeAtributo(atributo1));
        exibirValorAtributo(atributo1, valor2_atrib1);
        printf("\n%s: ", obterNomeAtributo(atributo2));
        exibirValorAtributo(atributo2, valor2_atrib2);
        printf("\nSoma dos atributos: %.2f pontos\n", soma_carta2);
        
        printf("\n--- VITÓRIAS POR ATRIBUTO ---\n");
        printf("Carta 1: %d vitória(s)\n", vitorias_carta1);
        printf("Carta 2: %d vitória(s)\n", vitorias_carta2);
        
        // Determinação do vencedor final
        printf("\n=== RESULTADO FINAL ===\n");
        if(soma_carta1 > soma_carta2) {
            printf("🎉 Carta 1 (%s) VENCEU! 🎉\n", carta1.cidade);
        } else if(soma_carta2 > soma_carta1) {
            printf("🎉 Carta 2 (%s) VENCEU! 🎉\n", carta2.cidade);
        } else {
            printf("🤝 EMPATE! As cartas têm soma igual. 🤝\n");
        }
        
        // Opção para continuar
        printf("\nDeseja fazer outra comparação? (s/n): ");
        scanf(" %c", &continuar);
        continuar = tolower(continuar);
        
    } while(continuar == 's');
    
    printf("\nObrigado por jogar Super Trunfo! 👋\n");
    return 0;
}