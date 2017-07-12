#include <iostream>
#include <map>
#include <time.h>
#include <string>
using namespace std;


class Table
{
private:
	string res[11][8]; //total slots for reservations are 11  and every slot is of 1 hour i.e: (11 AM - 10 PM)
	int size;


public:
	Table(){
		for (int i = 0; i < 11; i++){
			for (int j = 0; j < 8; j++){
				res[i][j] = "empty";
			}
			
		}
		size = 8;
	}
	Table(int siz){
		for (int i = 0; i < 11; i++){
			for (int j = 0; j < 8; j++){
				res[i][j] = "empty";
			}

		}
	size = siz;
	}
	int checktable(int tim){
		for (int i = 0; i < size; i++){
			if (res[tim][i] == "empty"){
				return i;
			}

		}
		return -1;
	}
	
	

	int totalfreetables(int tim){
		int freetables=0;
		for (int i = 0; i < size; i++){
			if (res[tim][i] == "empty"){
				freetables++;
			}

		}
		return freetables;

	}
	int reserveslot(int tim,int tab,string name){
		res[tim][tab] = name;
		return 0;
	}



};

int unittest(){ //unit test
  Table stable(2);
  int timeslot = 0;
  int cta;
  string name ="zxc";
  cta = stable.checktable(timeslot);
  if (cta != -1){ 
						stable.reserveslot(timeslot, cta, name);
						 cta = stable.checktable(timeslot);
						 if(cta != -1){
						   stable.reserveslot(timeslot, cta, name);
						   cta = stable.checktable(timeslot);
						   if(cta !=-1){
						   
						     return -1;
						   
						   }
						 }else{
						   return -1;
						 }
	}else{
	  return -1;
	}
  return 1;
}

