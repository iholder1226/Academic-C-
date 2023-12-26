//This progam uses an array of pointers to print out a number in english. The number is input from the user.
//Program#17 - Array of pointers to strings
//Isaiah Holder
//ComSc - 255, 8105
//4/30/10

#include"iostream"
using namespace std;
using std::endl;
void printGroup(int digit,int count);
int main(){

	int inputNum;
    long int base,digit;
	base = 1000000;
    
	//Prompt user for input
	cout << "Please enter a number: ";
	cin >> inputNum;

  //Check to see if the input is negative. 
  if(inputNum * -1 > 0){cout << "Negative "; inputNum *= -1;}

  //Break the input number into seperate number groups 
  int count = 0;
  while(count < 3){ 
	  if(inputNum == 0){printGroup(inputNum, count);break;}
	  while(true){
	    if(inputNum/base > 0){
		    digit = (inputNum - (inputNum%base))/base;
			count++;
			if(count < 3)digit = digit%base;
			inputNum = inputNum%base;
			base = base/1000;            
		    break;
	    }
	    count++;
		inputNum = inputNum%base;
	    base = base/1000;
	  }//while
      
	  //print the current number group
	  printGroup(digit,count);
	 
	}//while
    cout << endl;
	system("pause");
	return 0;
}






void printGroup(int digit,int count){
    
	char* ones[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	char* teens[10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
		             "eight-teen","nineteen"};
	char* tens[8]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	char* group[3]={"hundred","thousand,","million,"};
	

      int flag = 0;
	  if(digit == 0){cout << ones[digit];}
      int temp = digit/100;
	  if(temp > 0){
		 cout << ones[temp] << " ";
		 cout << group[0]  << " ";
		 flag = 1;
	  }
	  temp = digit%100;
	  if(temp/10 > 0 && temp/10 < 2) {
		 temp = temp%10;
         cout << teens[temp] << " ";
		 flag = 1;
		 if(count > 2)return;
		 else if(flag && count == 1){cout  << group[2] << " ";}
	     else if(flag && count == 2 ){cout << group[1] << " ";}
		 return;
	  }
	  else if(temp/10 > 0){
		  cout << tens[(temp/10)-2];
		  temp = temp%10;
		  if(temp > 0){
			  cout << "-";
		  }
		  else
			  cout << " ";
		  flag = 1;
	  }//else if
	  temp = digit%10;
	  if(temp > 0){
        cout << ones[temp] << " ";
		flag = 1;
      }

	  if(flag && count == 1){cout  << group[2] << " ";}
	  else if(flag && count == 2 ){
		  cout << group[1] << " ";
	  }	  
	  flag = 0;
}
