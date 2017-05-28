#include <iostream>
#include <fstream>

using namespace std;

class Matrix
{
	private:
		int** a;
		int n;
	public:
	Matrix(int** arr, int dim){
		n = dim;
		a = new int*[n];
		for (int i = 0; i < n; i++){
			a[i] = new int[n];
			for (int j = 0; j < n; j++)
				a[i][j] = arr[i][j];
		}
	}
	void DisplayMatrix(){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << " ";
			}
			cout << '\n';
		}
	}
	int** GetMatrix(){
		int** arr = new int*[n];
		for (int i = 0; i < n; i++){
			arr[i] = new int[n];
			for (int j = 0; j < n; j++){
				arr[i][j] = a[i][j];
			}
		}
		return arr;
	}
	int GetDim(){ 
		return n; 
	}
};

void InitFile(char c[]);
Matrix RandMatrix(int n);
void AddMatrix(Matrix a, char c[]);
void DisplayFile(char c[]);
Matrix TakeMatrix(int n, char c[], int pos);
void Transfer(char c1[], char c2[]);

int main()
{
	char c1[] = "Array1.txt";
	InitFile(c1);
	char c2[] = "Array2.txt";
	InitFile(c2);
	cout << "Your 1t file:\n";
	DisplayFile(c1);
	cout << "\nYour 2d file:\n";
	DisplayFile(c2);
	Transfer(c1, c2);
	cout << "Your 1t file:\n";
	DisplayFile(c1);
	cout << "\nYour 2d file:\n";
	DisplayFile(c2);
	system("pause");
}

void InitFile(char c[]) 
{
	cout << "Enter the number of matrices, please:\n";
	int n;
	cin >> n;
	system("cls");
	for (int i = 0; i < n; i++){
		cout << "Enter the size of " << i + 1 << " matrix, please:\n";
		int dim;
		cin >> dim;
		AddMatrix(RandMatrix(dim), c);
	}
}

Matrix RandMatrix(int n) 
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++){
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 100;
	}
	Matrix m(a, n);
	return m;
}

void AddMatrix(Matrix a, char c[]) 
{
	ofstream streamOut(c, ios::app, ios::binary);
	int n = a.GetDim();
	streamOut.write((char*)&n, sizeof(int));
	for (int i = 0; i < a.GetDim(); i++){
		streamOut.write((char*)a.GetMatrix()[i], sizeof(int)*n);
	}
	streamOut.close();
}
Matrix TakeMatrix(int n, char c[], int pos) 
{
	ifstream streamIn(c, ios::binary);
	streamIn.seekg(pos);
	int** a = new int* [n];
	for (int i = 0; i < n; i++){
		a[i] = new int[n];
		streamIn.read((char*)a[i], sizeof(int)*n);
	}
	Matrix m(a, n);
	return m;
	streamIn.close();
}

void DisplayFile(char c[]) 
{
	ifstream streamIn(c, ios::binary);
	int n;
	while (streamIn.read((char*)&n, sizeof(int))){
		Matrix m = TakeMatrix(n, c, streamIn.tellg());
		m.DisplayMatrix();
		cout << '\n';
		streamIn.seekg(sizeof(int)*n*n, ios::cur);
	}
	streamIn.close();
}

void Transfer(char c1[], char c2[]) 
{
	ifstream streamIn(c1, ios::binary);
	ifstream streamOut(c2, ios::binary);
	int n1, n2;
	streamOut.read((char*)&n2, sizeof(int));
	while (streamIn.read((char*)&n1, sizeof(int))){
		if (n1 == n2){
			AddMatrix(TakeMatrix(n1, c1, streamIn.tellg()), c2);
		}
		streamIn.seekg(sizeof(int)*n1*n1, ios::cur);
	}
}
