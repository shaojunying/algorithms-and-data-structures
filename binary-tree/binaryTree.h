//
// Created by shao on 2018/10/29.
//

#ifndef ALGORITHMS_AND_DATA_STRUCTURES_BINARYTREE_H
#define ALGORITHMS_AND_DATA_STRUCTURES_BINARYTREE_H

#include <iostream>
#include <queue>
#include <assert.h>

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
        Node(Node* node){
            this->key=node->left;
            this->value=node->value;
            this->left=node->value;
            this->right=node->right;
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

//    查找最小值
    Key findMin(){
        assert(count>0);
        Node* node = findMin(root);
        return node->key;
    }

    /*
     * 查找最大值
     * return: 最大值对应的key值
     * */
    Key findMax(){
        assert(count>0);
        Node* node = findMax(root);
        return node->key;
    }

    /*
     * 删除最小值
     * */
    void removeMin(){
        assert(count>0);
        root = removeMin(root);
    }


    void removeMax(){
        assert(count>0);
        root = removeMax(root);
    }

    void remove(Key key){
        remove(root,key);
    }

    /*
     * 找出当前节点的后继结点
     * */
    Key* findSuccessor(Key key){
        /*找到key值对应的节点*/
        Node* node = search(key);
        if (node == nullptr){
            /*说明不存在key对应的节点*/
            return nullptr;
        } else if (node->right==nullptr){
            /* node没有右节点
             * 说明该节点的后继节点在从root到node之间的路径上*/
            return &(findSuccessorFromAncestor(root,key)->key);
        } else{
            /*有右子树,说明后继结点为右子树的最小值*/
            Node* resultNode = findMin(node->right);
            return resultNode== nullptr?nullptr:&(resultNode->key);
        }
    }


    /*
     * 找出当前节点的前驱结点
     * */
    Key* findPredecessor(Key key){
        /*找到key值对应的节点*/
        Node* node = search(key);
        if (node == nullptr){
            /*说明不存在key对应的节点*/
            return nullptr;
        } else if (node->left==nullptr){
            /* node没有右节点
             * 说明该节点的后继节点在从root到node之间的路径上*/
            return &(findPredecessorFromAncestor(root,key)->key);
        } else{
            /*有右子树,说明后继结点为右子树的最小值*/
            Node* resultNode = findMax(node->left);
            return resultNode== nullptr?nullptr:&(resultNode->key);
        }
    }

    /*
     * floor函数,寻找二叉树中小于key值的最大节点
     * */

    Key* floor(Key key){
        if (count<1||key<findMin()){
            /*如果目标key小于树中任意一个节点,那么结果一定不存在,返回null*/
            return nullptr;
        }

        Node* resultNode = floor(root,key);
        if (resultNode == nullptr){
            return nullptr;
        }
        return &(resultNode->key);
    }

    /*
     * ceil函数,寻找二叉树中大于key值的最小节点
     * */

    Key* ceil(Key key){
        if (count<1||key>findMax()){
            return nullptr;
        }

        Node* resultNode = ceil(root,key);
        if (resultNode == nullptr){
            return nullptr;
        }
        return &(resultNode->key);
    }


private:

    Node* ceil(Node* node,Key key){

        if (node == nullptr){
            return nullptr;
        }

        if (node->key == key){
            return node;
        } else if(node->key > key){
            Node* currNode = node;
            node = ceil(node->left,key);
            if (node == nullptr){
                return currNode;
            }
            return node;
        } else{
            return floor(node->right,key);
        }
    }
    
    /*要求的是当前节点node里面比key小的值中的最大值*/
    Node* floor(Node* node,Key key){

        if (node == nullptr){
            /*到达根节点,直接返回null*/
            return nullptr;
        }

        if (node->key == key){
            /*当前节点的值和目标的值相等,直接返回当前节点*/
            return node;
        } else if(node->key < key){
            /*当前节点的key值小于目标值,那么当前节点
             * 说明当前节点可能就是目标值*/
            Node* currNode = node;
            node = floor(node->right,key);
            if (node == nullptr){
                return currNode;
            }
            return node;
        } else{
            /*当前节点的目标值太大,不满足,需要判断左节点*/
            return floor(node->left,key);
        }
    }

    Node* findPredecessorFromAncestor(Node* node,Key key){
        /*如果当前节点的key值即为目标值,返回null*/
        if (node->key == key){
            return nullptr;
        }

        if (node->key>key){
            return findSuccessorFromAncestor(node->left,key);
        } else{
            Node* curNode = node;
            node = findSuccessorFromAncestor(node->right,key);
            if (node== nullptr){
                return curNode;
            }
            return node;
        }
    }

    Node* findSuccessorFromAncestor(Node* node,Key key){
        /*如果当前节点的key值即为目标值,返回null*/
        if (node->key == key){
            return nullptr;
        }

        if (node->key<key){
            /*当前节点的值小于目标key,所以直接找当前节点的右子树即可*/
            return findSuccessorFromAncestor(node->right,key);
        } else{
            /*节点的key大于目标key,有可能就是目标的后继结点*/
            Node* curNode = node;
            node = findSuccessorFromAncestor(node->left,key);
            if (node== nullptr){
                return curNode;
            }
            return node;
        }
    }

    Node* remove(Node* node, Key key){
//        当前节点为空，说明不存在key值为key的节点
        if (node == nullptr){
            return nullptr;
        }

//      要找的key值只有可能在左子树上
        if (node->key > key){
            node->left = remove(node->left,key);
        } else if(node->key < key){
            node->right = remove(node->right,key);
        } else{
//            找到了key对应的节点
            if (node->left == nullptr){
//                左子树为空
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            } else if (node->right == nullptr){
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            } else{
//                左右子树都不为空
//                记录要删除的节点
                Node* delNode = node;
//                找到右子树对应的最小值深拷贝存储起来
                Node* rightMinNode = new Node(findMin(delNode->right));
                count++;
//                删除右子树的最小节点
                rightMinNode->right = removeMin(delNode->right);
//                将新节点的左右孩子分别指向被删除节点左右子树
                rightMinNode->left=delNode->left;

                delete delNode;
                count--;
//                返回
                return rightMinNode;
            }
        }

    }


    /*
     * 删除以node为根的树的最小值
     * return: 当前的根节点
     * */
    Node* removeMin(Node* node){
        if (node->left==nullptr){
            Node* leftNode = node->right;
            delete node;
            count--;
            return leftNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node* removeMax(Node* node){
        if (node->right==nullptr){
            Node* rightNode = node->left;
            delete node;
            count--;
            return rightNode;
        }
        node->right = removeMin(node->right);
        return node;
    }

    /*
     * 返回最小值对应的节点地址
     * */
    Node* findMin(Node* node){
        assert(node!= nullptr);
        if (node->left==nullptr){
            return node;
        }
        return findMin(node->left);
    }


    Node* findMax(Node* node){
        assert(node!=nullptr);
        if (node->right==nullptr){
            return node;
        }
        return findMax(node->right);
    }

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

    Node* search(Node* node,Key key){
        if (node == nullptr){
            return nullptr;
        }

        if (node->key == key){
            return node;
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
