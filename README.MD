# Universidade de Brasilia																		 
# Instituto de Ciencia Exata 																		 
# Departamento de Ciencia da Computacao

# Projeto 2 Teoria e Aplicação de Grafos

## Turma A - 1/2020
## Prof. Díbio

Alunos: 
Vinicius da Silva Rocha 18/0028804  
João Victor Pinheiro de Souza 18/0103407

Este projeto visa analisar possíveis caminhos críticos (CPM) das disciplinas do seu curso na UnB. Para
isso deve ser construído um grafo direcionado acíclico (DAG) das disciplinas obrigatórias do curso (32
para Bac. Ciência da Computação) (obs. Não incluindo as duas disciplinas de Trabalho de Graduação
(1 e 2)). 
    
Elas deverão ser indicadas pelo código numérico da UnB. Edite um arquivo de entrada com
esses dados e/ou inicialize seu programa com esses dados estruturados. Para o DAG devem ser
considerados os pré-requisitos, e um peso P ligado ao vértice de uma determinada disciplina que será
exatamente o número de créditos da disciplina. Um algoritmo de Ordenação Topológica deverá então
ser aplicado no DAG e as três sequências distintas (i.e. todas disciplinas diferentes) mais longas
(somatória de pesos) deverão ser geradas. 

Como saídas do programa deverão ser apresentados na tela
do computador, o nome do curso, DAG respectivo (códigos de disciplina como vértices e arestas
indicando pré-requisitos), a ordenação topológica gerada, e as três sequências mais longas (Caminhos
Críticos) identificadas (disciplinas em ordem topológica, pesos das arestas e peso total). Use uma
biblioteca gráfica para gerar os resultados visualmente (e.g. gnuplot ou Graphviz).

# Biblioteca usada:
Graphviz

# Terminal:

No terminal vai aparecer um menu interativo, onde vai aparecer 4 opções:

Opção 1 :
    Vai gerar um .png do grafo das materias, e vai aparecer na terminal seu codigo, nome e peso.

Opção 2 :
    Vai gerar um .png do grafo da ordenação topologica, e vai aparecer na terminal o codigo e nome das materias.

Opção 3 :
    Vai gerar as 3 imagens dos caminhos criticos, e vai aparecer no terminal o codigo, peso e peso total.

Opção -1 : Onde ele termina a execução do programa.

# Observacao:
    As imagens vão ser criadas na pasta : Grafos_Imagens
    As cores representa a quantidade de creditos que a materia possui
    Verde   - 2 creditos
    Azul    - 4 creditos
    Amarelo - 6 creditos 

### versao do Compilador: g++ version 9.3.0 
### Execução:

Compilação do programa

```bash
make all
```

Execução do programa

```bash
./main
```

Limpeza dos Arquivos Gerados

```bash
make clean
```
