(defpackage #:hamming
  (:use #:cl)
  (:export #:distance)
  )

(in-package #:hamming)

(defun distance(dna1 dna2)
  (when (= (length dna1) (length dna2))  
    (apply #'+ 
	 (mapcar (lambda (pair) (if (char= (first pair) (second pair)) 0 1))
		  (mapcar #'list 
			  (coerce dna1 'list) (coerce dna2 'list))))))




