#include "files.h"
#include "graph.h"

map<string, Materia *> vertice;
vector<Materia *> verticesenumerados;

// Funcao vai ler a arquivo .gml e armazenar no vertice
vector<Materia *> Read(string file)
{
    fstream FileReader;
    FileReader.open(file.c_str());
    string checkline;
    int num = 0;
    if (FileReader.is_open())
    {
        while (!FileReader.eof())
        {
            FileReader >> checkline;
            if (checkline == "node")
            {
                while (checkline != "id")
                {
                    FileReader >> checkline;
                }
                string id;
                string nome;
                int peso;

                FileReader >> id;
                FileReader >> nome;
                FileReader >> peso;
                Materia *materia = new Materia(id, nome, peso);
                vertice.insert({id, materia});
                verticesenumerados.push_back(materia);
                num++;
            }
            else if (checkline == "edge")
            {
                while (checkline != "source")
                {
                    FileReader >> checkline;
                }
                string source;
                string destiny;
                FileReader >> source;
                FileReader >> checkline;
                FileReader >> destiny;
                vertice[source]->InsertCon(vertice[destiny]);
                vertice[destiny]->InsertAnt(vertice[source]);
                vertice[destiny]->grau += 1;
            }
        }
    }
    else
    {
        cout << "Error reading File: " << file << endl;
    }
    FileReader.close();

    return verticesenumerados;
}

// Funcao vai pegar as materias e criar um .dot pra criar um grafo
void MakeDOT(vector<Materia *> materias)
{
    ofstream myfile;
    myfile.open("grafo.dot");
    myfile << "digraph Ciencia_da_Computacao{\n";
    //Direcionamento dos vertices
    for (int i = 0; i < materias.size(); i++)
    {
        if (materias[i]->conexoes.size() == 0)
        {
            myfile << "\t" << materias[i]->id << "\n ";
        }
        else
        {
            for (int j = 0; j < materias[i]->conexoes.size(); j++)
            {
                myfile << "\t" << materias[i]->id << " -> " << materias[i]->conexoes[j]->id << " [label = " << materias[i]->peso << "];\n";
            }
        }
    }
    //Colorização dos vertices por peso
    for (int i = 0; i < materias.size(); i++)
    {
        if (materias[i]->peso == 2)
        {
            myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=green]\n ";
        }
        else if (materias[i]->peso == 4)
        {
            myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=skyblue]\n ";
        }
        else if (materias[i]->peso == 6)
        {
            myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=yellow]\n ";
        }
    }
    myfile << "}\n";
    myfile.close();
    system("dot -Tpng grafo.dot -o Grafos_Imagens/grafo.png");
}

// Funcao vai criar um .dot da ordenacao topologica pra criar um grafo
void MakeDOT_Top(vector<Materia *> materias)
{
    ofstream myfile;
    myfile.open("grafo_Ordenado.dot");

    myfile << "digraph Ciencia_da_Computacao{\n";
    myfile << "\tnode [shape=doublecircle];\n";
    myfile << "\tranksep = \"4\";\n";
    //Inicializacao do grafo ordenado
    myfile << "\tsubgraph{\n ";
    myfile << "\trank = same; ";

    for (int i = 0; i < materias.size(); i++)
    {
        myfile << materias[i]->id << "; ";
    }
    myfile << "\n\t}\n";
    //Direcionamento dos vertices
    for (int i = 0; i < materias.size(); i++)
    {
        if (materias[i]->conexoes.size() == 0)
        {
            myfile << "\t" << materias[i]->id << "\n ";
        }
        else
        {
            for (int j = 0; j < materias[i]->conexoes.size(); j++)
            {
                myfile << "\t" << materias[i]->id << " -> " << materias[i]->conexoes[j]->id << " [label = " << materias[i]->peso << "];\n";
            }
        }
    }
    //Colorização dos vertices por peso
    for (int i = 0; i < materias.size(); i++)
    {
        if (materias[i]->peso == 2)
        {
            myfile << "\t" << materias[i]->id << " [style=filled, fillcolor=green]\n ";
        }
        else if (materias[i]->peso == 4)
        {
            myfile << "\t" << materias[i]->id << " [style=filled, fillcolor=skyblue]\n ";
        }
        else if (materias[i]->peso == 6)
        {
            myfile << "\t" << materias[i]->id << " [style=filled, fillcolor=yellow]\n ";
        }
    }
    myfile << "}\n";
    myfile.close();
    system("dot -Tpng grafo_Ordenado.dot -o Grafos_Imagens/grafo_Ordenado.png");
}

// Funcao vai criar .dot do caminho critico pra fazer um grafo
void MakeDOT_CPM(vector<Materia *> CPM, vector<Materia *> materias, string color)
{
    {
        //a->b[color = red, penwidth = 3.0];
        ofstream myfile;
        myfile.open("grafoCPM.dot");
        myfile << "digraph Ciencia_da_Computacao{\n";
        ///Direcionamento dos vertices
        for (int i = 0; i < materias.size(); i++)
        {
            if (materias[i]->conexoes.size() == 0)
            {
                myfile << "\t" << materias[i]->id << "\n ";
            }
            else
            {
                for (int j = 0; j < materias[i]->conexoes.size(); j++)
                {
                    //Colorização do Caminho Critico
                    if ((SearchMateria(CPM, materias[i]) == true) && (SearchMateria(CPM, materias[i]->conexoes[j]) == true))
                    {
                        myfile << "\t" << materias[i]->id << " -> " << materias[i]->conexoes[j]->id << " [label = " << materias[i]->peso << ", color = " + color + ", penwidth = 3.0];\n";
                    }
                    else
                    {
                        myfile << "\t" << materias[i]->id << " -> " << materias[i]->conexoes[j]->id << " [label = " << materias[i]->peso << "];\n";
                    }
                }
            }
        }
        //Colorização dos vertices por peso
        for (int i = 0; i < materias.size(); i++)
        {
            if (materias[i]->peso == 2)
            {
                myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=green]\n ";
            }
            else if (materias[i]->peso == 4)
            {
                myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=skyblue]\n ";
            }
            else if (materias[i]->peso == 6)
            {
                myfile << "\t" << materias[i]->id << " [shape=doublecircle, style=filled, fillcolor=yellow]\n ";
            }
        }
        myfile << "}\n";
        myfile.close();
    }
}