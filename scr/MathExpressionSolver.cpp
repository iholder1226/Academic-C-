// This program reads in an expression, and then solves it.

//Program#19 - Final 
//Isaiah Holder, 0871484
//ComSc-265, 8105
//5-20-10

#include<iostream>
using namespace::std;

struct node{
  char token[9];
  node* next;
  node* prev;
};
void printExp(node* h);
void addQ(node*, char*);
node* popQ(node* head);
void addExp(node* LP, node* RP);
void multExp(node* LP, node* RP);
void removeP(node* LP, node* RP);
void tokenizer(node* head, char* expression);
char* intToChar(float ans);
float charToFloat(char* arg);
void solveEx(node* head);
int errorHandler(char* expression);

int main(){

	//Declare variables, start double liked list with two nodes, 
	//the first containing nothing, and the second a left parenthesis

	char* expression = new char[];
	char again;

	do{
	node* head = 0;
    head = new node();
	head->next = new node();
	strcpy(head->next->token , "(" );
	head->next->prev = head;

	int error = 0;
	do{
	    //Prompt user for expression
	    cout << "Please enter an expression:";
	    cin >> expression;

	    //Check for errors in the expression
        error = errorHandler(expression);
	    if(error > 0){cout << "Invalid Expression!" << endl << endl;}
   	  }
    while(error > 0);
	//Add token from expression to a double linked list
    tokenizer(head,expression);

	//Solve Expression
	solveEx(head);

	//Print list
    node* temp = head;
    printExp(temp);

    //Delete list
	while(head){
	  temp = head->next;
      delete head;
	  head = temp;
    }//while()
    delete head;

    cout << endl << "Would you like to make another calculation?(y/n):";
	cin >> again;
	again = toupper(again);
	cout << endl;

  }//do
  while(again != 'N');
return 0;
}//main()


//***************************************************FUNCTION BODYS*****************************************************

//**********************************************PERFORM MULTIPLICATION AND DIVISION*************************************
void multExp(node* LP, node* RP){
    node* temp, *LPtemp;
    LPtemp = LP;
	float arg1, arg2, result;
	while(LP->next != RP){
		LP = LP->next;
		switch(*LP->token){
		  case '*':
			  arg1 = charToFloat(LP->prev->token);
			  arg2 = charToFloat(LP->next->token);
              result = arg1 * arg2;
			  strcpy(LP->token,intToChar(result));
			  LP->prev = LP->prev->prev;
              temp = LP->prev->next;			 
			  LP->prev->next = LP;
              delete temp;

			  LP->next = LP->next->next;
			  temp = LP->next->prev;
			  LP->next->prev = LP;
			  delete temp;
			  break;

		  case '/':
			  arg1 = charToFloat(LP->prev->token);
			  arg2 = charToFloat(LP->next->token);
              result = arg1 / arg2;
			  strcpy(LP->token,intToChar(result));
			  LP->prev = LP->prev->prev;
			  temp = LP->prev->next;
			  LP->prev->next = LP;
              delete temp;

			  LP->next = LP->next->next;
			  temp = LP->next->prev;
			  LP->next->prev = LP;
			  delete temp;
			  break;

		  default:
			  break;
		}//switch
	}//while
	LP=LPtemp;
}
//*******************************************PERFORM ALL ADDITION AND SUBTRACTION*****************************************

