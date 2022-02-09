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
        return insert(data, root);
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
    bool insert(const T &data, BiTNode<T>* &node);
    int biTreeDepth(BiTNode<T> *node);
    int getNodeBalanceFactor(BiTNode<T> *node);
    void setBiTreeBalanceFactor(BiTNode<T>* &node);
    void getImbalanceNodeIsTwo(BiTNode<T>* &node, BiTNode<T>* &p);
    void getImbalanceNodeFatherIsTwo(BiTNode<T>* &node, BiTNode<T>* &p_father);
    void LLAdjust(BiTNode<T>* &node, BiTNode<T>* &p, BiTNode<T>* &p_father);
    void inorder(BiTNode<T> *current);
    //  BiTNode<T>* &b——以引用传递的方式传入指针，去掉&为以值传递的方式传入指针
    bool searchBST(const T &data, BiTNode<T>* &node);
    bool deleteBST(const T &data, BiTNode<T>* &node);
    void destroy(BiTNode<T>* &node);
};

// 二叉排序树不存在等于已经存在树中的元素时，插入该关键词返回true，否则返回false。
template<typename T>
bool AVLTree<T>::insert(const T &data, BiTNode<T>* &node) {
    if (!searchBST(data)) {
        if (node == NULL) {
            node = new BiTNode<T>(data);
            if (!node)  cout << "out of space!" << endl;
        }
        else if (data < node->data) insert(data, node->lchild);
        else insert(data, node->rchild);

        return true;
    }
    return false;
}

// 求子树的高度
template<typename T>
int AVLTree<T>::biTreeDepth(BiTNode<T> *node) {
    int left_depth = 0, right_depth = 0;
    // 空树，高度为0
    if (node == NULL)   return 0;
    else {
        // 对于当前结点作为根节点，求左子树的高度
        left_depth = BiTreeDepth(node->lchild);
        // 对于当前结点作为根节点，求右子树的高度
        right_depth = BiTreeDepth(node->rchild);
        // 将最大depth的作为node为根的深度
        if (left_depth > right_depth)   return left_depth + 1;
        else return right_depth + 1;
    }
}

// 求某个结点的BF
template<typename T>
int AVLTree<T>::getNodeBalanceFactor(BiTNode<T> *node) {
    int left_depth, right_depth;
    if (node != NULL) {
        left_depth = biTreeDepth(node->lchild);
        right_depth = biTreeDepth(node->rchild);
    }

    return left_depth - right_depth;
}
// 求树中每个结点的BF
template<typename T>
void AVLTree<T>::setBiTreeBalanceFactor(BiTNode<T>* &node) {
    if (node != NULL) {
        node->bf = getNodeBalanceFactor(node);
        setBiTreeBalanceFactor(node->lchild);
        setBiTreeBalanceFactor(node->rchild);
    }
}

// 获得平衡因子为2或-2的结点
template<typename T>
void AVLTree<T>::getImbalanceNodeIsTwo(BiTNode<T>* &node, BiTNode<T>* &p) {
    if (node->bf == 2 || node->bf == -2) {
        p = node;
    }
    getImbalanceNodeIsTwo(node->lchild, p);
    getImbalanceNodeIsTwo(node->rchild, p);
}

// 获得平衡因子为2或-2的结点的父节点
template<typename T>
void AVLTree<T>::getImbalanceNodeFatherIsTwo(BiTNode<T>* &node, BiTNode<T>* &p_father) {
    if (node != NULL) {
        if (node->lchild != NULL) {
            if (node->lchild->bf == 2 || node->lchild->bf == -2)    p_father = node;
        }

        if (node->rchild != NULL) {
            if (node->rchild->bf == 2 || node->rchild->bf == -2)    p_father = node;
        }

        getImbalanceNodeFatherIsTwo(node->lchild, p_father);
        getImbalanceNodeFatherIsTwo(node->rchild, p_father);
    }

}

// LL调整——新插入的结点在左孩子的左子树上，要做单右旋处理
template<typename T>
void AVLTree<T>::LLAdjust(BiTNode<T>* &node, BiTNode<T>* &p, BiTNode<T>* &p_father) {
    
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