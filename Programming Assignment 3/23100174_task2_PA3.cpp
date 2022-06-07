#include <iostream>
using namespace std;

class clocks
{
private:
	int minutes;
	int hours ;
	string meridiem ;

public:

	clocks()
	{
		minutes = 0; 
		hours = 0 ;
		meridiem = " " ;
	}

	clocks(int h, int m, string me)
	{
		minutes = m ;
		hours = h ;
		meridiem = me ;
	}

	void setMinutes(int m)
	{
		minutes = m ;
	}

	void setHours(int h)
	{
		hours = h ;
	}

	void setMeridiem(int me)
	{
		meridiem = me ;
	}

	int getMinutes()
	{
		return minutes; 
	}

	int getHours()
	{
		return hours ; 
	}

	string getMeridiem()
	{
		return meridiem ;
	}

	void display_time()
	{
		if (hours < 10 && minutes < 10 )
		{
			cout << "Time in 12-hour format: 0" << hours << ":0" << minutes << " " << meridiem << endl;
		}
		else if ( minutes < 10)
		{
			cout << "Time in 12-hour format: " << hours << ":0" << minutes << " " << meridiem << endl;
		}
		else if (hours < 10 )
		{
			cout << "Time in 12-hour format: 0" << hours << ":" << minutes << " " << meridiem << endl;
		}
		else 
		{
			cout << "Time in 12-hour format: " << hours << ":" << minutes << " " << meridiem << endl;
		}
	}
};

class clock_angle: public clocks
{
private:

	int angle ;

public:

	clock_angle(): clocks()
	{
		angle = 0;
	}

	clock_angle(int h, int m, string me): clocks(h, m, me)
	{
		angle =0 ;
	}

	void serAngle(int a)
	{
		angle = a ;
	}

	int getAngle()
	{
		return angle ;
	}

	void display_time()
	{
		if ( getHours() == 12 && getMeridiem() == "AM")
		{
			if(getMinutes() <10 )
			{
				cout << "Time in 24-hour format: 000" << getMinutes() << " hrs" << endl;
			}
			else 
			{
				cout << "Time in 24-hour format: 00" << getMinutes() << " hrs" << endl;
			}		
			
		}
		else if (getHours() == 12 && getMeridiem() == "PM")
		{
			if (getHours() < 10 && getMinutes() < 10)
			{
				cout << "Time in 24-hour format: 0" << getHours() << "0" << getMinutes() << " hrs" << endl;
			}
			else if(getMinutes() < 10)
			{
				cout << "Time in 24-hour format: " << getHours() << "0" << getMinutes() << " hrs" << endl;
			}
			else
			{
				cout << "Time in 24-hour format: " << getHours() << getMinutes() << " hrs" << endl;
			}
			
		}
		else if ( getHours() != 12 && getMeridiem() == "PM" )
		{
			if(getMinutes() < 10 )
			{
				cout << "Time in 24-hour format: " << getHours()+12 << "0" << getMinutes() << " hrs" << endl;
			}
			else 
			{
				cout << "Time in 24-hour format: " << getHours()+12 << getMinutes() << " hrs" << endl;
			}
		}
		else 
		{
			if (getHours() < 10 && getMinutes() < 10)
			{
				cout << "Time in 24-hour format: 0" << getHours() << "0" << getMinutes() << " hrs" << endl;
			}
			else if (getMinutes() < 10 )
			{
				cout << "Time in 24-hour format: " << getHours() << "0" << getMinutes() << " hrs" << endl;
			}
			else if(getHours() < 10)
			{
				cout << "Time in 24-hour format: 0" << getHours() << getMinutes() << " hrs" << endl;
			}
			else
			{
				cout << "Time in 24-hour format: " << getHours() << getMinutes() << " hrs" << endl;
			}
		}
	}