void addExp(node* LP, node* RP){
    node* temp,*LPtemp;
    LPtemp = LP;;
	float arg1, arg2, result;
	while(LP->next != RP){
		LP = LP->next;
		switch(*LP->token){
		  case '+':
			  arg1 = charToFloat(LP->prev->token);
			  arg2 = charToFloat(LP->next->token);
              result = arg1 + arg2;
			  strcpy(LP->token,intToChar(result));
			  LP->prev = LP->prev->prev;
              temp = LP->prev->next;			 
			  LP->prev->next = LP;
              delete temp;

			  LP->next = LP->next->next;
			  temp = LP->next->prev;
			  LP->next->prev = LP;
			  delete temp;
			  break;
		  case '-':
			  arg1 = charToFloat(LP->prev->token);
			  arg2 = charToFloat(LP->next->token);
			  if(arg2 == 0){//arg1 is negative
			    break;
			  }
              result = arg1 - arg2;
			  strcpy(LP->token,intToChar(result));
			  LP->prev = LP->prev->prev;
			  temp = LP->prev->next;
			  LP->prev->next = LP;
              delete temp;

			  LP->next = LP->next->next;
			  temp = LP->next->prev;
			  LP->next->prev = LP;
			  delete temp;
			  break;
		  default:
			  break;
		}//switch
	}//while
	LP=LPtemp;
}

//*******************************************REMOVE PARENTHESIS*********************************************************
void removeP(node* LP, node* RP){
	node* temp = LP->prev;
	temp->next = LP->next;
	LP->next->prev = temp;
	delete LP;

	temp = RP->prev;
	temp->next = RP->next;
	RP->next->prev = temp;
	delete RP;

}
//*************************************************ADD A NODE TO Q-LIST*************************************************
void addQ(node*  head, char* value){
	while(head->next != 0){
		head = head->next;
	}
	head->next = new node();
	head->next->prev = head;
	strcpy(head->next->token,value);
}

//***************************************************PRINT Q-LIST************************************************************
void printExp(node* h){
	while(h != 0){
		cout << h->token;
		h = h->next;
	}
}

//************************************************TOKENIZE EXPRESSION***************************************************
void tokenizer(node* head, char* expression){
   //Declare and initialize a delimiter to tokenize the expression.
	char delim[7]={'(',')','+','-','/','*',' '};

	//tokenize the entered expression, add each token to the list.
	int expSize;
	char token[9];
	expSize = strlen(expression);
    int j = 0;
	node* temp;
	int count2 = 0;
	//Loop through each char in the expression
	for(int i = 0; i < expSize; i++){
	    int count = 0;
	    int flag = 0;
        //Loop to see if the current char is one of the delimeters, if so set a flag to true
		while(true){
			if(count == 7) {break;}
			if(expression[i] == delim[count]){
               flag = 1;
			   break;
			}//if
			count++;
		}//while()
		/*if the flag is true or its the last char in the expression add the current token to list, 
		  then add dilimeter as token to the list. */
		if(flag|| i == expSize-1){ 
			//End of expression and the flag is false
		   if(i == expSize-1 && flag == 0){
			   token[j++] = expression[i];
			   token[j] = NULL;
			   temp = head;
			   addQ(temp,token);
			   temp = head;
			   addQ(temp,")");
			   temp = head;
			   addQ(temp,"");
			   break;
		   }//if
             
		    //End of expression and flag is true
		   else if(i == expSize-1 && flag == 1){
             temp = head;
		     token[j] = NULL;
             addQ(temp,token);

             temp = head;
		     char opr[2];
		     opr[0] = delim[count];
		     opr[1] = NULL;
		     addQ(temp,opr);

			 temp = head;
		     addQ(temp,")");
			 temp = head;
			 addQ(temp,"");

			 break;
		   }
           
		   //Flag is true
		   temp = head;
		   token[j] = NULL;

		   if(strcmp(token,"") != 0){
             addQ(temp,token);
		   }
		   else if(expression[i] == '-' && expression[i-1] == '('){
	         flag = 0;
	         token[j++] = expression[i++];
	         while(flag == 0){
	           token[j++] = expression[i++];
               for(int k = 0; k < 7; k++) { 
	             if(expression[i] == delim[k]){
                   flag = 1;
	             }//if
               }//for
	         }//while
	         i -= 1;
			  
			token[j]=NULL;
			temp = head;
			addQ(temp,token);

			if(i == expSize-1){
				for(int jp = 0; jp < j; jp++){token[jp] = 0;}
	            j = 0;
				token[j++] = expression[i++];
                token[j++] = expression[i++];
				token[j]=NULL;
			    temp = head;
				addQ(temp,token);

				temp = head;
		        addQ(temp,")");
		        temp = head;
                addQ(temp,"");
			}//if

			//Clear valuse stored in token, for next token
		     for(int jp = 0; jp < j; jp++){token[jp] = 0;}
		     j = 0;
			 continue;
		   }//else if

		   if(i < expSize-1){
		         temp = head;
		         char opr[2];
		         opr[0] = delim[count];
		         opr[1] = NULL;
		         addQ(temp,opr); 
		   }//if
		  
		  
		   //Clear valuse stored in token, for next token
		   for(int jp = 0; jp < j; jp++){token[jp] = 0;}
		   j = -1;
		}//if
		else{
		  token[j] = expression[i];
		}
		j++;
		count2++;
	}//for
}//tokenizer()

