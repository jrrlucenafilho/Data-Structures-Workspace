#include <iostream>

using std::cin;
using std::cout;

class bin_tree_node
{
    private:
        bin_tree_node* left_node_ptr;
        bin_tree_node* right_node_ptr;
        int content;

    public:
        bin_tree_node();
        ~bin_tree_node();

        bin_tree_node* get_left_node();
        bin_tree_node* get_right_node();
        int get_content();

        void set_left_node(bin_tree_node* new_left_node);
        void set_right_node(bin_tree_node* new_right_node);
        void set_content(int new_content);
};

bin_tree_node::bin_tree_node()
{
    right_node_ptr = NULL;
    left_node_ptr = NULL;
}

bin_tree_node::~bin_tree_node()
{
    delete right_node_ptr;
    delete left_node_ptr;
}

bin_tree_node* bin_tree_node::get_left_node()
{
    return left_node_ptr;
}

bin_tree_node* bin_tree_node::get_right_node()
{
    return right_node_ptr;
}

int bin_tree_node::get_content()
{
    return content;
}

void bin_tree_node::set_left_node(bin_tree_node* new_left_node)
{
    left_node_ptr = new_left_node;
}

void bin_tree_node::set_right_node(bin_tree_node* new_right_node)
{
    right_node_ptr = new_right_node;
}

void bin_tree_node::set_content(int new_content)
{
    content = new_content;
}


class bin_search_tree
{
    private:
        bin_tree_node* node;
        bin_tree_node* root;
    
    public:
        bin_search_tree();
        ~bin_search_tree();
       
       bin_tree_node* get_node();
       void set_node(bin_tree_node* new_node);

       bin_tree_node* get_root_node();
       void set_root_node(bin_tree_node* new_root_node);

        bool isEmpty();
        void print_inorder();
        void inorder(bin_tree_node* b_tree_node);
        void print_preorder();
        void preorder(bin_tree_node* b_tree_node);
        void print_postorder();
        void postorder(bin_tree_node* b_tree_node);
        void insert(int new_value);
};

bin_search_tree::bin_search_tree()
{
    root = NULL;
    node = NULL;
}

bin_search_tree::~bin_search_tree()
{
    delete root;
    delete node;
}

bin_tree_node* bin_search_tree::get_node()
{
    return node;
}

void bin_search_tree::set_node(bin_tree_node* new_node)
{
    node = new_node;
}

bin_tree_node* bin_search_tree::get_root_node()
{
    return root;
}

void bin_search_tree::set_root_node(bin_tree_node* new_root_node)
{
    root = new_root_node;
}

bool bin_search_tree::isEmpty()
{
    return root == NULL;    //Auto true/false
}

void bin_search_tree::insert(int new_value)
{
    bin_tree_node* b_tree_node = new bin_tree_node();
    bin_tree_node* parent_node;

    b_tree_node->set_content(new_value);
    parent_node = NULL;
    
    if(isEmpty()){
        root = b_tree_node;
    }else{
        bin_tree_node* current_node;
        current_node = root;

        while(current_node)
        {
            parent_node = current_node;
            if(b_tree_node->get_content() > current_node->get_content()){
                current_node = current_node->get_right_node();
            }else{
                current_node = current_node->get_left_node();
            }
        }

        if(b_tree_node->get_content() < parent_node->get_content()){
           parent_node->set_left_node(b_tree_node);
        }else{
           parent_node->set_right_node(b_tree_node);
        }
    }
}

void bin_search_tree::print_inorder()
{
  inorder(root);
}

void bin_search_tree::inorder(bin_tree_node* b_tree_node)
{
    if(b_tree_node != NULL)
    {
        if(b_tree_node->get_left_node()){
            inorder(b_tree_node->get_left_node());
        }
        cout << ' ' << b_tree_node->get_content();

        if(b_tree_node->get_right_node()){
            inorder(b_tree_node->get_right_node());
        }
    }else{
        return;
    }
}
void bin_search_tree::print_preorder()
{
    preorder(root);
}

void bin_search_tree::preorder(bin_tree_node* b_tree_node)
{
    
    if(b_tree_node != NULL)
    {
        cout << ' ' << b_tree_node->get_content();

        if(b_tree_node->get_left_node()){
            preorder(b_tree_node->get_left_node());
        }

        if(b_tree_node->get_right_node()){
            preorder(b_tree_node->get_right_node());
        }
    }else{
        return;
    }
}

void bin_search_tree::print_postorder()
{
    postorder(root);
}

void bin_search_tree::postorder(bin_tree_node* b_tree_node)
{
    if(b_tree_node != NULL)
    {
        if(b_tree_node->get_left_node()){
            postorder(b_tree_node->get_left_node());
        }

        if(b_tree_node->get_right_node()){
            postorder(b_tree_node->get_right_node());
        }

        cout << ' ' << b_tree_node->get_content();
    }else{
        return;
    }
}

int main(void)
{
    int test_quant, tree_element_quant, inserted_num;
    int i;
    
    cin >> test_quant;
    
    for(i = 0; i < test_quant; i++){
          cin >> tree_element_quant;

          bin_search_tree bin_search_tree;

          while(tree_element_quant--){
            cin >> inserted_num;
            bin_search_tree.insert(inserted_num);
          }

          cout << "Case " << i + 1 << ":\n";
          cout << "Pre.:";
          bin_search_tree.print_preorder();
          cout << "\nIn..:";
          bin_search_tree.print_inorder();
          cout << "\nPost:";
          bin_search_tree.print_postorder();
          cout << "\n\n";
    }

    return 0;
}