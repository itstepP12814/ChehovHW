#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <Time.h>
using namespace std;

class Stop {
public:
	Stop(int Time, string name_) :
		TimeToNext(Time), name(name_)
	{};
	int TimeToNext;
	string name;
};

vector<Stop> route{
	Stop(50, "Kupalauskaja"),
	Stop(70, "Niamiha"),
	Stop(90, "Frunzenskaja"),
	Stop(75, "Maladzezhnaja"),
	Stop(75, "Frunzenskaja"),
	Stop(57, "Niamiha"),
	Stop(50, "Kupalauskaja"),
	Stop(45, "Pershamajskaja"),
};

class Bus {
public:
	static int busLastNumber;
	int number;
	Bus(vector<Stop>::iterator initialPosition) :
		position(initialPosition), number(++busLastNumber)
	{};
	Bus(const Bus& orig) :
		position(orig.position), number(++busLastNumber){};
	//
	vector<Stop>::iterator position;
};

int Bus::busLastNumber = 0;

class Event {
public:
	int Time;
	Event(int Time_) : Time(Time_) {};
	virtual void process() = 0;
};

multimap<int, Event*> events;

// bus arrives on a stop
class BusEvent : public Event {
public:
	// which bus gonna come
	Bus &bus;
	BusEvent(int Time_, Bus& bus_) :
		Event(Time_), bus(bus_)
	{}
	virtual void process() {
		// 
		cout << Time << " A bus " << bus.number << " arrives at " << bus.position->name << endl;
		// get next stop;
		bus.position++;
		if (bus.position == route.end()){
			bus.position = route.begin();
		}
		int t = Time + bus.position->TimeToNext;
		events.insert(
			pair<int, Event*>(
			t, new BusEvent(t, bus)
			)
			);
	};
};


int main() {

	vector<Bus> park(10,
		Bus(route.begin())
		);
	for (size_t i = 0; i < park.size(); i++) {
		int t = i * 30;
		events.insert( pair<int, Event*>(t, new BusEvent(t, park[i])) );
	}


	while (events.size() > 0) {


		// get event
		Event *ev = events.begin()->second;
		int Time = events.begin()->first;

		// remove event from queue
		events.erase(events.begin());

		// do something
		ev->process();

		// dispose event
		delete ev;

		int s = time(0);
		while (s == time(0));

	}

	system("pause");

}
