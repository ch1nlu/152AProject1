
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
    double r = negExpDist(rate) * 1544;
    while(r > 1544){
        r = negExpDist(rate) * 1544;
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

Event new_event(int type, int source, double time)
{
  Event test;
  test.type = type;
  test.source = source;
  test.dest = rand() % num_hosts;
  while(test.source == test.dest){
    test.dest = rand() % num_hosts;
  }
  // first
  if(type == 0){
    test.time = time + negExp(lambda);
  }
  //
  //back off
  else if(type == 1){
    test.time = time + negExp(mu);
  }
  // sense
  else if(type == 2){
    test.time = time + 0.01;
  }
  else{
    cout << "Error"<<endl;
  }
  return test;
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


  Event GEL;

  cout<< "Lambda: ";
  cin >> lambda;
  cout<< "Number of hosts: ";
  cin >> num_hosts;
  cout << "T value: "; //value used for random backoff
  cin >> T;

  //Data Queue(MAXBUFFER); need to change to hosts

  //Host initialized with variables
  host hosts[num_hosts];
  for(int = 0); i < num_hosts; i++){
    Event Event1 = newEvent(0, i, time);
    Event1.type2 - 0;
    insert_GEL(Event1);
    hosts[i].length = 0;
    hosts[i].tot_length = 0;
    hosts[i].dropped = 0;
    hosts[i].N = 0;
    hosts[i].trans_time = 0;
    host[i].q_time = 0;
    host[i].backoff = 0;
}

    for(int i = 0; i < num_packets; i++)
    {
      Event curr_event;
      curr_event = GEL.front();
      time = curr_event.time;

      if(curr_event.type == 0){
      //process beginning of arrival event
      if(curr_event.type2 == 0){
        //arrival event
        Event new_arriv = new_event(0, curr_event.source, time)
        new_arriv.type2 = 0;
        insert_GEL(new_arriv);

        //Create new packets
        packet new_packet;
        new_packet.size = negExp(mu);
        new_packet.service_t = negExp(mu);

        //departure event
















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
  cout << "Throughput: " <<tot_bytes/time << endl;
  cout << "Avg Network Delay: " << tot_delay/ (tot_bytes/time) << endl;
