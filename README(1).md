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

## Exemplo de uso

```
=== BIBLIOTECA MÁGICA ===
1. Cadastrar livro
2. Deletar livro
3. Mostrar livro
4. Editar livro
5. Listar títulos
6. Organizar livros
7. Sair
Escolha uma opção: 1

Digite o id do livro: 1
Digite o título: O Grimório Perdido
Digite o nome do autor: Elandra Vys
...
Livro cadastrado com sucesso!
```

*(substituir pelo exemplo real do grupo, se quiserem mostrar mais casos)*

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
