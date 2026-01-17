#include "CellularSpace.h"



  namespace CellularSpace
  {
    //Converts a string number into an integer. Exits the program in case it fails
     int ConvertToInt(string strNum)
        {
          stringstream ss {strNum};
          int intNum;
          ss >> intNum;
          if(ss.fail())
            {
              cerr << "Conversion error" << endl;
              cout << "Could not convert " << strNum << " to integer";
              exit(ERR_CONV);
            }

          return intNum;
        }

   //Initialises the 1D array
      QueueType InitArray(int intCount)
        {
          //Declare the 1D array variable
           QueueType arrCells;
          //Allocate memory
            arrCells = new bool[intCount];
          //Initialise the values in the array to false
          for(int i=0;i<intCount;i++)
            {
              arrCells[i] = false;
            }

          return arrCells;
         }

      //A function that deallocates a 1D array
         void RemoveArray(QueueType& arrCells)
            {
             //Deallocate the memory of the array
             delete[] arrCells;
            //Change the value of the variable to NULL.
             arrCells = nullptr;
            }

     //Outputs arrCells
        void OutputArr(QueueType arrCells, int intArrCount)
           {
               for(int i=0;i<intArrCount;i++)
                  {
                    switch(arrCells[i])
                        {
                         case true:
                         cout << CH_TRUE << " ";
                         break;
                         case false:
                         cout << CH_FALSE << " ";
                         break;
                        }
                }
               cout << endl;
          }

       //Returns a random number in the range of intLower and intUpper
         int GetRandom(int intLower, int intUpper)
              {
                int intNum;
                int intRange = intUpper - intLower + 1;
                intNum = rand()%intRange + intLower;
                 return intNum;
              }

         void Pause()
            {
             cin.ignore(100,'\n');
             cout << "Press Enter to contiue" << endl;
             cin.get();

             }

         void RandomArray(QueueType arrCells, int intArrCount)
            {
              //Loop through each array value
              for(int i=0;i<intArrCount;i++)
                {
                //Generate either a zero or one
                  int intRandNum = GetRandom(0,1);
                  if(intRandNum==0)
                  arrCells[i] = false;
                  else

                  arrCells[i] = true;
                }
            }

         //Guarantees an integer returned from the std input stream.
         int GetInt()
            {
             int intNum;
             cin >> intNum;
             while(cin.fail())
                {
                 cerr << "Could not convert to integer. Please only type a number. Please retry:" << endl;
                 string strJunk;
                 cin >> strJunk;
                 cin >> intNum;
                }
               return intNum;
            }


            //Makes a copy of arrTwo, into arrOne
        void CopyArray(QueueType arrOne, QueueType arrTwo, int intCount)
           {
            for(int i=0;i<intCount;i++)
               {
                arrOne[i] = arrTwo[i];
               }
           }


   }
