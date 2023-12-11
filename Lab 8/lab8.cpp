//============================================================================
// Name        : lab8.cpp
// Author      : Benjarit Hotrabhavananda
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <ctype.h>
#include <cstdlib>
#include <typeinfo>
using namespace std;

class Message{
	protected:
		string message1;
		char *message2;
	public:
		Message(string);
		Message();
		virtual ~Message();
		virtual void print();
};
Message::Message(string text){
	this->message1 = text;
	message2 = new char[(message1.length()*4)];
}
Message::Message(){
	cout << "Enter the massage: ";
	getline(cin, this->message1);
	message2 = new char[(message1.length()*4)];
}
Message::~Message(){
	delete[] message2;
}
void Message::print(){
	cout << message1 << endl;
}
//===========================================================================//
class MorseCodeMessage: public Message{
	private:
		vector<string> svec1 = {"a.-","b-...","c-.-.","d-..","e.","f..-.","g--.","h....","i..","j.---","k-.- ","l.-..","m--","n-.","o---","p.--.","q--.-","r.-. ","s...","t-","u..-","v...-","w.--","x-..-","y-.--","z--..","  ", "?..--..",
								"/-..-.","..-.-.-",",--..--","1.----","2..---","3...--","4....-","5.....","6-....","7--...","8---..","9----.","0-----","=-...-","--....-","@.--.-.","'.----."};
	int count = 0;
	public:
		MorseCodeMessage(string);
		MorseCodeMessage();
		void Translate();
		void print();
};

MorseCodeMessage::MorseCodeMessage(string ms) : Message(ms){
	Translate();
}
MorseCodeMessage::MorseCodeMessage() : Message(){
	Translate();
}
void MorseCodeMessage::Translate(){
	//search for the corresponding letter, letter by letter
	for(unsigned int x = 0; x < this->message1.length(); ++x){
			for(unsigned int z = 0; z < svec1.size(); ++z){
				if ((tolower(message1.c_str()[x])) == svec1[z][0]){
					for(unsigned int y = 1; y < svec1[z].length(); ++y){
						message2[count] = svec1[z][y];
						count++;
					}
					break;
				}
			}
	}
}
void MorseCodeMessage::print(){
	cout << message1 << endl;
	for(int i = 0; i < count; i++) {
		cout << message2[i];
	}
	cout << endl;
}
//----------------------------------------------//
class MessageStack{
	private:
		Message *stack[50];
		int tos;
	public:
		MessageStack(Message*);
		~MessageStack();
		void push(Message*);
		bool pop();
		void printStrack();
};
MessageStack::MessageStack(Message* element){
	this->tos = 0;
	push(element);
}
MessageStack::~MessageStack(){
	for(int i = 0; i < this->tos; i++) {
		delete stack[i];
	}
}
void MessageStack::push(Message* element){
	if(tos == 50) {
		cout << "Stack is already full..." << endl;
		return;
	}
	stack[tos] = element;
	this->tos++;
}
bool MessageStack::pop(){
	if(stack == NULL){
		cout << "Stack is empty.." << endl;
		return 0;
	}
	delete stack[this->tos];
	this->tos--;
	return 1;
}
void MessageStack::printStrack(){
	for(int x = 0; x < this->tos; ++x){
			stack[x]->print();
	}
}
int main(){
	MessageStack mstack(new MorseCodeMessage);
	//mstack.push(new MorseCodeMessage);
	mstack.printStrack();
	return 0;
}