//
// Created by shao on 2018/10/29.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_BINARYTREE_H
#define ALGORITHMS_AND_DATA_STRUCTURES_BINARYTREE_H

#include <iostream>
#include <queue>
using namespace std;

template <typename Key,typename Value>
class BinaryTree{
private:
    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(Key key,Value value){
            this->key=key;
            this->value=value;
            this->left=this->right= nullptr;
        }
    };
    Node* root;
    int count;
public:
    BinaryTree(){
        root= nullptr;
        count=0;
    }
    ~BinaryTree(){
        destory(root);
    }
    int size(){
        return count;
    }
    int isEmpty(){
        return size()==0;
    }
    void insert(Key key,Value value){
        insert(root,key,value);
    }

    bool contain(Key key){
        contain(root,key);
    }
    Value* search(Key key){
        search(root,key);
    }

    void preOrder(){
        preOrder(root);
    }

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

//    层序遍历
    void levelOrder(){
        queue<Node*> queue1;
        queue1.push(root);
        while (!queue1.empty()){
            Node* node = queue1.front();
            queue1.pop();
            cout<<node->key<<endl;
            if (node->left!=nullptr) {
                queue1.push(node->left);
            }
            if (node->right!= nullptr) {
                queue1.push(node->right);
            }
        }
    }
private:

    void destory(Node* node){
        if (node!=nullptr){
            destory(node->left);
            destory(node->right);
            destory(node);
            count--;
        }
    }

    void preOrder(Node* node){
        if (node!=nullptr) {
            cout << node->key << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node* node){
        if (node!=nullptr) {
            preOrder(node->left);
            cout << node->key << endl;
            preOrder(node->right);
        }
    }

    void postOrder(Node* node){
        if (node!=nullptr) {
            preOrder(node->left);
            cout << node->key << endl;
            preOrder(node->right);
        }
    }

    bool contain(Node* node,Key key){
        if (node == nullptr){
            return false;
        }

        if (node->key == key){
            return true;
        } else if(node->key>key){
            search(node->left,key);
        } else {
            search(node->right, key);
        }
    }

    Value* search(Node* node,Key key){
        if (node == nullptr){
            return nullptr;
        }

        if (node->key == key){
            return &(node->value);
        } else if(node->key>key){
            search(node->left,key);
        } else {
            search(node->right, key);
        }
    }


    Node* insert(Node* node,Key key,Value value){
        if (node== nullptr){
            count++;
            return new Node(key,value);
        }

        if (key == node->key){
            node->value=value;
        } else if(key < node->key){
            insert(node->left,key,value);
        } else{
            insert(node->right,key,value);
        }
        return node;
    }
};

#endif //ALGORITHMS_AND_DATA_STRUCTURES_BINARYTREE_H
