// Martin Jars�ter
// Labb3, Datum

#include <iostream>
#include "Datum.h"

 // Funktion som anv�nds endast f�r test/evaluering av din l�sning, denna �r samma
 // som "min_print_eval()", fast den har fler utskrifter. Vid evaluering, s� skall
 // endast "min_print_eval()" anropas. Bortkommentera d� anropet till denna funktion.
void max_print()
{
  Datum dat1; // defaults to 1 January, 2000
  Datum dat2( 2019, 8, 31 ); // Augusti 31, 2019

  std::cout << "dat1 �r " << dat1 << "\ndat2 �r " << dat2 << std::endl;;
  std::cout << "\ndat1 += 7 �r ";
  std::cout << ( dat1 += 7 ) << std::endl;

  std::cout << "dat1 + 2 dagar blir ";
  std::cout << dat1 + 2 << " (ej tilldelning)" << std::endl;
  std::cout << "2 dagar + dat1 + 2 dagar blir ";
  std::cout << 2 + dat1 + 2; std::cout << " (ej tilldelning)" << std::endl;
  std::cout << std::endl;

  dat2.set_date( 2020, 2, 28 );

  std::cout << "dat2 efter set_date(2020,2,28) �r ";
  std::cout << dat2 << std::endl;
  std::cout << "++dat2 �r " << ++dat2 << " (skott�r 29 dagar) \n";
  std::cout << "++dat2 �r " << ++dat2 << std::endl;

  Datum dat3( 2020, 7, 13 );

  std::cout << "\nPrefix increment operator:\n" <<"dat3 �r " << dat3 << std::endl;
  std::cout << "++dat3 �r " << ++dat3 << std::endl;
  //std::cout << ++dat3 << std::endl;
  std::cout << "dat3 �r " << dat3;
  //std::cout << dat3 << std::endl;

  std::cout << std::endl;
  std::cout << "\nPostfix increment operator:\n" << "dat3 �r " << dat3 << std::endl;
  std::cout << "dat3++ �r " << dat3++ << std::endl;
  //std::cout << dat3++ << std::endl;
  std::cout << "dat3 �r " << dat3 << std::endl;
  //std::cout << dat3 << std::endl;

  std::cout << std::endl;
  std::cout << "dat2: "<< dat2 << std::endl;
  std::cout << "dat3: "<< dat3 << std::endl;

  std::cout << "\ndat2 < dat3?(Sant) ";
  (dat2 < dat3) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  std::cout << "dat3 < dat2?(Falskt) ";
  (dat3 < dat2) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  Datum dat4( 2020, 7, 15 );
  std::cout << "dat3 == dat4?(Sant) ";
  (dat3 == dat4) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  std::cout << "dat3 != dat4?(Falskt) ";
  (dat3 != dat4) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  std::cout << "dat2 == dat3?(Falskt) ";
  (dat2 == dat3) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  std::cout << "dat2 <= dat3?(Sant) ";
  (dat2 <= dat3) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  std::cout << "dat3 <= dat2?(Falskt) ";
  (dat3 <= dat2) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  std::cout << "dat2 > dat3? (Falskt)";
  (dat2 > dat3) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  std::cout << "dat3 > dat2? (Sant)";
  (dat3 > dat2) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

}
/*
// Funktion som endast anv�nds f�r test/evaluering av din l�sning, samma som ovanst�ende fast bantade utskrifter.
void min_print_eval()
{
 // OBS. Ingen kod skall �ndras eller skrivas till i denna funktion.
 // Funktionen anv�nds av VPL vid evaluering av l�sningen.

  Datum dat1; // defaults to 1 January, 2000
  Datum dat2( 2019, 8, 31 ); // Augusti 31, 2019

  //std::cout << "dat1 �r " << dat1 << "\ndat2 �r " << dat2 << std::endl;;
  //std::cout << "\ndat1 += 7 �r ";
  std::cout << ( dat1 += 7 ) << std::endl;

  //std::cout << "dat1 + 2 dagar blir ";
  std::cout << dat1 + 2 << std::endl; //std::cout << " (ej tilldelning)" << std::endl;
  //std::cout << "2 dagar + dat1 + 2 dagar blir ";
  std::cout << 2 + dat1 + 2; //std::cout << " (ej tilldelning)" << std::endl;
  std::cout << std::endl;

  dat2.set_date( 2020, 2, 28 );

  //std::cout << "dat2 efter set_date() �r ";
  std::cout << dat2 << std::endl;
  //std::cout << "++dat2 �r ";
  std::cout << ++dat2 << std::endl;//" (skott�r 29 dagar)\n";
  std::cout << ++dat2 << std::endl;

  Datum dat3( 2020, 7, 13 );

  //std::cout << "\n\nPrefix increment operator:\n" <<"dat3 �r " << dat3 << std::endl;
  //std::cout << "++dat3 �r ";
  std::cout << ++dat3 << std::endl;
  //std::cout << ++dat3 << std::endl;
  //std::cout << "dat3 �r " << dat3;
  std::cout << dat3 << std::endl;

  //std::cout << "\n\nPostfix increment operator:\n" << "dat3 �r " << dat3 << std::endl;
  //std::cout << "dat3++ �r " << dat3++ << std::endl;
  std::cout << dat3++ << std::endl;
  //std::cout << "dat3 �r " << dat3 << std::endl;
  std::cout << dat3 << std::endl;

  //std::cout << "\ndat2: "<< dat2 << std::endl;
  //std::cout << "dat3: "<< dat3 << std::endl;

  //std::cout << "\ndat2 < dat3?(Sant) ";
  (dat2 < dat3) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  //std::cout << "dat3 < dat2?(Falskt) ";
  (dat3 < dat2) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  Datum dat4( 2020, 7, 15 );
  //std::cout << "dat3 == dat4?(Sant) ";
  (dat3 == dat4) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  //std::cout << "dat3 != dat4?(Falskt) ";
  (dat3 != dat4) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  //std::cout << "dat2 == dat3?(Falskt) ";
  (dat2 == dat3) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  //std::cout << "dat2 <= dat3?(Sant) ";
  (dat2 <= dat3) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  //std::cout << "dat3 <= dat2?(Falskt) ";
  (dat3 <= dat2) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  //std::cout << "dat2 > dat3? (Falskt)";
  (dat2 > dat3) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

  //std::cout << "dat3 > dat2? (Sant)";
  (dat3 > dat2) ? (std::cout << "Sant") : (std::cout << "Falskt");
  std::cout << std::endl;

}
*/

void first_print()
{
	std::cout << "Skapa ett datumobjekt med datum \"28 Februari 2020\" \n -> ";
	Datum dat1(2020, 2, 28);
	std::cout << dat1 << std::endl;

	std::cout << "�ka datum med 1 dag (i detta fall skottdag!) \n -> ";
	dat1.step_one_day();
	std::cout << dat1 << std::endl;

	std::cout << "�ka datum med 1 dag (i detta fall ny m�nad!) \n -> ";
	dat1.step_one_day();
	std::cout << dat1 << std::endl;
	std::cout << std::endl;
}

int main(int argc, const char* argv[]) {
	/* Denna uppgift kan du kompilera och k�ra fr�n b�rjan. Du anropar bara
	 * funktionen "first_print()".
	 * Funktionen "max_print()" testar alla de funktioner som du skall skriva.
	 * F�r att utv�rdera/evaluate din l�sning i VPL, s� skall endast "min_print_eval()"
	 * k�ras, "max_print()" och "first_print()"skall d� vara bortkommenterade.
	 */

	first_print();
	max_print();
	//min_print_eval();

	return 0;
}
