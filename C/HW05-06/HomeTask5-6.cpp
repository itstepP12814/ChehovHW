/*
 * HomeTask5-6.cpp
 *
 *  Created on: 27 июня 2014 г.
 *      Author: felias
 */
#include <iostream>
using namespace std;


int prime_number() {//простые числа от 3 до 1000 
	cout<<"\t\tПростые числа от 3 до 1000"<<endl;
	int j;
	for(int i=3; i<=1000; i++){
		if(i%2==0){continue;}
		else{
			for(j=3; j<=7; j++){
				if (j%2==0){continue;}
				else{
					if(i%j==0){break;}
				}
			}
		}
		if(i==3||i==5||i==7) {cout<<i<<endl;}
		else{
		if(i%j==0){}
		else {cout<<i<<endl;}
		}
}
return 0;
}
int figure() {//прямоугольник
	cout<<"\t\tПрямоуглольник"<<endl;
	cout<<"\tВведи длину"<<endl;
	int lenght;//длина строки
	cin>>lenght;
	cout<<"\tВведи высоту"<<endl;
	int high;//количество строк
	cin>>high;
	for(int i=0; i<high; i++){
		if(i>0&&i<high-1){//если строчка не нулевая и не последняя, будем выполнять следующий цикл
		for(int j=0; j<lenght; j++) {
			if(j>0&&j<lenght-1){//если j не  нулевая и не последний символ в строке, выводим пробел
				cout<<" ";
			}
			else {
				cout<<"*";//иначе(т.е 0 и последний символ) выводим *
			}
		}
		cout<<endl;}//в конце каждой строки выводим endl;
	else{ //иначе i==0 и i==последней строке, будем выполнять этот цикл
		for(int k=0; k<lenght; k++) {
		cout<<"*";
		if(k==lenght-1){cout<<endl;}//Вместе с последней выводимой звездочкой выводим endl
			}
		}
	}
	return 0;
}
int calendar(){//каленьдарь
	cout<<"\t\tКалендарь"<<endl;
	for(int i=1; i<=31; i++){
		cout<<i<<" ";
		if(i%7==0){
			cout<<endl;
		}
	}

	return 0;
}
int arr_reverse(){//реверс массива
	const int size =3;
	int array[size];
	for(int i=0; i<size; i++){
		cout<<"\tвведи элемент массива\n";
		cin>>array[i];
	}
	cout<<"\tвведенные элементы массива"<<endl;
	for(int j=size-1; j>=0; j--){
		cout<<array[j]<<" ";
	}

	return 0;
}
int summ(){//сумма четных и нечетных чисел
	const int num= 10;
	int summ_odd=0;
	int summ_nodd=0;
	//int array[num]={15,18,28,54,66,92,111,78,93,53};
	int array[num];
	cout<<"\t\tСумма четных и нечетных чисел"<<endl;
	cout<<"\tвведите любые 10 чисел"<<endl;
	for(int j=0; j<num;j++){
		cin>>array[j];
	}

	for(int i=0; i<num; i++){
		if(array[i]%2==0){
			summ_odd=summ_odd+array[i];
		}
		else{
			summ_nodd=summ_nodd+array[i];
		}
	}
	cout<<"\tсумма четных чисел равна "<<summ_odd<<endl;
	cout<<"\tсумма нечетных чисел равна "<<summ_nodd<<endl;
	return 0;
}
int copy_detector(){//детектор одинаковых чисел
	const int size=10;
	int array[size]={15,18,28,18,65,79,15,97,97,55};
	int array2[size];
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(array[i]==array[j] && i!=j ){
				//cout<<array[i]<<",";
				array2[j]=array[i];
			}
			else {array2[i]=0;}
		}
	}
	cout<<"\tповторяющиеся числа в массиве"<<endl;
	for(int k=0; k<size; k++){
		if(array2[k]!=0){
		cout<<array2[k]<<endl;
		}
	}
	/* 1)Проверяем все числа массива array[] с копией массива, при этом индекс проверяемого числа не проверяется с таким же индексом в "копии", ибо иначе у нас будут совпадать
	 * все числа.Копия это сам же массив array, просто при сравнении масива с самим собой мы не проверяем такую же ячейку в так называемой копии
	 * 2)Если соблюдены условия т.е значение в одной ячейке массива равно такому же значению в другой ячейке "копии массива", то мы наткнулись на повторяющееся число
	 * 3)Переписываем ззначение из индекса копии в такой же индекс в array2[]
	 * 4)Если условия не соблюдаются записываем 0 в ячейку array2, имеющую такой же индекс как и проверяемая нами в array[]
	 * 5)Когда мы наконец наткнулись на второе повторяющееся число, мы делаем как бы реверс. Т.Е. в ячейку массива в array2 в которую было ранее вписано потворное значение
	 * копии записывается 0, а когда программа дойдет до первого потворяющегося числа, она записывает его значение в ячейку с индексом от array. Другими
	 * словами потворяется пункт 3 и 4.
	 * 6)В итоге получаем новый массив в котором будут только повторяющиеся значения в единственном числе, а все остальное заполнено нулями, и выводим все ненулевые значения
	 * П.с надеюсь я сам пойму то что тут написал...:)*/


	return 0;
}
int small(){//самые маленькие четные и нечетные числа
	const int size=10;
	int array[size]={97, 87,1,24,17,46,55,82,93,11};
	int digit=array[0];
	int odd_small=array[0];
	for(int i=0; i<size; i++){
		if(array[i]%2!=0&&digit>array[i]){
			digit=array[i];
		}
		else{
			if( array[i]%2==0&& odd_small>array[i]){
				odd_small=array[i];
			}
		}
	}
	cout<<"\tсамое меньшее нечетное число массива: "<<digit<<endl;
	cout<<"\tсамое меньшее четное число массива: "<<odd_small<<endl;
	return 0;
}

int main(){
	cout<<"\t\tHome Task 5, 6\n";
	//prime_number();
	//figure();
	//calendar();
	//arr_reverse();
	//summ();
	//copy_detector();
	//small();
	cout<<"\t\tEnd of programm\n";
	return 0;
}
