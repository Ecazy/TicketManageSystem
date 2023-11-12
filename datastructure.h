#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

/**
 * @brief 链表中的结点，包括数据和指向下一个结点的指针
 * 同时声明了一个默认构造函数，用于初始化头结点（默认参数是空指针）
 * @tparam T 
 */
template<class T>
struct Node {
    T data;
    Node *next;

    Node(T _data, Node *_next = nullptr) : data(_data), next(_next) {}

    Node() : data(0), next(nullptr) {}
};

/**
 * @brief 二叉树中的结点，包括数据和指向左右子树的指针
 * 同时声明了一个默认构造函数，用于初始化根结点（默认参数是空指针）
 * @tparam T
 */
template<class T>
struct TreeNode {
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T _data, TreeNode *_left = nullptr, TreeNode *_right = nullptr) : data(_data), left(_left),
                                                                               right(_right) {}

    TreeNode() : data(0), left(nullptr), right(nullptr) {}
};

template<class T>
class Linklist {
private:
    void insert(T _data, int pos);

public:
    //类的公有成员变量包括头结点和链表长度
    Node<T> *head;
    int length;

    //默认构造函数，用于初始化空链表
    Linklist(Node<T> *_head = nullptr, int _length = 0) : head(_head), length(_length) {}

    //拷贝构造函数，用于初始化链表
    Linklist(Linklist &_list) {
        length = _list.length;
        if (length == 0) {
            head = nullptr;
            return;
        }
        head = new Node<T>(_list.head->data);
        Node<T> *p = head;
        Node<T> *q = _list.head->next;
        while (q != nullptr) {
            p->next = new Node<T>(q->data);
            p = p->next;
            q = q->next;
        }
    }

    //析构函数，用于释放链表中的内存
    ~Linklist() {
        for (Node<T> *p = head; p != nullptr; p = head) {
            head = head->next;
            delete p;
        }
    }

    void addToHead(T _data);

    void addToTail(T _data);

    void remove(int pos);

    void removeByElement(T _data);

    void sort(bool(*compare)(T, T) = [](T a, T b) { return a < b; });

    bool findByElement(T _data);

    T &getNode(int pos);

    T &operator[](int pos);

    void setNode(int pos, T _data);
};

template<class T>
class Queue : public Linklist<T> {
public:
    Queue(Node<T> *_head = nullptr, int _length = 0) : Linklist<T>(_head, _length) {}

    Queue(Queue &_queue) : Linklist<T>(_queue) {}

    void push(T _data);

    T pop();
};

template<class T>
class Stack : public Linklist<T> {
public:
    Stack(Node<T> *_head = nullptr, int _length = 0) : Linklist<T>(_head, _length) {}

    Stack(Stack &_stack) : Linklist<T>(_stack) {}

    void push(T _data);

    T pop();
};

template<class T>
class BinaryTree {
public:

    TreeNode<T> *root;
    int length;

    BinaryTree(TreeNode<T> *_root = nullptr, int _length = 0) : root(_root), length(_length) {}

    ~BinaryTree() {
        for (TreeNode<T> *p = root; p != nullptr; p = root) {
            root = root->left;
            delete p;
        }
    }

    void preorder(TreeNode<T> *_root);

    void inorder(TreeNode<T> *_root);

    void postorder(TreeNode<T> *_root);

    void insert(T _data);

    void remove(T _data);

    void remove(TreeNode<T> *node);

    TreeNode<T> *search(T _data);
};

#endif // DATASTRUCTURE_H

//functions
/**
 * @brief 公有函数，用于对链表进行排序
 * @tparam T
 * @param compare 比较函数，用于比较两个数据的大小
*/
template<class T>
void Linklist<T>::sort(bool(*compare)(T, T)) {
    if (length <= 1)
        return;
    Node<T> *p = head;
    Node<T> *q = head->next;
    Node<T> *r = head;
    while (q != nullptr) {
        if (compare(q->data, head->data)) {
            r = r->next;
            T temp = r->data;
            r->data = q->data;
            q->data = temp;
        }
        q = q->next;
    }
    T temp = r->data;
    r->data = head->data;
    head->data = temp;
    Linklist<T> left(head, length / 2);
    Linklist<T> right(r->next, length - length / 2 - 1);
    left.sort(compare);
    right.sort(compare);
    head = left.head;
    p = head;
    while (p->next != nullptr)
        p = p->next;
    p->next = r;
    r->next = right.head;
}

