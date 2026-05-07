import java.util.LinkedList;
import java.util.Queue;

class Nodo {

    int dato;
    Nodo izquierda;
    Nodo derecha;

    public Nodo(int dato) {
        this.dato = dato;
        this.izquierda = null;
        this.derecha = null;
    }
}

public class Main {

    // ======================================
    // RECORRIDOS
    // ======================================

    public static void preorden(Nodo raiz) {

        if (raiz == null)
            return;

        System.out.print(raiz.dato + " ");

        preorden(raiz.izquierda);
        preorden(raiz.derecha);
    }

    public static void inorden(Nodo raiz) {

        if (raiz == null)
            return;

        inorden(raiz.izquierda);

        System.out.print(raiz.dato + " ");

        inorden(raiz.derecha);
    }

    public static void postorden(Nodo raiz) {

        if (raiz == null)
            return;

        postorden(raiz.izquierda);
        postorden(raiz.derecha);

        System.out.print(raiz.dato + " ");
    }

    public static void bfs(Nodo raiz) {

        if (raiz == null)
            return;

        Queue<Nodo> cola = new LinkedList<>();

        cola.add(raiz);

        while (!cola.isEmpty()) {

            Nodo actual = cola.poll();

            System.out.print(actual.dato + " ");

            if (actual.izquierda != null)
                cola.add(actual.izquierda);

            if (actual.derecha != null)
                cola.add(actual.derecha);
        }
    }

    // ======================================
    // CONTAR NODOS
    // ======================================
    public static int contarNodos(Nodo raiz) {

        if (raiz == null)
            return 0;

        return 1 +
               contarNodos(raiz.izquierda) +
               contarNodos(raiz.derecha);
    }

    // ======================================
    // EJERCICIO 4
    // CONTAR HOJAS
    // ======================================
    public static int contarHojas(Nodo raiz) {

        if (raiz == null)
            return 0;

        // Si no tiene hijos -> hoja
        if (raiz.izquierda == null &&
            raiz.derecha == null) {

            return 1;
        }

        return contarHojas(raiz.izquierda) +
               contarHojas(raiz.derecha);
    }

    public static void main(String[] args) {

        Nodo raiz = new Nodo(10);

        raiz.izquierda = new Nodo(5);
        raiz.derecha = new Nodo(15);

        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha = new Nodo(7);

        raiz.derecha.izquierda = new Nodo(12);
        raiz.derecha.derecha = new Nodo(20);

        // EJERCICIO 2
        raiz.izquierda.izquierda.izquierda = new Nodo(1);
        raiz.izquierda.izquierda.derecha = new Nodo(3);

        raiz.derecha.derecha.izquierda = new Nodo(18);
        raiz.derecha.derecha.derecha = new Nodo(25);

        System.out.println("RECORRIDOS DEL ARBOL");

        System.out.print("\nPreorden: ");
        preorden(raiz);

        System.out.print("\nInorden: ");
        inorden(raiz);

        System.out.print("\nPostorden: ");
        postorden(raiz);

        System.out.print("\nBFS: ");
        bfs(raiz);

        System.out.print("\n\nTotal de nodos: ");
        System.out.println(contarNodos(raiz));

        // ======================================
        // MOSTRAR TOTAL DE HOJAS
        // ======================================
        System.out.print("Total de hojas: ");
        System.out.println(contarHojas(raiz));
    }
}