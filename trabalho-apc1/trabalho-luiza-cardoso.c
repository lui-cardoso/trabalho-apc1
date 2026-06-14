#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    #define TAM 2

    // scanf com espaços %N[^\n]s
    // while(getchar() != '\n');

    // printf("-- REGISTRO DE FILMES --\n\n");
    // printf("1 - Cadastrar Filmes\n");
    // printf("2 - Listar registros\n");
    // printf("3 - Buscar registro\n");
    // printf("4 - Atualizar registro\n\n");
    // printf("Selecione uma opção: \n");

    struct filme_t {
        char titulo[51];
        int ano;
        int estrelas;
    }filme;

    struct filme_t filmes[TAM];

    //CADASTRO

    for(int i=0; i<TAM; i++){
        printf("Insira os dados do Filme %d:\n", i+1);
        
        puts("Título:");
        scanf("[^\n]s", filmes[i].titulo);
        while(getchar() != '\n');

        puts("Ano:");
        scanf("%d", &filmes[i].ano);
        while(getchar() != '\n');

        puts("Estrelas (1 a 5):");
        scanf("%d", &filmes[i].estrelas);
        while(getchar() != '\n');
    }
    printf("\n");

    //EXIBIR LISTA
    printf("----- SEUS FILMES -----\n");
    for(int i=0; i<TAM; i++){
        printf("Filme %d\n", i+1);
        printf("Título: %s\n", filmes[i].titulo);
        printf("Ano: %d\n", filmes[i].ano);
        printf("Estrelas: %d\n\n", filmes[i].estrelas);
    }


    return 0;
}