#include<iostream>

using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

//Funcion agregar elementos a la lista
void agregarNodo(Nodo*& cabeza, int valor) {
	Nodo* nuevoNodo = new Nodo; // Creando el apuntador hacia el nuevo nodo
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = nullptr;

	if (cabeza == nullptr) {
		cabeza = nuevoNodo;
	}
	else {
		Nodo* actual = cabeza;
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}
		actual->siguiente = nuevoNodo;
	}

}

void imprimirlista(Nodo* cabeza) {
	Nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << actual->siguiente;
		actual = actual->siguiente;
	}
	cout << endl;
}
void borrarLista(Nodo* cabeza) {
	while (cabeza != nullptr) {
		Nodo* siguiente = cabeza->siguiente;
		delete cabeza;
		cabeza = siguiente;
		cout << "Elemento borrado";
	}
}

int main() {
	Nodo* cabeza = nullptr;//Declaramos un puntero de memotia nulo
	int tamanoLista;
	cout << "ingrese la cantidad de elementos que desea agregar a la lista: ";
	cin >> tamanoLista;

	if (tamanoLista <= 0) {
		cout << "cantidad de lementos no valida" << endl;
		return 1;
	}
	for (int i = 0; 1 < tamanoLista; i++) {
		int valor;
		cout << "ingrese dato" << i + 1 << ":";
		cin >> valor;
		// invocamos nuestra funciona deagregar Nodo
		agregarNodo(cabeza, valor);
	}
	cout << " imprimiento Lista de numeros" << endl;
	imprimirlista(cabeza);

	borrarLista(cabeza);
	return 0;
}
