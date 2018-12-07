(in-package #:cl-user)
(defpackage #:phrase
  (:use #:cl)
  (:export #:word-count))
(in-package #:phrase)

(ql:quickload :cl-ppcre)

(defun word-count (phrase)
  (setf pairs (mapcar (lambda (x) (cons (string-downcase x) 1)) (cl-ppcre::split "[ ,:!&@$%^&]+" phrase)))
  (setf result ())
  (loop for pair in pairs do
	(progn
	  (setf value (cdr (assoc (first pair) result :test #'equalp)))
	  (setf value (if value value 0))
	  (setf result (remove  (first pair) result  :test 'equal :key 'car))
	  (push (cons (first pair) (+ value 1)) result)))
  result)

;(reduce #'(lambda (x y) (+ (second x) (second y))) 

