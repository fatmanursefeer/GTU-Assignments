(defvar Space " ")
(defvar Operator (list "+" "-" "/" "**" "*" "(" ")" "\"" ","))
(defvar Keywords (list "and" "or" "not" "equal" "less" "nil" "list" "append" "concat" "set" "deffun" "for" "if" "exit" "load" "disp" "true" "false"))
(defvar Comment ";")
(defvar OpAndOc 0)


(defun gppinterpreter (&optional inputLine)
    (if (equal inputLine nil)
        (progn
            (loop
            	(terpri)
                (setf enteredLine (read-line))    ;;reads line
                (setf enteredLine (string enteredLine))
                (princ "(")
                (if (not(string-equal (char enteredLine 0) Comment))   ;;checks comment
                    (progn
                        (setf enteredLine (string-trim '(#\Space #\Tab #\Newline) enteredLine))   ;;ignores these values
                        (parseLine enteredLine)
                    )
                    (format t "(~S \"COMMENT\")" enteredLine)
                )
                (princ ") ")
                (when (equal enteredLine nil) (return-from gppinterpreter nil))
            )
        )
        (progn
            (with-open-file (stream inputLine)  ;;opens file
                (loop for enteredLine = (read-line stream nil)
                    while enteredLine
                    collect enteredLine
                    do
                    (princ "(")
                    (if (not(= (length enteredLine) 0))
                        (if (not(string-equal (aref enteredLine 0) Comment))   ;;checks comment
                            (progn
                                (setf enteredLine (string-trim '(#\Space #\Tab #\Newline) enteredLine))
                                (parseLine enteredLine)
                            )
                            (format t "(~S \"COMMENT\")" enteredLine)
                        )
                    )
                    (princ ") ")
                )
            )  
        )
    )
)

;; this function parse the line
(defun parseLine (enteredLine)
   (defvar tempVal (list))
   (loop for lenVal from 0 to (- (length enteredLine) 1)
        do
        (if (or (string-equal (aref enteredLine lenVal) Space) (= lenVal (- (length enteredLine) 1))) 
            (progn
                (if (= lenVal (- (length enteredLine) 1))
                    (setq tempVal (append tempVal (list (aref enteredLine lenVal))))      
                )
                (parseToken tempVal)
                (setq tempVal nil)
            )
            (progn
                (setq tempVal (append tempVal (list (aref enteredLine lenVal))))
            )
        ) 
   )
)

;;this function parse the token
(defun parseToken (parsedVal)
    (setf val "")
    (defvar tokenVal (list))
    (setq lastVal "")
    (if (not (checkWord parsedVal) ) 
        (progn
            (loop for i in parsedVal
            do
                (setq lastVal i)
                (if (checkChar i)
                    (progn
                        (if (not(string-equal "" val))
                            (progn
                                (setq tokenVal (append tokenVal (list val)))
                                (setf val "")
                            )
                        )
                    (setq tokenVal (append tokenVal (list i)))
                )
                (setf val (concatenate 'string val (string i)))
            )
        )
        (if (not (checkChar lastVal))
            (setq tokenVal (append tokenVal (list val)))
        )
     )
        (progn
            (loop for i in parsedVal
               do
               (setf val (concatenate 'string val (string i)))
            )
            (setq tokenVal (append tokenVal (list val)))
        )
    )
    (checkToken tokenVal)
    (setq tokenVal nil)
)

;; this function checks the token
(defun checkToken (listOfTokens)
    (loop for i in listOfTokens
        do 
        (setq tempFlag 0)
        (loop for oper in Operator
            do (if (string-equal i oper)  ;; if it operator this will works
                (progn
                   (writeOp i)
                   (setq tempFlag 1)
                )  
            )
        )
        (if (equal tempFlag 0)
            (loop for kWord in Keywords
                do (if (string-equal i kWord)  ;; if it is keyword this will works
                    (progn
                      (writeKeyWord i)
                      (setq tempFlag 1)
                    )
                )
            ) 
        )
        (if (equal tempFlag 0)
            (if (checkIntVal i)  ;; if it is integer value this will works
                (progn
                   (writeVal i)
                   (setq tempFlag 1)
                )
            )
        )
        (if (equal tempFlag 0)
            (if (checkFloatVal i)   ;; if it is float value this will works
                (progn
                   (writeFloatVal i)
                   (setq tempFlag 1)
                )
            )
        )
        (if (equal tempFlag 0)
            (if (checkIdentity i)  ;; if it is identifier this will works
                (progn
                   (writeId i)
                   (setq tempFlag 1)
                )
            )
        )
        (if (equal tempFlag 0)
            (if (checkStr i)  ;; if it is string this will works
                (progn
                   (writeStr i)
                   (setq tempFlag 1)
                )
            )
        )
        (if (equal tempFlag 0)  ;; if it none of the above prints error and terminate the program
        	(progn
        		(format t "LEXICAL ERROR ~S cannot be tokenized" i)
        		(quit)
        	)
        )
   )
)

;; this function checks the string
(defun checkStr (tempVar)
    (setq resultVal T)
    (if (< (length tempVar) 3)
        (return-from checkFloatVal nil)
        (progn
        	(loop for lenVal from 0 to (- (length tempVar) 1)
     	 		do
     	 		  (if (= lenVal 0)
     	 		      (if (string-equal (aref tempVar 0) "\"")
     	 		         (setq resultVal T)
     	 		         (setq resultVal nil)
     	 		      )
     	 		  )
     	 		  (if (= lenVal (- (length tempVar) 1))
     	 		      (if (string-equal (aref tempVar 0) "\"")
     	 		         (setq resultVal T)
     	 		         (setq resultVal nil)
     	 		      )
     	 		  )
    		)
        )
    )
    (return-from checkStr resultVal)
)

;; this function checks the identifier
(defun checkIdentity (tempVar)
    (setq resultVal T)
    (loop for lenVal from 0 to (- (length tempVar) 1)
        do
        (if (= lenVal 0)
            (if (alpha-char-p (aref tempVar lenVal))
               (setq resultVal T)
               (if (string-equal (aref tempVar 0) "_")
              		(setq resultVal T)
              		(return-from checkIdentity nil)
              	)
            )
            (if (or (alpha-char-p (aref tempVar lenVal)) (checkDigit (aref tempVar lenVal)))
               (setq resultVal T)
               (if (string-equal (aref tempVar 0) "_")
              		(setq resultVal T)
              		(setq resultVal nil)
              	)
            )
        )
    )
    (return-from checkIdentity resultVal)
)

;;this function checks the digit
(defun checkDigit (chr)
    (loop for lenVal from 0 to 9 
        do
        (if (equal (digit-char lenVal) chr)
           (return-from checkDigit T)
        )
    )
    (return-from checkDigit nil)
)

;; this function writes the string
(defun writeStr (tempVar)
   (princ "(\"\"\" \"OP_OC\") (\"")
   (format t "~S" tempVar)
   (princ "\" \"VALUESTR\") (\"\"\" \"OP_CC\")")
)

;; this function writes the identifier
(defun writeId (tempVar)
   (princ "(")
   (format t "~S" tempVar)
   (princ " \"IDENTIFIER\")")
)

;; this function writes the integer value
(defun writeVal (tempVar)
   (princ "(\"")
   (format t "~d" tempVar)
   (princ "\" \"VALUEI\")")
)

;; this function writes the float value
(defun writeFloatVal (tempVar)
   (princ "(")
   (format t "~S" tempVar)
   (princ " \"VALUEF\")")
)

;; this function checks the integer value
(defun checkIntVal (tempVar)
    (setq resultVal T)
    (if (= (length tempVar) 1)
        (if (string-equal (aref tempVar 0) "0")
            (return-from checkIntVal T)
            (if (checkDigit (aref tempVar 0))
               (return-from checkIntVal T)
               (return-from checkIntVal nil)
            )
        )
        (progn
            (loop for lenVal from 0 to (- (length tempVar) 1)
                do
                (if (= lenVal 0)
                    (if (string-equal (aref tempVar lenVal) "0")
                        (return-from checkIntVal nil)
                        (if (checkDigit (aref tempVar lenVal))
                            (setq resultVal T)
                            (return-from checkIntVal nil)
                        )
                    )
                    (if (checkDigit (aref tempVar lenVal))
                        (setq resultVal T)
                        (return-from checkIntVal nil)
                    )
                )
            )
            (return-from checkIntVal resultVal)  
        )
    )
)

;; this function checks the float value
(defun checkFloatVal (tempVar)
    (setq resultVal T)
    (setq counter 0)
    (if (< (length tempVar) 3)
        (return-from checkFloatVal nil)
        (progn
            (loop for lenVal from 0 to (- (length tempVar) 1)
                do
                (if (= lenVal 0)
                    (if (string-equal (aref tempVar lenVal) "0")
                        (return-from checkFloatVal nil)
                        (if (checkDigit (aref tempVar lenVal))
                            (setq resultVal T)
                            (return-from checkFloatVal nil)
                        )
                    )
                    (if (checkDigit (aref tempVar lenVal))
                       (setq resultVal T)
                       (progn
                       	(if (string-equal (aref tempVar lenVal) "f")
                       		(if (< counter 1)
                				(progn
                   					(setq counter (+ counter 1))
                   					(setq resultVal T)
                				)
                				(return-from checkFloatVal nil)
                			)
                			(return-from checkFloatVal nil)
                       	)
                       )
                    )
                )
            )
            (return-from checkFloatVal resultVal)  
        )
    )
)

;; this function writes the keywords
(defun writeKeyWord (tempVar)
   (cond
      ((string-equal tempVar "and") (princ "(\"and\" \"KW_AND\")"))
      ((string-equal tempVar "or") (princ "(\"or\" \"KW_OR\")"))
      ((string-equal tempVar "not") (princ "(\"not\" \"KW_NOT\")"))
      ((string-equal tempVar "equal") (princ "(\"equal\" \"KW_EQUAL\")"))
      ((string-equal tempVar "less") (princ "(\"less\" \"KW_LESS\")"))
      ((string-equal tempVar "nil") (princ "(\"nil\" \"KW_NIL\")"))
      ((string-equal tempVar "list") (princ "(\"list\" \"KW_LIST\")"))
      ((string-equal tempVar "append") (princ "(\"append\" \"KW_APPEND\")"))
      ((string-equal tempVar "concat") (princ "(\"concat\" \"KW_CONCAT\")"))
      ((string-equal tempVar "set") (princ "(\"set\" \"KW_SET\")"))
      ((string-equal tempVar "deffun") (princ "(\"deffun\" \"KW_DEFFUN\")"))
      ((string-equal tempVar "for") (princ "(\"for\" \"KW_FOR\")"))
      ((string-equal tempVar "if") (princ "(\"if\" \"KW_IF\")"))
      ((string-equal tempVar "exit") (princ "(\"exit\" \"KW_EXIT\")"))
      ((string-equal tempVar "load") (princ "(\"load\" \"KW_LOAD\")"))
      ((string-equal tempVar "disp") (princ "(\"disp\" \"KW_DISP\")"))
      ((string-equal tempVar "true") (princ "(\"true\" \"KW_TRUE\")"))
      ((string-equal tempVar "false") (princ "(\"false\" \"KW_FALSE\")"))
   )
)

;; this function writes the operations
(defun writeOp (tempVar)
   (cond
        ((string-equal tempVar "+") (princ "(\"+\" \"OP_PLUS\")"))
        ((string-equal tempVar "-") (princ "(\"-\" \"OP_MINUS\")"))
        ((string-equal tempVar "/") (princ "(\"/\" \"OP_DIV\")"))
        ((string-equal tempVar "**") (princ "(\"**\" \"OP_DBLMULT\")"))
        ((string-equal tempVar "*") (princ "(\"*\" \"OP_MULT\")"))
        ((string-equal tempVar "(") (princ "(\"(\" \"OP_OP\")"))
        ((string-equal tempVar ")") (princ "(\")\" \"OP_CP\")"))
        ((string-equal tempVar "\"") 
            (if (= OpAndOc 0)
                (progn
                   (princ "(\"\"\" \"OP_OC\")")
                   (setf OpAndOc 1)
                )
                (progn
                   (princ "(\"\"\" \"OP_CC\")")
                   (setf OpAndOc 0)
                )
            )
        )
        ((string-equal tempVar ",") (princ "(\",\" \"OP_COMMA\")")) 
   )
)

;; this function checks the chars
(defun checkChar (chr)
    (loop for oper in Operator
        do
            (if (string-equal chr oper)
               (return-from checkChar t)                 
            )
    )
    (return-from checkChar nil)
)

;; this function checks the words
(defun checkWord (parsedVal)
    (loop for m in parsedVal
        do
        (loop for n in Operator
            do  (if (string-equal m n)
                    (return-from checkWord nil)
                )
        )
    )
    (return-from checkWord T)
)

(defun mainFunction ()
    (terpri)
    (format t "Please type a file name or type terminal to continue with terminal or type CTRL+C for exit to program ~%")
    (setf inputLine (read))
    (if (string-equal "terminal" inputLine) 
        (gppinterpreter )
        (gppinterpreter (string-downcase inputLine))
    )
)

(mainFunction )



