#include<iostream>
#include<math.h>

using namespace std;
void Input(char* str, double* arr, char* get, const int n);
int  isInteger(double* arr, char* get, int& index, int& counter_arr);
void Calculator(char* str, double* arr, int counter_arr, int counter_str)
{
	int index;
	for (int j = 0, c = 0; j < counter_arr && c < counter_str; c++, j++)
	{
		if (str[c] == '^')
		{
			arr[c + 1] = pow(arr[j], arr[j + 1]);
			str[c] = '?';
		}
	}
	for (int j = 0, c = 0, index; j < counter_arr && c < counter_str; c++, j++)
	{
		if (str[c + 1] == '?' && (str[c] == '*' || str[c] == '/'))
		{
			index = c + 1;					           //  index points to '?'
			for (; str[index] == '?'; index++);       //  after the loop, the index points the item with which to perform the operation

			str[c] == '*' ? arr[index] = arr[j] * arr[index] : arr[index] = arr[j] / arr[index];	//	assign the result to an array element
			str[c] = '?';
			continue;
		}

		if (str[c] == '*') {

			arr[j + 1] = arr[j] * arr[j + 1];
			str[c] = '?';
		}
		else if (str[c] == '/')
		{
			arr[j + 1] = arr[j] / arr[j + 1];
			str[c] = '?';
		}
	}
	for (int c = 0, j = 0; j < counter_arr && c < counter_str; c++, j++)
	{
		if (str[c + 1] == '?' && (str[c] == '-' || str[c] == '+'))
		{
		    index = c + 1;					     			 //  index points to '?'
			for (; str[index] == '?'; index++);				//  after the loop, the index points the item with which to perform the operation

			str[c] == '+' ? arr[index] = arr[j] + arr[index] : arr[index] = arr[j] - arr[index];	//  assign the result to an array element
			continue;
		}
		if (str[c] == '+')
		{
			arr[j + 1] = arr[j] + arr[j + 1];
		}
		else if (str[c] == '-')
		{
			arr[j + 1] = arr[j] - arr[j + 1];
		}
	}
	for (int i = 0; i < counter_arr; i++)cout << "arr[" << i << "] = " << arr[i] << endl;
   cout << "Rezultat >> " << arr[counter_arr - 1] << endl;
}

///////////////////////////////////////////////		main
 void main()
{
	 const int n = 50;
	 double arr[n]{};
	 char str[n];
	 char get[n];

	 cout << "1. In the end of equation put ' = '\n Enter the equation >> ";  cin.getline(get, n);

	 Input(str, arr, get, n);
}
//////////////////////////////////////////////

 void Input(char* str, double* arr, char* get, const int n)
 {
	 int counter_arr = 0, counter_str = 0;		

	 for (int i = 0; get[i] != '='; i++)
	 {
		 if (get[i] >= 48 && get[i] <= 57 || (get[i] == '-') && get[i + 1] >= 48 && get[i + 1] <= 57)
		 {
			 i = isInteger(arr, get, i, counter_arr);
		 }
		 else
		 {
			 switch (get[i])
			 {
				 case '+': str[counter_str++] = '+'; break;
				 case '-': str[counter_str++] = '-'; break;
				 case '*': str[counter_str++] = '*'; break;
				 case '/': str[counter_str++] = '/'; break;
				 case '^': str[counter_str++] = '^'; break;
				 case '(': str[counter_str++] = '('; break;
				 case ')': str[counter_str++] = ')'; break;
			 }
		 }
	 }
	 Calculator(str, arr, counter_arr, counter_str);
 }

int isInteger(double* arr, char* get, int& index, int& counter_arr)
{
	int numb = 1, numb_2 = 10;
	while((get[index] >= 48 && get[index] <= 57) || get[index] == '.')
	{
		if (get[index] == '.' || numb_2 == 1) 
		{
			if (get[index] == '.')index++;
			
				numb *= 10;
				numb_2 = 1;
		}
		arr[counter_arr] = (arr[counter_arr] * numb_2)  +  (((double)get[index++] - (double)'0') / numb);		
	}
	counter_arr++;
	return (index - 1);
}

	
