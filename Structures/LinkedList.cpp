#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include "LinkedList.h"

int main() {
    linkedList<int> c = linkedList<int>();
    linkedList<int> t = linkedList<int>();

    //push_back, pop_back, push_front, pop_front
    for(int i = 0; i < 5; i++)  c.push_front(i);
    for(int i = 0; i < 5; i++) std::cout<<c.pop_front();
    std::cout << std::endl;
    for(int i = 0; i < 5; i++) c.push_back(i);
    for(int i = 0; i < 5; i++) std::cout << c.pop_back();

    std::cout << std::endl;

    //Operator=, copy constructor, returnAt
    for(int i = 0; i < 10; i++) c.push_back(i);
    t = c;
    linkedList<int> d = linkedList<int>(t);
    for(int i = 0; i < 10; i++) std::cout << t.returnAt(i);
    std::cout <<std::endl;
    for(int i = 0; i < 10; i++) std::cout << d.returnAt(i);
    std::cout <<std::endl;

    //insertAt, removeAt, print
    c.insertAt(13,4);
    c.insertAt(23,8);
    c.print();
    std::cout << std::endl;
    c.removeAt(3);
    c.removeAt(4);
    c.print();

    //search, size, front, back
    std::cout << std::endl;
    std::cout << c.search(23);
    std::cout << std::endl << c.size();
    std::cout << std::endl << c.front();
    std::cout << std::endl << c.back();
    std::cout << std::endl;    

    //reverse && merge
    linkedList<int> q = linkedList<int>();
    linkedList<int> r = linkedList<int>();
    r = c;
    q = c;

    c.print();
    std::cout << std::endl;
    q.reverse();
    q.print();
    std::cout << std::endl;
    r.merge(q);
    r.print();
    std::cout << std::endl;


    //Operators
    linkedList<int> aa = linkedList<int>();
    linkedList<int> ab = linkedList<int>();
    linkedList<int> ac = linkedList<int>();
    linkedList<int> ad = linkedList<int>();

    for(int i = 0; i < 10; i++) aa.push_back(i);

    ab = aa;
    ac = aa;
    ad = aa;

    aa.print();
    std::cout << std::endl;
    ab.print();
    std::cout << std::endl;
    ac.push_back(11);
    ad.pop_back();
    ac.print();
    std::cout << std::endl;
    ad.print();
    std::cout << std::endl;

    std::cout << (aa==ab) << " ";
    std::cout << (aa <= ab) << " ";
    std::cout << (aa < ac) << " ";
    std::cout << (aa > ad) << " ";

    return 0;
}