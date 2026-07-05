
/// Buscar livro pelo ID, mostrar informações, editar e listar títulos

#include "biblioteca.h"

/// Busca um livro pelo ID e mostra suas informações
void mostrarLivro(LivroMagico **biblioteca, int id)
{
    int i;

    /// Percorre toda a biblioteca
    for (i = 0; i < TAM_BIBLIOTECA; i++)
    {
        /// Verifica se existe um livro nessa posição
        if (biblioteca[i] != NULL)
        {
            /// Verifica se o ID é o procurado
            if (biblioteca[i]->id == id)
            {
                /// Mostra as informações do livro
                printf("ID: %d\n", biblioteca[i]->id);
                printf("Titulo: %s\n", biblioteca[i]->titulo);
                printf("Autor: %s\n", biblioteca[i]->autor.nome);

                printf("Nascimento: %02d/%02d/%04d\n",
                       biblioteca[i]->autor.data_nascimento.dia,
                       biblioteca[i]->autor.data_nascimento.mes,
                       biblioteca[i]->autor.data_nascimento.ano);

                printf("Data de escrita: %02d/%02d/%04d\n",
                       biblioteca[i]->data_escrita.dia,
                       biblioteca[i]->data_escrita.mes,
                       biblioteca[i]->data_escrita.ano);

                /// Encerra a função após encontrar o livro
                return;
            }
        }
    }

    /// Executa caso o livro não exista
    printf("Livro nao encontrado!\n");
}

/// Edita as informações de um livro
void editarLivro(LivroMagico **biblioteca, int id)
{
    int i;

    /// Percorre toda a biblioteca
    for (i = 0; i < TAM_BIBLIOTECA; i++)
    {
        /// Verifica se existe um livro
        if (biblioteca[i] != NULL)
        {
            /// Procura o ID informado
            if (biblioteca[i]->id == id)
            {
                /// Lê o novo título
                printf("Novo titulo: ");
                scanf(" %[^\n]", biblioteca[i]->titulo);

                /// Lê o novo autor
                printf("Novo autor: ");
                scanf(" %[^\n]", biblioteca[i]->autor.nome);

                /// Lê a nova data de nascimento do autor
                printf("Nova data de nascimento (dia mes ano): ");
                scanf("%d %d %d",
                      &biblioteca[i]->autor.data_nascimento.dia,
                      &biblioteca[i]->autor.data_nascimento.mes,
                      &biblioteca[i]->autor.data_nascimento.ano);

                /// Lê a nova data de escrita do livro
                printf("Nova data de escrita (dia mes ano): ");
                scanf("%d %d %d",
                      &biblioteca[i]->data_escrita.dia,
                      &biblioteca[i]->data_escrita.mes,
                      &biblioteca[i]->data_escrita.ano);

                printf("Livro atualizado com sucesso!\n");

                /// Encerra a função
                return;
            }
        }
    }

    /// Executa caso o ID não exista
    printf("Livro nao encontrado!\n");
}

/// Lista todos os livros cadastrados
void listarTitulos(LivroMagico **biblioteca)
{
    int i;

    /// Percorre toda a biblioteca
    for (i = 0; i < TAM_BIBLIOTECA; i++)
    {
        /// Verifica se existe um livro
        if (biblioteca[i] != NULL)
        {
            /// Mostra os dados do livro
            printf("ID: %d\n", biblioteca[i]->id);
            printf("Titulo: %s\n", biblioteca[i]->titulo);
            printf("Autor: %s\n\n", biblioteca[i]->autor.nome);
        }
    }
}