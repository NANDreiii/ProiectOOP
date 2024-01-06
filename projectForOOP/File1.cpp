#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
enum class ZoneType{No_Access = 0,General_access = 1, Special_access = 2, VIP = 3 };
class Ticket {
private:
	const int uniqueId = 0;
	int row = 0;
	int seat = 0;
	double price = 0;
	bool isValid = false;
	char* name_of_holder = nullptr;
	ZoneType zone = ZoneType::No_Access;
public:
	static int soldTickets; 
	static const int MAX_PRICE = 10000;
	static const int MAX_ROW = 100;
	static const int MAX_SEAT = 100;
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
	double getPrice()
	{
		return this->price;
	}
	bool getValidity()
	{
		return this->isValid;
	}
	string getName()
	{
		return string(this->name_of_holder);
	}
	string getZone()
	{
		
		switch (this->zone) {
		case ZoneType::No_Access:
			return "You cannot enter the event. ";
		case ZoneType::General_access:
			return "General_Access";
		case ZoneType::Special_access:
			return "Special_Access";
		case ZoneType::VIP:
			return "VIP";
		default:
			return "Wrong value for the zone. ";
		}
	}
	//setters
	void setRow(int value)
	{
		if (value >= 1 && value <= MAX_ROW)
			this->row = value;
		else
			throw exception("Wrong value. Row does not exist. ");
	}
	void setSeat(int value)
	{
		if (value >= 1 && value <= MAX_SEAT)
			this->seat = value;
		else
			throw exception("Wrong value. Number of seat on the ticket is not right. ");

	}
	void setPrice(float value)
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
	void setNameOfPerson(char* value)
	{
		delete[] this->name_of_holder;
		this->name_of_holder = new char[strlen(value) + 1];
		strcpy_s(this->name_of_holder, strlen(value) + 1, value);
	}
	void setZone(const char* variable) {
			if (strcmp(variable, "General_access") == 0)
				this->zone = ZoneType::General_access;
			else if (std::strcmp(variable, "Special_access") == 0)
				this->zone = ZoneType::Special_access;
			else if (std::strcmp(variable, "VIP") == 0)
				this->zone = ZoneType::VIP;
		else {
			throw exception("The zone is not valid.");
		}
	}


	//constructors, copy constr, destructor, overloaded operator=
	Ticket() :uniqueId(++soldTickets) {

	}
	Ticket(int row, int seat, double price, bool isValid, const char* name,ZoneType zone) :uniqueId(++soldTickets)
	{
		this->row = row;
		this->seat = seat;
		this->price = price;
		this->isValid = isValid;
		this->name_of_holder = new char[strlen(name) + 1];
		strcpy(this->name_of_holder, name);
		this->zone = zone;
	}


	Ticket(int row, int seat):uniqueId(++soldTickets)
	{
		this->row = row;
		this->seat = seat;
	}


	Ticket(double price, bool isValid) :uniqueId(++soldTickets) {
		this->price = price;
		this->isValid = isValid;
	}


	~Ticket() {
		cout << endl << "Deconstructor for Ticket class. ";
		delete[] this->name_of_holder;

	}


	Ticket(const Ticket& t) :uniqueId(++soldTickets) {

		this->row = t.row;
		this->seat = t.seat;
		if (t.name_of_holder != NULL) {
			this->name_of_holder = new char[strlen(t.name_of_holder) + 1];
			strcpy(this->name_of_holder, t.name_of_holder);
		}
		this->price = t.price;
		this->isValid = t.isValid;
		this->zone = t.zone;

	}


	Ticket& operator=(const Ticket& s)
	{
		this->row = s.row;
		this->seat = s.seat;
		if (s.name_of_holder != NULL) {
			if (this->name_of_holder != NULL)
			{
				delete[] this->name_of_holder;
				this->name_of_holder = nullptr;
			}
			this->name_of_holder = new char[strlen(s.name_of_holder) + 1];
			strcpy(this->name_of_holder, s.name_of_holder);
		}
		this->price = s.price;
		this->isValid = s.isValid;
		this->zone = s.zone;
		return *this;

	}


	//operatori


	void operator++()
	{
		this->price++;
	}


	char operator[](int i)
	{
		if (i > 0 && i <= strlen(this->name_of_holder))
			return this->name_of_holder[i];
		else
			cout << "Wrong index. ";
	}


