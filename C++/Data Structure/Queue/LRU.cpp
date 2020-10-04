#include<bits/stdc++.h>
using namespace std;
class least_Recently_Used{
	list<int> elements;//Doubly linked list to store the elements
	unordered_map<int, list<int>::iterator> refer;//hashtable for storing the reference address
	int n;//hashtable for storing the refernce address
	public:
	/*Constructor to initialize the capacity of cache*/
		least_Recently_Used(int capacity){
			n=capacity;
		}
	
	/*add a value to the list if new or move the value to the front if already present*/
    void insert(int value){
	if(refer.find(value)==refer.end()){// if the value is not found in the list
		if(refer.size()==n){//if the cache size is equal to the capacity
			int x=elements.back();
			elements.pop_back();//removing the last element from the queue
            refer.erase(x); //erasing the key value pair from the hash table
		}
	}
	else{
		elements.erase(refer.find(value)->second);//if present erasing it 
	}
	elements.push_front(value);//adding the value to the front
	refer[value]=elements.begin();//storing the address in the hashtable
    }
    
    
    /*Iterating through the entire list and printing the elements*/
    void print(){
	for(auto it=elements.begin();it!=elements.end();it++)
	cout<<*it<<" ";
	cout<<endl;
    }
    
    
		
};


int main(){
least_Recently_Used lruImplementation(3); //to specify the capacity

lruImplementation.insert(1);//1
lruImplementation.insert(2);//2
lruImplementation.insert(3);//3
lruImplementation.insert(2);//4
lruImplementation.insert(4);//5
lruImplementation.insert(2);//6
lruImplementation.insert(5);//7
lruImplementation.print();
}   
