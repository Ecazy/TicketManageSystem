#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

template<class T>
struct Node
{
    T data;
    Node* next;
    Node(T _data, Node* _next = nullptr) :data(_data), next(_next) {}
    Node() :data(0), next(nullptr) {}
};

template<class T>
struct TreeNode
{
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T _data, TreeNode* _left = nullptr, TreeNode* _right = nullptr) :data(_data), left(_left), right(_right) {}
    TreeNode() :data(0), left(nullptr), right(nullptr) {}
};

template<class T>
class Linklist
{
private:

    void insert(T _data, int pos);
public:
    Node<T>* head;
    int length;

    Linklist(Node<T>* _head = nullptr, int _length = 0) :head(_head), length(_length) {}
    Linklist(Linklist& _list)
    {
        length = _list.length;
        if (length == 0)
        {
            head = nullptr;
            return;
        }
        head = new Node<T>(_list.head->data);
        Node<T>* p = head;
        Node<T>* q = _list.head->next;
        while (q != nullptr)
        {
            p->next = new Node<T>(q->data);
            p = p->next;
            q = q->next;
        }
    }
    ~Linklist(){for(Node<T>* p = head;p != nullptr;p = head){head = head->next;delete p;}}

    void addToHead(T _data);
    void addToTail(T _data);
    void remove(int pos);
    void removeByElement(T _data);
    void sort(bool(*compare)(T, T) = [](T a, T b) {return a < b; });
    bool findByElement(T _data);
    T& getNode(int pos);
    T& operator[](int pos);
    void setNode(int pos, T _data);
};

template<class T>
class Queue:public Linklist<T>
{
public:
    Queue(Node<T>* _head = nullptr, int _length = 0) :Linklist<T>(_head, _length) {}
    Queue(Queue& _queue) :Linklist<T>(_queue) {}

    void push(T _data);
    T pop();
};

template<class T>
class Stack:public Linklist<T>
{
public:
    Stack(Node<T>* _head = nullptr, int _length = 0) :Linklist<T>(_head, _length) {}
    Stack(Stack& _stack) :Linklist<T>(_stack) {}
    void push(T _data);
    T pop();
};

template<class T>
class BinaryTree
{
public:

    TreeNode<T>* root;
    int length;

    BinaryTree(TreeNode<T>* _root = nullptr, int _length = 0) :root(_root), length(_length) {}
    ~BinaryTree() { for (TreeNode<T>* p = root; p != nullptr; p = root) { root = root->left; delete p; } }
    void preorder(TreeNode<T>* _root);
    void inorder(TreeNode<T>* _root);
    void postorder(TreeNode<T>* _root);
    void insert(T _data);
    void remove(T _data);
    void remove(TreeNode<T>* node);
    TreeNode<T>* search(T _data);
};

#endif // DATASTRUCTURE_H

