#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::map;

map<char, int> aux_map;

typedef struct bin_tree_node
{
    char content;
    struct bin_tree_node* right_node_ptr;
    struct bin_tree_node* left_node_ptr;
} bin_tree_t;

void get_position(bin_tree_t* bin_tree_node)
{
    if(!bin_tree_node){
        return;
    }
    get_position(bin_tree_node->left_node_ptr);
    get_position(bin_tree_node->right_node_ptr);

    cout << bin_tree_node->content;
}

bin_tree_t* insert_element(bin_tree_t* bin_tree_node, char content)
{
    //Empty tree check, actually fill root node
    if(!bin_tree_node){
        bin_tree_node = (bin_tree_t*)malloc(sizeof(bin_tree_t));
        bin_tree_node->content = content;
        bin_tree_node->right_node_ptr = NULL;
        bin_tree_node->left_node_ptr = NULL;
    }else{
        if(aux_map[bin_tree_node->content] < aux_map[content]){
            bin_tree_node->right_node_ptr = insert_element(bin_tree_node->right_node_ptr, content);
        }else{
            bin_tree_node->left_node_ptr = insert_element(bin_tree_node->left_node_ptr, content);
        }
    }

    return bin_tree_node;
}

bin_tree_t* remove_element(bin_tree_t* bin_tree_node)
{
    if(!bin_tree_node){
        return NULL;
    }

    //Recursively removes nodes
    remove_element(bin_tree_node->left_node_ptr);
    remove_element(bin_tree_node->right_node_ptr);

    //Clearing mem
    free(bin_tree_node);
    bin_tree_node = NULL;

    return bin_tree_node;
}

int main(void)
{
    int test_quant, node_quant, i;
    char str1[53];
    char str2[53];
    bin_tree_t* bin_tree_node;

    cin >> test_quant;

    while(test_quant--){
        bin_tree_node = NULL;
        cin >> node_quant >> str1 >> str2;
        
        for(i = 0; i < node_quant; i++){
            aux_map[str2[i]] = i;
        }

        for(i = 0 ; i < node_quant; i++){
            bin_tree_node = insert_element(bin_tree_node, str1[i]);
        }

        get_position(bin_tree_node);
        cout << '\n';

        //Deferences and clears for next case
        remove_element(bin_tree_node);
        aux_map.clear();
        bin_tree_node = NULL;
    }
}