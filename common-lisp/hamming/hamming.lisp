(defpackage #:hamming
  (:use #:cl)
  (:export #:distance)
  )

(in-package #:hamming)

(defun distance(dna1 dna2)
  (if (not (eql (length dna1) (length dna2))) nil  
    (let ((x 0))
      (loop :for i :from 0 :to (- (length dna1) 1)
	    do (if (not (eql (elt dna1 i) (elt dna2 i)))
		 (incf x)))
      x)))

