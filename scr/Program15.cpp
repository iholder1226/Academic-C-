/*This program calculates the number of records in a file, then dynamically creates an
  array to store the records. Once the records have been stored in the array the program 
  sorts and prints the list using a pointer array  */


//Problem#15 - Dynamic Memeory Allocation
//Isaiah Holder
//ComSc 265, 8105
//04-15-10

#include<iostream>
  using std::cout;
  using std::cin;
  using std::endl;
  using std::flush;

#include<fstream>
  using std::fstream;
  using std::ios;

struct record{
  char name[15];
  float amt;
};

int largestAmtIndex(record*[], int,int);
int sortAlpha(record* p[], int top, int NR);

int main(){
  char* fileName;
  fileName = new char[50];
  cout << "Please enter the name of the file you would like to read: " << flush;
  cin >> fileName;

  //Calculate the number of records in the file and store the value in NR.
  fstream fin(fileName,ios::in | ios::binary);
  fin.seekg(0,ios::end);
  long lastBite = fin.tellg();
  int NR = lastBite / sizeof(record);
  fin.seekg(0,ios::beg);

  //Dynamically create an array of records NR long;
  record *recs = new record[NR];

  //Read each record from the file into the array.
  int i = 0;
  while(!fin.eof()){
    fin.read((char*)&recs[i], sizeof(record));
	i++;
  }

  //Create a record array pointer to match the new recs array.
  record** ptr = new record*[NR];
  for(i = 0; i < NR; i++){
    ptr[i] = &recs[i];
  }

  //sort the pointer array by amt.
  for(i = 0; i < NR; i++){
    int largeSub = largestAmtIndex(ptr,i,NR);
	//switch pointers
    record *temp = ptr[i];
	ptr[i] = ptr[largeSub];
	ptr[largeSub] = temp;
	
  }//for

   //Print pointer list.
  cout << endl << "List sorted by amount " << endl;
  for(i = 0; i < NR; i++){
	  cout<<ptr[i]->name << " " << (*ptr[i]).amt << endl;
  }//for
  system("pause");
  

  //sort the pointer array by name.
  for(i = 0; i < NR; i++){
	  int smallSub = sortAlpha(ptr,i,NR);
      //switch pointers
	  record* temp = ptr[i];
	  ptr[i] = ptr[smallSub];
	  ptr[smallSub] = temp;
	  
  }//for

  //Print pointer list.
  cout << endl << "List sorted by name" << endl;
  for(i = 0; i < NR; i++){
	  cout<<ptr[i]->name << " " << (*ptr[i]).amt << endl;
  }//for
  system("pause");
  
  delete []recs;
  return 0;
}//main()


int largestAmtIndex(record* p[], int top, int NR){
  int largeSub = top;
  float largestAmt = p[top]->amt;
  for(int i = top + 1; i < NR; i++ ){
	  if(p[i]->amt  > largestAmt){
        largestAmt = p[i]->amt;
        largeSub = i;
	  }//if
  }//for
  return largeSub;
}//sortSmallest

int sortAlpha(record* p[], int top, int NR){
	int smallSub = top;
	int x;

	for(int i = top + 1; i < NR; i++){
		x = strcmp(p[i]->name,p[smallSub]->name);
	   if(x < 0){
          smallSub = i;
	   }
	}
	return smallSub;
}

