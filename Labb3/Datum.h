// Labb3, Datum.h – klassdefinition

#ifndef DATUM_H
#define DATUM_H

#include <array>
#include <iostream>

class Datum
{
	friend std::ostream& operator<<(std::ostream&, const Datum&);

	unsigned int year;
	unsigned int month;
	unsigned int day;
	// Deklaration av statisk privat medlem, "ant_dagar per månad"
	static const std::array< unsigned int, 13 > ANT_DAGAR_PER_MAANAD;
	//void step_one_day(); // Öka datum med en dag

public:
	// Konstruktor med parametrar
	Datum(int, int, int);

	//Standardkonstruktor
	Datum();

	// set year, month, day
	void set_date(int, int, int);

	// += operator
	const Datum operator+=(int);

	// + operator
	const Datum operator+(int);

	friend Datum operator+(int add, Datum& date);

	//++operator PREFIX
	const Datum operator++();

	//++operator POSTFIX
	const Datum operator++(int);

	

private:
	//OBS. funktionen "step_one_day()" bör vara PRIVATE
	void step_one_day(); // Öka datum med en dag

	static bool is_skott_aar(int); // Är det skottår?
	bool end_of_month(int) const; // Är dagen den sista i månaden?
	// < operator
	friend bool operator<(const Datum& left, const Datum& right);
	// > operator
	friend bool operator>(const Datum& left, const Datum& right);
};

inline bool operator==(const Datum& left, const Datum& right) {
	return !(left < right) && !(right < left);
}

inline bool operator!=(const Datum& left, const Datum& right) {
	return !(left == right);
}

inline bool operator>=(const Datum& left, const Datum& right) {
	return !(left < right);
}

inline bool operator<=(const Datum& left, const Datum& right) {
	return !(right < left);
}



#endif