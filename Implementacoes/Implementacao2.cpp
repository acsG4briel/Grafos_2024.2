#include <iostream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

//EXERCÍCIO: Gerador de todos os subgrafos de um grafo completo com N vértices + contador de subgrafos gerados.

class GrafoCompleto {
  public:
    int num_vertices;
    list<int> *relacoes;

  public:
    GrafoCompleto(int vertices){
      this->num_vertices = vertices;
      this->relacoes = new list<int>[num_vertices];
    }

  public:
    void MontarGrafoCompleto() {
      for ( int i = 0; i < num_vertices; i++ ) {
          for ( int j = 0; j < num_vertices; j++ ) {
              if ( i != j ) {
                relacoes[i].push_back(j);
              }
          }
      }

    }

    void MostrarGrafoCompleto() {
      for(int i = 0 ; i < num_vertices ; i++) {
        cout << i << "->" ;
        for(int elemento : relacoes[i]) {
          cout << elemento << " ";
        }
        cout << endl;
      }
    }

    int ObterTodosSubgrafos() {
      int totalSubgrafos = 0;

        for (int i = 1; i < (1 << num_vertices); i++) {
          vector<int> verticesSubgrafo;
          for (int j = 0; j < num_vertices; j++) {
            if (i & (1 << j)) { 
              verticesSubgrafo.push_back(j);
            }
          }

          int numeroVerticesSubgrafo = verticesSubgrafo.size();
          
          int numeroArestasPossiveis = numeroVerticesSubgrafo * (numeroVerticesSubgrafo - 1) / 2;

          for (int k = 0; k < (1 << numeroArestasPossiveis); k++) {
            cout << "Subgrafo " << totalSubgrafos + 1 << "-> ";

            for (int v : verticesSubgrafo) {
              cout << v << " ";
            }
            cout << " com arestas { ";

            int verticeBordaIndex = 0;
            
            for (int m = 0; m < numeroVerticesSubgrafo; m++) {
              for (int n = m + 1; n < numeroVerticesSubgrafo; n++) {
                if (k & (1 << verticeBordaIndex)) { 
                  cout << "(" << verticesSubgrafo[m] << ", " << verticesSubgrafo[n] << ") ";
                }
                verticeBordaIndex++;
              }
            }
            cout << "}" << endl;

            totalSubgrafos++;
          }
        }

        return totalSubgrafos;
      }
};

int DefinirNumerosVertice() {
  int x;
  cout << "Insira o número de vértices: ";
  cin >> x;
  return x;
}

void Menu()
{
  bool menu = true;
  while(menu) {
    cout << "GERADOR DE SUBGRAFOS" << endl;
    cout << "EXECUTAR PROGRAMA - 1" << endl;
    cout << "SAIR DO PROGRAMA - 2" << endl;

    int option;
    cin >> option;

    if(option == 1) { 
      GrafoCompleto grafo(DefinirNumerosVertice());
      grafo.MontarGrafoCompleto();
      grafo.MostrarGrafoCompleto();
      int x = grafo.ObterTodosSubgrafos();

      cout << "TOTAL SUBGRAFOS: " << x << endl;
    }
    else if(option == 2) {
      menu = false;
    }
    else {
      cout << "Opção inválida." << endl;
    }
  }
}

int main() 
{ 
  Menu();
}