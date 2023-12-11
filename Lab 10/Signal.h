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
class badLength{
private:
	int v1;
	int v2;
public:
	badLength(int a = 0, int b = 0) : v1(a), v2(b){}
	void mesg();
};

inline void badLength::mesg()
{
	cout << "Two data vectors are not the same length";
}
