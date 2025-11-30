#include <iostream>
using namespace std;
template<typename T>
class vector{
    private:
    T *storage;
    unsigned int sz;
    unsigned int capacity;
    float policy;

    public:     
    vector(){
        storage = new T[5];
        sz=0;
        capacity=5;
        policy=1.7;
    }
    vector(unsigned int c, float p=1.7){
        storage = new T[c];
        sz = 0;
        capacity = c;
        policy = p;
    }
    vector(const vector<T> &other){
        sz = other.size();
        capacity = other.capacity;
        policy = other.policy;
        storage = new T[capacity];
        for(unsigned int i = 0; i < sz; i++) {
            storage[i] = other.storage[i];
        }
      
    }
    ~vector(){
        delete[] storage;
    }

    void push_back(const T& value){
        if(sz >= capacity) { 
            resize();        
        }
        storage[sz] = value;
        sz++;              
    }
    void push_back(const vector<T> &other){
        reserve(sz + other.size());
        for(unsigned int i = 0; i < other.size(); i++) {
            push_back(other.storage[i]);
        }
    }

    unsigned int size() const{
        return sz;
    }
    unsigned int get_capacity() const {
        return capacity;
    }
    void pop_back(){
        if(sz > 0) {
            sz--;
        }
    }
    
    private:
    void resize(){
        capacity *= policy;
        T *new_storage = new T[capacity];
        for(unsigned int i = 0; i < sz; i++) {
            new_storage[i] = storage[i];
        }
        delete[] storage;
        storage = new_storage;
    }
    void reserve(unsigned int new_capacity){
        if(new_capacity > capacity) {
            T *new_storage = new T[new_capacity];
            for(unsigned int i = 0; i < sz; i++) {
                new_storage[i] = storage[i];
            }
            delete[] storage;
            storage = new_storage;
            capacity = new_capacity;
        }
    }
    public:
    void shrink_to_fit(){
        if(sz < capacity) {
            capacity = sz;
            T *new_storage = new T[capacity];
            for(unsigned int i = 0; i < sz; i++) {
                new_storage[i] = storage[i];
            }
            delete[] storage;
            storage = new_storage;
        }
    }
   void printvector(const vector<T> &v) {
        for(unsigned int i = 0; i < v.size(); i++) {
            cout << v.storage[i] << " ";
        }
        cout << endl;
    }
    T& operator[](unsigned int index) {
        if(index >= sz) {
            throw out_of_range("Index out of range");
        }
        return storage[index];
    }
    const T& operator[](unsigned int index) const {
        if(index >= sz) {
            throw out_of_range("Index out of range");
        }
        return storage[index];
    }
    T& at(unsigned int index) {
        if(index >= sz) {
            throw out_of_range("Index out of range");
        }
        return storage[index];
    }
    const T& at(unsigned int index) const {
        if(index >= sz) {
            throw out_of_range("Index out of range");
        }
        return storage[index];
    }
  
};

int suma_vector(const vector<int> &v){
    int suma=0;
    for(unsigned int i=0; i<v.size(); i++){
        suma+=v[i];
    }
    return suma;
}
void reverse_vector(vector<int> &v) {
    unsigned int left = 0;
    unsigned int right = v.size() - 1;
    while(left < right) {
        int temp = v[left];
        v[left] = v[right];
        v[right] = temp;
        left++;
        right--;
    }
}
void filtropar(vector<int> &v) {
    unsigned int j = 0;
    for(unsigned int i = 0; i < v.size(); i++) {
        if(v[i] % 2 == 0) {
            v[j] = v[i];
            j++;
        }
    }
    while(v.size() > j) {
        v.pop_back();//elimina elementos impares
    }
}
void prueba_crecimiento_dinamico() {
    vector<int> u;
    unsigned int last_capacity = u.get_capacity();
    for (int i = 1; i <= 1000; i++) {
        u.push_back(i);
        if (u.get_capacity() != last_capacity) {
            cout << "Size: " << u.size() << ", Capacity: " << u.get_capacity() << endl;
            last_capacity = u.get_capacity();
        }
    }
}
vector<int> mezclavector(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    unsigned int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }
    // Agrega los elementos restantes de a
    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }
    // Agrega los elementos restantes de b
    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }
    return result;// se llama de la forma mergeSorted(a, b);
}

int main() {

     vector<int> y;
    for(int i=0; i<100; i++){
        y.push_back(i*1.5);
    };
    y.shrink_to_fit();
   reverse_vector(y);
   cout << "Elementos del vector despues de invertirlo: ";
   y.printvector(y);
    
   cout << "Elementos pares del vector: ";
    filtropar(y);
    y.printvector(y);
    
    prueba_crecimiento_dinamico();
    cout << endl;

    vector<int> a;
    for(int i=0; i<10; i++){
        a.push_back(i*2);
    };
    a.printvector(a);
    vector<int> b;
    for(int i=0; i<10; i++){
        b.push_back(i*3);
    }
    b.printvector(b);
    cout << "Elementos del vector despues de mezclarlo: ";
    vector<int> result = mezclavector(a, b);
    result.printvector(result);

    system("pause");
    return 0;
}