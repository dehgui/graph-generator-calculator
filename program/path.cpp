#include "path.hpp"

vector<arests> path::getDirection()
{
	return this->direction;
}

float path::getTotal_price()
{
	return this->total_price;
}

bool path::iscompleted()
{
	return this->completed;
}

void path::setDirection(arests new_direction)
{
	this->direction.push_back(new_direction);
}

void path::setTotal_price(float new_price)
{
	this->total_price = new_price;
}

void path::setCondition(bool new_condition)
{
	this->completed = new_condition;
}
