#include <iostream>

class Array {
   private:
    size_t _length;

   public:
    int* data;

    Array(size_t length);
    void print();
    void populate();
    ~Array();
};

Array::Array(size_t length) {
    _length = length;
    data = new int[length];
}

void Array::print() {
    printf("\n[%d] array\n", _length);

    for (size_t count = 0; count < _length; count++) {
        printf("%d\t", data[count]);

        if ((count + 1) % 5 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

void Array::populate() {
    for (size_t count = 0; count < _length; count++) {
        data[count] = count;
    }
}

Array::~Array() {}

void arrays() {
    Array array(30);

    array.print();
    array.populate();
    array.print();
}

int main(int argc, char const* argv[]) {
    arrays();
    return 0;
}
