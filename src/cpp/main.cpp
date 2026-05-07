#include <iostream>
#include <queue>

using namespace std;

// ======================================
// ESTRUCTURA DEL NODO
// ======================================
struct Nodo {
    string dato;
    Nodo* izquierda;
    Nodo* derecha;

    // Constructor
    Nodo(string valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

// ======================================
// PREORDEN
// Raíz -> Izquierda -> Derecha
// ======================================
void preorden(Nodo* raiz) {

    if (raiz == nullptr)
        return;

    cout << raiz->dato << " ";

    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

// ======================================
// INORDEN
// Izquierda -> Raíz -> Derecha
// ======================================
void inorden(Nodo* raiz) {

    if (raiz == nullptr)
        return;

    inorden(raiz->izquierda);

    cout << raiz->dato << " ";

    inorden(raiz->derecha);
}

// ======================================
// POSTORDEN
// Izquierda -> Derecha -> Raíz
// ======================================
void postorden(Nodo* raiz) {

    if (raiz == nullptr)
        return;

    postorden(raiz->izquierda);
    postorden(raiz->derecha);

    cout << raiz->dato << " ";
}

// ======================================
// BFS
// Recorrido por niveles
// ======================================
void bfs(Nodo* raiz) {

    if (raiz == nullptr)
        return;

    queue<Nodo*> cola;

    cola.push(raiz);

    while (!cola.empty()) {

        Nodo* actual = cola.front();
        cola.pop();

        cout << actual->dato << " ";

        // Insertar hijos
        if (actual->izquierda != nullptr)
            cola.push(actual->izquierda);

        if (actual->derecha != nullptr)
            cola.push(actual->derecha);
    }
}

int main() {

    // ======================================
    // ÁRBOL DEL SISTEMA WEB
    // ======================================

    Nodo* raiz = new Nodo("Sistema Web");

    raiz->izquierda = new Nodo("Usuarios");
    raiz->derecha = new Nodo("Inventario");

    raiz->izquierda->izquierda = new Nodo("Registrar");
    raiz->izquierda->derecha = new Nodo("Buscar");

    raiz->derecha->izquierda = new Nodo("Productos");
    raiz->derecha->derecha = new Nodo("Reportes");

    // ======================================
    // MOSTRAR RECORRIDOS
    // ======================================

    cout << "SISTEMA WEB - ARBOL BINARIO" << endl;

    cout << "\n\nPreorden: ";
    preorden(raiz);

    cout << "\nInorden: ";
    inorden(raiz);

    cout << "\nPostorden: ";
    postorden(raiz);

    cout << "\nBFS: ";
    bfs(raiz);

    // ======================================
    // EXPLICACIÓN DE RECORRIDOS
    // ======================================

    cout << "\n\n===== APLICACION DE RECORRIDOS =====";

    cout << "\n\n1. Mostrar el menu principal:";
    cout << "\nSe recomienda BFS porque muestra";
    cout << "\nlos modulos nivel por nivel.";

    cout << "\n\n2. Procesar primero modulos internos:";
    cout << "\nSe recomienda Postorden porque";
    cout << "\nprocesa primero los hijos.";

    cout << "\n\n3. Mostrar primero el modulo principal:";
    cout << "\nSe recomienda Preorden porque";
    cout << "\nvisita primero la raiz.";

    cout << endl;

    return 0;
}