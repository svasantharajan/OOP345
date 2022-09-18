#include "carads.h"
#include <iostream>
#include <iomanip>
using namespace std;//**

double g_taxrate=0;//*
double g_discount=0;

namespace sdds {

	void listArgs(int argc, char* argv[]) {

		cout << "Command Line:" <<endl;
		cout << "--------------------------" << endl;
		for (int i = 0; i < argc; i++) {
			cout << i+1<< ": " << argv[i] <<endl;
		}
		cout << "--------------------------" << endl;
	}

	std::istream& Cars::read(std::istream& is) {//*

		char promotion;
		if (is) {
			is >> m_used;
			is.ignore();
			is.getline(m_brand, 9, ',');
			is.getline(m_model, 14, ',');
			is >> m_year;
			is.ignore();
			is >> m_price;
			is.ignore();
			is >> promotion;
			if (promotion == 'Y') {
				m_flagDiscount = true;
			}
			else {
				m_flagDiscount = false;
			}
			is.ignore();
		}
		return is;
	}

	void Cars::display(bool reset) const { 
		//currentCar.display(0);
		static int COUNTER = 0;

		if (reset == 1) {
			COUNTER = 0;
		}
		COUNTER++;//*À§Ä¡

		for (int i = 0; i < COUNTER; i++) {

			if (EOF) {
				cout << left << setw(2) << i + 1 << ". No Car" << endl;
			}
			else {
				cout << left << setw(2) << i + 1 << ". " << setw(10) << m_brand << "| " << setw(15) << m_model << "| " << setw(4) << m_year << " |" << setw(12) << (1 + g_taxrate) * m_price << setw(12) << (1 - g_discount) * m_price << endl;
			}
		}

	}

	char Cars::getStatus() const {
		return m_used;
	}


	//part2
	//read function modify
	//char* m_brand{ nullptr };

	//Cars() = default;
	//cars()(const Cars& other) {
	//	this = other;
	//}
	//Cars& operator=(const Cars& other) {
	//	if....(...) {
	//		delete[] = m_brand;
	//		m_brand = nullptr;
	//		m_used = other.used;
	//		....
	//			strcpy(m_model, other.model);
	//		m_brand = new char[strlen(other.m_brand)...];
	//		strcpy(m_brand, other.brand);
	//	}
	//	return ...;

	//	~Cars() {
	//		delete[] m_brand;
	//	}
	//	std::istream& operator >>(std::istream& is, Cars& car) {
	//		car.read(is);
	//		return is;
	//	}

}







