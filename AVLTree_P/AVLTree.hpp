//
// Created by 区彦成 on 2017-01-08.
//

#ifndef AVLTREE_P_AVLTREE_HPP
#define AVLTREE_P_AVLTREE_HPP
#include <stdarg.h>
#include <queue>
#include <deque>
template <typename K, typename V>
class AVLTree {
private:
    struct node {
        K key;
        V value;

        int height;

        node *parent;
        node *lchild;
        node *rchild;

        node(const K &key, const V &value, node *const &parent) :
                key(key), value(value), height(1), parent(parent), lchild(nullptr), rchild(nullptr) {

        }
    };

    node *root;
    size_t count;

private:
    void copyTree(const node *src, node *&dest, node *destParent) {
        if (src != nullptr) {
            dest = new node (src->key, src->value, destParent);
            dest->height = src->height;
            copyTree(src->lchild, dest->lchild, dest);
            copyTree(src->rchild, dest->rchild, dest);
        }
    }

    void deleteTree(node *p) {
        if (p != nullptr) {
            deleteTree(p->lchild);
            deleteTree(p->rchild);
            delete p;
        }
    }

public:
    AVLTree() : root(nullptr), count(0) {

    }

    AVLTree(const AVLTree<K, V> &another) {
        copyTree(another.root, this->root, nullptr);
        this->count = another.count;
    }

    ~AVLTree() {
        deleteTree(root);
    }

    AVLTree & operator = (const AVLTree<K, V> &another) {
        deleteTree(this->root);
        this->root = nullptr;
        copyTree(another.root, this->root, nullptr);
        this->count = another.count;
        return *this;
    }

    void swapWith(AVLTree<K, V> &another) {
        node *p = this->root;
        this->root = another.root;
        another.root = p;
        size_t temp = another.count;
        another.count = this->count;
        this->count = temp;
    }

private:
    template <typename FP>
    void inOrderTraverseCore(node *p, FP fPointer) const {
        if (p != nullptr) {
            inOrderTraverseCore(p->lchild, fPointer);
            (fPointer)(p->key, p->value);
            inOrderTraverseCore(p->rchild, fPointer);
        }
    }

    template <typename FP>
    void preOrderTraverseCore(node *p, FP fPointer) const {
        if (p != nullptr) {
            (fPointer)(p->key, p->value);
            preOrderTraverseCore(p->lchild, fPointer);
            preOrderTraverseCore(p->rchild, fPointer);
        }
    }

    template <typename FP>
    void postOrderTraverseCore(node *p, FP fPointer) const {
        if (p != nullptr) {
            postOrderTraverseCore(p->lchild, fPointer);
            postOrderTraverseCore(p->rchild, fPointer);
            (fPointer)(p->key, p->value);
        }
    }

    template <typename FP>
    void layerOrderTraverseCore(node *p, FP fPointer) const {
        if (p == nullptr)
            return;
        std::deque<node *> q;
        //std::queue<node *> q;
        q.push_front(p);
        //q.push(p);
        node *tempPtr = p;
        while (!q.empty()) {
            tempPtr = q.back();
            //tempPtr = q.front();
            q.pop_back();
            //q.pop();
            if (tempPtr->lchild != nullptr)
                q.push_front(tempPtr->lchild);
                //q.push(tempPtr->lchild);
            if (tempPtr->rchild != nullptr)
                q.push_front(tempPtr->rchild);
                //q.push(tempPtr->rchild);
            (fPointer)(tempPtr->key, tempPtr->value);
        }

        std::queue<node *> Q;
    }

public:
    template <typename FP>
    void inOrderTraverse(FP fPointer) const {
        inOrderTraverseCore(root, fPointer);
    }

    template <typename FP>
    void preOrderTraverse(FP fPointer) const {
        preOrderTraverseCore(root, fPointer);
    }

    template <typename FP>
    void postOrderTraverse(FP fPointer) const {
        postOrderTraverseCore(root, fPointer);
    }

    template <typename FP>
    void layerOrderTraverse(FP fPointer) const {
        layerOrderTraverseCore(root, fPointer);
    }

