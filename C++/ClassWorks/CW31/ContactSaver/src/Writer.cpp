#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct person
{
    string name;
    string number;
};

class Writer
{
public:
    Writer()
    {
    }
    virtual void write(person* people, int size)=0;
    virtual ~Writer() {}
};

class Writer_json: public Writer
{
public:
    Writer_json()
    {
    }
    virtual void write(person* people, int size)
    {
        ofstream output ("contacts.json", ofstream::out);
        output<<"[";
        for(int i=0; i<size; ++i)
        {
            output<<"{name:\""<<people[i].name<<"\", "<<"number:\""<<people[i].number<<"\"}";
            if(i!=size-1) output<<", ";
        }
        output<<"]";
        output.close();
    }
    virtual ~Writer_json() {}
};

class Writer_xml:public Writer
{
public:
    Writer_xml()
    {
    }
    virtual void write(person* people, int size)
    {
        ofstream output ("contacts.xml", ofstream::out);
        for(int i=0; i<size; ++i)
        {
            output<<"<person>\n\t<name>"<<people[i].name<<"</name>\n";
            output<<"\t<number>"<<people[i].number<<"</number>\n";
            output<<"</person>\n\n";
        }
        output.close();
    }
    virtual ~Writer_xml() {}
};

class Writer_csv:public Writer
{
public:
    Writer_csv()
    {
    }
    virtual void write(person* people, int size)
    {
        ofstream output ("contacts.csv", ofstream::out);
        for(int i=0; i<size; ++i)
        {
            output<<"\""<<people[i].name<<"\";"<<people[i].number<<"\n";
        }
        output.close();
    }
    virtual ~Writer_csv() {}
};
class Writer_txt: public Writer
{
public:
    Writer_txt()
    {
    }
    virtual void write(person* people, int size)
    {
        ofstream output ("contacts.txt", ofstream::out);
        for(int i=0; i<size; ++i)
        {
            output<<people[i].name<<"\n";
            output<<people[i].number<<"\n\n";
        }
        output.close();
    }
    virtual ~Writer_txt() {}
};

int main()
{
    const int size=3;
    person people[size]= {{"Jhon","11223344"}, {"Mark", "66778899"}, {"Andrew", "1009199"}};
    Writer* all[4]= {new Writer_json, new Writer_txt, new Writer_xml, new Writer_csv};

    for(int i=0; i<4; ++i)
    {
        all[i]->write(people, size);
    }
    cout<<"all done"<<endl;
    return 0;
}
