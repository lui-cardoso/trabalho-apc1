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
    // printf("Selecione uma opção: \n"); //ADD seleçao invalida

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
        scanf("%50[^\n]s", filmes[i].titulo);
        while(getchar() != '\n');

        puts("Ano:");
        scanf("%d", &filmes[i].ano);
        while(getchar() != '\n');

        puts("Estrelas (1 a 5):"); //ADD numero <1 ou >5 invalido
        scanf("%d", &filmes[i].estrelas);
        while(getchar() != '\n');
        printf("\n");
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

    //EDITAR REGISTRO

    int num;
    puts("Digite o número do filme que deseja editar:");
    scanf("%d", &num);
    while(getchar() != '\n');
    int num_edit = num-1; // numero real que será editado
    // ADD if num > TAM é invalido

    char titulo_novo[51];
    int ano_novo, estrelas_novo;

    printf("Insira os dados do filme %d\n", num);
    puts("Título:");
    scanf("%50[^\n]s", &titulo_novo);
    while(getchar() != '\n');

    puts("Ano:");
    scanf("%d", &ano_novo);
    while(getchar() != '\n');

    puts("Estrelas (1 a 5):");
    scanf("%d", &estrelas_novo);
    while(getchar() != '\n');

    strcpy(filmes[num_edit].titulo, titulo_novo);
    filmes[num_edit].ano = ano_novo;
    filmes[num_edit].estrelas = estrelas_novo;

    printf("\n");
    printf("Filme %d\n", num);
    printf("Título: %s\n", filmes[num_edit].titulo);
    printf("Ano: %d\n", filmes[num_edit].ano);
    printf("Estrelas: %d\n\n", filmes[num_edit].estrelas);

    return 0;
}