    template <typename FP>
    void inOrderTraverse_NR(FP fPointer) const {
        node *p = root;
        std::deque<node *> stack;
        while (p != nullptr || !stack.empty()) {
            while (p != nullptr) {
                stack.push_back(p);
                p = p->lchild;
            }
            if (!stack.empty()) {
                p = stack.back();
                (fPointer)(p->key, p->value);
                stack.pop_back();
                p = p->rchild;
            }
        }
    }

private:
    inline int max(int a, int b) {
        return (a < b) ? (b) : (a);
    }

    int getHeight(node *p) {
        if (p == nullptr)
            return 0;
        else if (p->lchild != nullptr && p->rchild != nullptr)
            return max(p->lchild->height, p->rchild->height) + 1;
        else if (p->lchild == nullptr && p->rchild == nullptr)
            return 1;
        else
            return (p->lchild == nullptr) ? (p->rchild->height + 1) : (p->lchild->height + 1);
    }

    void L_Rotate(node *&p) {
        node *temp = p;
        p->rchild->parent = p->parent;
        p = p->rchild;
        if (p->lchild != nullptr)
            p->lchild->parent = temp;
        temp->rchild = p->lchild;
        p->lchild = temp;
        temp->parent = p;
        p->height = getHeight(p);
        temp->height = getHeight(temp);
    }

    void R_Rotate(node *&p) {
        node *temp = p;
        p->lchild->parent = p->parent;
        p = p->lchild;
        if (p->rchild != nullptr)
            p->rchild->parent = temp;
        temp->lchild = p->rchild;
        p->rchild = temp;
        temp->parent = p;
        p->height = getHeight(p);
        temp->height = getHeight(temp);
    }

    void LR_Rotate(node *&p) {
        L_Rotate(p->lchild);
        R_Rotate(p);
    }

    void RL_Rotate(node *&p) {
        R_Rotate(p->rchild);
        L_Rotate(p);
    }

    void refreshHeight(node *p) {
        node *tempPtr = p;
        node *temp;
        while (tempPtr != nullptr) {
            if (getHeight(tempPtr->lchild) - getHeight(tempPtr->rchild) >= 2) {
                temp = tempPtr->lchild;
                if (getHeight(temp->lchild) > getHeight(temp->rchild)) {
                    //LL
                    //rotate(tempPtr, (this->R_Rotate));
                    if (tempPtr->parent == nullptr)
                        R_Rotate(root);
                    else
                        R_Rotate((tempPtr == tempPtr->parent->lchild) ?
                                 (tempPtr->parent->lchild) :
                                 (tempPtr->parent->rchild));
                    break;
                } else {
                    //LR
                    //rotate(tempPtr, this->LR_Rotate);
                    if (tempPtr->parent == nullptr)
                        LR_Rotate(root);
                    else
                        LR_Rotate((tempPtr == tempPtr->parent->lchild) ?
                                  (tempPtr->parent->lchild) :
                                  (tempPtr->parent->rchild));
                    break;
                }
            } else if (getHeight(tempPtr->rchild) - getHeight(tempPtr->lchild) >= 2) {
                temp = tempPtr->rchild;
                if (getHeight(temp->rchild) > getHeight(temp->lchild)) {
                    //RR
                    //rotate(tempPtr, this->L_Rotate);
                    if (tempPtr->parent == nullptr)
                        L_Rotate(root);
                    else
                        L_Rotate((tempPtr == tempPtr->parent->lchild) ?
                                 (tempPtr->parent->lchild) :
                                 (tempPtr->parent->rchild));
                    break;
                } else {
                    //RL
                    //rotate(tempPtr, this->RL_Rotate);
                    if (tempPtr->parent == nullptr)
                        RL_Rotate(root);
                    else
                        RL_Rotate((tempPtr == tempPtr->parent->lchild) ?
                                  (tempPtr->parent->lchild) :
                                  (tempPtr->parent->rchild));
                    break;
                }
            } else if (getHeight(tempPtr->rchild) == getHeight(tempPtr->lchild)) {
                //tempPtr->height = getHeight(tempPtr);
                break;
            } else {
                tempPtr->height = getHeight(tempPtr);
            }
            tempPtr = tempPtr->parent;
        }
    }

