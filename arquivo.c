#include "biblioteca.h"

void criptografar(char *str) {
    if (str == NULL) return;

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] ^= 5;
    }
}

void descriptografar(char *str) {
    criptografar(str);
}

void salvarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "wb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    int quantidade = 0;
    for (int i = 0; i < TAM_BIBLIOTECA; i++) {
        if (biblioteca[i] != NULL) {
            quantidade++;
        }
    }

    fwrite(&quantidade, sizeof(int), 1, arq);

    for (int i = 0; i < TAM_BIBLIOTECA; i++) {
        if (biblioteca[i] != NULL) {
            LivroMagico temp = *biblioteca[i];
            criptografar(temp.titulo);
            criptografar(temp.autor.nome);
            fwrite(&temp, sizeof(LivroMagico), 1, arq);
        }
    }

    fclose(arq);
}

void carregarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "rb");
    if (arq == NULL) {
        for (int i = 0; i < TAM_BIBLIOTECA; i++) {
            biblioteca[i] = NULL;
        }
        return;
    }

    int quantidade = 0;
    fread(&quantidade, sizeof(int), 1, arq);

    for (int i = 0; i < TAM_BIBLIOTECA; i++) {
        biblioteca[i] = NULL;
    }

    for (int i = 0; i < quantidade && i < TAM_BIBLIOTECA; i++) {
        biblioteca[i] = (LivroMagico *)malloc(sizeof(LivroMagico));
        if (biblioteca[i] == NULL) {
            fclose(arq);
            return;
        }

        fread(biblioteca[i], sizeof(LivroMagico), 1, arq);
        descriptografar(biblioteca[i]->titulo);
        descriptografar(biblioteca[i]->autor.nome);
    }

    fclose(arq);
}
