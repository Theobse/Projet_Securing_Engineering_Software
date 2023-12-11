// Lab7_vectors.cpp
// This program shows some simple vector examples, and asks for simple tasks.
// Reference: Lippman, section 3.3

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab7_vectors.cpp -o Lab7_vectors -std=c++11
//      or:  g++ Lab7_vectors.cpp -o Lab7_vectors -std=c++0x
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	vector<int> ivec1(5), ivec2;
	vector<double> dvec1{5.1}, dvec2(5,1.5);
	vector<string> svec1 = {"hello", "world"};
	// vector<myClass> myCvec;	// you can have vectors of objects
	// in general: vector<Type> vec;	// vector is a template

	for(int i = 0; i < ivec1.size(); i++)
		cout << ivec1[i] << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:ivec1)	// This is equivalent to the above for loop
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:dvec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:dvec2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	for(auto i:svec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;

	cout << "Original size: " << ivec2.size() << endl;
	ivec2.push_back(50);
	cout << "New size: " << ivec2.size() << "\nAdded element: " << ivec2[0] << endl;
	cout << "\n------------------------------------------------------------------" << endl;

// ***********************************************************************
// Try all the ways to initializa a vector shown in Table 3.4. Use the
// vectors above and/or declare new vectors.
// Some of those operations have already been used, but write your
// own examples.

	vector<int> v1{1,2,3};
	vector<int> v2(v1);
	vector<int> v3 = v1;
	vector<int> v4(3,0);
	vector<int> v5(3);
	vector<int> v6{3,4,5};
	vector<int> v7 = {6,7,8};
	for(auto i:v1)
			cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v2)
			cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v3)
			cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v4)
			cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v5)
			cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v6)
			cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	for(auto i:v7)
			cout << i << endl;
		cout << "\n------------------------------------------------------------------" << endl;
// Do exercises 3.14 and 3.15 from Lippman (page 102)
	vector<int> v8;
	int f,g,j,k,i;
	cin >> f;
	cin >> g;
	cin >> j;
	cin >> k;
	cin >> i;
	v8.push_back(f);
	v8.push_back(g);
	v8.push_back(j);
	v8.push_back(k);
	v8.push_back(i);
	cout << endl;
	for(auto x:v8)
		cout << x << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	vector<string> v9;
	string a,b,c,d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	v9.push_back(a);
	v9.push_back(b);
	v9.push_back(c);
	v9.push_back(d);
	cout << endl;
	for(auto y:v9)
		cout << y << endl;
// Try all the vector operations shown in table 3.5. Use the vectors above
// or define new ones. Try different types.
// ***********************************************************************

	vector<string> v10;
	vector<int> v11{1,2};
	vector<string> v12{"sist","Bro"};
	if(v11.empty()){
		cout << "vector v11 is empty.\n\n";
	}
	else{
		cout << "vector v11 is not empty.\n\n";
	}
	cout << "The size of vector v10 is " << v10.size() << ".\n\n";

	v10.push_back("Hey!");
	cout << v10[0] << "\n\n" << endl;

	v10 = v12;
	cout << v10[0] << " " << v10[1] << "\n\n" << endl;

	v10 = {"lala", "land"};
	cout << v10[0] << " " << v10[1] << "\n\n" << endl;

	if(v10 == v12){
		cout << "v10 and v12 are equal.\n\n";
	}
	else{
		cout << "v10 and v12 are not equal.\n\n";
	}

	return 0;
}
