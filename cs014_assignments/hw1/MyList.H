#ifndef MYLIST_H
#define MYLIST_H

using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* pred;
    Node() {}
    Node(T data) : data(data), next(0), pred(0) {} 
};

template<typename T>
class MyList {
    private:
        Node<T>* head;
    public:
        Mylist() {
            head = 0;
        }
        MyList(const MyList& str) {
            //use push_back();
            
            Node<T>* temp = str.head;
            Node<T>* oth = head;
            oth = temp;
            for(temp = str.head->next; temp != 0; temp = temp->next)
            {
                oth->next = temp;
                oth = oth->next;
            }
        }
        MyList(const string& str) {
            
        }
        MyList(const char* str);
        ~MyList();
};


#endif