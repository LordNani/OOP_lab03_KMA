#include "AComplex.h"
#include "TComplex.h"
#include <iostream>
using namespace std;

int main() {
  AComplex Afirst(15, 4.5), Asecond(2.91, -5), Athird(Afirst);
  TComplex Tfirst(15, 120), Tsecond(22, 90), Tthird(Tsecond), Tfourth(Asecond);
  AComplex Afourth(Tsecond);
  cout << Athird << Athird.conj();
  Athird.~AComplex();
  cout << (Asecond + Afourth) / Afirst;
  cout << Afirst + Asecond;
  Afirst /= Asecond;
  if (Asecond == AComplex(Tfourth)) {
    cout << "================" << endl
         << "They are equal!" << endl
         << "================" << endl;
  }
  if (Tsecond != TComplex(Afirst)) {
	  cout << "================" << endl
		  << "They are not equal!" << endl
		  << "================" << endl;
  }
  cout << Tthird <<"Tthird Angle = " << Tthird.getArg() << endl;
  Tthird.~TComplex();
  cout << (Tsecond + Afourth) / Tfirst;
  cout << Tfirst + Tfirst;
  cout << Tsecond;
  Tsecond /= Tfourth *= Tfirst;
  cout << Tsecond;
  Tfirst = Tfourth;
  AComplex Afifth(2,5);
  TComplex Tfifth(0,0);
  cin >> Afifth;
  cout << Afifth;

  cin >> Tfifth;
  cout << Tfifth;
  return 0;
}
