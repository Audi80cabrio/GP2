#include <iostream>
#include <map>
#include <string>

class Person
{
private:
    std::string name;
    std::string firstName;
    std::string contact;
public:
    Person(std::string pName, std::string pFirstName, std::string pContact)
    {
        name = pName;
        firstName = pFirstName;
        contact = pContact;
    }
    void send(std::string message)
    {
        std::cout << "message \"" << message
                  << "\" sent to " << contact << '\n';
    }
};

template <class T> class PersMap
{
private:
    std::map<std::string, T*> *entries = new std::map<std::string, T*>();
public:
    void add(std::string id, T *t)
    {
        entries->insert({id, t});
    }
    void send(std::string id, std::string message)
    {
        (*entries)[id]->send(message);
    }
};

int main()
{
    Person *donald = new Person("Duck", "Donald", "donald.duck@disney.com");
    PersMap<Person> *pmap = new PersMap<Person>();
    pmap->add("donald", donald);
    pmap->send("donald", "hello donald");

    /*std::string jenny("+0184123236");
    PersMap<std::string> *pmap2 = new PersMap<std::string>();
    pmap2->add("jenny", &jenny);
    pmap2->send("jenny", "hello jenny");*/

    return 0;
}
