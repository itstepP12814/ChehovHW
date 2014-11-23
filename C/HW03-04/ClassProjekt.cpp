/*
 * ClassProjekt.cpp
 *
 *  Created on: 28 июня 2014 г.
 *      Author: felias
 */

#include <iostream>
#include<cstdlib>
#include <fstream>//для работы с выводом в файл
#include <ctime>
using namespace std;

int task6_1() {
	//srand(time(NULL));
		ofstream out("/home/felias/x.csv");
		out<<"3;7;-1\n 2;15\n";
		//for(int i=0; i<100; i++) {
			//out<<(rand()%10)<<";"<<(rand()%25-12)<<endl;}


	return 0;
}
int fx(){//использование записи в файл и рандомизации
	srand(time(NULL));//автоматизирует рандомизацию
	int startRate=10200;
	int maxChange=50;
	int rate = startRate;
	int exp, days;
	days=31;
	int random_value, delta, average_delta;
	int delta_summ=0;
	exp=1000;
	ofstream rateFileOutput("/home/felias/rates.csv");// функция ofstream называется rateFileOutput("путь/к/файлу/название.расширение");
rateFileOutput<<"Дни"<<"\tСумма редних отклонений за периоды\n";
for(int k=0;k<10;k++){
	for(int j=0; j<exp; j++){
	rate=startRate;
	for(int i=0; i<days; i++){
		random_value=rand()%(2*maxChange+1)-maxChange;//rand()%(число или выражение +1) Устанавливает коэффицент для рандома в котором он будет работать. в нашем случае от 0 до 100
		rate=rate+random_value;//изменения будут от 0-50 минимально до 100-50 максимально, т.е от -50 до 50
	}
			delta=startRate-rate;
			delta=abs(delta);
			delta_summ=delta_summ+delta;
	}
average_delta=delta_summ/exp;
rateFileOutput<<days<<"\t"<<average_delta<<endl;
days*=2;
}
/* Дельта - это разница между курсом 31 дня и начальным, мы считаем 1000 таких дельт и потом находим среднее. Далее, мы умножаем количество дней до 62, и находим дельту
 * между 61 днем и начальным курсом и снова считаем 1000 таких дельт. Далее повторяем для 122 дней, тоже находим сумму и среднее 1000 таких дельт. и так повторяем столько раз
 * сколько у нас раз проводиться 1000 экспериментов, а у нас проводиться в данном случае 10 раз по 1000 экспериментов и в каждом последующей тысяче, количество дней
 * умножается на двое*/
	return 0;
}
int task7_brainfuck(){//кривой интерпритатор брейнфака
	cout<<"\tвведите символы\n";
	char a;
	const int size=256;
	char array[size];
	int i=0;
	for(i=0; i<size; ++i){
		array[i]=0;
	}
	int j=0;
	for( ;a!=';'; ){
		cin>>a;
		switch (a){
		case '+': array[j]++;
		break;
		case '-': array[j]--;
		break;
		case'>':++j;
		break;
		case'<':--j;
		break;
		case '.': cout<<array[j];
		break;
		case ';':break;
		case'\0':break;
		default: cout<<"\tневерный оператор\n";
		break;
		}
	}
	return 0;
}
int main() {
	//task6_1();
	//fx();
	//task7_brainfuck();
}




