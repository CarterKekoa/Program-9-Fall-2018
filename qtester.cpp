// Carter Mooring & Jerry Xue
// client program to test methods of class queue
// client.cpp
// nov 16, 2020
// Gonzaga University, CPSC 122, Dr. Yerion

#include "queue.h"
#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	ItemType value;
	ifstream infile;
	Queue norvelle;
	Queue tille ;
	bool isNotFull;

  infile.open("requests.dat");
	infile >> value;

	cout << endl << endl;
	cout << "Norvelle Queue Made: " << endl;
	cout << "Norvelle: " << norvelle << endl;
	cout << endl;

	cout << "Adding cycle of request to Norvelle" << endl;
  norvelle.lineUp(value, isNotFull);
	cout << "Adding next cycle of request to Norvelle" << endl;
	infile >> value;
	norvelle.lineUp(value, isNotFull);
	cout << "Adding next cycle of request to Norvelle" << endl;
	infile >> value;
	norvelle.lineUp(value, isNotFull);
	cout << endl << endl;
	cout << "Front of the Norvelle Queue" << endl;
	cout << norvelle.getWhoIsServed() << endl;

	cout << "Adding cycle of request to Tille " << endl;
	infile >> value;
	tille .lineUp(value, isNotFull);

	cout << "Printing Norvelle and Tille " << endl;
	cout << norvelle << endl << tille ;
	cout << endl << endl;
	cout << "Size of Norvelle Queue " << norvelle.getSize() << endl;
	cout << "Size of Tille  Queue " << tille .getSize() << endl;
	cout << "Deleting front item of Norvelle" << endl;
  norvelle.getServed(isNotFull);

	cout << "Norvelle " << norvelle << endl;
	cout << "Tille  " << tille  << endl;
	cout << "Size of Norvelle " << norvelle.getSize() << endl;
	cout << "Size of Tille  " << tille .getSize() << endl;
	cout << "Setting Tille  to equal norvelle" << endl;
	tille  = norvelle;
	cout << "Tille  " << tille  << endl;

	infile.close();

	return 0;
}
