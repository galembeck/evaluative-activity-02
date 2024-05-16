#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include <unistd.h>

#include <locale.h>

#define max_char 100
#define max_flights 15
#define max_scales 5

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

typedef struct flightData {
    int flight_code, scales_amount;
    char departure_city[max_char], arrival_city[max_char], scales_cities[max_scales][max_char];
} FlightData;



void companyShowcase();

void loginInformation();
void loginPage();

void optionsMenu(int *selected_option);

void includeFlight(FlightData data[], int *flights_count);
void updateFlightInformation(FlightData data[], int flights_count);



int main() {
    setlocale(LC_ALL, "portuguese");

    FlightData data[max_flights];
    int selected_option, flag = 0, flights_count = 0;

    // loginPage();

    do {
        system("cls");

        flag = 0;

        optionsMenu(&selected_option);

        switch(selected_option) {
            case 1:
                includeFlight(data, &flights_count);

                break;
            case 2:
                updateFlightInformation(data, flights_count);

                break;
            case 7:
                system("cls");

                companyShowcase();

                sleep(1);

                printf("\n Obrigado por utilizar os serviços da \"Voe Sempre, Voe Feliz\"!\n");

                exit(0);
            default:
                printf("\n A opção inserida é inválida!");

                system("cls");
                break;
        }
    } while(flag != 1);
}



void companyShowcase() {
   printf("\n                                   |                                ");
   printf("\n                                   |                                ");
   printf("\n                                  _|_                               ");
   printf("\n                                 /___\\                              ");
   printf("\n                                /_____\\                             ");
   printf("\n                               /oo   oo\\                            ");
   printf("\n   \\___________________________\\       /___________________________/");
   printf("\n    `-----------|------|--------\\_____/--------|------|-----------' ");
   printf("\n               ( )    ( )     O|OOo|oOO|O     ( )    ( )");

   printf("\n\n                        \"Voe Sempre, Voe Feliz\"\n\n");
}

void loginInformation() {
    companyShowcase();

    printf("\n Olá! Seja bem-vindo ao sistema de controle de voos e passagens aéreas.");

    printf("\n\n Para acessar o painel de controle da \"Voe Sempre, Voe Feliz\", você deve utilizar o usuário a senha correta.");
    printf("\n Há, ao total, apenas 3 tentativas para efetuar corretamente o login (após, o processo é cancelado).");

    printf("\n\n Informe, nos campos abaixo, o \"usuário\" e a \"senha\" corretos para acessar o painel.\n");
}

void loginPage() {
    char user[max_char];
    int password, trys = 0;

    do {
        loginInformation();

        sleep(1);

        printf("\n º Usuário: ");
        fflush(stdin);
        gets(user);

        printf(" º Senha: ");
        scanf("%d", &password);

        if((strcmp(user, "admin") != 0) && (password != 1234)) {
            trys++;

            printf("\n Usuário e/ou senha incorreto(s)! Restam-lhe %d tentativas...\n\n", 3-trys);

            sleep(1);
            system("pause");
            system("cls");
        }

        if(trys == 3) {
            companyShowcase();

            sleep(1);

            printf("\n Que pena! Sua tentativas de login se esgotaram :(");
            printf("\n Parece que você não conseguiu acessar o painel de controle...\n");

            sleep(1);

            exit(0);
        }
    } while((strcmp(user, "admin") != 0) && (password != 1234));

    sleep(1);

    printf("\n Carregando");

    sleep(1);
    printf(" .");
    sleep(1);
    printf(" .");
    sleep(1);
    printf(" .\n\n");

    sleep(1);

    system("cls");
}

