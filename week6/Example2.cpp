#include <iostream>
#include <string>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Tree{
    private:
    Node* root;
    public:
    Tree(){
        root = nullptr;
    }
    Node* insert(Node* node, int data){
        if(node == nullptr){
            return new Node(data);
        }
        else if(data < node->data){
            node->left = insert(node->left, data);
        }
        else if(data > node->data){
            node->right = insert(node->right, data);
        }
        return node;
    }

    void inOrder(Node* root){
        if(root != nullptr){
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }
    void displayInOrder(){
        inOrder(root);
        cout<<endl;
    }
    void displayOrder(){
        inOrder(root);
        cout << endl;
    }
    void add(int value){
        root = insert(root, value);
    }
    void preOrder(Node* root){
        if(root != nullptr){
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void displayPreOrder(){
        preOrder(root);
        cout << endl;
    }
    void postOrder(Node* root){
        if(root != nullptr){
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }
    }
    void displayPostorder(){
        postOrder(root);
        cout <<endl;
    }
    

};

int main(){
    Tree tree;
    tree.add(50);

    tree.add(17);
    tree.add(72);

    tree.add(12); 
    tree.add(23);
    tree.add(54);
    tree.add(76);

    tree.add(67);
    tree.add(14);
    tree.add(9);
    tree.add(19);

    tree.displayOrder();
    tree.displayPreOrder();
    tree.displayPostorder();
    tree.displayInOrder();

    return 0;
}