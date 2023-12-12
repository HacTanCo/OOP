#include <iostream>
#include <ctime>
using namespace std;
int getYear() 
{	
    time_t x = time(NULL);
    struct tm *localTime = localtime(&x);
    int year = localTime->tm_year + 1900;
    return year;
}

int main() 
{
    int x = getYear();
	cout << "nam hien tai la: " << x;
}