//**************************************************CONVERT CHAR[] TO FLOAT**************************************************
float charToFloat(char* arg){
  char num[11] = {"0123456789"};
  int len;
  float intArg,group;
  group = 1;
  intArg = 0;
  len = strlen(arg);
  for(int i = len-1; i >= 0; i--){
   
   for(int j = 0; j < 10; j++){
	   if(arg[i] == num[j]){
         intArg += j * group;
		 break;
	   }
	   if(arg[i]== '.'){
          intArg /= group;
		  group = .1;
		  break;
	   }
   }
   group *= 10;
  }//for()
  //In case of negative numbers
  if(arg[0]=='-'){
    intArg *= -1;
  }
  return intArg;
}//charToInt()

//***********************************************CONVERT FLOAT TO CHAR[]*****************************************************
char* intToChar(float ans){
  int group = 100000;
  char table[11]={"0123456789"};
  char* newNum = new char[];
  int j;
  int i = 0;
  if(ans * -1 > 0){
	  ans *= -1;
	  newNum[i++]='-';
  }
  int flag = 0;
  float temp = ans;
  while(group > 0){
    
	float temp = (int)ans/group;
	if(temp > 0 && flag == 0){
      flag = 1;
	}
	if(flag > 0){
	  j = 0;
	  while((int)temp/1 != j){
        j++;
	  }//while
	  newNum[i++] = table[j];
      ans = (int)ans%group;
	}//if
	group = group / 10;
  }//while
  
  temp = temp*100;
  temp  = (int)temp%100;
  if(temp > 0){
    newNum[i++]='.';
	
	char* decNum = intToChar(temp);
	int len = strlen(decNum);
	if(temp < 10){
	  newNum[i++]='0';
	}
	for(int k = 0; k < len; k++ ){
		newNum[i++] = decNum[k];
	}//for
  }//if
  newNum[i]=NULL;
  return newNum;
}//intToChar

//***********************************************ERROR HANDLER***************************************************************
int errorHandler(char* expression){
  int i = 0;
  int lp,rp;
  int result = 0;
  lp=rp=0;
  do{
	  if(expression[i]=='('){lp++;}
	  else if(expression[i]==')'){rp++;}
	  i++;
  }
  while(expression[i] != NULL);
  if(lp != rp){result = 1;}
  return result;
}
//***********************************************SOLVE EXPRESSION************************************************************
void solveEx(node* head){
  	node* temp ;
	if(strcmp(head->next->token,"(") != 0){return;}
	  //Traverse until a right parenthesis  
	  node* RP;
      temp = head;
	  while(strcmp(temp->token, ")") != 0){
		  if(temp->next == 0){break;}
	   	  temp = temp->next;
	  }//while
      RP = temp;


	  //Traverse until a left parenthesis
	  node* LP;
	  temp = RP;
	  while(strcmp(temp->token,"(") != 0){
		  if(temp->next == 0){break;}
		  temp = temp->prev;
	  }
      LP = temp;

	  //Perform all multiplication and division.
	  multExp(LP,RP);

	  
      //Perform all addition and subtraction
      addExp(LP,RP);

	  
      
      //Remove Parenthesis
      removeP(LP,RP);

	  temp = head;
	  solveEx(temp);
}
