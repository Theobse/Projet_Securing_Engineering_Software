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
using namespace std;

class Signal {
private:
	int length;
	double max;
	double average;
	double *samples;
	void find_average();
	void find_max();
public:
	Signal();
	Signal(int);
	Signal(string);
	~Signal();
	void offsetting(double);
	void scaling(double);
	void statistics();
	void center();
	void normalize();
	void sig_info();
	void save_file(string);
};

