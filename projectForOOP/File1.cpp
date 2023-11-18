#include<iostream>
using namespace std;
class Ticket {
private:
	const int uniqueId;
	int row;
	int seat;
	char* zone;
public:
	static int ticketsSold;
	Ticket() :uniqueId(0) {//default constr
		this->row = 0;
		this->seat = 0;
		this->zone = "VIP";
	}
	//constr with parameters
	Ticket(int row, int seat, char* zone) :uniqueId(++ticketsSold) {
		this->row = row;
		this->seat = seat;
		this->zone = new char[strlen(zone) + 1];
		strcpy(this->zone, zone);
	}


};
class Event {
private:
	const char* nameOfEvent;
	int numberOfSeats;
[public:
	static int 
	
};
int main()
{
	cout << "De testare";
}