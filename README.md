## <center>航空机票订票系统设计</center>

---

> 本项目为中南大学2022年高级程序设计课程要求的四个项目中的第一项，被归于“单链表、队列、二叉树查找和排序算法的实践”中

#### *要求*

1. 设计每条航线所涉及的信息，包括航班信息：**起点终点站名**、**航班号**、**飞机号**、**飞机周日（星期几）**、**乘员定额**、**票价**、**余票量**等，所有客户订票信息：包括**姓名**、**订票量**、**航班号**，**舱位等级1，2或3等**；所有客户退票信息：包括**姓名**、**退票量**、**航班号**，**舱位等级1，2或3等**；
2. 结合基本操作的**单链表、队列、二叉树等数据结构以及排序算法**，设计实现机票订票系统的**查询、订票、退票、改签**等功能；
3. 设计并实现*人机交互友好的界面或菜单*。

---

根据要求设定以下数据结构

```cpp
template<class T>
struct Node {
    T data;
    Node *next;

    Node(T _data, Node *_next = nullptr) : data(_data), next(_next) {}
    Node(const Node& _node)
    {
        data = _node.data;
        next = _node.next;
    }
    Node() : data(0), next(nullptr) {}
};

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

    Linklist(const Linklist &other) {
        length = other.length;
        if (length == 0) {
            head = nullptr;
            return;
        }

        head = new Node<T>(other.head->data);
        Node<T> *p = head;
        Node<T> *q = other.head->next;
        while (q != nullptr) {
            p->next = new Node<T>(q->data);
            p = p->next;
            q = q->next;
            if (q != nullptr) {
                p->next = nullptr; // 设置新链表的非最后一个节点的指针为nullptr
            }
        }
    }

    void clear() {
        Node<T> *current = head;
        while (current) {
            Node<T> *next = current->next; // 保存下一个节点的指针
            delete current; // 释放当前节点
            current = next; // 移动到下一个节点
        }
        head = nullptr; // 将头指针设置为 nullptr，表示链表为空
        length = 0; // 更新链表长度
    }

    void insertBack(const T& data) {
        Node<T>* newNode = new Node<T>(data); // 创建一个新节点

        if (!head) { // 如果链表为空，将新节点设为头节点
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next) { // 找到链表中的最后一个节点
                current = current->next;
            }
            current->next = newNode; // 将新节点连接到最后一个节点的后面
        }

        length++; // 链表长度加一
    }

    Linklist<T> &operator=(const Linklist<T> &other) {
        if (this != &other) {
            clear(); // 清空当前链表内容

            Node<T> *current = other.head;
            while (current) {
                insertBack(current->data); // 后向插入操作，将 other 链表中的节点一个一个插入到当前链表中
                current = current->next;
            }
        }
        return *this;
    }

    //析构函数，用于释放链表中的内存
    ~Linklist() {
        for (Node<T> *p = head; p->next != nullptr; p = head) {
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

//冒泡排序，避免错误
template<class T>
void Linklist<T>::sort(bool(*compare)(T, T)) {
    if (length <= 1)
        return;

    Node<T>* current = nullptr;
    Node<T>* end = nullptr;

    for (int i = 0; i < length - 1; ++i) {
        current = head;

        while (current->next != end) {
            Node<T>* nextNode = current->next;

            if (compare(nextNode->data, current->data)) {
                // 交换节点数据
                T temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }

            current = current->next;
        }

        end = current;  // 已排序部分的尾部
    }
}


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

template<class T>
void Linklist<T>::addToHead(T _data) {
    insert(_data, 0);
}

template<class T>
void Linklist<T>::addToTail(T _data) {
    insert(_data, length);
}

template<class T>
T &Linklist<T>::getNode(int pos) {
    if (pos < 0 || pos >= length)
        throw ("out of range");
    Node<T> *p = head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    return p->data;
}

template<class T>
T &Linklist<T>::operator[](int pos) {
    return getNode(pos);
}

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
template<class T>
void BinaryTree<T>::preorder(TreeNode<T> *root) {
    if (root == nullptr)
        return;
    preorder(root->left);
    preorder(root->right);
}

template<class T>
void BinaryTree<T>::inorder(TreeNode<T> *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    //cout << root->data << " ";
    inorder(root->right);
}

template<class T>
void BinaryTree<T>::postorder(TreeNode<T> *root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    //cout << root->data << " ";
}

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

template<class T>
void BinaryTree<T>::remove(TreeNode<T> *node) {
    if (node == nullptr)
        return;
    remove(node->left);
    remove(node->right);
    delete node;
}

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
```

