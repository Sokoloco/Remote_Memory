#include <iostream>
#include "Structures/LinkedList.cpp"



using namespace std;

int main() {
    LinkedList<int> ok;
    int *onep, *twop, *threep;
    int one = 1,two = 2,three = 3;
    onep = &one;
    twop = &two;
    threep = &three;
    cout<< one<<endl;
    ok.add(onep);
    ok.add(twop);
    ok.add(threep);
}