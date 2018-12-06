(in-package #:cl-user)
(defpackage #:phrase
  (:use #:cl)
  (:export #:word-count))
(in-package #:phrase)

(ql:quickload :cl-ppcre)

(defun word-count (phrase)
  (setf pairs (mapcar (lambda (x) (list (string-downcase x) 1)) (cl-ppcre::split "[ ]+" phrase)))

  (loop for pair in pairs do
	(print pair))
  
  )

;(reduce #'(lambda (x y) (+ (second x) (second y))) 

(print (word-count "hello Hello"))
