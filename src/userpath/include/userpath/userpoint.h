///////////////////////////////////////////////////////////////////////////////
//
// Defines the Userpoint struct. Each Userpoint is just a node in the Userpath linked list.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef USERPATH_PLANNER_USERPOINT_H
#define USERPATH_PLANNER_USERPOINT_H
#include <string>

namespace userpath {

class Userpoint {	
// Member variables and Constructors.
public:
  std::string id;
  std::vector<double> location;
  Userpoint* prev;
  Userpoint* next;

  Userpoint()
  {
    id="";
    location=std::vector<double>{0.0, 0.0, 0.0};
    prev=NULL;
    next=NULL;
  }
  
  Userpoint(std::string id_, std::vector<double> location_)
  {
    id=id_;
    location=location_;
    prev=NULL;
    next=NULL;
  }
  
  Userpoint(std::string id_, std::vector<double> location_, Userpoint* prev_, Userpoint* next_)
  {
    id=id_;
    location=location_;
    prev=prev_;
    next=next_;
  }
};

} //\namespace userpath

#endif

