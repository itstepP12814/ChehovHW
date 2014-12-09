#include "Time.h"
#include <cstring>
#include <stdlib.h>
MyTime::MyTime() {
    mytime=new mytm;
    t=time(NULL);
    aTm=localtime(&t);
    mytime=new mytm;
    mytime->hour=aTm->tm_hour;
    mytime->min=aTm->tm_min;
    mytime->sec=aTm->tm_sec;
    //ctor
}
MyTime::MyTime(char* str) {
	mytime=new mytm;
	setTime(str);
}
MyTime ::MyTime(MyTime& t1) {
    MyTime* t2=new MyTime;
    t2->mytime->hour=t1.mytime->hour;
    t2->mytime->min=t1.mytime->min;
    t2->mytime->sec=t1.mytime->sec;
}
MyTime::~MyTime() {
    //dtor
}
void MyTime::getTimeEu()const {
    printf("%02d:%02d:%02d \n", mytime->hour, mytime->min, mytime->sec);
}
void MyTime::getTimeUs()const {
    if(mytime->hour>12) {
        printf("%02d:%02d:%02d pm\n", mytime->hour-12, mytime->min, mytime->sec);
    } else {
        printf("%02d:%02d:%02d am\n", mytime->hour, mytime->min, mytime->sec);
    }
}
void MyTime::convert(char *str) {
    char f[3];
    int res = sscanf(str,"%02d:%02d:%02d %s", &mytime->hour, &mytime->min, &mytime->sec, &f);
    //проверки
    if ((res == 0) || (mytime->hour<0) || (mytime->hour>12)) {
        cout<<"\tError in set hour\n";
        exit(0);
    }
    if ((res == 1) || (mytime->min<0) || (mytime->min>59)) {
        cout<<"\tError in set minutes\n";
        exit(0);
    }
    if ((res == 2) || (mytime->sec<0) || (mytime->sec>59)) {
        cout<<"\tError in set seconds\n";
        exit(0);
    }
    if( (res==3) || (strcmp(f, "am")!=0 && strcmp(f, "pm")!=0)) {
        cout<<"\tError data format\n";
        exit(0);
    }
    //сама конвертация
    if(strcmp(f, "pm")==0) {
        mytime->hour+=12;
    }
}
void MyTime::setTime(char* str) {
    int res = sscanf(str,"%02d:%02d:%02d", &mytime->hour, &mytime->min, &mytime->sec);
    if ((res == 0) || (mytime->hour<0) || (mytime->hour>23)) {
        cout<<"\tError in set hour\n";
        exit(0);
    }
    if ((res == 1) || (mytime->min<0) || (mytime->min>59)) {
        cout<<"\tError in set minutes\n";
        exit(0);
    }
    if ((res == 2) || (mytime->sec<0) || (mytime->sec>59)) {
        cout<<"\tError in set seconds\n";
        exit(0);
    }
}
MyTime MyTime::operator+(const MyTime& t1) const {
    MyTime t2;
    t2.setTime("00:00:00");
    t2.mytime->sec+=t1.mytime->sec+this->mytime->sec;
    if(t2.mytime->sec>=60) {
        t2.mytime->sec-=60;
        t2.mytime->min+=1;
    }
    t2.mytime->min+=t1.mytime->min+this->mytime->min;
    if(t2.mytime->min>=60) {
        t2.mytime->min-=60;
        t2.mytime->hour+=1;
    }
    t2.mytime->hour+=t1.mytime->hour+this->mytime->hour;
    if(t2.mytime->hour>=24) {
        t2.mytime->hour-=24;
    }
    return t2;
}
MyTime MyTime::operator-(const MyTime& t1) const {
    MyTime t2;
    t2.setTime("00:00:00");
    t2.mytime->sec=this->mytime->sec-t1.mytime->sec;
    if(t2.mytime->sec<0) {
        t2.mytime->sec=60+t2.mytime->sec;
        t2.mytime->min-=1;
    }
    t2.mytime->min+=this->mytime->min-t1.mytime->min;
    if(t2.mytime->min<0) {
        t2.mytime->min=60+t2.mytime->min;
        t2.mytime->hour-=1;
    }
    t2.mytime->hour+=this->mytime->hour-t1.mytime->hour;
    if(t2.mytime->hour<0) {
        t2.mytime->hour=24+t2.mytime->hour;
    }
    return t2;
}
int MyTime::operator==(const MyTime& t1) const {
    if(t1.mytime->hour==this->mytime->hour && t1.mytime->min==this->mytime->min && t1.mytime->sec==this->mytime->sec) return 1;
    else return 0;
}
