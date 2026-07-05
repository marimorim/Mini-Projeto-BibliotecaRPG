#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BIBLIOTECA 100

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    Data data_nascimento;
} Autor;

typedef struct {
    int id;
    char titulo[100];
    Autor autor;
    Data data_escrita;
} LivroMagico;

/* Protótipos */

void InicializarVetor(LivroMagico **biblioteca);
void cadastrarLivro(LivroMagico **biblioteca);
void deletarLivro(LivroMagico **biblioteca, int id);

void mostrarLivro(LivroMagico **biblioteca, int id);
void editarLivro(LivroMagico **biblioteca, int id);
void listarTitulos(LivroMagico **biblioteca);

void salvarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo);
void carregarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo);

void criptografar(char *str);
void descriptografar(char *str);

void mostrarLivroOrganizado(LivroMagico *livro);
int deveTrocar(LivroMagico *livro1, LivroMagico *livro2);
void organizarBiblioteca(LivroMagico **biblioteca);

#endif
