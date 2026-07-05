#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "lendarios.h"

//Inicializando Vetor
void InicializarVetor(LivroMagico **biblioteca){
    int i;
    for ( i = 0; i < 100; i++) biblioteca[i] = NULL;
}

//Cadastro do livro
void cadastrarLivro(LivroMagico **biblioteca){
    int i;
    int livre = -1;
    int novo_id;

    //achando estante vazia
    for ( i = 0; i < TAM_BIBLIOTECA; i++){
        if (biblioteca[i] == NULL){
            livre = i;
            break;
        }
        
    }

    if (livre == -1){
        printf("A estante esta cheia!\n");
        return;
    }

    printf("Digite o ID do Livro: ");
    scanf("%d",&novo_id);
    
    //Validando Id
    for ( i = 0; i < TAM_BIBLIOTECA; i++){
        if (biblioteca[i] != NULL && biblioteca[i]->id == novo_id){
                printf("Esse ID ja esta em uso :(\n");
                return;   
            }
        
    }

    //alocando
    biblioteca[livre] = (LivroMagico*) malloc(sizeof(LivroMagico));

    if (biblioteca[livre] == NULL){
        printf("Erro ao alocar memória!\n");
        return;
    }
    
    
    //guarda o ID
    biblioteca[livre]->id = novo_id;

    printf("Titulo: ");
    scanf(" %[^\n]",biblioteca[livre]->titulo);

    printf("Autor: ");
    scanf(" %[^\n]",biblioteca[livre]->autor.nome);

    printf("Nascimento do Autor: ");
    scanf("%d %d %d",&biblioteca[livre]->autor.data_nascimento.dia,&biblioteca[livre]->autor.data_nascimento.mes,&biblioteca[livre]->autor.data_nascimento.ano);

    printf("Data de escrita do livro: ");
    scanf("%d %d %d", &biblioteca[livre]->data_escrita.dia, &biblioteca[livre]->data_escrita.mes, &biblioteca[livre]->data_escrita.ano);

    printf("Livro Colocado na Estante!\n");

    verificarLivroLendario(biblioteca[livre]);
}

//Deletando o livro pelo ID
void deletarLivro(LivroMagico **biblioteca, int id){
    int i;

    for (i = 0; i < TAM_BIBLIOTECA; i++){
        if (biblioteca[i] != NULL && biblioteca[i]->id == id){
    
                free(biblioteca[i]);

                //deixando o lugar vago
                biblioteca[i] = NULL;

                printf("O livro foi retirado da estante!\n");
                return;
            
            
        }
        
    }
    
    printf("Livro não encontrado\n");

}
