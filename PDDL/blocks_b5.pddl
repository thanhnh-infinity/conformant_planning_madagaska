(define (problem b5)
  (:domain blocks)
  (:objects A B C D E - block)
  (:init
    (oneof (handempty) (holding A) (holding B) (holding C) (holding D) (holding E)) ; (holding ?x)
         (oneof (holding A) (clear A) (on B A) (on C A) (on D A) (on E A))            ; (above A ?x)
         (oneof (holding A) (ontable A) (on A B) (on A C) (on A D) (on A E))          ; (on A ?x)
         (oneof (holding B) (clear B) (on A B) (on C B) (on D B) (on E B))            ; (above B ?x)
         (oneof (holding B) (ontable B) (on B A) (on B C) (on B D) (on B E))          ; (on B ?x)
         (oneof (holding C) (clear C) (on A C) (on B C) (on D C) (on E C))            ; (above C ?x)
         (oneof (holding C) (ontable C) (on C A) (on C B) (on C D) (on C E))          ; (on C ?x)
         (oneof (holding D) (clear D) (on A D) (on B D) (on C D) (on E D))            ; (above D ?x)
         (oneof (holding D) (ontable D) (on D A) (on D B) (on D C) (on D E))          ; (on D ?x)
         (oneof (holding E) (clear E) (on A E) (on B E) (on C E) (on D E))            ; (above E ?x)
         (oneof (holding E) (ontable E) (on E A) (on E B) (on E C) (on E D))          ; (on E ?x)

         (or (not (handempty)) (not (holding A)))
         (or (not (handempty)) (not (holding B)))
         (or (not (handempty)) (not (holding C)))
         (or (not (handempty)) (not (holding D)))
         (or (not (handempty)) (not (holding E)))
         (or (not (holding A)) (not (holding B)))
         (or (not (holding A)) (not (holding C)))
         (or (not (holding A)) (not (holding D)))
         (or (not (holding A)) (not (holding E)))
         (or (not (holding B)) (not (holding C)))
         (or (not (holding B)) (not (holding D)))
         (or (not (holding B)) (not (holding E)))
         (or (not (holding C)) (not (holding D)))
         (or (not (holding C)) (not (holding E)))
         (or (not (holding D)) (not (holding E)))

         (or (not (holding A)) (not (clear A)))
         (or (not (holding A)) (not (on B A)))
         (or (not (holding A)) (not (on C A)))
         (or (not (holding A)) (not (on D A)))
         (or (not (holding A)) (not (on E A)))
         (or (not (clear A)) (not (on B A)))
         (or (not (clear A)) (not (on C A)))
         (or (not (clear A)) (not (on D A)))
         (or (not (clear A)) (not (on E A)))
         (or (not (on B A)) (not (on C A)))
         (or (not (on B A)) (not (on D A)))
         (or (not (on B A)) (not (on E A)))
         (or (not (on C A)) (not (on D A)))
         (or (not (on C A)) (not (on E A)))
         (or (not (on D A)) (not (on E A)))

         (or (not (holding A)) (not (ontable A)))
         (or (not (holding A)) (not (on A B)))
         (or (not (holding A)) (not (on A C)))
         (or (not (holding A)) (not (on A D)))
         (or (not (holding A)) (not (on A E)))
         (or (not (ontable A)) (not (on A B)))
         (or (not (ontable A)) (not (on A C)))
         (or (not (ontable A)) (not (on A D)))
         (or (not (ontable A)) (not (on A E)))
         (or (not (on A B)) (not (on A C)))
         (or (not (on A B)) (not (on A D)))
         (or (not (on A B)) (not (on A E)))
         (or (not (on A C)) (not (on A D)))
         (or (not (on A C)) (not (on A E)))
         (or (not (on A D)) (not (on A E)))

         (or (not (holding B)) (not (clear B)))
         (or (not (holding B)) (not (on A B)))
         (or (not (holding B)) (not (on C B)))
         (or (not (holding B)) (not (on D B)))
         (or (not (holding B)) (not (on E B)))
         (or (not (clear B)) (not (on A B)))
         (or (not (clear B)) (not (on C B)))
         (or (not (clear B)) (not (on D B)))
         (or (not (clear B)) (not (on E B)))
         (or (not (on A B)) (not (on C B)))
         (or (not (on A B)) (not (on D B)))
         (or (not (on A B)) (not (on E B)))
         (or (not (on C B)) (not (on D B)))
         (or (not (on C B)) (not (on E B)))
         (or (not (on D B)) (not (on E B)))

         (or (not (holding B)) (not (ontable B)))
         (or (not (holding B)) (not (on B A)))
         (or (not (holding B)) (not (on B C)))
         (or (not (holding B)) (not (on B D)))
         (or (not (holding B)) (not (on B E)))
         (or (not (ontable B)) (not (on B A)))
         (or (not (ontable B)) (not (on B C)))
         (or (not (ontable B)) (not (on B D)))
         (or (not (ontable B)) (not (on B E)))
         (or (not (on B A)) (not (on B C)))
         (or (not (on B A)) (not (on B D)))
         (or (not (on B A)) (not (on B E)))
         (or (not (on B C)) (not (on B D)))
         (or (not (on B C)) (not (on B E)))
         (or (not (on B D)) (not (on B E)))

         (or (not (holding C)) (not (clear C)))
         (or (not (holding C)) (not (on A C)))
         (or (not (holding C)) (not (on B C)))
         (or (not (holding C)) (not (on D C)))
         (or (not (holding C)) (not (on E C)))
         (or (not (clear C)) (not (on A C)))
         (or (not (clear C)) (not (on B C)))
         (or (not (clear C)) (not (on D C)))
         (or (not (clear C)) (not (on E C)))
         (or (not (on A C)) (not (on B C)))
         (or (not (on A C)) (not (on D C)))
         (or (not (on A C)) (not (on E C)))
         (or (not (on B C)) (not (on D C)))
         (or (not (on B C)) (not (on E C)))
         (or (not (on D C)) (not (on E C)))

         (or (not (holding C)) (not (ontable C)))
         (or (not (holding C)) (not (on C A)))
         (or (not (holding C)) (not (on C B)))
         (or (not (holding C)) (not (on C D)))
         (or (not (holding C)) (not (on C E)))
         (or (not (ontable C)) (not (on C A)))
         (or (not (ontable C)) (not (on C B)))
         (or (not (ontable C)) (not (on C D)))
         (or (not (ontable C)) (not (on C E)))
         (or (not (on C A)) (not (on C B)))
         (or (not (on C A)) (not (on C D)))
         (or (not (on C A)) (not (on C E)))
         (or (not (on C B)) (not (on C D)))
         (or (not (on C B)) (not (on C E)))
         (or (not (on C D)) (not (on C E)))

         (or (not (holding D)) (not (clear D)))
         (or (not (holding D)) (not (on A D)))
         (or (not (holding D)) (not (on B D)))
         (or (not (holding D)) (not (on C D)))
         (or (not (holding D)) (not (on E D)))
         (or (not (clear D)) (not (on A D)))
         (or (not (clear D)) (not (on B D)))
         (or (not (clear D)) (not (on C D)))
         (or (not (clear D)) (not (on E D)))
         (or (not (on A D)) (not (on B D)))
         (or (not (on A D)) (not (on C D)))
         (or (not (on A D)) (not (on E D)))
         (or (not (on B D)) (not (on C D)))
         (or (not (on B D)) (not (on E D)))
         (or (not (on C D)) (not (on E D)))

         (or (not (holding D)) (not (ontable D)))
         (or (not (holding D)) (not (on D A)))
         (or (not (holding D)) (not (on D B)))
         (or (not (holding D)) (not (on D C)))
         (or (not (holding D)) (not (on D E)))
         (or (not (ontable D)) (not (on D A)))
         (or (not (ontable D)) (not (on D B)))
         (or (not (ontable D)) (not (on D C)))
         (or (not (ontable D)) (not (on D E)))
         (or (not (on D A)) (not (on D B)))
         (or (not (on D A)) (not (on D D)))
         (or (not (on D A)) (not (on D E)))
         (or (not (on D B)) (not (on D C)))
         (or (not (on D B)) (not (on D E)))
         (or (not (on D C)) (not (on D E)))

         (or (not (holding E)) (not (clear E)))
         (or (not (holding E)) (not (on A E)))
         (or (not (holding E)) (not (on B E)))
         (or (not (holding E)) (not (on C E)))
         (or (not (holding E)) (not (on D E)))
         (or (not (clear E)) (not (on A E)))
         (or (not (clear E)) (not (on B E)))
         (or (not (clear E)) (not (on C E)))
         (or (not (clear E)) (not (on D E)))
         (or (not (on A E)) (not (on B E)))
         (or (not (on A E)) (not (on C E)))
         (or (not (on A E)) (not (on D E)))
         (or (not (on B E)) (not (on C E)))
         (or (not (on B E)) (not (on D E)))
         (or (not (on C E)) (not (on D E)))

         (or (not (holding E)) (not (ontable E)))
         (or (not (holding E)) (not (on E A)))
         (or (not (holding E)) (not (on E B)))
         (or (not (holding E)) (not (on E C)))
         (or (not (holding E)) (not (on E D)))
         (or (not (ontable E)) (not (on E A)))
         (or (not (ontable E)) (not (on E B)))
         (or (not (ontable E)) (not (on E C)))
         (or (not (ontable E)) (not (on E D)))
         (or (not (on E A)) (not (on E B)))
         (or (not (on E A)) (not (on E C)))
         (or (not (on E A)) (not (on E D)))
         (or (not (on E B)) (not (on E C)))
         (or (not (on E B)) (not (on E D)))
         (or (not (on E C)) (not (on E D)))

         (or (not (on A B)) (not (on B A)))                                  ; cycles
         (or (not (on A C)) (not (on C A)))
         (or (not (on A D)) (not (on D A)))
         (or (not (on A E)) (not (on E A)))
         (or (not (on B C)) (not (on C B)))
         (or (not (on B D)) (not (on D B)))
         (or (not (on B E)) (not (on E B)))
         (or (not (on C D)) (not (on D C)))
         (or (not (on C E)) (not (on E C)))
         (or (not (on D E)) (not (on E D)))

         (or (not (on A B)) (not (on B C)) (not (on C A)))                   ; on(A,B) & on(B,C) => -on(C,A)
         (or (not (on A B)) (not (on B D)) (not (on D A)))                   ; on(A,B) & on(B,D) => -on(D,A)
         (or (not (on A B)) (not (on B E)) (not (on E A)))                   ; on(A,B) & on(B,E) => -on(E,A)
         (or (not (on A C)) (not (on C B)) (not (on B A)))                   ; on(A,C) & on(C,B) => -on(B,A)
         (or (not (on A C)) (not (on C D)) (not (on D A)))                   ; on(A,C) & on(C,D) => -on(D,A)
         (or (not (on A C)) (not (on C E)) (not (on E A)))                   ; on(A,C) & on(C,E) => -on(E,A)
         (or (not (on A D)) (not (on D B)) (not (on B A)))                   ; on(A,D) & on(D,B) => -on(B,A)
         (or (not (on A D)) (not (on D C)) (not (on C A)))                   ; on(A,D) & on(D,C) => -on(C,A)
         (or (not (on A D)) (not (on D E)) (not (on E A)))                   ; on(A,D) & on(D,E) => -on(E,A)
         (or (not (on A E)) (not (on E B)) (not (on B A)))                   ; on(A,E) & on(E,B) => -on(B,A)
         (or (not (on A E)) (not (on E C)) (not (on C A)))                   ; on(A,E) & on(E,C) => -on(C,A)
         (or (not (on A E)) (not (on E D)) (not (on D A)))                   ; on(A,E) & on(E,D) => -on(D,A)
         (or (not (on B C)) (not (on C D)) (not (on D B)))                   ; on(B,C) & on(C,D) => -on(D,B)
         (or (not (on B C)) (not (on C E)) (not (on E B)))                   ; on(B,C) & on(C,E) => -on(E,B)
         (or (not (on B D)) (not (on D C)) (not (on C B)))                   ; on(B,D) & on(D,C) => -on(C,B)
         (or (not (on B E)) (not (on E C)) (not (on C B)))                   ; on(B,E) & on(E,C) => -on(C,B)
         (or (not (on C D)) (not (on D E)) (not (on E C)))                   ; on(C,D) & on(D,E) => -on(E,C)
         (or (not (on C D)) (not (on D E)) (not (on E C)))                   ; on(C,E) & on(E,D) => -on(D,C)

         (or (not (on A B)) (not (on B C)) (not (on C D)) (not (on D A)))    ; on(A,B) & on(B,C) & on(C,D) => -on(D,A)
         (or (not (on A B)) (not (on B C)) (not (on C E)) (not (on E A)))    ; on(A,B) & on(B,C) & on(C,E) => -on(E,A)
         (or (not (on A B)) (not (on B D)) (not (on D C)) (not (on C A)))    ; on(A,B) & on(B,D) & on(D,C) => -on(C,A)
         (or (not (on A B)) (not (on B D)) (not (on D E)) (not (on E A)))    ; on(A,B) & on(B,D) & on(D,E) => -on(E,A)
         (or (not (on A B)) (not (on B E)) (not (on E C)) (not (on C A)))    ; on(A,B) & on(B,E) & on(E,C) => -on(C,A)
         (or (not (on A B)) (not (on B E)) (not (on E D)) (not (on D A)))    ; on(A,B) & on(B,E) & on(E,D) => -on(D,A)
	 (or (not (on A C)) (not (on C B)) (not (on B D)) (not (on D A)))    ; on(A,C) & on(C,B) & on(B,D) => -on(D,A)
         (or (not (on A C)) (not (on C B)) (not (on B E)) (not (on E A)))    ; on(A,C) & on(C,B) & on(B,E) => -on(E,A)
         (or (not (on A C)) (not (on C D)) (not (on D B)) (not (on B A)))    ; on(A,C) & on(C,D) & on(D,B) => -on(B,A)
         (or (not (on A C)) (not (on C D)) (not (on D E)) (not (on E A)))    ; on(A,C) & on(C,D) & on(D,E) => -on(E,A)
         (or (not (on A C)) (not (on C E)) (not (on E B)) (not (on B A)))    ; on(A,C) & on(C,E) & on(E,B) => -on(B,A)
         (or (not (on A C)) (not (on C E)) (not (on E D)) (not (on D A)))    ; on(A,C) & on(C,E) & on(E,D) => -on(D,A)
	 (or (not (on A D)) (not (on D B)) (not (on B C)) (not (on C A)))    ; on(A,D) & on(D,B) & on(B,C) => -on(C,A)
	 (or (not (on A D)) (not (on D B)) (not (on B E)) (not (on E A)))    ; on(A,D) & on(D,B) & on(B,E) => -on(E,A)
         (or (not (on A D)) (not (on D C)) (not (on C B)) (not (on B A)))    ; on(A,D) & on(D,C) & on(C,B) => -on(B,A)
         (or (not (on A D)) (not (on D C)) (not (on C E)) (not (on E A)))    ; on(A,D) & on(D,C) & on(C,E) => -on(E,A)
         (or (not (on A D)) (not (on D E)) (not (on E B)) (not (on B A)))    ; on(A,D) & on(D,E) & on(E,B) => -on(B,A)
         (or (not (on A D)) (not (on D E)) (not (on E C)) (not (on C A)))    ; on(A,D) & on(D,E) & on(E,C) => -on(C,A)
         (or (not (on A E)) (not (on E B)) (not (on B C)) (not (on C A)))    ; on(A,E) & on(E,B) & on(B,C) => -on(C,A)
         (or (not (on A E)) (not (on E B)) (not (on B D)) (not (on D A)))    ; on(A,E) & on(E,B) & on(B,D) => -on(D,A)
         (or (not (on A E)) (not (on E C)) (not (on C B)) (not (on B A)))    ; on(A,E) & on(E,C) & on(C,B) => -on(B,A)
         (or (not (on A E)) (not (on E C)) (not (on C D)) (not (on D A)))    ; on(A,E) & on(E,C) & on(C,D) => -on(D,A)
         (or (not (on A E)) (not (on E D)) (not (on D B)) (not (on B A)))    ; on(A,E) & on(E,D) & on(D,B) => -on(B,A)
         (or (not (on A E)) (not (on E D)) (not (on D C)) (not (on C A)))    ; on(A,E) & on(E,D) & on(D,C) => -on(C,A)

         (or (not (on A B)) (not (on B C)) (not (on C D)) (not (on D E)) (not (on E A)))
         (or (not (on A B)) (not (on B C)) (not (on C E)) (not (on E D)) (not (on D A)))
         (or (not (on A B)) (not (on B D)) (not (on D C)) (not (on C E)) (not (on E A)))
         (or (not (on A B)) (not (on B D)) (not (on D E)) (not (on E C)) (not (on C A)))
         (or (not (on A B)) (not (on B E)) (not (on E C)) (not (on C D)) (not (on D A)))
         (or (not (on A B)) (not (on B E)) (not (on E D)) (not (on D C)) (not (on C A)))
         (or (not (on A C)) (not (on C B)) (not (on B D)) (not (on D E)) (not (on E A)))
         (or (not (on A C)) (not (on C B)) (not (on B E)) (not (on E D)) (not (on D A)))
         (or (not (on A C)) (not (on C D)) (not (on D B)) (not (on B E)) (not (on E A)))
         (or (not (on A C)) (not (on C D)) (not (on D E)) (not (on E B)) (not (on B A)))
         (or (not (on A C)) (not (on C E)) (not (on E B)) (not (on B D)) (not (on D A)))
         (or (not (on A C)) (not (on C E)) (not (on E D)) (not (on D B)) (not (on B A)))
         (or (not (on A D)) (not (on D B)) (not (on B C)) (not (on C E)) (not (on E A)))
         (or (not (on A D)) (not (on D B)) (not (on B E)) (not (on E C)) (not (on C A)))
         (or (not (on A D)) (not (on D C)) (not (on C B)) (not (on B E)) (not (on E A)))
         (or (not (on A D)) (not (on D C)) (not (on C E)) (not (on E B)) (not (on B A)))
         (or (not (on A D)) (not (on D E)) (not (on E B)) (not (on B C)) (not (on C A)))
         (or (not (on A D)) (not (on D E)) (not (on E C)) (not (on C B)) (not (on B A)))
         (or (not (on A E)) (not (on E B)) (not (on B C)) (not (on C D)) (not (on D A)))
         (or (not (on A E)) (not (on E B)) (not (on B D)) (not (on D C)) (not (on C A)))
         (or (not (on A E)) (not (on E C)) (not (on C B)) (not (on B D)) (not (on D A)))
         (or (not (on A E)) (not (on E C)) (not (on C D)) (not (on D B)) (not (on B A)))
         (or (not (on A E)) (not (on E D)) (not (on D B)) (not (on B C)) (not (on C A)))
         (or (not (on A E)) (not (on E D)) (not (on D C)) (not (on C B)) (not (on B A)))



  )
  (:goal (and (ontable A) (on B A) (on C B) (on D C) (on E D)
  ))
)
