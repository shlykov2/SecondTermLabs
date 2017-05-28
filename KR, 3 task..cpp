#include<iostream>
#include <fstream>

using namespace std;

void FindWords(char*, char*, char*);

int main() 
{
	FindWords("file1.txt", "file2.txt", "file3.txt");
	system("pause");
}

void FindWords(char* file1, char* file2, char* file3) 
{
	ifstream s2(file2);
	while (!s2.eof()){
		char c, c2[20] = "";
		int i = 0, flag = 0, count = 0;
			while (s2.read(&c, 1)){
				if (c < 123 && c>96){
				c2[i] = c;
				i++;
				flag = 1;
			}
			else if (c < 91 && c>64){
				c2[i] = c + 32;
				i++;
				flag = 1;
			}
			else if (flag == 1) break;
		}
		i = flag = 0;
		ifstream s1(file1);
		while (!s1.eof()){
			char c1[20] = "";
			while (s1.read(&c, 1)){
				if (c < 123 && c>96){
					c1[i] = c;
					i++;
					flag = 1;
				}
				else if (c < 91 && c>64){
					c1[i] = c + 32;
					i++;
					flag = 1;
				}
				else if (flag == 1) break;
			}
			i = flag = 0;
			if (!strcmp(c1, c2)) count++;
		}
		s1.close();
		ofstream s3(file3, ios::binary | ios::app);
		s3.write(c2, strlen(c2));
		s3.write((char*)&count, sizeof(int));
		cout << c2 << " " << count << '\n';
		count = 0;
	}
}