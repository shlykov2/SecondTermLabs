#include <iostream>  //14 вариант 

using namespace std;

int** AllocMatrix(int);
void DisplayMatrix(int**, int);
int** AlgorithmMatrix(int**, int);
void RandomMatrix(int**, int);
int Algorithm(int**, int, int, int);

int main()
{
	while (true){
		int n;
		while (true){
			cout << "Hello, enter the size(n) of square matrix(n*n), please: ";
			cin >> n;
			if (n > 0) break;
			cout << "Try again!\n";
		}
		int** a = AllocMatrix(n);
		RandomMatrix(a, n);
		cout << endl << "Source Matrix:\n";
		DisplayMatrix(a, n);
		int** b = AlgorithmMatrix(a, n);
		cout << endl << "New Matrix:\n";
		DisplayMatrix(b, n);
		system("pause");
	}
}

void RandomMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 100;
}

int** AllocMatrix(int n)
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	return a;
}

void DisplayMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout.width(4);
			cout << a[i][j];
		}
		cout << endl;
	}
}

int** AlgorithmMatrix(int** a, int n)
{
	int** b = AllocMatrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			b[i][j] = Algorithm(a, n, i, j);
	return b;
}

int Algorithm(int** a, int n, int k, int l)
{
	int flag = 0, c = 0, max = a[0][0];
	for (int i = 0; i < n && (l - c >= 0 || l + c <= n); i++)
	{
		if (flag) 
			c += 1;
		if (i == k) 
			flag = 1;
		for (int j = 0; j < n; j++)
		{
			if (j < l - c || j > l + c)
				if (a[i][j]>max) 
					max = a[i][j];
		}
	}
	return max;
}
