#include <bits/stdc++.h>

using namespace std;

int main() {

	int ends[2], size = 100;
	pipe(ends);
	char out[size];
	
	write(ends[1], "Abdullah Ahmad",  size);
	
	read(ends[0], out, size);
	
	cout<<out<<endl;

	return 0;
}
