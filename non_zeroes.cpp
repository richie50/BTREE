#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <limits.h>

using namespace std;
int main(){
	size_t non_zeros = 0;
	int value =21245566;
	for(size_t i = 0; i < CHAR_BIT * sizeof(value) ; ++i){
		int temp = 1 << i;
		cout << (value & temp) << endl;
		if((value & temp) != 0){
			++non_zeros;
		}
	}
	cout << "NON ZEROES\t" << non_zeros << "\n";
	cout << CHAR_BIT * sizeof(value) <<endl;
	return 0;
}
