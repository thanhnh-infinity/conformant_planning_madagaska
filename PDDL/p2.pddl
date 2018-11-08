	
(define (problem ring-win-2)

  (:domain ring)

  (:objects win1 win2 pos1 pos2)

  (:init

    (position pos1)
    (position pos2)

    (oneof   (position pos1)
	     (position pos2))

    (open win1)
    (closed win1)
    (locked win1)

    (oneof   (open win1)
             (closed win1)
             (locked win1))

    (or   (position pos1)
	      (position pos2))
	      
    (open win2)
    (closed win2)
    (locked win2)
    
    (or (test) (open win1))

    (oneof   (open win2)
             (closed win2)
             (locked win2))
)

(:goal 

(and 
	(locked win1) 
	(locked win2) 
)

)

)
