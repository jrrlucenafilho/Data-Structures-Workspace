#include <iostream>
#include <list>

using std::cin;
using std::cout;
using std::string;
using std::list;

int main(void)
{
    int op_quant, joy_value;
    string operation_str;
    list<int> noels_stacky_list, noels_sorted_stacky_list;

    cin >> op_quant;

    while(op_quant--){
        cin >> operation_str;

        if(operation_str == "PUSH"){
            cin >> joy_value;
            noels_stacky_list.push_back(joy_value);
        }else if(operation_str == "MIN"){
            if(noels_stacky_list.empty()){
                cout << "EMPTY\n";
                continue;
            }

            //Copies and makes a sorted version
            noels_sorted_stacky_list = noels_stacky_list;
            noels_sorted_stacky_list.sort();

            //First element will be the min
            cout << noels_sorted_stacky_list.front() << "\n";
        }else if(operation_str == "POP"){
            if(noels_stacky_list.empty()){
                cout << "EMPTY\n";
                continue;
            }

            noels_stacky_list.pop_back();
        }
    }

    return 0;
}