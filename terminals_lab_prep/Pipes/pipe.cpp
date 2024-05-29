#include <bits/stdc++.h>

using namespace std;

int main() {
	int ends[2], size = 50;
	pipe(ends);
	char out[size];
	
	write(ends[1], "Abdullah", size);
	read(ends[0], out, size);
	
	cout<<out<<endl;
	
	return 0;
}
