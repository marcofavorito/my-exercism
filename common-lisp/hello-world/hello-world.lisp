(defpackage #:hello-world
  (:use #:common-lisp)
  (:export #:hello-world)
  (:nicknames #:hw))

(in-package #:hello-world)

(defun HELLO-WORLD (&optional name)
  (if name
     (format nil "Hello ~a!" name)
     (format nil "Hello World!")))