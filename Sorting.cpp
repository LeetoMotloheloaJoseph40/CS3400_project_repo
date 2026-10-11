#include "Sorting.h"

bool lessThan(const Vehicle& q,const Vehicle& r,int key){
	if(key==1) return q.getID()<r.getID();
	if(key==2) return q.getCapacity()<r.getCapacity();
	if(key==3) return q.gettype()<r.gettype();
	return q.getplate()<r.getplate();
}

void insertionSort(Vehicle q[],int T,int key){
	for(int i=1;i<T;i++){
		Vehicle temp=q[i];
		int j=i-1;
		while(j>=0&&lessThan(temp,q[j],key)){
			q[j+1]=q[j];
			j--;
		}
		q[j+1]=temp;
	}
}
void merge(Vehicle q[],Vehicle temp[],int low,int moderate,int high,int key){
	int i=low,j=moderate+1,k=low;
	while(i<=moderate&&j<=high){
		if(lessThan(q[j],q[i],key)) temp[k++]=q[j++];
		else temp[k++]=q[i++];
	}
	while(i<=moderate) temp[k++]=q[i++];
	while(j<=high) temp[k++]=q[j++];
	for(int z=low;z<=high;z++) q[z]=temp[z];
}
void merger(Vehicle q[],Vehicle temp[],int low,int high,int key){
	if(low>=high) return;
	int moderate=(low+high)/2;
	merger(q,temp,low,moderate,key);
	merger(q,temp,moderate+1,high,key);
	merge(q,temp,low,moderate,high,key);
}
void mergeSort(Vehicle q[],int T,int key){
	Vehicle* temp=new Vehicle[T];
	merger(q,temp,0,T-1,key);
	delete[] temp;
}
int binarysearch(Vehicle q[],int T,const string& id){
	int low=0,high=T-1;
	while(low<=high){
		int moderate=(low+high)/2;
		if(q[moderate].getID()==id) return moderate;
		if(q[moderate].getID()<id) low=moderate+1;
		else high=moderate-1;
	}
	return -1;
}
