# Biblioteca Mágica — Backend de Inventário (RPG)

Sistema em C que gerencia o inventário de livros mágicos de um jogo de RPG, com cadastro, edição, exclusão e persistência em arquivo (save game). Os títulos dos livros são criptografados antes de serem salvos em disco.

## Integrantes do grupo

- [Maria Eduarda Tavares Câmara Amorim] — Inventário / Lendários
- [Laura Teixeira Veloso Macedo] — Catálogo / Organização
- [Maria Luiza Ribeiro Amaral] — Principal
- [Amanda de Brito Silva] — Manipulação de Arquivos

## Link do repositório

🔗 [https://github.com/marimorim/Mini-Projeto-BibliotecaRPG](https://github.com/marimorim/Mini-Projeto-BibliotecaRPG)

## Funcionalidades

O sistema é controlado por um menu principal em loop, com as seguintes opções:

1. **Cadastro de livro** — adiciona um novo livro à biblioteca (alocação dinâmica).
2. **Deleção de livro** — remove um livro pelo `id`, liberando a memória.
3. **Mostrar livro** — exibe os dados completos de um livro pelo `id`.
4. **Editar livro** — permite alterar os dados de um livro já cadastrado.
5. **Listar títulos dos livros** — lista o `id` e `título` de todos os livros cadastrados.
6. **Organizar a lista dos livros** — organiza os livros de acordo com esses criterios **Autor**->**Ano de publicação**->**Título (alfabética)** 
7. **Sair** — salva a biblioteca no arquivo e encerra o programa.

## Estrutura dos dados

- **Data**: dia, mês e ano.
- **Autor**: nome e data de nascimento (uma `Data`).
- **LivroMagico**: id, título, autor (uma `Autor`) e data de escrita (uma `Data`).

Internamente, a biblioteca é um **vetor de 100 ponteiros** para `LivroMagico`. Cada posição aponta para um livro alocado dinamicamente ou é `NULL`, indicando uma posição livre no inventário.

## Persistência e criptografia

Os dados da biblioteca são salvos e carregados de um arquivo texto passado como argumento na linha de comando. O campo `titulo` é criptografado com a técnica de **complemento de 255** antes de ser salvo, e descriptografado automaticamente ao ser carregado — a mesma operação serve para os dois sentidos, já que é sua própria inversa.

## Como compilar

No terminal, dentro da pasta do projeto:

```bash
gcc arquivo.c -o biblioteca
```
```bash
gcc cadastro.c -o biblioteca
```
```bash
gcc consulta.c -o biblioteca
```
```bash
gcc gerenciamento.c -o biblioteca
```
```bash
gcc organizar.c -o biblioteca
```
```bash
gcc lentadios.c -o biblioteca
```
```bash
gcc main.c -o biblioteca
```

## Como executar

O programa recebe o nome do arquivo de save como argumento:

```bash
./biblioteca biblioteca.txt
```

- Se o arquivo já existir, a biblioteca salva anteriormente será carregada automaticamente ao iniciar.
- Se o arquivo não existir, o programa inicia com o inventário vazio e criará o arquivo ao salvar.

## Exemplo de uso(Casos de Teste — Biblioteca Mágica)

Todos os casos abaixo foram executados de verdade no binário compilado
(`gcc main.c cadastro.c consulta.c organizar.c arquivo.c lendarios.c -o biblioteca`)

---

  ## 1. Cadastrar livro (sucesso)
    
    ```
    ===== MENU =====
    1 - Cadastrar livro
    2 - Deletar livro
    3 - Mostrar livro (buscar por ID)
    4 - Editar livro
    5 - Listar titulos
    6 - Organizar biblioteca (ano/autor/titulo)
    0 - Sair (salva automaticamente)
    =================
    Escolha uma opcao: 1
    Digite o ID do Livro: 1
    Titulo: O Hobbit
    Autor: J.R.R. Tolkien
    Nascimento do Autor: 3 1 1892
    Data de escrita do livro: 21 9 1937
    Livro Colocado na Estante!
    ```
    
  ## 2. Cadastrar livro (ID duplicado)
    
    ```
    Escolha uma opcao: 1
    Digite o ID do Livro: 1
    Esse ID ja esta em uso :(
    ```
    
  ## 3. Cadastrar livro (estante cheia)
    
    ```
    Escolha uma opcao: 1
    A estante esta cheia!
    ```
    *(ocorre quando as 100 posições da biblioteca já estão ocupadas)*
    
    ---
    
  ## 4. Deletar livro (sucesso)
    
    ```
    Escolha uma opcao: 2
    Digite o ID do livro a deletar: 1
    O livro foi retirado da estante!
    ```
    
  ## 5. Deletar livro (ID inexistente)
    
    ```
    Escolha uma opcao: 2
    Digite o ID do livro a deletar: 99
    Livro não encontrado
    ```
    
    ---
    
  ## 6. Mostrar livro (sucesso)
    
    ```
    Escolha uma opcao: 3
    Digite o ID do livro: 1
    ID: 1
    Titulo: O Hobbit - Edicao Ilustrada
    Autor: J.R.R. Tolkien
    Nascimento: 03/01/1892
    Data de escrita: 21/09/1937
    ```
    
  ## 7. Mostrar livro (ID inexistente)
    
    ```
    Escolha uma opcao: 3
    Digite o ID do livro: 99
    Livro nao encontrado!
    ```
    
    ---
    
  ## 8. Editar livro (sucesso)
    
    ```
    Escolha uma opcao: 4
    Digite o ID do livro a editar: 1
    Novo titulo: O Hobbit - Edicao Ilustrada
    Novo autor: J.R.R. Tolkien
    Nova data de nascimento (dia mes ano): 3 1 1892
    Nova data de escrita (dia mes ano): 21 9 1937
    Livro atualizado com sucesso!
    ```
    
    ## 9. Editar livro (ID inexistente)
    
    ```
    Escolha uma opcao: 4
    Digite o ID do livro a editar: 99
    Livro nao encontrado!
    ```
    
    ---
    
  ## 10. Listar títulos (biblioteca vazia)
    
    ```
    Escolha uma opcao: 5
    
    ===== MENU =====
    ```
    *(nenhuma linha é exibida, o menu volta a aparecer normalmente)*
    
    ## 11. Listar títulos (com livros cadastrados)
    
    ```
    Escolha uma opcao: 5
    ID: 1
    Titulo: O Hobbit
    Autor: J.R.R. Tolkien
    
    ID: 2
    Titulo: O Nome do Vento
    Autor: Patrick Rothfuss
    ```
    
    ---
    
  ## 12. Organizar biblioteca (vazia)
    
    ```
    Escolha uma opcao: 6
    A biblioteca esta vazia!
    ```
    
  ## 13. Organizar biblioteca (apenas 1 livro)
    
    ```
    Escolha uma opcao: 6
    Existe apenas um livro na biblioteca!
    ```
    
  ## 14. Organizar biblioteca (vários livros fora de ordem)
    
    ```
    Escolha uma opcao: 6
    
    As estantes magicas foram reorganizadas!
    Ordem usada: ano -> autor -> titulo
    Livros encontrados: 3
    Trocas realizadas: 1
    
    ID: 2
    Ano: 2005
    Autor: Autor A
    Titulo: Alfa
    
    ID: 1
    Ano: 2010
    Autor: Autor Z
    Titulo: Zorro
    
    ID: 3
    Ano: 2015
    Autor: Autor B
    Titulo: Beta
    ```
    *(confirmado: ordenação correta por ano → autor → título)*
    
    ---
    
  ## 15. Easter egg — RPGs Lendários
    
    Cadastrando um livro com o título exato de um dos 5 RPGs lendários, aparece uma mensagem especial colorida logo após "Livro Colocado na Estante!":
    
    ```
    Escolha uma opcao: 1
    Digite o ID do Livro: 1
    Titulo: Dungeons & Dragons
    Autor: Gary Gygax
    Nascimento do Autor: 27 7 1938
    Data de escrita do livro: 1 1 1974
    Livro Colocado na Estante!
    O Dragao Ancestral despertou!
    ```
    
    | Título exato | Mensagem exibida |
    |---|---|
    | `Dungeons & Dragons` | `O Dragao Ancestral despertou!` |
    | `Tormenta` | `Uma nuvem rubra cobre Arton!` |
    | `Ordem Paranormal` | `A membrana esta fraca!` |
    | `Vampiro` | `A besta desperta nas sombras!` |
    | `Call of Cthulhu` | `Algo desperta nas profundezas!` |
    
    Quando os 5 lendários já foram cadastrados na mesma execução, a última mensagem vem acompanhada de:
    
    ```
     OS RPGs LENDARIOS FORAM ENCONTRADOS
    A Biblioteca Magica lhe reconhece
    ```
    
    Cadastrar o mesmo lendário duas vezes não repete a mensagem (cada um só conta uma vez).
    
    ---
    
  ## 16. Persistência em arquivo
    
    **Primeira vez que o programa roda (sem `biblioteca.dat` ainda):**
    ```
    ===== BIBLIOTECA MAGICA =====
    Nenhuma biblioteca salva encontrada. Comecando do zero!
    ```
    
    **Depois de cadastrar livros e sair (opção 0):**
    ```
    Escolha uma opcao: 0
    Salvando biblioteca... ate a proxima aventura!
    ```
    *(o arquivo `biblioteca.dat` é criado/atualizado no disco, com título e autor criptografados)*
    
    **Abrindo o programa novamente:**
    ```
    ===== BIBLIOTECA MAGICA =====
    Biblioteca carregada com 1 livro(s) salvos anteriormente.
    ```
    *(confirmado: os dados batem exatamente com o que foi cadastrado na execução anterior)*
    
    ---
    
  ## 17. Entrada inválida no menu
    
    ```
    Escolha uma opcao: abc
    Opcao invalida! Digite um numero.
    ```
    
    ```
    Escolha uma opcao: 9
    Opcao invalida!
    ```


## Organização dos arquivos

| Arquivo | Responsável | Conteúdo |
|---|---|---|
| `biblioteca.h` | [Maria Eduarda] | Structs e protótipos das funções |
| `lendarios.h` | [Maria Eduarda] | Prototipo das funções dos lendários |
| `consulta.c` | [Maria Eduarda] | `InicializarVetor`, `cadastrarLivro`, `deletarLivro` |
| `consulta.c` | [Laura Macedo] | `mostrarLivro`, `editarLivro`, `listarTitulos` |
| `arquivo.c` | [Amanda de Brito] | `criptografar`, `descriptografar`, `salvarBiblioteca`, `carregarBiblioteca`|
| `organizar.c` | [Laura Macedo] | `mostrarLivroOrganizado`, `deveTrocar`, `organizarBiblioteca` |
| `lendarios.c` | [Maria Eduarda] | `verificarLivroLendario` |
| `main.c` | [Maria Luiza] | Menu principal |

## Vídeo de apresentação

🔗 [link do vídeo, se for incluído aqui também]
