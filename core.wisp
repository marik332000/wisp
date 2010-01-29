;;; Core definitions for Wisp

;; Set up require
(defun apply (f lst)
  (if (not (listp lst))
      (throw 'wrong-type-argument lst)
    (eval (cons f lst))))

(defun concat (str &rest strs)
  (if (nullp strs)
      str
    (concat2 str (apply concat strs))))

(defun require (lib)
  (load (concat wisproot "/wisplib/" (symbol-name lib) ".wisp")))

;; Load up other default libraries
(require 'list)
(require 'math)

(defmacro setq (var val)
  (list 'set (list 'quote var) val))

(defun equal (a b)
  (or (eql a b)
      (and (listp a)
	   (listp b)
	   (equal (car a) (car b))
	   (equal (cdr a) (cdr b)))))
