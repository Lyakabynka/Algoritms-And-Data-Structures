#include <iostream>
#include <list>
using namespace std;

class Complex {
private:
	double re, im;
public:
	Complex(double re, double im) {
		this->re = re;
		this->im = im;
	}
	Complex& operator=(const Complex o) {
		this->re = o.re;
		this->im = o.im;
		return *this;
	}
	Complex operator+(const Complex o) {
		return Complex(this->re + o.re, this->im + o.im);
	}
	friend bool operator == (const Complex& r, const Complex& l)
	{
		return r.re == l.re && r.im == l.im;
	}
	friend ostream& operator<<(ostream& o, Complex c) {
		o << c.re << "+" << c.im << "i" << endl;
		return o;
	}
};

template<class T>
int array_search(T element, T array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == element) return i;
	}
	return -1;
}
int main()
{
	//there is nothing to explain (because we did it in prev semester (except templates))
	int a[] = { 1,2,3,4 };
	cout << array_search(3, a, 4) << endl;
	
	double b[] = { 1.2,5.1,6.1,61.2 };
	cout << array_search(5.1, b, 4) << endl;

	Complex c[] = { Complex(1,2), Complex(4,3), Complex(5,6) };
	cout << array_search(Complex(1, 2), c, 3) << endl;
 return 0;
}