(in-package #:cl-user)
(defpackage #:gigasecond
  (:use #:cl)
  (:export #:from))
(in-package #:gigasecond)

(defun from (year month day hour minute second) 
  (multiple-value-bind 
    (sec mi h d mo y  _1 _2 _3)
    (decode-universal-time 
      (+ (encode-universal-time second minute hour day month year) (expt 10 9)))
    (list y mo d h mi sec))
)

