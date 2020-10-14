#include "graph.h"

// Metodo que vai inserir na classe seus atributos
Materia::Materia(string id, string nome, int peso)
{
    this->id = id;
    this->nome = nome;
    this->peso = peso;
    this->grau = 0;
}

void Materia::InsertCon(Materia *materia)
{
    conexoes.push_back(materia);
}

void Materia::InsertAnt(Materia *materia)
{
    antecessor.push_back(materia);
}

// vai procurar o index da materia
int SearchMateriaIndex(vector<Materia *> materias, Materia *materia)
{
    int i = 0;
    while (materias[i]->id != materia->id)
    {
        i++;
    }

    return i;
}

// Vai procurar se tem a materia
bool SearchMateria(vector<Materia *> materias, Materia *materia)
{
    for (int i = 0; i < materias.size(); i++)
    {
        if (materias[i]->id == materia->id)
        {
            return true;
        }
    }
    return false;
}

vector<Materia *> OrganizacaoTopologica(vector<Materia *> materias)
{
    queue<Materia *> fila;
    queue<Materia *> filafinal;
    int contadordevertices = 0;

    // Vai colocar na pilha as materias que nao tem depedencia
    for (int i = 0; i < materias.size(); i++)
    {
        if (materias[i]->grau == 0)
        {
            fila.push(materias[i]);
        }
    }

    // parte do programa que vai percorrer as conexoes pra fazer a ordenacao topologica 
    while (!fila.empty())
    {
        contadordevertices++;
        if (fila.front()->conexoes.size() != 0)
        {
            for (int i = 0; i < fila.front()->conexoes.size(); i++)
            {
                // verifica se grau da conexao eh 0, pelo fato de quando chegar a zero
                // significa que nao tem mais caminho para percorre e vai ser adicionado na fila
                fila.front()->conexoes[i]->grau--;
                if (fila.front()->conexoes[i]->grau == 0)
                {
                    fila.push(fila.front()->conexoes[i]);
                }
            }
        }
        filafinal.push(fila.front());
        fila.pop();
    }

    // Vai inverter a pilha
    vector<Materia *> vecordenado;
    for (int i = (filafinal.size() - 1); i >= 0; i--)
    {
        vecordenado.push_back(filafinal.front());
        filafinal.pop();
    }
    return vecordenado;
}

// Funcao vai fazer o caminho pra ver quais materias faz parte do caminho critico 
vector<Materia *> BuildPath(vector<Materia *> materias, int *distanciaMaterias, int distanciaMax, int indexMax)
{
    vector<Materia *> temp;
    stack<Materia *> pilha;
    Materia *materiaAtual = materias[indexMax];
    int Distancia = 0;

    pilha.push(materiaAtual);
    //Construindo caminho para a materia selecionada
    while (Distancia != distanciaMax)
    {
        for (int i = 0; i < materias.size(); i++)
        {
            for (int j = 0; j < materias[i]->conexoes.size(); j++)
            {
                int atualIndex = SearchMateriaIndex(materias, materiaAtual);
                int previous = SearchMateriaIndex(materias, materias[i]);
                
                // Verifica se a soma da distancia e o peso da materia anterior vai ser o peso total do caminho
                if ((materias[i]->conexoes[j] == materiaAtual) && (distanciaMaterias[atualIndex] == distanciaMaterias[previous] + materias[i]->peso))
                {
                    pilha.push(materias[i]);
                    Distancia += materias[i]->peso;
                    materiaAtual = materias[i];
                }
            }
        }
    }
    //Invertendo ordem da pilha para o vetor a ser retornado
    while (!pilha.empty())
    {
        temp.push_back(pilha.top());
        pilha.pop();
    }

    return temp;
}

