# Introdução

O objetivo desse projeto é implementar a estrutura de dados tabela de dispersão em c++. A fim de auxiliar no entendimento a respeito dessa estrutura de dados, o desenvolvimento será feito considerando uma aplicação simples que mantém os dados de contas correntes armazenados em tabelas de dispersão.

# Compilação

Para compilar esse projeto será necessário o [cmake](https://cmake.org) e o [Google tests](https://github.com/google/googletest/blob/master/googletest/docs/primer.md). 

1. `cd hash-table`: entra no diretório principal do projeto
2. `cmake -S . -Bbuild`:  O cmake cria um diretório build e gera um Makefile baseado no script encontrado em `CMakeLists.txt` 
3. `cd build`: entra no diretório `build`
5. `cmake --build .` or `make`: aciona o processo de compilação

Os executáveis estarão no diretório `build`

# Execução

```
$ ./build/driver_hash
```

Os testes foram feitos usando o [Google tests](https://github.com/google/googletest/blob/master/googletest/docs/primer.md), faça o download na máquina de execução. E execute:

```
$ ./build/run_tests
```


# Discente

- Karina Maria