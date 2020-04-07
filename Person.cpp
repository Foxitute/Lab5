#include "Person.hpp"

Sortable::~Sortable() { }

Person const& Person::operator= (Person const &other)
{
    this->_name = other._name;
    this->_address = other._address;
    this->_phone = other._phone;
    
    return *this;
}

int Person::Compare (Sortable const &o) const
{
    Person const &other = (Person const &)o;

    // first try: if names unequal, we're done
    if ( this->_name != other._name )
        return false;
    // second try: compare by addresses
    if ( this->_address != other._address )
        return false;
    // third try: compare by phone_numbers
    return ( this->_phone == other._phone );
}