// Funcao que vai fazer o caminho critico 
vector<vector<Materia *>> CPM(vector<Materia *> materias)
{
    vector<Materia *> materias2 = materias;  
    vector<Materia *> materias3 = materias;
    queue<Materia *> fila;
    int distancia[materias.size()];

    //Inicializando vetor de distancias e fila de materias
    for (int i = 0; i < materias.size(); i++)
    {
        distancia[i] = 0;
        if (materias[i]->grau == 0)
        {
            fila.push(materias[i]);
        }
    }
    // Preenchendo vetor de distancias e fila ordenada
    // Nela vai colocar a maior distancia que que a materia pode ter
    while (!fila.empty())
    {
        Materia *materia = fila.front();
        fila.pop();
        for (int i = 0; i < materia->conexoes.size(); i++)
        {
            // procura os index da materia que vai ser analisado e sua anterior
            int indexMateria = SearchMateriaIndex(materias, materia->conexoes[i]);
            int previousMateria = SearchMateriaIndex(materias, materia);

            // Vai adicionar os pesos maximos para cada materia, adicionando a distancia total da anterior
            // mais o peso dela.
            distancia[indexMateria] = max(distancia[indexMateria], distancia[previousMateria] + materia->peso);
            materia->conexoes[i]->grau--;
            if (materia->conexoes[i]->grau == 0)
            {
                fila.push(materia->conexoes[i]);
            }
        }
    }

    int Max1 = 0;
    int Max2 = 0;
    int Max3 = 0;
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;

    //Materias com a maiores distancias
    for (int i = 0; i < materias.size(); i++)
    {
        if (distancia[i] >= Max1)
        {
            Max1 = distancia[i];
            index1 = i;
        }
    }

    //Gerando caminhos criticos e retornando
    vector<vector<Materia *>> CPM;
    vector<Materia *> firstCPM = BuildPath(materias, distancia, Max1, index1);

    // Colocando os graus ao normal, ja que foram zerados
    for(int i = 0; i < materias.size(); i++){
        for(int j = 0; j < materias[i]->conexoes.size(); j++)
            materias2[i]->conexoes[j]->grau++; 
    }

    //Inicializando vetor de distancias e fila de materias
    for (int i = 0; i < materias2.size(); i++)
    {
        distancia[i] = 0;
        if (materias2[i]->grau == 0)
        {
            fila.push(materias2[i]);
        }
    }

    // Preenchendo vetor de distancias e fila ordenada
    // Nela vai colocar a maior distancia que que a materia pode ter
    while (!fila.empty())
    {
        Materia *materia = fila.front();
        fila.pop();

        // Verifica se a materia ja foi chamada nos outros caminhos criticos
        if(!SearchMateria(firstCPM,materia)){

            for (int i = 0; i < materia->conexoes.size(); i++)
            {
                // procura os index da materia que vai ser analisado e sua anterior
                int indexMateria = SearchMateriaIndex(materias2, materia->conexoes[i]);
                int previousMateria = SearchMateriaIndex(materias2, materia);

                // Vai adicionar os pesos maximos para cada materia, adicionando a distancia total da anterior
                // mais o peso dela.
                distancia[indexMateria] = max(distancia[indexMateria], distancia[previousMateria] + materia->peso);
            
                materia->conexoes[i]->grau--;
                if (materia->conexoes[i]->grau == 0)
                {
                    fila.push(materia->conexoes[i]);
                }
            }
        }
    }

    for (int i = 0; i < materias.size(); i++)
    {
        if (distancia[i] >= Max2)
        {
            Max2 = distancia[i];
            index2 = i;
        }
    }

    vector<Materia *> secondCPM = BuildPath(materias2, distancia, Max2, index2);

    // Colocando os graus ao normal, ja que foram zerados
    for(int i = 0; i < materias.size(); i++){
        for(int j = 0; j < materias[i]->conexoes.size(); j++)
            materias3[i]->conexoes[j]->grau++; 
    }
    
    //Inicializando vetor de distancias e fila de materias
    for (int i = 0; i < materias3.size(); i++)
    {
        distancia[i] = 0;
        if (materias3[i]->grau == 0)
        {
            fila.push(materias3[i]);
        }
    }

    // Preenchendo vetor de distancias e fila ordenada
    // Nela vai colocar a maior distancia que que a materia pode ter
    while (!fila.empty())
    {
        Materia *materia = fila.front();
        fila.pop();

        // Verifica se a materia ja foi chamada nos outros caminhos criticos
        if(!SearchMateria(firstCPM,materia) && !SearchMateria(secondCPM,materia)){

            for (int i = 0; i < materia->conexoes.size(); i++)
            {
                // procura os index da materia que vai ser analisado e sua anterior
                int indexMateria = SearchMateriaIndex(materias3, materia->conexoes[i]);
                int previousMateria = SearchMateriaIndex(materias3, materia);

                // Vai adicionar os pesos maximos para cada materia, adicionando a distancia total da anterior
                // mais o peso dela.
                distancia[indexMateria] = max(distancia[indexMateria], distancia[previousMateria] + materia->peso);
                materia->conexoes[i]->grau--;
                if (materia->conexoes[i]->grau == 0)
                {
                    fila.push(materia->conexoes[i]);
                }
            }
        }
    }

    for (int i = 0; i < materias.size(); i++)
    {
        if (distancia[i] >= Max3)
        {
            Max3 = distancia[i];
            index3 = i;
        }
    }

    vector<Materia *> thirdCPM = BuildPath(materias, distancia, Max3, index3);

    CPM.push_back(firstCPM);
    CPM.push_back(secondCPM);
    CPM.push_back(thirdCPM);
    return CPM;
}

