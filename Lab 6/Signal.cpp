/*
 * Signal.cpp
 *
 *  Created on: Mar 13, 2017
 *      Author: Bens-Acer
 */

#include "Signal.h"

Signal::Signal() {
	//Initializes length, max, average
	this->length = 0;
	this->max = 0;
	this->average = 0;
	int count = 0;
	ifstream myFile;

	//defualt input data file
	myFile.open("Raw_data_01.txt",ios::in);

	if(!myFile.is_open()){
		//if having trouble opening file or file does not exist
		cout << "File does not exist" << endl;
		exit(EXIT_FAILURE);
	}

	myFile >> this->length;
	myFile >> this->max;
	this->average = 0;

	this->samples = new double[length];
	while(!myFile.eof()){
		myFile >> samples[count];
		count++;
	}
	myFile.close();
}
Signal::Signal(int number){
	//Initializes length, max, average
	this->length = 0;
	this->max = 0;
	this->average = 0;
	char name_of_file[20];
	int count = 0;
	//cout << "HEllo" << endl;
	//take in number of file and open that file accordingly
	ifstream myFile;
	sprintf(name_of_file, "Raw_data_%02d.txt", number);
	myFile.open(name_of_file,ios::in);
	//if having trouble opening file or file does not exist
	if(!myFile.is_open()){
		cerr << "File does not exist" << endl;
		exit(EXIT_FAILURE);
	}

	myFile >> this->length;
	myFile >> this->max;
	this->average = 0;

	this->samples = new double[length];
	while(!myFile.eof()){
		myFile >> samples[count];
		count++;
	}
	myFile.close();
}
Signal::Signal(string name){
	//Initializes length, max, average
	this->length = 0;
	this->max = 0;
	this->average = 0;
	int count = 0;
	ifstream myFile;

	//take in name and read that file name
	myFile.open(name.c_str(),ios::in);
	if(!myFile.is_open()){
		cout << "File does not exist" << endl;
		exit(EXIT_FAILURE);
	}

	myFile >> this->length;
	myFile >> this->max;
	this->average = 0;

	this->samples = new double[length];
	while(!myFile.eof()){
		myFile >> samples[count];
		//cout << samples[count] << endl;
		count++;
	}
	//cout << this->samples[4] << endl;
	myFile.close();
}
Signal::~Signal() {
	delete[] samples;
}
void Signal::find_average(){
	double total = 0;
	int counter = 0;
	while(counter < this->length){
		total += this->samples[counter];
		counter++;
	}
	this->average = ((double)total/this->length);
}
void Signal::find_max(){
	int counter = 0;
	double max = 0;
	while(counter < this->length){
		if(this->samples[counter] >= max){
			this->max = this->samples[counter];
		}
		counter++;
	}
}
void Signal::offsetting(double offset){
	int counter = 0;
	//add offset to data signal
	while(counter < this->length){
		samples[counter] = (double)samples[counter]+offset;
		counter++;
	}
	//to update max value and average;
	this->statistics();
}
void Signal::scaling(double offset){
	int counter = 0;
	while(counter < this->length){
		samples[counter] = (double)samples[counter]*offset;
		counter++;
	}
	//to update max value and average;
	this->statistics();
}
void Signal::statistics(){
	//calling find_average() and find_max() methods
	//no arguments needed
	this->find_average();
	this->find_max();
}
void Signal::center(){
	//update average before doing offset
	this->find_average();
	this->offsetting(-(this->average));
}
void Signal::normalize(){
	//update max before doing offset
	this->statistics();
	this->scaling((1.0/this->max));
}
void Signal::sig_info(){
	this->statistics();
	cout << "Number of data: " << this->length << endl;
	cout << "Maximum value: " << this->max << endl;
	cout << "Average value: " << this->average << endl;
}
void Signal::save_file(string name){
	this->statistics();
	ofstream myfile;
	myfile.open (name.c_str(),ios::out);
	myfile << this->length << " "<< this->max << endl;
	for(int count = 0; count < this->length; count++){
		myfile << this->samples[count] << endl;
	}
	myfile.close();
}
