// Generated by gencpp from file ardrone_autonomy/navdata_video_stream.msg
// DO NOT EDIT!


#ifndef ARDRONE_AUTONOMY_MESSAGE_NAVDATA_VIDEO_STREAM_H
#define ARDRONE_AUTONOMY_MESSAGE_NAVDATA_VIDEO_STREAM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace ardrone_autonomy
{
template <class ContainerAllocator>
struct navdata_video_stream_
{
  typedef navdata_video_stream_<ContainerAllocator> Type;

  navdata_video_stream_()
    : header()
    , drone_time(0.0)
    , tag(0)
    , size(0)
    , quant(0)
    , frame_size(0)
    , frame_number(0)
    , atcmd_ref_seq(0)
    , atcmd_mean_ref_gap(0)
    , atcmd_var_ref_gap(0.0)
    , atcmd_ref_quality(0)
    , desired_bitrate(0)
    , data2(0)
    , data3(0)
    , data4(0)
    , data5(0)
    , fifo_queue_level(0)  {
    }
  navdata_video_stream_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , drone_time(0.0)
    , tag(0)
    , size(0)
    , quant(0)
    , frame_size(0)
    , frame_number(0)
    , atcmd_ref_seq(0)
    , atcmd_mean_ref_gap(0)
    , atcmd_var_ref_gap(0.0)
    , atcmd_ref_quality(0)
    , desired_bitrate(0)
    , data2(0)
    , data3(0)
    , data4(0)
    , data5(0)
    , fifo_queue_level(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _drone_time_type;
  _drone_time_type drone_time;

   typedef uint16_t _tag_type;
  _tag_type tag;

   typedef uint16_t _size_type;
  _size_type size;

   typedef uint8_t _quant_type;
  _quant_type quant;

   typedef uint32_t _frame_size_type;
  _frame_size_type frame_size;

   typedef uint32_t _frame_number_type;
  _frame_number_type frame_number;

   typedef uint32_t _atcmd_ref_seq_type;
  _atcmd_ref_seq_type atcmd_ref_seq;

   typedef uint32_t _atcmd_mean_ref_gap_type;
  _atcmd_mean_ref_gap_type atcmd_mean_ref_gap;

   typedef float _atcmd_var_ref_gap_type;
  _atcmd_var_ref_gap_type atcmd_var_ref_gap;

   typedef uint32_t _atcmd_ref_quality_type;
  _atcmd_ref_quality_type atcmd_ref_quality;

   typedef uint32_t _desired_bitrate_type;
  _desired_bitrate_type desired_bitrate;

   typedef int32_t _data2_type;
  _data2_type data2;

   typedef int32_t _data3_type;
  _data3_type data3;

   typedef int32_t _data4_type;
  _data4_type data4;

   typedef int32_t _data5_type;
  _data5_type data5;

   typedef uint32_t _fifo_queue_level_type;
  _fifo_queue_level_type fifo_queue_level;





  typedef boost::shared_ptr< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> const> ConstPtr;

}; // struct navdata_video_stream_

typedef ::ardrone_autonomy::navdata_video_stream_<std::allocator<void> > navdata_video_stream;

typedef boost::shared_ptr< ::ardrone_autonomy::navdata_video_stream > navdata_video_streamPtr;
typedef boost::shared_ptr< ::ardrone_autonomy::navdata_video_stream const> navdata_video_streamConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ardrone_autonomy

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'ardrone_autonomy': ['/home/sebastian/stability_scale/catkin_ws/src/ardrone_autonomy/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> >
{
  static const char* value()
  {
    return "caf560356d435eb563ce5b9e8278da00";
  }

  static const char* value(const ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcaf560356d435eb5ULL;
  static const uint64_t static_value2 = 0x63ce5b9e8278da00ULL;
};

template<class ContainerAllocator>
struct DataType< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ardrone_autonomy/navdata_video_stream";
  }

  static const char* value(const ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float64 drone_time\n\
uint16 tag\n\
uint16 size\n\
uint8 quant\n\
uint32 frame_size\n\
uint32 frame_number\n\
uint32 atcmd_ref_seq\n\
uint32 atcmd_mean_ref_gap\n\
float32 atcmd_var_ref_gap\n\
uint32 atcmd_ref_quality\n\
uint32 desired_bitrate\n\
int32 data2\n\
int32 data3\n\
int32 data4\n\
int32 data5\n\
uint32 fifo_queue_level\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.drone_time);
      stream.next(m.tag);
      stream.next(m.size);
      stream.next(m.quant);
      stream.next(m.frame_size);
      stream.next(m.frame_number);
      stream.next(m.atcmd_ref_seq);
      stream.next(m.atcmd_mean_ref_gap);
      stream.next(m.atcmd_var_ref_gap);
      stream.next(m.atcmd_ref_quality);
      stream.next(m.desired_bitrate);
      stream.next(m.data2);
      stream.next(m.data3);
      stream.next(m.data4);
      stream.next(m.data5);
      stream.next(m.fifo_queue_level);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct navdata_video_stream_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ardrone_autonomy::navdata_video_stream_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "drone_time: ";
    Printer<double>::stream(s, indent + "  ", v.drone_time);
    s << indent << "tag: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.tag);
    s << indent << "size: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.size);
    s << indent << "quant: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.quant);
    s << indent << "frame_size: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.frame_size);
    s << indent << "frame_number: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.frame_number);
    s << indent << "atcmd_ref_seq: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.atcmd_ref_seq);
    s << indent << "atcmd_mean_ref_gap: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.atcmd_mean_ref_gap);
    s << indent << "atcmd_var_ref_gap: ";
    Printer<float>::stream(s, indent + "  ", v.atcmd_var_ref_gap);
    s << indent << "atcmd_ref_quality: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.atcmd_ref_quality);
    s << indent << "desired_bitrate: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.desired_bitrate);
    s << indent << "data2: ";
    Printer<int32_t>::stream(s, indent + "  ", v.data2);
    s << indent << "data3: ";
    Printer<int32_t>::stream(s, indent + "  ", v.data3);
    s << indent << "data4: ";
    Printer<int32_t>::stream(s, indent + "  ", v.data4);
    s << indent << "data5: ";
    Printer<int32_t>::stream(s, indent + "  ", v.data5);
    s << indent << "fifo_queue_level: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.fifo_queue_level);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARDRONE_AUTONOMY_MESSAGE_NAVDATA_VIDEO_STREAM_H
