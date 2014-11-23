#ifndef DATE_H
#define DATE_H
class Date {
public:
    Date();
    Date(int, int, int);
    ~Date();
    void getDate() const;
    void enterDate(char*);
    int operator-(const Date&)const;
    void operator+=(int);
protected:
    int day;
    int month;
    int year;
};

#endif // DATE_H
