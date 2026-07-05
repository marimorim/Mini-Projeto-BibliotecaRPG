#include <stdio.h>
#include <string.h>
#include "lendarios.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

#define TOTAL_LENDARIOS 5

static int encontrados = 0;

static int dnd = 0;
static int tormenta = 0;
static int ordem = 0;
static int vampiro = 0;
static int cthulhu = 0;

void verificarLivroLendario(LivroMagico *livro){
    //D&D
    if (strcmp(livro->titulo,"Dungeons & Dragons")==0 && !dnd){
        dnd = 1;
        encontrados++;
        printf(RED BOLD);
        printf("O Dragao Ancestral despertou!\n");
        printf(RESET);
    } else if (strcmp(livro->titulo,"Tormenta") == 0 && !tormenta){
        tormenta = 1;
        encontrados++;
        printf(MAGENTA BOLD);
        printf("Uma nuvem rubra cobre Arton!\n");
        printf(RESET);
    } else if (strcmp(livro->titulo,"Ordem Paranormal") == 0 && !ordem){
        ordem = 1;
        encontrados++;
        printf(YELLOW BOLD);
        printf("A membrana esta fraca!\n");
        printf(RESET);
    } else if ( strcmp(livro->titulo,"Vampiro") == 0 && !vampiro){
        vampiro = 1;
        encontrados++;
        printf(RED BOLD);
        printf("A besta desperta nas sombras!\n");
        printf(RESET);
    } else if (strcmp(livro->titulo,"Call of Cthulhu")==0 && !cthulhu){
        cthulhu = 1;
        encontrados++;
        printf(GREEN BOLD);
        printf("Algo desperta nas profundezas!\n");
        printf(RESET);
    }

    if (encontrados == TOTAL_LENDARIOS){
        printf(GREEN BOLD);
        printf(" OS RPGs LENDARIOS FORAM ENCONTRADOS\n");
        printf("A Biblioteca Magica lhe reconhece\n");
        printf(RESET);
    }
    
}