	Ticket operator!() {
		Ticket copie = *this;
		copie.isValid = !copie.isValid;
		return copie;
	}

	

	//cast


	operator double() {
		return this->price;
	}


	friend ostream& operator<<(ostream& console,const Ticket& ticket);


	//opeartor >>(cin)


	friend void operator>>(istream& console, Ticket& ticket);

	//other methods for ticket.
	void printLocationOfTicket(Ticket& ticket)
	{
		cout << endl << "Your will stay on row " << ticket.getRow() << ", on seat " << ticket.getSeat();
	}
	void priceInEuro(Ticket& ticket)
	{
		double price;
		price= ticket.getPrice();
		cout << price / 5.0;
	}
	static void printSeat(Ticket ticket)
	{
		cout << endl << "The ticket is on seat: " << ticket.getSeat() << ", on row: " << ticket.getRow();
	}
};
string zoneToString(ZoneType zone) {
	switch (zone) {
	case ZoneType::No_Access:
		return "No_Access";
	case ZoneType::General_access:
			return "General_Access";
	case ZoneType::Special_access:
			return "Special_Access";
		case ZoneType::VIP:
			return "VIP";
		default:
			return "Cannot enter";
	}
}
//operator <<
ostream& operator<<(ostream& out, const Ticket& ticket)
{
	out << ticket.uniqueId << endl << ticket.row << endl << ticket.seat << endl << ticket.price << endl << ticket.isValid << endl << zoneToString(ticket.zone)<<endl<< ticket.name_of_holder << endl;
	return out;
}