void optionsMenu(int *selected_option) {
    companyShowcase();

    printf("\n Olá! Seja bem-vindo ao sistema de controle de voos e passagens aéreas.");

    printf("\n\n Abaixo, estão listadas todas as opções disponíveis para serem executadas em nosso sistema.");
    printf("\n Escolha, dentre as opções listadas abaixo (1-7), uma para ser executada a seguir.\n");

    sleep(1);

    printf("\n º Opção 1: Incluir voos;");
    printf("\n º Opção 2: Alterar informações de voo;");
    printf("\n º Opção 3: Apagar voos;");
    printf("\n º Opção 4: Voos partindo de uma cidade de origem;");
    printf("\n º Opção 5: Informações do voo com menor número de escalas (determinada partida e origem);");
    printf("\n º Opção 6: Voos chegando em uma cidade de destino;");
    printf("\n º Opção 7: Sair;");

    sleep(1);
    printf("\n\n Opção: ");
    scanf("%d", selected_option);
}

void includeFlight(FlightData data[], int *flights_count) {
    int i, j;
    int flights_to_include;

    char inclusion_confirmation;

    system("cls");

    do {
        companyShowcase();

        printf("\n Para incluir um voo no sistema, é necessário preencher algumas informações...");

        printf("\n\n Primeiramente, quantos voos serão incluídos no sistema? ");
        scanf("%d", &flights_to_include);

        if((flights_to_include <= 0) || (*flights_count + flights_to_include > max_flights)) {
            printf("\n O número informado de voos a serem incluídos é inválido!\n\n");

            sleep(1);
            system("cls");
        }
    } while((flights_to_include <= 0) || (*flights_count + flights_to_include > max_flights));

    printf("\n Ótimo! Com o número de voos a serem incluídos definido, podemos continuar com o processo.\n\n");

    sleep(1);
    system("pause");
    system("cls");

    FlightData temp_data[max_flights];
    int temp_flights_count = 0;

    for(i = 0; i < flights_to_include; i++) {
        companyShowcase();

        printf("\n Agora, com o número de voos a serem incluídos definido, será necessário preencher alguns campos.");
        printf("\n\n Dentre as informações ncessárias, informe, abaixo, os seguintes dados:");
        printf("\n º Código do voo;");
        printf("\n º Cidade de origem;");
        printf("\n º Cidade de destino;");
        printf("\n º Número de escalas (se houver);");
        printf("\n º Cidades de escala (se houver);\n");

        sleep(1);

        printf("\n Código do %dº voo: ", i+1);
        scanf("%d", &temp_data[temp_flights_count].flight_code);

        printf("\n Cidade de origem do %dº voo: ", i+1);
        fflush(stdin);
        fgets(temp_data[temp_flights_count].departure_city, max_char, stdin);

        printf("\n Cidade de destino do %dº voo: ", i+1);
        fflush(stdin);
        fgets(temp_data[temp_flights_count].arrival_city, max_char, stdin);

        do {
            printf("\n Número de escalas do %dº voo: ", i+1);
            scanf("%d", &temp_data[temp_flights_count].scales_amount);
        } while((temp_data[temp_flights_count].scales_amount < 0) || (temp_data[temp_flights_count].scales_amount > max_scales));

        for(j = 0; j < temp_data[temp_flights_count].scales_amount; j++) {
            printf("\n Cidade da %dº escala do %dº voo: ", j+1, i+1);
            fflush(stdin);
            fgets(temp_data[temp_flights_count].scales_cities[j], max_char, stdin);
        }

        temp_flights_count++;

        system("cls");
    }

    companyShowcase();

    sleep(1);

    printf("\n Ao término da inserção dos dados/informações solicitadas, confirme a inclusão dos seguintes voos: ");

    printf("\n\n Total de voos a serem incluídos: %d voo(s).\n", temp_flights_count);

    for(i = 0; i < temp_flights_count; i++) {
        printf("\n º Código do %dº voo: %d", i+1, temp_data[i].flight_code);
        printf("\n º Cidade de origem do %dº voo: %s", i+1, temp_data[i].departure_city);
        printf(" º Cidade de destino do %dº voo: %s", i+1, temp_data[i].arrival_city);
        printf(" º Número de escalas do %dº voo: %d\n", i+1, temp_data[i].scales_amount);
        if(temp_data[i].scales_amount > 0) {
           printf(" º Cidades de escala do %dº voo:\n", i+1);
            for(j = 0; j < temp_data[i].scales_amount; j++) {
                printf("   | %s", temp_data[i].scales_cities[j]);
            }
        } else {
            printf(" º Cidades de escala do %dº voo: \"NÃO HÁ ESCALAS\"\n", i+1);
        }
    }

    printf("\n Deseja confirmar a inclusão dos voos listados acima? [S/n]: ");

    do {
        fflush(stdin);
        inclusion_confirmation = getchar();
    } while((toupper(inclusion_confirmation) != 'S') && (tolower(inclusion_confirmation) != 'n'));

    if(toupper(inclusion_confirmation) == 'S') {
        for(i = 0; i < temp_flights_count; i++) {
            data[*flights_count] = temp_data[i];
            (*flights_count)++;
        }
        printf("\n Os voos listados foram incluídos com sucesso!\n");
    } else {
        printf("\n A inclusão dos voos listados foi cancelada!\n");
    }

    printf("\n");
    sleep(1);
    system("pause");
}

