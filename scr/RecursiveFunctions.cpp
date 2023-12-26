/*This program uses a recursive function to convert a decimal number to binary.*/

//Program#18 - Recursive Functions
//Isaiah Holder
//ComSc - 255, 8105
//05-06-10

#include<iostream>
using namespace::std;

void dec2bin(int num);
int main(){
    int decNum;

	cout << endl << "Enter a decimal number to be converted to binary: ";
	cin >> decNum;
    cout << endl << "The binary equivalent of the number " << decNum << " is ";
	dec2bin(decNum);
	cout << endl;
	system("pause");
	return 0;
}

void dec2bin(int num){
  if(num > 1){
	dec2bin(num/2);
  }
  int rem = num%2;
  cout << rem;
  return;
}

