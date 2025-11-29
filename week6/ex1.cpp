#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Tree {
public:
    Node* root;
    int size;
    Tree(int root_data = -1) {
         root = nullptr;
        if (root_data != -1) {
            root = new Node(root_data);
        }
    }
    ~Tree() {
        deleteTree(root);
    }
    
    void buildTree() {
        

    }
    void pre_order(Node * root){ 
        if (root == nullptr) {
            return;
        }else {
            cout << root-> data<<endl;
            pre_order(root->left);
            pre_order(root->right);            
        }
    }
private:
    void deleteTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node; 
    }
};

int main() {
    Tree my_tree;

    my_tree.buildTree();
    my_tree.pre_order(my_tree.root);


    
    return 0;
}
