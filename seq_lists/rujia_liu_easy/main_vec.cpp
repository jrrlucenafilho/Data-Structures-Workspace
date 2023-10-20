#include <iostream>
#include <vector>

//using namespace std; (+bro is slowness-phobic)
//Version with regressive whiles

int main(void)
{
    int vecElementQuant, queries;
    int pushBackNum;
    int searchedOccurrenceQuant, searchedNum;
    int numOccurrences = 0;
    bool occurrenceFound = false;
    size_t i;

    std::vector<int> numVec;

    //Pre-alloc so it doesn't need to keep doubling, heap-alloc'ing memory for it (+speed)
    numVec.reserve(100);

    //Searching
    while(std::cin >> vecElementQuant >> queries){
        //std::cin >> vecElementQuant >> queries;

        //Make the vector itself from input
        while(vecElementQuant--){
            std::cin >> pushBackNum;
            numVec.push_back(pushBackNum);
        }
        
        while(queries--){
            std::cin >> searchedOccurrenceQuant >> searchedNum;

            for(i = 0; i < numVec.size(); i++){
                //Match for each singular occurrence
                if(numVec[i] == searchedNum){
                    numOccurrences++;
                }else{
                    //It'll only trigger the next if-block if it's found an occurrence (+speed)
                    continue;
                }

                //Matches for the chosen occurrence, if found
                if(numOccurrences == searchedOccurrenceQuant){
                    std::cout << i+1 << '\n';
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