/**
 * @brief 私有函数，用于插入结点到列表中
 * @param _data 要插入的数据 
 * @param pos 要插入的位置
 */
template<class T>
void Linklist<T>::insert(T _data, int pos) {
    if (pos < 0 || pos > length)
        return;
    Node<T> *p = head;
    Node<T> *q = new Node<T>(_data);
    if (pos == 0) {
        q->next = head;
        head = q;
    } else {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        q->next = p->next;
        p->next = q;
    }
    length++;
}

/**
 * @brief 公有函数，用于查找链表中是否存在某个数据
 * @tparam T
 * @param _data 要查找的数据
 * @return true 存在 
 */
template<class T>
bool Linklist<T>::findByElement(T _data) {
    Node<T> *p = head;
    while (p != nullptr) {
        if (p->data == _data)
            return true;
        p = p->next;
    }
    return false;
}

/**
 * @brief 公有函数，通过给定结点位置删除链表中的某个结点
 * @tparam T
 * @param pos 要删除的结点的位置
 */
template<class T>
void Linklist<T>::remove(int pos) {
    if (pos < 0 || pos >= length)
        return;
    Node<T> *p = head;
    if (pos == 0) {
        head = head->next;
        delete p;
    } else {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        Node<T> *q = p->next;
        p->next = q->next;
        delete q;
    }
    length--;
}

/**
 * @brief 公有函数，通过给定数据删除链表中的某个结点
 * @tparam T
 * @param _data 要删除的结点的数据
 */
template<class T>
void Linklist<T>::removeByElement(T _data) {
    Node<T> *p = head;
    if (p->data == _data) {
        head = head->next;
        delete p;
    } else {
        while (p->next != nullptr) {
            if (p->next->data == _data) {
                Node<T> *q = p->next;
                p->next = q->next;
                delete q;
                break;
            }
            p = p->next;
        }
    }
    length--;
}

/**
 * @brief 将数据添加到链表的头部
 * @tparam T 
 * @param _data 要添加的数据
 */
template<class T>
void Linklist<T>::addToHead(T _data) {
    insert(_data, 0);
}

/**
 * @brief 将数据添加到链表的尾部
 * @tparam T
 * @param _data 要添加的数据 
 */
template<class T>
void Linklist<T>::addToTail(T _data) {
    insert(_data, length);
}

/**
 * @brief 公有函数，通过给定位置获取链表中的某个结点
 * @tparam T
 * @param pos 要获取的结点的位置
 * @return T& 要获取的结点的数据的引用 
 */
template<class T>
T &Linklist<T>::getNode(int pos) {
    if (pos < 0 || pos >= length)
        throw ("out of range");
    Node<T> *p = head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    return p->data;
}

/**
 * @brief 重载[]运算符，通过给定位置获取链表中的某个结点
 * @tparam T
 * @param pos 要获取的结点的位置
 * @return T& 要获取的结点的数据的引用
 */
template<class T>
T &Linklist<T>::operator[](int pos) {
    return getNode(pos);
}

/**
 * @brief 公有函数，通过给定位置设置链表中的某个结点的数据
 * @tparam T
 * @param pos 要设置的结点的位置
 * @param _data 要设置的数据
 */
template<class T>
void Linklist<T>::setNode(int pos, T _data) {
    if (pos < 0 || pos >= length)
        return;
    Node<T> *p = head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    p->data = _data;
}

/*-------------------------------------------------*/
//以下为队列、栈成员函数的实现

template<class T>
void Queue<T>::push(T _data) {
    addToTail(_data);
}

