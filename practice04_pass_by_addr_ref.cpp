#include <iostream>
using namespace std;

//void myfunction(const int &a)
//void myfunction(int &a)
void myfunction(const int *p)
{
    
}

int main() {
	//code
	int x = 3;
	//myfunction(4);
	//myfunction(&(x+1));
	myfunction(&(x+1)); // okay with const int &a as the parameter, but not with (const) int *p
	return 0;
}
