#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
enum class zonesOfEvent { VIP, zone1, zone2};
class Ticket {
private:
	const int uniqueId = 0;
	int row = 0;
	int NumberOfSeats = 0;
	double price = 100;
	bool isValid = true;
	char* zone = nullptr;
	int ageOfPeople[6] = { 0,0,0,0,0,0 };
public:
	static int soldTickets; 
	static const int MAX_PRICE = 9999;
	static const int MAX_ROW = 150;
	static const int MAX_SEAT = 6;
	//getters
	int getUniqueId()
	{
		return this->uniqueId;
	}
	int getRow()
	{
		return this->row;
	}
	int getSeats()
	{
		return this->NumberOfSeats;
	}
	double getPrice()
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
	int getAgeOfPerson1()
	{
		return this->ageOfPeople[0];
	}
	int getAgeOfPerson2()
	{
		return this->ageOfPeople[1];
	}
	int getAgeOfPerson3()
	{
		return this->ageOfPeople[2];
	}
	int getAgeOfPerson4()
	{
		return this->ageOfPeople[3];
	}
	int getAgeOfPerson5()
	{
		return this->ageOfPeople[4];
	}
	int getAgeOfPerson6()
	{
		return this->ageOfPeople[5];
	}
	//setters
	void setRow(int value)
	{
		if (value >= 1 && value <= MAX_ROW)
			this->row = value;
		else
			throw exception("Wrong value. Row does not exist. ");
	}
	void setNumberOfSeats(int value)
	{
		if (value >= 1 && value <= MAX_SEAT)
			this->NumberOfSeats = value;
		else
			throw exception("Wrong value. Number of seats on the ticket is not right. ");

	}
	void setPrice(int value)
	{
		if (value >= 0 && value <= MAX_PRICE)
			this->price = value;
		else
			throw exception("The price is not right. ");
	}
	void setValidTicket()
	{
		this->isValid = true;
	}
	void setInvalidTicket()
	{
		this->isValid = false;
	}
	void setZone(string variable)
	{
		delete[] this->zone;
		this->zone = new char[variable.size() + 1];
		strcpy_s(this->zone, variable.size() + 1, variable.c_str());
	}
	void setAgeOfPerson(int index, int value)
	{
		if (index >= 0 && index <= 5 && value >= 14 && value <= 100)
			this->ageOfPeople[index] = value;
		else
			throw exception("Wrong value. ");
	}
	//constructors, copy constr, destructor, overloaded operator=
	Ticket() :uniqueId(++soldTickets) {

	}
	Ticket(int row, int NumberOfSeats, double price, bool isValid, const char* zone,int age1,int age2,int age3, int age4,int age5, int age6) :uniqueId(++soldTickets)
	{
		this->row = row;
		this->NumberOfSeats = NumberOfSeats;
		this->price = price;
		this->isValid = isValid;
		this->zone = new char[strlen(zone) + 1];
		strcpy(this->zone, zone);
		this->ageOfPeople[0] = age1;
		this->ageOfPeople[1] = age2;
		this->ageOfPeople[2] = age3;
		this->ageOfPeople[3] = age4;
		this->ageOfPeople[4] = age5;
		this->ageOfPeople[5] = age6;


	}
	Ticket(int row, int NumberOfSeats):uniqueId(++soldTickets)
	{
		this->row = row;
		this->NumberOfSeats = NumberOfSeats;
	}
	Ticket(double price, bool isValid) :uniqueId(++soldTickets) {
		this->price = price;
		this->isValid = isValid;
	}
	
