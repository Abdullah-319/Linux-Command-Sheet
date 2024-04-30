#include <iostream>
#include <sys/wait.h>
#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

int a=0;

void * incA (void *arg){
	cout<<"Inside incA Thread ..."<<endl;
	for(int i=0; i<20000 ; i++){
	
		a++;
		//sleep(2);
	}
	return nullptr;

}
void * decA (void *arg){
	cout<<"Inside decA Thread ..."<<endl;
	for(int i=0; i<50000 ; i++){
	
		a--;
		//sleep(2);
	}
	return nullptr;

}
int main() {
    
    pthread_t one;
    pthread_t two;

    pthread_create(&one,NULL,incA,NULL);

    pthread_join(one,NULL);
    
    pthread_create(&two,NULL,decA,NULL);
    
    pthread_join(two,NULL);
    
    cout<<"Inside MAIN  ..."<<endl;
    cout<<"Value of A is : "<<a<<endl;
   
    return 0;
}

