#include <stdio.h>

class Complex {
   private:
    double real = 0;
    double imaginary = 0;

   public:
    Complex(double realIn, double imaginaryIn);
    Complex(double realIn);
    Complex();

    void print();
    static Complex conjugate(Complex complexIn);

    static Complex add(Complex a, Complex b);
    static Complex add(Complex a, double b);

    static Complex subtract(Complex a, Complex b);
    static Complex subtract(Complex a, double b);

    static Complex multiply(Complex a, Complex b);
    static Complex multiply(Complex a, double b);

    static Complex divide(Complex a, Complex b);
    static Complex divide(Complex a, double b);

    ~Complex();
};

Complex::Complex(double realIn, double imaginaryIn) {
    real = realIn;
    imaginary = imaginaryIn;
}

Complex::Complex(double realIn) {
    real = realIn;
    imaginary = 0;
}

Complex::~Complex() {
}

void Complex::print() {
    if (real != 0 && imaginary == 0) {
        printf("%f", real);
    }

    else if (real == 0 && imaginary != 0) {
        printf("%.4fj\n", imaginary);
    }

    else {
        printf("%.4f", real);

        if (imaginary > 0) {
            printf("+");
        }

        printf("%.4fj\n", imaginary);
    }
}

Complex Complex::conjugate(Complex complexIn) {
    return Complex(
        complexIn.real,
        -1 * complexIn.imaginary
    );
}

Complex Complex::add(Complex a, Complex b) {
    return Complex(
        a.real + b.real,
        a.imaginary + b.imaginary
    );
}

Complex Complex::add(Complex a, double b) {
    return Complex(
        a.real + b,
        a.imaginary
    );
}

Complex Complex::subtract(Complex a, Complex b) {
    return Complex(
        a.real - b.real,
        a.imaginary - b.imaginary
    );
}

Complex Complex::subtract(Complex a, double b) {
    return Complex(
        a.real - b,
        a.imaginary
    );
}

Complex Complex::multiply(Complex a, Complex b) {
    return Complex(
        a.real * b.real - a.imaginary * b.imaginary,
        a.real * b.imaginary + a.imaginary * b.real
    );
}

Complex Complex::multiply(Complex a, double b) {
    return Complex(
        a.real * b,
        a.imaginary * b
    );
}

Complex Complex::divide(Complex a, double b) {
    return Complex(
        a.real / b,
        a.imaginary / b
    );
}

Complex Complex::divide(Complex a, Complex b) {
    const Complex CONJUGATE = Complex::conjugate(b);

    return Complex::divide(
        Complex::multiply(a, CONJUGATE),
        Complex::multiply(b, CONJUGATE).real
    );
}

void complexNumbers() {
    Complex a(4, 3);
    a.print();

    Complex b(4);
    b.print();

    Complex c(4, -3);
    c.print();
}

void complexArithmetic() {
    Complex a(3, 5);
    Complex b(5, -8);
    double scalar = 3;

    Complex::add(a, scalar).print();
    Complex::subtract(a, scalar).print();
    Complex::multiply(a, scalar).print();
    Complex::divide(a, scalar).print();

    Complex::add(a, b).print();
    Complex::subtract(a, b).print();
    Complex::multiply(a, b).print();
    Complex::divide(a, b).print();
}

int main(int argc, char const *argv[]) {
    complexNumbers();
    complexArithmetic();

    return 0;
}
