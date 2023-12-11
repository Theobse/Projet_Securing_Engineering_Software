//============================================================================
// Name        : lab10.cpp
// Author      : Benjarit Hotrabhavananda
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class BaseConic {
protected:
	double x;
	double y;
public:
	BaseConic(double,double);
	void move(double shX, double shY);
	virtual double area()=0;
	virtual void resize(double)=0;
	virtual void display()=0;
};
BaseConic::BaseConic(double x,double y) {
	this->x = x;
	this->y = y;
}
void BaseConic::move(double shX, double shY){
	x += shX;
	y += shY;
}
class Ellipse : public BaseConic {
private:
	double a; // semi-major axis
	double b; // semi-minor axis
	double angle; // orientation angle
public:
	Ellipse(double,double,double,double,double);
	double area();
	void display();
	void resize(double);
	void rotate(double);
	double vertices();
};
Ellipse::Ellipse(double a,double b,double angle,double x,double y) : BaseConic(x,y){
	this->a = a; // semi-major axis
	this->b = b; // semi-minor axis
	this->angle = angle;
}
double Ellipse::area(){
	return 3.14159 * a * b;
}
void Ellipse::resize(double a){
	this->a = a;
}
void Ellipse::display(){
	cout << "Center: " << "(" << x << "," << y << ")" << endl;
	cout << "Semi-major axis: " << this->a << endl;
	cout << "Semi-minor axis: " << this->b << endl;
	cout << "Angle: " << this->angle << endl;
	cout << "Vertices: " << vertices() << endl;
	cout << "An area: " << area() << endl;
}
void Ellipse::rotate(double ang){
	this->angle+= ang;
}
double Ellipse::vertices(){
	return this->a + x;
}

class Circle : public BaseConic {
private:
	double radius;
public:
	Circle(double,double,double);
	double area();
	void display();
	void resize(double);
	string checkPoint(double,double);
};
Circle::Circle(double radius ,double x,double y) : BaseConic(x,y){
	this->radius = radius;
}
double Circle::area() {
	return (3.14159*radius*radius);
}
void Circle::resize(double newRadius) {
	radius = newRadius;
}
void Circle::display() {
	cout << "Center: " << "(" << x << "," << y << ")" << endl;
	cout << "Radius: " << radius << endl;
	cout << "An area: " << area() << endl;
}
string Circle::checkPoint(double x,double y) {
	if(x < radius && y < radius){
		return "Inside"; //inside
	}
	else if(x == radius && y == radius){
		return "On the circle"; //on
	}
	else{
		return "Outside"; //outside
	}
}
int main() {
	Ellipse myEllipse(1,2,3,4,5);
	Circle myCircle(6,7,8);
	BaseConic* myBase1,*myBase2;
	/*myBase1 = &myEllipse;
	myBase2 = &myCircle;
	myBase1->display();

	cout << endl;
	myBase1->move(1,1);
	myBase1->resize(3);
	myBase1->display();*/

	myBase2 = &myCircle;
	myBase2->display();

	cout << endl;
	myBase2->resize(3);
	myBase2->move(9,9);
	myBase2->display();

	return 0;
}
