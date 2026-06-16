#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    #define TAM 10

    // copia e cola:
    // scanf com espaços %N[^\n]s
    // while(getchar() != '\n');

    struct filme_t {
        char titulo[51];
        int ano;
        int estrelas;
    }filme;

    struct filme_t filmes[TAM];
    int qtd_atual = 0; // filmes cadastrados
    int opcao;

    do {
    printf("\n--- MENU DE FILMES ---\n\n");
    printf("1 - Cadastrar Filmes\n");
    printf("2 - Listar Filmes\n");
    printf("3 - Editar Registro\n");
    printf("4 - Buscar Filme\n");
    printf("5 - Deletar Filme\n");
    printf("6 - Sair\n\n");
    printf("Selecione uma opção: \n"); //ADD seleçao invalida
    scanf("%d", &opcao);
    while(getchar() != '\n');

    if (opcao == 1) {
        if (qtd_atual >= TAM) {
            printf("Não há espaço para mais filmes! (%d/%d)", qtd_atual, TAM);
        } else {

            //=================== CADASTRO =============================

            printf("Insira os dados do Filme %d:\n", qtd_atual + 1);
            puts("Título:");
            scanf("%50[^\n]s", filmes[qtd_atual].titulo);
            while(getchar() != '\n');

            puts("Ano:");
            scanf("%d", &filmes[qtd_atual].ano);
            while(getchar() != '\n');

            puts("Estrelas (1 a 5):"); //ADD numero <1 ou >5 invalido
            scanf("%d", &filmes[qtd_atual].estrelas);
            while(getchar() != '\n');
            printf("\n");

            qtd_atual++;
            printf("Filme cadastrado com sucesso!\n");
            
        }
    } else if (opcao == 2) {

        //===================== EXIBIR LISTA ========================

        if (qtd_atual == 0) {
            printf("Nenhum filme cadastrado!\n");
            } else {
                printf("\n----- SEUS FILMES -----\n");
                for(int i=0; i < qtd_atual; i++){
                printf("Filme %d\n", i+1);
                printf("Título: %s\n", filmes[i].titulo);
                printf("Ano: %d\n", filmes[i].ano);
                printf("Estrelas: %d\n\n", filmes[i].estrelas);
            }
        }
    } else if (opcao == 3) {

        //===================== EDITAR REGISTRO ==========================

        int num_user, num_real;

        if (qtd_atual == 0) {
            printf("Nenhum filme cadastrado!\n");
        }

        printf("Digite o número do filme que deseja editar (1 a %d):\n", qtd_atual);
        scanf("%d", &num_user);
        while(getchar() != '\n');

        num_real = num_user - 1; // converte para o indice real do filme dentro do array

        if (num_real >= qtd_atual || num_real < 0) {
            printf("Opção inválida. Não existe um filme com o número %d\n", num_user);

            } else { 

                char titulo_novo[51];
                int ano_novo, estrelas_novo;

                printf("Insira os dados do filme %d\n", num_user);
                puts("Título:");
                scanf("%50[^\n]s", &titulo_novo);
                while(getchar() != '\n');

                puts("Ano:");
                scanf("%d", &ano_novo);
                while(getchar() != '\n');

                puts("Estrelas (1 a 5):");
                scanf("%d", &estrelas_novo);
                while(getchar() != '\n');

                strcpy(filmes[num_real].titulo, titulo_novo);
                filmes[num_real].ano = ano_novo;
                filmes[num_real].estrelas = estrelas_novo;

                printf("\n");
                printf("Filme %d\n", num_user);
                printf("Título: %s\n", filmes[num_real].titulo);
                printf("Ano: %d\n", filmes[num_real].ano);
                printf("Estrelas: %d\n\n", filmes[num_real].estrelas);

            }
        } else if (opcao == 4){

            // ================== DELETAR FILME =======================
            int num_user, num_real;

            if (qtd_atual == 0) {
                printf("Não há filmes cadastrados para remover.\n");
            }

            printf("Digite o número do filme que deseja remover: ");
            scanf("%d", &num_user);
            while(getchar() != '\n');

            num_real = num_user - 1; // converte para o indice real do filme dentro do array

            for (int i = num_real; i < qtd_atual - 1; i++) {
                filmes[i] = filmes[i+1];
            }

            qtd_atual--; // decrementa quantidade de filmes
            printf("Filme %d removido com sucesso!\n", num_user);

        }
    // ADD OPCAO INVALIDA
    } while (opcao !=6);
    

    return 0;
}