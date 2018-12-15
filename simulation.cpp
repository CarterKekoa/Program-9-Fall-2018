//Authors: Carter Mooring & Jerry Xue
//Date: Dec. 1st, 2018
// File Name: simulation.cpp
// Gonzaga University, CPSC 122, Dr. Yerion

#include "queue.h"
#include "itemtype.h"
#include <iostream>
#include <fstream>

using namespace std;

void printTheDisk(Queue& disk);
void fillDisk(int size, ifstream& infile, Queue& disk);
void serve(int size, ifstream& infile, Queue& disk);
void openFile(ifstream& infile, string fileName);
void closeFile(ifstream& infile);
void doSimulation(Queue& disk, ifstream& infile);

int main() {

  ifstream infile;
  Queue disk;

  openFile(infile, "requests.dat");
  doSimulation(disk, infile);

  closeFile(infile);

  return 0;
}

//Description: This function prints the disk to the screen
//Pre: disk object exists and is filled with values
//Post: The contents of disk have been displayed to the screen
//Usage: printTheDisk(disk)
void printTheDisk(Queue& disk)
{
    cout << "The queue: " << disk << endl;
}

//Description: This function fills the disk with values in the file
//Pre: size is known, the input file has been accessed and is filled,
//      the disk object exists
//Post: The disk object is filled with values from the input file
//Usage: fillDisk(3, infile, disk)
void fillDisk(int size, ifstream& infile, Queue& disk)
{
  bool isNotFull;

  ItemType item;
  for (int count = 0; count < size; count++)
  {
    infile >> item;
    disk.lineUp(item, isNotFull);
  }
}

//Description: This function serves the requests until it reaches the end of the file
//Pre: size is known, the input file has been accessed and is filled,
//         the disk object exists
//Post: The requests have been served
//Usage: serveRequest(1, infile, disk)
void serveRequest(int size, ifstream& infile, Queue& disk)
{
  bool isNotFull;
  for (int count = 0; count < size; count++)
  {
    if (count == 0)
    {
      cout << "The Request being served: ";
    }
    cout << disk.getWhoIsServed();
    disk.getServed(isNotFull);
    if (count == size - 1)
    {
      cout << endl << endl;
    }
  }
}
//Description: This function opens a file
//Pre: file exist and we know the name and infile exist
//Post: file is opened
//Usage: openFile(in, "requests.dat")
void openFile(ifstream& infile, string fileName)
{
	infile.open (fileName);
	if (!infile.is_open())
    {
	    cout << "Failed to open input file." << endl;
	    exit(-1);
	}
}

//Description: This function closes the file
//Pre:infile exist
//Post: file is closed
//Usage: closeFile(infile);
void closeFile(ifstream& infile)
{
  infile.close();
}

//Description: This function simulates requests for a magnetic disk coming in
//          and being served
//Pre: disk object exists and the input file has been accessed and is filled
//Post: A sequence of requests coming in and being served is output to the screen
//Usage: doSimulation(disk, infile);
void doSimulation(Queue& disk, ifstream& infile)
{
  cout << endl << endl;
  printTheDisk(disk);
  fillDisk(3, infile, disk);
  printTheDisk(disk);
  serveRequest(1, infile, disk);
  printTheDisk(disk);
  fillDisk(2, infile, disk);
  printTheDisk(disk);
  serveRequest(3, infile, disk);
  printTheDisk(disk);
  fillDisk(5, infile, disk);
  printTheDisk(disk);
  serveRequest(6, infile, disk);
  printTheDisk(disk);
  cout << endl;
}
