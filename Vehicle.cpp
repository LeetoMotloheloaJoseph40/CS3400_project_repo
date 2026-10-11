#include "Vehicle.h"

Vehicle::Vehicle():Capacity(0){}

Vehicle::Vehicle(string ID,string plate,string type,string route,int Capacity,string status):ID(ID),plate(plate),type(type),route(route),Capacity(Capacity),status(status){}

string Vehicle::getID()const{
	return ID;
}
string Vehicle::getplate()const{
	return plate;
}
string Vehicle::gettype()const{
	return type;
}
string Vehicle::getroute()const{
	return route;
}
string Vehicle::getstatus()const{
	return status;
}
int Vehicle::getCapacity()const{
	return Capacity;
}

void Vehicle::setID(string id){
	ID=id;
}
void Vehicle::setplate(string plt){
	plate=plt;
}
void Vehicle::settype(string typ){
	type=typ;
}
void Vehicle::setroute(string rte){
	route=rte;
}
void Vehicle::setstatus(string sts){
	status=sts;
}
void Vehicle::setCapacity(int Cap){
	Capacity=Cap;
}

void Vehicle::display()const{
	cout<<ID<<"|"<<plate<<"|"<<type<<"|"<<route<<"|"<<Capacity<<"|"<<status<<endl;
}
