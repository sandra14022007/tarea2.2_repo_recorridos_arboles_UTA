import java.util.LinkedList;
import java.util.Queue;

// ======================================
// CLASE NODO
// ======================================
class Nodo {

    String dato;
    Nodo izquierda;
    Nodo derecha;

    public Nodo(String dato) {
        this.dato = dato;
        this.izquierda = null;
        this.derecha = null;
    }
}

public class Main {

    // ======================================
    // PREORDEN
    // ======================================
    public static void preorden(Nodo raiz) {

        if (raiz == null)
            return;

        System.out.print(raiz.dato + " ");

        preorden(raiz.izquierda);
        preorden(raiz.derecha);
    }

    // ======================================
    // INORDEN
    // ======================================
    public static void inorden(Nodo raiz) {

        if (raiz == null)
            return;

        inorden(raiz.izquierda);

        System.out.print(raiz.dato + " ");

        inorden(raiz.derecha);
    }

    // ======================================
    // POSTORDEN
    // ======================================
    public static void postorden(Nodo raiz) {

        if (raiz == null)
            return;

        postorden(raiz.izquierda);
        postorden(raiz.derecha);

        System.out.print(raiz.dato + " ");
    }

    // ======================================
    // BFS
    // ======================================
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

    public static void main(String[] args) {

        // ======================================
        // ÁRBOL DEL SISTEMA WEB
        // ======================================

        Nodo raiz = new Nodo("Sistema Web");

        raiz.izquierda = new Nodo("Usuarios");
        raiz.derecha = new Nodo("Inventario");

        raiz.izquierda.izquierda = new Nodo("Registrar");
        raiz.izquierda.derecha = new Nodo("Buscar");

        raiz.derecha.izquierda = new Nodo("Productos");
        raiz.derecha.derecha = new Nodo("Reportes");

        // ======================================
        // MOSTRAR RECORRIDOS
        // ======================================

        System.out.println("SISTEMA WEB - ARBOL BINARIO");

        System.out.print("\nPreorden: ");
        preorden(raiz);

        System.out.print("\nInorden: ");
        inorden(raiz);

        System.out.print("\nPostorden: ");
        postorden(raiz);

        System.out.print("\nBFS: ");
        bfs(raiz);

        // ======================================
        // EXPLICACIÓN DE RECORRIDOS
        // ======================================

        System.out.println("\n\n===== APLICACION DE RECORRIDOS =====");

        System.out.println("\n1. Mostrar el menu principal:");
        System.out.println("Se recomienda BFS porque muestra");
        System.out.println("los modulos nivel por nivel.");

        System.out.println("\n2. Procesar primero modulos internos:");
        System.out.println("Se recomienda Postorden porque");
        System.out.println("procesa primero los hijos.");

        System.out.println("\n3. Mostrar primero el modulo principal:");
        System.out.println("Se recomienda Preorden porque");
        System.out.println("visita primero la raiz.");
    }
}