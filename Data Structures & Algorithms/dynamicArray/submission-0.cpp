class DynamicArray {
    int * arr;
    int size;
    int capacity;
public:

    DynamicArray(int capacity) {
        this->arr = new int[capacity];
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int i) {
        if(i < size)
            return arr[i];
    }

    void set(int i, int n) {
        if(i < size)
            arr[i] = n;
    }

    void pushback(int n) {
        if(capacity == size) 
            this->resize();
        arr[size++] = n;
    }

    int popback() {
        int ret = arr[size - 1];
        size--;
        return ret;
    }

    void resize() {
        this->capacity = this->capacity * 2;
        int * new_arr = new int[this->capacity];
        for(int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        delete [] arr;
        arr = new_arr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
