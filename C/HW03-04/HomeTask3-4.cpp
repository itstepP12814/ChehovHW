/*
 * HomeTask3-4.cpp
 *
 *  Created on: 16 июня 2014 г.
 *      Author: felias
 */

#include<stdio.h>
#include<iostream>
using namespace std;

int horizontal_line() {//горизонтальная и вертикальная линия звездочек
	int a=0;
	int b=0;
	while (a<10) { cout<<"*"; a++;}
	while (b<10) {cout<<"*"<<endl; b++;}
return 0;
}
int sum_odd() { //сумма всех целых нечетных чисел
	cout<<"\n\t\tThe summ of all odd numbers\n";
	int first_number, second_number;
	int i, summ;
	summ=0;
	cout<<"\t\tEnter first number\n";
	cin>>first_number;
	cout<<"\t\tEnter second number\n";
	cin>>second_number;
	for(i=first_number; i<=second_number; i++) {
		if(i%2!=0) { summ=summ+i;}
		else{}
		}
cout<<"\t\tSumm of odd numbers"<<summ<<endl;
return 0;
}
int factorial() {//факториал
	cout<<"\n\t\tFactorial programm\n";
	unsigned long long int fact=1;
	unsigned long long int i=1;
	unsigned long long int n;
	cout<<"\t\tEnter factorial number\n";
	cin>>n;
	cout<<"\t\tfactorial\n";
	while( i<=n ) { fact*=i; cout<<fact<<endl; i++; }
	//for(i; i<=n; i++) { fact=fact*i;	cout<<fact<<endl;	}
	return 0;
}

int elka_cool() {//ееее
	int a, b, c, d, lv, k, prob, zvezd, cn, constprob;
	cout<<"\t\telka v3.0\n";
	cout<<"\t\tвведите количество ярусов\n";
	cin>>d;//кол-во ярусов
	cout<<"\t\tвведите количество уровней\n";
	cin>>lv;
	//cout<<"\t\tвведите начальное количество звездочек в ярусе\n";//начальное количество звезд в ярусе
	//cin>>c;
	cout<<"\t\tполучи елку!\n";
	constprob=d;
	prob=d+lv;
	c=1;
	zvezd=c;
	for(;k<lv;){
		for(;prob>0;) {//выполнять пока ярусов не станет 0
			for(a=prob; a>=0; a--){cout<<" ";if(a==0){cout<<"/";}}//выводит столько пробелов сколько ярусов, потом ставит /
			for(b=1;b<=zvezd;b++){cout<<"*";if(b==zvezd){cout<<"\\"<<endl;}}//вывод количество зведочек на две больше в каждом новом ярусе
			cn=0; cn++;
			prob=prob-cn; zvezd=zvezd+2;
	 }
		k=0; k++;
		prob=constprob+lv; zvezd=c;
	}

	return 0;
}

int elka_v4() {
	int i;
	for(i=0; i<=1; i++){cout<<i<<endl;}
	cout<<i;//0, 1;
	return 0;
}

int digit(){
	for(;;){
	cout<<"\t\tВведите число\n";
	long long int digit, a, summ, b, i;
	summ=0;
	cin>>digit;
	b=digit;
	for(;;){
		a=digit%10;//123%10=3	12%10=2	 1%10=1
		digit=digit/10;//123/10=12	12/10=1	1/10=0;
		summ=summ+a;
		cout<<a;
		if(digit==0){break;}
		}

	if(b>=0&&b<=9){i=1;}
	else{for(i=1;i<=b; i++){b=b/10;}}

	cout<<endl;
	cout<<"\t\tсумма цифр числа "<<summ<<endl;
	cout<<"\t\tв числе "<<i<<" цифр\n";
	cout<<"\t\tеще раз? y или n\n";
	char answer;
	cin>>answer;
	if(answer!='y'){break;}
	}

	return 0;
}

int main() {
cout<<"\t\t\t\tHome Task 3, 4"<<endl;
horizontal_line();
//sum_odd();
//factorial();
//elka_cool();
//elka_v4();
//digit();
cout<<"\t\t\t\tEnd of programm"<<endl;
return 0;
}




