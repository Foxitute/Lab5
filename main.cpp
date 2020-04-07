#include "Person.hpp"
#include <iostream>
using namespace std;

string cmp_result (Sortable* s1, Sortable* s2)  // get result of comparing two objects
{
    return s1->Compare(*s2)
        ? s1->GetName() +" and "+ s2->GetName() +" is the same person."
        : s1->GetName() +" and "+ s2->GetName() +" are different people.";
}

int main ()
{
    Sortable *sp, *sp2;
    
    Person *p = new Person ("Mike", "mike@iccewin.nl", "582466");
    sp = p;            // sp now points to a Person [p]
    cout << "Result of Comparing is that:\n" << cmp_result(p, sp) << "\n\n";
    
    Person *p2 = new Person ("Clare", "clare@beauty.cl", "123984");
    sp = p2;           // sp now points to a Person [p2]
    cout << "Result of Comparing is that:\n" << cmp_result(p2, sp) << "\n\n";
    
    sp = p2;           // sp points to a Person [p2]
    sp2 = p;           // sp2 points to a Person [p]
    p->SetPhone("325643"); // we can change phone for p and sp at once
    cout << "Result of Comparing is that:\n" << cmp_result(p, sp) << "\n\n";
    
    delete sp;         // objects sp and p2 destroyed
    delete sp2;        // objects sp2 and p destroyed
    
    cin.ignore();
    return 0;
}
