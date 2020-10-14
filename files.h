#ifndef FILES_H
#define FILES_H

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "graph.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

class Materia;

vector<Materia *> Read(string file);
void MakeDOT(vector<Materia *> materias);
void MakeDOT_Top(vector<Materia *> materias);
void MakeDOT_CPM(vector<Materia *> CPM, vector<Materia *> materias, string color);

#endif