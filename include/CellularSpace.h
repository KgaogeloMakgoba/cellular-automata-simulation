#ifndef CELLULARSPACE_H_INCLUDED
#define CELLULARSPACE_H_INCLUDED


#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

   using namespace std;

   namespace CellularSpace
   {
    //Here we declare const variables and types
     typedef bool* QueueType; //QueueType is an array type that describes a number of bool values.
    //Program return values
     const int ERR_RANGE = -3;
     const int ERR_CONV = -2;
     const int ERR_ARGC = -1;
     const int SUCCESS = 0;
    //Output characters
     const char CH_TRUE = '#';
     const char CH_FALSE = '.';
    //Range check to ensure the system doesn't run forever.
     const int MAX_ROUNDS = 1000;
     const int MIN_NUM_VALS = 20;

     int ConvertToInt(string strNum); //Converts a string to an int if possible
     QueueType InitArray(int intCount); //Returns an array of boolean values
     void RemoveArray(QueueType& arrCells); //Deallocate the memory of an array
     void OutputArr(QueueType arrCells, int intArrCount); //Print the array
     int GetRandom(int intLower, int intUpper); //Returns a random number between the range
     void Pause();
     void RandomArray(QueueType arrCells, int intArrCount);
     int GetInt();
     void CopyArray(QueueType arrOne, QueueType arrTwo, int intCount);


   }



#endif // CELLULARSPACE_H_INCLUDED