	void calculate_clock_angle(int minutesElapsed) // assunming that hour hand will not move with minute hand.
	{
		int newMinutes ;
		int newHours = getHours();
		newMinutes = minutesElapsed + getMinutes() ;

		if(newMinutes == 60)
		{
			newHours = getHours() + 1  ;
			newMinutes = 0 ;
			if (newHours > 12 )
			{
				newHours = newHours -12 ;
			}
		}
		else if (newMinutes > 60)
		{
			newMinutes = newMinutes - 60 ;
			newHours = getHours() + 1 ;
			if (newHours > 12 )
			{
				newHours = newHours -12 ;
			}
		}

		int hourAngle; 
		int minuteAngle;

		hourAngle = ( getHours()/12.0 )* 360.0 ;
		minuteAngle = ( getMinutes()/60.0)* 360.0 ;
		if (hourAngle > minuteAngle)
		{
			angle = hourAngle - minuteAngle ;
		}
		else if (minuteAngle > hourAngle)
		{
			angle = minuteAngle - hourAngle ;
		}

		if (angle > 180)
		{
			angle = 360 - angle ;
		}

		cout << "The angle difference between clock hour and clock minute: " << angle << " degrees" << endl;

		int newHourAngle ;
		int newMinuteAngle ;
		int newAngle;
		newHourAngle = ( newHours/12.0 )* 360.0 ;
		newMinuteAngle = ( newMinutes/60.0)* 360.0 ;
		if (newHourAngle > newMinuteAngle)
		{
			newAngle = newHourAngle - newMinuteAngle ;
		}
		else if (newMinuteAngle > newHourAngle)
		{
			newAngle = newMinuteAngle - newHourAngle ;
		}

		if (newAngle > 180)
		{
			newAngle = 360 - newAngle ;
		}

		double angleDifference ;
		angleDifference = newAngle - angle;
		if (angleDifference < 0 )
		{
			angleDifference = angleDifference* (-1.0) ;
		}

		cout << "The angle difference between clock hour and minutes elapsed: " << newAngle << " degrees" << endl;
		cout << "Angle difference: " << angleDifference << " degrees " << endl;

	}
};

int main()
{
	cout << "Enter the time in 12-Hour format: " ;
	int time ;
	cin >> time; 

	while(cin.fail() || time/100 < 1 || time/100 > 12 || time%100 <0 || time%100 > 60 )
	{
		cout << "Enter time in correct format " ;
		cin.clear ();
     	cin.ignore(10000,'\n');
     	cin >> time ;
	}

	cout << "Enter the meridiem" << endl;
	cout << "1. AM " << endl;
	cout << "2. PM " << endl;

	int m; 
	cin >> m; 
	while(cin.fail() || (m != 1 && m != 2))
	{
		cout << "Choose a correct option " ;
		cin.clear ();
     	cin.ignore(10000,'\n');
     	cin >> m ;
    }

    cout << "Enter the minutes elapsed " ;
    int minutesElapsed ; 
    cin >> minutesElapsed ;

    while(cin.fail() || (minutesElapsed < 0) || minutesElapsed > 60)
    {
    	cout << "Enter correct amount of minutes " ;
		cin.clear ();
     	cin.ignore(10000,'\n');
     	cin >> minutesElapsed ;
    }

	int hour ;
	int minute ;
	string meri ;

	if(m ==1)
	{
		meri = "AM" ;
	}
	else if (m == 2)
	{
		meri = "PM" ;
	}

	hour = time/100 ;
	minute = time%100 ;

	if(minute == 60)
	{
		hour++; 
		if (hour == 13)
		{
			hour = 1 ;
		}
		else if (hour == 12)
		{
			hour = 12 ;
			if(meri == "AM")
			{
				meri = "PM" ;
			}
			else if (meri == "PM")
			{
				meri = "AM" ;
			}
		}
		
		minute = 0 ;
	}

	clocks l(hour, minute, meri);
	l.display_time();

	clocks *ptr = new clock_angle(hour, minute, meri) ;
	((clock_angle *)ptr) -> display_time() ;
	((clock_angle *)ptr) -> calculate_clock_angle(minutesElapsed) ;
	


}