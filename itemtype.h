// Specification of ADT ItemType
//     data object is an item for an i/o request to a magnetic disk
//     operations: create, destroy, copy, operator=
//     friends: operator<< for output and operator>> for input

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
using namespace std;

class ItemType
{
   //prints out an item
   //pre rhsitem is assigned, output is assigned either cout or output file
   //post rhsitem's contents are printed on output
   //     in the following order: id, track, read/write, sector
   //usage cout << item;
   friend ostream& operator<< (ostream& output, const ItemType& rhsitem);

   //inputs an item
   //pre input is assigned either cin or an input file
   //    input is organized with id space read/write space track space sector newline
   //post contents from input are loaded into rhsitem
   //usage infile >> item;
   friend istream& operator>> (istream& input, ItemType& rhsitem);

public:

   //makes an empty item
   //post item is empty
   //usage ItemType it;
   ItemType();

   //destroys an item
   //pre item exists
   //post item does not exist
   //usage automatically done at the end of scope
   ~ItemType();

   //copies an item
   //pre rhsitem is assigned
   //post calling object is a copy of rhsitem
   //usage  ItemType item2(item1);
   ItemType(const ItemType& rhsitem);

   //copies an item
   //pre calling object and rhsitem exist
   //post calling object is a copy of rhsitem
   //usage item2 = item1;
   ItemType& operator=(const ItemType& rhsitem);


private:
   char readWrite;
   int sector;
   int track;
   int id;
};
#endif
