/*This progam sets up 10 variables of type struct entry. Then connects all the entries 
  together to form a linked list. A function to print the address,value and pointer address
  of each node in the list is created, along with delete/insert functions to update the list.
*/
//Program#13, pointers/linked lists
//Isaiah Holder, 0871484
//ComSc-265, 8105
//3/26/10

#include<iostream>
using std::cout;
using std::endl;

struct entry{
  int value;
  entry* next;
};

void printList(const entry* h);
entry* deletenode(int num, entry* h);
entry* insertnode(entry &n, entry* h);
int main(){
	//Declare 10 type entry variables, then connect them to form a linked list;
    entry n1,n2,n3,n4,n5,n6,n7,n8,n9,N10;
	entry* head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = &N10;
	N10.next = 0;
    
	//Assign values to each node;
	n1.value = 2;
	n2.value = 6;
	n3.value = 9;
	n4.value = 13;
	n5.value = 22;
	n6.value = 25;
	n7.value = 30;
	n8.value = 35;
	n9.value = 40;
	N10.value = 50;
    
	//delete a node
	entry* temp;
	temp = head;
	n6.next = deletenode(25,temp);
   
	temp = head;
	head = deletenode(2,temp);

	temp = head;
	N10.next = deletenode(50,temp);

	//create three new nodes
    entry n11, n12, n13;
	n11.value = 17;
	n12.value = 75;
	n13.value = 1;

	//insert the new nodes one at a time at the end of the list.
    temp = head;
	n9.next = insertnode(n11,temp);

	temp = head;
	n11.next = insertnode(n12,temp);
   
	temp = head;
	n12.next = insertnode(n13,temp);


	//print the updated list
	temp = head;
	printList(temp);
	system("pause");
	return 0;
}//main()


void printList(const entry* pointer){
	cout << "****************************** Linked List Data *******************************"
		 << endl << endl;
	while(pointer != 0){
		cout << pointer << " " << pointer->value << " " << pointer->next
			 << endl;
		pointer = pointer->next;
	
	}//while()
}//printlist()


entry* deletenode(int num, entry* pointer){
	int i = 1;
	while( pointer->value != num && pointer->next->value != num){
		pointer = pointer->next;
		i++;
	}//while()
	
	if(pointer->value == num){
		pointer = pointer->next;
	}//if
	else {
		   pointer->next = pointer->next->next;
		 }//else

  return pointer;
}//deletenode()


entry* insertnode(entry &n, entry* pointer){
	while(pointer->next != 0){
		pointer = pointer->next;
	}//while()

	n.next = pointer->next;
	pointer = &n; 
    return pointer;
}//insertnode()
