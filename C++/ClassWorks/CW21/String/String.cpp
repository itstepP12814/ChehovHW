#include "String.h"
String::String() {
    s=(char*)malloc(sizeof(char));
    s[0]=0;
    lenght=0;
    //ctor
}
String::String(const char *str) {
    lenght=strlen(str);
    s=(char*)malloc(lenght+1);
    strcpy(s, str);
}
String::String(const String &source) {
    lenght = source.lenght;
    s=(char*)malloc(lenght);
    strcpy(s, source.s);
}

String::~String() {
    free(s);
    //dtor
}

void String::printToStream(ostream &str) {
	str<<s;
}
