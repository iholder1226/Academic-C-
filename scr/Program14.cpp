/*This program reads a polish string, then calculates the value*/
//Problem#14 - linked lists
//Isaiah Holder
//ComSc 265, 8105
//04-02-10

#include <string>
#include "iostream"

using std::cout;
using std::cin;
using std::endl;

//create a structure to a serve as the nodes of each lists
struct entry{
  char value[9];
  entry* next;
};

//function profiles
entry* addStack(entry* , char*);
entry* popStack(entry*, char*);
void addQ(entry*,char*);
entry* popQ(entry*, char*);
void printList(entry*);
int charToInt(char*);
char* intToChar(int);

int main(){
  //Create the list head and variables needed for input.
  char polStr[50];
  char token[9];
  entry* temp,*newEntry = 0, *head = 0;

  int entryCount = 0;
  head = new entry();
  temp = head;
  
  //Prompt the user for input, then store the value in a char array.
  cout<< "Please enter an equation in reverse polish notation: ";
  cin.getline(polStr,50);

  //Seperate each value from the string of input, then add that value to a queue list.
  int len = strlen(polStr);
  int j = 0;
  for(int i = 0; i <= len; i++){ 
    if(polStr[i] != ' ' && i != len ){
      token[j] = polStr[i];
    }
	else {
	  if(entryCount == 0){
		token[j]=NULL;
	    strcpy(head->value, token);
		entryCount++;
		j = -1;
	  }//if
	  else {
		  if(i == len-1){
            token[len] = NULL;
		  }//if
		  else
		      token[j]=NULL;
	      addQ(temp,token);
	      j = -1;
	  }//else
	}//else
	j++;
  }//for
  
  //Output the new created queue list.
  cout << "Polish Queue List"<< endl;
  temp = head;
  printList(temp);

  //Create a pointer to serve as the head of a stack list
  entry* tempSt,*stackHead = 0;
  stackHead = new entry(); 
  char* arg1, *arg2;
  double ans;
  
  do{
	temp = head;
    char* arg = new char[];
    head = popQ(temp,arg);
	arg1 = new char[];
    arg2 = new char[];
    int intArg1, intArg2;
	switch(*arg){
	  case '+':
			  tempSt = stackHead;
              stackHead = popStack(tempSt, arg2);
			  intArg2 = charToInt(arg2);

              tempSt = stackHead;
              stackHead = popStack(tempSt, arg1);
			  intArg1 = charToInt(arg1);

			  ans = intArg1 + intArg2;
			  arg = intToChar(ans);
              break;


      case '-':
			  tempSt = stackHead;
              stackHead = popStack(tempSt, arg2);
			  intArg2 = charToInt(arg2);

              tempSt = stackHead;
              stackHead = popStack(tempSt, arg1);
			   intArg1 = charToInt(arg1);

			  ans = intArg1 - intArg2;
			  arg = intToChar(ans);
              break;


      case '/':
			  tempSt = stackHead;
              stackHead = popStack(tempSt, arg2);
			  intArg2 = charToInt(arg2);

              tempSt = stackHead;
              stackHead = popStack(tempSt, arg1);
			  intArg1 = charToInt(arg1);

			  ans = intArg1 / intArg2;
			  arg = intToChar(ans);
              break;


      case '*':
			  tempSt = stackHead;
              stackHead = popStack(tempSt, arg2);
			  intArg2 = charToInt(arg2);

              tempSt = stackHead;
              stackHead = popStack(tempSt, arg1);
			  intArg1 = charToInt(arg1);

			  ans = intArg1 * intArg2;
			  arg = intToChar(ans);
              break;
      
	}//switch

    cout << "Polish Queue List" << endl;;
	temp = head;
    printList(temp);

    tempSt = stackHead;
    stackHead = addStack(tempSt,arg);

	cout << "Stack List" << endl;
    tempSt = stackHead;
    printList(tempSt);
  }
  while(head != 0);

  return 0;
}//main()


entry* addStack(entry* h, char* n){
  entry* newNode = new entry();
  strcpy(newNode->value,n);
  newNode->next = h;
  h = newNode;
  return h;
}//addStack()


entry* popStack(entry* h, char* x){
	strcpy(x,h->value);
	entry* n = h->next;
	delete h;
	return n;
}//popStack()


void addQ(entry* h, char* newEntry){
   
	while(h->next != 0){
		h = h->next;
		
    }
	h->next = new entry();
	strcpy(h->next->value, newEntry);
	h->next->next = 0; 
	
}//addQ()


entry* popQ(entry* h, char* x){
	strcpy(x,h->value);
	entry* n = h->next;
	delete h;
    return n;
}//popQ()


void printList(entry* p){
	while(p){
		cout << p->value << endl;
		p = p->next;
	}
	system("pause");
}//printList()


int charToInt(char* arg){
  char num[11] = {"0123456789"};
  int intArg,len,group;
  group = 1;
  intArg = 0;
  len = strlen(arg);
  for(int i = len-1; i >= 0; i--){
   
   for(int j = 0; j < 10; j++){
	   if(arg[i] == num[j]){
         intArg += j * group;
		 break;
	   }
   }
   group *= 10;
  }//for()
  return intArg;
}//charToInt()


char* intToChar(int ans){
  int group = 100000;
  char table[11]={"0123456789"};
  char* newNum = new char[];
  int j;
  int i = 0;
  int flag = 0;
  while(group > 0){
    
	int temp = ans/group;
	if(temp > 0 && flag == 0){
      flag = 1;
	}
	if(flag > 0){
	  j = 0;
	  while(temp != j){
        j++;
	  }//while
	  newNum[i++] = table[j];
      ans = ans%group;
	}//if
	group = group / 10;
  }//while
  newNum[i]=NULL;
  return newNum;
}//intToChar()