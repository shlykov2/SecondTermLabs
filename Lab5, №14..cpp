#include <iostream>
#include <fstream>

using namespace std;

struct st
{
	char address[50] = "";
	char type[50] = "";
	int floors;
	int flats;
	int srok;
	int kap;
};

st* InitArray(int n);
void InitStruct(st& a);
void DisplayArray(st* a, int n);
void Sort(st* a, int n);
void Swap(st& a, st& b);
st* TakeArray(int n);
void WriteArray(st* arr, int n);
void FindStruct(st* arr, int n);
void DisplayStruct(st a);

int main()
{
	cout << "Hello, enter the number of structs, please:\n";
	int n;
	cin >> n;
	system("cls");
	st* arr = InitArray(n);
	cout << "Your sorted array:\n";
	Sort(arr, n);
	DisplayArray(arr, n);
	system("pause");
}

st* InitArray(int n)
{
	st* a = new st[n];
	for (int i = 0; i < n; i++){
		cout << "Enter the " << i + 1 << " struct\n";
		InitStruct(a[i]);
	}
	return a;
}

void InitStruct(st& a)
{
	cout << "address: ";
	cin.ignore();
	cin.getline(a.address, 50);
	cout << "type: ";
	cin.getline(a.type, 50);
	cout << "floors: ";
	cin >> a.floors;
	cout << "flats: ";
	cin >> a.flats;
	cout << "srok: ";
	cin >> a.srok;
	system("cls");
	a.kap = 25 - a.srok;
}

void DisplayArray(st* a, int n)
{
	for (int i = 0; i < n; i++){
		cout << "struct #" << i + 1 << " :\n";
		DisplayStruct(a[i]);
	}
	cout << endl;
}

void DisplayStruct(st a) 
{
	cout << a.address << endl;
	cout << a.type << endl;
	cout << a.floors << endl;
	cout << a.flats << endl;
	cout << a.srok << endl;
	cout << a.kap << endl;
}

void Sort(st* a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j].kap > a[j - 1].kap)
				Swap(a[j], a[j - 1]);
}

void Swap(st& a, st& b)
{
	st c = a;
	a = b;
	b = c;
}

void FindStruct(st* a, int n) 
{
	for (int i = 0; i < n; i++)
		if (a[i].kap == 0)
			DisplayStruct(a[i]);
}

st* TakeArray(int n)
{
	ifstream streamIn;
	streamIn.open("Array.txt", ios::binary);
	st* arr = new st[n];
	streamIn.getline((char*)&*arr, sizeof(st)*n);
	streamIn.close();
	return arr;
}

void WriteArray(st* arr, int n)
{
	ofstream streamOut("Array.txt", ios::app, ios::binary);
	streamOut.write((char*)&*arr, sizeof(st)*n);
	streamOut.close();
}
