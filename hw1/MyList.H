//  =============== BEGIN ASSESSMENT HEADER ================
/// Joshua Lai
/// 861163421
/// 13 April 2015
//  ================== END ASSESSMENT HEADER ===============
#ifndef MYLIST_H
#define MYLIST_H
#include <string>
#include <iostream>
#include <assert.h>

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
            head = 0;
            Node* temp = str.head;
            
            do
            {
                push_back(temp->data);
                temp = temp->next;
            }while(temp != head);
        }
        MyList(const string& str) {
            head = 0;
            for(unsigned i = 0; i < str.size(); i++)
            {
                push_back(str.at(i));
            }
        }
        MyList(const char* str)
        {
            head = 0;
            int i = 0;
            for(; *str != '\n'; str++)
            {
                push_back(str[i]);
                i++;
            }
        }
        ~MyList()
        {
            Node* temp = head;
            Node* copy;
            do
            {
                copy = temp;
                temp = temp->next;
                delete copy;
            }while(temp != head);
        }
        
        void push_front(char value) {
            Node* add = new Node(value);
            if(!head)
            {
                head = add;
                head->next = head;
                head->pred = head;
                return;
            }
            Node* temp = head->pred;
            
            temp->next = add;
            add->pred = temp;
            add->next = head;
            head->pred = add;
            
        }
        void push_back(char value) {
            Node* add = new Node(value);
            if(!head)
            {
                head = add;
                head->next = head;
                head->pred = head;
                return;
            }
            Node* temp = head->pred;
            
            temp->next = add;
            add->pred = temp;
            add->next = head;
            head->pred = add;
            
        }
        void pop_front() {
            if(!head)
            {
                return;
            }
            if(head->pred == head)
            {
                delete head;
                head = 0;
                return;
            }
            Node* temp = head;
            head = head->next;
            head->pred = temp->pred;
            temp->pred->next = head;
            delete temp;
        }
        void pop_back()
        {
            if(!head)
            {
                return;
            }
            if(head->pred == head)
            {
                delete head;
                head = 0;
                return;
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
            
            //figure out endcases
            if(temp->pred) 
                temp->pred->next = temp2;
            if(temp2->pred)  
                temp2->pred->next = temp;
            if(temp->next) 
                temp->next->pred = temp2;
            if(temp2->next) 
                temp2->next->pred= temp;
            Node* copy;
            copy = temp->pred;
            temp->pred = temp2->pred;    
            temp2->pred = copy;
            copy = temp->next;
            temp->next = temp2->next;    
            temp2->next= copy;
            
        }
        void insert_at_pos(int i, char value) {
            assert(!(i >= size()));
            
            Node* temp = head;
            for(int x = 0; x < i; x++)
                temp = temp->next;
                
            Node* add = new Node(value);
            temp->pred->next = add;
            add->pred = temp->pred;
            add->next = temp;
            temp->pred = add;
        }
        void reverse()
        {
            Node* temp = head;
            Node* copy;
            do
            {
                copy = temp->pred;
                temp->pred = temp->next;
                temp->next = copy;
                temp = temp->pred;
            }while(temp != head);
            
            head = head->next;
        }
        int size()const
        {
            Node* temp = head;
            int count = 0;
            do
            {
                count++;
                temp = temp->next;
            }while(temp != head);
            
            return count;
        }
        void print()const
        {
            assert(head);
            Node* temp = head;
            do
            {
                cout << temp->data << ' ';
                temp = temp->next;
            }while(temp != head);
            cout << endl;
        }
        int find(char value)const
        {
            Node* temp = head;
            int count = 0;
            do
            {
                if(temp->data == value)
                    return count;
                temp = temp->next;
                count++;
            }while(temp != head);
            
            return -1;
        }
        int find(MyList& query_str)const
        {
            Node* temp = head;
            Node* qtemp = query_str.head;
            bool flag = true;
            int count = 0;
            do
            {
                if(temp->data == qtemp->data)
                {
                    Node* a = temp;
                    Node* b = qtemp;
                    flag = true;
                    for(int i = 1; i < query_str.size(); i++)
                    {
                        a = a->next;
                        b = b->next;
                        if(a->data != b->data)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                        return count;
                }
                
                temp = temp->next;
                count++;
            }while(temp != head);
            
            return -1;
        }
        MyList& operator=(const MyList& str)
        {
            Node* temp = str.head;
            Node* itemp = head;
            
            do
            {
                itemp->data = temp->data;
                temp = temp->next;
                itemp = itemp->next;
                if(itemp == head)
                    break;
            }while(temp != head);
            // if(temp->next != str.head)
            // {
            //     do
            //     {
            //         push_back(temp->data);
            //         temp = temp->next;
            //     }while(temp != head);
            // }
            
            return *this;
        }
        char& operator[](const int i)
        {
            Node* temp = head;
            if(i == 0)
                return temp->data;
            assert(!(i < 0));
            assert(!(i >= size()));
            for(int j = 0; j < i; j++)
            {
                temp = temp->next;
            }
            
            return temp->data;
        }
        MyList& operator+(const MyList& str)
        {
            Node* tail = head->pred;
            Node* tail2 = str.head->pred;
            str.head->pred = tail;
            tail->next = str.head;
            
            head->pred = tail2;
            tail2->next = head;
            
            return *this;
        }
};


#endif