#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::stack;
using std::string;

int main(void)
{
    int test_quant, cur_operator_prec, top_operator_prec;
    string evaluated_str;

    stack<char> conversion_stack;

    cin >> test_quant;

    //Reading each str
    for(int i = 0; i < test_quant; i++){
        cin >> evaluated_str;

        //Iterates through each char, using shunting yard algo
        for(size_t j = 0; j < evaluated_str.size(); j++){
            //Usual chars are just printed
            if(isdigit(evaluated_str[j]) || isalpha(evaluated_str[j])){
                cout << evaluated_str[j];
            }else if((evaluated_str[j] == '(') || (evaluated_str[j] == '^')){
                conversion_stack.push(evaluated_str[j]);
            }else if(evaluated_str[j] == ')'){
                while((!conversion_stack.empty()) && (conversion_stack.top() != '(')){
                    cout << conversion_stack.top();
                    conversion_stack.pop();
                }

                //Working only with operators from here on
                if(!conversion_stack.empty()){
                    conversion_stack.pop();
                }
            }else{
                //Checking shich ops to put in first, comparing current to top of stack
                    switch(evaluated_str[j]){
                        case '+': cur_operator_prec = 1;
                            break;
                        case '-': cur_operator_prec = 1;
                            break;
                        case '*': cur_operator_prec = 2;
                            break;
                        case '/': cur_operator_prec = 2;
                    }

                    switch(conversion_stack.top()){
                        case '+': top_operator_prec = 1;
                            break;
                        case '-': top_operator_prec = 1;
                            break;
                        case '*': top_operator_prec = 2;
                            break;
                        case '/': top_operator_prec = 2;
                    }

                //CHecking operator precedence
                while((!conversion_stack.empty()) && (conversion_stack.top() != '(') && (cur_operator_prec <= top_operator_prec)){
                    cout << conversion_stack.top();
                    conversion_stack.pop();
                }
                conversion_stack.push(evaluated_str[j]);
            }
        }

        //Finally just printing
        while(!conversion_stack.empty()){
            cout << conversion_stack.top();
            conversion_stack.pop();
        }
        cout << '\n';
    }

    return 0;
}