#include <iostream>
#include <fstream>

using namespace std;

int* InitArray(int n);
void DisplayArray(int* a, int n);
void DeleteElement(int* a, int n, int b);
int* Deleting(int*, int&);
void Sort(int* a, int n, int b);
void Swap(int& a, int& b);
int* TakeArray(int n);
void WriteArray(int* arr, int n);
void CreateFile(int* arr, int n);

int main()
{
	cout << "Hello, enter the size of array, please:\n";
	int n;
	cin >> n;
	system("cls");
	int* arr1 = InitArray(n);
	CreateFile(arr1, n);
	arr1 = TakeArray(n);
	system("cls");
	cout << "Your array is:\n";
	DisplayArray(arr1, n);
	int n1 = n;
	int* arr2 = Deleting(arr1, n1);
	int a;
	cout << "Now enter the dividor:\n";
	cin >> a;
	Sort(arr1, n1, a);
	system("cls");
	WriteArray(arr2, n - n1);
	cout << "Success! The new arrays are:\n";
	DisplayArray(arr1, n1);
	DisplayArray(arr2, n - n1);
	system("pause");
}

int* InitArray(int n)
{
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter the " << i + 1 << "'s number\n";
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
		if (i % 2 == 0 && a[i] % 2 == 0) {
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

int* TakeArray(int n)
{
	ifstream streamIn;
	streamIn.open("Array.txt");
	int* arr = new int[n];
	streamIn.getline((char*)&*arr, sizeof(int)*n);
	streamIn.close();
	return arr;
}

void CreateFile(int* arr, int n)
{
	ofstream streamOut("Array.txt");
	streamOut.write((char*)&*arr, sizeof(int)*n);
	streamOut.close();
}

void WriteArray(int* arr, int n)
{
	ofstream streamOut("Array.txt", ios::app);
	streamOut.write((char*)&*arr, sizeof(int)*n);
	streamOut.close();
}