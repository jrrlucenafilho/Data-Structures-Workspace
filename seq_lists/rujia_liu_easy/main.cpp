#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int vecElementQuant, queries;
    int pushBackNum;
    int searchedOccurrenceQuant, searchedNum;
    int numOccurrences = 0;
    bool occurrenceFound = false;

    vector<int> numVec;

    cin >> vecElementQuant >> queries;

    //Make the vector itself from input
    while(vecElementQuant--){
        cin >> pushBackNum;
        numVec.push_back(pushBackNum);
    }

    //Searching
    while(queries--){
        cin >> searchedOccurrenceQuant >> searchedNum;

        for(size_t i = 0; i < numVec.size(); i++){
            //Match for each singular occurrence
            if(numVec[i] == searchedNum){
                numOccurrences++;
            }

            //Matches for the chosen occurrence, if found
            if(numOccurrences == searchedOccurrenceQuant){
                cout << i+1 << '\n';
                occurrenceFound = true;
                break;
            }
        }

        //Prints zero if not found while also resetting individual occurrence counting and bool
        if(!occurrenceFound){
            cout << "0\n";
        }
        occurrenceFound = false;
        numOccurrences = 0;
    }

    return 0;
}