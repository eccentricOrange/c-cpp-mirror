#include<stdio.h>
#include<stdexcept>

class Rational {
  private:
    int numerator, denominator;

    void checkSign() {
        if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)) {
            numerator *= -1;
            denominator *= -1;
            return;
        }
    }

    static int gcd(int a, int b) {
        if (a < 0) {
            a *= -1;
        }

        if (b < 0) {
            b *= -1;
        }

        if (a == 0 && b > 0) {
            return b;
        }

        if (a > 0 && b == 0) {
            return a;
        }

        int result = 1;

        for (int i = 1; (i <= a) && (i <= b); i++) {
            if ((a % i == 0) && (b % i == 0)) {
                result = i;
            }
        }

        return result;
    }

  public:
    void reduce() {
        const int GCD = gcd(numerator, denominator);

        numerator = numerator / GCD;
        denominator = denominator / GCD;
    }

    Rational(int n, int d) {
        numerator = n;
        denominator = d;

        if (denominator == 0) {
            throw new std::invalid_argument("Cannot divide by zero.");
        }

        checkSign();
        reduce();
    }

    Rational(int n) {
        numerator = n;
        denominator = 1;
    }

    void print() {
        if (numerator == 0) {
            printf("%d\n", 0);
            return;
        }

        if (denominator == 1) {
            printf("%d\n", numerator);
            return;
        }

        printf("%d / %d\n\n", numerator, denominator);
    }

    static Rational add(Rational a, Rational b) {
        Rational output(0);

        output.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
        output.denominator = a.denominator * b.denominator;
        output.reduce();

        return output;
    }

    static Rational subtract(Rational a, Rational b) {
        Rational output(0);

        output.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
        output.denominator = a.denominator * b.denominator;
        output.reduce();

        return output;
    }

    static Rational multiply(Rational a, Rational b) {
        Rational output(0);

        output.numerator = a.numerator * b.numerator;
        output.denominator = a.denominator * b.denominator;
        output.reduce();

        return output;
    }

    static Rational divide(Rational a, Rational b) {
        Rational output(0);

        if (b.numerator == 0) {
            throw new std::invalid_argument("Cannot divide by zero.");
        }

        output.numerator = a.numerator * b.denominator;
        output.denominator = a.denominator * b.numerator;
        output.reduce();
        output.checkSign();

        return output;
    }
};

void displayRational() {
    Rational a(2, 3);
    a.print();

    Rational b(100, 400);
    b.print();

    Rational c(4);
    c.print();

    Rational d(0, 20);
    d.print();
}

void rationalsArithmetic() {
    Rational a(2, 3);
    Rational b(-4, 2);

    printf("A is\n");
    a.print();

    printf("B is\n");
    b.print();

    printf("The sum is:\n");
    Rational::add(a, b).print();

    printf("The difference is:\n");
    Rational::subtract(a, b).print();

    printf("The product is:\n");
    Rational::multiply(a, b).print();

    printf("The quotient is:\n");
    Rational::divide(a, b).print();
}

int main(int argc, char const *argv[]) {
    displayRational();
    rationalsArithmetic();
    return 0;
}
