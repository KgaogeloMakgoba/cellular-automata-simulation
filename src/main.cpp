#include <iostream>
#include "CellularSpace.h"



   using namespace std;
   using namespace CellularSpace;

   int main(int argc, char** argv)
   {
      //Seed the random number generator
       srand(time(nullptr));
     //See if the program arguments are set properly
      if(argc!=2)
        {
          cerr << "Incorrect argument count" << endl;
          cout << "Please run the application as:" << argv[0] << " <Num of items>" << endl;
          exit(ERR_ARGC);
        }


    //Convert the command line argument to integers
     int intArrCount = ConvertToInt(argv[1]);
     int intLoopCount = 0;
    //Make sure the number is positive and big
    if(intArrCount<MIN_NUM_VALS)
      {
        cerr << "Please run the program with an array size of at least 20 numbers" << endl;
        exit(ERR_RANGE);
      }

   //Variables for the main loop
     bool blnContinue = true;
     char chInput = '\0';
     QueueType arrCells = InitArray(intArrCount);



   return SUCCESS;
  }
