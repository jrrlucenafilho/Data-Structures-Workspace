#include <iostream>
#include <string>
#include <queue>

using std::cin;
using std::cout;
using std::string;
using std::queue;

class node
{
    public:
        node();
        virtual ~node();

        char get_content();
        node* get_left_node();
        node* get_right_node();

        void set_content(int new_content);
        void set_left_node(node* new_left_node);
        void set_right_node(node* new_right_node);

    private:
        char content;
        node* left_node;
        node* right_node;
};


node::node()
{
    left_node = nullptr;
    right_node = nullptr;
    content = ' ';
}

node::~node()
{
    delete left_node;
    delete right_node;
    content = ' ';
}

char node::get_content()
{
    return content;
}

node* node::get_left_node()
{
    return left_node;
}

node* node::get_right_node()
{
    return right_node;
}

void node::set_content(int new_content)
{
    content = new_content;
}

void node::set_left_node(node* new_left_node)
{
    left_node = new_left_node;
}

void node::set_right_node(node* new_right_node)
{
    right_node = new_right_node;
}


class binary_tree
{
    public:
        binary_tree();
        virtual ~binary_tree();

        node* get_root();

        void set_root(node* new_root);

        node* insert_node(string str, int begin, int end);
        void print_tree_row(queue<node*> row_queue, int curr_level);
        void print_tree();

    private:
        node* root;
};

binary_tree::binary_tree()
{
    root = nullptr;
}

binary_tree::~binary_tree()
{
    delete root;
}

node* binary_tree::get_root()
{
    return root;
}

void binary_tree::set_root(node* new_root)
{
    root = new_root;
}

node* binary_tree::insert_node(string str, int begin, int end)
{
    int counter = 0;
    int counter_parent = 0;
    int sep = 0;
    char curr_chosen_char = ' ';

    node* aux_node = new node();

    if(begin == end){
        //No need to nullptr since constr does it
        aux_node->set_content(str[begin]);
    }else{
        if((str[begin] == '(') && (str[end] == ')')){
            aux_node = insert_node(str, begin+1, end-1);
        }else{
            for(counter = begin; counter <= end; counter++){
                if(str[counter] == '('){
                    counter_parent++;
                }else if(str[counter] == ')'){
                    counter_parent--;
                }else if(str[counter] == '+' || str[counter] == '-'){
                    if(counter_parent == 0){
                        sep = counter;
                        curr_chosen_char = str[counter];
                    }
                }else if(str[counter] == '/' || str[counter] == '*'){
                    if(counter_parent == 0 && (curr_chosen_char != '+' && curr_chosen_char != '-')){
                        sep = counter;
                        curr_chosen_char = str[counter];
                    }
                }
            }

            aux_node->set_content(curr_chosen_char);
            aux_node->set_left_node(insert_node(str, begin, sep - 1));
            aux_node->set_right_node(insert_node(str, sep + 1, end));
        }
    }

    return aux_node;
}

void binary_tree::print_tree_row(queue<node*> row_queue, int curr_level)
{
    queue<node*> aux_queue;

    if(row_queue.empty()){
        return;
    }else{
        cout << "Nivel " << curr_level << ": ";
        
        while(!row_queue.empty()){
            cout << row_queue.front()->get_content();

            if(row_queue.front()->get_left_node() != nullptr){
                aux_queue.push(row_queue.front()->get_left_node());
            }

            if(row_queue.front()->get_right_node() != nullptr){
                aux_queue.push(row_queue.front()->get_right_node());
            }

            row_queue.pop();
        }
        cout << '\n';
        print_tree_row(aux_queue, curr_level + 1);
    }
}

void binary_tree::print_tree()
{
    queue<node*> aux_queue;

    aux_queue.push(get_root());
    print_tree_row(aux_queue, 0);
}

string strip_string(string str)
{
    string return_str;

    for(size_t i = 0; i < str.size(); i++){
        if(str[i] != ' '){
            return_str += str[i];
        }
    }

    return return_str;
}

int main(void)
{
    string expression;
    binary_tree* bin_tree = new binary_tree();

    while(!cin.eof()){
        getline(cin, expression);

        expression = strip_string(expression);

        bin_tree->set_root(bin_tree->insert_node(expression, 0, expression.length()-1));

        bin_tree->print_tree();
    }

    cout << '\n';

    return 0;
}
