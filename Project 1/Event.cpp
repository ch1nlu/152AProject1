#include "Event.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

Event& Event::insert(double time, bool type){
  Event_node *node_data;
  Event_node *node_ptr;
  Event_node *prev_node = NULL;

  //create an event node that will hold what we are copying
  node_data = new Event_node;
  node_data -> time = time;
  node_data -> type = type;

  //create the new list if none exist
  if(front == NULL)
  {
    front = node_data;
    node_data -> next_event = NULL;
    node_data -> prev_event = NULL;
  }
  else
  {
    node_ptr = front; // keep track of front

    //while we are not at the end we will loop through until it breaks off
    while(node_ptr != NULL)
    {
      if((node_ptr -> time) < time)
      {
        prev_node = node_ptr;
        node_ptr = node_ptr -> next_event;
      }
      else
      {
        break;
      }
    }
    if(prev_node == NULL & (node_ptr == front))
    {
      Event_node *temp = NULL;
      temp = front;
      temp->time = front->time;
      temp->type = front->type;
      temp->next_event = front->next_event;
      front = node_data;
      front->time = node_data->time;
      front->type = node_data->type;
      front->next_event = temp;
    }
    else
    {
      prev_node->next_event = node_data;
      if(prev_node != front && node_ptr != NULL)
      {
        node_ptr->prev_event = node_data;
      }
      node_data->prev_event = prev_node;
      node_data->next_event = node_ptr;
    }
  }
  /*return the object*/
  return *this;
}

// return the front node
Event_Node& Event::front_return()
{
    return *front;
}

Event& Event::deleting()
