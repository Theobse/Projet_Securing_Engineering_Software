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
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
string svec1[] = {"a.-","b-...","c-.-.","d-..","e.","f..-.","g--.","h....","i..","j.---","k-.- ","l.-..","m--","n-.","o---","p.--.","q--.-","r.-. ","s...","t-","u..-","v...-","w.--","x-..-","y-.--","z--.."," ", "?..--..",
								"/-..-.","..-.-.-",",--..--","1.----","2..---","3...--","4....-","5.....","6-....","7--...","8---..","9----.","0-----","=-...-","--....-","@.--.-.","'.----."};
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
	int count;
	public:
		MorseCodeMessage(string);
		MorseCodeMessage();
		void Translate();
		void print();
		int MorseCodeToLights();
};

MorseCodeMessage::MorseCodeMessage(string ms) : Message(ms){
	count = 0;
	Translate();
}
MorseCodeMessage::MorseCodeMessage() : Message(){
	count = 0;
	Translate();
}
void MorseCodeMessage::Translate(){
	//search for the corresponding letter, letter by letter
	for(unsigned int x = 0; x < this->message1.length(); ++x){
			for(unsigned int z = 0; z < 45; ++z){
				if ((tolower(message1.c_str()[x])) == svec1[z][0]){
					for(unsigned int y = 1; y < svec1[z].length(); ++y){
						message2[count] = svec1[z][y];
						count++;
					}
					message2[count] = ' ';
					count++;
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
	if(MorseCodeToLights() == 1){
		cout << "\nFinish!!";
	}
	cout << endl;
}
int MorseCodeMessage::MorseCodeToLights(){
		int fd;		// for the file descriptor of the special file we need to open.
		unsigned long *BasePtr;		// base pointer, for the beginning of the memory page (mmap)
		unsigned long *PBDR, *PBDDR;	// pointers for port B DR/DDR

	    fd = open("/dev/mem", O_RDWR|O_SYNC);	// open the special file /dem/mem
		if(fd == -1){
			printf("\n error\n");
		    return(-1);  // failed open
		}

		// We need to map Address 0x80840000 (beginning of a memory page)
		// An entire memory page is mapped. We need to point to the beginning of the page.
		BasePtr = (unsigned long*)mmap(NULL,getpagesize(),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0x80840000);
	    if(BasePtr == MAP_FAILED){
	    	printf("\n Unable to map memory space \n");
	    	return(-2);
	    }  // failed mmap

		// To access other registers in the page, we need to offset the base pointer to reach the
		// corresponding addresses. Those can be found in the board's manual.
		PBDR = BasePtr + 1;		// Address of port B DR is 0x80840004
	    PBDDR = BasePtr + 5;	// Address of port B DDR is 0x80840014

	for(int i = 0; i < count; i++) {
		if(message2[i] == '.'){
			*PBDDR |= 0x20;			// configures port B7 as output (Red LED)

			*PBDR |= 0x20;	
			usleep(600000);	
			*PBDR &= ~0x20;	
			usleep(250000);	
		}
		else if(message2[i] == '-'){
			*PBDDR |= 0x40;			// configures port B7 as output (Yellow LED)

			 *PBDR |= 0x40;	.
			 usleep(600000);	
			 *PBDR &= ~0x40;
			 usleep(250000);	
		}
		else if(message2[i] == ' '){
			*PBDDR |= 0x80;			
			*PBDDR |= 0x40;
			*PBDDR |= 0x20;

			*PBDR &= ~0x80;
			*PBDR &= ~0x40;
			*PBDR &= ~0x20;
			usleep(500000);
		}
	}
	*PBDDR |= 0x80;			// configures port B7 as output (Green LED)

	*PBDR |= 0x80;	        // ON: write a 1 to port B0. Mask all other bits.
	sleep(3);	   
	*PBDR &= ~0x80;

	return 1;
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
