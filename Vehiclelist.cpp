#include "Vehiclelist.h"
using namespace std;
Node::Node(const Vehicle& vehi): data(vehi),next(NULL){
}
Vehiclelist::Vehiclelist(): head(NULL),tail(NULL),size(0){
}

Vehiclelist::~Vehiclelist(){
	while(head){
		Node*temp=head;
		head=head->next;
		delete temp;
	}
}
Node* Vehiclelist::search(const string& id){
	for(Node* current=head;current;current=current->next)
		if(current->data.getID()==id) return current;
	return NULL;	
}

bool Vehiclelist::insertFront(const Vehicle& vehi){
	if(search(vehi.getID())) return false;
	Node* n=new Node(vehi);
	n->next=head;
	head=n;
	if(!tail) tail=n;
	size++;
	return true;
}

bool Vehiclelist::insertEnd(const Vehicle& vehi){
	if(search(vehi.getID())) return false;
	Node* n=new Node(vehi);
	if(!head) head=tail=n;
	else{
		tail->next=n;
		tail=n;
	}
	size++;
	return true;
}
Vehicle* Vehiclelist::toArray()const{
	Vehicle* arr=new Vehicle[size];
	Node* current=head;
	int i=0;
	while(current!=NULL){
		arr[i++]=current->data;
		current=current->next;
	}
	return arr;
}
void Vehiclelist::saveToFile(const string& Vehicles)const{
	ofstream out(Vehicles.c_str());
	Node* current=head;
	while(current!=NULL){
		out<<current->data.getID()<<"|"<<current->data.getplate()<<"|"<<current->data.gettype()<<"|"<<current->data.getroute()<<"|"<<current->data.getCapacity()<<"|"<<current->data.getstatus()<<"\n";
		current=current->next;
	}
	out.close();
}
void Vehiclelist::loadFromFile(const string& Vehicles){
	ifstream in(Vehicles.c_str());
	if(!in) return;
	string line;
	while(getline(in,line)){
		if(line=="") continue;
		stringstream ss(line);
		string ID,plate,type,route,Cap,status;
		getline(ss,ID,'|');
		getline(ss,plate,'|');
		getline(ss,type,'|');
		getline(ss,route,'|');
		getline(ss,Cap,'|');
		getline(ss,status,'|');
		insertEnd(Vehicle(ID,plate,type,route,atoi(Cap.c_str()),status));
	}
	in.close();
}
