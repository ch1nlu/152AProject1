#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <time.h>


using namespace std;

double negExp(double rate);//generate the negative-exp distributed time



int main()
{
    double arrivalRate, serviceRate;
    int MAXBUFFER;
    srand(time(NULL));
    cout << "MAXBUFFER size: ";
    cin >> MAXBUFFER;
    cout << "Arrival rate: ";
    cin >> arrivalRate;
    cout << "Service rate: ";
    cin >> serviceRate;




    return 0;
}

double negExp(double rate){
    double u;
    u = rand()% RAND_MAX /(double)RAND_MAX;
    return ((-1 / rate) * log(1 - u));
}
