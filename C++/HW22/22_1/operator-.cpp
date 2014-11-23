#include "date.h"
int Date::operator-(const Date& D) const {
    int diff_day, diff_month, diff_year, diff_all;
    if(year<D.year) diff_year=D.year-year;//разница в годах между датами
    else diff_year=year-D.year;

    if(month<D.month) diff_month=D.month-month;//в месяах
    else diff_month=month-D.month;

    if(day<D.day) diff_day=D.day-day;//в днях
    else diff_day=day-D.day;

    diff_all=(365*diff_year)+(31*diff_month)+diff_day;//общая разница в днях
    return diff_all;
}
