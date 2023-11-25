#include<iostream>
using namespace std;
enum class zonesOfEvent { VIP, zone1, zone2};
class Ticket {
private:
	const int uniqueId = 0;
	int row = 0;
	int seat = 0;
	int price = 100;
	bool isValid = true;
	char* zone = nullptr;
	int ageOfPeople[6] = { 18 };
public:
	static int soldTickets; 
	//getters
	int getUniqueId()
	{
		return this->uniqueId;
	}
	int getRow()
	{
		return this->row;
	}
	int getSeat()
	{
		return this->seat;
	}
	int getPrice()
	{
		return this->price;
	}
	bool getValidity()
	{
		return this->isValid;
	}
	string getZone()
	{
		return string(this->zone);
	}
	//setters



	Ticket() :uniqueId(0) {
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
	int NumberOfSeats = 0;
	int reviews[10] = { 5 };
	bool isAvailable = true;
	char* nameOfLocation = nullptr;
public:
	//getters
	int getNumberOfSeats()
	{
		return this->NumberOfSeats;
	}
	bool availability()
	{
		return this->isAvailable;
	}
	string getNameOfLocation()
	{
		return string(this->nameOfLocation);
	}
};
class Event {
private:
	int eventId = 0;
	char* nameOfEvent = nullptr;
	bool isCanceled = false;
	int maximumAttendancePerDay[7] = { 0 };
public:
	//getters
	int getId()
	{
		return this->eventId;
	}
	string getNameOfEvent()
	{
		return string(this->nameOfEvent);
	}
	bool getAvailableness()
	{
		return this->isCanceled;
	}
public:
	//default constr
	Event() :eventId(0) {
		this->nameOfEvent = NULL;
		this->numberOfSeats = 0;
	}
	

	
};
int Ticket::soldTickets = 0;
int main()
{
	cout << "De testare";
}