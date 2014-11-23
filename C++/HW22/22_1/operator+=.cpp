#include "date.h"
void Date::operator+=(int number_of_days) {
    int all_days;//переменная для хранения общего числа дней в дате
    int ost_days;//переменная для хранения остатка дней
    all_days=365*year+31*month+day+number_of_days;
    year=all_days/365;
    ost_days=all_days%365;
    month=ost_days/31;
    ost_days%=31;
    day=ost_days;
}
