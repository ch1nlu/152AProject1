#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <Event.h>


using namespace std;

double negExp(double rate)//generate the negative-exp distributed time
{
  double u;
  u = drand48();
  return((-1/rate) * log(1-u));
}

double negExp2(double rate){
    double u;
    u = rand()% RAND_MAX /(double)RAND_MAX;
    return ((-1) * log(1 - u));
}



int main()
{
    double arrivalRate, serviceRate;
    double MAXBUFFER;
    double lambda;
    double total_time;
    double arrival_time;
    double depart_time;
    double previous_time = 0;
    double idle_time = 0;
    double idle_start = 0;
    double packs_in_queue = 0;
    int packs_dropped  = 0;
    srand(time(NULL));

    Event GEL;

    cout<< "Lambda: ";
    cin >> lambda;
    cout << "MAXBUFFER size: ";
    cin >> MAXBUFFER;

    Data Queue(MAXBUFFER);

    for(int i = 0; i < 100000; i++)
    {
      arrival_time = negExp(lambda) + prev_time;
      GEL.insert(arrival_time, 0);
      prev_time = arrival_time;
    }
    Event_node testing_node;
    int i = 0;
    





    cout << "Arrival rate: ";
    cin >> arrivalRate;
    cout << "Service rate: ";
    cin >> serviceRate;




    return 0;
}
