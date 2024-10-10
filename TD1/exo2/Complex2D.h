//
// Created by Maxime Sanciaume on 10/10/2024.
//

#ifndef COMPLEX2D_H
#define COMPLEX2D_H

class Complex2D {
private:
    double real;
    double imag;

public:
    // constructors
    Complex2D(double real, double imag);
    Complex2D(double real);
    Complex2D(Complex2D &c);
    Complex2D();

    // getters/setters
    double getReal() const;
    void setReal(double real);

    double getImag() const;
    void setImag(double imag);

    //to simplify operations
    static Complex2D symetric(const Complex2D &c);
    static Complex2D conjugate(const Complex2D &c);
    static Complex2D inverse(const Complex2D &c);
    static Complex2D rotate(const Complex2D &c, double angle);
    static double norm(const Complex2D &c);

    //for operations
    Complex2D operator+(const Complex2D &c);
    Complex2D operator-(const Complex2D &c);
    Complex2D operator*(const Complex2D &c);
    Complex2D operator/(const Complex2D &c);
    bool operator>(const Complex2D &c);
    bool operator<(const Complex2D &c);

    //destructors
    virtual ~Complex2D() = default;

};
#endif //COMPLEX2D_H
