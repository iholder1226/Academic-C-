/*This program calculates the number of day between two entered dates. 
  It also tells the day of the week the two entered dates fall on*/

//Program#10 - structures
//Isaiah Holder, 0871484
//Comsc 265 - 8105
//03-11-10
#include<iostream>
using namespace::std;

struct date{
long month, day, year;
};

long calcN(date);
long f(long year, long month);
long g(long month);
void printDayOfWeek(date);
long calcDaysBetween(date d1, date d2);

int main(){
  char again;
  cout << "******************************** Days Between *********************************"<<endl;
  do{
    date d1, d2;
	cout << endl << "Enter first date(i.e 12 21 1984): ";
    cin >> d1.month >> d1.day >> d1.year;
	cout << "Enter second date(i.e 12 21 1984): ";
    cin >> d2.month >> d2.day >> d2.year;
  
    cout << endl << "The first date entered falls on a ";
    printDayOfWeek(d1);
    cout << "." << endl << "The second date entered falls on a " ;
    printDayOfWeek(d2);
    cout << endl << endl << "There are " << calcDaysBetween(d1,d2); 
	cout << " days between the two entered dates."<< endl;
    cout << endl << "Would you like to make another entry?(y/n): ";
    cin >> again;
    cout << endl;
  }//do
  while(again == 'y' || again == 'Y');
  return 0;
}//main

long calcN(date d){
  long n = 1461 * f(d.year,d.month)/4 +153 * g(d.month)/5 + d.day;
  return n;
}//calcN

long f(long year, long month){
  long f = 0;
  if(month <= 2){
    year =  year - 1;
	f = year;
  }
  else
	  f = year;

  return f;
}//f()
long g(long month){
  long g = 0;
  if(month <= 2){
	g = month + 13;
	return g;
  }//if
  else
	 g = month + 1;
  return g;
}//g()

void printDayOfWeek(date d1){
	int i = (calcN(d1) - 621049)%7;
	switch(i){
	  case 0:
		  cout << "sunday";
		  break;
	  case 1:
		  cout << "monday";
		  break;
	  case 2:
		  cout << "tuesday";
		  break;
	  case 3:
		  cout << "wendsday";
		  break;
	  case 4:
		  cout << "thursday";
		  break;
	  case 5:
		  cout << "friday";
		  break;
	  case 6:
		  cout << "saturday";
		  break;
	}//switch
}//printDayOfWeek

long calcDaysBetween(date d1, date d2){
  long n2 = calcN(d2);
  long n1 = calcN(d1);
  long daysBetween;
  if(n1 > n2){
    daysBetween = n1-n2;
  }//if
  else
	  daysBetween = n2-n1;
  return daysBetween;
}//calcDaysBetween()