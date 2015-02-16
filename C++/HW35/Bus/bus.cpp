#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//остановка
class Stop {
public:
	Stop(int Time, string name_) : TimeToNext(Time), name(name_){}
	int TimeToNext;//время до следующей остановки
	string name;
};
// глобальный массив остановок со списковой инициализацией
vector<Stop> route{
	Stop(50, "Kupalauskaja"),
	Stop(70, "Niamiha"),
	Stop(90, "Frunzenskaja"),
	Stop(75, "Maladzezhnaja"),
	Stop(75, "Pushkinskaya"),
	Stop(57, "Spartiunaya"),
	Stop(50, "Kuncevshina"),
	Stop(45, "Kamennaya gorka"),
};

class Bus {
public:
	static int busLastNumber;
	int number;
	Bus(vector<Stop>::iterator initialPosition) : position(initialPosition), number(++busLastNumber) {};
	Bus(const Bus& orig) : position(orig.position), number(++busLastNumber){};
	//указатель на позицию автобуса
	vector<Stop>::iterator position;
};
int Bus::busLastNumber = 0;//самый первый автобус имеет номер 0, его мы жертвуем на копирование для все остальных автобусов

//пассажир
class Passenger {
public:
	Passenger(){}
	Passenger(vector<Stop>::iterator initPos, string name_, int counter) :position(initPos), name(name_), positionCounter(counter), currentBus(NULL){}
	Passenger(const Passenger& passenger_) : position(passenger_.position), name(passenger_.name), positionCounter(passenger_.positionCounter), currentBus(passenger_.currentBus){}
	string name;
	vector<Stop>::iterator position;
	int positionCounter;//количество остановок, которое необходимо проехать пассажиру
	Bus* currentBus;
};

//событие, класс от которого мы отнаследуем совершение конкретного события
class Event {
public:
	int Time;//время события
	Event(int Time_) : Time(Time_) {}
	virtual void process() = 0;
	//создаем чисто виртуальный метод, это гарантирует, что мы не сможем создать объект чисто базового класса Event.
};

//Б-дерево из событий, multimap даст нам возможность запрограммировать несколько одинаковых событий в один момент времени
multimap<int, Event*> events;

// случайное событие: приход автобуса на остановку
class BusEvent : public Event {
public:
	// which bus gonna come
	Bus &bus;
	BusEvent(int Time_, Bus& bus_) : Event(Time_), bus(bus_){}//конструктор события прихода создает объект класса Event
	virtual void process() {//обработка случайного события
		cout << Time << " A bus " << bus.number << " arrives at " << bus.position->name << endl;
		// планирование следующей остановки
		bus.position++;
		if (bus.position == route.end()){
			bus.position = route.begin();
		}
		int t = Time + bus.position->TimeToNext;//время до следующей остановки + время текущее время настуления события
		events.insert(pair<int, Event*>(t, new BusEvent(t, bus)));//вставка события в массив событий.
		//по сути планирование следующего прихода на остановку
	}
};
//событие прихода пассажира на остановку
class PassengerEvent : public Event{
public:
	Passenger& passenger;
	PassengerEvent(int Time_, Passenger& passenger_) : Event(Time_), passenger(passenger_){}
	virtual void process(){
		cout << Time << "A passenger " << passenger.name << " come to " << passenger.position->name << endl;
	}
};

int main() {
	srand(time(NULL));
	vector<string> names{ "Andrev", "Chashbr", "Kostya", "Max", "Aragorn" };
	//создаем овтобусный парк, 10 автобусов, первый мы инициализируем временным объектом Bus, все последующие инициализируем оператором копирования для временного Bus
	vector<Bus> park(10, Bus(route.begin()));

	for (size_t i = 0; i < park.size(); i++) {//инициализируем массив событий прихода автобусов-по сти расписание
		int t = i * 30;
		events.insert(pair<int, Event*>(t, new BusEvent(t, park[i])));
	}

	Passenger* p = NULL;
	while (events.size() > 0) {
		if (!p){
			p = new Passenger(route.begin() + rand() % (route.size() - 1), names[rand() % (names.size() - 1)], rand() % route.size()+1);
			cout << "passenger " << p->name << " come to " << p->position->name << endl;
		}

		// get event
		Event *ev = events.begin()->second;
		int Time = events.begin()->first;
		//мы удаляем совершившиеся событие из очереди событий
		events.erase(events.begin());

		/* а тут мы как-то обрабатываем свершившееся событие, кстати в момент обработки текущго события
		в очередь бобавляется следующшее планируемое событие. Т.е одно событие произошло автобус пришел на сотановку, мы удалили
		событие из очереди, а тут же автобус запланировал себе приход на следующую остановку, и мы добавлили новое событие в очередь*/
		ev->process();

		if (p->currentBus == NULL){
			for (size_t j = 0; j < park.size(); ++j){//посадили пассажира на автобус
				if (park[j].position == p->position){
					p->currentBus = &park[j];
					p->position = p->currentBus->position;
					cout << "Passenger " << p->name << " take a bus number " << park[j].number << " and need to pass " << p->positionCounter << " stations" << endl;
					break;
				}
			}
		}

		if (p->currentBus != NULL && p->position != p->currentBus->position){
			p->position = p->currentBus->position;
			(p->positionCounter)--;
			if (p->positionCounter == 0){
				cout << "Passenger " << p->name << " was gone from bus number " << p->currentBus->number << endl;
				delete p;
				p = NULL;
			}
		}

		// удаляем указатель на событие
		delete ev;

		int s = time(0);
		while (s == time(0));
	}

}
