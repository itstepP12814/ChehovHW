#include <iostream>
#include "List.h"
using namespace std;

int main() {
    string str, filter_word;
    filter_word="lol";
    int count=0;//количество слов в нашем списке
    List A(filter_word);
    cout<< "filter word: lol" <<endl;
    while(str.back()!='.') {
        cin >> str;
        A.push_back(str);
        count++;
    }
    cout<<endl;
    A.parser(count);
    cout<<endl;
    A.show(count);
    return 0;
}
