#ifndef PATHS_HPP
#define PATHS_HPP

#include "arests.hpp"

class path
{
	private:
		vector<arests> direction;
		float total_price;
		bool completed;
	public:
		vector<arests> getDirection();
		float getTotal_price();
		bool iscompleted();
		
		void setDirection(arests);
		void setTotal_price(float);
		void setCondition(bool);
};

#endif
