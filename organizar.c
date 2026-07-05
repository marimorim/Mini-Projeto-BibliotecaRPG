
         
      /// Organizador magico da biblioteca
/// Organiza os livros por ano, autor e titulo

#include "biblioteca.h"

/// Mostra um livro depois da organizacao
void mostrarLivroOrganizado(LivroMagico *livro)
{
    printf("ID: %d\n", livro->id);
    printf("Ano: %d\n", livro->data_escrita.ano);
    printf("Autor: %s\n", livro->autor.nome);
    printf("Titulo: %s\n\n", livro->titulo);
}

/// Verifica se dois livros precisam trocar de lugar
int deveTrocar(LivroMagico *livro1, LivroMagico *livro2)
{
    /// Primeiro compara pelo ano
    if(livro1->data_escrita.ano > livro2->data_escrita.ano)
    {
        return 1;
    }

    /// Se o ano for igual, compara pelo autor
    if(livro1->data_escrita.ano == livro2->data_escrita.ano)
    {
        if(strcmp(livro1->autor.nome, livro2->autor.nome) > 0)
        {
            return 1;
        }

        /// Se o autor for igual, compara pelo titulo
        if(strcmp(livro1->autor.nome, livro2->autor.nome) == 0)
        {
            if(strcmp(livro1->titulo, livro2->titulo) > 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

/// Organiza a biblioteca por ano, autor e titulo
void organizarBiblioteca(LivroMagico **biblioteca)
{
    int i, j;
    int total = 0;
    int trocas = 0;
    LivroMagico *aux;

    /// Conta quantos livros existem
    for(i = 0; i < TAM_BIBLIOTECA; i++)
    {
        if(biblioteca[i] != NULL)
        {
            total++;
        }
    }

    /// Verifica se a biblioteca esta vazia
    if(total == 0)
    {
        printf("A biblioteca esta vazia!\n");
        return;
    }

    /// Verifica se existe apenas um livro
    if(total == 1)
    {
        printf("Existe apenas um livro na biblioteca!\n");
        return;
    }

    /// Organiza os livros usando comparacoes
    for(i = 0; i < TAM_BIBLIOTECA - 1; i++)
    {
        for(j = i + 1; j < TAM_BIBLIOTECA; j++)
        {
            if(biblioteca[i] != NULL && biblioteca[j] != NULL)
            {
                /// Se estiver fora de ordem, troca
                if(deveTrocar(biblioteca[i], biblioteca[j]) == 1)
                {
                    aux = biblioteca[i];
                    biblioteca[i] = biblioteca[j];
                    biblioteca[j] = aux;

                    trocas++;
                }
            }
        }
    }

    printf("\nAs estantes magicas foram reorganizadas!\n");
    printf("Ordem usada: ano -> autor -> titulo\n");
    printf("Livros encontrados: %d\n", total);
    printf("Trocas realizadas: %d\n\n", trocas);

    /// Mostra a biblioteca depois de organizada
    for(i = 0; i < TAM_BIBLIOTECA; i++)
    {
        if(biblioteca[i] != NULL)
        {
            mostrarLivroOrganizado(biblioteca[i]);
        }
    }
}
