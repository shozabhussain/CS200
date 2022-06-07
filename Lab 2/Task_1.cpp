#include <iostream>
using namespace std;

struct date{

	int month, day, year;

	point(){

		int month=0;
		int day=0;
		int year=0;
	}
};

void printdate(date a){

	cout << a.year << "-"<< a.month << "-" << a.day << endl;
}

date adddate(date a, date b){

	date c;
	c.day= a.day+ b.day;
	c.month = a.month + b.month;
	c.year = a.year+ b.year;
	c.year= c.year-2000;

	return c;
}

date subdate(date a, date b){

	date d;
	if (a.day> b.day){
		d.day= a.day-b.day;
	}
	else {
		d.day= b.day-a.day;
	}

	if (a.month> b.month){
		d.month= a.month-b.month;
	}
	else {
		d.month= b.month-a.month;
	}

	if (a.year> b.year){
		d.year= a.year-b.year;
		d.year= d.year + 2000;
	}
	else {
		d.year= b.year-a.year;
		d.year= d.year + 2000;
	}

	return d;
}

int main(){
	cout << "Please enter Date One " << endl;
	date one;
	do {
		cout << " month ( less than and equal to 12): " ;
		cin >> one.month ;
	}
 	while (one.month >13);


	do {
		cout << " day ( less than and equal to 31): " ;
		cin >> one.day ;
	}
 	while (one.month >30);
	cout << " year: " ;
	cin >> one.year ;

	cout << "Please enter Date Two " << endl;
	date two;
	do {
		cout << " month ( less than and equal to 12): " ;
		cin >> two.month ;
	}
 	while (one.month >13);
	
	do {
		cout << " day ( less than and equal to 31): " ;
		cin >> two.day ;
	}
 	while (one.month >30);
	cout << " year: " ;
	cin >> two.year ;

	cout << "date format: ";
	 printdate(one);

	date sum= adddate(one, two) ;
	cout << " add date: " ;
	printdate(sum);

	date sub= subdate(one, two);
	cout << " subtract date: " ;
	printdate(sub);

}