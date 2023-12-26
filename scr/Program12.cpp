//This program updates the master file from program 11

//Problem 12 Updating a disk file
//Isaiah Holder, 0871484
//ComSc 265 - 8105
//03-23-10

#include<fstream>
using std::fstream;
using std::ios;

#include<iostream>
using std::cout;
using std::endl;


struct record{
	char name[15];
	float amt;
};

int numOfRec(char fileName[], record &rec);
void readLine(char fileName[], record &rec, int recNum);
void writeLine(char fileName[], record &rec, int recNum);


int main(){
  //Two records to store data from each file.
  record master, transaction;
 
  //create a file in-stream object pointing to the master file.
  fstream mf("Master.dat",ios::in | ios::binary);
 
   //create a file out-stream object pointing to a new file
  fstream mc("Masterc.dat", ios::out | ios::binary);
 
  /*Read value from the in object, display them on the screen, then write them to the
    out object.*/
  cout << endl << "Master File" << endl;
  while(mf.read((char*)&master,sizeof(master))){
	  cout << master.name << "\t";
	  cout << master.amt << endl;
	  mc.write((char*)&master,sizeof(master));
  }
  //Close all I/O streams
  mf.close();
  mc.close();
  
  //Reset the mc I/O object's mode
  mc.open("Masterc.dat", ios::in | ios::out | ios::binary);
  

  //create a new in-file stream object, then point it to the transaction file
  fstream tr("Trans.dat",ios::in | ios::binary);
 
  //determine the number of records on the transaction file
  int lr = numOfRec("Trans.dat", transaction);
  
  tr.read((char*)&transaction,sizeof(transaction));
 
  
  int count = 1;
  int count2 = 1;

  //determine the number of records on the master file
  int n = numOfRec("Masterc.dat", master);
 
  

 
  //Update the master copy file with new data from transaction file
  while(mc.read((char*)&master,sizeof(master))) {
	  
	  if(strcmp(transaction.name, master.name)== 0){
		  mc.seekg(-sizeof(record),ios::cur);
		  master.amt += transaction.amt;		  
		  mc.write((char*)&master,sizeof(master));
	  	  mc.seekg(0, ios::beg);
		  tr.read((char*)&transaction, sizeof(transaction));
		  count = 0;
		  count2++;
        }
      
	   else if( count == n){
		  mc.seekg(0, ios::end);
		  mc.write((char*)&transaction, sizeof(transaction));
		  mc.seekg(0, ios::beg);
		  tr.read((char*)&transaction, sizeof(transaction));
		  count2++;
		}
      count++;
	  if(count2 > lr)break;
  }//while
  
  //close  open stream
  tr.close();
  

  cout << endl << "New Master Copy" << endl;
  mc.seekg(0, ios::beg);
  while(mc.read((char*)&master,sizeof(master))){
	  cout << master.name << "\t" << master.amt << endl;
  }
  system("pause");
  //close open stream
  mc.close();
  return 0;
}



//failed function
void readLine(char fileName[], record &rec, int numRec){
   int count = 0;
   fstream finfout(fileName,ios::in | ios::out | ios::binary);
   finfout.seekg(sizeof(rec) * (numRec), ios::beg);
   finfout.read((char*)&rec,sizeof(rec));
   finfout.close();
   
}
//failed function
void writeLine(char fileName[], record &rec, int recNum){
   //create a file out-stream object pointing to a new file
	fstream fout(fileName, ios::out );
   fout.seekg(sizeof(rec) * recNum, ios::beg);
   fout.write((char*)&rec,sizeof(rec));
   fout.close();
}

int numOfRec(char fileName[], record &rec){
   fstream fin(fileName,ios::in | ios::binary);
   fin.seekg(0,ios::end);
   long lastByte = fin.tellg();
   int n = lastByte / sizeof(rec);
   fin.seekg(0, ios::beg);
   fin.close();
   return n;
}