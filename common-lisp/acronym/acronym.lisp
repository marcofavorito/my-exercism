(in-package #:cl-user)
(defpackage #:acronym
  (:use #:common-lisp)
  (:export #:acronym))

(in-package #:acronym)

(ql:quickload :cl-ppcre)

(defun acronym (str)
  (if (eql (length str) 0) "" 
    (string-upcase (concatenate 'string
      (mapcar (lambda (x) (elt x 0)) (cl-ppcre::split "[ ;,.-]+" str))))))

