#include <iostream>
//Not using vectors just yet
#define ARR_MAX_QUANT 5
#define INPUT_SIZE 15

using namespace std;

void arrayAdder(int evenArray[], int oddArray[], int currentInput)
{
    if(currentInput % 2){   //Is Odd
        for(int i = 0; i < ARR_MAX_QUANT; i++){
            if(oddArray[i] == 0){
                oddArray[i] = currentInput;
                break; //So it doesn't continue
            }
        }
    }else{
        for(int i = 0; i < ARR_MAX_QUANT; i++){
            if(evenArray[i] == 0){
                evenArray[i] = currentInput;
                break;
            }
        }
    }
}

bool isArrayFull(int arr[])
{
    for(int i = 0; i < ARR_MAX_QUANT; i++){
        if(arr[i] == 0){
            return false;
        }
    }
    
    return true;
}

int main(void)
{
    int evenArray[ARR_MAX_QUANT] = {0, 0, 0, 0, 0};
    int oddArray[ARR_MAX_QUANT] = {0, 0, 0, 0, 0};

    int currentInput;

    for(int i = 0; i < INPUT_SIZE; i++){
        cin >> currentInput;

        arrayAdder(evenArray, oddArray, currentInput);
    
        if(isArrayFull(oddArray)){
            for(int j = 0; j < ARR_MAX_QUANT; j++){
                cout << "impar[" << j << "] = " << oddArray[j] << '\n';
                oddArray[j] = 0; //Immediately clear it
            }
        }

        if(isArrayFull(evenArray)){
            for(int j = 0; j < ARR_MAX_QUANT; j++){
                cout << "par[" << j << "] = " << evenArray[j] << '\n';
                evenArray[j] = 0;
            }
        }

        //Unconditionally print what's left on both arrays once input ends
        if(i == INPUT_SIZE - 1){
            for(int j = 0; j < ARR_MAX_QUANT; j++){
                if(oddArray[j] != 0){
                    cout << "impar[" << j << "] = " << oddArray[j] << '\n';
                }
            }

            for(int j = 0; j < ARR_MAX_QUANT; j++){
                if(evenArray[j] != 0){
                    cout << "par[" << j << "] = " << evenArray[j] << '\n';
                }
            }
        }
    }

    return 0;
}