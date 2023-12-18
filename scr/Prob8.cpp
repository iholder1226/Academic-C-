//This program converts any number from base x to base y(bases are 2 - 16)
//Problem #8, arrays and functions
//Isaiah Holder
//ComSc 265-8105
//03-01-2010

#include<iostream>
#include<cmath>
#include<cctype>
using namespace::std;

void getInput(char numbers[],int& base1,int& base2);
void validate(char numbers[], double numToValidForm[]);
int toBaseTen(double validDigits[], int size, int& base1);
int tenToBaseX(int rem[],int num1, int base2);

int main(){
char again;
cout << "************************** Base Converter *************************" << endl;
cout << endl;
do{
  int  base1, base2;
  char numbers[10];
  char values[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
 
  getInput(numbers,base1,base2);
  double validDigits[10];          // use to store values converted from char to double
  validate(numbers, validDigits);  //convert all characters of the numbers array,
                                   //store new values in validDigits
 
  //convert the double array validDigits into base ten, store the value in num1
  int size = strlen(numbers);
  int num1 = toBaseTen(validDigits, size, base1); 

  //Convert from base 10 to base XXX
   int rem[50];
   int numLength = tenToBaseX(rem, num1, base2);

   cout << "The base " << base1 << " number " ;
   for(int i = 0; i < size; i++){
     cout << numbers[i];
   }//for
   cout << " converted to base " << base2
	   << " is equal to : ";

   int j;
   for(j = numLength-1; j >= 0; j--){
     cout << values[rem[j]];
	 
   }//for
   cout << endl;
   cout << endl << "Would you like to make another conversion?(y/n): ";
   cin >> again;
  }//do
  while(again == 'y' || again == 'Y');
  return 0;
}//main




void getInput(char numbers[],int& base1,int& base2){
    cout << "Please enter a number followed by it's current base, " 
		 << endl << "followed by the base you wish to convert to: "; 
	cin  >> numbers >> base1 >> base2;
}//getInput



int toBaseTen(double numBase10[], int size, int& base1){
    int num =0; 
	for(int i = 0; i < size; i++){ 
	  num += numBase10[i];
	  if(i != size - 1){
	    num *= base1;
	  }//if
	}//for
  return num;
}//toBaseTen

int tenToBaseX(int rem[],int num1, int base2){
  int temp = num1;
  int i = 0;
 
  do{
    rem[i] = num1%base2; 
	num1 = num1/base2;
    i++;
  }//do
  while(num1 !=0);
  return i;
}//tenToBaseX



void validate(char numbers[], double numBase10[]){
    char digits[10]={'0','1','2','3','4','5','6','7','8','9'};
	
	for(int i = 0; i < strlen(numbers); i++){
		switch(numbers[i]){
		case 'a':
		case 'A':
            numBase10[i] = 10;
			break;
		case 'b':
		case 'B':
			numBase10[i] = 11;
			break;
		case 'c':
		case 'C':
			numBase10[i] = 12;
			break;
		case 'd':
		case 'D':
			numBase10[i] = 13;	
			break;
		case 'e':
		case 'E':
			numBase10[i] = 14;
			break;
		case 'f':
		case 'F':
			numBase10[i] = 15;
			break;
		}//switch

		for(int j = 0; j < strlen(digits); j++){
		  if(numbers[i] == digits[j]){
            numBase10[i] = j;
		  }//if
		}//for
	}//for
}//validate