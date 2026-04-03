// #include<iostream>
// using namespace std;  
// class Node{
//     public :
//     int val;
//     Node *left , *right;

//      Node(int v){
//         val = v;
//         left = NULL;
//         right = NULL;
//     }
// };
// class BST{
//     public:
//     Node* insert(Node*root , int v){
//         if(!root)
//         return new Node(v);

//         else if(root->val > v)
//         root->left = insert(root->left,v);
//         else
//         root->right = insert(root->right,v);

//         return root;
//     }

//     void display_inorder(Node*root){
//         if(!root)
//         return;
//         display_inorder(root->left);
//         cout<<root->val<<" ";
//         display_inorder(root->right);
//     }
// };
// int main(){
//     BST T1;
//     Node *root = NULL;
//     root = T1.insert(root,8);
//     root = T1.insert(root,5);
//     root = T1.insert(root,3);
//     root = T1.insert(root,6);
//     root = T1.insert(root,10);
//     root = T1.insert(root,9);
//     root = T1.insert(root,13);
//     root = T1.insert(root,11);
//     root = T1.insert(root,14);

//     T1.display_inorder(root);

//     return 0;
// }

//Best Approach for implementing : 
#include<iostream>
using namespace std;  
class Node{
    public :
    int val;
    Node *left , *right;

     Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};
class BST{
    private :
    Node* root;
    Node* insert(Node*root , int v){
        if(!root)
        return new Node(v);

        else if(root->val > v)
        root->left = insert(root->left,v);
        else
        root->right = insert(root->right,v);

        return root;
    }

    //Inorder Traversal
    void display_inorder(Node*root){
        if(!root)
        return;
        display_inorder(root->left);
        cout<<root->val<<" ";
        display_inorder(root->right);
    }
    bool search(Node *root,int target){
        if(!root)
        return 0;
        if(root->val == target)
        return 1;
        else if(root->val > target)
        return search(root->left,target);
        else
        return search(root->right,target);

        return 0;
    }
    Node* delete_Node(Node *root, int key){
        //Search KEY first then we can Delete
        //root not present
        if(!root)
        return NULL;
        else if(root->val > key){
             root->left = delete_Node(root->left,key);
             return root;
        }
        else if(root->val <key){
            root->right = delete_Node(root->right,key);
            return root;
        }
        else{
        //leaf node
        if(!root->left && !root->right){
        delete root;
        return NULL;
        }
        //only left child exist
        else if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //only right child exist
        else if(!root->left){
            Node *temp = root->right;
            delete root;
            return temp;
        }

        //Both child Exists
        //finding greatest in left (or we can find smallest in right)
        Node* child = root->left;
        Node* parent = root;
        //Right most Node tak pahuchna hai
        while(child->right){
            parent = child;
            child = child->right;
        }

        //delete root
        if(parent != root){
            parent->right = child->left;
            child->left = root->left;
            child->right = root->right;
            delete root;
            return child;
        }
        else{
            child->right = root->right;
            delete root;
            return child;
        }
    }
    }
    public :
    BST(){
        root = NULL;
    }
    void insert(int v){
         root = insert(root,v);
        }
    void display_inorder(){
        display_inorder(root);
    }
    bool search(int target){
       return search(root,target);
    }
    void delete_Node(int key){
       root = delete_Node(root,key);
    }
};
int main(){
    BST T1;
    T1.insert(8);
    T1.insert(5);
    T1.insert(3);
    T1.insert(6);
    T1.insert(10);
    T1.insert(9);
    T1.insert(13);
    T1.insert(11);
    T1.insert(14);
    T1.delete_Node(11);

    T1.display_inorder();

    cout<<"\n"<<T1.search(10);
    return 0;
}
