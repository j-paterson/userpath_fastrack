// Auto-generated. Do not edit!

// (in-package userpath_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class UserpointInstruction {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.curr_id = null;
      this.prev_id = null;
      this.x = null;
      this.y = null;
      this.z = null;
      this.action = null;
    }
    else {
      if (initObj.hasOwnProperty('curr_id')) {
        this.curr_id = initObj.curr_id
      }
      else {
        this.curr_id = '';
      }
      if (initObj.hasOwnProperty('prev_id')) {
        this.prev_id = initObj.prev_id
      }
      else {
        this.prev_id = '';
      }
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('z')) {
        this.z = initObj.z
      }
      else {
        this.z = 0.0;
      }
      if (initObj.hasOwnProperty('action')) {
        this.action = initObj.action
      }
      else {
        this.action = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type UserpointInstruction
    // Serialize message field [curr_id]
    bufferOffset = _serializer.string(obj.curr_id, buffer, bufferOffset);
    // Serialize message field [prev_id]
    bufferOffset = _serializer.string(obj.prev_id, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.float64(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float64(obj.y, buffer, bufferOffset);
    // Serialize message field [z]
    bufferOffset = _serializer.float64(obj.z, buffer, bufferOffset);
    // Serialize message field [action]
    bufferOffset = _serializer.string(obj.action, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type UserpointInstruction
    let len;
    let data = new UserpointInstruction(null);
    // Deserialize message field [curr_id]
    data.curr_id = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [prev_id]
    data.prev_id = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z]
    data.z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [action]
    data.action = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.curr_id.length;
    length += object.prev_id.length;
    length += object.action.length;
    return length + 36;
  }

  static datatype() {
    // Returns string type for a message object
    return 'userpath_msgs/UserpointInstruction';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '29084584a0c6fe06139836eb5f255c3b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string curr_id
    string prev_id
    float64 x
    float64 y
    float64 z
    string action
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new UserpointInstruction(null);
    if (msg.curr_id !== undefined) {
      resolved.curr_id = msg.curr_id;
    }
    else {
      resolved.curr_id = ''
    }

    if (msg.prev_id !== undefined) {
      resolved.prev_id = msg.prev_id;
    }
    else {
      resolved.prev_id = ''
    }

    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.z !== undefined) {
      resolved.z = msg.z;
    }
    else {
      resolved.z = 0.0
    }

    if (msg.action !== undefined) {
      resolved.action = msg.action;
    }
    else {
      resolved.action = ''
    }

    return resolved;
    }
};

module.exports = UserpointInstruction;
