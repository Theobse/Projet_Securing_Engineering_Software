// Lab7_strings.cpp
// This program shows some simple string examples, and asks for simple tasks.
// Reference: Lippman, section 3.2

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab7_strings.cpp -o Lab7_strings -std=c++11
//      or:  g++ Lab7_strings.cpp -o Lab7_strings -std=c++0x
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <string>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	/*string s1, s2("Hello"), s3 = "World";
	cout << "\nEnter a word:" << endl;
	cin >> s1;
	cin.ignore();	// to consume the '\n' character. Otherwise, you may get issues with
	cin.ignore();		// the getline() below. Try commenting this out. Any issues?

	string s4(s1);

	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;

	s1 = s2 + s3;
	cout << s1 << endl;*/

// ***********************************************************************
// Try all the operations in Table 3.2 using the strings above and
// using new strings that you may declare.
// Some of those operations have already been used, but write your
// own examples.
// ***********************************************************************
	//----------------------------operator 1---------------------------------------//
	string str1 = "Example of '<<' operator.\n\n";
	cout << "Case 1: '<<' operation\n";
	cout << str1;
	//----------------------------operator 2---------------------------------------//
	string str2;
	cout << "Please enter your last name.\n";
	cin >> str2;
	cin.ignore();	// to consume the '\n' character.
	cout << "Your last name is: " << str2 << endl;
	//----------------------------operator 3---------------------------------------//
	string str3;
	cout << "\nPlease enter your favorite movie.\n";
	getline(cin, str3);
	cout << "Your favorite movie is: " << str3 << "\n\n";
	//----------------------------operator 4---------------------------------------//
	string str4;
	if(str4.empty()){
		cout << "This string is empty.\n\n";
	}
	else{
		cout << "It's not empty\n\n";
	}
	//----------------------------operator 5---------------------------------------//
	string str5 = "Hello, nice to meet you!";
	cout << "\"" << str5 << "\"" << " has " << str5.size() << " characters.\n\n";
	//----------------------------operator 6---------------------------------------//
	int index = 4;
	cout << "The character at index 4 is " << str5[index] << ".\n\n";
	//----------------------------operator 7---------------------------------------//
	string str6 = "Disney", str7 = "World";
	cout << "Let's go to " << str6 + str7 << "!!\n\n";
	//----------------------------operator 8---------------------------------------//
	string str8 = "Hate", str9 = "Love";
	str8 = str9;
	cout << str8 << "!\n\n";

	//----------------------------operator 9---------------------------------------//
	string str10 = "love";
	if(str10 == str9){
		cout << str10 << " and " << str9 << " is the same!\n\n";
	}
	else{
		cout << str10 << " and " << str9 << " is not the same!\n\n";
	}
	//----------------------------operator 10---------------------------------------//
	string str11 = "Love";
	if(str11 != str9){
		cout << str11 << " and " << str9 << " is not the same!\n\n";
	}
	else{
		cout << str11 << " and " << str9 << " is the same!\n\n";
	}
	//----------------------------operator 11---------------------------------------//
	string str12 = "abc", str13 = "bcd";
	if(str12 > str13){
		cout << str12 << " comes first!!\n\n";
	}
	else{
		cout << str13 << " comes first!!\n\n";
	}
	//----------------------------operator 12---------------------------------------//
	string str14 = "rat", str15 = "bat";
	if(str14 <= str15){
		cout << str14  << " is less than or equal to " << str15 << ".\n\n";
	}
	else{
		cout << str15 << " is less than or equal to " << str14 << ".\n\n";
	}

// -----------------------------------------------------------------------
	string line;
	cout << "\nEnter some text:" << endl;
	getline(cin, line);
	cout << line << endl;

	cout << "\nEnter some text, finish it with an &:" << endl;
	getline(cin, line, '&');	// the delimiter can be any character
	cout << line << endl;

// ***********************************************************************
// Use a "Range for" (Lippman, page 93) and operations in table 3.3 to:
// 1) change the case of the letters in your input line above (upper to
//    lowercase and vice-versa).
// 2) Replace any whitespace with a dot ('.').
// Print the converted text.
// ***********************************************************************
		cout<< "Changing to upper case" << endl;
		for (auto &c : line){
			c = toupper(c);
		}
		cout<<line<<endl;
		cout<<"Changing to lower case"<<endl;
		for(auto &c:line){
			c= tolower(c);
		}
		cout<<line<<endl;
		cout<<"Changing whitespace to a dot\n";
		for(auto &c:line)
		{
			if(isspace(c)){
				c = '.';
			}
		}
		cout<<line<<endl;


	return 0;
}
