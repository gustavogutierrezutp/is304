/*
Name: Juan Jose Posada Arboleda 
Teacher: Gustavo Adolfo Gutierrez
Course: Data Structures 2025-2
Date: 09/20/2025
Description: Implementation of a generic singly linked list in C++ .
    Includes the basic operations of a list:
    - Insertion and deletion at the front and back.
    - Insertion and deletion at specific positions.
    - Element access using operator [] and method at().
    - front() and back() methods to access the first and last elements.
    - Utility methods such as size(), emptyList(), print(), clear(), and reverse().
    - Copy constructor and methods to copy or concatenate lists.

    The file also contains a main function with tests for each functionality.
*/

#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>

class List{
private:
    class Node {
        private:
            T data;       // Valor almacenado en el nodo
            Node *next;   // Puntero al siguiente nodo
        public:
            // Constructor por defecto: inicializa next como nullptr
            Node() : data(), next(nullptr) {}
            // Constructor con argumento: inicializa data con v
            Node(const T& v) : data(v), next(nullptr) {}
            // Establece el puntero al siguiente nodo
            void setNext(Node *n) { next = n; }
            // Devuelve el puntero al siguiente nodo
            Node* getNext() const { return next; }
            // Devuelve una referencia al dato almacenado
            T& getData() { return data; }
            // Versión constante para acceso de solo lectura
            const T& getData() const { return data; }
    };
    Node *first;          // Puntero al primer nodo de la lista
    Node *last;           // Puntero al último nodo de la lista
    unsigned int sz;      // Tamaño actual de la lista (# de elementos)
public:
    List() : first(nullptr), last(nullptr), sz(0){}  //Constructor inicializado en 0
    ~List(){  //Destructor de la lista
        Node *temp = first;
        while (first != nullptr){
            temp = first;
            first = first->getNext();
            delete temp;
        }
        last = nullptr;
        first = nullptr;
        sz = 0;
    }
    bool emptyList() const{
        return first == nullptr && last == nullptr;
    }
    
    void push_back(const T &value){
        Node *newNode = new Node(value);
        if(!emptyList()){
            last->setNext(newNode); //Modificacion de last, para que almacene la nueva direccion de memoria del nuevo ultimo
            last = newNode; //Actualizar newnode como el nuevo ultimo, simpre se debe saber quien es el nuevo ultimo para poder que la lista se mantenga continua
        }else{
            first = newNode;
            last = newNode;
        }
        sz++;
    }

    void pop_back(){
        if(!emptyList()){
            if(sz == 1){
                delete first;
                first = nullptr;
                last = nullptr;
            }else{
                Node *temp = first;
                while(temp->getNext() != last){
                    temp = temp->getNext();
                }
                delete last;
                last = temp;
                last->setNext(nullptr);
            }
            sz--;
        }else{
            cout << "La lista esta vacia" << endl;
        }
    }
    void push_front(const T &value){
        Node *newNode = new Node(value);
        if(!emptyList()){
            newNode->setNext(first);
            first = newNode;
        }else{
            first = newNode;
            last = newNode;
        }
        sz++;
    }
    void pop_front(){
        if(!emptyList()){
            if(sz == 1){
                delete first;
                first = nullptr;
                last = nullptr;
            }else{
                Node *temp = first;
                first = first->getNext();
                delete temp;
            }
            sz--;
        }else{
            cout << "La lista esta vacia" << endl;
        }
    }
    T& front() {
        if (emptyList()) {
            throw out_of_range("La lista está vacía");
        }
        return first->getData();
    }

    const T& front() const {
        if (emptyList()) {
            throw out_of_range("La lista está vacía");
        }
        return first->getData();
    }

    T& back() {
        if (emptyList()) {
            throw out_of_range("La lista está vacía");
        }
        return last->getData();
    }

    const T& back() const {
        if (emptyList()) {
            throw out_of_range("La lista está vacía");
        }
        return last->getData();
    }

    unsigned int size(){ return sz;}

    void clear(){
        Node* actual = first;
        while(actual != nullptr){
            Node* temp = actual;
            actual = actual->getNext();
            delete temp;
        }
        first = nullptr;
        last = nullptr;
        sz = 0;
    }

