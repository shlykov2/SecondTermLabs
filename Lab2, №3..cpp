#include <iostream>;

using namespace std;

double**TeylorSinMatrix(int, double);
double**LibrarySinMatrix(int);
double**AllocMatrix(int);
double Teylor(double, double);
double**Differense(double**, double**, int);
void DisplayMatrix(double**, int);
double MaxElementInMatrix(double**, int);

int main()
{
	double exp;
	int n;
	while (true){
		cout << "Hello, enter size of matrix:\n";
		cin >> n;
		if (n > 0) break;
		cout << "Try again\n";
	}
	while (true){
		cout << "Enter accuracy\n";
		cin >> exp;
		if (exp < 1 && exp>0) break;
		system("cls");
		cout << "Try again, please\n";
	}
	double**a = TeylorSinMatrix(n, exp);
	double**b = LibrarySinMatrix(n);
	double**c = Differense(a, b, n);
	cout << endl << "Teylor Matrix\n";
	DisplayMatrix(a, n);
	cout << endl << "Liblriary Matrix" << endl;
	DisplayMatrix(b, n);
	cout << endl << "Differense" << endl;
	DisplayMatrix(c, n);
	cout << endl << "Max element in matrix is " << MaxElementInMatrix(c, n) << endl;
	system("pause");
}

double**TeylorSinMatrix(int n, double exp)
{
	double pi = 3.14159265359;
	double**a = AllocMatrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i != 2 * j)
				a[i][j] = i;
			else {
				double k = 2 * i*j, l = i;
				while (k > pi)
					k -= 2 * pi;
				while (l > pi)
					l -= 2 * pi;
				while (k < (-1)* pi)
					k += 2 * pi;
				while (l < (-1)* pi)
					l += 2 * pi;
				a[i][j] = (Teylor(k, exp) - Teylor(l, exp)) / ((i - j - 4)*(i - j - 4)*(i - j - 4) + (i + 2)*(i + 2));
			}
		}
	return a;
}

double**LibrarySinMatrix(int n)
{
	double**a = AllocMatrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i != 2 * j)
				a[i][j] = i;
			else a[i][j] = (sin(2 * i*j) - sin(i)) / ((i - j - 4)*(i - j - 4)*(i - j - 4) + (i + 2)*(i + 2));
		}
	return a;
}

double**AllocMatrix(int n)
{
	double**a = new double*[n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	return a;
}

double**Differense(double**a, double**b, int n)
{
	double** c = AllocMatrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = fabs(a[i][j] - b[i][j]);
	return c;
}

void DisplayMatrix(double**a, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(20);
			cout << a[i][j];
		}
		cout << endl;
	}
}

double Teylor(double x, double exp)
{
	double sum = 0;
	double an = x;
	int n = 0;
	while (fabs(an) > exp) {
		sum += an;
		n++;
		an *= (-1)*x*x / (2 * n + 1) / (2 * n);
	}
	return sum;
}

double MaxElementInMatrix(double**a, int n)
{
	double max = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > max)
				max = a[i][j];
	return max;
}