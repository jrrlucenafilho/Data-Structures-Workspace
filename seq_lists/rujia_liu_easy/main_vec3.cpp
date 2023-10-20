#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std; (+bro is slowness-phobic)
//Version with fors

using std::cin;
using std::cout;
using std::vector;
//using std::count;

int findNthOccurrence(const vector<int>& numVec, int targetNum, int targetOccQuant)
{
    int occurrences = 0;

    for(int i = 0; i < (int)numVec.size(); i++){

        if(numVec[i] == 0){
            return 0;   //Since 0 means empty spot here
        }

        if(numVec[i] == targetNum){
            occurrences++;

            if(occurrences == targetOccQuant){
                return i+1;     //Return the index of the n-th occurrence
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
    int numOccurrences = 0;
    //int i;

    vector<int> numVec;

    //Pre-alloc so it doesn't need to keep doubling the first time, heap-alloc'ing memory for it (+speed)
    numVec.reserve(1000000);

    //Searching
    while(cin >> vecElementQuant >> queries){

        //Make the vector itself from input
        while(vecElementQuant--){
            cin >> pushBackNum;
            numVec.push_back(pushBackNum);
        }
        
        while(queries--){
            cin >> searchedOccurrenceQuant >> searchedNum;

            numOccurrences = count(numVec.begin(), numVec.end(), searchedNum);

            //Stops here if no occurrences of the searched number (+speed)
            if(numOccurrences == 0){
                cout << "0\n";
                continue;
            }

            //Matches for the chosen occurrence
            cout <<  findNthOccurrence(numVec, searchedNum, searchedOccurrenceQuant) << '\n';
        }
        numVec.clear();
    }

    return 0;
}