void updateFlightInformation(FlightData data[], int flights_count) {
    FlightData old_data;
    int update_option, updatable_code, stored_flight = -1, i, j;

    system("cls");

    companyShowcase();

    printf("\n Neste painel, é possível editar as informações de um determinado voo inserido no sistema.");

    printf("\n\n Para que uma alteração/modificação de um voo seja efetivada, é necessário que seu código seja informado.");
    printf("\n Abaixo estão listados todos os códigos dos voos presentes no banco de dados do sistema da \"Voe Sempre, Voe Feliz\".\n");

    if(flights_count > 0) {
        for(i = 0; i < flights_count; i++) {
            printf("\n º Código do %dº voo: %d", i+1, data[i].flight_code);
        }

        printf("\n\n º Código do voo (a ser alterado): ");
        scanf("%d", &updatable_code);

        for(j= 0; j < flights_count; j++) {
            if(data[j].flight_code == updatable_code) {
                stored_flight = j;
                old_data = data[j];
                break;
            }
        }

        if(stored_flight == -1) {
            printf("\n Nenhum voo com código \"%d\" foi encontrado no banco de dados do sistema.\n\n", updatable_code);

            sleep(1);
            system("pause");

            return;
        }

        system("cls");
        companyShowcase();

        printf("\n Atualmente, as informações do voo solicitado/informado são:");
        printf("\n º Código do voo: %d", data[stored_flight].flight_code);
        printf("\n º Cidade de origem: %s", data[stored_flight].departure_city);
        printf(" º Cidade de destino: %s", data[stored_flight].arrival_city);
        printf(" º Número de escalas: %d\n", data[stored_flight].scales_amount);
        if(data[stored_flight].scales_amount > 0) {
            printf(" º Cidades de escala:\n");
            for(j = 0; j < data[stored_flight].scales_amount; j++) {
                printf("   | %s", data[stored_flight].scales_cities[j]);
            }
        } else {
            printf(" º Cidades de escala: \"NÃO HÁ ESCALAS\"\n");
        }

        printf("\n Opções de alterações que podem ser realizadas no banco de dados de voos do sistema da \"Voe Sempre, Voe Feliz\".");
        printf("\n Para realizar alguma alteração/modificação, selecione uma das opções disponíveis abaixo.");

        printf("\n\n º Opção 1: Alterar código do voo;");
        printf("\n º Opção 2: Alterar cidade de origem;");
        printf("\n º Opção 3: Alterar cidade de destino;");
        printf("\n º Opção 4: Alterar número de escalas;");
        printf("\n º Opção 5: Alterar cidades de escala (se houver);");
        printf("\n º Opção 6: Voltar (menu principal);");

        printf("\n\n Opção: ");
        scanf("%d", &update_option);

        sleep(1);
        system("cls");

        companyShowcase();

        printf("\n Alterando as informações listadas para o seguinte voo:");
        printf("\n º Código do voo: %d", data[stored_flight].flight_code);
        printf("\n º Cidade de origem: %s", data[stored_flight].departure_city);
        printf(" º Cidade de destino: %s", data[stored_flight].arrival_city);
        printf(" º Número de escalas: %d\n", data[stored_flight].scales_amount);
        if(data[stored_flight].scales_amount > 0) {
            printf(" º Cidades de escala:\n");
            for(j = 0; j < data[stored_flight].scales_amount; j++) {
                printf("   | %s", data[stored_flight].scales_cities[j]);
            }
        } else {
            printf(" º Cidades de escala: \"NÃO HÁ ESCALAS\"\n");
        }

        switch(update_option) {
            case 1:
                printf("\n Informe o novo código do voo: ");
                scanf("%d", &data[stored_flight].flight_code);
                break;
            case 2:
                printf("\n Informe a nova cidade de origem: ");
                fflush(stdin);
                fgets(data[stored_flight].departure_city, max_char, stdin);
                break;
            case 3:
                printf("\n Informe a nova cidade de destino: ");
                fflush(stdin);
                fgets(data[stored_flight].arrival_city, max_char, stdin);
                break;
            case 4:
                do {
                    printf("\n Informe o novo número de escalas: ");
                    scanf("%d", &data[stored_flight].scales_amount);
                } while((data[stored_flight].scales_amount < 0) || (data[stored_flight].scales_amount > max_scales));
                break;
            case 5:
                if(data[stored_flight].scales_amount > 0) {
                    for(j = 0; j < data[stored_flight].scales_amount; j++) {
                        printf("\n Informe a nova cidade da %dº escala: ", j+1);
                        fflush(stdin);
                        fgets(data[stored_flight].scales_cities[j], max_char, stdin);
                    }
                } else {
                    printf("\n O voo em questão não possui escalas!\n\n");

                    sleep(1);
                    system("pause");
                    return;
                }
                break;
            case 6:
                return;
            default:
                printf("\n A opção escolhida é inválida!\n");

                sleep(1);
                system("pause");

                return;
        }

        sleep(1);

        printf("\n Atualizando informações");

        sleep(1);
        printf(" .");
        sleep(1);
        printf(" .");
        sleep(1);
        printf(" .");

        sleep(1);
        system("cls");

        companyShowcase();

        printf("\n Informações antigas do voo:");
        printf("\n º Código do voo: %d", old_data.flight_code);
        printf("\n º Cidade de origem: %s", old_data.departure_city);
        printf(" º Cidade de destino: %s", old_data.arrival_city);
        printf(" º Número de escalas: %d\n", old_data.scales_amount);
        if(old_data.scales_amount > 0) {
            printf(" º Cidades de escala:\n");
            for(j = 0; j < old_data.scales_amount; j++) {
                printf("   | %s", old_data.scales_cities[j]);
            }
        } else {
            printf(" º Cidades de escala: \"NÃO HÁ ESCALAS\"\n");
        }

        printf("\n Informações atualizadas do voo:");
        printf("\n º Código do voo: %d", data[stored_flight].flight_code);
        printf("\n º Cidade de origem: %s", data[stored_flight].departure_city);
        printf(" º Cidade de destino: %s", data[stored_flight].arrival_city);
        printf(" º Número de escalas: %d\n", data[stored_flight].scales_amount);
        if(data[stored_flight].scales_amount > 0) {
            printf(" º Cidades de escala:\n");
            for(j = 0; j < data[stored_flight].scales_amount; j++) {
                printf("   | %s", data[stored_flight].scales_cities[j]);
            }
        } else {
            printf(" º Cidades de escala: \"NÃO HÁ ESCALAS\"\n");
        }

        printf("\n Informações do voo atualizadas com sucesso!\n\n");
        sleep(1);
        system("pause");
    } else {
        printf("\n\n º Não há nenhum voo inserido no banco de dados do sistema (sem voos para exibir)...\n\n");

        sleep(1);
        system("pause");
        return;
    }
}

