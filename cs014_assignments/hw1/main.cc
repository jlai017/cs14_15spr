#include "MyList.H"
#include <iostream>

using namespace std;

int main() {
    
    MyList l = MyList();
    string n = "something";
    MyList s = MyList(n);
    
    l.push_back('s');
    l.push_back('t');
    l.push_back('u');
    l.push_back('v');
    l.push_back('w');
    l.push_back('x');
    l.push_back('y');
    l.push_back('z');
    
    l.print();
    //l.swap(1, 4);
    l.reverse();
    l.print();
    l.insert_at_pos(1, 'j');
    l.print();
    cout << l.find('v') << endl;
    s.print();
    return 0;
}