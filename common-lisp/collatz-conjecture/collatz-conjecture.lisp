(defpackage #:collatz-conjecture
  (:use #:common-lisp)
  (:export #:collatz))

(in-package #:collatz-conjecture)


(defun collatz-helper(n steps)
    (if (eql n 1) steps
        (if (eql (mod n 2) 0) 
            (collatz-helper (/ n 2) (+ steps 1)) 
            (collatz-helper (+ 1 (* 3 n)) (+ steps 1)))))

(defun collatz (n)
    (when (> n 0)
        (collatz-helper n 0)))
