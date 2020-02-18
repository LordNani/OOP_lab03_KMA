#pragma once
#include "AComplex.h"
#include <math.h>

int AComplex::_freeId(0);
using namespace std;

AComplex::AComplex(double re, double im) : _id(_freeId++), _re(re), _im(im) {
#ifndef NDEBUG
  cout << "Created AComplex object using 2 values, id: " << _id << endl;
#endif // !NDEBUG
}

AComplex::AComplex(const TComplex &num) : _id(_freeId++) {
  _re = num.getMod() * cos(num.getArg());
  _im = num.getMod() * sin(num.getArg());
#ifndef NDEBUG
  cout << "Created AComplex object using TComplex object, id: " << _id << endl;
#endif // !NDEBUG
}

AComplex::AComplex(const AComplex &num)
    : _id(_freeId++), _re(num._re), _im(num._im) {
#ifndef NDEBUG
  cout << "Created AComplex object using copy of AComplex, id: " << _id << endl;
#endif // !NDEBUG
}

AComplex::~AComplex() {
#ifndef NDEBUG
  cout << "Destroyed AComplex, id: " << _id << endl;
#endif // !NDEBUG
}

AComplex &AComplex::operator=(const AComplex &num) {
  this->_re = num._re;
  this->_im = num._re;
  return *this;
}

double AComplex::getRe() const { return this->_re; }

double AComplex::getIm() const { return this->_im; }

void AComplex::setRe(double re_in) { this->_re = re_in; }

void AComplex::setIm(double im_in) { this->_im = im_in; }

double AComplex::mod() const { return sqrt(pow(_re, 2) + pow(_im, 2)); }

double AComplex::arg() const { return atan(_im / _re); }

const AComplex AComplex::conj() const {
	return AComplex(this->getRe(), -1.f * this->getIm());
}

AComplex &operator+=(AComplex &a, const AComplex &b) {
  a.setRe(a.getRe() + b.getRe());
  a.setIm(a.getIm() + b.getIm());
  return a;
}
AComplex &operator-=(AComplex &a, const AComplex &b) {
	a.setRe(a.getRe() - b.getRe());
	a.setIm(a.getIm() - b.getIm());
	return a;
}
AComplex &operator*=(AComplex &a, const AComplex &b) {
  a.setRe(a.getRe() * b.getRe() - a.getIm() * b.getIm());
  a.setIm(a.getRe() * b.getIm() + b.getRe() * a.getIm());
  return a;
}


AComplex &operator/=(AComplex &a, const AComplex &b) {
  if (!b.getRe() && !b.getIm())
    throw runtime_error("Tried to divide by a complex number that equal 0\n");
  double denom = (pow(b.getRe(), 2) + pow(b.getRe(), 2));
  a.setRe((a.getRe() * b.getRe() + a.getIm() * b.getIm()) / denom);
  a.setIm((-1 * a.getRe() * b.getIm() + a.getIm() * b.getRe()) / denom);
  return a;
}

ostream &operator<<(ostream &os, const AComplex &num) {

  os << "AComlpex object with Id :  " << num.getId() << ", Re: " << num.getRe()
     << " , "
     << "Im:   " << num.getIm() << endl;
  return os;
}

const AComplex operator+(const AComplex &a, const AComplex &b) {
  return AComplex(a.getRe() + b.getRe(), a.getIm() + b.getIm());
}

const AComplex operator-(const AComplex &a, const AComplex &b) {
  return AComplex(a.getRe() - b.getRe(), a.getIm() - b.getIm());
}

const AComplex power(const AComplex &num, unsigned int n) {
  double r =
      pow(sqrt(num.getRe() * num.getRe() + num.getIm() * num.getIm()), n);
  return AComplex(r * cos(n * atan2(num.getIm(), num.getRe())),
                  r * sin(n * atan2(num.getIm(), num.getRe())));
}

bool operator== (const AComplex& a, const AComplex& b) {
	return (a.getRe() == b.getRe() && a.getIm() == b.getIm());
}

bool operator!= (const AComplex& a, const AComplex& b) {
	return !(a.getRe() == b.getRe() && a.getIm() == b.getIm());
}
