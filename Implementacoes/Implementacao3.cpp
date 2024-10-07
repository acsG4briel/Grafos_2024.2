#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

//EXERCÍCIO: Implementar algoritmos de busca Djikstra, min-max, max-min e entender suas aplicações.

class Grafo 
{
  public:
      int numeroDeVertices; 
      vector<list<pair<int, int>>> adjacencias;
  
      Grafo(int vertices) : numeroDeVertices(vertices) 
      {
          adjacencias.resize(vertices);
      }

      void adicionarAresta(int origem, int destino, int peso)
      {
          adjacencias[origem]
            .push_back(make_pair(destino, peso));
      }
};

class BuscaDijkstra 
{
  public:
      vector<int> calcularMenorCaminho(Grafo& grafo, int origem, int destino) 
      {
          vector<int> distancia(grafo.numeroDeVertices, INT_MAX);
          vector<int> predecessor(grafo.numeroDeVertices, -1);

          vector<int> caminho;
  
          priority_queue<pair<int, int>> fila;
  
          distancia[origem] = 0;
          fila.push(make_pair(0, origem));
  
          while (!fila.empty()) 
          {
              int u = fila.top().second; 
              fila.pop();
  
              for (const auto& par : grafo.adjacencias[u]) 
              {
                  int v = par.first;  
                  int peso = par.second;  
  
                  if (distancia[u] + peso < distancia[v]) 
                  {
                      distancia[v] = distancia[u] + peso;
                      predecessor[v] = u;
                      fila.push(make_pair(distancia[v], v));
                  }
              }
          }

          for (int v = destino; v != -1; v = predecessor[v]) {
              caminho.push_back(v);
          }

          reverse(caminho.begin(), caminho.end());

          return caminho;
      }
};

class BuscaMinMax 
{
  public:
      vector<int> calcularMenorCaminho(Grafo& grafo, int origem, int destino) 
      {
          vector<int> distancia(grafo.numeroDeVertices, INT_MAX);
          vector<int> predecessor(grafo.numeroDeVertices, -1);

          vector<int> caminho;

          priority_queue<pair<int, int>> fila;

          distancia[origem] = 0;
          fila.push(make_pair(0, origem));

          while (!fila.empty()) 
          {
              int u = fila.top().second; 
              fila.pop();

              for (const auto& par : grafo.adjacencias[u]) 
              {
                  int v = par.first;  
                  int peso = par.second; 

                  int novoMaximo = max(distancia[u], peso);

                  if (novoMaximo < distancia[v]) 
                  {
                      distancia[v] = novoMaximo;
                      predecessor[v] = u;
                      fila.push(make_pair(distancia[v], v));
                  }
              }
          }

          for (int v = destino; v != -1; v = predecessor[v]) {
              caminho.push_back(v);
          }

          reverse(caminho.begin(), caminho.end());

          return caminho;
      }
};

class BuscaMaxMin 
{
  public:
    vector<int> calcularMenorCaminho(Grafo& grafo, int origem, int destino) 
    {
        vector<int> distancia(grafo.numeroDeVertices, INT_MIN);
        vector<int> predecessor(grafo.numeroDeVertices, -1);
        vector<int> caminho;
    
        distancia[origem] = INT_MAX; 
        priority_queue<pair<int, int>> fila;
      
        fila.push(make_pair(INT_MAX, origem)); 
    
        while (!fila.empty()) 
        {
            int u = fila.top().second; 
            fila.pop();
    
            for (const auto& par : grafo.adjacencias[u]) 
            {
                int v = par.first;  
                int peso = par.second; 
    
                int novoMinimo = min(distancia[u], peso);
    
                if (novoMinimo > distancia[v]) 
                {
                    distancia[v] = novoMinimo;
                    predecessor[v] = u;
                    fila.push(make_pair(distancia[v], v));
                }
            }
        }
    
        for (int v = destino; v != -1; v = predecessor[v]) {
            caminho.push_back(v);
        }
    
        reverse(caminho.begin(), caminho.end());
    
        return caminho;
    }
};

void ExecutarBuscaDjikstra(Grafo& grafo, int origem, int destino)
{
    BuscaDijkstra buscaDjikstra;
  
    vector<int> menorCaminhoDjikstra = buscaDjikstra.calcularMenorCaminho(grafo, origem, destino);
  
    cout << "Menor caminho djikstra:" << endl;
    for (int vertice : menorCaminhoDjikstra) 
    {
        cout << vertice << " ";
    }
    cout << endl;
}

void ExecutarBuscaMinMax(Grafo& grafo, int origem, int destino)
{
    BuscaMinMax buscaMinMax;
  
    vector<int> menorCaminhoMinMax = buscaMinMax.calcularMenorCaminho(grafo, origem, destino);
  
    cout << "Menor caminho min-max:" << endl;
    for (int vertice : menorCaminhoMinMax) 
    {
        cout << vertice << " ";
    }
    cout << endl;
}

void ExecutarBuscaMaxMin(Grafo& grafo, int origem, int destino)
{
    BuscaMaxMin buscaMaxMin;
  
     vector<int> menorCaminhoMaxMin = buscaMaxMin.calcularMenorCaminho(grafo, origem, destino);
  
     cout << "Menor caminho max-min:" << endl;
     for (int vertice : menorCaminhoMaxMin) 
     {
         cout << vertice << " ";
     }
     cout << endl;
}

int main() 
{
    Grafo grafo(6);

    grafo.adicionarAresta(0, 1, 5);
    grafo.adicionarAresta(0, 4, 2);
    grafo.adicionarAresta(1, 3, 2);
    grafo.adicionarAresta(1, 4, 7);
    grafo.adicionarAresta(4, 2, 1);
    grafo.adicionarAresta(4, 5, 10);
    grafo.adicionarAresta(2, 3, 3);
    grafo.adicionarAresta(3, 5, 4);

    int origem = 0;
    int destino = 5;

    ExecutarBuscaDjikstra(grafo, origem, destino);

    ExecutarBuscaMinMax(grafo, origem, destino);

    ExecutarBuscaMaxMin(grafo, origem, destino);
}