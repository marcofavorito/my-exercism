(in-package #:cl-user)
(defpackage #:robot
  (:use #:common-lisp)
  (:export #:build-robot #:robot-name #:reset-name))

(in-package #:robot)

(defparameter CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
(defparameter NUMBERS "0123456789")
(defparameter ROBOTS ())

(defun generate-name ()
  (setf name "")
  (setf name (concatenate 'string name (string (elt CHARACTERS (random (length CHARACTERS))))))
  (setf name (concatenate 'string name (string (elt CHARACTERS (random (length CHARACTERS))))))
  (setf name (concatenate 'string name (string (elt NUMBERS (random (length NUMBERS))))))
  (setf name (concatenate 'string name (string (elt NUMBERS (random (length NUMBERS))))))
  (setf name (concatenate 'string name (string (elt NUMBERS (random (length NUMBERS))))))
  name)

(defun generate-unique-name ()
  (setf name (generate-name))
   (loop while (find name ROBOTS) do
	(setf name (generate-name)))
   name)

(defun build-robot ()
  (setf name (generate-unique-name))
  (push (cons name name) ROBOTS)
  name)

(defun robot-name (robot)
    (cdr (assoc robot ROBOTS)))

(defun reset-name (robot)
  (setf new-name (generate-unique-name))
  (setf ROBOTS (remove robot ROBOTS :test 'equal :key 'car)))