template<class T>
T Queue<T>::pop() {
    T data = this->head->data;
    removeByElement(data);
    return data;
}

template<class T>
void Stack<T>::push(T _data) {
    this->addToHead(_data);
}

template<class T>
T Stack<T>::pop() {
    T data = this->head->data;
    removeByElement(data);
    return data;
}


/*-------------------------------------------------*/
//以下为二叉树成员函数的实现

/**
 * @brief 公有函数，用于前序遍历二叉树
 * @tparam T
 * @param root 二叉树的根结点 
 */
template<class T>
void BinaryTree<T>::preorder(TreeNode<T> *root) {
    if (root == nullptr)
        return;
    //cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

/**
 * @brief 公有函数，用于中序遍历二叉树
 * @tparam T
 * @param root 二叉树的根结点
 */
template<class T>
void BinaryTree<T>::inorder(TreeNode<T> *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    //cout << root->data << " ";
    inorder(root->right);
}

/**
 * @brief 公有函数，用于后序遍历二叉树
 * @tparam T
 * @param root 二叉树的根结点
 */
template<class T>
void BinaryTree<T>::postorder(TreeNode<T> *root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    //cout << root->data << " ";
}

/**
 * @brief 公有函数，用于向二叉树中插入结点
 * @tparam T
 * @param _data 要插入的数据 
 */
template<class T>
void BinaryTree<T>::insert(T _data) {
    if (root == nullptr) {
        root = new TreeNode(_data);
        return;
    }
    TreeNode<T> *p = root;
    while (true) {
        if (_data < p->data) {
            if (p->left == nullptr) {
                p->left = new TreeNode(_data);
                return;
            } else
                p = p->left;
        } else {
            if (p->right == nullptr) {
                p->right = new TreeNode(_data);
                return;
            } else
                p = p->right;
        }
    }
}

/**
 * @brief 公有函数，用于删除二叉树中的某个结点，通过给定数据
 * @tparam T
 * @param _data 要删除的结点的数据 
 */
template<class T>
void BinaryTree<T>::remove(T _data) {
    TreeNode<T> *p = root;
    TreeNode<T> *q = nullptr;
    while (p != nullptr && p->data != _data) {
        q = p;
        if (_data < p->data)
            p = p->left;
        else
            p = p->right;
    }
    if (p == nullptr)
        return;
    if (p->left == nullptr && p->right == nullptr) {
        if (q == nullptr)
            root = nullptr;
        else if (q->left == p)
            q->left = nullptr;
        else
            q->right = nullptr;
        delete p;
    } else if (p->left == nullptr) {
        if (q == nullptr)
            root = p->right;
        else if (q->left == p)
            q->left = p->right;
        else
            q->right = p->right;
        delete p;
    } else if (p->right == nullptr) {
        if (q == nullptr)
            root = p->left;
        else if (q->left == p)
            q->left = p->left;
        else
            q->right = p->left;
        delete p;
    } else {
        TreeNode<T> *s = p->left;
        TreeNode<T> *t = p;
        while (s->right != nullptr) {
            t = s;
            s = s->right;
        }
        p->data = s->data;
        if (t == p)
            t->left = s->left;
        else
            t->right = s->left;
        delete s;
    }
}

/**
 * @brief 私有函数，用于删除二叉树中的某个结点，通过给定结点
 * @tparam T
 * @param node 要删除的结点  
 */
template<class T>
void BinaryTree<T>::remove(TreeNode<T> *node) {
    if (node == nullptr)
        return;
    remove(node->left);
    remove(node->right);
    delete node;
}

/**
 * @brief 公有函数，用于查找二叉树中的某个结点，通过给定数据
 * @tparam T
 * @param _data 要查找的结点的数据
 * @return TreeNode<T>* 要查找的结点的指针 
 */
template<class T>
TreeNode<T> *BinaryTree<T>::search(T _data) {
    TreeNode<T> *p = root;
    while (p != nullptr && p->data != _data) {
        if (_data < p->data)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}
