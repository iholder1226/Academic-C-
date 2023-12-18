//The following program uses a two dimensional array to create the game "Bomesweeper"
//Program#9- 2-d arrays and functions
//Isaiah Holder
//ComSc-265, 8105
//03-04-2010

#include<ctime>
#include<iostream>
using namespace::std;

void newBoard(int bombs[][5]);
void drawBoard(int bombs[][5], int hit);
void searchArea(int bombs[][5], int num1, int num2, int& hit);
int main(){	
	char agine;

	cout << "**************************BOMBESWEAPER**********************"<< endl;
	cout << endl << "There are five bombs hidden in a 5x5 mile streach of land." << endl
		   <<"Enter a pair of numbers in the range of 1-5  to indicate the row and colmn of " 
		   << endl << "the square mile you think might have a bomb." 
		   << endl << endl << "You have 7 trys to find as many bombs as you can. " <<endl;
	  
	do{
	  /*Create a matrix to represent the search area, then place five bombs in random
	  locations througout the matrix. A bomb is represented by a 1 and a empty area is
	  reprsented by 0*/
	  int bombs[5][5]={{0},{0}};
	  newBoard(bombs);

	  int num1, num2, hit;
	  hit = 0;
	 

	  //Loop through seven user entrys
	  for(int i = 0; i < 7; i++){

		  //Check for valid input
		  do{
		    cout << endl << "Enter guess " << i+1 << ": ";
		    cin >> num1 >> num2;
		    if(num1 > 5 || num1 < 1 || num2 > 5 || num2 < 1){
              cout << "OUTSIDE SEARCH AREA!" << endl;
		    }//if
		  }//do
		  while(num1 > 5 || num1 < 1 || num2 > 5 || num2 < 1);
	   
		  //subtract 1 so that the input values match the bombs array sub-scripts
	      num1 -= 1;
	      num2 -= 1;

		  /*The searchArea function checks the bombs array aginst the user input,
		  and then informs the user if they found a bomb or not.*/
          searchArea(bombs,num1,num2,hit);
      }//for
      /*The drawBoard function prints the results of the game, then prints the values
	  stored in the bombs array.*/
      drawBoard(bombs,hit);
	
	  cout << "Would you like to play again(y/n).";
	  cin >> agine;
	}//do
	while(agine == 'y');
  return 0;
}//main()


void drawBoard(int bombs[][5], int hit){
  
  cout << endl << "RESULTS" << endl 
	   << endl << "You found " << hit << " bomb(s). " << endl
	   << "Value 1 indicates the location of a bomb that was not found."
	   << endl << "Value 2 indicates the location of a bomb you found." << endl
	   << "Value 3 indicates a place you searched but found nothing. " << endl << endl;

  for(int m = 0; m < 5; m++){
	  for(int j = 0; j < 5; j++){
        cout << bombs[m][j] << "    ";
	  }//for
	  cout << endl << endl;
	}//for
  cout << endl;	
}//drawBoard()


void newBoard(int bombs[5][5]){
    int randNum1;
	int randNum2;
	for(int i = 0; i < 5; i++){ 
	  srand(time(0));
        
	  do{
	       randNum1 = rand()%5;
	       randNum2 = rand()%5;
	    }//do
	    while(bombs[randNum1][randNum2] != 0);
	    bombs[randNum1][randNum2] = 1;
   	  }//for

}//newBoard()



void searchArea(int bombs[][5], int num1, int num2, int& hit){
  if(bombs[num1][num2] == 1){
            cout << "Good work, you found a bomb!"  << endl;
		    bombs[num1][num2] = 2;
			hit++;
	      }//if
	      else if(bombs[num1][num2] == 0){
	        cout << "No bombs here." << endl;
            bombs[num1][num2] = 3;	
	      }//else if
	      else if(bombs[num1][num2] == 2 || bombs[num1][num2] == 3){
            cout << "You already searched there." << endl;
	      }//else if
}//searchArea()