#include <iostream>
#include <vector>
#include <map>

//using namespace std; (bro is slowness-phobic?)
//Finally got it under 2s, where is Rujia Liu

using std::cin;
using std::cout;
using std::map;
using std::vector;

int getChosenOccurrence(map<int, vector<int>>& numMap, int searchedOcc, int searchedNum)
{
    //If the vector (of occurrences)'s size associated (in the map) with the key (searchNum) is lesser than the
    //value of the searchedOccurrence. Then, since the vector holds positions of i-nth occurrences: it means the
    //searchOccurrence doesn't exist in a metaphorical list made with these numbers.
    //Vector of positions:
    //index = i-nth occurrence
    //value = position of i-nth occurrence in a metaphorical list
    if((int)numMap[searchedNum].size() < searchedOcc){
        return 0;
    }else{
        //If the searched occurrence is lower than the number of elements (occurences), then the occurrence
        //exists in the metaphorical list.
        //So, since the position of each element in the vector signifies each i-nth occurrence, i just need to
        //return the element (in the vector associated with the searchedNum (in the map)), but since the occurrence
        //i inserted in the searchedOccurrence regards a 1-indexed list, i need to to reduce it by one to translate
        //it to the 0-indexed vector (0th position in vector = 1st occurence, that's the reason for '-1').
        //And then i need to add '+1' on the value itself returned, cuz the position of the occurrence (which
        //is each element in the vec) is also 1-indexed (cause each element (number) in the vector is a position/index
        //in the metaphorical list, that's why these '+1' and '-1' don't cancel out, each one is meant to correct
        //the indexes of their own lists)
        return numMap[searchedNum][searchedOcc - 1] + 1;
    }
}

int main(void)
{
    int listElementQuant, queries;
    int listNum;
    int searchedOccurrence, searchedNum;
    int i;

    map<int, vector<int>> numMap;

    while(cin >> listElementQuant >> queries){
        numMap.clear();

        for(i = 0;i < listElementQuant; i++){
            cin >> listNum;
            numMap[listNum].push_back(i);
        }

        while(queries--){
            cin >> searchedOccurrence >> searchedNum;
            cout << getChosenOccurrence(numMap, searchedOccurrence, searchedNum) << '\n';
        }
    }
}