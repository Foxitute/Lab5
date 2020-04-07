#ifndef Person_hpp
#define Person_hpp
#include <string>

using namespace std;

class Sortable
{
public:
    virtual ~Sortable();
    virtual int Compare (Sortable const& other) const = 0;
    virtual string GetName() const = 0;
};

class Person: public Sortable
{
public:
    // constructors, destructors, and stuff
    Person (string name, string add, string ph)
    : _name(name),_address(add),_phone(ph) { };
    Person (Person const& other);
    Person const& operator= (Person const &other);
    
    // interface
    string GetName () const override { return this->_name; }
    string GetAddress () const { return this->_address; }
    string GetPhone () const { return this->_phone; }
    void SetName (string name) { this->_name = name; }
    void SetAddress (string add) { this->_address = add; }
    void SetPhone (string ph) { this->_phone = ph; }

    // requirements enforced by Sortable
    int Compare (Sortable const& other) const override;

private:
    // data members
    string _name, _address, _phone;
};
#endif
