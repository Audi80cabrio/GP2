#include <iostream>
#include <map>
#include <string>
#include <type_traits>

class ISendable
{
public:
    virtual void send(std::string) = 0;
};

template <typename T>
concept Callable = std::is_base_of_v<ISendable, T>;

class Person : public ISendable
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

template <Callable T> class PersMap
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
