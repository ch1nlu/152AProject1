#include <iostream>
#ifndef E_Handler
#define E_Handler

class Event_node{
  //data inside each node
public:
  //double linked list for the GEL(next and previous event)
  Event_node *next_event;
  Event_node *prev_event;

  //
  double time;
  double type;

  //packet object will contain time and type
  Event_node(){};

  //Evebt class (GEL) can hve event_node atttributes
  friend class Event;
};

class Event{
private:
    Event_node* front; //Front node
  public:
    Event()
    {
      front = NULL; //constructor
    };
    ~Event(){}; //  deconstructor
    Event& insert(double time, bool type); //This will placeevents into the GEL
    Event& deleting();
    Event_node& front_return(); //return the front node
    int check_front();
    int print();
};

class Data{
private:

  public:
    int length;
    Data(int MAXBUFFER);
    struct packet{
      double time;
    };
    double rmv_head();
    packet* queue;
};
#endif
