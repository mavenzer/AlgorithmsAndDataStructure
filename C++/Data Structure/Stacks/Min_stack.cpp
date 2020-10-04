#include<bits/stdc++.h>
using namespace std;
#define INVALID_VALUE 999

class MinStack
{   
    // Current Stack
      stack<int> currStack;
    //Min stack 
      stack<int> mStack;//min stack
public:
      // Push Method
      void push(int item){

            //push item in original stack
            currStack.push(item);

            if(mStack.empty()){

                  mStack.push(item);               

            }else if(item <= mStack.top())
            {
                  mStack.push(item);
            }
      }  

// Pop Method
void pop(){

      
      if(!currStack.empty() && !currStack.empty() ){

            if( mStack.top() == currStack.top()){

            mStack.pop();
      }
      } 
      //Also pop original stack

      if(!currStack.empty()){
            currStack.pop(); 
      }         
}



// return minimum value from the stack

int getMin(){

      if(!mStack.empty()){

            return mStack.top();
      }

      return INVALID_VALUE;
}

//Get to value from the stack
//if empty then return large value
int getTop(){     

      if(!currStack.empty()){

            return currStack.top();

      }

      return INVALID_VALUE;
}
};



/*------------------------------------------
* Test minimum value from stack
*/

int main(){
      //Fill the stack
      MinStack s;

      s.push(5);
      s.push(7);
      s.push(2);
      s.push(8);
      s.push(5);
      s.push(9);

      cout<<"Value :"<<s.getTop();
      cout<<" Min value :"<<s.getMin()<<endl;     

      s.pop();
      cout<<"Value :"<<s.getTop();
      cout<<" Min value :"<<s.getMin()<<endl;

      s.pop();
      cout<<"Value :"<<s.getTop();
      cout<<" Min value :"<<s.getMin()<<endl;

      s.pop();
      cout<<"Value :"<<s.getTop();
      cout<<" Min value :"<<s.getMin()<<endl;

      s.pop();
      cout<<"Value :"<<s.getTop();
      cout<<" Min value :"<<s.getMin()<<endl;

      s.pop();
      cout<<"Value :"<<s.getTop();
      cout<<" Min value :"<<s.getMin()<<endl;

      return 0;

}
