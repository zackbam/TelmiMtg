#include "Fruit.h"

 

Fruit::Fruit()
{
	//set values for default constructor
	setType("null");
	setColour(Scalar(0,0,0));

}

Fruit::Fruit(string name){

	setType(name);
	
	if(name=="bow"){

		//TODO: use "calibration mode" to find HSV min
		//and HSV max values

		setHSVmin(Scalar(96,179,78));
		setHSVmax(Scalar(121,256,230));

		//BGR value for Blue:
		setColour(Scalar(255,0,0));

	}
	if(name=="violin"){

		//TODO: use "calibration mode" to find HSV min
		//and HSV max values

		setHSVmin(Scalar(19,144,117));
		setHSVmax(Scalar(44,252,256));

		//BGR value for Yellow:
		setColour(Scalar(0,255,255));

	}
}

Fruit::~Fruit(void)
{
}

int Fruit::getXPos(){

	return Fruit::xPos;

}

void Fruit::setXPos(int x){

	Fruit::xPos = x;

}

int Fruit::getYPos(){

	return Fruit::yPos;

}

void Fruit::setYPos(int y){

	Fruit::yPos = y;

}

Scalar Fruit::getHSVmin(){

	return Fruit::HSVmin;

}
Scalar Fruit::getHSVmax(){

	return Fruit::HSVmax;
}

void Fruit::setHSVmin(Scalar min){

	Fruit::HSVmin = min;
}


void Fruit::setHSVmax(Scalar max){

	Fruit::HSVmax = max;
}