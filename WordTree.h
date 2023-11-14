#include <iostream>
#include <string>
#include <stack>
using namespace std;
        
  
struct WordNode {
    
    WordNode(string s) {
        data = s;
        left = right = nullptr;
        count = 1;
    }
    
    ~WordNode() {
         
    }
    
    string data;
    WordNode *left;
    WordNode *right;
    int count;
};
        
class WordTree {
            
private:
    WordNode *root;
    void postOrderTraversalDelete(WordNode* node) {
        if (node == nullptr) {
            return;
        }

        postOrderTraversalDelete(node->left);

        postOrderTraversalDelete(node->right);
    
        cout << "Deleting " << node->data << endl;
    }
   
public:
               
    WordTree() { 
        root = nullptr; 
    }
    
    ~WordTree() {
        postOrderTraversalDelete(root);
    };
    
    int findOccurrences(string str) {
        WordNode *tmp = root;
        while (tmp != nullptr) {
            if (tmp->data == str) {
                return tmp->count;
            } else if (str < tmp->data) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }
        return 0;
    }

    void add(string str) {
        WordNode *tmp = root;
        for(;;){
            if(tmp==nullptr){
                root = new WordNode(str);
                return;
            }
            else if(tmp->data == str){
                tmp->count++;
                return;
            }
            else if(str< tmp->data){
                if(tmp->left == nullptr){
                    tmp->left = new WordNode(str);
                    return;
                }
                else{
                    tmp = tmp->left;
                }
            }
            else if(str>tmp->data){
                if(tmp->right == nullptr){
                    tmp->right = new WordNode(str);
                    return;
                }
                else{
                    tmp = tmp->right;
                }
            }
        }
    }

    void remove(string str) {
        cout << "Removing " << str << endl;
        WordNode *tmp = root;
        WordNode *parent = nullptr;

        while (tmp != nullptr) {
            if (tmp->data == str) {
                tmp->count--;
                if (tmp->count == 0) {
                    if (tmp->left == nullptr && tmp->right == nullptr) {
                        if (parent == nullptr) {
                            root = nullptr;
                        } else if (parent->left == tmp) {
                            parent->left = nullptr;
                        } else {
                            parent->right = nullptr;
                        }
                        cout << "Deleting " << tmp->data << endl;
                        delete tmp;
                    } else if (tmp->left != nullptr && tmp->right != nullptr) {
                        WordNode *successor = tmp->left;
                        WordNode *successorParent = tmp;

                        while (successor->right != nullptr) {
                            successorParent = successor;
                            successor = successor->right;
                        }

                        successor->right = tmp->right;

                        if (parent == nullptr) {
                            root = successor;
                        } else if (parent->left == tmp) {
                            parent->left = successor;
                        } else {
                            parent->right = successor;
                        }

                        cout << "Deleting " << tmp->data << endl;
                        delete tmp;
                    } else {
                        WordNode *child = (tmp->left != nullptr) ? tmp->left : tmp->right;

                        if (parent == nullptr) {
                            root = child;
                        } else if (parent->left == tmp) {
                            parent->left = child;
                        } else {
                            parent->right = child;
                        }

                        cout << "Deleting " << tmp->data << endl;
                        delete tmp;
                    }
                }
                return;
            } else if (str < tmp->data) {
                parent = tmp;
                tmp = tmp->left;
            } else if (str > tmp->data) {
                parent = tmp;
                tmp = tmp->right;
            }
        }
        cout << str << " not found\n";
    }


    int distinctWords( ) const {
        if(root==nullptr){
            return 0;
        }
        stack<WordNode*> nodeStack;
        nodeStack.push(root);
        int count = 0;
        while(true){
            if(nodeStack.empty()){
                return count;
            }
            WordNode *tmp = nodeStack.top();
            nodeStack.pop();
            count++;
            if(tmp->left!=nullptr){
                nodeStack.push(tmp->left);
            }
            if(tmp->right!=nullptr){
                nodeStack.push(tmp->right);
            }
        }
    }

    int totalWords() const {
        if(root==nullptr){
            return 0;
        }
        stack<WordNode*> nodeStack;
        nodeStack.push(root);
        int count = 0;
        while(true){
            if(nodeStack.empty()){
                return count;
            }
            WordNode *tmp = nodeStack.top();
            nodeStack.pop();
            count += tmp->count;
            if(tmp->left!=nullptr){
                nodeStack.push(tmp->left);
            }
            if(tmp->right!=nullptr){
                nodeStack.push(tmp->right);
            }
        }
    }

    void print() {
        print(root);
    }

    void print(WordNode *tmp) {
        if(tmp==nullptr){
            return;
        }
        else{
            if(tmp->left!=nullptr)
                print(tmp->left);
            cout << endl << tmp->data << "(" << tmp->count << ")";
            if(tmp->right!=nullptr)
                print(tmp->right);
        }
    }

};

