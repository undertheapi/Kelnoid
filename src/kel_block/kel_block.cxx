/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Object File for the Kel_Block Class.
*/

#include "kel_block.hxx"

Kel_Block::Kel_Block(short _type, int _points, float _x, float _y) {
	Kel_Block::type = _type;
	Kel_Block::points = _points;
	Kel_Block::xPosition = _x;
	Kel_Block::yPosition = _y;
}

short Kel_Block::getType() {
	return Kel_Block::type;
}
		
int Kel_Block::getPoints() {
	return Kel_Block::points;
}
		
float Kel_Block::getXPosition() {
	return Kel_Block::xPosition;
}
		
float Kel_Block::getYPosition() {
	return Kel_Block::yPosition;
}