    void removeLeaf(node *&p) {
        node *temp = p;
        node *parent = p->parent;
        //p = (p->lchild == nullptr) ? (p->rchild) : (p->lchild);
        if (p->lchild != nullptr) {
            p = p->lchild;
            p->parent = parent;
        } else if (p->rchild != nullptr) {
            p = p->rchild;
            p->parent = parent;
        } else {
            p = nullptr;
        }
        delete temp;
        refreshHeight(parent);
    }

    void removeNonLeaf(node *&p) {
        node **temp = &p;
        if (getHeight(p->lchild) > getHeight(p->rchild)) {
            temp = &(p->lchild);
            while ((*temp)->rchild != nullptr)
                temp = &((*temp)->rchild);
        } else {
            temp = &(p->rchild);
            while ((*temp)->lchild != nullptr)
                temp = &((*temp)->lchild);
        }
        swap(p, (*temp));
        removeLeaf(*temp);
    }

    void swap(node *p, node *q) {
        K key = p->key;
        p->key = q->key;
        q->key = key;
        V value = p->value;
        p->value = q->value;
        q->value = value;
    }


public:
    void insert(K key, V value) {
        if (root == nullptr) {
            root = new node(key, value, nullptr);
            ++count;
            return;
        } else {
            node **pPointer = &root;
            node *pParent = nullptr;
            while ((*pPointer) != nullptr) {
                if ((*pPointer)->key == key) {
                    (*pPointer)->value = value;
                    return;
                }
                pParent = (*pPointer);
                pPointer = (key < (*pPointer)->key) ? (&((*pPointer)->lchild)) : (&((*pPointer)->rchild));
            }
            (*pPointer) = new node(key, value, pParent);
            ++count;
            refreshHeight((*pPointer)->parent);
        }
    }

    bool remove(K key) {
        node **pPointer = &root;
        while ((*pPointer) != nullptr) {
            if ((*pPointer)->key == key)
                break;
            pPointer = (key < (*pPointer)->key) ? (&((*pPointer)->lchild)) : (&((*pPointer)->rchild));
        }
        if ((*pPointer) == nullptr)
            return false;
        else if ((*pPointer)->lchild != nullptr && (*pPointer)->rchild != nullptr)
            removeNonLeaf(*pPointer);
        else
            removeLeaf(*pPointer);
        --count;
        return true;
    }

    V & find(const K &key) {
        node **p = &root;
        node *parent = nullptr;
        while ((*p) != nullptr) {
            if (key == (*p)->key)
                return (*p)->value;
            parent = (*p);
            p = (key < (*p)->key) ? (&((*p)->lchild)) : (&((*p)->rchild));
        }
        //this->insert(key, V());
        (*p) = new node(key, V(), parent);
        ++count;
        node *temp = (*p);
        refreshHeight((*p)->parent);
        return temp->value;
    }

    V & operator [](const K &key) {
        return find(key);
    }

    void clear() {
        deleteTree(root);
        root = nullptr;
    }

    bool isEmpty() {
        return (root == nullptr);
    }

    size_t size() {
        return count;
    }

};


#endif //AVLTREE_P_AVLTREE_HPP


/*void L_Rotate_r(node *&p) {
     node *temp = p;
     p->rchild->parent = p->parent;
     p = p->rchild;
     p->lchild->parent = temp;
     temp->rchild = p->lchild;
     p->lchild = temp;
     temp->parent = p;
     p->height = getHeight(p);
     temp->height = getHeight(temp);
 }

 void R_Rotate_r(node *&p) {
     node *temp = p;
     p->lchild->parent = p->parent;
     p = p->lchild;
     p->rchild->parent = temp;
     temp->lchild = p->rchild;
     p->rchild = temp;
     temp->parent = p;
     p->height = getHeight(p);
     temp->height = getHeight(temp);
 }

 void LR_Rotate_r(node *&p) {
     L_Rotate_r(p->lchild);
     R_Rotate_r(p);
 }

 void RL_Rotate_r(node *&p) {
     R_Rotate_r(p->rchild);
     L_Rotate_r(p);
 }*/

/*void rotate(node *&p, void (AVLTree::*rotation)(node *&)) {
    if (p->parent == nullptr) {
        (*rotation)(root);
    } else {
        (this->*rotation)(
                (p == p->parent->lchild) ? (p->parent->lchild) : (p->parent->rchild)
        );
    }
}*/
