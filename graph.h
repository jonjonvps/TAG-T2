#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Materia
{
public:
  string id;
  string nome;
  int peso;
  int grau;

  Materia(string id, string nome, int peso);
  vector<Materia *> conexoes;
  vector<Materia *> antecessor;

  void InsertCon(Materia *materia);
  void InsertAnt(Materia *materia);
};

int SearchMateriaIndex(vector<Materia *> materias, Materia *materia);
bool SearchMateria(vector<Materia *> materias, Materia *materia);
vector<Materia *> OrganizacaoTopologica(vector<Materia *> materias);
vector<vector<Materia *>> CPM(vector<Materia *> materias);
vector<Materia *> BuildPath(vector<Materia *> materias, vector<int> distanciaMaterias, int distanciaMax, int indexMax);

#endif