# Introdução
Projeto apresentado à disciplina Estrutura de Dados Básicas I, como requisito parcial para obtenção de nota da primeira unidade. A disciplina é ministrada pelo professor Selan Rodrigues dos Santos. 

# Algoritmos de busca
Os objetivos desse trabalho são:
1. Implementar e testar uma função de busca linear
2. Implementar e testar uma função de busca binária
3. Implementar e testar uma função de lower bound
4. Implementar e testar uma função de upper bound
5. Responder as perguntas: a busca binária é mais eficiente que a busca linear? Qual a versão (recursiva ou iterativa) da busca binária é mais eficiente?

# Compilação

Para compilar esse projeto com o [cmake](https://cmake.org) siga os passos:

1. `cd searching_exercise`: entra no diretório principal do projeto
2. `cmake -S . -Bbuild`:  O cmake cria um diretório build e gera um Makefile baseado no script encontrado em `CMakeLists.txt` 
3. `cd build`: entra no diretório `build`
5. `cmake --build .` or `make`: aciona o processo de compilação

Os executáveis estão no diretório `build`


# Execução

```
$ ./build/driver_search
```

```
$ ./build/run_tests
```
```
$ ./build/timing_template
```


# Discente

- Karina Maria Bezerra Jacinto