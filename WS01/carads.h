#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

#include <iostream>//*
#include <iomanip>

extern double g_taxrate;
extern double g_discount;

namespace sdds {

	void listArgs(int argc, char* argv[]);

	class Cars {
		char m_brand[10]{};
		char m_model[15]{};
		int m_year{};
		double m_price{};
		char m_used{};
		bool m_flagDiscount{}; // a boolean flag indicating whether or not the car is on promotion discount

	public: 
		Cars() {};
		~Cars() {};
		std::istream& read(std::istream& is);//** type 
		void display(bool reset) const;
		char getStatus() const;//a query that returns if the car is new or used.
	};
}



#endif