#include <iostream>

using std::cin;
using std::cout;

int main(void)
{
    int regionQuant, jumpSize = 1;
    int returningJumps = 0;
    int i;

    while(true){
        cin >> regionQuant;
        
        if(regionQuant == 0){
            break;
        }

        while(true){
            for(i = 1; i < regionQuant; i++){
                returningJumps = (returningJumps + jumpSize) % i;   //Regarding position
            }

            if(returningJumps != 13){
                jumpSize++;
            }else{
                break;
            }
        }
        cout << jumpSize << '\n';
    }
    return 0;
}