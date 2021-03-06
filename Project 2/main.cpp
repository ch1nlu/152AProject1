
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

//generate time and packet
double transmissionTime(double rate){
    double r = negExp(rate) * 1544;
    while(r > 1544){
        r = negExp(rate) * 1544;
    }
    totalSent += r;
    double out  = (r*8.0)/11e6;
    return out;
}

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

void incrSIFS(double sifsIn){
    int new_time = idle_time + sifsIn; //need to make sure idle_time is our current time
    //we need to build a new event based on this new time right?
    sensed_busy = sensed_busy + sifsIn;
}
void incrDIFS(double difsIn){
    int new_time = idle_time + difsIn; //need to make sure idle_time is our current time
    //we need to build a new event based on this new time right?
    sensed_busy = sensed_busy + difsIn;
}

void collision_chance(int* k){
    int c = 100 * drand48(); //random number 0 - 100
    if(c <= 20){
        *k += 1;
    }
}

int main()
{
  double MAXBUFFER = 1000000;
  int num_packets = 100000;
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
  double sensed_busy;//the extra time added when a host is sensed busy

  Event GEL;

  cout<< "Lambda: ";
  cin >> lambda;
  cout<< "Number of hosts: ";
  cin >> num_hosts;
  cout << "T value: "; //value used for random backoff
  cin >> T;

  //Data Queue(MAXBUFFER); need to change to hosts
    
  //*************
  
  //the user will enter how many number of users
  ////the user will enter the value of lambda


  int number_of_users = 0;
  int number_of_collisions = 0;
  //create new acknowledge event

  //create two queues 
  //create arriving event
  //insert the arriving event into gel
  

  for (int i = 0; i < 100000; i++) {
    next_event_node = GEL.front_return(); //get the next event
    if(next_event_node.type == 0) //it is an arriving event
  //***get the transmission***
    }
  
    else if (next_event_node.type == 1) {//it is an departing event
    //a collision happens first
      int number_of_collisions = 100 * drand48(); //random number 0 - 100
      if(number_of_collisions <= 10){
        number_of_collisions += 1; //I want to change this value forever here, maybe change to *number_of_collisions? 
      }
    //***get the transmission***
    }
    else if (next_event_node.type == 2){//it is an acknowledgement
    //we need to put this event into our queue
    }  
    else if (next_event_node.type == 3){//acknowledge received
    //
        
    }
}


//double throughput = number of bytes / current time;
//double average_network_delay = time when server is busy / throughput;
        

  















/*  for(int i = 0; i < 100000; i++)
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
  }*/
}
}
  cout << "Throughput: " <<tot_bytes/time << endl;
  cout << "Avg Network Delay: " << tot_delay/ (tot_bytes/time) << endl;
}
