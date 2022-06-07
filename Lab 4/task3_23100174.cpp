#include <iostream>
using namespace std;

class person
{
private:
	bool status; // True means in home while false mean out
	bool verdict; // True means innocent while false mean guilty
	bool faceMask;
	bool handSanitzer;
	bool socialDistancing; 

public:
	person()
	{
	status = true ;
	verdict= true ;
	faceMask= true;
	handSanitzer= true;
	socialDistancing= true;
	}	

	person(bool s, bool v, bool f, bool h, bool sd)
	{

	status = s ;
	verdict= v ;
	faceMask= f;
	handSanitzer= h;
	socialDistancing= sd;

	}

	void setStatus(bool s)
	{
		status= s;
	}

	bool getStatus()
	{
		return status;
	}

	void setVerict(bool v)
	{
		verdict= v;
	}

	bool getVerdict()
	{
		return verdict;
	}

	void setFaceMask(bool f)
	{
		faceMask= f;
	}

	bool getFaceMask()
	{
		return faceMask;
	}

	void setHandSanitizer(bool h)
	{
		handSanitzer= h;
	}

	bool getHandSanitizer()
	{
		return handSanitzer;
	}

	void setSocialDistancing(bool sd)
	{
		socialDistancing= sd;
	}

	bool getSocialDistancing()
	{
		return socialDistancing;
	}

	void goingOut()
	{
		status= false;
		faceMask= true;
		handSanitzer= true;
		socialDistancing= true;
	}

	void comingIn()
	{
		status= true;
		faceMask= false;
		handSanitzer= false;
		socialDistancing= false;
	}

	void inTrouble()
	{
		status = false;
		faceMask= false;
		handSanitzer=true;
		socialDistancing= true;
	}

	void print()
	{	
		string homeOrOut;
		string innocentOrGuilty;
		if( status)
		{
			homeOrOut= "home" ;
		}
		else if (!status)
		{
			homeOrOut= "out" ;
		}

		if (verdict)
		{
			innocentOrGuilty= "innocent";
		}
		else if (!verdict)
		{
			innocentOrGuilty= "guilty" ;
		}

		cout << "The person is " << homeOrOut << " and " << innocentOrGuilty << endl;
	} 
};

class policePerson
{
public:

	void setPersonVerdict(person *a)
	{
		if( a->getStatus() == false )
		{
			if(a->getFaceMask() == false || a->getHandSanitizer() == false || a->getSocialDistancing() == false )
				{
					a->setVerict(false);
				}
		}
		else
		{
			a-> setVerict(true); 
		}
	}
};

int main()
{
	policePerson p ;
	person x,y,z ;
	x.comingIn();
	y.goingOut();
	z.inTrouble();

	p.setPersonVerdict(&x);
	p.setPersonVerdict(&y);
	p.setPersonVerdict(&z);

	x.print();
	y.print();
	z.print();

}