    void print() const {
        Node *temp = first;
        while (temp != nullptr) {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl; 
    }
    T& operator[](unsigned int index){ //Operador de acceso a los elementos del vector, devuelve una referencia al elemento en la posicion index
        Node* actual = first;
        for (unsigned int i = 0; i < index; ++i) {
            actual = actual->getNext();
        }
        return actual->getData();
    }
    const T& operator[](unsigned int index) const{ //Version constante del operador de acceso, no permite modificar el elemento
        Node* actual = first;
        for (unsigned int i = 0; i < index; ++i) {
        actual = actual->getNext();
        }
        return actual->data;
    }

    T& at(unsigned int index){ //Version constante del operador de acceso, no permite modificar el elemento
        if(index >= sz){
            throw out_of_range("Index out of range");
        }
        Node* actual = first;
        for (unsigned int i = 0; i < index; ++i) {
        actual = actual->getNext();
        }
        return actual->data;
    }

    const T& at(unsigned int index) const{ //Version constante del operador de acceso, no permite modificar el elemento
        if(index >= sz){
            throw out_of_range("Index out of range");
        }
        Node* actual = first;
        for (unsigned int i = 0; i < index; ++i) {
        actual = actual->getNext();
        }
        return actual->data;
    }

    
    void insert(unsigned int index, const T& val) {
        if (index > sz) {
            throw out_of_range("Index out of range");
        }
        Node* nuevo = new Node(val);
        if (index == 0) { // insertar al inicio
            nuevo->setNext(first);
            first = nuevo;
            if (sz == 0) last = nuevo; // si estaba vacía
        }
        else if (index == sz) { // insertar al final
            last->setNext(nuevo);
            last = nuevo;
        } else { // insertar en el medio
           Node* actual = first;
           for (unsigned int i = 0; i < index - 1; ++i) {
                actual = actual->getNext();
            }
            nuevo->setNext(actual->getNext());
            actual->setNext(nuevo);
        }
        ++sz;
    }

    void erase(unsigned int index) {
        if (index >= sz) {
           throw std::out_of_range("Index out of range");
        }
        Node* temp;
        if (index == 0) { // eliminar cabeza
            temp = first;
            first = first->getNext();
            if (sz == 1) last = nullptr; // si solo había un nodo
        } else {
           Node* actual = first;
           for (unsigned int i = 0; i < index - 1; ++i) {
                actual = actual->getNext();
            }
            temp = actual->getNext();
            actual->setNext(temp->getNext());
            if (index == sz - 1) last = actual; // si borramos la cola
        }
        delete temp;
        --sz;
    }
    void reverse() {
        if (!first || !first->getNext()) return; // vacio o un solo nodo
        Node* prev = nullptr;
        Node* current = first;
        Node* next = nullptr;
        last = first; // el viejo first es el nuevo last
        while (current != nullptr) {
          next = current->getNext();
          current->setNext(prev);
          prev = current;
           current = next;
        }
        first = prev; // el nuevo first es el viejo last
    }

    List(const List& other) : first(nullptr), last(nullptr), sz(0){
        Node* actual = other.first;
        while(actual != nullptr){
            this->push_back(actual->getData());
            actual = actual->getNext();
        }
    }

    void push_back(const List &other) {
        Node* actual = other.first;
        while(actual != nullptr){
            this->push_back(actual->getData());
            actual = actual->getNext();
        }
    }

    void push_front(const List &other) {
        // Creamos una lista temporal para mantener el orden
        List temp;
        Node* actual = other.first;
        // Copiamos todos los elementos de 'other' a 'temp'
        while(actual != nullptr){
            temp.push_back(actual->getData());
         actual = actual->getNext();
        }
        // Ahora insertamos los elementos de 'temp' al frente de nuestra lista
        // Los insertamos en orden inverso para mantener el orden original de 'other'
        for(int i = temp.size() - 1; i >= 0; i--){
            this->push_front(temp[i]);
        }
    }
};

//Main donde se prueban los metodos solicitados en el taller:
int main(){
    List<int> v;
    cout << "Tamaño inicial: " << v.size() << endl;
    v.print();
    cout << "\n=== Insertando 10 elementos con push_back ===" << endl;
    for(int i = 0; i < 10; i++){
        v.push_back(i+1);
        cout << "Insertado: " << i+1 << " -> ";
        v.print();
    }


    cout << "\n=== Ejecutando push front ===" << endl;
    v.push_front(100);
    v.push_front(200);
    v.print();

    cout << "\n=== Eliminando el último elemento ===" << endl;
    v.pop_back();
    v.print();

    cout << "\n=== Eliminando el primer elemento ===" << endl;
    v.pop_front();
    v.print();

    cout << "\n=== Insertando en posición específica ===" << endl;
    v.insert(2, 999);
    v.print();

    cout << "\n=== Eliminando en posición específica ===" << endl;
    v.erase(2);
    v.print();

    cout << "\n=== Accediendo con [] ===" << endl;
    for(unsigned int i = 0; i < v.size(); i++){
        cout << "v[" << i << "] = " << v[i] << endl;
    }

    cout << "\n=== Accediendo con at() ===" << endl;
    try {
        cout << "Elemento en posición 3: " << v.at(3) << endl;
    } catch(const out_of_range& e){
        cout << e.what() << endl;
    }

    cout << "\n=== Accediendo al frente y al final ===" << endl;
    cout << "Primer elemento: " << v.front() << endl;
    cout << "Último elemento: " << v.back() << endl;

    // 11. Crear otra lista para concatenar con push_back
    cout << "\n=== Creando otra lista m ===" << endl;
    List<int> m;
    m.push_back(500);
    m.push_back(600);
    m.push_back(700);
    cout << "Lista m: ";
    m.print();

    cout << "\n=== Concatenando m al final de v ===" << endl;
    v.push_back(m);
    v.print();

    cout << "\n=== Insertando lista m al frente de v ===" << endl;
    v.push_front(m);
    v.print();

    cout << "\n=== Creando lista copia c desde v ===" << endl;
    List<int> c(v);
    cout << "Lista c (copia de v): ";
    c.print();

    cout << "\n=== Probando reverse() en lista v ===" << endl;
    cout << "Lista v antes de reverse: ";
    v.print();
    v.reverse();
    cout << "Lista v después de reverse: ";
    v.print();

    cout << "\n=== Probando clear() ===" << endl;
    cout << "Lista v antes de clear: ";
    v.print();
    cout << "Tamaño: " << v.size() << endl;
    v.clear();
    cout << "Lista v después de clear: ";
    v.print();
    cout << "Tamaño: " << v.size() << endl;
    return 0;
}