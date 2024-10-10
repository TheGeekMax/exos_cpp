//
// Created by Maxime Sanciaume on 10/10/2024.
//

#include "Complex2D.h"

#include <iostream>
#include <math.h>

// constructors
Complex2D::Complex2D(double real_, double imag_): real(real_), imag(imag_) {}
Complex2D::Complex2D(double real_): real(real_), imag(0) {}
Complex2D::Complex2D(Complex2D &c) = default;
Complex2D::Complex2D(): real(0), imag(0) {}

// getters/setters
double Complex2D::getReal() const {
    return real;
}

void Complex2D::setReal(double real_) {
    real = real_;
}

double Complex2D::getImag() const {
    return imag;
}

void Complex2D::setImag(double imag_) {
    imag = imag_;
}

//to simplify operations
Complex2D symetric(const Complex2D &c) {
    return Complex2D(-c.getReal(), -c.getImag());
}

Complex2D conjugate(const Complex2D &c) {
        return Complex2D(c.getReal(), -c.getImag());
}

Complex2D inverse(const Complex2D &c) {
    double n = Complex2D::norm(c);
    return Complex2D(c.getReal()/n, -c.getImag()/n);
}

Complex2D rotate(const Complex2D &c, double angle) {
    return Complex2D(c.getReal()*cos(angle) - c.getImag()*sin(angle), c.getReal()*sin(angle) + c.getImag()*cos(angle));
}

double norm(const Complex2D &c) {
    return c.getReal()*c.getReal() + c.getImag()*c.getImag();
}

//for operations

Complex2D Complex2D::operator+(const Complex2D &c) {
    return Complex2D(real + c.real, imag + c.imag);
}

Complex2D Complex2D::operator-(const Complex2D &c) {
    return operator+(symetric(c));
}

Complex2D Complex2D::operator*(const Complex2D &c) {
    return Complex2D(real*c.real - imag*c.imag, real*c.imag + imag*c.real);
}

Complex2D Complex2D::operator/(const Complex2D &c) {
    return operator*(inverse(c));
}

bool Complex2D::operator>(const Complex2D &c) {
    return norm(*this) > norm(c);
}

bool Complex2D::operator<(const Complex2D &c) {
    return norm(*this) < norm(c);
}

