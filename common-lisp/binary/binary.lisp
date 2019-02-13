(in-package #:cl-user)
(defpackage #:binary
  (:use #:cl)
  (:export #:to-decimal))
(in-package #:binary)

(defun to-decimal (input-s) 
    (setf s (remove-if-not (lambda (x) (or 
                        (char= x #\0)
                        (char= x #\1))) input-s))
    (setf result 0)
    (setf counter 0)
    (setf number-of-01 (count #\0 s))
    (setf number-of-01 (+ number-of-01 (count #\1 s)))
    (loop :for i :from 0 :to (- (length s) 1)
        do 
            (progn
                (print i)
                (when (char= (elt s i) #\1) (incf result))
                (when (not (= i (- (length s) 1))) (setf result (* result 2)))))
    result)

