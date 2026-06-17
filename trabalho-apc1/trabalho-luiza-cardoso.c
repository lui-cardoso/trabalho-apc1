#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    #define TAM 10

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

            while (1) { 
                puts("Ano:");               
                if (scanf("%d", &filmes[qtd_atual].ano) != 1) {
                    printf("Erro: Número inválido. Tente de novo.\n\n");
                    while(getchar() != '\n');
                    continue;
                }
                if (filmes[qtd_atual].ano < 0) {
                    printf("Erro: Insira um ano válido.\n\n");
                    continue;
                } break;
            }
            
            while (1) {
                puts("Estrelas (1 - 5):"); 
                scanf("%d", &filmes[qtd_atual].estrelas);
                
                if (filmes[qtd_atual].estrelas < 1 || filmes[qtd_atual].estrelas > 5) {
                    printf("Erro: Insira um valor entre 1 e 5\n\n");
                    while(getchar() != '\n');
                    continue;
                } break;
                printf("\n");
            }

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
        } else {
            while (1) {
                printf("Digite o número do filme que deseja editar (1 a %d):\n", qtd_atual);
                if (scanf("%d", &num_user) != 1) {
                    printf("Erro: Insira um número válido.\n\n");
                    while(getchar() != '\n');
                    continue;
                } break;
            }

        num_real = num_user - 1; // converte para o indice real do filme dentro do array

        if (num_real >= qtd_atual || num_real < 0) {
            printf("Opção inválida. Não existe um filme com o número %d\n", num_user);

            } else { 

                char titulo_novo[51];
                int ano_novo, estrelas_novo;

                printf("Insira os dados do Filme %d\n", num_user);
                printf("Título:\n");
                scanf("%s", titulo_novo);
                while(getchar() != '\n');

                while (1) {
                    puts("Ano:");
                    if (scanf("%d", &ano_novo) != 1) {
                        printf("Erro: Insira um número válido.\n\n");
                        while(getchar() != '\n');
                        continue;
                        }
                    if (ano_novo < 0) {
                        printf("Erro: Insira um ano válido.\n\n");
                        continue;
                    } break;
                } 

                while (1) {
                    puts("Estrelas (1 - 5):");
                    scanf("%d", &estrelas_novo);
                    if (estrelas_novo < 1 || estrelas_novo > 5) {
                        printf("Erro: Insira um valor de 1 a 5.\n\n");
                        while(getchar() != '\n');
                        continue;
                    } break;
                }

                strcpy(filmes[num_real].titulo, titulo_novo);
                filmes[num_real].ano = ano_novo;
                filmes[num_real].estrelas = estrelas_novo;

                printf("\n");
                printf("Filme %d\n", num_user);
                printf("Título: %s\n", filmes[num_real].titulo);
                printf("Ano: %d\n", filmes[num_real].ano);
                printf("Estrelas: %d\n\n", filmes[num_real].estrelas);
                printf("Filme editado com sucesso!\n\n");
                }
            }
        } else if (opcao == 4) {

            // ================== BUSCAR FILME =========================

            int num_user, num_real;

            if (qtd_atual == 0) {
                printf("Nenhum filme cadastrado!\n");
            } else {
                while (1) {
                    printf("Digite o número do filme que deseja buscar (1 - %d): ", qtd_atual);
                    if (scanf("%d", &num_user) != 1) {
                        printf("Erro: Insira um número válido.\n\n");
                        while(getchar() != '\n');
                        continue;
                    } break;
                }

                num_real = num_user - 1; // converte para o indice real do filme dentro do array

                if (num_real < 0 || num_real >= qtd_atual) {
                    printf("Não existe um filme com o número %d\n", num_user);
                } else {
                    printf("Filme %d\n", num_user);
                    printf("Título: %s\n", filmes[num_real].titulo);
                    printf("Ano: %d\n", filmes[num_real].ano);
                    printf("Estrelas: %d\n\n", filmes[num_real].estrelas);
                }
            }
        } else if (opcao == 5){

            // ================== DELETAR FILME =======================

            int num_user, num_real;

            if (qtd_atual == 0) {
                printf("Não há filmes cadastrados para remover.\n");
            } else {
                printf("Digite o número do filme que deseja remover: ");
                scanf("%d", &num_user);
                while(getchar() != '\n');

                num_real = num_user - 1; // converte para o indice real do filme dentro do array

                if (num_real < 0 || num_real >= qtd_atual) {
                    printf("Opção inválida! Tente de novo.");

                } else {
                for (int i = num_real; i < qtd_atual - 1; i++) {
                    filmes[i] = filmes[i+1];
                    } 
                }

                qtd_atual--; // decrementa quantidade de filmes
                printf("\n");
                printf("Filme %d removido com sucesso!\n", num_user);
            }
        } else if (opcao < 1 || opcao > 6) {
            printf("Opção inválida! Tente de novo\n");
        }
    } while (opcao !=6);

    if (opcao == 6) {
        printf("Encerrando. Até a próxima! (^o^)/\n");
    }
    
    return 0;
}