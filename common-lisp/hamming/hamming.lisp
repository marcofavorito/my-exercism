(defpackage #:hamming
  (:use #:cl)
  (:export #:distance)
  )

(in-package #:hamming)

(defun distance(dna1 dna2)
  (when (= (length dna1) (length dna2))  
    (let ((x 0))
      (loop :for i :from 0 :to (- (length dna1) 1)
	    do (unless (char= (elt dna1 i) (elt dna2 i))
		 (incf x)))
      x)))

