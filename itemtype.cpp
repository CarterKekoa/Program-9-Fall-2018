// Implementation of ADT ItemType
//    data object is an item for an i/o request to a magnetic disk
//    data structures: a char for read or write, an int for sector, track, and id
//    operations: create, destroy, copy, operator=
//                GetReadWrite, GetSector, GetTrack, GetId
//    friends: operator<< for output and operator>> for input
// Gonzaga University, CPSC 122, Dr. Yerion

#include "itemtype.h"

//prints out an item
//pre rhsitem is assigned, output is assigned either cout or output file
//post rhsitem's contents are printed on output
//     in the following order: id, track, read/write, sector
//usage cout << item;
ostream& operator<< (ostream& output, const ItemType& rhsitem)
{
   cout << endl;
   cout << "     ";
   output << "*Id = " << rhsitem.id << "* ";
   output << "TRACK = " << rhsitem.track << " *";
   output << " RW = " << rhsitem.readWrite << "*";
   output << " sector = " << rhsitem.sector << "* ";
   return output;
}

//inputs an item
//pre input is assigned either cin or an input file
//    input is organized with id space read/write space track space sector newline
//post contents from input are loaded into rhsitem
//usage infile >> item;
istream& operator>> (istream& input, ItemType& rhsitem)
{
   input >> rhsitem.id;
   input >> rhsitem.readWrite;
   input >> rhsitem.track;
   input >> rhsitem.sector;
   return input;
}

//makes an empty item
//post item is empty
//usage ItemType it;
ItemType::ItemType()
{
   id = 0;
   readWrite = '\0';
   track = 0;
   sector = 0;
}

//destroys an item
//pre item exists
//post item does not exist
//usage automatically done at the end of scope
ItemType::~ItemType()
{
   id = 0;
   readWrite = '\0';
   track = 0;
   sector = 0;
}


//copies an item
//pre rhsitem is assigned
//post calling object is a copy of rhsitem
//usage  ItemType item2(item1);
ItemType::ItemType(const ItemType& rhsitem)
{
   id = 0;
   readWrite = '\0';
   track = 0;
   sector = 0;
   operator=(rhsitem);
}

//copies an item
//pre calling object and rhsitem exist
//post calling object is a copy of rhsitem
//usage item2 = item1;
ItemType& ItemType::operator=(const ItemType& rhsitem)
{
   if (this != &rhsitem)
   {
      id = rhsitem.id;
      readWrite = rhsitem.readWrite;
      track = rhsitem.track;
      sector = rhsitem.sector;
   }
   return *this;
}
