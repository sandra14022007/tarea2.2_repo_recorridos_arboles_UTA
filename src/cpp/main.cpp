#include <iostream>
#include <queue>

using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

// ===============================
// RECORRIDOS
// ===============================
void preorden(Nodo* raiz) {

    if (raiz == nullptr)
        return;

    cout << raiz->dato << " ";

    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

void inorden(Nodo* raiz) {

    if (raiz == nullptr)
        return;

    inorden(raiz->izquierda);

    cout << raiz->dato << " ";

    inorden(raiz->derecha);
}

void postorden(Nodo* raiz) {

    if (raiz == nullptr)
        return;

    postorden(raiz->izquierda);
    postorden(raiz->derecha);

    cout << raiz->dato << " ";
}

void bfs(Nodo* raiz) {

    if (raiz == nullptr)
        return;

    queue<Nodo*> cola;

    cola.push(raiz);

    while (!cola.empty()) {

        Nodo* actual = cola.front();
        cola.pop();

        cout << actual->dato << " ";

        if (actual->izquierda != nullptr)
            cola.push(actual->izquierda);

        if (actual->derecha != nullptr)
            cola.push(actual->derecha);
    }
}

// ===============================
// CONTAR NODOS
// ===============================
int contarNodos(Nodo* raiz) {

    if (raiz == nullptr)
        return 0;

    return 1 +
           contarNodos(raiz->izquierda) +
           contarNodos(raiz->derecha);
}

// ===============================
// EJERCICIO 4
// CONTAR HOJAS
// ===============================
int contarHojas(Nodo* raiz) {

    if (raiz == nullptr)
        return 0;

    // Si no tiene hijos -> hoja
    if (raiz->izquierda == nullptr &&
        raiz->derecha == nullptr) {

        return 1;
    }

    return contarHojas(raiz->izquierda) +
           contarHojas(raiz->derecha);
}

int main() {

    Nodo* raiz = new Nodo(10);

    raiz->izquierda = new Nodo(5);
    raiz->derecha = new Nodo(15);

    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha = new Nodo(7);

    raiz->derecha->izquierda = new Nodo(12);
    raiz->derecha->derecha = new Nodo(20);

    // EJERCICIO 2
    raiz->izquierda->izquierda->izquierda = new Nodo(1);
    raiz->izquierda->izquierda->derecha = new Nodo(3);

    raiz->derecha->derecha->izquierda = new Nodo(18);
    raiz->derecha->derecha->derecha = new Nodo(25);

    cout << "RECORRIDOS DEL ARBOL" << endl;

    cout << "\nPreorden: ";
    preorden(raiz);

    cout << "\nInorden: ";
    inorden(raiz);

    cout << "\nPostorden: ";
    postorden(raiz);

    cout << "\nBFS: ";
    bfs(raiz);

    cout << "\n\nTotal de nodos: "
         << contarNodos(raiz);

    // ===============================
    // MOSTRAR TOTAL DE HOJAS
    // ===============================
    cout << "\nTotal de hojas: "
         << contarHojas(raiz);

    cout << endl;

    return 0;
}