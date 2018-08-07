;; Auto-generated. Do not edit!


(when (boundp 'userpath_msgs::UserpointInstruction)
  (if (not (find-package "USERPATH_MSGS"))
    (make-package "USERPATH_MSGS"))
  (shadow 'UserpointInstruction (find-package "USERPATH_MSGS")))
(unless (find-package "USERPATH_MSGS::USERPOINTINSTRUCTION")
  (make-package "USERPATH_MSGS::USERPOINTINSTRUCTION"))

(in-package "ROS")
;;//! \htmlinclude UserpointInstruction.msg.html


(defclass userpath_msgs::UserpointInstruction
  :super ros::object
  :slots (_curr_id _prev_id _x _y _z _action ))

(defmethod userpath_msgs::UserpointInstruction
  (:init
   (&key
    ((:curr_id __curr_id) "")
    ((:prev_id __prev_id) "")
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:action __action) "")
    )
   (send-super :init)
   (setq _curr_id (string __curr_id))
   (setq _prev_id (string __prev_id))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _action (string __action))
   self)
  (:curr_id
   (&optional __curr_id)
   (if __curr_id (setq _curr_id __curr_id)) _curr_id)
  (:prev_id
   (&optional __prev_id)
   (if __prev_id (setq _prev_id __prev_id)) _prev_id)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:action
   (&optional __action)
   (if __action (setq _action __action)) _action)
  (:serialization-length
   ()
   (+
    ;; string _curr_id
    4 (length _curr_id)
    ;; string _prev_id
    4 (length _prev_id)
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _z
    8
    ;; string _action
    4 (length _action)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _curr_id
       (write-long (length _curr_id) s) (princ _curr_id s)
     ;; string _prev_id
       (write-long (length _prev_id) s) (princ _prev_id s)
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _z
       (sys::poke _z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; string _action
       (write-long (length _action) s) (princ _action s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _curr_id
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _curr_id (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _prev_id
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _prev_id (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _z
     (setq _z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; string _action
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _action (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get userpath_msgs::UserpointInstruction :md5sum-) "29084584a0c6fe06139836eb5f255c3b")
(setf (get userpath_msgs::UserpointInstruction :datatype-) "userpath_msgs/UserpointInstruction")
(setf (get userpath_msgs::UserpointInstruction :definition-)
      "string curr_id
string prev_id
float64 x
float64 y
float64 z
string action

")



(provide :userpath_msgs/UserpointInstruction "29084584a0c6fe06139836eb5f255c3b")


