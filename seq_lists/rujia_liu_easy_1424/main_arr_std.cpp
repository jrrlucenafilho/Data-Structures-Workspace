#include <iostream>
#include <array>
#include <algorithm>

using std::cin;
using std::cout;
using std::array;
using std::count;

#define ELEMENT_QUANT 26096

int findNthOccurrence(const array<int, ELEMENT_QUANT>& numArr, int targetNum, int targetOccQuant)
{
    int occurrences = 0, i;

    for(i = 0; i < ELEMENT_QUANT; i++){

        if(numArr[i] == 0){
            return 0;   //Since 0 means empty spot here
        }

        if(numArr[i] == targetNum){
            occurrences++;

            if(occurrences == targetOccQuant){
                return i+1;   //Return the index of the n-th occurrence
            }
        }
    }

    return 0;
}

int main(void)
{
    int vecElementQuant, queries;
    int pushBackNum;
    int searchedOccurrenceQuant, searchedNum;
    //int numOccurrences = 0;
    int i;

    array<int, ELEMENT_QUANT> numArr;

    //Searching
    while(cin >> vecElementQuant >> queries){
        //Zeroing the entire array
        numArr.fill(0);

        //Make the vector itself from input
        while(vecElementQuant--){
            cin >> pushBackNum;

            for(i = 0; i < ELEMENT_QUANT; i++){     //Basically a push-back
                if(numArr[i] == 0){
                    numArr[i] = pushBackNum;
                    break;
                }
            }
        }
        
        while(queries--){
            cin >> searchedOccurrenceQuant >> searchedNum;

            //numOccurrences = count(numArr.begin(), numArr.end(), searchedNum);

            //Stops here if no occurrences of the searched number (+speed)
            //if(numOccurrences == 0){
            //    cout << "0\n";
            //    continue;
            //}
            
            //Matches for the chosen occurrence
            cout <<  findNthOccurrence(numArr, searchedNum, searchedOccurrenceQuant) << '\n';
        }
    }

    return 0;
}