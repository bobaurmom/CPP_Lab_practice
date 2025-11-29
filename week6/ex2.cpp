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
    Tree(int root_data = -1) : root(nullptr) {
        if (root_data != -1) {
            root = new Node(root_data);
        }
    }
    ~Tree() {
        deleteTree(root);
    }
    void insert(int val) {
        if ( root == nullptr) {
            root = new Node(val);
            return;
        }else{

            Node* current = root;
            Node* parent = nullptr;
            while (current != nullptr) {
                parent = current;
                if (val < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (val < parent->data) {
                parent->left = new Node(val);
            } else {
                parent->right = new Node(val);
            }
        }
    }
    
    void inOrder( Node * root){
        if(root!=nullptr){
            inOrder(root->left);
            cout<<root->data;
            inOrder(root->right); 
        }
    }
    void add(int val){
        root  = new Node(val);
        
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

    my_tree.insert(50);
    my_tree.insert(17);
    my_tree.insert(72);
    my_tree.insert(90);
    my_tree.insert(90);
    cout << "Root is" << my_tree.root->data << endl;
    cout<<my_tree.root->left->data<<endl;
    cout<< my_tree.root->right->data<<endl;


     
    return 0;
}
