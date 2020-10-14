#include "graph.h"
#include "files.h"

int main()
{
    vector<Materia *> Vertices = Read("graph-unb.gml");
    vector<Materia *> Grafo_Ordenado = OrganizacaoTopologica(Vertices);
    vector<vector<Materia *>> Caminho_Critico = CPM(Grafo_Ordenado);

    int condicao = 0;

    // Menu interativo
    while (condicao != -1)
    {
        cout << "-- CIENCIA DA COMPUTAÇÃO/CIC - Bacharel - Presencial - D --" << endl;
        cout << endl;
        cout << "Digite 1 Para mostrar o grafo do curso"<<endl;
        cout << "Digite 2 para fazer a ordenação topologicca"<<endl;
        cout << "Digite 3 para fazer o caminho critico"<<endl;
        cout << "Digite -1 para encerrar"<<endl;
        cin >> condicao;    
        system(CLEAR);

        if (condicao == 1)
        {
            MakeDOT(Vertices);

            for (int i = 0; i < Vertices.size(); i++)
            {
                cout << Vertices[i]->id << " " << Vertices[i]->nome << " - Peso: "<<Vertices[i]->peso <<endl;
            }
            cout << "---------------------------------------------------" << endl;
        }

        if (condicao == 2)
        {
            cout << "-- Ordenacao Topologica --" << endl;
            MakeDOT_Top(Grafo_Ordenado);

            for (int i = 0; i < Grafo_Ordenado.size(); i++){
                cout << Grafo_Ordenado[i]->id << " " << Grafo_Ordenado[i]->nome << endl;
            }

            cout << "---------------------------------------------------" << endl;
        }

        if (condicao == 3)
        {
            MakeDOT_CPM(Caminho_Critico[0], Grafo_Ordenado, "red");
            system("dot -Tpng grafoCPM.dot -o Grafos_Imagens/grafo_CPM1.png");
            MakeDOT_CPM(Caminho_Critico[1], Grafo_Ordenado, "blue");
            system("dot -Tpng grafoCPM.dot -o Grafos_Imagens/grafo_CPM2.png");
            MakeDOT_CPM(Caminho_Critico[2], Grafo_Ordenado, "green");
            system("dot -Tpng grafoCPM.dot -o Grafos_Imagens/grafo_CPM3.png");

            for (int i = 0; i < Caminho_Critico.size(); i++)
            {   
                int pesoTotal = 0;
                cout << "Caminho Critico " << i + 1 << endl;
                for (int j = 0; j < Caminho_Critico[i].size(); j++)
                {
                    cout << "=> Materia: " << Caminho_Critico[i][j]->id << " - Peso: " << Caminho_Critico[i][j]->peso << endl;
                    if (j != (Caminho_Critico[i].size() - 1))
                    {
                        pesoTotal += Caminho_Critico[i][j]->peso;
                    }
                }
                cout << "Peso Total: " << pesoTotal << endl;
                cout << "---------------------------------------------------" << endl;
            }
        }


    }
    
    return 0;
}
