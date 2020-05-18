#include<iostream>
#include<math.h>
using namespace std;
void InputLine(char str[], const int n);
void Input(char* str, double* arr, char* get, const int n);
int  isInteger(double* arr, char* get, int& index, int& counter_arr);
void Ischar(char get[], char* str, double* arr, int &counter_str, int& counter_arr, int& index);

int Calculator(char* str, double* arr, int& counter_arr)
{
	double rez = arr[0];
	for (int i = 1; i < counter_arr ; i++) { 

		 if (str[i - 1] == '+')  rez += arr[i];
		 else if (str[i - 1] == '-') rez -= arr[i];
		 else if (str[i - 1] == '*') rez *= arr[i];
		 else if (str[i - 1] == '/') rez /= arr[i];
		 else if (str[i - 1] == '^') rez = pow(rez, arr[i]);
	}
	return rez;
}

 void main()
{
	 const int n = 30;
	 double arr[n];
	 char str[n];
	 char get[n];
	 Input(str, arr, get, n);
}

void Input(char* str, double* arr, char* get, const int n)
{ 
	int counter_arr = 0, counter_str = 0;
	cout << "1. In the end of equation put ' = '\n Enter the equation >> "; InputLine(get, n);

	for (int i = 0; get[i] != '='; i++)
	{
		if (get[i] >= 48 && get[i] <= 57 )
		{
			i = isInteger(arr, get, i, counter_arr);
		}
		else if (get[i] != ' ')
		{
			Ischar(get, str, arr, counter_str, counter_arr, i); 
		}
	}
	cout << endl << "Rezult >> " << Calculator(str ,arr ,counter_arr);
}

int isInteger(double* arr, char* get, int& index, int& counter_arr)
{
	double buff[4];
	double sum = 0;
	int i2 = 0;
	while(get[index] >= 48 && get[index] <= 57)
	{
		buff[i2] = (double)get[index++] - (double)'0';
		sum = (sum * 10) + buff[i2++];
	}
	arr[counter_arr++] = sum;
	return (index - 1);
}

void Ischar(char get[], char* str, double* arr, int& counter_str, int& counter_arr, int& index)
{
	if (get[index] == '+' || get[index] == '-')
	{
	     get[index] == '+' ? str[counter_str++] = '+' : str[counter_str++] = '-';
	}
	else if (get[index] == '*' || get[index] == '/')
	{
		get[index] == '*' ? str[counter_str++] = '*' : str[counter_str++] = '/';
	}
	else if (get[index] == '^') str[counter_str++] = '^';

}

void InputLine(char get[], const int n)  
{
	cin.getline(get, n);
}