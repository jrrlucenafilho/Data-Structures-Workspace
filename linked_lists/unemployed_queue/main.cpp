#include <iostream>
#include "Node.hpp"

#define CANDIDATE_QUANT 21

using namespace std;

int main(void)
{
    int kPosCounter, nStartingPos, mPosCounter; //Counting selection positions

    while(true){
        Node candidates[CANDIDATE_QUANT];
        int remainingCandidates;
        int i, j, k;

        cin >> nStartingPos >> kPosCounter >> mPosCounter;

        if((kPosCounter == 0) || (nStartingPos == 0) || (kPosCounter == 0)){
            break;
        }

        //"Assigning Circularity" loop
        for(i = 1; i <= nStartingPos; i++){
            candidates[i].setContent(i);

            //For prev pos'
            if(i == 1){
                candidates[i].setPrevious(nStartingPos); //For first iter
            }else{
                candidates[i].setPrevious(i - 1);
            }

            //For next pos'
            if(i == nStartingPos){
                candidates[i].setNext(1);
            }else{
                candidates[i].setNext(i + 1);
            }
        }

        //Handling "rots"
        candidates[0].setNext(1);
        candidates[nStartingPos + 1].setPrevious(nStartingPos);

        remainingCandidates = nStartingPos;
        j = 0;
        k = nStartingPos + 1;

        while(true){
            for(i = 0; i < kPosCounter; i++){   //Nexts loop
                j = candidates[j].getNext();
            }

            for(i = 0; i < mPosCounter; i++){   //Prevs loop
                k = candidates[k].getPrevious();
            }

            printf("%3d", candidates[j].getContent());  //Using printf for consistent formatting of 3 chars
            
            remainingCandidates--;

            if(j != k){
                printf("%3d", candidates[j].getContent());
                remainingCandidates--;
            }

            if((candidates[j].getPrevious() == k) || (candidates[j].getNext() == k)){
                //First case (Prev edge)
                if(candidates[j].getPrevious() == k){
                    candidates[j].setPrevious(candidates[k].getPrevious());
                    candidates[k].setNext(candidates[j].getNext());
                }

                //Second case (Next Edge)
                if(candidates[j].getNext() == k){
                    candidates[j].setNext(candidates[k].getNext());
                    candidates[k].setPrevious(candidates[j].getPrevious());
                }
            }

            candidates[candidates[j].getPrevious()].setNext(candidates[j].getNext());
            candidates[candidates[j].getNext()].setPrevious(candidates[j].getPrevious());

            if(j != k) {
                candidates[candidates[k].getPrevious()].setNext(candidates[k].getNext());
                candidates[candidates[k].getNext()].setPrevious(candidates[k].getPrevious());
            }

            if(remainingCandidates > 0){
                cout << ",";
            }else{
                cout << "\n";
                break;
            }
        }
    }

    return 0;
}