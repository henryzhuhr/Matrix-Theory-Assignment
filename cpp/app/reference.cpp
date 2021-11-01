#include <iostream>
#include <string>
#ifndef PERSON_H
#define PERSON_H
class Person
{
  private:
    std::string name{"noName"};
    int         age{0};

  public:
    Person(/* args */);
    Person(std::string name, int age) : name(name), age(age){};
    ~Person();
    Person(Person& other) = default; // copy constructor
    Person& operator=(Person const& other) = default;

  public:
    friend std::ostream& operator<<(std::ostream& os, Person const& person);

  public:
    void SetAge(int age) { this->age = age; };
};
#endif
Person::~Person() {}
std::ostream& operator<<(std::ostream& os, Person const& person) { return os << "Person(" << person.name << "," << person.age << ")"; }


int main()
{
    // region value copy
    Person person          = Person("tim", 10);
    Person person_value_cp = person;
    person.SetAge(11);
    std::cout << "Value: " << person << std::endl;
    std::cout << "Value: " << person_value_cp << std::endl;


    // region reference copy
    Person& personRef_cp = person;
    person.SetAge(12);
    std::cout << "Reference: " << person << std::endl;
    std::cout << "Reference: " << personRef_cp << std::endl;
    personRef_cp.SetAge(13);
    std::cout << "Reference r: " << person << std::endl;
    std::cout << "Reference r: " << personRef_cp << std::endl;


    // region pointer copy
    Person* personPtr    = new Person("pointer", 10); // new in heap
    Person* personPtr_cp = personPtr;
    personPtr->SetAge(20);
    std::cout << "Reference: " << *personPtr << std::endl;
    std::cout << "Reference: " << *personPtr_cp << std::endl;
    delete personPtr;


    Person person_cp_cons = person;
    person_cp_cons        = person;
}