#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::stack;
using std::string;

int main(void)
{
    stack<char> par_stack;
    string line;
    size_t open_par_count = 0;
    size_t closing_par_count = 0;
    int i;
    bool correctness = true;    //right 'till it's wrong

    //Reading 'till it ends
    while(true){
        cin >> line;

        for(i = 0; i < (int)line.size(); i++){
            if(line[i] == '('){
                par_stack.push('(');
            }else if(line[i] == ')'){
                par_stack.push(')');
            }
        }

        //Checks for un-closed parenthesis
        if(par_stack.top() == '('){
            correctness = false;
        }

        //Checks for counter equality
        open_par_count = count(line.begin(), line.end(), '(');
        closing_par_count = count(line.begin(), line.end(), ')');

        if(open_par_count != closing_par_count){
            correctness = false;
        }

        if(correctness){
            cout << "correct\n";
        }else{
            cout << "incorrect\n";
        }
    }

    return 0;
}