	~Ticket() {
		cout << endl << "Deconstructor for Ticket class. ";
		delete[] this->zone;

	}
	Ticket(const Ticket& t) :uniqueId(++soldTickets) {

		this->row = t.row;
		this->NumberOfSeats = t.NumberOfSeats;
		if (t.zone != NULL) {
			this->zone = new char[strlen(t.zone) + 1];
			strcpy(this->zone, t.zone);
		}
		this->price = t.price;
		this->isValid = t.isValid;
		for (int i = 0; i < 6; i++)
			this->ageOfPeople[i] = t.ageOfPeople[i];

	}
	Ticket& operator=(const Ticket& s)
	{
		this->row = s.row;
		if (s.zone != NULL) {
			if (this->zone != NULL)
			{
				delete[] this->zone;
				this->zone = nullptr;
			}
			this->zone = new char[strlen(s.zone) + 1];
			strcpy(this->zone, s.zone);
		}
		this->isValid = s.isValid;
		for (int i = 0; i < 6; i++)
			this->ageOfPeople[i] = s.ageOfPeople[i];
		return *this;

	}
};
//other methods for ticket.
void printLocationOfTicket(Ticket ticket)
{
	cout << endl << "Your will stay on row " << ticket.getRow() << ", where you have " << ticket.getSeats() << " seats.";
}
void TotalCost(Ticket ticket)
{
	double sum = 0;
	if (ticket.getAgeOfPerson1() != 0)
		sum += ticket.getPrice();
	if (ticket.getAgeOfPerson2() != 0)
		sum += ticket.getPrice();
	if (ticket.getAgeOfPerson3() != 0)
		sum += ticket.getPrice();
	if (ticket.getAgeOfPerson4() != 0)
		sum += ticket.getPrice();
	if (ticket.getAgeOfPerson5() != 0)
		sum += ticket.getPrice();
	if (ticket.getAgeOfPerson6() != 0)
		sum += ticket.getPrice();
	cout << "The total cost of the ticket is: " << sum << " lei";
}
class Location {
	int numberOfSeats = 0;
	int reviews[5] = {-1, -1, -1, -1, -1};
	bool isAvailable = true;
	char* nameOfLocation = nullptr;
public:
	static const int MAX_SEATS = 150000;
	//getters
	int getNumberOfSeats()
	{
		return this->numberOfSeats;
	}
	bool availability()
	{
		return this->isAvailable;
	}
	string getNameOfLocation()
	{
		return string(this->nameOfLocation);
	}
	int getReviewNumber1()
	{
		return this->reviews[0];
	}
	int getReviewNumber2()
	{
		return this->reviews[1];
	}
	int getReviewNumber3()
	{
		return this->reviews[2];
	}
	int getReviewNumber4()
	{
		return this->reviews[3];
	}
	int getReviewNumber5()
	{
		return this->reviews[4];
	}
	//setters
	void setNumberOfSeats(int value)
	{
		if (value >= 1 && value <= MAX_SEATS)
			this->numberOfSeats = value;
		else
			throw exception("The value is wrong. "); 
	}
	void setReview(int index, int value)
	{
		if (index >= 0 && index <= 4 && value >= 0 && value <= 5)
			this->reviews[index] = value;
		else
			throw exception("The value of the index or of the review is not right. ");
	}
	void setAvailableLocation()
	{
		this->isAvailable = true;
	}
	void setUnavailableLocation()
	{
		this->isAvailable = false;
	}
	void setNameOfLocation(string value)
	{
		delete[] this->nameOfLocation;
		this->nameOfLocation = new char[value.size() + 1];
		strcpy_s(this->nameOfLocation, value.size() + 1, value.c_str());
		
	}
	//constr, copy constr, operator=, deconstr
	Location(){

	}
	Location(int nr, int r[5], bool av, const char* name)
	{
		this->numberOfSeats = nr;
		this->isAvailable = av;
		this->nameOfLocation = new char[strlen(name) + 1];
		strcpy(this->nameOfLocation, name);
		for (int i = 0; i < 5; i++)
			this->reviews[i] = r[i];


	}
	Location(int nr, bool avlb)
	{
		this->numberOfSeats = nr;
		this->isAvailable = avlb;
	}

