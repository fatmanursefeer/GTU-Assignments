(defvar Space " ")
(defvar Operator (list "+" "-" "/" "*" "(" ")" ","))
(defvar Keywords (list "and" "or" "not" "equal" "gt" "set" "defvar" "deffun" "while" "if" "true" "false")) 
(defvar Comment ";")
(defvar listOfToken (list))
(defvar vars (list))

; this function read a line repl
(defun gppinterpreter ()
	(loop
		(terpri)
		(terpri)
		(princ "Enter line: ")
		(setf enteredLine (read-line))
        (setf enteredLine (string enteredLine))
		(if (string-equal (char enteredLine 0) Comment)
            (princ "Syntax OK. This is COMMENT")
            (progn
              	(setf enteredLine (string-trim '(#\Space #\Tab #\Newline #\Backspace #\Return) enteredLine))
              	(parseLine enteredLine)
            )
        )
        (when (equal enteredLine nil) (return-from gppinterpreter nil))
    )
)

; this function parses the line 
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
            (setq tempVal (append tempVal (list (aref enteredLine lenVal))))
        ) 
   )
   (checkOfToken listOfToken)
   (setq listOfToken nil)
)

; this function parses the token
(defun parseToken (parsedVal)
   (setf val "")
   (defvar tokenVal (list))
   (setq lastVal "")
   (if (checkWord parsedVal)
        (progn
            (loop for i in parsedVal
                do
                (setf val (concatenate 'string val (string i)))
            )
            (setq tokenVal (append tokenVal (list val)))
        )
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
    )
    (loop for i in tokenVal
        do
        (if (not (string-equal i ""))
            (setq listOfToken (append listOfToken (list i)))
        )
    )
    (setq tokenVal nil)
)

; this function checks the token is right or not. If it is not prints error and terminate the program
(defun checkOfToken (listOfTokens)
	(setf f 0)
   (setq listOfToken nil)
   (loop for i in listOfTokens
        do 
        (setq tempFlag 0)
        (loop for oper in Operator
            do (if (string-equal i oper)
                (progn
                    (setq listOfToken (append listOfToken (list (take_operator i))))
                    (setq tempFlag 1)
                )  
            )
        )
        (if (equal tempFlag 0)
            (loop for kWord in Keywords
                do (if (string-equal i kWord)
                    (progn
                        (setq listOfToken (append listOfToken (list (take_keyword i))))
                        (setq tempFlag 1)
                    )
                )
            ) 
        )
        (if (equal tempFlag 0)
            (if (checkFloatVal i)
                (progn
                    (setq listOfToken (append listOfToken (list i)))
                    (setq tempFlag 1)
                )
            )
        )
        (if (equal tempFlag 0)
            (if (checkIdentity i)
                (progn
                    (setq listOfToken (append listOfToken (list i)))
                    (setq tempFlag 1)
                )
            )
        )
        (if (equal tempFlag 0)
            (progn
                (princ "SYNTAX ERROR! Expression not recognized.")
                (exit)
            )
        )
    )
    (setq parseNumber 0)
    (setq paranth 1)
    (setq count 0)
    (loop for j in listOfToken
        do
        (if (or (and (string-equal j "OP_PLUS") (string-equal (nth (+ count 1) listOfToken) "OP_PLUS"))
                (and (string-equal j "OP_MINUS") (string-equal (nth (+ count 1) listOfToken) "OP_MINUS"))
                (and (string-equal j "OP_MULT") (string-equal (nth (+ count 1) listOfToken) "OP_MULT"))
                (and (string-equal j "OP_DIV") (string-equal (nth (+ count 1) listOfToken) "OP_DIV"))
            )
            (progn
                (princ "SYNTAX ERROR! Expression not recognized.")
                (exit)
            )
        )
        (setq count (+ count 1))
    )
    (loop for i in listOfToken
        do
        (if (string-equal i "OP_OP")
            (progn
                (setq parseNumber (+ parseNumber 1))
                (setq paranth 0)
            )
           
        )
        (if (string-equal i "OP_CP")
            (progn
                (setq parseNumber (- parseNumber 1))
                (setq paranth 0)
            )
        )   
    )
    (if (or (not (equal parseNumber 0)) (equal paranth 1)) 
        (progn
            (princ "Syntax ERROR! Missing parantheses.")
            (return-from checkOfToken nil)
        )
    )
    (princ "Syntax OK. Result: ")
    (princ (convertFloatToString (checkSyntax listOfToken)))
)

; this function convert the value float to string. For example 1.5 => 3f2
(defun convertFloatToString (newNumber)
    (if (or (typep newNumber 'string) (typep newNumber 'boolean))
        (return-from convertFloatToString newNumber)
        (progn 
            (setf flag 0)
	        (setf val "f1")
	        (setf newNumber (write-to-string newNumber))
            (loop for lenVal from 0 to (- (length newNumber) 1)
                do
                (if (string-equal (aref newNumber lenVal) #\/)
                	(progn 
                    	(setf (aref newNumber lenVal) #\f)
                    	(setf flag 1)	
                    )
                )
            )
            (if (equal flag 0)
            	(setf newNumber (concatenate 'string newNumber val))
            )
            (return-from convertFloatToString newNumber)
        )
    )
)  

; this function converts the value string to float. For example 3f2 => 1.5
(defun convertStringToFloat (num)
    (setf val "")
    (setf num1 0)
    (setf num2 0)
    (setf newNumber 0)
    (setf val (concatenate 'string val num))
    (loop for lenVal from 0 to (- (length val) 1)
        do
        (if (string-equal (aref val lenVal) "f")
            (progn
            	(setf num1 (subseq val 0 lenVal))
                (setf num2 (subseq val (+ lenVal 1)))
            	(setf num1 (with-input-from-string (in num1) (read in)))
                (setf num2 (with-input-from-string (in num2) (read in)))
                (setf newNumber (/ num1 num2))
            )
        )
    )
    (return-from convertStringToFloat newNumber)
)

(defun convertStringToBinary (num)
    (setf binVal 2)
    (if (string-equal num "KW_TRUE")
        (setf binVal 1)
        (setf binVal 0)
    )
    (if (> binVal 1)
        (progn
            (princ "SYNTAX ERROR! Expression not recognized.")
            (exit)
        )
    )
    (return-from convertStringToBinary binVal)
)

; this function checks the syntax. if the syntax is not correct gives an error and terminate the program
(defun checkSyntax (listOfArg)
    (let ((arg1 0) (arg2 0))
        (cond
            ( (string-equal (nth 1 listOfArg) "OP_PLUS")  
                (progn
                    (if (not (checkIdentity (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (take_value (nth 2 listOfArg))))
                    )
                    (if (not (checkIdentity (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (take_value (nth 3 listOfArg))))
                    )
                    (if (or (equal arg1 nil) (equal arg2 nil))
                        (progn
                            (princ "SYNTAX ERROR! Expression not recognized.")
                            (return-from checkSyntax nil)
                        )
                        (return-from checkSyntax (+ arg1 arg2))
                    )
                )
            )
            ( (string-equal (nth 1 listOfArg) "OP_MINUS") 
                (progn
                    (if (not (checkIdentity (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (take_value (nth 2 listOfArg))))
                    )
                    (if (not (checkIdentity (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (take_value (nth 3 listOfArg))))
                    )
                    (if (or (equal arg1 nil) (equal arg2 nil))
                        (progn
                            (princ "SYNTAX ERROR! Expression not recognized.")
                            (return-from checkSyntax nil)
                        )
                        (return-from checkSyntax (- arg1 arg2))
                    )
                )
            )
            ( (string-equal (nth 1 listOfArg) "OP_MULT") 
                (progn
                    (if (not (checkIdentity (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (take_value (nth 2 listOfArg))))
                    )
                    (if (not (checkIdentity (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (take_value (nth 3 listOfArg))))
                    )
                    (if (or (equal arg1 nil) (equal arg2 nil))
                        (progn
                            (princ "SYNTAX ERROR! Expression not recognized.")
                            (return-from checkSyntax nil)
                        )
                        (return-from checkSyntax (* arg1 arg2))
                    )
                )
            )
            ( (string-equal (nth 1 listOfArg) "OP_DIV") 
                (progn
                    (if (not (checkIdentity (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (take_value (nth 2 listOfArg))))
                    )
                    (if (not (checkIdentity (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (take_value (nth 3 listOfArg))))
                    )
                    (if (or (equal arg1 nil) (equal arg2 nil))
                        (progn
                            (princ "SYNTAX ERROR! Expression not recognized.")
                            (return-from checkSyntax nil)
                        )
                        (return-from checkSyntax (/ arg1 arg2))
                    )
                )
            )
            ( (string-equal (nth 1 listOfArg) "KW_AND")  
                (progn
                    (if (not (checkIdentity (nth 2 listOfArg)))
                        (setq arg1 (convertStringToBinary (nth 2 listOfArg)))
                        (setq arg1 (convertStringToBinary (take_value (nth 2 listOfArg))))
                    )
                    (if (not (checkIdentity (nth 3 listOfArg)))
                        (setq arg2 (convertStringToBinary (nth 3 listOfArg)))
                        (setq arg2 (convertStringToBinary (take_value (nth 3 listOfArg))))
                    )
                    (if (or (equal arg1 nil) (equal arg2 nil))
                        (progn
                            (princ "SYNTAX ERROR! Expression not recognized.")
                            (return-from checkSyntax nil)
                        )
                        (progn
                            (if (> (+ arg1 arg2) 1)
                                (return-from checkSyntax T)
                                (return-from checkSyntax NIL)
                            )
                        )
                    )
                )
            )
            ( (string-equal (nth 1 listOfArg) "KW_OR")  
                (progn
                    (if (not (checkIdentity (nth 2 listOfArg)))
                        (setq arg1 (convertStringToBinary (nth 2 listOfArg)))
                        (setq arg1 (convertStringToBinary (take_value (nth 2 listOfArg))))
                    )
                    (if (not (checkIdentity (nth 3 listOfArg)))
                        (setq arg2 (convertStringToBinary (nth 3 listOfArg)))
                        (setq arg2 (convertStringToBinary (take_value (nth 3 listOfArg))))
                    )
                    (if (or (equal arg1 nil) (equal arg2 nil))
                        (progn
                            (princ "SYNTAX ERROR! Expression not recognized.")
                            (return-from checkSyntax nil)
                        )
                        (progn
                            (if (> (+ arg1 arg2) 0)
                                (return-from checkSyntax T)
                                (return-from checkSyntax nil)
                            )
                        )
                    )
                )
            )
            ( (string-equal (nth 1 listOfArg) "KW_NOT")  
                (progn
                    (if (not (checkIdentity (nth 2 listOfArg)))
                        (setq arg1 (convertStringToBinary (nth 2 listOfArg)))
                        (setq arg1 (convertStringToBinary (take_value (nth 2 listOfArg))))
                    )
                    (if (not (equal arg1 nil))
                        (progn
                            (if (equal arg1 0)
                                (return-from checkSyntax T)
                                (return-from checkSyntax nil)
                            )
                        )
                        (progn
                            (princ "SYNTAX ERROR! Expression not recognized.")
                            (return-from checkSyntax nil)
                        )
                    )
                )
            )
            ( (string-equal (nth 1 listOfArg) "KW_EQUAL")  
                (progn
                    (if (not (checkIdentity (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (take_value (nth 2 listOfArg))))
                    )
                    (if (not (checkIdentity (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (take_value (nth 3 listOfArg))))
                    )
                    (if (or (equal arg1 nil) (equal arg2 nil))
                        (progn
                            (princ "SYNTAX ERROR! Expression not recognized.")
                            (return-from checkSyntax nil)
                        )
                        (return-from checkSyntax (equal arg1 arg2))
                    )
                )
            )
            ( (string-equal (nth 1 listOfArg) "KW_GT")  
                (progn
                    (if (not (checkIdentity (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (nth 2 listOfArg)))
                        (setq arg1 (convertStringToFloat (take_value (nth 2 listOfArg))))
                    )
                    (if (not (checkIdentity (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (nth 3 listOfArg)))
                        (setq arg2 (convertStringToFloat (take_value (nth 3 listOfArg))))
                    )
                    (if (or (equal arg1 nil) (equal arg2 nil))
                        (progn
                            (princ "SYNTAX ERROR! Expression not recognized.")
                            (return-from checkSyntax nil)
                        )
                        (return-from checkSyntax (> arg1 arg2))
                    )
                )
            )
            ( (string-equal (nth 1 listOfArg) "KW_SET") 
                (progn
                    (setq arg2 (nth 3 listOfArg))
                    (if (not (checkCont (nth 2 listOfArg)))
                        (setq vars (append vars (list (list (nth 2 listOfArg) arg2))))
                        (arrange (nth 2 listOfArg) arg2)
                    )
                    (return-from checkSyntax arg2)
                )
            )
            ( (string-equal (nth 1 listOfArg) "KW_DEFVAR") 
                (progn
                    (setq arg2 (nth 3 listOfArg))
                    (if (not (checkCont (nth 2 listOfArg)))
                        (setq vars (append vars (list (list (nth 2 listOfArg) arg2))))
                        (arrange (nth 2 listOfArg) arg2)
                    )
                    (return-from checkSyntax arg2)
                )
            )
        )
    )
)

; this function controls the variables
(defun checkCont (tempVar)
    (loop for x from 0 to (- (length vars) 1)
        do
        (if (string-equal tempVar (nth 0 (nth x vars)))
            (return-from checkCont T)
        )
    )
    nil
)

; this function arrange the variables
(defun arrange (tempVar number)
    (let ((tValue (list)))
        (loop for x from 0 to (- (length vars) 1)
            do
            (if (not (string-equal tempVar (nth 0 (nth x vars))))
                (setq tValue (append tValue (list (list tempVar (nth 1 (nth x vars))))))
                (setq tValue (append tValue (list (list tempVar number))))
            )
        )
        (setq vars tValue)
    )
)

; this function takes the value
(defun take_value (tempVar)
    (loop for x from 0 to (- (length vars) 1)
        do
        (if (string-equal tempVar (nth 0 (nth x vars)))
            (return-from take_value (nth 1 (nth x vars)))
        )
    )
    nil
)

; this function checks the token is identifier or not
(defun checkIdentity (tempVar)
    (setq resultVal T)
    (loop for x from 0 to (- (length tempVar) 1)
        do
        (if (= x 0)
            (if (not (alpha-char-p (aref tempVar x)))
                (return-from checkIdentity nil)
                (setq resultVal T)
            )
            (if (or (alpha-char-p (aref tempVar x)) (checkDigit (aref tempVar x)))
                (setq resultVal T)
                (return-from checkIdentity nil)
            )
        )
    )
    (return-from checkIdentity resultVal)
)

; this function checks the token is digit or not
(defun checkDigit (chr)
    (loop for x from 0 to 9 
        do
        (if (equal (digit-char x) chr)
            (return-from checkDigit T)
        )
    )
    (return-from checkDigit nil)
)

; this function checks the token is float number or not
(defun checkFloatVal (tempVar)
    (setq resultVal T)
    (setq counter 0)
    (setq flag 0)
    (setq fFlag 0)
    (if (< (length tempVar) 3)
        (progn
        	(princ "SYNTAX ERROR! The length of the valuef cannot be less than 3 !")
        	(exit)
        )
        (progn
            (if (= (length tempVar) 3)
                (if (not (string-equal (aref tempVar 1) "f"))
                    (progn
                    	(princ "SYNTAX ERROR! Expression not recognized!")
                    	(exit)
                    )
                    (progn
                        (if (or (checkDigit (aref tempVar 0)) (checkDigit (aref tempVar 2)))
                            (progn
                            	(if (not (string-equal (aref tempVar 2) #\0))
                            		(setq resultVal T)
                            		(progn
                            			(princ "SYNTAX ERROR! Number can not be divide by zero!")
                            			(exit)
                            		)
                            	)
                            )
                            (progn
                            	(princ "SYNTAX ERROR! Expression not recognized!")
                            	(exit)
                            )
                        )
                    )
                )
                (progn
                    (loop for lenVal from 0 to (- (length tempVar) 1)
                        do
                        (if (checkDigit (aref tempVar lenVal))
                            (setq resultVal T)
                            (progn
                           	    (if (string-equal (aref tempVar lenVal) "f")
                                    (progn
                                        (setq fFlag 1)
                                        (if (< counter 1)
                	    	    		    (progn
                   	    	    		    	(setq counter (+ counter 1))
                   	    	    		    	(setq resultVal T)
                	    	    		    )
                	    	    		    (progn
                	    	    		    	(princ "SYNTAX ERROR! Expression not recognized!")
                	    	    		    	(exit)
                	    	    		    )
                	    	    	    )
                                        (setq flag (+ lenVal 1))
                                    )
                                    (progn
                                    	(princ "SYNTAX ERROR! Expression not recognized!")
                                    	(exit)
                                    )
                           	    )
                            )
                        )
                    )
                    (if (string-equal (aref tempVar flag) #\0)
            		    (progn
               		        (princ "SYNTAX ERROR! Leading zero!")
                           	(exit)
               	        )
               	    )
                    (if (equal fFlag 0)
                        (progn
                        	(princ "SYNTAX ERROR! Expression not recognized!")
                        	(exit)
                        )
                    )
                )    
            )
            (return-from checkFloatVal resultVal)
        )
    )
)

; this function checks the token is char or not
(defun checkChar (chr)
    (loop for oper in Operator
        do
        (if (string-equal chr oper)
            (return-from checkChar t)                 
        )
    )
    (return-from checkChar nil)
)

; this function checks the token is word or not
(defun checkWord (parsedVal)
    (loop for m in parsedVal
        do
        (loop for n in Operator
            do (if (string-equal m n)
                (return-from checkWord nil)
            )
        )
    )
    (return-from checkWord T)
)

; this function takes the keyword
(defun take_keyword (tempVar)
    (cond
        ((string-equal tempVar "and") (return-from take_keyword "KW_AND"))
        ((string-equal tempVar "or") (return-from take_keyword "KW_OR"))
        ((string-equal tempVar "not") (return-from take_keyword "KW_NOT"))
        ((string-equal tempVar "equal") (return-from take_keyword "KW_EQUAL"))
        ((string-equal tempVar "gt") (return-from take_keyword "KW_GT"))
        ((string-equal tempVar "list") (return-from take_keyword "KW_LIST"))
        ((string-equal tempVar "set") (return-from take_keyword "KW_SET"))
        ((string-equal tempVar "defvar") (return-from take_keyword "KW_DEFVAR"))
        ((string-equal tempVar "deffun") (return-from take_keyword "KW_DEFFUN"))
        ((string-equal tempVar "while") (return-from take_keyword "KW_WHILE"))
        ((string-equal tempVar "if") (return-from take_keyword "KW_IF"))
        ((string-equal tempVar "exit") (return-from take_keyword "KW_EXIT"))
        ((string-equal tempVar "true") (return-from take_keyword "KW_TRUE"))
        ((string-equal tempVar "false") (return-from take_keyword "KW_FALSE"))
    )
)

; this function takes the operator
(defun take_operator (tempVar)
    (cond
        ((string-equal tempVar "+") (return-from take_operator "OP_PLUS"))
        ((string-equal tempVar "-") (return-from take_operator "OP_MINUS"))
        ((string-equal tempVar "*") (return-from take_operator "OP_MULT"))
        ((string-equal tempVar "/") (return-from take_operator "OP_DIV"))
        ((string-equal tempVar "(") (return-from take_operator "OP_OP"))
        ((string-equal tempVar ")") (return-from take_operator "OP_CP"))
        ((string-equal tempVar ",") (return-from take_operator "OP_COMMA")) 
    )
)

(gppinterpreter )

