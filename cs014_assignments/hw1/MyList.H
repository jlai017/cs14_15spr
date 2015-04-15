#ifndef MYLIST_H
#define MYLIST_H
#include <string>

using namespace std;


struct Node {
    char data;
    Node* next;
    Node* pred;
    Node() {}
    Node(char data) : data(data), next(0), pred(0) {} 
};

class MyList {
    private:
        Node* head;
    public:
        MyList() {
            head = 0;
        }
        MyList(const MyList& str) {
            //use push_back();
            
            Node* temp = str.head;
            
            do
            {
                push_back(temp->data);
                temp = temp->next;
            }while(temp != head);
        }
        MyList(const string& str) {
            for(unsigned i = 0; i < str.size(); i++)
            {
                push_back(str.at(i));
            }
        }
        MyList(const char* str)
        {
            int i = 0;
            for(; *str != '\n'; str++)
            {
                push_back(str[i]);
                i++;
            }
        }
        ~MyList()
        {
            
        }
        
        void push_front(char value) {
            Node* temp = head->pred;
            Node* add = new Node(value);
            if(head == 0)
            {
                head = add;
                head->next = head;
                head->pred = head;
            }
            
            temp->next = add;
            add->pred = temp;
            add->next = head;
            head->pred = add;
            
        }
        void push_back(char value) {
            Node* temp = head->pred;
            Node* add = new Node(value);
            if(head == 0)
            {
                head = add;
                head->next = head;
                head->pred = head;
            }
            
            temp->next = add;
            add->pred = temp;
            add->next = head;
            head->pred = add;
        }
        void pop_front() {
            if(head == 0)
            {
                return;
            }
            if(head->pred == head)
            {
                delete head;
                head = 0;
            }
            Node* temp = head;
            head = head->next;
            head->pred = temp->pred;
            temp->pred->next = head;
            delete temp;
        }
        void pop_back()
        {
            if(head == 0)
            {
                return;
            }
            if(head->pred == head)
            {
                delete head;
                head = 0;
            }
            Node* temp = head->pred;
            temp->pred->next = head;
            head->pred = temp->pred;
            delete temp;
            
        }
        void swap(int i, int j)
        {
            if(i >= size() || j >= size())
                return;
            Node* temp = head;
            Node* temp2 = head;
            for(int x = 0; x < i; x++)
                temp = temp->next;
            for(int x = 0; x < j; x++)
                temp2 = temp2->next;
            
            Node* copy = new Node();
            *copy = *temp;
            temp->next = temp2->next;
            temp->pred = temp2->pred;
            temp2->pred = copy->pred;
            temp2->next = copy->next;
            
            delete copy;
            
        }
        void insert_at_pos(int i, char value) {
            if(i >= size())
                return;
            Node* temp = head;
            for(int x = 0; x < i; x++)
                temp = temp->next;
                
            Node* add = new Node(value);
            temp->pred->next = add;
            add->pred = temp->pred;
            add->next = temp;
            temp->pred = add;
        }
        void reverse();
        int size()const;

};


#endif