	~Location() {
		cout << endl << "Deconstructor for Location class. ";
		delete[] this->nameOfLocation;

	}
	Location(const Location& l){

		this->numberOfSeats = l.numberOfSeats;
		this->isAvailable = l.isAvailable;
		if (l.nameOfLocation != NULL) {
			this->nameOfLocation = new char[strlen(l.nameOfLocation) + 1];
			strcpy(this->nameOfLocation, l.nameOfLocation);
		}
		for (int i = 0; i < 5; i++)
			this->reviews[i] = l.reviews[i];

	}
	Location& operator=(const Location& s)
	{
		this->numberOfSeats = s.numberOfSeats;
		if (s.nameOfLocation != NULL) {
			if (this->nameOfLocation != NULL)
			{
				delete[] this->nameOfLocation;
				this->nameOfLocation = nullptr;
			}
			this->nameOfLocation = new char[strlen(s.nameOfLocation) + 1];
			strcpy(this->nameOfLocation, s.nameOfLocation);
		}
		this->isAvailable = s.isAvailable;
		for (int i = 0; i < 5; i++)
			this->reviews[i] = s.reviews[i];
		return *this;
	}

};
//other methods for Location
void totalNumberOfSeats(Location location)
{
	cout << "the location has a maximum number of: " << location.getNumberOfSeats() << " seats";
}
void averageReview(Location location)
{
	int i = 0;
	double avg = 0;
	if (location.getReviewNumber1() > -1)
	{
		i++;
		avg += location.getReviewNumber1();
	}
	if (location.getReviewNumber2() > -1)
	{
		i++;
		avg += location.getReviewNumber2();
	}
	if (location.getReviewNumber3() > -1)
	{
		i++;
		avg += location.getReviewNumber3();
	}
	if (location.getReviewNumber4() > -1)
	{
		i++;
		avg += location.getReviewNumber4();
	}
	if (location.getReviewNumber5() > -1)
	{
		i++;
		avg += location.getReviewNumber5();
	}
	cout << i << endl << avg << endl;
	if (i >= 1)
	{
		avg =avg / i;
		cout << "The average rating for this location is: " << avg << " stars. ";
	}
	else
		cout << "The location has no ratings. ";

}
class Event {
private:
	int eventId = 0;
	char* nameOfEvent = nullptr;
	bool isCanceled = false;
	int maximumAttendancePerDay[7] = { 0 };
public:
	static const int MAX_CAPACITY = 150000;
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
	int getAttendanceDay1()
	{
		return this->maximumAttendancePerDay[0];
	}
	int getAttendanceDay2()
	{
		return this->maximumAttendancePerDay[1];
	}
	int getAttendanceDay3()
	{
		return this->maximumAttendancePerDay[2];
	}
	int getAttendanceDay4()
	{
		return this->maximumAttendancePerDay[3];
	}
	int getAttendanceDay5()
	{
		return this->maximumAttendancePerDay[4];
	}
	int getAttendanceDay6()
	{
		return this->maximumAttendancePerDay[5];
	}
	int getAttendanceDay7()
	{
		return this->maximumAttendancePerDay[6];
	}
	//setters
	void setIdOfEvent(int value)
	{
		if (value > 0)
			this->eventId = value;
		else
			throw exception("The value of the ID is not right. ");
	}
	void setNameOfEvent(const char* name)
	{
		if (this->nameOfEvent != NULL)
			delete[] this->nameOfEvent;
		this->nameOfEvent = new char[strlen(name) + 1];
		strcpy_s(this->nameOfEvent, strlen(name) + 1, name);

	}
	void cancelEvent()
	{
		this->isCanceled = true;
	}
	void activateEvent()
	{
		this->isCanceled = false;
	}
	void setMaxAttendanceEveryDay(int index, int number)
	{
		if (index >= 0 && index <= 6 && number >= 1 && number <= MAX_CAPACITY)
			this->maximumAttendancePerDay[index] = number;
		else
			throw exception("One of the values is wrong. ");
	}
	//constr, copy constr, operator=, deconstr
	Event() {

	}
	Event(int Id, int attendance[7], bool cancel, const char* name)
	{
		this->eventId = Id;
		this->isCanceled = cancel;
		this->nameOfEvent = new char[strlen(name) + 1];
		strcpy(this->nameOfEvent, name);
		for (int i = 0; i < 7; i++)
			this->maximumAttendancePerDay[i] = attendance[i];


	}
	Event(int nr, bool is)
	{
		this->eventId = nr;
		this->isCanceled = is;
	}

