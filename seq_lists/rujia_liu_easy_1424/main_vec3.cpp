#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

//using namespace std; (+bro is slowness-phobic)
//Version with fors

int main(void)
{
    int vecElementQuant, queries;
    int pushBackNum;
    int searchedOccurrenceQuant, searchedNum;
    int numOccurrences;
    //bool occurrenceFound = false;
    int i, j;

    std::vector<int> numVec;

    //Pre-alloc so it doesn't need to keep doubling the first time, heap-alloc'ing memory for it (+speed)
    numVec.reserve(100);

    //Searching
    while(std::cin.eof() == false){
        std::cin >> vecElementQuant >> queries;

        //Make the vector itself from input
        for(i = 0; i < vecElementQuant; i++){
            std::cin >> pushBackNum;
            numVec.push_back(pushBackNum);
        }
        
        for(i = 0; i < queries; i++){
            std::cin >> searchedOccurrenceQuant >> searchedNum;

            numOccurrences = std::count(numVec.begin(), numVec.end(), searchedNum);

            //Stops here if no occurrences of the searched number (+speed)
            if(numOccurrences == 0){
                std::cout << "0\n";
                continue;
            }

            //Matches for the chosen occurrence
            if(numOccurrences == searchedOccurrenceQuant){
                //TODO: Print the chosen occurrence
                for(j = 0; j < (int)numVec.size(); j++){
                    if(numVec.at(i) == searchedNum){
                        
                    }
                }
                break;
            }
        }
        numVec.clear();
    }

    return 0;
}