#include <iostream>
#define LH +1   // 左高
#define EH 0   // 等高
#define RH -1   // 右高

using namespace std;

template<class T>
class AVLTree;

// 定义树的结点
template<class T>
class BiTNode {
friend class AVLTree<T>;
private:
    T data;
    int bf;
    BiTNode<T> *lchild, *rchild;
    
public:
    BiTNode() {
        this->lchild = NULL;
        this->rchild = NULL;
    }

    BiTNode(T data, BiTNode<T> *lchild=NULL, BiTNode<T> *rchild=NULL) {
        this->data = data;
        this->lchild = lchild;
        this->rchild = rchild;
    }
};

//平衡二叉树的定义
template<class T>
class AVLTree {
public:
    AVLTree() {
        root = NULL;
    }

    // 1、建树
    void createTree(T *data, int len);

    // 2、中序遍历是升序的序列
    void inorder() {
        inorder(root);
        cout << endl;
        }
    // 3、平衡二叉树的查找过程其实就是二叉排序树的查找过程
    bool searchBST(const T &data) {
        return searchBST(data, root);
    };

    // 4、插入新的元素
    bool insert(const T &data) {
        return insert(data, root, false);
    }
    
    // 5、删除输入元素
    bool deleteBST(const T &data) {
        return deleteBST(data, root);
    }

    // 6、销毁整棵树
    void destroy() {
        destroy(root);
        cout << "整棵树删除完毕" << endl;
    }

private:
    BiTNode<T> *root;
    void R_Rotate(BiTNode<T>* &node);
    void L_Rotate(BiTNode<T>* &node);
    void rightBalance(BiTNode<T>* &node);
    void leftBalance(BiTNode<T>* &node);
    bool insert(const T &data, BiTNode<T>* &node, bool *taller);
    void inorder(BiTNode<T> *current);
    //  BiTNode<T>* &b——以引用传递的方式传入指针，去掉&为以值传递的方式传入指针
    bool searchBST(const T &data, BiTNode<T>* &node);
    bool deleteBST(const T &data, BiTNode<T>* &node);
    void destroy(BiTNode<T>* &node);
};


template<typename T>
void AVLTree<T>::R_Rotate(BiTNode<T>* &node) {
    // L____left_child
    // L是左子树的根结点
    BiTNode<T> *L = node->lchild;
    // L的右子树接成node的左子树
    node->lchild = L->rchild;
    L->rchild = node;
    node = L;
}

template<typename T>
void AVLTree<T>::L_Rotate(BiTNode<T>* &node) {
    // R____right_child
    // R是右子树的根结点
    BiTNode<T> *R = node->rchild;
    // R的左子树接成node的右子树
    node->rchild = R->lchild;
    R->Lchild = node;
    node = R;
}

template<typename T>
void AVLTree<T>::rightBalance(BiTNode<T>* &node) {
    BiTNode<T> *R, *R_lchild;
    R = node->rchild;
    switch (R->bf) {
    // 新插入的结点在右孩子的右子树上，要做单左旋处理
    case RH:
        L_Rotate(node);
        node->bf = L->bf = EH;
        break;
    
    // 新插入的结点在右孩子的左子树上，要做双旋处理
    case LH:
        // 修改BF
        R_lchild = R->lchild;
        switch (R_lchild->bf) {
        case LH:
            node->bf = RH;
            L->bf = EH;
            break;

        case EH:
            node->bf = L->bf = EH;
            break;

        case RH:
            node->bf = EH;
            L->bf = LH;
            break;
        }
    }
    R_lchild->bf = EH;
    // 对node的右子树进行右旋处理，统一和最小不平衡子树根结点的符号
    R_Rotate(node->rchild);
    // 再对整体进行左旋处理
    L_Rotate(node);
}
template<typename T>
void AVLTree<T>::leftBalance(BiTNode<T>* &node) {
    BiTNode<T> *L, *L_rchild;
    L = node->lchild;
    switch (L->bf) {
    // 新插入的结点在左孩子的左子树上，要做单右旋处理
    case LH:
        R_Rotate(node);
        node->bf = L->bf = EH;
        break;
    
    // 新插入的结点在左孩子的右子树上，要做双旋处理
    case RH:
        // 修改BF
        L_rchild = L->rchild;
        switch (L_rchild->bf) {
        case LH:
            node->bf = RH;
            L->bf = EH;
            break;

        case EH:
            node->bf = L->bf = EH;
            break;

        case RH:
            node->bf = EH;
            L->bf = LH;
            break;
        }
    }

    L_rchild->bf = EH;
    // 对node的左子树进行左旋处理，统一和最小不平衡子树根结点的符号
    L_Rotate(node->lchild);
    // 再对整体进行右旋处理
    R_Rotate(node);
}



