#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

void pushTareaCola(queue<string>& tareaCola, const string& elemento) {
    tareaCola.push(elemento);
}

void pushTareaPila(stack<string>& tareaPila, const string& elemento) {
    tareaPila.push(elemento);
}

void terminarTareaAntigua(queue<string>& tareaCola) {
    if (!tareaCola.empty()) {
        cout << "Tarea completada: " << tareaCola.front() << endl;
        tareaCola.pop();
    }
    else {
        cout << "No hay tareas por completar\n";
    }
}

void terminarTareaVieja(stack<string>& tareaPila) {
    if (!tareaPila.empty()) {
        cout << "Tarea completada: " << tareaPila.top() << endl;
        tareaPila.pop();
    }
    else {
        cout << "No hay tareas por completar\n";
    }
}

void mostrarTareas(const stack<string>& tareaPila, const queue<string>& tareaCola) {
    if (tareaPila.empty() && tareaCola.empty()) {
        cout << "No hay tareas en la lista.\n";
        return;
    }

    cout << "\nTareas en la pila:\n";
    stack<string> tempPila = tareaPila;
    while (!tempPila.empty()) {
        cout << tempPila.top() << endl;
        tempPila.pop();
    }

    cout << "\nTareas en la cola:\n";
    queue<string> tempCola = tareaCola;
    while (!tempCola.empty()) {
        cout << tempCola.front() << endl;
        tempCola.pop();
    }
}


void tareas() {
    int opcion;
    string tarea;

    queue<string> tareaCola;
    stack<string> tareaPila;

    do {
        cout << "\n\tMenu para las tareas\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Terminar tarea mas antigua\n";
        cout << "3. Terminar tarea mas reciente\n";
        cout << "4. Mostrar todas las tareas\n";
        cout << "5. Salir\n";

        cout << "Opción: ";
        cin >> opcion;
        cin.ignore();
        system("cls");
        switch (opcion) {
        case 1:
            cout << "Ingresa la tarea: ";
            getline(cin, tarea);
            pushTareaCola(tareaCola, tarea);
            pushTareaPila(tareaPila, tarea);
            break;
        case 2:
            terminarTareaAntigua(tareaCola);
            break;
        case 3:
            terminarTareaVieja(tareaPila);
            break;
        case 4:
            mostrarTareas(tareaPila, tareaCola);
            break;
        case 5:
            cout << "Has salido del programa\n";
            break;
        default:
            cout << "Opcion invalida\n";
            break;
        }
    } while (opcion != 5);
}

int main() {
    tareas();
    return 0;
}
