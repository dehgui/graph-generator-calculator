#include "arests.hpp"

node arests::getBegin()
{
	return this->Begin;
}

node arests::getEnd()
{
	return this->End;
}

float arests::getPrice()
{
	return this->Price;
}


void arests::setBegin(node Begin)
{
	this->Begin = Begin;
}

void arests::setEnd(node End)
{
	this->End = End;
}

void arests::setPrice(float price)
{
	this->Price = price;
}
