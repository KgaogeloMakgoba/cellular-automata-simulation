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

         //Evolution algorithm
        void Evolve(QueueType arrCells, int intArrCount)
           {
             //Generates a temporary 1D array
             QueueType tempArr = InitArray(intArrCount);

             //Create three variables to hold left, middle and right values.
             bool blnLeft;
             bool blnMiddle;
             bool blnRight;

             //For each of the values in the array. Calculate the new value
             for(int i=0;i<intArrCount;i++)
                {
                  if(i==0)
                     blnLeft = arrCells[intArrCount-1];
                  else
                     blnLeft = arrCells[i-1];

                  if(i==intArrCount-1)
                     blnRight = arrCells[0];
                  else
                     blnRight = arrCells[i+1];

                  blnMiddle = arrCells[i];

                 //Convert the values of the three cells into an integer value
                  int intRuleValue = 0;
                  intRuleValue += static_cast<int>(blnLeft)*4;
                  intRuleValue += static_cast<int>(blnMiddle)*2;
                  intRuleValue += static_cast<int>(blnRight)*1;

                 //Lets assume the next version of the cell is dead
                  tempArr[i] = false;
                 //Pattern 4-7 is a decimal representation of values 1-4. In those cases the next version of the cell is alive
                  if(intRuleValue>=1 && intRuleValue <= 4)
                      tempArr[i] = true;

              }
          //Overwrite the main array with temp array
           CopyArray(arrCells,tempArr,intArrCount);
         //Remove temp array, otherwise there will be a memory leak.
           RemoveArray(tempArr);

          }

          //Function called from main menu to start the evolution process
         void RunEvolution(QueueType arrCells, int intArrCount, int intRounds)
             {
              //Output the array
               OutputArr(arrCells,intArrCount);
              //Run for intRounds

               for(int i=0;i<intRounds;i++)
                  {
                    Evolve(arrCells,intArrCount); //Modify arrCells to the new round
                    OutputArr(arrCells,intArrCount);
                  }
               Pause();
             }

          //Outputs the index values of the array when using the manual input.
         void OutputIndex(int intIndex, int intArrCount)
             {
               for(int i=0;i<intArrCount;i++)
                  {
                     cout << setw(2);
                     if(i==intIndex)
                       cout << i;
                     else
                       cout << " ";
                  }
               cout << endl;
            }


           //Allows the user to input the array manually using a cursor based system
           void ManualArray(QueueType arrCells, int intArrCount)
               {
                 bool blnContinue = true;
                 char chInput = '\0';
                 int intActIndex = 0; //The current index of the array item on the screen
                 do
                   {
                     //Determines if system("clear") or system("cls") should be used.
                     #ifdef __linux__
                     system("clear");
                     #elif _WIN32
                     system("cls");
                     #endif

                     cout << " ";
                     OutputArr(arrCells,intArrCount); //Outputs the array
                     OutputIndex(intActIndex,intArrCount); //Outputs the index
                     cout << "a) Move the cursor left" << endl
                          << "d) Move the cursor right" << endl
                          << "p) Toggle the current value" << endl
                          << "q) Quit the input" << endl;
                     cin >> chInput;
                     //Moves the cursor left and right, allowing the user to toggle a value to either true or false
                     switch(toupper(chInput))
                        {
                          case 'A': //Move left
                              if(intActIndex>0)
                                 intActIndex--;
                              break;
                          case 'D': //Move right
                              if(intActIndex<intArrCount-1)
                                 intActIndex++;
                              break;
                          case 'P': //Toggle the value at the current index
                               arrCells[intActIndex]=!arrCells[intActIndex];
                              break;
                          case 'Q': //Quit the manual input
                               blnContinue = false;
                              break;
                          default:
                               cout << "Invalid option. Please retry" << endl;

                       }

                    }while(blnContinue);

              }


              int GetRounds()
                {
                 int intNum = 0;
                 cout << "How many rounds must the life evolve? (1 - " << MAX_ROUNDS << "):";
                 intNum = GetInt();
                 while(intNum <=0 || intNum > MAX_ROUNDS)
                    {
                      cerr << "Please make sure the number of round are between 1 and " << MAX_ROUNDS << endl;
                      cout << "Please retry:";
                      intNum = GetInt();
                     }
                 return intNum;
                }

   }





