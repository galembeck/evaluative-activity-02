#include <stdio.h>
#include <stdlib.h>

#include <locale.h>

#include <unistd.h>

#define max_flights 15
#define scales_maximum 5
#define city_name 100

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
    int flight_code, scales_amount[scales_maximum];
    char arrival_city[city_name], departure_city[city_name], scale_city[city_name];
} FlightInformation;

void introductionMessage() {
    system("cls");

    printf("\n Seja bem-vindo ao sistema de ajuda ao usuário da \"Voe Sempre, Voe Feliz\".");

    printf("\n\n Abaixo, estão listadas todas as opções disponíveis para serem executadas em nosso sistema.");
    printf("\n Escolha, dentre as opções listadas abaixo (1-7), uma para ser executada a seguir.\n");
}

void optionsMenu(int *selected_option) {
    introductionMessage();

    printf("\n Opção 1: Incluir voos;");
    printf("\n Opção 2: Alterar informações de voo;");
    printf("\n Opção 3: Apagar voos;");
    printf("\n Opção 4: Voos partindo de uma cidade de origem;");
    printf("\n Opção 5: Informações do voo com menor número de escalas (determinada partida e origem);");
    printf("\n Opção 6: Voos chegando em uma cidade de destino;");
    printf("\n Opção 7: Sair;");

    printf("\n\n Opção: ");
    scanf("%d", selected_option);
}

void includeFlights(FlightInformation info) {
    int flights;

    system("cls");

    // #TODO: INCLUIR SISTEMA DE VERIFICAÇÃO DA QUANTIDADE DE VOOS A SEREM INCLUIDOS NO SISTEMA.

    do {
        printf("\n Quantos voos você deseja incluir? ");
        scanf("%d", &flights);

        if((flights <= 0) || (flights > max_flights)) {
            printf("\n O número informado de voos a serem incluídos é inválido!\n");

            sleep(2);
            system("cls");
        }
    } while((flights <= 0) || (flights > max_flights));

    printf("\n Informe o código do voo: ");
    scanf("%d", &info.flight_code);

    printf("%d", info.flight_code);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    FlightInformation info;
    int selected_option, flag = 0;

    do {
        flag = 0;

        optionsMenu(&selected_option);

        switch(selected_option) {
            case 1:
                includeFlights(info);

                system("pause");
                break;
            case 2:
                printf("TESTE2");

                break;
            case 3:
                exit(0);
        }
    } while(flag != 1);
}
