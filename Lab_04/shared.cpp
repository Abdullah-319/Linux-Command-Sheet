#include <bits/stdc++.h>

using namespace std;

int items = 0, x;

void producer() {
    cout<<"Producer produced items: "<<++items<<endl;
    x = 6;
}

void consumer() {
    cout<<"Before consuming value of x: "<< x << endl;
    cout<<"Consuer consume value of x: "<< items << endl;
    x=12;
    cout<<"Consuer consume value of x: "<< x << endl;
}

int main() {

    producer();
    consumer();

    return 0;
}