//============================================================================
// Name        : Lab6.cpp
// Author      : Benjarit Hotrabhavananda
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Signal.h"

Signal operator+(Signal &lhs, Signal &rhs)
{
	cout << "operator +" << endl;
	Signal sum;
	if(lhs.getlength() == rhs.getlength()){
		for(int i = 0; i < lhs.getlength(); i++){
			sum.samples.push_back(0);
		}
		for(int i = 0; i < lhs.getlength(); i++){
			sum.samples[i] = lhs.samples[i] + rhs.samples[i];
		}
		sum.setlength(rhs.getlength());
		sum.statistics();
		int counter = 0;
		double max = 0;
		while(counter < lhs.getlength()){
			if(lhs.samples[counter] >= max){
				max = lhs.samples[counter];
			}
			counter++;
		}
		counter = 0;
		while(counter < rhs.getlength()){
			if(rhs.samples[counter] >= max){
				max = rhs.samples[counter];
			}
			counter++;
		}
			sum.setMax(max);
			sum.find_average();
	}
	else{
		throw badLength(lhs.getlength(),rhs.getlength());
	}
	return sum;
}

int main(int argc, char *argv[]) {
	//user will be prompt with menu and make a choice
	int choice = 0;
	//Creating signal pointer so we can use later when we create object
	Signal *signal1;
	//check to see if user has pass in command line agruments
	if(argc >= 2){
		//if command is -n then we will take in number
		//there is also throw statement in this if command -n does not have number following it
		if(strcmp(argv[1],"-n") == 0){
			try{
				//if user does not give number of file then command is incomplete
				if(argv[2] == NULL){
					throw NULL;
				}
			//make pointer point to new signal object
			signal1 = new Signal(atoi(argv[2]));
			}catch(...){
				cerr << "Incomplete command.";
				return 0;
			}
		}
		//if command is -n then we will take in number
		//there is also throw statement in this if command -f does not have string following it
		else if(strcmp(argv[1],"-f") == 0){
			char name_of_file[20];
			try{
				//if user does not give name then command is incomplete
				if(argv[2] == NULL){
					throw NULL;
				}
			//append that name with .txt
			sprintf(name_of_file, "%s.txt", argv[2]);
			//make pointer point to new signal object

			try{
			signal1 = new Signal(name_of_file);
			}catch(const char * s){
				cout << s << endl;
				return 0;
			}
			}catch(...){ // catch all errors
				cerr << "Incomplete command.";
				return 0;
			}
		}
	}
	else{
		//call default constructor if no command line is given
		//make pointer point to new signal object
		signal1 = new Signal();
	}
	//while user does not want to exit, keep running
	//appropriate actions are taken based on user input
	while(choice != 7){
	try{
		cout << "1.Offset data. \n2.Scale data. \n3.Center data.\n4.Normalize data. \n"
				"5.See signal data. \n6.Save data to File. \n7.Exit\n";
		cout << "Enter choice above: ";
		cin >> choice;
		//choice can not be more than 7 and less than 1
		if(choice > 7 || choice < 1){
			throw choice;
		}
		switch(choice){
		case 1:
			double offset;
			cout << "\nEnter offset value: ";
			cin >> offset;
			try{
			*(signal1)+offset;
			}catch(const char* s){
				cout << s << endl;
				return 0;
			}
			cout << "\nOffset Done.....\n\n";
			break;
		case 2:
			double scale;
			cout << "\nEnter scaling factor: ";
			cin >> scale;
			try{
				*(signal1)*scale;
			}catch(const int s){
				cout << "Invalid scaling number: " <<  s << endl;
				return 0;
			}

			cout << "\nScaling Done.....\n\n";
			break;
		case 3:
			cout << "\nCentering signal data done....\n\n";
			signal1->center();
			break;
		case 4:
			cout << "\nNormalizing signal data done.... \n\n";
			signal1->normalize();
			break;
		case 5:
			cout << endl;
			signal1->sig_info();
			cout << endl;
			break;
		case 6:
			string name;
			cout << "Please enter name of file to be created: ";
			cin >> name;
			signal1->save_file(name);
			break;
		}
	//if user give choice number out of range then there is an error
	}catch(const int s){
		cout << "\nInvalid choice: " << s   << endl << endl;
		return 0;
	}
	}
	cout << "\nAdding two signals data together...\n"<< endl;
	Signal s1(1), s2(1),s3;
	try{
		s3 = s1+s2;
	//catch an object
	}catch(badLength & bl){
		bl.mesg();
		return 0;
	}
	for(int i = 0; i < s3.getlength(); i++){
		cout << s3.samples[i] << endl;
	}
	cout << "The maximum number among s1 and s2 is " << s3.getMax() << ".\n";

	return 0;
}
