
/*
 * HomeTask2.cpp
 *
 *  Created on: 16 июня 2014 г.
 *      Author: felias
 */

#include<stdio.h>
#include<iostream>
using namespace std;

int endless() {cout<<"\t\tEnd\n";
return 0;
}

int millionare() {
	//кто хочет стать миллионером
		char answer, cont, restart;
		answer = '1';
		cont = 'y';
		int score =0;
		cout<<"\n"<<"\t\tКто хочет стать миллионером\n";
		cout<<"\t\tДля ответа на вопрос выберите один из четырех вариантов \"a\" , \"b\", \"c\", \"d\" \n";
		cout<<"\t\tГотовы? Первый вопрос \n";
		cout<<"\t\tКакое здание самое высокое в мире?\n";
		cout<<"\t\tВведите ваш ответ\n"<<"\t\ta) Мой дом\n"<<"\t\tb)Небесное дерево в Токио\n"<<"\t\tc)Бурдж халифа\n"<<"\t\td) Минская телевышка\n";
		cin>>answer;
		switch (answer) {
								case 'A':
								case 'a':
											cout<<"\t\tВероятно, вам очень повезло, но к сожелению ответ неверный\n";
											break;
								case 'B':
								case 'b':
											cout<<"\t\tНеплохая попытка, но это неправильный ответ\n";
											break;
								case 'C':
								case 'c':
											cout<<"\t\tДа, это действительно самый высокйи в мире небоскреб\n";
											score+=100;
											cout<<"\t\tУ Вас "<<score<<" $\n"<<"\t\tжелаете продолжить игру?\n";
											cout<<"\t\tвведите \"y\" если желаете продолжить и \"n\" если желаете забрать деньги\n";
											cin>>cont;
											switch (cont) {
																		case 'y':
																		case 'Y':
																			cout<<"\t\tок, мы продолжаем. Следующий вопрос\n"<<"\t\tВ каком году родился А.С.Пушкин?\n";
																			cout<<"\t\ta)1799 b) 1817\n"<<"\t\tc)1783 d)1917 \n"<<"\t\tвведите Ваш ответ\n";
																			cin>>answer;
																			switch (answer) {
																									case 'a':
																									case 'A':
																									cout<<"\t\tДа, это правильный ответ\n";
																									score+=100;
																									cout<<"\t\tВы заработали "<<score<<" $\n";
																									cout<<"\t\tЖелаете продолжать? Выберете \"y\" или \"n\" \n";
																									cin>>cont;
																												switch (cont) { case 'y':
																																		case 'Y':
																																		cout<<"\t\tok, мы продолжаем играть\n";
																																		cout<<"\t\tСледующий вопрос. Кто разработкал язык C?\n";
																																		cout<<"\t\ta) Пушкин с) Дэнис Ритчи\n";
																																		cout<<"\t\tb)Билл Гейтс d)Стив Джобс\n";
																																		cout<<"\t\tВведите вариант ответа\n";
																																		cin>>answer;
																																		switch (answer) { case 'a':
																																									case 'A':
																																									cout<<"\t\tХорошая попытка, но нет, это был не пушкин\n";
																																									score=0;
																																									break;
																																									case 'b':
																																									case 'B':
																																									cout<<"\t\tБилл разработал кое что другое, но не язык Си\n";
																																									score=0;
																																									break;
																																									case 'c':
																																									case 'C':
																																									cout<<"\t\tДа, это верный ответ\n";
																																									score+=300;
																																									break;
																																									case 'd':
																																									case 'D':
																																									cout<<"\t\tДжобс безсулсовно великий человек, но язык Си придумал не он\n";
																																									score=0;
																																									break;
																																									default:cout<<"\t\tНекорректный символ\n";
																																									break;

																																		}
																																		break;
																																		case 'n':
																																		case 'N':
																																		cout<<"\t\tок,Вы забрали деньги\n";
																																		break;
																																		default:cout<<"\t\tНекорректный символ\n";
																																		break;

																												}

																									break;

																									case 'b':
																									case 'B':
																									cout<<"\t\tНеправильный ответ\n";
																									score=0;
																									break;

																									case 'c':
																									case 'C':
																									cout<<"\t\tНеверно\n";
																									score=0;
																									break;

																									case 'd':
																									case 'D':
																									cout<<"\t\tЭто неправильный ответ\n";
																									score=0;
																									break;
																									default:cout<<"\t\tНекорректный символ\n";
																									break;
																								}
																	break;
																	case 'n':
																	case'N':cout<<"\t\toк, игра окончена\n";
										                            break;
																	default:cout<<"\t\tНекорректный символ\n";
																	break;
																			}
																	break;
								case 'D':
								case 'd':
								cout<<"\t\tЯ тоже люблю свой город, но это неправильной ответ =( \n";
								break;
								default:cout<<"\t\tНекорректный символ\n";
								break;
								}

		if (answer=='a' || answer=='b' || answer=='c' || answer=='d' || answer=='A'|| answer=='B' || answer=='C'|| answer=='D') {
								if (cont=='y' || cont == 'n') {
																				if (score == 0) {
																				cout<<"\t\tВаш выигрыш составил "<<score<<" $\n";
																				cout<<"\t\tВы можете перезапустить программу и попробовать снова\n";
																																							cout<<"\t\tСыграть еще раз?\n";
																																							cout<<"\t\tEnter \"y\" or \"n\" \n";
																																							cin>>restart;
																																							if (restart == 'y') {
																																								millionare();
																																								}
																																							else {if (restart == 'n') endless();}
																					}
																				else {cout<<"\t\tВаш Выигрыш составил "<<score<<" $\n"<<"\t\tВы молодец!\n";
																					cout<<"\t\tСыграть еще ?\n";
																					cout<<"\t\tEnter \"y\" or \"n\" \n";
																					cin>>restart;
																					if (restart == 'y') {
																						millionare();
																						}
																					else {if (restart=='n') endless();}
																					}
																			}
							else 	{cout<<"\t\tOшибка. Пожалуйста, перезапустите программу и выбирете один из 4 ответов\n";
									printf("\t\tСыграть еще раз?\n");
									cout<<"\t\tEnter \"y\" or \"n\" \n";
									cin>>restart;
									if (restart == 'y') {
																millionare();
																}
									else {if (restart=='n') endless();}
							}
				}
			else { cout<<"\t\tOшибка. Пожалуйста, перезапустите программу и выбирете один из 4 ответов\n";

			printf("\t\tСыграть еще раз?\n");
			cout<<"\t\tEnter \"y\" or \"n\" \n";
			cin>>restart;
			if (restart == 'y') {
				millionare();
				}
			else {if (restart=='n') endless();}
			}
return 0;
};

