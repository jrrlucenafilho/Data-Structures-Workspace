#include <iostream>
#include <vector>

//using namespace std; (+bro is slowness-phobic)
//Version with fors
int main(void)
{
    int vecElementQuant, queries;
    int pushBackNum;
    int searchedOccurrenceQuant, searchedNum;
    int numOccurrences = 0;
    bool occurrenceFound = false;
    int i, j;

    std::vector<int> numVec;

    //Pre-alloc so it doesn't need to keep doubling, heap-alloc'ing memory for it (+speed)
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

            for(j = 0; j < (int)numVec.size(); j++){
                //Match for each singular occurrence
                if(numVec[j] == searchedNum){
                    numOccurrences++;
                }else{
                    //It'll only trigger the next if-block if it's found an occurrence (+speed)
                    continue;
                }

                //Matches for the chosen occurrence, if found
                if(numOccurrences == searchedOccurrenceQuant){
                    std::cout << j+1 << '\n';
                    occurrenceFound = true;
                    break;
                }
            }

            //Prints zero if not found while also resetting individual occurrence counting and bool
            if(!occurrenceFound){
                std::cout << "0\n";
            }
            occurrenceFound = false;
            numOccurrences = 0;
        }
        numVec.clear();
    }

    return 0;
}