
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "Student.h"
#include "Tokenizer.h"
#include "trim.h"

using namespace std;

template<typename T>

void print_element(T st) {
	cout << st.get_name() << "\t"<< st.get_telno() << endl;//print element
} //

vector<Student>readStudents(char *fName)
{
	ifstream fin(fName);
	string buf;
	Tokenizer str;
	string name;
	string telno;
	vector<Student>students;//새로 만듬
	while (getline(fin, buf))
	{
		str.set(buf, "#");
		name = trim(str.next());
		telno = trim(str.next());
		students.push_back(Student(name, telno));//새로 넣음
	}

	return students;
}

void merge2(vector<Student>&S, int low, int mid,int high)
{
	int i, j, k;
	vector<Student>U(S.size());
	i = k = low;
	j = mid + 1;
	while (i <= mid&&j <= high)
	{
		if (S[i]< S[j])
		{
			U[k] = S[i];
			i++;
		}
		else
		{
			U[k] = S[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		copy(S.begin() + j, S.begin() + high + 1, U.begin() + k);
	}
	else
	{
		copy(S.begin() + i, S.begin() + mid + 1, U.begin() + k);
	}
	copy(U.begin()+low,U.begin()+high+1,S.begin()+low);
}

void mergesort2(vector<Student>&A,int low,int high)
{
	int mid;
	if (low >= high)return;
	mid = (low + high) / 2;
	mergesort2(A,low,mid);
	mergesort2(A, mid + 1, high);
	merge2(A, low, mid, high);
}


int main(int argc, char* argv[])
{
	char *fName = "C:\\Users\\shmon\\Documents\\Visual Studio 2017\\Projects\\Project5\\students.txt";
	vector<Student> A = readStudents(fName);
	//for_each(A.begin(), A.end(), print_element<Student>);

	cout << endl;
	mergesort2(A,0, A.size() - 1);//mergesort 구현
	for_each(A.begin(), A.end(), print_element<Student>);

	


    //// instanciate Tokenizer class
    //Tokenizer str;
    //string token;
    //int counter = 0;

    //// set source string with default delimiters (space, tab, and newline char)
    //str.set("This is a testing\t string.\n\nTry to modify it \t\t yourself.");

    //// Tokenizer::next() returns a next available token from source string
    //// If it reaches EOS, it returns zero-length string, "".
    //while((token = str.next()) != "")
    //{
    //    ++counter;
    //    cout << counter << ": " << token << endl;
    //}
    //cout << endl;


    //// set a different string and delimiters(~, _)
    //// Notice that space is not delimiter any more.
    //counter = 0;
    //str.set("Now,~the_delimiters~~~are__changed~to_tild  and  underscore.~", "~_");
    //while((token = str.next()) != "")
    //{
    //    ++counter;
    //    cout << counter << ": " << token << endl;
    //}

    //return 0;
}