//functions
template<class T>
void Linklist<T>::sort(bool(*compare)(T, T))
{
    if (length <= 1)
        return;
    Node<T>* p = head;
    Node<T>* q = head->next;
    Node<T>* r = head;
    while (q != nullptr)
    {
        if (compare(q->data, head->data))
        {
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

template<class T>
void Linklist<T>::insert(T _data, int pos)
{
    if (pos < 0 || pos > length)
        return;
    Node<T>* p = head;
    Node<T>* q = new Node<T>(_data);
    if (pos == 0)
    {
        q->next = head;
        head = q;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        q->next = p->next;
        p->next = q;
    }
    length++;
}

template<class T>
bool Linklist<T>::findByElement(T _data)
{
    Node<T>* p = head;
    while (p != nullptr)
    {
        if (p->data == _data)
            return true;
        p = p->next;
    }
    return false;
}

template<class T>
void Linklist<T>::remove(int pos)
{
    if (pos < 0 || pos >= length)
        return;
    Node<T>* p = head;
    if (pos == 0)
    {
        head = head->next;
        delete p;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        Node<T>* q = p->next;
        p->next = q->next;
        delete q;
    }
    length--;
}

template<class T>
void Linklist<T>::removeByElement(T _data)
{
    Node<T>* p = head;
    if (p->data == _data)
    {
        head = head->next;
        delete p;
    }
    else
    {
        while (p->next != nullptr)
        {
            if (p->next->data == _data)
            {
                Node<T>* q = p->next;
                p->next = q->next;
                delete q;
                break;
            }
            p = p->next;
        }
    }
    length--;
}

template<class T>
void Linklist<T>::addToHead(T _data)
{
    insert(_data, 0);
}

template<class T>
void Linklist<T>::addToTail(T _data)
{
    insert(_data, length);
}

template<class T>
T& Linklist<T>::getNode(int pos)
{
    if(pos < 0 || pos >= length)
        throw("out of range");
    Node<T>* p = head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    return p->data;
}

template<class T>
T& Linklist<T>::operator[](int pos)
{
    return getNode(pos);
}

template<class T>
void Linklist<T>::setNode(int pos, T _data)
{
    if (pos < 0 || pos >= length)
        return;
    Node<T>* p = head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    p->data = _data;
}

template<class T>
void Queue<T>::push(T _data)
{
    addToTail(_data);
}
template<class T>
T Queue<T>::pop()
{
    T data = this->head->data;
    removeByElement(data);
    return data;
}

template<class T>
void Stack<T>::push(T _data)
{
    this->addToHead(_data);
}
template<class T>
T Stack<T>::pop()
{
    T data = this->head->data;
    removeByElement(data);
    return data;
}

template<class T>
void BinaryTree<T>::preorder(TreeNode<T>* root)
{
    if (root == nullptr)
        return;
    //cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
template<class T>
void BinaryTree<T>::inorder(TreeNode<T>* root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    //cout << root->data << " ";
    inorder(root->right);
}
template<class T>
void BinaryTree<T>::postorder(TreeNode<T>* root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    //cout << root->data << " ";
}
template<class T>
void BinaryTree<T>::insert(T _data)
{
    if (root == nullptr)
    {
        root = new TreeNode(_data);
        return;
    }
    TreeNode<T>* p = root;
    while (true)
    {
        if (_data < p->data)
        {
            if (p->left == nullptr)
            {
                p->left = new TreeNode(_data);
                return;
            }
            else
                p = p->left;
        }
        else
        {
            if (p->right == nullptr)
            {
                p->right = new TreeNode(_data);
                return;
            }
            else
                p = p->right;
        }
    }
}
template<class T>
void BinaryTree<T>::remove(T _data)
{
    TreeNode<T>* p = root;
    TreeNode<T>* q = nullptr;
    while (p != nullptr && p->data != _data)
    {
        q = p;
        if (_data < p->data)
            p = p->left;
        else
            p = p->right;
    }
    if (p == nullptr)
        return;
    if (p->left == nullptr && p->right == nullptr)
    {
        if (q == nullptr)
            root = nullptr;
        else if (q->left == p)
            q->left = nullptr;
        else
            q->right = nullptr;
        delete p;
    }
    else if (p->left == nullptr)
    {
        if (q == nullptr)
            root = p->right;
        else if (q->left == p)
            q->left = p->right;
        else
            q->right = p->right;
        delete p;
    }
    else if (p->right == nullptr)
    {
        if (q == nullptr)
            root = p->left;
        else if (q->left == p)
            q->left = p->left;
        else
            q->right = p->left;
        delete p;
    }
    else
    {
        TreeNode<T>* s = p->left;
        TreeNode<T>* t = p;
        while (s->right != nullptr)
        {
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
template<class T>
void BinaryTree<T>::remove(TreeNode<T>* node)
{
    if (node == nullptr)
        return;
    remove(node->left);
    remove(node->right);
    delete node;
}
template<class T>
TreeNode<T>* BinaryTree<T>::search(T _data)
{
    TreeNode<T>* p = root;
    while (p != nullptr && p->data != _data)
    {
        if (_data < p->data)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}
