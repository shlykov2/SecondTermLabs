#include <iostream>

using namespace std;

int* InitArray(int n);
void DisplayArray(int* a, int n);
void DeleteElement(int* a, int n, int b);
int* Deleting(int*, int&);
void Sort(int* a, int n, int b);
void Swap(int& a, int& b);

int main()
{
	cout << "Hello, enter the size of array, please:\n";
	int n;
	cin >> n;
	system("cls");
	int* arr1 = InitArray(n);
	system("cls");
	cout << "Your array:\n";
	DisplayArray(arr1, n);
	int n1 = n;
	int* arr2 = Deleting(arr1, n1);
	int a;
	cout << "Enter the dividor:\n";
	cin >> a;
	Sort(arr1, n1, a);
	system("cls");
	cout << "The new arrays are:\n";
	DisplayArray(arr1, n1);
	DisplayArray(arr2, n - n1);
	system("pause");
}

int* InitArray(int n)
{
	int* a = new int[n];
	for (int i = 0; i < n; i++){
		cout << "Enter the " << i+1 << "'s number\n";
		int b;
		cin >> b;
		a[i] = b;
		system("cls");
	}
	return a;
}

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void DeleteElement(int* a, int n, int b)
{
	for (int i = b; i < n; i++)
		a[i] = a[i + 1];
}

int* Deleting(int* a, int& n)
{
	int* b = new int[n];
	int n1 = -1;
	for (int i = n - 1; i >= 0; i--)
		if (i % 2 == 0 && a[i] % 2 == 0){
			n1++;
			b[n1] = a[i];
			DeleteElement(a, n, i);
			n--;
		}
	return b;
}

void Sort(int* a, int n, int b)
{
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] % b > a[j - 1] % b)
				Swap(a[j], a[j - 1]);
}

void Swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

/*
CHECKING.
1.
SIZE IN - 11.
ARRAY IN - 3, 2, 14, 3, 8, 6, 9, 5, 4, 7, 4.
DIVIDER IN - 2.
ARRAY OUT - 3, 3, 9, 5, 7, 2, 6.
ARRAY OUT - 4, 4, 8, 14.
2.
SIZE IN - 12.
ARRAY IN - 6, 3, 76, 43, 54, 65, 77, 80, 5, 3, 4, 6.
DIVIDER IN - 9.
ARRAY OUT - 80, 43, 6, 77, 5, 3, 3, 65.
ARRAY OUT - 4, 54, 76, 6.
*/