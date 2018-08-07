
(cl:in-package :asdf)

(defsystem "userpath_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "UserpointInstruction" :depends-on ("_package_UserpointInstruction"))
    (:file "_package_UserpointInstruction" :depends-on ("_package"))
  ))