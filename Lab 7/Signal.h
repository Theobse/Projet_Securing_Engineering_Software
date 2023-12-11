/*
 * Signal.h
 *
 *  Created on: Mar 13, 2017
 *      Author: Bens-Acer
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

class Signal {
private:
	int length;
	double max;
	double average;
	void find_max();
public:
	Signal();
	Signal(int);
	Signal(string);
	~Signal();
	void operator+(double);
	void operator*(double);
	void statistics();
	void center();
	void normalize();
	void sig_info();
	void save_file(string);
	int getlength(){ return this->length;}
	void setlength(int length){ this->length = length;}
	double getMax(){ return this->max;}
	void setMax(double max){ this->max = max;}
	void find_average();
	vector<double> samples;
};