//operator >>
void operator>>(istream& console, Ticket& ticket)
{
	cout << endl << "Input name of the owner: ";
	char buffer[2000];
	console.getline(buffer, 2000);
	console.clear();
	ticket.setNameOfPerson(buffer);
	cout << endl << "Input row, seat, price, validity(if valid, write 1, if not valid, write 0) and zone(For general access, write 1, for special access, write 2, and for VIP, write 3): ";
	int zone;
	console >> ticket.row >> ticket.seat  >>ticket.price >> ticket.isValid >> zone;
	ticket.zone = static_cast<ZoneType>(zone);
	
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
	int getReview(int i)
	{
		return this->reviews[i];
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
	//operatori
	void operator++()
	{
		this->numberOfSeats++;
	}
	int operator[](int i)
	{
		if (i > 0 && i <= 4)
			return this->reviews[i];
		else
			cout << "Wrong index. ";
	}
	Location operator!() {
		Location copie = *this;
		copie.isAvailable = !copie.isAvailable;
		return copie;
	}

	//operator << (cout)
	friend ostream& operator<<(ostream& console, const Location& l);
	//opeartor >>(cin)


	friend void operator>>(istream& console, Location& l);


	//other methods for Location
	static void totalNumberOfSeats(Location location)
	{
		cout << "the location has a maximum number of: " << location.getNumberOfSeats() << " seats";
	}
	static void averageReview(Location location)
	{
		int i = 0;
		float avg = 0;
		for (i = 0; i < 5; i++)
			avg = avg + location.getReview(i);
		if (i >= 1)
		{
			avg = avg / 5;
			cout << "The average rating for this location is: " << avg << " stars. ";
		}
		else
			cout << "The location has no ratings. ";

	}

};	
//operator <<
ostream& operator<<(ostream& out, const Location& l)
{
	out << l.numberOfSeats << endl << l.nameOfLocation << endl << l.isAvailable;
	for (int i = 0; i < 5; i++)
		out <<' '<< l.reviews[i];

	return out;
}
//operator >>
void operator>>(istream& in, Location& l) {
	char name[200];
	cout << "Enter name of location, number of seats, reviews, availability(true or false): ";
	in.getline(name, 2000);
	in.clear();
	l.setNameOfLocation(name);
	in >> l.numberOfSeats;
	for (int i = 0; i < 5; i++)
		in >> l.reviews[i];
	in >> l.isAvailable;

}


class Event {
private:
	int eventId = 0;
	int day = 0;
	int* maximumAttendancePerDay = nullptr;
public:
	static const int MAX_CAPACITY = 150000;
	//getters
	int getId()
	{
		return this->eventId;
	}
	int getDay()
{
	return this->day;
	}
	int* getAttendance()
	{
		int* copy = new int[this->day];
		for (int i = 0; i < this->day; i++)
			copy[i] = this->maximumAttendancePerDay[i];
		return copy;
	}


	//setters
	void setIdOfEvent(int value)
	{
		if (value > 0)
			this->eventId = value;
		else
			throw exception("The value of the ID is not right. ");
	}
	void setDay(int day)
	{
		if (day >= 0 && day <= 6)
			this->day = day;
		else
			throw exception("The day is not right. ");
	}
	void setMaxAttendanceEveryDay(int* newAttendance, int newDay)
	{
		delete[] this->maximumAttendancePerDay;
		this->maximumAttendancePerDay = new int[newDay];
		memcpy(this->maximumAttendancePerDay, newAttendance , sizeof(int) * newDay);
		this->day = newDay;
	}
	//constr, copy constr, operator=, deconstr
	Event():maximumAttendancePerDay(nullptr) {

	}
	Event(int Id, int day, int *att)
	{
		setIdOfEvent(Id);
		setDay(day);
		setMaxAttendanceEveryDay(att, day);

	}
	Event(int nr)
	{
		this->eventId = nr;
		
	}

	Event(const Event& e) {

		this->eventId = e.eventId;
		this->day = day;
		for (int i = 0; i < this->day; i++)
			this->setMaxAttendanceEveryDay(e.maximumAttendancePerDay, i);
		

	}
	Event& operator=(const Event& s)
	{
		this->eventId = s.eventId;
		this->day = day;
		for (int i = 0; i < this->day; i++)
			this->setMaxAttendanceEveryDay(s.maximumAttendancePerDay, i);
		return *this;

	}
	~Event()
	{
		cout<<"Deconstructor for Event";
		delete[] this->maximumAttendancePerDay;
	}
	//operatori
	void operator++()
	{
		this->eventId++;
	}
	int operator[](int i)
	{
		if (i > 0 && i <= 4)
			return this->maximumAttendancePerDay[i];
		else
			cout << "Wrong index. ";
	}

	friend ostream& operator<<(ostream& console, const Event& e);
	//opeartor >>(cin)
	friend void operator>>(istream& console, Event& e);

};
//operator <<
ostream& operator<<(ostream& out, const Event& e)
{
	out << e.eventId << endl << e.day;
	int* attendanceArray = e.maximumAttendancePerDay;
	for (int i = 0; i < e.day; ++i) {
		cout << attendanceArray[i] << " ";
	}
	return out;
}
//operator >>
void operator>>(istream& in, Event& e) {
	cout << "Enter eventId,number of days, and max attendance per day: ";
	in >> e.eventId >> e.day;
	delete[] e.maximumAttendancePerDay;
	if (e.day > 0) {
		e.maximumAttendancePerDay = new int[e.day];
		for (int i = 0; i < e.day; ++i) {
			in >> e.maximumAttendancePerDay[i];
		}
	}
	else {
		e.maximumAttendancePerDay = nullptr;
	}

}
//other methods for event

int Ticket::soldTickets = 0;
int main()
{

	/*Ticket ticket(1, 2, 22.56, false, "Nitu Andrei", static_cast<ZoneType>(1));
	cout<<ticket[1];
	float price;
	price = ticket;
	cout << endl<<price;
	cout << !ticket;
	ticket.priceInEuro(ticket);
	cout << endl;
	Ticket::printSeat(ticket);*/
	//int reviews[5] = { 3, 5, 5, 2, 1 };
	//Location location(2000, reviews, true, "Andrei");
	//cout<<location.getReview(3);
	//Location location1 = location;
	//Location location2;
	//location2 = location;
	//cout << endl << location.getReview(1) << endl << location1.getReview(1) << endl << location2.getReview(1);
	//cout<<location.availability();
	//Location::averageReview(location);
	/*int review[] = { 1,2,3,4,5 };
	Location location;
	cin >> location;
	cout << location;*/
	
	/*cin >> location;
	cout << endl << location.getNumberOfSeats() << ' ' << location.getNameOfLocation() << endl;
	for (int i = 0; i < 5; i++)
		cout << ' ' << location.getReview(i);
	cout << endl << location.availability();*/

	int daily[3] = {2000, 30000, 40000};
	Event event(20, 3, daily);
	cout << event.getDay();
	int* attendanceArray = event.getAttendance();
	for (int i = 0; i < event.getDay(); ++i) {
		cout << attendanceArray[i] << " ";
	}
	Event event1;
	cin >> event1;
	cout << event1;
}
	