<mark>此处采用template模板，方便存储不同数据类型的数据，使之成为适用性更强的数据结构</mark>
但需要注意到本程序几乎只使用了其中**Linklist**的部分，故其他部分能否在程序中正常运行存疑。

在设计存储信息的时候，考虑到只需存储航班信息和乘客信息，而航班与乘客又具有一定的联系，由于不能使用外部数据库，此处考虑将航班信息存储在乘客成员中（每个乘客成员不是可简单地理解成乘客本人，而其实质是含有乘客和航班信息的一次航行记录）

在整个信息存储中，我们都需要使用舱位等级，而其又是有限的、可枚举的，另外此处宏定义各舱位总票数方便更改，故有以下内容

```cpp
#define STOCK_TOTAL_FIRST 50
#define STOCK_TOTAL_SECOND 100
#define STOCK_TOTAL_THIRD 200 

typedef enum
{
 FIRST,SECOND,THIRD
}travelClass;
```

航班信息以及乘客信息如下

```cpp
class FlightInfo {
//已去除构造函数等影响理解的信息
private:

    string beginning, destination;
    string flightID;
    DateTime depature;
    int capacity;
    double first_fare;
    double second_fare;
    double third_fare;
    StockRemained stockRemained;

public:
    string getBeginning();

    string getDestination();

    string getFlightID();

    DateTime getDepature();

    int getCapacity();

    double getFares(travelClass a);

    unsigned int getStockRemained(travelClass _travelClass);

    StockRemained  getStockRemained();

    void setStockRemained(travelClass _travelClass, int a);
    
    bool ticket_has_left();
};

class passengerInfo {
//同上描述
private:
    string name;
    FlightInfo my_flight;
    bool isBooked;
public:
    travelClass my_class;

    friend class FlightInfo;

    string getName();

    FlightInfo getFlightInfo();

    bool getIsBooked();

    void setIsBooked(bool isBooked);
};
```
---

以下将列出在用户操作界面将直接调用的函数的定义，及使用方法。

- 查询
  - 在进行查询时，用户将被要求输入航班的时间（具体到天）和始末地址。进而程序将所有符合条件的航班信息返回到界面上。
- 筛选
  - 点击”去除无票航班“，可以使界面中展示的所有航班信息中，去除无票的航班。
- 排序
  1. 根据出发时间排序（仅支持时间从早到晚的排序）
  2. 根据票价排序（仅支持价格从高到低的排序）
- 购票、退票、改签
  - 购票：用户点击查询后，系统将会把存放到用户可选择的位置，如此用户只需根据查询得到的航班信息按航班号选择航班，同时需要附上舱位信息
  - 退票：用户购票完成后，系统将会将所有用户已购的航班信息展示在用户可见的位置（以表的形式），并在退票界面仅允许用户选择此中的航班，防止错误退票
  - 改签：同上所描述，改签时用户依然只能从展示的可供选择的航班中购买改签之后的航班，同样也只能从展示的已购航班中选择改签的航班
 
  在选择航班时间的时候，本系统支持两种输入时间的方法：
  1. 直接输入时间（如：2023-12-2）
  2. 在日历小组件中选择日期
---
  本系统还支持登陆界面，用户信息检验只在登录时，因为本系统的定位只是课程设计作业（lazy)。用户信息只用简单的链表储存在程序中，但航班信息意义较大内容较多，故决定存储在文件中（data.bin)。