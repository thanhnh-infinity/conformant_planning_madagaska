/*
 * @ThanhNH
 */
#define MAX_LENGTH 10000
#define SMALL_LENGTH 100
#define NORMAL_LENGTH 100
#define NUMBER_OF_INISTATE_FROM_BELIEF_STATE 2
#define TIME_RODA 10000

/***DATA STRUCTURE***/
typedef struct _complexAtomList {
	atomlist* list[MAX_LENGTH];
	int* pos_neg[MAX_LENGTH];
	long length;
} complexAtomList;

typedef struct _negativeListAtom {
	atom list[MAX_LENGTH];
	long length;
} negativeListAtom;

typedef struct _originalInitAtomList {
	atom* list;
	int length;
} originalInitAtomList;

typedef struct _beliefStateStructure {
	originalInitAtomList* list[MAX_LENGTH];
	negativeListAtom* negativeList[MAX_LENGTH];
	int NUMBER_OF_INITIAL_SATE;
} beliefStateStructure;

typedef struct _OneOFCombinationObject {
	int NUMBER_OF_OBJECT;
	int operation; // 0 is disjunction, 1 is conjunction
	atom listAtom[SMALL_LENGTH];
} OneOfCombinationObject;

typedef struct _OneOFCombination {
	int NUMBER_OF_OBJECT;
	OneOfCombinationObject* listOneOfCombinationObject[NORMAL_LENGTH];
} OneOfCombination;

typedef struct _OneOFCombinationList {
	int NUMBER_OF_LIST;
	OneOfCombination* listOneOfCombination[NORMAL_LENGTH];
} OneOfCombinationList;

typedef struct _AllLiteralStructure {
	atom positiveList[MAX_LENGTH];
	int positiveLength;
	atom negativeList[MAX_LENGTH];
	int negativeLength;
} AllLiteralStructure;

//typedef enum { patom, natom, conj, disj, TRUE, FALSE } fmatype;
//                   1     2     3     4     5     6
typedef struct _FMAStructure {
	//atom positiveAtom[NORMAL_LENGTH];
	atom positiveAtom;
	//int number_positve_atom ;
	//atom negativeAtom[NORMAL_LENGTH];
	atom negativeAtom;
	//int number_negative_atom ;
	atom Conjunction[NORMAL_LENGTH];
	atom Disjunction[NORMAL_LENGTH];
	int number_conjunction_object;
	int number_disjunction_object;
	int fmatype;

} FMAStructure;

typedef struct _SecondFMAStructure {
	FMAStructure* fmaStructure;
	struct _SecondFMAStructure *next;
} SecondFMAStructure;

typedef struct _newAtom {
	atom atom;
	int pos_neg;
} newAtom;

typedef struct _SetOfLiteral {
	newAtom set_of_literal[NORMAL_LENGTH];
	int length;
} SetOfLiteral;

typedef struct _SetOfAction {
	int index_action[NORMAL_LENGTH];
	int length;
} SetOfAction;

typedef struct _EffectsStructure {
	newAtom* list_atom_per_each_effect[SMALL_LENGTH];
	int NUMBER_EFFECTS;
	int number_atom_per_each_effect[SMALL_LENGTH];
} EffectsStructure;

/**Object Of Data Structure **/
complexAtomList *oneOfAtomList;
complexAtomList *orAtomList;
complexAtomList *BeliefInitState;
negativeListAtom *negAtomList;
negativeListAtom *storeNegativeAtomList;
beliefStateStructure* beliefInitialState;
originalInitAtomList *preInit;
OneOfCombinationList *oneOfCombinationList;
AllLiteralStructure *allLiteral;
/** Flag **/
int runningOneOfCombine;
int runningReduceAction;
int displayAllAction;
int displayUsefulActionl;
int displayAllLiteral;
/************************************************/
atomlist *atomlist_combine(atomlist *, atomlist *);
atomlist *atomcons_thanhnh(atom, atomlist *);
SetOfLiteral *convert_atomlist_to_setOfLiteral(atomlist *);
SetOfLiteral *lit_of_literal(atomlist *);

