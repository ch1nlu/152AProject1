#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Event.h"


using namespace std;

double negExp(double rate)//generate the negative-exp distributed time
{
  double u;
  u = drand48();
  return((-1/rate) * log(1-u));
}

double negExp2(){
    double u;
    u = drand48();
    return ((-1) * log(1 - u));
}



int main()
{
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

    for(int i = 0; i < 100; i++)
    {
      arrival_time = negExp(lambda) + previous_time;
      GEL.insert(arrival_time, 0);
      previous_time = arrival_time;
    }
    Event_node testing_node;
    int i = 0;
    while(GEL.check_front() != 1)
    {
      testing_node = GEL.front_return();
      if(testing_node.type == 0)
      {
        packs_in_queue = packs_in_queue + Queue.length;
        if(Queue.length == 0)
        {
          (Queue.length)++;
          idle_time = (testing_node.time - idle_start) + idle_time;
          (Queue.queue[(Queue.length) - 1]).time = testing_node.time;
          depart_time = testing_node.time + negExp2();
          GEL.insert(depart_time, 1);
        }
        else if(((Queue.length) < MAXBUFFER) && (Queue.length > 0))
        {
          (Queue.length)++;
          (Queue.queue[(Queue.length) - 1]).time = testing_node.time;
        }
        else
        {
          ++packs_dropped;
        }
      }
      else
      {
        if(Queue.length > 0)
        {
          Queue.length = Queue.length - 1;
          if(Queue.length == 0)
            idle_start = testing_node.time;
          depart_time = Queue.rmv_head();
          if(depart_time !=0)
          {
            depart_time = depart_time + negExp2();
            GEL.insert(depart_time, 1);
            total_time = depart_time;
          }
        }
      }
      GEL.deleting();
      i++;
    }

    cout <<"Packets dropped: " <<packs_dropped<< endl;
    cout <<"Average packets in queue: "<<(packs_in_queue/total_time)<< endl;
    cout <<"Utilization: " <<(total_time - idle_time)/total_time<< endl;

}
