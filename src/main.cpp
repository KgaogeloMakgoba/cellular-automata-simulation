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

    //Main loop
     do
       {
        //Output the menu options here
          #ifdef __linux__
          system("clear");
          #elif _WIN32
          system("cls");
          #endif
          cout << "1.) Set the number of rounds to run the algorithm" << endl;
          cout << "2.) Create an initial random pattern" << endl;
          cout << "3.) Set a manual initial pattern" << endl;
          cout << "4.) Run the algorithm" << endl;
          cout << "0.) Quit" << endl;
          //Output the initial array
          cout << "Number of rounds:" << intLoopCount << endl;
          OutputArr(arrCells,intArrCount);
          //Get input from user
          cin >> chInput;
          switch(chInput)
                {
                  case '1':
                      intLoopCount = GetRounds();
                      break;
                  case '2':
                      RandomArray(arrCells,intArrCount);
                      break;
                  case '3':
                      ManualArray(arrCells,intArrCount);
                      break;
                  case '4':
                      RunEvolution(arrCells,intArrCount,intLoopCount);
                      break;
                  case '0':
                      blnContinue = false;
                      break;
                  default:
                      cerr << "Invalid option. Please retry";
                }

        }while(blnContinue);

       RemoveArray(arrCells);



   return SUCCESS;
  }