	~Event() {
		cout << endl << "Deconstructor for Event class. ";
		delete[] this->nameOfEvent;

	}
	Event(const Event& e) {

		this->eventId = e.eventId;
		this->isCanceled = e.isCanceled;
		if (e.nameOfEvent!= NULL) {
			this->nameOfEvent = new char[strlen(e.nameOfEvent) + 1];
			strcpy(this->nameOfEvent, e.nameOfEvent);
		}
		for (int i = 0; i < 7; i++)
			this->maximumAttendancePerDay[i] = e.maximumAttendancePerDay[i];

	}
	Event& operator=(const Event& s)
	{
		this->eventId = s.eventId;
		if (s.nameOfEvent != NULL) {
			if (this->nameOfEvent!= NULL)
			{
				delete[] this->nameOfEvent;
				this->nameOfEvent = nullptr;
			}
			this->nameOfEvent= new char[strlen(s.nameOfEvent) + 1];
			strcpy(this->nameOfEvent, s.nameOfEvent);
		}
		this->isCanceled= s.isCanceled;
		for (int i = 0; i < 7; i++)
			this->maximumAttendancePerDay[i] = s.maximumAttendancePerDay[i];
		return *this;

	}
};
//other methods for event
void TotalAttendance(Event event)
{
	int total = 0;
	total = total + event.getAttendanceDay1() + event.getAttendanceDay2() + event.getAttendanceDay3() + event.getAttendanceDay4() + event.getAttendanceDay5() + event.getAttendanceDay6() + event.getAttendanceDay7();
	cout << "In total, there can be a maximum of " << total << " people attending this event in a week. ";
}
void isMyEventAvailable(Event event)
{	
	if (event.getAvailableness() == true)
		cout << "Unfortunately, the event " << event.getNameOfEvent() << " is not available anymore. ";
	else
		cout << "Good news! The event " << event.getNameOfEvent() << " is still available. ";
}
int Ticket::soldTickets = 0;
int main()
{
	/*Ticket bilet1(10, 5, 29.8, true, "peluza", 15, 16, 17, 18, 19, 20);
	Ticket copy = bilet1;
	cout<<	copy.getAgeOfPerson2();
	Ticket bilet2;
	cout << endl;
	bilet2 = bilet1;
	cout<<bilet2.getAgeOfPerson2();*/
	/*bilet1.setRow(10);
	bilet1.setNumberOfSeats(4);
	bilet1.setPrice(20);
	bilet1.setAgeOfPerson(0, 15);
	bilet1.setAgeOfPerson(1, 20);
	bilet1.setAgeOfPerson(2, 30);
	TotalCost(bilet1);
	printLocationOfTicket(bilet1);
	cout << endl;



	Location locatie;
	locatie.setNumberOfSeats(15000);
	locatie.setReview(0, 5);
	locatie.setReview(1, 5);
	locatie.setReview(2, 1);
	locatie.setReview(3, 3);
	locatie.setReview(4, 4);
	averageReview(locatie);
	cout << endl;
	totalNumberOfSeats(locatie);
	cout << endl;


	Event event;
	event.setMaxAttendanceEveryDay(0, 10000);
	event.setMaxAttendanceEveryDay(1, 10000);
	event.setMaxAttendanceEveryDay(2, 10000);
	event.setMaxAttendanceEveryDay(3, 10000);
	event.setMaxAttendanceEveryDay(4, 10000);
	event.setMaxAttendanceEveryDay(5, 10000);
	event.setMaxAttendanceEveryDay(6, 10000);
	TotalAttendance(event);
	cout << endl;
	event.setNameOfEvent("Jazz Concert");
	event.activateEvent();
	isMyEventAvailable(event);*/
	

}
