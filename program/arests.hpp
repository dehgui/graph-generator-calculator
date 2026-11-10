#ifndef ARESTS_HPP
#define ARESTS_HPP

#include "node.hpp"

class arests
{
	private:
		node Begin;
		node End;
		float Price;
	public:
		node getBegin();
		node getEnd();
		float getPrice();

		void setBegin(node);
		void setEnd(node);
		void setPrice(float);
};

#endif
