#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "lendarios.h"

#define ARQUIVO_BIBLIOTECA "biblioteca.dat"

int main(void) {
    LivroMagico *biblioteca[TAM_BIBLIOTECA];
    int opcao;
    int id;
    int i;
    int livros_carregados;

    /* Carrega a biblioteca salva anteriormente (se existir) */
    carregarBiblioteca(biblioteca, ARQUIVO_BIBLIOTECA);

    livros_carregados = 0;
    for (i = 0; i < TAM_BIBLIOTECA; i++) {
        if (biblioteca[i] != NULL) {
            livros_carregados++;
        }
    }

    printf("===== BIBLIOTECA MAGICA =====\n");
    if (livros_carregados > 0) {
        printf("Biblioteca carregada com %d livro(s) salvos anteriormente.\n", livros_carregados);
    } else {
        printf("Nenhuma biblioteca salva encontrada. Comecando do zero!\n");
    }

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Deletar livro\n");
        printf("3 - Mostrar livro (buscar por ID)\n");
        printf("4 - Editar livro\n");
        printf("5 - Listar titulos\n");
        printf("6 - Organizar biblioteca (ano/autor/titulo)\n");
        printf("0 - Sair (salva automaticamente)\n");
        printf("=================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            /* limpa entrada invalida (ex: letras) do buffer */
            while (getchar() != '\n');
            printf("Opcao invalida! Digite um numero.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarLivro(biblioteca);
                break;

            case 2:
                printf("Digite o ID do livro a deletar: ");
                scanf("%d", &id);
                deletarLivro(biblioteca, id);
                break;

            case 3:
                printf("Digite o ID do livro: ");
                scanf("%d", &id);
                mostrarLivro(biblioteca, id);
                break;

            case 4:
                printf("Digite o ID do livro a editar: ");
                scanf("%d", &id);
                editarLivro(biblioteca, id);
                break;

            case 5:
                listarTitulos(biblioteca);
                break;

            case 6:
                organizarBiblioteca(biblioteca);
                break;

            case 0:
                printf("Salvando biblioteca... ate a proxima aventura!\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    /* Salva a biblioteca em arquivo antes de encerrar */
    salvarBiblioteca(biblioteca, ARQUIVO_BIBLIOTECA);

    /* Libera toda a memoria alocada antes de encerrar o programa */
    for (i = 0; i < TAM_BIBLIOTECA; i++) {
        if (biblioteca[i] != NULL) {
            free(biblioteca[i]);
            biblioteca[i] = NULL;
        }
    }

    return 0;
}
