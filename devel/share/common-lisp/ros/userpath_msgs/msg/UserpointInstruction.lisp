; Auto-generated. Do not edit!


(cl:in-package userpath_msgs-msg)


;//! \htmlinclude UserpointInstruction.msg.html

(cl:defclass <UserpointInstruction> (roslisp-msg-protocol:ros-message)
  ((curr_id
    :reader curr_id
    :initarg :curr_id
    :type cl:string
    :initform "")
   (prev_id
    :reader prev_id
    :initarg :prev_id
    :type cl:string
    :initform "")
   (x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (z
    :reader z
    :initarg :z
    :type cl:float
    :initform 0.0)
   (action
    :reader action
    :initarg :action
    :type cl:string
    :initform ""))
)

(cl:defclass UserpointInstruction (<UserpointInstruction>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UserpointInstruction>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UserpointInstruction)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name userpath_msgs-msg:<UserpointInstruction> is deprecated: use userpath_msgs-msg:UserpointInstruction instead.")))

(cl:ensure-generic-function 'curr_id-val :lambda-list '(m))
(cl:defmethod curr_id-val ((m <UserpointInstruction>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader userpath_msgs-msg:curr_id-val is deprecated.  Use userpath_msgs-msg:curr_id instead.")
  (curr_id m))

(cl:ensure-generic-function 'prev_id-val :lambda-list '(m))
(cl:defmethod prev_id-val ((m <UserpointInstruction>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader userpath_msgs-msg:prev_id-val is deprecated.  Use userpath_msgs-msg:prev_id instead.")
  (prev_id m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <UserpointInstruction>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader userpath_msgs-msg:x-val is deprecated.  Use userpath_msgs-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <UserpointInstruction>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader userpath_msgs-msg:y-val is deprecated.  Use userpath_msgs-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <UserpointInstruction>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader userpath_msgs-msg:z-val is deprecated.  Use userpath_msgs-msg:z instead.")
  (z m))

(cl:ensure-generic-function 'action-val :lambda-list '(m))
(cl:defmethod action-val ((m <UserpointInstruction>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader userpath_msgs-msg:action-val is deprecated.  Use userpath_msgs-msg:action instead.")
  (action m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UserpointInstruction>) ostream)
  "Serializes a message object of type '<UserpointInstruction>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'curr_id))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'curr_id))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'prev_id))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'prev_id))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'action))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'action))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UserpointInstruction>) istream)
  "Deserializes a message object of type '<UserpointInstruction>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'curr_id) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'curr_id) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'prev_id) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'prev_id) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'action) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'action) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UserpointInstruction>)))
  "Returns string type for a message object of type '<UserpointInstruction>"
  "userpath_msgs/UserpointInstruction")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UserpointInstruction)))
  "Returns string type for a message object of type 'UserpointInstruction"
  "userpath_msgs/UserpointInstruction")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UserpointInstruction>)))
  "Returns md5sum for a message object of type '<UserpointInstruction>"
  "29084584a0c6fe06139836eb5f255c3b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UserpointInstruction)))
  "Returns md5sum for a message object of type 'UserpointInstruction"
  "29084584a0c6fe06139836eb5f255c3b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UserpointInstruction>)))
  "Returns full string definition for message of type '<UserpointInstruction>"
  (cl:format cl:nil "string curr_id~%string prev_id~%float64 x~%float64 y~%float64 z~%string action~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UserpointInstruction)))
  "Returns full string definition for message of type 'UserpointInstruction"
  (cl:format cl:nil "string curr_id~%string prev_id~%float64 x~%float64 y~%float64 z~%string action~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UserpointInstruction>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'curr_id))
     4 (cl:length (cl:slot-value msg 'prev_id))
     8
     8
     8
     4 (cl:length (cl:slot-value msg 'action))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UserpointInstruction>))
  "Converts a ROS message object to a list"
  (cl:list 'UserpointInstruction
    (cl:cons ':curr_id (curr_id msg))
    (cl:cons ':prev_id (prev_id msg))
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':z (z msg))
    (cl:cons ':action (action msg))
))
