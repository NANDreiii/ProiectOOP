#include<iostream>
using namespace std;
class Ticket {
private:
	const int uniqueId;
	int row;
	int seat;
	int price;//added
	char* zone;
public:
	static int ticketsSold;
	Ticket() :uniqueId(0) {//default constr
		this->row = 0;
		this->seat = 0;
		this->price = 0;
		this->zone = NULL;
	}
	//constr with parameters
	Ticket(int row, int seat, int price, char* zone) :uniqueId(++ticketsSold) {
		this->row = row;
		this->seat = seat;
		this->price = price;
		this->zone = new char[strlen(zone) + 1];
		strcpy(this->zone, zone);
	}


};
class Location {
	int maxNumberSeats;
	int numberOfRows;
	int zones;

};
class Event {
private:
	const int eventId;//added
	char* nameOfEvent;
	int numberOfSeats;
[public:
	//default constr
	Event() :eventId(0) {
		this->nameOfEvent = NULL;
		this->numberOfSeats = 0;
	}
	

	
};
int main()
{
	cout << "De testare";
}