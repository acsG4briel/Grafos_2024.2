#include <iostream>

using namespace std;

// IMPLEMENTAÇÃO 1 - GABRIEL ARAUJO CAMPOS SILVA

class Celula {
public:
  int data;
  Celula *prox;

public:
  Celula(int data) {
    this->data = data;
    this->prox = nullptr;
  }
};

class CelulaMatriz {
public:
  int data;
  CelulaMatriz *inf;
  CelulaMatriz *sup;
  CelulaMatriz *esq;
  CelulaMatriz *dir;

public:
  CelulaMatriz(int data) {
    this->data = data;
    this->inf = nullptr;
    this->sup = nullptr;
    this->esq = nullptr;
    this->dir = nullptr;
  }
};

// QUESTAO 1 - Implementação de uma lista encadeada
class Lista {
public:
  Celula *inicio;

public:
  Lista() { this->inicio = nullptr; }

  // Metodos para adicionar, remover e mostrar os elementos
public:
  void Inserir(int data, int pos) {
    Celula *novaCelula = new Celula(data);

    if (pos == 0) {
      novaCelula->prox = inicio;
      inicio = novaCelula;
    } else {
      Celula *temp = inicio;
      for (int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->prox;
      }
      if (temp != nullptr) {
        novaCelula->prox = temp->prox;
        temp->prox = novaCelula;
      }
    }
  }

  void InserirInicio(int data) {
    Celula *novaCelula = new Celula(data);
    novaCelula->prox = inicio;
    inicio = novaCelula;
  }

  void InserirFim(int data) {
    Celula *novaCelula = new Celula(data);
    if (inicio == nullptr) {
      inicio = novaCelula;
    } else {
      Celula *temp = inicio;
      while (temp->prox != nullptr) {
        temp = temp->prox;
      }
      temp->prox = novaCelula;
    }
  }

  int Remover(int pos) {
    if (inicio == nullptr) {
      cout << "Lista vazia!" << endl;
    }

    Celula *temp = inicio;
    for (int i = 0; i < pos - 1 && temp->prox != nullptr; i++) {
      temp = temp->prox;
    }

    Celula *celulaRemovida = temp->prox;
    int data = celulaRemovida->data;
    temp->prox = celulaRemovida->prox;
    delete celulaRemovida;
    return data;
  }

  int RemoverInicio() {
    if (inicio == nullptr) {
      cout << "Lista vazia!" << endl;
    }
    Celula *temp = inicio;
    int data = temp->data;
    inicio = inicio->prox;
    delete temp;
    return data;
  }

  int RemoverFim() {
    if (inicio->prox == nullptr) {
      int data = inicio->data;
      delete inicio;
      inicio = nullptr;
      return data;
    }

    Celula *temp = inicio;
    while (temp->prox->prox != nullptr) {
      temp = temp->prox;
    }

    Celula *celulaRemovida = temp->prox;
    int data = celulaRemovida->data;
    temp->prox = nullptr;
    delete celulaRemovida;
    return data;
  }

  void Mostrar() {
    Celula *temp = inicio;
    while (temp != nullptr) {
      cout << temp->data << endl;
      temp = temp->prox;
    }
  }
};

// QUESTAO 2 - Implementação de uma pilha
class Pilha {
public:
  Celula *inicio;

public:
  Pilha() { this->inicio = nullptr; }

  // Metodos para adicionar, remover e mostrar os elementos
public:
  void InserirFim(int data) {
    Celula *novaCelula = new Celula(data);
    if (inicio == nullptr) {
      inicio = novaCelula;
    } else {
      Celula *temp = inicio;
      while (temp->prox != nullptr) {
        temp = temp->prox;
      }
      temp->prox = novaCelula;
    }
  }

  int RemoverFim() {
    if (inicio->prox == nullptr) {
      int data = inicio->data;
      delete inicio;
      inicio = nullptr;
      return data;
    }

    Celula *temp = inicio;
    while (temp->prox->prox != nullptr) {
      temp = temp->prox;
    }

    Celula *celulaRemovida = temp->prox;
    int data = celulaRemovida->data;
    temp->prox = nullptr;
    delete celulaRemovida;
    return data;
  }

  void Mostrar() {
    Celula *temp = inicio;
    while (temp != nullptr) {
      cout << temp->data << endl;
      temp = temp->prox;
    }
  }
};

// QUESTAO 3 - Implementação de uma fila
class Fila {
public:
  Celula *inicio;

public:
  Fila() { this->inicio = nullptr; }

