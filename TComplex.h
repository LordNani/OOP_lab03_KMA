// Complex numbers
// in polar form
class AComplex;
class TComplex
{
private:
	double _ro, _phi;
	static int _freeId;
	int _id;

public:
	TComplex (double ro=0, double phi=0);
	TComplex (const TComplex&);
	TComplex (const AComplex&);
	~TComplex();

	TComplex& operator= (const TComplex&);

	double& mod();
	double& arg();

	double mod() const;
	double arg() const;
	
	double re() const;
	double im() const;

};


TComplex& operator+=(TComplex& a, const TComplex& b);
TComplex& operator-=(TComplex& a, const TComplex& b);
TComplex& operator*=(TComplex& a, const TComplex& b);
TComplex& operator/=(TComplex& a, const TComplex& b);

const TComplex  operator* (const TComplex&, const TComplex&);
const TComplex  operator/ (const TComplex&, const TComplex&);
const TComplex  power(const TComplex&, unsigned int);

ostream& operator<<(ostream &, const TComplex&);
istream& operator>>(istream &, TComplex&);