int main(){
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);
	Table stable(2);
	Table mtable(8);
	Table ltable(3);
	Table xltable(1);
	int hour = aTime->tm_hour;
	int ctime =hour;
	int people;
	int timeslot;
	int restype;
	int cta;
	int ftab;
	string name;
	cout << "----Welcome to XYZ hotel---- \n";

	while (true){
		if (ctime >= 11 && ctime <= 22){

			cout << "1 - Make a Reservation for large parties  \n";
			cout << "2 - Make a Reservation   \n";
			cout << "3 - Run Unit Test   \n ";
			cin >> restype;
			if (restype == 2){
				cout << "\n Number of people : ";
				cin >> people;//Assuming max number of people = 12
				cout << "\n Enter Timeslot i.e 1100 hours to 2200 : ";
				cin >> timeslot;
				timeslot = timeslot / 1000;
				cout << "\n Checking Freeslots for you...please wait \n";
				if (people <= 2){  // priority S > m > l >xl
					cta = stable.checktable(timeslot);
					
					if (cta != -1){ //alotting s tables
						cout << " Enter Your Name : ";
						cin.ignore(); 
						getline (cin, name);
						stable.reserveslot(timeslot, cta, name);
					}
					else{
						cta = mtable.checktable(timeslot);
						if (cta != -1){ //alotting m tables
							cout << " Enter Your Name : ";
						cin.ignore(); 
							getline(cin, name);
							mtable.reserveslot(timeslot, cta, name);
						}
						else{ //alotting l tables
							cta = ltable.checktable(timeslot);
							if (cta != -1){
								cout << " Enter Your Name : ";
						cin.ignore(); 
								getline(cin, name);
								ltable.reserveslot(timeslot, cta, name);
							}
						}
					}
				}
				else if (people <= 4){  // priority m > s > l >xl
					cta = mtable.checktable(timeslot);
					if (cta != -1){ //alotting m tables
						cout << " Enter Your Name : ";
						cin.ignore(); 
						getline(cin, name);
						mtable.reserveslot(timeslot, cta, name);
					}
					else{ //alotting s tables
						ftab = stable.totalfreetables(timeslot);
						if (ftab >=2){
							cta = stable.checktable(timeslot);
							if (cta != -1){
								cout << " Enter Your Name : ";
						cin.ignore(); 
								getline(cin, name);
								stable.reserveslot(timeslot, cta, name);
								cta = stable.checktable(timeslot);
								stable.reserveslot(timeslot, cta, name);
							}

						}

				else{
					cta = ltable.checktable(timeslot);
					if (cta != -1){ //alotting l tables
						cout << " Enter Your Name : ";
						cin.ignore(); 
						getline(cin, name);
						ltable.reserveslot(timeslot, cta, name);
					}
					else{ //alotting xl tables
						cta = xltable.checktable(timeslot);
						if (cta != -1){
							cout << " Enter Your Name : ";
						cin.ignore(); 
							getline(cin, name);
							xltable.reserveslot(timeslot, cta, name);
						}
					}
				}
					}
				}
				else if (people <= 6){ // priority > l >xl > m
					cta = ltable.checktable(timeslot);
					if (cta != -1){ //alotting l table
						cout << " Enter Your Name : ";
						cin.ignore(); 
						getline(cin, name);
						ltable.reserveslot(timeslot, cta, name);
					}
					else
					{
						cta = xltable.checktable(timeslot);
					if (cta != -1){ //alotting xl table
						cout << " Enter Your Name : ";
						cin.ignore(); 
						getline(cin, name);
						xltable.reserveslot(timeslot, cta, name);
					}
					else{ //alotting m tables
						ftab = mtable.totalfreetables(timeslot);
						if (ftab >= 2){
							cta = mtable.checktable(timeslot);
							if (cta != -1){
								cout << " Enter Your Name : ";
						cin.ignore(); 
								getline(cin, name);
								mtable.reserveslot(timeslot, cta, name);
								cta = stable.checktable(timeslot);
								mtable.reserveslot(timeslot, cta, name);
							}

						}
					}
					}
				}
				else if (people <= 12){ // priority  xl >l > m
					cta = xltable.checktable(timeslot);
					if (cta != -1){//alotting xl tables
						cout << " Enter Your Name : ";
						cin.ignore(); 
						getline(cin, name);
						xltable.reserveslot(timeslot, cta, name);
					}
					else{
						ftab = ltable.totalfreetables(timeslot);
						if (ftab >= 2){
							cta = ltable.checktable(timeslot);
							if (cta != -1){
								cout << " Enter Your Name : ";
					    	cin.ignore(); 
								getline(cin, name);
								ltable.reserveslot(timeslot, cta, name);
								cta = stable.checktable(timeslot);
								ltable.reserveslot(timeslot, cta, name);
							}

						}
					}
				}

			}else if(restype==1){ //alocating for parties
			  cout << "\n Enter Timeslot i.e 1100 hours to 2200 : ";
				cin >> timeslot;
				timeslot = timeslot / 1000;
			   // priority  xl >l > m
					cta = xltable.checktable(timeslot);
					if (cta != -1){//alotting xl tables
						cout << " Enter Your Name : ";
						cin.ignore(); 
						getline(cin, name);
						xltable.reserveslot(timeslot, cta, name);
					}
					else{
						ftab = ltable.totalfreetables(timeslot);
						if (ftab >= 2){
							cta = ltable.checktable(timeslot);
							if (cta != -1){
								cout << " Enter Your Name : ";
					    	cin.ignore(); 
								getline(cin, name);
								ltable.reserveslot(timeslot, cta, name);
								cta = stable.checktable(timeslot);
								ltable.reserveslot(timeslot, cta, name);
							}

						}
					}
			}else if(restype==3){
			  
			  if(unittest()==1){
			    cout <<"Unit Test Working 100%";//check lin 66 for unit test
			    break;
			  }
			}



		}else{
		  cout <<"Hotel Closed";
		  break;
		}
	}


	cin >> timeslot;
	return 0;

	
}