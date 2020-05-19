#include<iostream>
#include<math.h>
using namespace std;
void InputLine(char str[], const int n);
void Input(char* str, double* arr, char* get, const int n);
int  isInteger(double* arr, char* get, int& index, int& counter_arr);
void Operator(char get[], char* str, int &counter_str, int& index);

void prioryti(char* str, double* arr, int &counter_arr, int &counter_str, int& j, int& c, char operator_1,char operator_2 ) {




}

void Calculator(char* str, double* arr, int counter_arr, int counter_str)

{
	for (int i = 0; i < counter_arr; i++) {
		if (str[i] == '^') {

			arr[i + 1] = pow(arr[i], arr[i + 1]);
			str[i] = '?';
		}
	}
	for (int j = 0, c = 0; j < counter_arr && c < counter_str; c++, j++)
	{
		if (str[c + 1] == '?' && (str[c] == '*' || str[c] == '/'))
		{
	
			int index = c + 1;
			for (; str[index] == '?'; index++);

			str[c] == '*' ? arr[index] = arr[j] * arr[index] : arr[index] = arr[j] / arr[index];

				str[c] = '?';
				continue;
		}

		if (str[c] == '*') {

			arr[j + 1] = arr[j] * arr[j + 1];
			str[c] = '?'; 
		}
		else if (str[c] == '/')
		{
			arr[j + 1] = arr[j] / arr[j+1];

			str[c] = '?'; 
		}
	}

	double rez;
	int j = 0;
	for (int c = 0; j < counter_arr && c < counter_str; c++, j++)
	{
		if (str[c + 1] == '?' && (str[c] == '-' || str[c] == '+'))		
		{ 
			int index = c + 1;
			for (; str[index] == '?'; index++);
			if (str[c] == '+')
			{
				arr[index] = arr[j] + arr[index];
			}
			else if (str[c] == '-')
			{
				arr[index] = arr[j] - arr[index];
			}
			continue;
		}
		if (str[c] == '+')
		{
			arr[j + 1] = arr[j] + arr[j + 1];
		}
		else if (str[c] == '-')
		{
			 arr[j + 1] =  arr[j] - arr[j + 1];
		}
	}
	for (int i = 0; i < counter_arr; i++) cout << "arr[" << i << "] = " << arr[i] << endl;

	//cout << "Rezultat >> " << arr[j];
							                                            //3+3-3*3/2+1-1=   1.5		3+3-3*3/2+1^1= 2.5			3+3-3*3/2^2-10= -6.25
}

///////////////////////////////////////////////
 void main()
{
	 const int n = 50;
	 double arr[n]{};
	 char str[n];
	 char get[n];
	 Input(str, arr, get, n);

}
 //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

 void Input(char* str, double* arr, char* get, const int n)
 {
	 int counter_arr = 0, counter_str = 0;
	 cout << "1. In the end of equation put ' = '\n Enter the equation >> "; InputLine(get, n);

	 for (int i = 0; get[i] != '='; i++)
	 {
		 if (get[i] >= 48 && get[i] <= 57)
		 {
			 i = isInteger(arr, get, i, counter_arr);
		 }
		 else if (get[i] != ' ')
		 {
			 Operator(get, str, counter_str, i);
		 }
	 }
	 Calculator(str, arr, counter_arr, counter_str);
 }

int isInteger(double* arr, char* get, int& index, int& counter_arr)
{
	while(get[index] >= 48 && get[index] <= 57)
	{
		arr[counter_arr] = (arr[counter_arr] * 10) + ((double)get[index++] - (double)'0');
	}
	counter_arr++;
	return (index - 1);
}

void Operator(char get[], char* str, int& counter_str, int& index)
{
	if (get[index] == '+') str[counter_str++] = '+';
	else if (get[index] == '-')str[counter_str++] = '-';
	else if (get[index] == '*')str[counter_str++] = '*';
	else if (get[index] == '/')str[counter_str++] = '/';
	else if (get[index] == '^')str[counter_str++] = '^';
}

void InputLine(char get[], const int n)  
{
	cin.getline(get, n);
}