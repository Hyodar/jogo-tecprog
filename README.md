# Aventuras de um Bardo (e seu fiel aventureiro)

Jogo feito usando SFML para a disciplina de Técnicas de Programação.
Arquivo deve ser lido preferencialmente com um leitor de Markdown ou
na página https://github.com/Hyodar/jogo-tecprog.

Autores:
- Franco Barpp Gomes
- João Vítor Dotto Rissardi

## Instruções de compilação

Compilado em Linux Mint 19.1, baseado em Ubuntu e Debian, usando g++ 
com C++17 (ou 1z). Considerando condições ideais de arquitetura de 
processador e OS, pode ser possível usar diretamente o arquivo compilado,
com `./jogo` dentro do diretório `jogo-tecprog`.

Se não for possível, seguem as instruções:

### Instruções para compilação:

  (`$ ` indica a linha de comando do terminal)
  - A partir desse diretório (jogo-tecprog), 
  ```bash
  $ cd jogo
  ```
  - Para instalar os pacotes necessários (pode ser apt, apt-get ou seu package manager de preferência): 
  ```bash
  $ sudo apt install g++
  $ sudo apt install make 
  $ sudo apt install libwxgtk3.0-dev
  $ sudo apt install libsfml-dev
  ```
  (é possível que falte algum pacote por questões de sistema, mas a princípio são esses)
  - 
  ```bash
  $ make
  ```
  (opcionalmente é possível colocar `make -j<NUM_THREADS_DO_PROCESSADOR>` para compilação mais rápida)
  - Após a compilação terminar: 
  ```bash
  $ ./jogo
  ```
