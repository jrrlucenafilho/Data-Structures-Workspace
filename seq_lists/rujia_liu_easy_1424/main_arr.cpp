#include <iostream>

//using namespace std; (bro is slowness-phobic)

#define ELEMENT_QUANT 50

int main(void)
{
    int vecElementQuant, queries;
    int pushBackNum;
    int searchedOccurrenceQuant, searchedNum;
    int numOccurrences = 0;
    bool occurrenceFound = false;
    int i;

    int numArr[ELEMENT_QUANT];

    //Zeroing the entire array
    for(i = 0; i < ELEMENT_QUANT; i++){
        numArr[i] = 0;
    }

    //Searching
    while(std::cin.eof() == false){
        std::cin >> vecElementQuant >> queries;

        //Make the vector itself from input
        while(vecElementQuant--){
            std::cin >> pushBackNum;

            for(i = 0; i < ELEMENT_QUANT; i++){     //Basically a push-back
                if(numArr[i] == 0){
                    numArr[i] = pushBackNum;
                    break;
                }
            }
        }
        
        while(queries--){
            std::cin >> searchedOccurrenceQuant >> searchedNum;

            for(i = 0; i < ELEMENT_QUANT; i++){
                //Match for each singular occurrence
                if(numArr[i] == searchedNum){
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

        //Zeroing the entire array to start anew
        for(i = 0; i < ELEMENT_QUANT; i++){
            numArr[i] = 0;
        }
    }

    return 0;
}