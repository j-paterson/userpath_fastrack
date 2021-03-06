// Generated by gencpp from file userpath_msgs/UserpointInstruction.msg
// DO NOT EDIT!


#ifndef USERPATH_MSGS_MESSAGE_USERPOINTINSTRUCTION_H
#define USERPATH_MSGS_MESSAGE_USERPOINTINSTRUCTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace userpath_msgs
{
template <class ContainerAllocator>
struct UserpointInstruction_
{
  typedef UserpointInstruction_<ContainerAllocator> Type;

  UserpointInstruction_()
    : curr_id()
    , prev_id()
    , x(0.0)
    , y(0.0)
    , z(0.0)
    , action()  {
    }
  UserpointInstruction_(const ContainerAllocator& _alloc)
    : curr_id(_alloc)
    , prev_id(_alloc)
    , x(0.0)
    , y(0.0)
    , z(0.0)
    , action(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _curr_id_type;
  _curr_id_type curr_id;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _prev_id_type;
  _prev_id_type prev_id;

   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _action_type;
  _action_type action;





  typedef boost::shared_ptr< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> const> ConstPtr;

}; // struct UserpointInstruction_

typedef ::userpath_msgs::UserpointInstruction_<std::allocator<void> > UserpointInstruction;

typedef boost::shared_ptr< ::userpath_msgs::UserpointInstruction > UserpointInstructionPtr;
typedef boost::shared_ptr< ::userpath_msgs::UserpointInstruction const> UserpointInstructionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::userpath_msgs::UserpointInstruction_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace userpath_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'userpath_msgs': ['/home/ros/userpath_fastrack/src/userpath_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "29084584a0c6fe06139836eb5f255c3b";
  }

  static const char* value(const ::userpath_msgs::UserpointInstruction_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x29084584a0c6fe06ULL;
  static const uint64_t static_value2 = 0x139836eb5f255c3bULL;
};

template<class ContainerAllocator>
struct DataType< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "userpath_msgs/UserpointInstruction";
  }

  static const char* value(const ::userpath_msgs::UserpointInstruction_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string curr_id\n\
string prev_id\n\
float64 x\n\
float64 y\n\
float64 z\n\
string action\n\
";
  }

  static const char* value(const ::userpath_msgs::UserpointInstruction_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.curr_id);
      stream.next(m.prev_id);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.action);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct UserpointInstruction_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::userpath_msgs::UserpointInstruction_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::userpath_msgs::UserpointInstruction_<ContainerAllocator>& v)
  {
    s << indent << "curr_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.curr_id);
    s << indent << "prev_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.prev_id);
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
    s << indent << "action: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.action);
  }
};

} // namespace message_operations
} // namespace ros

#endif // USERPATH_MSGS_MESSAGE_USERPOINTINSTRUCTION_H
