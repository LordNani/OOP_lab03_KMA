// Complex numbers
// in polar form
#pragma once
#include <iostream>
#include "AComplex.h"
class AComplex;
class TComplex {
private:
  double _ro, _phi;
  static int _freeId;
  int _id;

public:
  TComplex(double ro = 0, double phi = 0);
  TComplex(const TComplex &);
  TComplex(const AComplex &);
  ~TComplex();

  TComplex &operator=(const TComplex &);

  void setMod(double mod_in); // non-ref double to be able to put expressions
  void setArg(double arg_in); // non-ref double to be able to put expressions

  int getId() const { return _id; }

  double getMod() const;
  double getArg() const;
  double& getModRef() { return _ro; }
  double& getArgRef() { return _phi; }

  double re() const;
  double im() const;
};

// you can't avoid the conversion from polar to Cartesian and back to polar
TComplex &operator+=(TComplex &a, const TComplex &b);
TComplex &operator-=(TComplex &a, const TComplex &b);
TComplex &operator*=(TComplex &a, const TComplex &b);
TComplex &operator/=(TComplex &a, const TComplex &b);

const TComplex operator*(const TComplex &, const TComplex &);
const TComplex operator/(const TComplex &, const TComplex &);
const TComplex power(const TComplex &, unsigned int);

std::ostream& operator<<(std::ostream &os, const TComplex &num);
std::istream &operator>>(std::istream &is, TComplex &num);