  // Metodos para adicionar, remover e mostrar os elementos
public:
  void InserirFim(int data) {
    Celula *novaCelula = new Celula(data);
    if (inicio == nullptr) {
      inicio = novaCelula;
    } else {
      Celula *temp = inicio;
      while (temp->prox != nullptr) {
        temp = temp->prox;
      }
      temp->prox = novaCelula;
    }
  }

  int RemoverInicio() {
    if (inicio == nullptr) {
      cout << "Lista vazia!" << endl;
    }
    Celula *temp = inicio;
    int data = temp->data;
    inicio = inicio->prox;
    delete temp;
    return data;
  }

  void Mostrar() {
    Celula *temp = inicio;
    while (temp != nullptr) {
      cout << temp->data << endl;
      temp = temp->prox;
    }
  }
};

// QUESTAO 4 -  Implementação de uma matriz de inteiros
class Matriz {
public:
  CelulaMatriz *inicio;
  int linhas, colunas;

public:
  Matriz(int linhas, int colunas) : linhas(linhas), colunas(colunas) {
    inicio = new CelulaMatriz(0);
    CelulaMatriz *tmp = inicio;

    for (int c = 1; c < colunas; ++c) {
      tmp->dir = new CelulaMatriz(0);
      tmp->dir->esq = tmp;
      tmp = tmp->dir;
    }

    tmp = inicio;

    for (int l = 1; l < linhas; ++l) {
      tmp->inf = new CelulaMatriz(0);
      tmp->inf->sup = tmp;
      tmp = tmp->inf;
      CelulaMatriz *aux = tmp;

      for (int c = 1; c < colunas; ++c) {
        tmp->dir = new CelulaMatriz(0);
        tmp->dir->esq = tmp;
        tmp->dir->sup = tmp->sup->dir;
        tmp->sup->dir->inf = tmp->dir;
        tmp = tmp->dir;
      }

      tmp = aux;
    }
  }

public:
  void construirMatriz(int *elementos) {
    CelulaMatriz *tmp = inicio;
    CelulaMatriz *aux = inicio;
    int pos = 0;

    for (int l = 0; l < linhas; ++l) {
      while (tmp != nullptr) {
        tmp->data = elementos[pos++];
        tmp = tmp->dir;
      }
      aux = aux->inf;
      tmp = aux;
    }
  }

  int removerElemento(int linha, int coluna) {
    CelulaMatriz *tmp = inicio;
    CelulaMatriz *aux = inicio;

    for (int i = 1; i <= linha; i++) {
      if (i > 1) {
        aux = aux->inf;
      }
      tmp = aux;

      int c = 1;
      while (tmp != nullptr) {
        if (i == linha && c == coluna) {
          int elementoRemovido = tmp->data;
          tmp->data = -1;
          return elementoRemovido;
        }
        tmp = tmp->dir;
        c++;
      }
    }

    return 0;
  }

  void mostrarMatriz() const {
    CelulaMatriz *tmp = inicio;
    CelulaMatriz *aux = inicio;

    for (int l = 0; l < linhas; ++l) {
      while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->dir;
      }
      cout << endl;
      aux = aux->inf;
      tmp = aux;
    }
  }
};

int main() {
  // QUESTAO 1
  Lista lista;
  lista.InserirInicio(5);
  lista.Inserir(4, 1);
  lista.Inserir(3, 2);
  lista.Inserir(2, 3);
  lista.InserirFim(1);

  lista.Mostrar();

  int x = lista.Remover(2);
  int y = lista.RemoverInicio();
  int z = lista.RemoverFim();

  cout << x;
  cout << y;
  cout << z;
  cout << endl;

  // QUESTAO 2
  Pilha pilha;
  pilha.InserirFim(1);
  pilha.InserirFim(2);
  pilha.InserirFim(3);

  pilha.Mostrar();

  int a = pilha.RemoverFim();

  cout << a;
  cout << endl;

  // QUESTAO 3
  Fila fila;
  fila.InserirFim(1);
  fila.InserirFim(2);
  fila.InserirFim(3);

  fila.Mostrar();

  int b = fila.RemoverInicio();

  cout << b;
  cout << endl;

  // QUESTÃO 4
  Matriz matriz(3, 3);

  int elementos[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  matriz.construirMatriz(elementos);

  matriz.mostrarMatriz();

  int g = matriz.removerElemento(2, 2);

  cout << g << endl;

  matriz.mostrarMatriz();

  return 0;
}