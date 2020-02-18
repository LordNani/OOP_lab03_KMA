
#include "TComplex.h"
#include <math.h>
using namespace std;
const wchar_t angleSymbol = 0x299F;
TComplex::TComplex(double ro, double phi) : _id(_freeId++), _ro(ro), _phi(phi) {
#ifndef NDEBUG
  cout << "Created TComplex object using 2 values, id: " << _id << endl;
#endif // !NDEBUG
}

TComplex::TComplex(const AComplex &num) : _id(_freeId++) {
  _ro = num.mod();
  _phi = num.mod() * sin(num.arg());
#ifndef NDEBUG
  cout << "Created TComplex object using Acomplex object, id: " << _id << endl;
#endif // !NDEBUG
}

TComplex::TComplex(const TComplex &num)
    : _id(_freeId++), _ro(num._ro), _phi(num._phi) {
#ifndef NDEBUG
  cout << "Created TComplex object using copy of TComplex, id: " << _id << endl;
#endif // !NDEBUG
}

TComplex::~TComplex() {
#ifndef NDEBUG
  cout << "Destroyed TComplex, id: " << _id << endl;
#endif // !NDEBUG
}

TComplex &TComplex::operator=(const TComplex &num) {
  this->_ro = num._ro;
  this->_phi = num._phi;
  return *this;
}

void TComplex::setMod(double mod_in) { _ro = mod_in; }

void TComplex::setArg(double mod_in) { _phi = mod_in; }

double TComplex::getMod() const { return _ro; }
double TComplex::getArg() const { return _phi; }

double TComplex::re() const { return _ro * cos(_phi); }
double TComplex::im() const { return _ro * sin(_phi); }

TComplex &operator+=(TComplex &a, const TComplex &b) {
  a = TComplex(AComplex(a) + AComplex(b));
  return a;
}
TComplex &operator-=(TComplex &a, const TComplex &b) {
  a = TComplex(AComplex(a) - AComplex(b));
  return a;
}
TComplex &operator*=(TComplex &a, const TComplex &b) {
  a.setMod(a.getMod() * b.getMod());
  a.setArg(a.getArg() + b.getArg());
  return a;
}
TComplex &operator/=(TComplex &a, const TComplex &b) {
  if (!b.getMod() && !b.getArg())
    throw runtime_error("Tried to divide by a complex number that equal 0\n");
  a.setMod(a.getMod() / b.getMod());
  a.setArg(a.getArg() - b.getArg());
  return a;
}

const TComplex operator*(const TComplex &a, const TComplex &b) {
  return TComplex(a.getMod() * b.getMod(), a.getArg() + b.getArg());
}

const TComplex operator/(const TComplex &a, const TComplex &b) {
  if (!b.getMod())
    throw runtime_error("Tried to divide by a complex number that equal 0\n");
  return TComplex(a.getMod() / b.getMod(), a.getArg() - b.getArg());
}

const TComplex power(const TComplex &num, unsigned int n) {
  return TComplex(pow(num.getMod(), n), num.getMod() * n);
}

ostream &operator<<(ostream &os, const TComplex &num) {
  os << "TComplex object with ID: " << num.getId() << ", {" << num.getMod()
     << ", " << num.getArg() << angleSymbol << "}\n";
}

istream &operator>>(istream &is, TComplex &num) {
  cout << "Enter |z|: ";
  is >> num.getModRef();
  cout << "Enter Angle: ";
  is >> num.getArgRef();
}
