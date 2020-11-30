// Martin Jars�ter
// Labb3, Datum.cpp � definitioner av icke-triviala medlemsfunktioner

#include <iostream>
#include <string>
#include "Datum.h"

// Initialisera statisk medlem
// (f�rsta elementet anv�nds inte i denna l�sning!)
const std::array< unsigned int, 13 > Datum::ANT_DAGAR_PER_MAANAD = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };



// Konstruktor
Datum::Datum(int year, int month, int day)
{
	set_date(year, month, day);
}

Datum::Datum():day(1), month(1),year(2000){}

void Datum::set_date(int yy, int mm, int dd)
{
	// Gl�m inte att kontrollera inmatade v�rden, annars "exception"
	if (!year >= 2000 && !year <= 2100)
		throw std::invalid_argument("�ret m�ste vara mellan >= 2000 och <= 2100");
	if (!month >= 1 && !month <= 12) 
		throw std::invalid_argument("M�naden m�ste vara >= 1 och <= 12");
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if (!day >= 1 && !day <= 31)
			throw std::invalid_argument("Dagen st�mmer inte med �r och m�nad");
	if(month == 4 || month == 6 || month == 9 || month == 11)
		if (!day >= 1 && !day <= 30)
			throw std::invalid_argument("Dagen st�mmer inte med �r och m�nad");
	if (month == 2)
		if (is_skott_aar(year)){
			if (!day >= 1 && !day <= 29)
				throw std::invalid_argument("Dagen st�mmer inte med �r och m�nad");
		}else
			if(!day >= 1 && !day <= 28)
				throw std::invalid_argument("Dagen st�mmer inte med �r och m�nad");

	year = yy;
	month = mm;
	day = dd;
}

// Denna medlemsfunktion �r t�nkt att l�gga till 1 dag till befintligt datum.
// Om sista dagen i m�naden, s� byt m�nad.
//     Om skott�r, s� ta h�nsyn till att februari(m�nad 2) har 29 dagar.
// Om sista dagen p� �ret, s� byt �r.
void Datum::step_one_day()
{
	// Dagen �r inte sista dagen i m�naden!
	if (!end_of_month(day))
		++day;
	else
		if (month < 12)
		{
			++month;
			day = 1;
		}
		else
		{
			++year;
			month = 1;
			day = 1;
		}
}

// Returnera true om yy(year) �r skott�r!
bool Datum::is_skott_aar(int yy)
{
	if (yy % 400 == 0 ||
		(yy % 100 != 0 && yy % 4 == 0))
		return true;
	else
		return false;
}

// �r det sista dagen (dd) i m�naden?
bool Datum::end_of_month(int dd) const
{
	if (month == 2 && is_skott_aar(year))
		return dd == 29;
	else
		return dd == ANT_DAGAR_PER_MAANAD[month];
}

// operator<<
std::ostream& operator<<(std::ostream& output, const Datum& d)
{
	// OBS. Gl�m inte att modifiera vad som skrivs ut!
	output << d.year << '-' << d.month << '-' << d.day;
	return output;

}

const Datum Datum::operator++() {
	step_one_day;
	return *this;
}

const Datum Datum::operator++(int) {
	Datum temp(*this);
	step_one_day();
	return temp;
}


const Datum Datum::operator+=(int add) {
	
	for (int i = 0; i < add; i++)
		step_one_day();

	return *this;
}

const Datum Datum::operator+(int add) {
	Datum temp(*this);
	temp += add;
	return temp;
}

Datum operator+(int add,Datum& date) {
	return date += add;
}

bool operator<(const Datum& left, const Datum& right) {
	if(left.year < right.year)
		return true;
	if(left.month < right.month)
		return true;
	if (left.month < right.month)
		return true;
	else
		return false;
}