## <center>航空机票订票系统设计</center>

---

> 本项目为中南大学高级程序设计课程要求的四项中的第一项，被归于“单链表、队列、二叉树查找和排序算法的实践”中

#### *要求*

1. 设计每条航线所涉及的信息，包括航班信息：**起点终点站名**、**航班号**、**飞机号**、**飞机周日（星期几）**、**乘员定额**、**票价**、**余票量**等，所有客户订票信息：包括**姓名**、**订票量**、**航班号**，**舱位等级1，2或3等**；所有客户退票信息：包括**姓名**、**退票量**、**航班号**，**舱位等级1，2或3等**；
2. 结合基本操作的**单链表、队列、二叉树等数据结构以及排序算法**，设计实现机票订票系统的**查询、订票、退票、改签**等功能；
3. 设计并实现*人机交互友好的界面或菜单*。

---

根据要求设定以下数据结构

```cpp
template<class T>
struct Node
{
    T data;
    Node* next;
    Node(T _data, Node* _next = nullptr) :data(_data), next(_next) {}
    Node() :data(NULL), next(nullptr) {}
};

template<class T>
struct TreeNode
{
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T _data, TreeNode* _left = nullptr, TreeNode* _right = nullptr) :data(_data), left(_left), right(_right) {}
    TreeNode() :data(NULL), left(nullptr), right(nullptr) {}
};

template<class T>
class Linklist
{
private:
    void sort(bool(*compare)(T, T) = [](T a, T b) {return a < b; });
    void insert(T _data, int pos);
    bool find(T _data);
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
        Node* p = head;
        Node* q = _list.head->next;
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
    void remove(T _data);

    bool findByElement(T _data)
    {
        return find(_data);
    }
    T getNode(int pos);
    T operator[](int pos);
    void setNode(int pos, T _data);

};

template<class T>
class Queue:public Linklist<T>
{
public:
    Queue(Node<T>* _head = nullptr, int _length = 0) :Linklist(_head, _length) {}
    Queue(Queue& _queue) :Linklist(_queue) {}

    void push(T _data);
    T pop();
};

template<class T>
class Stack:public Linklist<T>
{
public:
    Stack(Node<T>* _head = nullptr, int _length = 0) :Linklist(_head, _length) {}
    Stack(Stack& _stack) :Linklist(_stack) {}
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
```

<mark>此处采用template模板，方便存储不同数据类型的数据，使之称为适用性更强的数据结构</mark>

在设计存储信息的时候，考虑到只需存储航班信息和乘客信息，而航班与乘客又具有一定的联系，由于不能使用外部数据库，此处考虑将乘客信息存储在航班中，即**每趟航班将储存其随行的乘客的身份信息，并以排列好的链表存储**

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
class flightInfo
{
private:
    string beginning, destination;
    string flightID;
    string planeID;
    int occupLimit;
    double fares;
    typedef struct{
        unsigned int first;
        unsigned int second;
        unsigned int third;
    }StockRemained;
    StockRemained stockRemained;
    void addPassenger(passengerInfo& _passenger);
    void deletePassenger(passengerInfo& _passenger);
public:
    Linklist<passengerInfo> passengerList;

    flightInfo(string beginning,string destination,string flightID,string planeID,int occupLimit,double fares):
        beginning(beginning),destination(destination),flightID(flightID),planeID(planeID),occupLimit(occupLimit),fares(fares),stockRemained(StockRemained{STOCK_TOTAL_FIRST,STOCK_TOTAL_SECOND,STOCK_TOTAL_THIRD})
    {}
    flightInfo(flightInfo& _flight)
    {
        beginning = _flight.beginning;
        destination = _flight.destination;
        flightID = _flight.flightID;
        planeID = _flight.planeID;
        occupLimit = _flight.occupLimit;
        fares = _flight.fares;
        stockRemained = _flight.stockRemained;
    }
    string getBeginning();
    string getDestination();
    string getFlightID();
    string getPlaneID();
    int getOccuoLimit();
    double getFares();
    unsigned int getStockRemained(travelClass _travelClass);

    bool passengerBook(passengerInfo& _passenger);
    void TicketInfo(passengerInfo& _passenger);
};

class passengerInfo
{
private:
    string name;
    travelClass travelclass;
    bool isBooked;
public:
    friend class flightInfo;
    passengerInfo(string name,travelClass travelclass):
        name(name),travelclass(travelclass)
    {}
    passengerInfo(passengerInfo& _passenger)
    {
        name = _passenger.name;
        travelclass = _passenger.travelclass;
    }
    string getName();
    travelClass getTravelClass();
    bool getIsBooked();
    void setIsBooked(bool isBooked);

    bool operator<(passengerInfo& _passenger);

};
```

其中航班信息可对外直接调用的，包括指定参数的初始化，以现有对象初始化，乘客预定以及乘客退票

---

以下将列出在用户操作界面将直接或间接调用的函数的定义，及使用方法。

- 查询
  1. 通过时间查询航班
  2. 通过始末点查询航班
- 筛选
  1. 通过是否有余票筛选
- 排序
  1. 根据出发时间排序
  2. 根据票价排序
  3. 根据到达时间排序
- 购票、退票、改签
  
  在进行上述操作时将对用户信息进行核实，而本系统仅类似demo，未涉及登录、用户信息处理等功能，故只采用简单的输入用户信息，不严格核查。