// 二叉排序树不存在等于已经存在树中的元素时，插入该关键词返回true，否则返回false。
template<typename T>
bool AVLTree<T>::insert(const T &data, BiTNode<T>* &node, bool *taller) {
    if (!searchBST(data)) {
        if (node == NULL) {
            node = new BiTNode<T>(data);
            if (!node)  cout << "out of space!" << endl;
            node->bf = EH;
            *taller = true;
        }
        else if (data < node->data) {
            insert(data, node->lchild);
            // 已插入则左子树会长高
            if (taller) {
                // 检查node的平衡度
                switch (node->bf) {
                    
                // 未插入新结点前左子树高于右子树，需要进行做平衡处理
                case LH:
                    leftBalance(node);
                    *taller = false;
                    break;

                // 未插入新结点前左右子树等高，插入后左子树变高
                case EH:
                    node->bf = LH;
                    *taller = true;
                    break;
                
                // 未插入新结点前右子树高于左子树，现在左右等高
                case RH:
                    node->bf = EH;
                    *taller = false;
                    break;
    
                }
            }


        }
        else {
            insert(data, node->rchild);
            // 已插入右子树会使得右子树长高
            if (*taller) {
                switch (node->bf) {
                    // 未插入新结点前左子树高于右子树，现在左右等高
                    case LH:
                        node->bf = EH;
                        *taller = false;
                        break;
                    
                    // 原来左右子树等高，新插入后右子树变高
                    case EH:
                        node->bf = RH;
                        *taller = true;
                        break;
                    
                    // 原来右子树比左子树高，新插入在右子树要进行右平衡处理
                    case RH:
                        rightBalance(node);
                        *taller = false;
                        break;
                }
            }
        }

        return true;
    }
    return false;
}

template<typename T>
void AVLTree<T>::createTree(T *data, int len) {
    for (int i = 0; i < len; i++) {
        bool res = insert(data[i]);
        if (!res) {
            cout << "插入有相同的元素，" << data[i] << "插入失败" << endl;
            return;
        }
    }
}


template<typename T>
void AVLTree<T>::inorder(BiTNode<T> *current) {
    if (current != NULL) {
        inorder(current->lchild);
        cout << current->data << "  ";
        inorder(current->rchild);
    }
}

template<typename T>
bool AVLTree<T>::searchBST(const T &data, BiTNode<T>* &node) {
    if (!node)  return false;
    else if (data == node->data)   return true;
    else if (data < node->data) return searchBST(data, node->lchild);
    else    return searchBST(data, node->rchild);
}

// 删除已经存在的关键字，成功返回true，删除失败为false
template<typename T>
bool AVLTree<T>::deleteBST(const T &data, BiTNode<T>* &node) {
    if (!node)  return false;
    else if (data < node->data) return deleteBST(data, node->lchild);
    else if (data > node->data)   return deleteBST(data, node->rchild);
    else {
        BiTNode<T> *current, *son;
        // 1、该节点的右子树不存在
        if (node->rchild == NULL) {
            current = node;
            node = node->lchild;
            delete(current);
        }
        // 2、该节点的左子树不存在
        else if (node->lchild == NULL) {
            current = node;
            node = node->rchild;
            delete(current);
        }
        // 3、左右都不为空
        else {
            current = node;
            son = node->lchild;
            // 先左，再转右，找到待删除结点的前驱结点
            while (son->rchild != NULL) {
                current = son;
                son = son->rchild;
            }
            node->data = son->data;
            if (current != node) {
                current->rchild = son->lchild;
            }
            // 如果son从一开始就不存在右孩子，则current=node
            else {
                current->lchild = son->lchild;
            }
            delete(son);
        }
    }

    return true;
}

template<typename T>
void AVLTree<T>::destroy(BiTNode<T>* &node) {
    if (node != nullptr) {
        if (node->lchild != nullptr)    destroy(node->lchild);
        if (node->rchild != nullptr)    destroy(node->rchild);
        delete node;
        // 删除一个指针之后，编译器只会释放该指针所指向的内存空间，而不会删除这个指针本身。
        node = nullptr;
    }
}

int main() {

    int arr[] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    int test_var = 10;
    // int arr[] = {20, 10, 22, 15};
    int len = sizeof(arr) / sizeof(arr[0]);
    AVLTree<int> BST;

    // 1、建树
    BST.createTree(arr, len);

    // 2、中序遍历是升序的序列
    BST.inorder();

    // 3、查找是否成功
    if (BST.searchBST(test_var)) {
        cout << test_var << "查找成功" << endl;
    }
    else {
        cout << "查找失败" << endl;
    }

    // 4、新插入元素检验
    bool res1 = BST.insert(test_var);
        if (!res1) {
            cout << "插入有相同的元素，插入失败" << endl;
        }
        else {
            cout << test_var << "插入成功" << endl;
        }

    // 查看插入后的结果
    BST.inorder();

    // 5、删除元素
    bool res2 = BST.deleteBST(test_var);
    // 查看删除后的结果
    if (!res2) {
        cout << test_var << "删除失败" << endl;
    }
    else {
        cout << test_var << "删除成功" << endl;
    }
    BST.inorder();

    // 6、删除整棵树
    BST.destroy();
    return 0;
}