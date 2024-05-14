#include <stdio.h>
#include <stdlib.h>

#include <locale.h>

/* Atividade Avaliativa (A2) | Engenharia de Computação - Programação de Computadores

    º IDEIA:
    A sua startup foi contrata para desenvolver um projeto para uma empresa de vendas de passagens aéreas “Voe Sempre, Voe Feliz”.

    Inicialmente terá que construir um programa que, trabalhando com ESTRUTURAS E FUNÇÕES, armazene as seguintes informações:
    • Código do voo;
    • Cidade de origem;
    • Cidade de destino;
    • Número de escalas (MÁXIMO 05 ESCALAS);
    • Cidades de escala (quando houver escala);

    º PROJETO:
    Você e seu Time deverão construir um programa que atenda às necessidades da empresa “Voe Sempre, Voe Feliz”.

    O programa deverá ser construído com um menu inicial contendo as seguintes opções:
    1. Incluir voos;
    2. Alterar as informações sobre um determinado voo;
    3. Apagar um voo;
    4. Dada a cidade de origem, determinar quantos voos saem dessa cidade;
    5. Dada a cidade de origem e destino, determinar o voo com menor número de escalas e imprimir todas as informações sobre esse voo;
    6. Dada a cidade de destino, determinar todos os voos com a respectiva cidade de origem que chegam nesse destino;
    7. Sair do sistema;

    º OBSERVAÇÕES:
    1. É proibido trabalhar com variáveis globais;
    2. Todas as opções, com exceção da 7ª. devem ser elaboradas com funções
    3. O Time tem liberdade de como irá construir o projeto, Times que apresentarem o mesmo “Lay-Out” terão suas notas diminuídas.
    4. Durante o desenvolvimento da Atividade os Times deverão considerar a professora como a representante da empresa “Voe Sempre, Voe Feliz”
    e tirar suas dúvidas (menu, o que inserir a mais, como o usuário gostaria do menu principal etc.).
*/

typedef struct flightInformation {
    int flight_code, scales_number;
    char departure_city, arrival_city, scale_city;
} FlightInformation;

void optionsMenu(int *selected_option) {
    system("cls");

    printf("1º opção:");
    printf("2º opção:");
    printf("3º opção:");
    printf("4º opção:");
    printf("5º opção:");
    printf("6º opção:");
    printf("7º opção:");

    //printf("");
    scanf("%d", &selected_option);
}


int main() {
    setlocale(LC_ALL, "portuguese");

    FlightInformation flight;

    // return 0;
    // system("pause");
}
