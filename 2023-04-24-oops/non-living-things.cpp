#include <iostream>

int main(int argc, char const *argv[]) {
    for (size_t i = 0; i < argc; i++) {
        printf(argv[i]);
        printf("\n");
    }

    return 0;
}
