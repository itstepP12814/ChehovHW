#ifndef STRING_H
#define STRING_H


class String
{
public:
    String();
    String (char*);
    String(const String&);
    ~String();
    String operator*(const String&) const;
    void print()const;
protected:
    char* s;
};

#endif // STRING_H
