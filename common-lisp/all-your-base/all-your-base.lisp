(in-package #:cl-user)
(defpackage #:all-your-base
  (:use #:common-lisp)
  (:export #:rebase))

(in-package #:all-your-base)

(defun input-is-valid (list-digits in-base out-base)
  (when (and 
	  (= (count t 
		    (map 
		      'list 
		      (lambda (x) (or (>= x in-base) (< x 0)))
		      list-digits))
	     0)
	  (> in-base 1)
	  (> out-base 1))
    t))

(defun base-to-10 (list-digits in-base)
  (if (null list-digits)
    0
    (apply #'+
	   (map 'list 
		(lambda (x y) (* x (expt in-base y))) 
		list-digits 
		(loop for n from (- (length list-digits) 1) downto -1 
		      collect n)))))

(defun dec-to-base (num out-base)
  (let ((x num)
	(result '()))
	(loop while (> x 0) do
	      (multiple-value-bind (q r) (floor x out-base)
		(setf x q)
		(setf result (append (list r) result))))  
	(if (= (length result) 0) (list 0 ) result)))

(defun rebase (list-digits in-base out-base)
  (print (input-is-valid list-digits in-base out-base))
  (when (input-is-valid list-digits in-base out-base)
    (dec-to-base (base-to-10 list-digits in-base) out-base)))


