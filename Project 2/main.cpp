#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Event.h"
#include <list>
#include <queue>
#include <ctime>
#include <random>
#include <time.h>
using namespace std;

#define NUM_HOSTS 10//Number of hosts, maybe better if set as an input
int mu = 1;

int dataSizeGenerate(double mu) //where mu is pkt/sec
{
    double u;
    u = (rand()%10000)/10000.0;
    return (int) (-1000/mu * log(1-u))%1544 + 1;
}

int selectReceiver(int sender)
{
    int recvr = rand() % NUM_HOSTS+1; //labeling start from 1
    if(recvr == sender) return selectReceiver(sender);
    return recvr;
}


int expBackoff(int T, int collision) //T is the contention window size 
{
    int bkoff = rand() % T + 1;
    int exp = rand()% (int)pow(2,collision) + 1;
    return bkoff * exp;
}


double negExp(double rate)//generate the negative-exp distributed time
{
  double u;
  u = drand48();
  return((-1/rate) * log(1-u));
}

int main()
{
    double MAXBUFFER = 1000000;
    int num_packets = 100000
    double lambda;
    double total_time;
    double arrival_time;
    double depart_time;
    double previous_time = 0;
    double idle_time = 0;
    double idle_start = 0;
    double packs_in_queue = 0;
    int packs_dropped  = 0;
    double DIFS = 0.1;
    double SIFS = 0.05;
    int T;
    int num_hosts;


    Event GEL;

    cout<< "Lambda: ";
    cin >> lambda;
    cout<< "Number of hosts: ";
    cin >> num_hosts;
    cout << "T value: "; //value used for random backoff
    cin >> T;

    //Data Queue(MAXBUFFER); need to change to hosts

    for(int i = 0; i < 100000; i++)
    {
      arrival_time = negExp(lambda) + previous_time; // maybe?
      GEL.insert(arrival_time, 0);
      previous_time = arrival_time;
    }
    Event_node testing_node;
    int i = 0;
    while(GEL.check_front() != 1)
    {
      testing_node = GEL.front_return();
      cout<<"Current Head Node: \n" <<testing_node.time<<"\n"<<testing_node.type<<endl;
      if(testing_node.type == 0)
      {
        packs_in_queue = packs_in_queue + Queue.length; //maybe?
        if(Queue.length == 0)
        {
          (Queue.length)++;
          idle_time = (testing_node.time - idle_start) + idle_time;// maybe?
          (Queue.queue[(Queue.length) - 1]).time = testing_node.time;
          depart_time = testing_node.time + negExp2();
          GEL.insert(depart_time, 1); //
          cout<<"GEL-Inserted Departure Time:"<<depart_time<<"\n----------------------\n";
        }
        else if(((Queue.length) < MAXBUFFER) && (Queue.length > 0))
        {

          (Queue.length)++;
          (Queue.queue[ (Queue.length)-1 ]).time = testing_node.time;
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
          {
            idle_start = testing_node.time;//maybe?
            depart_time = Queue.rmv_head(); //
          }
          if(depart_time !=0)
          {
            depart_time = depart_time + negExp2();//maybe?
            GEL.insert(depart_time, 1); //
            total_time = depart_time ;//maybe?
          }
        }
      }
      GEL.deleting();
      i++;
    }
    cout << "Throughput: " <<tot_bytes/time << endl;
    cout << "Avg Network Delay: " << tot_delay/ (tot_bytes/time) << endl;

}
