/*This program writes two arrays of structures on to two different disk files, then reads and 
  displays the data written onto the two files.*/

//Problem #11, writing structures of disk
//Isaiah Holder, 0871484
//ComSc 265-8105

#include<fstream>
using std::ofstream;
using std::ifstream;

#include<iostream>
using std::cout;
using std::endl;
using std::ios;


struct record{
	char name[15];
	float amt;
};

void writefile(char filename[], record rec[], int size);
void displayfile(char filename[]);

int main(){

	/*create and populate two record arrays. The master array contains the data for the 
	master file. The Trans array contains the data of recent transactions. */
	const int mastersize = 10;
	record master[10]={{"Helen",10},{"Julie",20},{"Lena",30},{"Alan",40},{"Annie",50},
	                   {"may",60},{"Lee",70},{"Sam",80},{"June",90},{"Bill",100}};
    
	const int transize = 7;
	record trans[transize]={{"Lena",10.},{"Julie",5.75},{"Lee",15.02},{"Ed",40.},{"Julie",10.00},
	                 {"Art",5.00},{"Bill",7.32}};

	//write content of the master array to a file named Master.dat
	writefile("Master.dat", master, mastersize);
	
	//write content of the Trans array to a file named Trans.dat
	writefile("Trans.dat", trans, transize);
    
	//read and display the data written to the master file
	cout << "Master File" << endl << endl;
	displayfile("Master.dat");

	//read and display the data written to the transaction file
    cout << endl << "Transaction File" << endl << endl;
	displayfile("Trans.dat");
	
    system("pause");
	return 0;
}



void writefile(char filename[], record rec[], int size){
    ofstream fout;
	fout.open(filename);
	for(int i = 0; i < size; i++){
      fout.write((char*)&rec[i],sizeof(record));
	}
	fout.close();
}


void displayfile(char filename[]){
    record temprec;
	ifstream fin;
	fin.open(filename, ios::binary);
	fin.read((char*)&temprec,sizeof(record));
	while(fin){
		cout << temprec.name << "\t"
			 << temprec.amt << endl;
		
      fin.read((char*)&temprec,sizeof(record));
	}
	fin.close();


}