int main () {
	//проверка четности числа
	int a;
	int b;
	cout<<"\t\tParity Checker\n";
	cout<<"\t\tplease enter the digit\n";
	cin>>a;
	b=a%2;
	if (b==0){ cout<<"\t\tParity digit!!!\n\n";}
	else cout<<"\t\tNot parity Digit\n\n";


	//количество цифр в числе, и сумма цифр
	int number, d, e;
	cout<<"\t\tNumber and summ of digits\n";
	cout<<"\t\tPlease enter the number from 0 to 99\n";
	cin>>number;
	d=number/10;
	e=number%10;
	cout<<"\t\tok, your number is "<<number<<"\n";
	if (number>=0 && number<=9) {
		cout<<"\t\tyour number consist from 1 digit\n";
		cout<<"\t\tsumm of digits is "<<number<<"\n\n";
			}
	else if (number>=10 && number<=99) {
		cout<<"\t\tyour number consist from 2 digits\n";
		cout<<"\t\tsumm of digits in your number is "<<d+e<<"\n\n";
			}
		else cout<<"\t\tError!!! Please select number from 0 to 99\n\n";

	//дюйм-сантиметр конвертер
	float inch, cm;
	char ch;
	cout<<"\t\tInch and cm converter\n";
	cout<<"\t\tPlease select your metric system\n"<<"\t\tpress \"i\" if you select inch\n"<<"\t\tpress \"c\" if you select cm\n";
	cin>>ch;
	if (ch=='i' || ch=='I') {
		cout<<"\t\tenter inch\n";
		cin>>inch;
		cout<<"\t\tok, "<<inch<<" inch it's "<<inch*2.54<<" cm\n\n";
		}
	else { if (ch=='c' || ch=='C') {
		cout<<"\t\tenter cm\n";
		cin>>cm;
		cout<<"\t\tok, "<<cm<<" cm it's "<<cm/2.54<<" inch\n\n";
		}
		else{ cout<<"\t\tError!!! Please select cm or inch\n\n";
		}
	}

	millionare();
	return 0;
}


