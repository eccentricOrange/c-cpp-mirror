#include <iostream>
#include <string>
#include <vector>

class Point {
   private:
    int x, y, z;

   public:
    Point(int xIn, int yIn, int zIn) {
        x = xIn;
        y = yIn;
        z = zIn;
    }

    operator std::string() {
        char charRepr[100];
        sprintf(charRepr, "(%d, %d, %d)", x, y, z);
        return std::string(charRepr);
    }
};

std::ostream &operator<<(std::ostream &outputStream, Point &point) {
    return outputStream << std::string(point);
}

template <typename DATATYPE>
class VectorWrapper : std::vector<DATATYPE> {
   public:
    void print();
    using vector::push_back;
};

template <typename DATATYPE>
void VectorWrapper<DATATYPE>::print() {
    const std::size_t length = size();
    printf("Vector [%d]: ", length);

    for (std::size_t i = 0; i < length; i++) {
        printf("%s ", std::string(this.at(i)).c_str());
    }

    printf("\n");
}

int main(int argc, char const *argv[]) {
    VectorWrapper<Point> points;
    points.push_back(Point(1, 2, 3));
    return 0;
}
