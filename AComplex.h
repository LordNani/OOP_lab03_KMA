// Complex numbers
// in cartesian (algebraic) form
#pragma once
#include <iostream>
#include "TComplex.h"

class TComplex;
class AComplex
{
private:
	double _re, _im;
	static int _freeId;
	int _id;

public:
	AComplex (double re=0, double im=0);
	AComplex (const TComplex&);
	AComplex (const AComplex&);
	~AComplex();

	AComplex& operator= (const AComplex&);
	
	void setRe(double re_in); //non-ref double to be able to put expressions
	void setIm(double im_in);

	double getRe() const;
	double getIm() const;
	double& getReRef() { return _re; }
	double& getImRef() { return _im; }

	int getId() const{ return _id; }

	double mod() const;
	double arg() const;

	const AComplex conj() const;

};

AComplex& operator+=(AComplex&, const AComplex&);
AComplex& operator-=(AComplex&, const AComplex&);
AComplex& operator*=(AComplex&, const AComplex&);
AComplex& operator/=(AComplex&, const AComplex&);

const AComplex  operator+ (const AComplex&, const AComplex&);
const AComplex  operator- (const AComplex&, const AComplex&);
const AComplex  power(const AComplex&, unsigned int);

bool operator== (const AComplex&, const AComplex&);
bool operator!= (const AComplex&, const AComplex&);

std::ostream& operator<<(std::ostream & os, const AComplex &num);
std::istream& operator>>(std::istream& is, AComplex&num);
