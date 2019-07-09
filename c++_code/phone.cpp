#include<iostream>
#include<memory>
using std::cin;
using std::cout;
using std::endl;


class Person;
class Phone;

class Phone
{
public:
    Phone(const long &phonenumber,const std::string &owener,const std::string &phonetype):
        PhoneNumber(phonenumber),Owener(owener),PhoneType(phonetype)
         {}

public:
    long PhoneNumber;
    std::string Owener;
    std::string PhoneType;
};


class Person
{
public:
    Person(const std::string &name,const int &age):Name(name),Age(age)
    {}

    void GetPhone(std::shared_ptr<Phone> myphone)
    {
        this->phone=myphone;
    }

    void PrintfMessage()
    {
        cout<<"name:"<<this->Name<<endl;
        cout<<"age:"<<this->Age<<endl;
        cout<<"PhoneNumber:"<<this->phone->PhoneNumber<<endl;
        cout<<"PhoneType:"<<this->phone->PhoneType<<endl;
    }
    ~Person()
    {
         cout<<"this person is die"<<endl; 
    }

private:
    std::string Name;
    int Age;
    std::shared_ptr<Phone> phone;

};


void func()
{
    std::unique_ptr<Person> p1(new Person("nmsl",20));
    std::shared_ptr<Phone> phone1(new Phone(15350015763,"nmsl","huawei"));
    p1->GetPhone(phone1);
    p1->PrintfMessage();

}







int main()
{
    func();
    system("pause");
    return 0;
}





