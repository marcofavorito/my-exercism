(defpackage #:sublist
  (:use #:common-lisp)
  (:export #:sublist))

(in-package #:sublist)


(defun lge (list1 list2)
  (if (= (length list1) (length list2))
   0 
  (if (> (length list1) (length list2))
   -1
   1)))
    

(defun sublist_equal (list1 list2)
  ":equal if lists are equal, :unequal otherwise"
  (if (= 0 (count t (map 'list #'/= list1 list2))) :equal :unequal))

(defun sublist_lower (list1 list2)
  (assert (< (length list1) (length list2)))
  (let ((*min_counter* 0) (*max_counter* 0))
  (loop while (and (< *max_counter* (length list2)) (< *min_counter* (length list1))) 
	do 
	(if (= (elt list1 *min_counter*) (elt list2 *max_counter*))
	     (incf *min_counter*)
	     (progn
	       (setf *max_counter* (- *max_counter* *min_counter*))
	       (setf *min_counter* 0)))
	(incf *max_counter*))
  (if (= *min_counter* (length list1)) :sublist :unequal)))

(defun sublist_greater (list1 list2)
  (assert (> (length list1) (length list2)))
  (setf result (sublist_lower list2 list1))
  (print result)
  (if (eql result :sublist) :superlist :unequal))

(defun sublist (list1 list2)
  "what is list1 of list2 (sublist, superlist, equal or unequal"
  (setf x (lge list1 list2))
  (print x)
  (print list1)
  (print list2)
  (case x
    ((0) (sublist_equal list1 list2))
    ((1) (sublist_lower list1 list2))
    ((-1) (sublist_greater list1 list2))))

