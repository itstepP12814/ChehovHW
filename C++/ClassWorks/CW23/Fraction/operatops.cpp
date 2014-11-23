#include "fraction.h"
#include <iostream>
using namespace std;

const Fraction Fraction::operator+(const Fraction &second_fract){
    int num, denom;
    num = (this->numerator)*(second_fract.denominator)+(second_fract.numerator)*(this->denominator);
    denom = this->denominator*second_fract.denominator;
    Fraction result(num, denom);
	return result;
}
const Fraction Fraction::operator-(const Fraction &second_fract){
 int num, denom;
    num = (this->numerator)*(second_fract.denominator)-(second_fract.numerator)*(this->denominator);
    denom = this->denominator*second_fract.denominator;
    Fraction result(num, denom);
	return result;
}
const Fraction Fraction::operator*(const Fraction &second_fract){
 int num, denom;
    num = this->numerator*second_fract.numerator;
    denom=this->denominator*second_fract.denominator;
    Fraction result(num, denom);
	return result;
}
const Fraction Fraction::operator/(const Fraction &second_fract){
 int num, denom;
    num = this->numerator*second_fract.denominator;
    denom=this->denominator*second_fract.numerator;
    Fraction result(num, denom);
	return result;
}
const Fraction Fraction::operator++(){
 int num, denom;
    num = (this->numerator)*2;
    denom=this->denominator;
    Fraction result(num, denom);
	return result;
}
const Fraction Fraction::operator--(){
 int num, denom;
    num = this->numerator-this->denominator;
    denom =this->denominator;
    Fraction result(num, denom);
	return result;
}
void Fraction::print() const {
    cout<<this->numerator<< "/" <<this->denominator <<endl;
}
