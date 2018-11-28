(defpackage #:raindrops
  (:use #:common-lisp)
  (:export #:convert))

(in-package #:raindrops)


(defun convert (i)
  (defparameter result "")
  (if (eql (mod i 3) 0) (setf result (concatenate 'string result "Pling")) nil)
  (if (eql (mod i 5) 0) (setf result (concatenate 'string result "Plang")) nil)
  (if (eql (mod i 7) 0) (setf result (concatenate 'string result "Plong")) nil)
  (if (string= result "") (write-to-string i) result))

