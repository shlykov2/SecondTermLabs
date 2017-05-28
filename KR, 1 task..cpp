#include<iostream>
#include <fstream>

using namespace std;

void InitFile(char*);
void Sorting(char*, char*, char*);
void DisplayFile(char c[]);

int main()
{
	InitFile("file1.txt");
	InitFile("file2.txt");
	Sorting("file1.txt", "file2.txt", "file3.txt");
	DisplayFile("file1.txt");
	DisplayFile("file2.txt");
	DisplayFile("file3.txt");
	system("pause");
}

void InitFile(char* file)
{
	cout << "Hello, fill the " << file << " file, please\nEnter the number of numbers:";
	int n;
	cin >> n;
	int* a = new int[n];
	system("cls");
	for (int i = 0; i < n; i++){
		cout << "Enter the " << i + 1 << " element, please:\n";
		cin >> a[i];
	}
	ofstream s(file);
	s.write((char*)a, sizeof(int)*n);
	s.close();
}

void Sorting(char* file1, char* file2, char* file3)
{
	ifstream s1(file1);
	ifstream s2(file2);
	ofstream s3(file3);
	int n1, n2, size = sizeof(int);
	while (s1.read((char*)&n1, size)){
		while (s2.read((char*)&n2, size)){
			if (n2 > n1){
				s2.seekg(-1 * size, ios::cur);
				break;
			}
			s3.write((char*)&n2, size);
		}
		s3.write((char*)&n1, size);
	}
	while (s2.read((char*)&n2, size)){
		s3.write((char*)&n2, size);
	}
	s1.close();
	s2.close();
	s3.close();
}

void DisplayFile(char c[])
{
	ifstream streamIn(c);
	int n;
	while (streamIn.read((char*)&n, sizeof(int))){
		cout << n << ' ';
	}
	cout << '\n';
	streamIn.close();
}
