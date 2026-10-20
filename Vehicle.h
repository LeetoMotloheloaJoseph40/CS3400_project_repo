#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
using namespace std;

class Vehicle{
	private:
		string ID, plate, type, route, status;
		int Capacity;
	public:
		Vehicle();
		Vehicle(string,string,string,string,int,string);
		
		string getID()const;
		string getplate()const;
		string gettype()const;
		string getroute()const;
		string getstatus()const;
		int getCapacity()const;
		
		void setID(string);
		void setplate(string);
		void settype(string);
		void setroute(string);
		void setstatus(string);
		void setCapacity(int);
		
		void display()const;
		 
};
#endif
