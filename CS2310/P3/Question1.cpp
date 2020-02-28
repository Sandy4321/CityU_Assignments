#include <iostream>
using namespace std;

// START

// Complex class
class Complex
{
  private:
	double real;
	double imag;

  public:
	//initialize the real and imaginary parts by a and b respectively
	void Initialize(double a, double b);

	// print the complex number on the screen
	void show();

	// compute and return the power (square) of the current complex number
	Complex power();

	// compute and return the multiplication of two complex numbers
	Complex multip(Complex A);

};

void Complex::Initialize(double a, double b)
{
	// putting the parameter into the real and imag
	real = a;
	imag = b;
}

void Complex::show()
{
	cout << real;

	// check if imaginary is 0 (no imaginary part)
	if (imag != 0)
	{
		// if negative need some space so we need to do extra work to split out
		if (imag < 0)
		{
			// add "i" into the console.
			cout << " - " << -imag << "i";
		}
		else
		{
			cout << " + " << imag << "i";
		}
	}
}

Complex Complex::power()
{
	// putting itself into the multip to square itself
	return multip(* this);
}

Complex Complex::multip(Complex A)
{

	/*
		multiplication of a imaginary number:
		( real1 + imag2 i ) * ( real1 + imag2 i )
		= (real1 * real2) + (real1 * imag2 i) + (real2 * imag1 i) + (imag1 i * imag2 i)
		= (real1*real2) + (real1 * imag2) i + (real2 * imag1) i + (imag1*imag2*(i*i))
		= (real1*real2) + (real1 * imag2 + real2 * imag1) i - (imag1*imag2) 
		note that  i*i = -1

		Therefore the new real part is 
		(real1*real2) - (imag1*imag2)

		the new imaginary part is
		(real1 * imag2 + real2 * imag1) i
	*/
	// create a nother complex number to store the result
	Complex multipComplex;
	// creating 2 double to store the real and imaginary of the product
	// ( for better reading the code )
	double realMultip, imagMultip;

	// finalReal = real1 * real2 - imag1 * imag2
	realMultip = real * A.real - imag * A.imag;

	// finalImag = real1 * imag2 + real2 * imag1
	imagMultip = real * A.imag + A.real * imag;

	// putting the values into the intitalization
	multipComplex.Initialize(realMultip,imagMultip);

	// return the result.
	return multipComplex;
}

int main()
{
	// PART 0: initialization
	// creating two complex number
	Complex complex1, complex2;

	// create two double to store the value for initialisation
	double tempReal, tempImag;

	// to request the user for input
	cout << "Enter two complex numbers: " << endl;

	// retriving the inputs
	cin >> tempReal >> tempImag;

	// initilize complex1
	complex1.Initialize(tempReal, tempImag);

	// retriving the inputs
	cin >> tempReal >> tempImag;

	// initilize complex2	
	complex2.Initialize(tempReal, tempImag);





	// PART 1: output all inputs as complex
	cout << "The complex numbers you entered are: " << endl;
	complex1.show();
	cout << endl;
	complex2.show();



	// PART 2: square the imaginary number
	// first complex squaring	
	cout << endl << "The power of ";
	complex1.show();
	cout << " is:" << endl;

	// using the power() and show() function
	complex1.power().show();

	// second complex squaring
	cout << endl << "The power of ";
	complex2.show();
	cout << " is:" << endl;
	
	// using the power() function	
	complex2.power().show();



	// PART 3: multiply the complexes
	cout << endl << "The result of (";
	complex1.show();
	cout << ") * (";
	complex2.show();
	cout << ") is:" << endl;
	// using the multip() and show() function
	complex1.multip(complex2).show();



	cout << endl;


	return 0;
}