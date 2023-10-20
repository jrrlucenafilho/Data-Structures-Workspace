#include <iostream>
#include <list>

using namespace std;

//Check if it's:
//LIFO: Stack
//FIFO: Queue
//Biggest-element-first: Priority queue

//"1" is an addition command
//"2" is a removal command
//suppose non-same-number additions
int main(void)
{
    int operation_quant, operand, operation, removal_return;
    bool is_stack = false, is_queue = false, is_p_queue = false; 
    
    list<int> placeholder_list;

    while(cin.eof() == false){
        cin >> operation_quant;

        while(operation_quant--){
            cin >> operation;

            //Kinds of ops
            //1 expects an "x" which is "operand" here
            if(operation == 1){
                cin >> operand;
                placeholder_list.push_back(operand);
            }else if(operation == 2){
                //Reads what would've been returned in the proper data structure, infer it from input
                cin >> removal_return;
            }

            if((operation == 2) && ((int)placeholder_list.size() > 1)){ //One-element-list would mess with it
                //Checks which data structure is being manip
                //Check if LIFO (Stack)
                int last_in = placeholder_list.back();

                if((last_in == removal_return) && !is_p_queue){
                    is_stack = true;
                }

                //Check if FIFO (Queue)
                int first_in = placeholder_list.front();

                if(first_in == removal_return){
                    is_queue = true;
                }

                //Check if Biggest-element-first (Priority Queue)
                placeholder_list.sort();

                if(placeholder_list.back() == removal_return){  //Means it's the biggest value (end-of-list after sorting)
                    is_p_queue = true;
                }

                //Removes the chosen opcode==2 operand from list
                placeholder_list.remove(removal_return);
            }
        }

        //Filters
        if(!(is_stack || is_queue || is_p_queue)){
            cout << "impossible\n";
        }

        if((is_stack && is_queue) || (is_stack && is_p_queue) || (is_queue && is_p_queue) || (is_queue && is_p_queue && is_stack)){
            cout << "not sure\n";
        }

        if(is_stack && !is_queue && !is_p_queue){
            cout << "stack\n";
        }

        if(is_queue && !is_stack && !is_p_queue){
            cout << "queue\n";
        }

        if(is_p_queue && !is_queue && !is_stack){
            cout << "priority queue\n";
        }

        is_stack = false;
        is_queue = false;
        is_p_queue = false;
        placeholder_list.clear();
    }

    return 0;
}