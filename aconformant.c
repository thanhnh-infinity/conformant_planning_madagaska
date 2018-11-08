/*
 * aconformant.c
 *
 *  Created on: Apr 2, 2014
 *      Author: ThanhNH
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

#include "asyntax.h"
#include "tables.h"
#include "intsets.h"
#include "ordintsets.h"
#include "operators.h"
#include "main.h"
#include "aconformant.h"
#include "parser.tab.h"

/************************************************/
/* Variables Private inside Conformant Planning */
/************************************************/
typedef struct _ConformantAction {
	action *allAction;
	action *usefulAction;
	newAtom* effAction[NORMAL_LENGTH];
	int number_Of_Atom_effAction[NORMAL_LENGTH];

	FMAStructure* precondition[NORMAL_LENGTH];
	SecondFMAStructure* ifCondition[NORMAL_LENGTH];
	EffectsStructure* effectAction[NORMAL_LENGTH];

	int NUMBER_ACTIONS;
	int NUMBER_USEFUL_ACTIONS;

	int add_useful_action_flag[NORMAL_LENGTH];

} ConformantAction;
ConformantAction *conformantAction;
SetOfAction *preact_of_literal(newAtom, ConformantAction *);
SetOfAction *get_preact_from_set_of_literal(atomlist *);
SetOfAction *preact_of_set_literal(SetOfLiteral *, ConformantAction *);
SetOfLiteral *deps_of_action(int, ConformantAction *, AllLiteralStructure *);
SetOfLiteral *deps_of_set_action(SetOfAction *, ConformantAction *,
		AllLiteralStructure *);

/************************************************/
/* Functions : Using to combine data structures */
/************************************************/
atomlist *atomcons_thanhnh(atom h, atomlist *t) {
	if (t == NULL) {
		t->hd = h;
		t->tl = NULL;
		return t;
	} else {
		atomlist *r = (atomlist *) malloc(sizeof(atomlist));
		r->hd = h;
		r->tl = t;
		return r;
	}
}

atomlist *atomlist_combine(atomlist *one, atomlist *two) {
	if (one == NULL && two == NULL) {
		return NULL;
	}
	if (one == NULL && two != NULL) {
		return two;
	}
	if (one != NULL && two == NULL) {
		return one;
	}
	if (one != NULL && two != NULL) {
		atomlist *r = (atomlist *) malloc(sizeof(atomlist));
		r = one;
		while (one->tl != NULL) {
			one = one->tl;
		}
		one->tl = two;
		return r;
	}
	return NULL;
}

void addAtomToOriginInitAtomList(atom atom,
		originalInitAtomList* originAtomList) {
	int length = originAtomList->length;
	originAtomList->list[length] = atom;
	originAtomList->length = length + 1;
}

void addAtomToNegativeAtomList(atom a) {
	if (a == NULL)
		return;
	if (negAtomList == NULL) {
		negAtomList = (negativeListAtom *) malloc(sizeof(negativeListAtom));
		negAtomList->length = 0;
		negAtomList->list[0] = a;
		negAtomList->length = negAtomList->length + 1;
	} else {
		long currentLength = negAtomList->length;
		negAtomList->list[currentLength] = a;
		currentLength = currentLength + 1;
		negAtomList->length = currentLength;
	}
}

/***************************************************************/
/* Functions : Using to save data from PDDL to data structures */
/***************************************************************/
void save_or(atomlist *a) {
	atomlist *g = a;
	if (orAtomList == NULL) {
		orAtomList = (complexAtomList *) malloc(sizeof(complexAtomList));
		orAtomList->list[0] = g;
		orAtomList->length = 1;
	} else {
		long currentLength = orAtomList->length;
		orAtomList->list[currentLength] = g;
		orAtomList->length = currentLength + 1;
	}

}
void save_not(atomlist *a) {
	atom atom = a->hd;
	if (negAtomList == NULL) {
		negAtomList = (negativeListAtom *) malloc(sizeof(negativeListAtom));
		negAtomList->length = 0;
		negAtomList->list[0] = atom;
		negAtomList->length = negAtomList->length + 1;

		storeNegativeAtomList = (negativeListAtom *) malloc(
				sizeof(negativeListAtom));
		storeNegativeAtomList->length = 0;
		storeNegativeAtomList->list[0] = atom;
		storeNegativeAtomList->length = storeNegativeAtomList->length + 1;
	} else {
		long currentLength = negAtomList->length;
		negAtomList->list[currentLength] = atom;
		currentLength = currentLength + 1;
		negAtomList->length = currentLength;

		currentLength = storeNegativeAtomList->length;
		storeNegativeAtomList->list[currentLength] = atom;
		currentLength = currentLength + 1;
		storeNegativeAtomList->length = currentLength;
	}
}

void save_one_of(atomlist *a) {
	atomlist *g = a;
	if (oneOfAtomList == NULL) {
		oneOfAtomList = (complexAtomList *) malloc(sizeof(complexAtomList));
		oneOfAtomList->list[0] = g;
		oneOfAtomList->length = 1;
	} else {
		long currentLength = oneOfAtomList->length;
		oneOfAtomList->list[currentLength] = g;
		oneOfAtomList->length = currentLength + 1;
	}
}

/*******************************************************/
/* Functions : Using to print data structures to debug */
/*******************************************************/
void print_complex_atom_list(complexAtomList *complex, char message[]) {
	if (complex == NULL) {
		printf("--Nothing in %s list", message);
		return;
	}
	long length = complex->length;
	long i = 0;
	for (i = 0; i < length; i++) {
		printf("\n-----View %s : %ld \n", message, i + 1);
		atomlist *al = (atomlist *) malloc(sizeof(atomlist));
		al = complex->list[i];
		while (al != NULL) {
			printatom(al->hd);
			al = al->tl;
		}
	}
}

void print_negative_atomlist(negativeListAtom *object) {
	long i = 0;
	if (object == NULL || object->length == 0) {
		printf("\n-- Nothing in negative atom list");
		return;
	}
	for (i = 0; i < object->length; i++) {
		printf("\n(not ");
		printatom(object->list[i]);
		printf(")");
	}
	printf("\n");
}

void print_negative_atomlist_for_testing(negativeListAtom *temp) {
	long i = 0;
	if (temp == NULL || temp->length == 0) {
		printf("\n-- Nothing in negative atom list");
		return;
	}
	for (i = 0; i < temp->length; i++) {
		printf("\n(not ");
		printatom(temp->list[i]);
		printf(")");
	}
	printf("\n");
}

void copyNegativeList(negativeListAtom *from, negativeListAtom *to) {
	long i = 0;
	if (from == NULL || from->length == 0) {
		printf("\n-- Nothing in negative atom list");
		return;
	}
	to->length = from->length;
	for (i = 0; i < from->length; i++) {
		to->list[i] = from->list[i];
	}
}

void print_negative_atomlist_in_final() {
	long i = 0;
	if (negAtomList == NULL || negAtomList->length == 0) {
		printf("\n-- Nothing in negative atom list");
		return;
	}
	for (i = 0; i < negAtomList->length; i++) {
		printf("\n(not ");
		printatom(negAtomList->list[i]);
		printf(")");
	}
	printf("\n");
}

void print_original_atom_list(originalInitAtomList *object) {
	int length = object->length;
	int i = 0;
	for (i = 0; i < length; i++) {
		printatom(object->list[i]);
	}
	printf("\n");
}

void print_one_of_combine_object(OneOfCombinationObject *oneOfCBObject) {
	int NUMBER_ATOM = oneOfCBObject->NUMBER_OF_OBJECT;
	int i = 0;
	for (i = 0; i < NUMBER_ATOM; i++) {
		if (i == 0) {
			printf(" [");
		}
		printatom(oneOfCBObject->listAtom[i]);
		if (i != NUMBER_ATOM - 1) {
			if (oneOfCBObject->operation == 1) {
				printf(" AND ");
			}
		} else {
			printf("],");
		}

	}
}

void print_one_of_combination_list(OneOfCombinationList *oneOfCBList) {
	if (oneOfCBList == NULL)
		return;

	int NUMBER_LIST = oneOfCBList->NUMBER_OF_LIST;
	int i = 0;
	printf("\n-------------------------------------------------");
	printf("\n------------LIST ONE-OF COMBINATION LIST---------");
	for (i = 0; i < NUMBER_LIST; i++) {
		printf("\n----ONE-OF COMBINATION %d  : ", i);
		print_one_of_combination(oneOfCBList->listOneOfCombination[i]);

	}
	printf("\n-------------------------------------------------\n");
}

void print_one_of_combination(OneOfCombination *oneOfCb) {
	int NUMBER_OBJECT = oneOfCb->NUMBER_OF_OBJECT;
	int i = 0;
	printf("\n  { ");
	for (i = 0; i < NUMBER_OBJECT; i++) {
		print_one_of_combine_object(oneOfCb->listOneOfCombinationObject[i]);
	}
	printf(" } ");
}
/*********************************************/
/* Functions : Using to create initial state */
/*********************************************/
void prepareOriginInit(atomlist *a) {
	int cnt, i;
	cnt = listlen(a);
	preInit = (originalInitAtomList *) malloc(sizeof(originalInitAtomList));
	preInit->list = (atom *) malloc((cnt + 1) * sizeof(atom));
	for (i = 0; i < cnt; i++) {
		preInit->list[i] = a->hd;
		a = a->tl;
	}
	preInit->list[cnt] = NULL;
	preInit->length = cnt;
}

void copyOriginInit(originalInitAtomList* from, originalInitAtomList *to) {
	if (from == NULL) {
		printf("\n---ThanhNH--Error : Original object is NULL");
		return;
	} else {
		int length = from->length;
		int i = 0;
		for (i = 0; i < length; i++) {
			to->list[i] = from->list[i];
		}
		to->length = from->length;
	}
}

/*******************************************************/
/* Functions : **Important Method** Create Belief State*/
/*******************************************************/
void settingsFlag() {
	runningOneOfCombine = 1;
	runningReduceAction = 1;
	displayAllAction = 0;
	displayUsefulActionl = 1;
	displayAllLiteral = 1;
}

void getInitState(atomlist *a) {
	/** Settings flag **/
	settingsFlag();
	/** End Setting Flag **/
	prepareOriginInit(a);

	printf("\n-----Danh sach cac ORIGINAL ATOMS in INIT STATE -----\n");
	while (a != NULL) {
		printatom(a->hd);
		a = a->tl;
	}
	printf("\n-----------------------------------------------------");
	printf("\n");

	printf("\n-----Danh sach cac ONE OF list va cac atom cua no----");
	complexAtomList *temp = oneOfAtomList;
	if (temp != NULL) {
		print_complex_atom_list(temp, "ONE-OF List");
	} else {
		printf("\n Nothing in ONE-OF");
	}
	printf("\n-----------------------------------------------------");
	printf("\n-----Danh sach cac OR list va cac atom cua no--------");
	temp = orAtomList;
	if (temp != NULL) {
		print_complex_atom_list(temp, "OR List");
	} else {
		printf("\n Nothing in OR");
	}
	printf("\n-----------------------------------------------------");
	printf("\n-----Danh sach cac NEGATIVE atom              -------");
	print_negative_atomlist_in_final();
	printf("\n-----------------------------------------------------");
	printf("\n");
	//runningConformantPlanning();
}

void runningConformantPlanning() {
	performCombineOriginalFactsAndOneOFAtom();
	printf("\n-------------------------------------------");
	if (oneOfAtomList == NULL) {
		printf("\n----Problem PDDL provide Completed State---");
		printf("\n----RUN ORIGINAL MADAGASKA-----------------");
		printf("\n");
		printf("\n-------------------------------------------");
	} else {
		if (oneOfAtomList != NULL) {
			setUpNewStructureOfLiterals();
			if (displayAllLiteral == 1) {
				print_all_atom_conformant();
			}
			if (runningReduceAction == 1) {
				runningReduceActions();
			}
			if (runningOneOfCombine == 1 && oneOfAtomList != NULL) {
				performOneOfCombine();
				print_one_of_combination_list(oneOfCombinationList);
				addMoreOneOfCombination_to_BeliefState(oneOfCombinationList);
			}
		}

		printf("\n----Problem PDDL provide Belief State---");
		printf("\n----RUN Conformant Planning-------------");
		storeFinalInit();
		printf("\n");
		printf("\n----------------------------------------");
	}
	printf("\n----------------------------------------");
	printf("\n");

}

void addMoreOneOfCombination_to_BeliefState() {
	if (oneOfCombinationList != NULL
			&& oneOfCombinationList->NUMBER_OF_LIST >= 0) {
		int h = 0;
		originalInitAtomList *finalInitState = (originalInitAtomList *) malloc(
				sizeof(originalInitAtomList));
		finalInitState->list = (atom *) malloc(
				(preInit->length + 1) * sizeof(atom));
		copyOriginInit(preInit, finalInitState);

		negAtomList = (negativeListAtom *) malloc(sizeof(negativeListAtom));
		negAtomList->length = 0;
		negAtomList = storeNegativeAtomList;
		for (h = 0; h < oneOfCombinationList->NUMBER_OF_LIST; h++) {
			OneOfCombination *oneOfCombine =
					oneOfCombinationList->listOneOfCombination[h];

			if (oneOfCombine == NULL || oneOfCombine->NUMBER_OF_OBJECT <= 0) {
				return;
			}

			int i = 0;
			for (i = 0; i < oneOfCombine->NUMBER_OF_OBJECT; i++) {
				if (i == 0) //Add to positive
						{
					OneOfCombinationObject *oneOfObject =
							oneOfCombine->listOneOfCombinationObject[i];
					if (oneOfObject == NULL
							|| oneOfObject->NUMBER_OF_OBJECT <= 0) {
						return;
					}
					int j = 0;
					for (j = 0; j < oneOfObject->NUMBER_OF_OBJECT; j++) {
						addAtomToOriginInitAtomList(oneOfObject->listAtom[j],
								finalInitState);
					}
				} else { //Add to negative
					OneOfCombinationObject *oneOfObject =
							oneOfCombine->listOneOfCombinationObject[i];
					if (oneOfObject == NULL
							|| oneOfObject->NUMBER_OF_OBJECT <= 0) {
						return;
					}
					int j = 0;
					for (j = 0; j < oneOfObject->NUMBER_OF_OBJECT; j++) {
						addAtomToNegativeAtomList(oneOfObject->listAtom[j]);
					}
				}
			}
			createBeliefState(finalInitState);
		}
		printf(
				"\n===Thu nghiem mot Init State sau khi da chay One-Of Combine : ");
		print_original_atom_list(beliefInitialState->list[2]);
		print_negative_atomlist(beliefInitialState->negativeList[2]);
	} else {
		return;
	}
}

void storeFinalInit() {
	atom *temp = beliefInitialState->list[0]->list;
	int cnt, i;
	cnt = beliefInitialState->list[0]->length;
	Sinit = (atom *) malloc((cnt + 1) * sizeof(atom));
	for (i = 0; i < cnt; i++) {
		Sinit[i] = temp[i];
	}
	Sinit[cnt] = NULL;
}

void printatomlist(atomlist *a) {
	while (a != NULL) {
		atom at = a->hd;
		printf("\n (");
		printatom(at);
		printf(")");
		a = a->tl;
	}
}

void performCombineOriginalFactsAndOneOFAtom() {
	complexAtomList *tempOneOfComplexList = oneOfAtomList;
	int checkConsistance_OneOf_Main = 0;
	int checkConsistance_OR_Main = 0;
	if (tempOneOfComplexList == NULL) {
		printf("No-thing in List of One-Of - Do nothing -");
	} else {
		int k = 0;
		/* Create temp state to store original initial state */
		originalInitAtomList* finalInitState;
		for (k = 0; k < NUMBER_OF_INISTATE_FROM_BELIEF_STATE; k++) {
			finalInitState = (originalInitAtomList *) malloc(
					sizeof(originalInitAtomList));
			finalInitState->list = (atom *) malloc(
					(preInit->length + 1) * sizeof(atom));
			copyOriginInit(preInit, finalInitState);

			/* Scann one of list - Each one of list pick one atom to Fact - All rest atom assigns to negative list */
			int i = 0;
			int numberOfOneOfList = tempOneOfComplexList->length;
			for (i = 0; i < numberOfOneOfList; i++) {
				atomlist* a = tempOneOfComplexList->list[i];
				atom atom;
				if (k == 0) {
					atom = a->hd;
				} else {
					int ran = rand() % NUMBER_OF_INISTATE_FROM_BELIEF_STATE;
					int index = 0;
					while (a != NULL) {
						if (index == ran) {
							atom = a->hd;
							break;
						} else {
							index = index + 1;
							a = a->tl;
						}
					}
					a = tempOneOfComplexList->list[i];
				}

				processTheRestAtomInOneOfList(atom, a);

				/* Check consistance */
				int checkConsistance_OneOf =
						checkConsistent_AnotherAtomInOneOF_WithOriginaList(atom,
								a, finalInitState);
				int checkConsistance_OneOf_2 =
						checkConsistent_PickedAtom_WithOriginalList(atom,
								finalInitState);
				/* End check */
				/** Cho nay la cai cho khong bao gio hieu noi **/
				negativeListAtom *tempNegAtomList = (negativeListAtom *) malloc(
						sizeof(negativeListAtom));
				tempNegAtomList->length = 0;
				copyNegativeList(negAtomList,tempNegAtomList);
				/** Cho nay la cai cho khong bao gio hieu noi **/

				if (checkConsistance_OneOf == 1
						&& checkConsistance_OneOf_2 == 0) {
					addAtomToOriginInitAtomList(atom, finalInitState);
					checkConsistance_OneOf_Main = 1;
					negAtomList = tempNegAtomList;
				} else {
					printf(
							"\n Cannot create possible initial state in belief State. Problem in in-consistant after combine with One-OF! \n");
					exit(1);
				}
			}

			int checkConsistent_ListOfOrs =
					checkConsistent_OriginalAtomList_With_ListOfOrs(
							finalInitState);

			if (checkConsistent_ListOfOrs == 1)
				checkConsistance_OR_Main = 1;

			if (checkConsistance_OR_Main == 1
					&& checkConsistance_OneOf_Main == 1) {
				printf(
						"\n ThanhNH: Create successful 1 initial state in Belief State");

				createBeliefState(finalInitState);
			}
			printf("\n");
			negAtomList = (negativeListAtom *) malloc(sizeof(negativeListAtom));
			negAtomList->length = 0;
			negAtomList = storeNegativeAtomList;
		}
		/* Test */
		printf("----Original Initial State ----\n");
		print_original_atom_list(preInit);
		printf("----Final Initial State---\n");

		k = beliefInitialState->NUMBER_OF_INITIAL_SATE;
		for (k = 0; k < NUMBER_OF_INISTATE_FROM_BELIEF_STATE; k++) {
			printf("-------Initial State %d : ", k + 1);
			print_original_atom_list(beliefInitialState->list[k]);
		}
		printf("----NEGATIVE Atom List-------\n");
		k = 0;
		for (k = 0; k < NUMBER_OF_INISTATE_FROM_BELIEF_STATE; k++) {
			printf("-------Equal Initial State %d : ", k + 1);
			print_negative_atomlist(beliefInitialState->negativeList[k]);
		}

		//print_all_belief_state();
	}
}

void print_all_belief_state() {
	printf("----Final Initial State---\n");
	int k = beliefInitialState->NUMBER_OF_INITIAL_SATE;
	for (k = 0; k < NUMBER_OF_INISTATE_FROM_BELIEF_STATE; k++) {
		printf("-------Initial State %d : ", k + 1);
		print_original_atom_list(beliefInitialState->list[k]);
	}
	printf("----NEGATIVE Atom List-------\n");
	k = 0;
	for (k = 0; k < NUMBER_OF_INISTATE_FROM_BELIEF_STATE; k++) {
		printf("-------Equal Initial State %d : ", k + 1);
		print_negative_atomlist(beliefInitialState->negativeList[k]);
	}
}

void createBeliefState(originalInitAtomList *object) {
	if (beliefInitialState == NULL) {
		beliefInitialState = (beliefStateStructure *) malloc(
				sizeof(beliefStateStructure));
		beliefInitialState->NUMBER_OF_INITIAL_SATE = 0;
		beliefInitialState->list[0] = object;
		beliefInitialState->negativeList[0] = negAtomList;
		beliefInitialState->NUMBER_OF_INITIAL_SATE = 1;
	} else {
		int currentLength = beliefInitialState->NUMBER_OF_INITIAL_SATE;
		beliefInitialState->list[currentLength] = object;
		beliefInitialState->negativeList[currentLength] = negAtomList;
		beliefInitialState->NUMBER_OF_INITIAL_SATE = currentLength + 1;
	}

}

void processTheRestAtomInOneOfList(atom pickedAtom, atomlist *oneOfTemp) {
	if (oneOfTemp == NULL) {
		return;
	}
	while (oneOfTemp != NULL) {
		atom atom = oneOfTemp->hd;
		if (atom == NULL)
			return;
		if (compareTowAtomList(atom, pickedAtom) == 1) {
			oneOfTemp = oneOfTemp->tl;
			continue;
		}

		int checkAtomInPossitive = 0;
		if (preInit == NULL || preInit->length == 0) {
			checkAtomInPossitive = 0;
		} else {
			checkAtomInPossitive = checkAtomInOriginalInitAtomList(atom,
					preInit);
		}
		int checkAtomInNegative = 0;
		if (negAtomList == NULL || negAtomList->length == 0) {
			checkAtomInNegative = 0;
		} else {
			checkAtomInNegative = checkAtomInNegativeWorld(atom);
		}
		if (checkAtomInPossitive == 0 && checkAtomInNegative == 0) {

			if (negAtomList == NULL) {
				negAtomList = (negativeListAtom *) malloc(
						sizeof(negativeListAtom));
				negAtomList->length = 0;
				negAtomList->list[0] = atom;
				negAtomList->length = 1;
			} else {
				long currentLength = negAtomList->length;
				negAtomList->list[currentLength] = atom;
				negAtomList->length = currentLength + 1;
			}

		}
		oneOfTemp = oneOfTemp->tl;
	}
}

/***********************************/
/* Functions : Checking consistency*/
/***********************************/
int checkConsistent_OriginalAtomList_With_ListOfOrs(
		originalInitAtomList* object) {
	if (orAtomList == NULL)
		return 1;
	complexAtomList *tempOrComplexList = orAtomList;
	int check = 0;
	int i = 0;
	int numberOfORList = tempOrComplexList->length;
	for (i = 0; i < numberOfORList; i++) {
		atomlist* checkAtomList = tempOrComplexList->list[i];
		check = checkEachOrListWithInitList(checkAtomList, object);
		/*
		 if (check == 1) {
		 return 1;
		 }
		 */
		if (check == 0) {
			return 0;
		}
	}
	return 1;
	//return 0;
}

int checkEachOrListWithInitList(atomlist *eachOrList,
		originalInitAtomList *object) {
	int check = 0;
	while (eachOrList) {
		atom checkAtom = eachOrList->hd;
		check = checkAtomInOriginalInitAtomList(checkAtom, object);
		if (check == 1) {
			return 1;
		}
		eachOrList = eachOrList->tl;
	}
	return 0;
}

int checkConsistent_AnotherAtomInOneOF_WithOriginaList(atom pickedAtom,
		atomlist *a, originalInitAtomList* original) {
	if (a == NULL) {
		return 1;
	}

	while (a != NULL) {
		atom b = a->hd;
		if (compareTowAtomList(pickedAtom, b) == 1) {
			a = a->tl;
			continue;
		}

		int checkAtomInNegative = checkAtomInNegativeWorld(b);
		int checkAtomInPositive = checkAtomInOriginalInitAtomList(b, original);
		if (checkAtomInNegative == 0 || checkAtomInPositive == 1) {
			return 0;
		}
		a = a->tl;
	}
	return 1;
}

int checkConsistent_PickedAtom_WithOriginalList(atom pickedAtom,
		originalInitAtomList* finalInit) {
	if (pickedAtom == NULL) {
		return 1;
	}
	int checkInPossitive = checkAtomInOriginalInitAtomList(pickedAtom,
			finalInit);
	int checkInNegative = checkAtomInNegativeWorld(pickedAtom);
	if (checkInPossitive == 0 && checkInNegative == 0) {
		return 0;
	} else {
		return 1;
	}
}

int compareTowAtomList(atom a, atom b) {
	if (a == NULL || b == NULL) {
		return -1;
	}
	if (a[0] == b[0] && a[1] == b[1]) {
		int i = 0;
		int n = a[1];
		for (i = 2; i < n + 2; i++) {
			if (a[i] != b[i]) {
				return 2;
			}
		}
		return 1;
	} else {
		return 0;
	}
}

int checkAtomInOriginalInitAtomList(atom a, originalInitAtomList* orginal) {
	int kt = 0;
	if (orginal == NULL) {
		return 0;
	}
	int length = orginal->length;
	int i = 0;
	int check = 0;
	for (i = 0; i < length; i++) {
		atom checkAtom = orginal->list[i];
		check = compareTowAtomList(a, checkAtom);
		if (check == 1) {
			return 1;
		}
	}
	return 0;
}

int checkAtomInNegativeWorld(atom a) {
	int i = 0;
	if (negAtomList == NULL || negAtomList->length == 0)
		return 0;
	for (i = 0; i < negAtomList->length; i++) {
		atom checkAtom = negAtomList->list[i];
		if (compareTowAtomList(a, checkAtom) == 1) {
			return 1;
		}
	}
	return 0;
}

/*******************************************************/
/* PART III : REDUCE ACTION AND ATOMS JOIN PLANS********/
/*******************************************************/

//CHECK TRONG EFFECTS :
// Duyet toan bo cac Literal trong tap All Atoms
// Neu co bat cu mot literal nao in Effects cua mot action a
// Dieu do co nghia la action a la possible useful
void initConformantAction() {
	conformantAction = (ConformantAction *) malloc(sizeof(ConformantAction));
	conformantAction->NUMBER_ACTIONS = nOfActions;
	conformantAction->allAction = actions;
	conformantAction->NUMBER_USEFUL_ACTIONS = 0;
}

void initConformantLiteral() {
	allLiteral = (AllLiteralStructure *) malloc(sizeof(AllLiteralStructure));
	allLiteral->negativeLength = 0;
	allLiteral->positiveLength = 0;
}

void addLiteralToAllLiteralList(atom a, int typeInsert, int pos_neg) {
	if (a == NULL) {
		return;
	}
	if (allLiteral == NULL) {
		allLiteral = (AllLiteralStructure *) malloc(
				sizeof(AllLiteralStructure));
		if (typeInsert == 1) { //Insert atom in Original Init to All Literals
			if (pos_neg == 1) {
				allLiteral->negativeLength = 0;
				allLiteral->positiveLength = 0;
				allLiteral->positiveList[0] = a;
				allLiteral->positiveLength = 1;
			} else if (pos_neg == -1) {
				allLiteral->negativeLength = 0;
				allLiteral->positiveLength = 0;
				allLiteral->negativeList[0] = a;
				allLiteral->negativeLength = 1;
			}
		} else if (typeInsert == 2) { //Insert atom in One-Of Structure to All Literals
			allLiteral->negativeLength = 0;
			allLiteral->positiveLength = 0;
			allLiteral->positiveList[0] = a;
			allLiteral->positiveLength = 1;
			allLiteral->negativeList[0] = a;
			allLiteral->negativeLength = 1;
		} else if (typeInsert == 3) { //Insert atom in OR Structure to All Literals
			if (pos_neg == 1) {
				allLiteral->negativeLength = 0;
				allLiteral->positiveLength = 0;
				allLiteral->positiveLength = 1;
				allLiteral->positiveList[0] = a;
			} else if (pos_neg == -1) {
				allLiteral->negativeLength = 0;
				allLiteral->positiveLength = 0;
				allLiteral->negativeLength = 1;
				allLiteral->negativeList[0] = a;
			}
		} else if (typeInsert == 4) {
			if (pos_neg == 1) {
				allLiteral->negativeLength = 0;
				allLiteral->positiveLength = 0;
				allLiteral->positiveList[0] = a;
				allLiteral->positiveLength = 1;
			} else if (pos_neg == -1) {
				allLiteral->negativeLength = 0;
				allLiteral->positiveLength = 0;
				allLiteral->negativeList[0] = a;
				allLiteral->negativeLength = 1;
			}
		}
	} else {
		if (typeInsert == 1) { //Insert atom in Original Init to All Literals
			if (pos_neg == 1) {
				int currentPositiveLength = allLiteral->positiveLength;
				allLiteral->positiveList[currentPositiveLength] = a;
				allLiteral->positiveLength = currentPositiveLength + 1;
			} else if (pos_neg == -1) {
				int currentNegativeLength = allLiteral->negativeLength;
				allLiteral->negativeList[currentNegativeLength] = a;
				allLiteral->negativeLength = currentNegativeLength + 1;
			}
		} else if (typeInsert == 2) {
			int currentPositiveLength = allLiteral->positiveLength;
			allLiteral->positiveList[currentPositiveLength] = a;
			allLiteral->positiveLength = currentPositiveLength + 1;
			int currentNegativeLength = allLiteral->negativeLength;
			allLiteral->negativeList[currentNegativeLength] = a;
			allLiteral->negativeLength = currentNegativeLength + 1;
		} else if (typeInsert == 3) { //Insert atom in OR Structure to All Literals
			if (pos_neg == 1) {
				int currentPositiveLength = allLiteral->positiveLength;
				allLiteral->positiveList[currentPositiveLength] = a;
				allLiteral->positiveLength = currentPositiveLength + 1;
			} else if (pos_neg == -1) {
				int currentNegativeLength = allLiteral->negativeLength;
				allLiteral->negativeList[currentNegativeLength] = a;
				allLiteral->negativeLength = currentNegativeLength + 1;
			}
		} else if (typeInsert == 4) {
			if (pos_neg == 1) {
				int currentPositiveLength = allLiteral->positiveLength;
				allLiteral->positiveList[currentPositiveLength] = a;
				allLiteral->positiveLength = currentPositiveLength + 1;
			} else if (pos_neg == -1) {
				int currentNegativeLength = allLiteral->negativeLength;
				allLiteral->negativeList[currentNegativeLength] = a;
				allLiteral->negativeLength = currentNegativeLength + 1;
			}
		}
	}
}

void setUpNewStructureOfLiterals() {
	int i = 0;
	printf("\n------------------------------------------------------");
	printf("\n---ThanhNH----Settings & List all literals------------");
	initConformantLiteral();
	printf("\n");
	/*
	 for (i = 0; i < nOfAtoms; i++) {
	 int *a = (int *) malloc(sizeof(int) * SMALL_LENGTH);
	 convert_from_atomi_atom(i, a);
	 addLiteralToAllLiteralList(a);
	 }
	 */
	if (preInit != NULL && preInit->length != 0) {
		addAtomsToAllLiteralStructures(1);
	}
	if (oneOfAtomList != NULL && oneOfAtomList->length != 0) {
		addAtomsToAllLiteralStructures(2);
	}
	if (orAtomList != NULL && orAtomList->length != 0) {
		addAtomsToAllLiteralStructures(3);
	}

}

void addAtomsToAllLiteralStructures(int type) {
	int i = 0;
	if (type == 1) { //Add All atoms in Original to All Literal Structures
		for (i = 0; i < preInit->length; i++) {
			addLiteralToAllLiteralList(preInit->list[i], 1, 1);
		}
	} else if (type == 2) { //Add all atoms in One-OF Structure to all Literal Structures
		complexAtomList *tempOneOfComplexList = oneOfAtomList;
		int numberOfOneOfList = tempOneOfComplexList->length;
		for (i = 0; i < numberOfOneOfList; i++) {
			atomlist* a = tempOneOfComplexList->list[i];
			atom atom;
			while (a != NULL) {
				atom = a->hd;
				addLiteralToAllLiteralList(atom, 2, 1);
				a = a->tl;
			}
		}
	} else if (type == 3) {
		complexAtomList *tempOrComplexList = orAtomList;
		int numberOfOrList = tempOrComplexList->length;
		for (i = 0; i < numberOfOrList; i++) {
			atomlist* a = tempOrComplexList->list[i];
			//int* pos_neg = tempOrComplexList->pos_neg[i];
			atom atom;
			while (a != NULL) {
				atom = a->hd;
				addLiteralToAllLiteralList(atom, 3, 1);
				a = a->tl;
			}
		}
	} else {
		return;
	}
}

void print_all_atom_conformant() {
	int i = 0;
	printf("\n---All positive literals : ");
	for (i = 0; i < allLiteral->positiveLength; i++) {
		printatom(allLiteral->positiveList[i]);
	}
	printf("\n---All negative literals : ");
	for (i = 0; i < allLiteral->negativeLength; i++) {
		printf("-");
		printatom(allLiteral->negativeList[i]);
	}
	printf("\n------------------------------------------------------");
	printf("\n");
}

void convert_from_atomi_atom(int index, int *ato) {
	intlist *a = atomtable[index];
	if (index < 0) {
		printf("----Error----1");
		return;
	}
	if (index >= nOfAtoms) {
		printf("----Error----2");
		return;
	}
	if (a == NULL) {
		fprintf(stderr, "INTERNAL ERROR: symbol table 1244\n");
		return;
	}
	ato[0] = a->hd;
	ato[1] = 0;
	a = a->tl;
	int len = 2;
	while (a != NULL) {
		ato[len] = a->hd;
		len++;
		a = a->tl;
	}
	ato[1] = len - 2;
}

void setUpConformantAction() {
	int i = 0;
	if (conformantAction == NULL)
		initConformantAction();

	for (i = 0; i < conformantAction->NUMBER_ACTIONS; i++) {
		action tempAction = conformantAction->allAction[i];
		eff *effectPointer = &(tempAction.effects);
		fma *preCondition = tempAction.precon;

		int j = 0;
		newAtom* listAtom_Effects = (newAtom *) malloc(sizeof(newAtom));
		listAtom_Effects->pos_neg = 0;
		newAtom* small_listAtom_Effects;
		FMAStructure *fmaStructure = (FMAStructure *) malloc(
				sizeof(FMAStructure));
		fmaStructure->number_conjunction_object = 0;
		fmaStructure->number_disjunction_object = 0;

		/* Build Atom List of Effects */
		while (effectPointer != NULL) {
			small_listAtom_Effects = (newAtom *) malloc(sizeof(newAtom));
			small_listAtom_Effects->pos_neg = 0;
			int k = 0;
			int *effects = effectPointer->effectlits;
			fma *preConditionOfEffect = effectPointer->condition;
			FMAStructure *fmaSmall = (FMAStructure *) malloc(
					sizeof(FMAStructure));
			fmaSmall->number_conjunction_object = 0;
			fmaSmall->number_disjunction_object = 0;
			while (*effects != -1) {
				int *a = (int *) malloc(sizeof(int) * SMALL_LENGTH);
				convert_from_atomi_atom(feVAR(*effects), a);
				listAtom_Effects[j].atom = a;
				if ((*effects) & 1) {
					small_listAtom_Effects[k].atom = a;
					small_listAtom_Effects[k].pos_neg = -1;
					listAtom_Effects[j].pos_neg = -1;
				} else {
					small_listAtom_Effects[k].atom = a;
					small_listAtom_Effects[k].pos_neg = 1;
					listAtom_Effects[j].pos_neg = 1;
				}
				j++;
				k++;
				effects = effects + 1;
			}

			if (conformantAction->effectAction[i] == NULL) {
				conformantAction->effectAction[i] = (EffectsStructure *) malloc(
						sizeof(EffectsStructure));
				conformantAction->effectAction[i]->NUMBER_EFFECTS = 1;
				conformantAction->effectAction[i]->list_atom_per_each_effect[0] =
						small_listAtom_Effects;
				conformantAction->effectAction[i]->number_atom_per_each_effect[0] =
						k;
			} else {
				int currentLength =
						conformantAction->effectAction[i]->NUMBER_EFFECTS;
				conformantAction->effectAction[i]->list_atom_per_each_effect[currentLength] =
						small_listAtom_Effects;
				conformantAction->effectAction[i]->number_atom_per_each_effect[currentLength] =
						k;
				conformantAction->effectAction[i]->NUMBER_EFFECTS =
						currentLength + 1;
			}

			/* Build Atom List of Precondition of Effects*/
			if (preConditionOfEffect != NULL) {
				int *a = (int *) malloc(sizeof(int) * SMALL_LENGTH);
				switch (preConditionOfEffect->t) {
				case patom:
					convert_from_atomi_atom(preConditionOfEffect->a, a);
					addPATOMToFMAStrucutre(fmaSmall, a);
					break;
				case natom:
					convert_from_atomi_atom(preConditionOfEffect->a, a);
					addNATOMToFMAStrucutre(fmaSmall, a);
					break;
				case conj:
					addConjuctionsObjectToFMAStructure(fmaSmall,
							preConditionOfEffect->juncts);
					break;
				case disj:
					addDisjunctionObjectToFMAStructure(fmaSmall,
							preConditionOfEffect->juncts);
					break;
				case TRUE:
					addFMAType(fmaSmall, 5);
					break;
				case FALSE:
					addFMAType(fmaSmall, 6);
					break;
				}
			}

			if (conformantAction->ifCondition[i] == NULL) {
				conformantAction->ifCondition[i] =
						(SecondFMAStructure *) malloc(
								sizeof(SecondFMAStructure));
				conformantAction->ifCondition[i]->fmaStructure = fmaSmall;
				conformantAction->ifCondition[i]->next = NULL;
			} else {
				SecondFMAStructure *temp = (SecondFMAStructure *) malloc(
						sizeof(SecondFMAStructure));
				temp->fmaStructure = fmaSmall;
				/*
				 temp->next = conformantAction->ifCondition[i];
				 conformantAction->ifCondition[i] = temp;
				 */
				temp->next = NULL;
				SecondFMAStructure *move = conformantAction->ifCondition[i];
				while (move->next != NULL) {
					move = move->next;
				}
				move->next = temp;
			}

			effectPointer = effectPointer->tl;
		}
		conformantAction->number_Of_Atom_effAction[i] = j;
		conformantAction->effAction[i] = listAtom_Effects;

		/* Build Atom List of Precondition */
		int *a = (int *) malloc(sizeof(int) * SMALL_LENGTH);
		switch (preCondition->t) {
		case patom:
			convert_from_atomi_atom(preCondition->a, a);
			addPATOMToFMAStrucutre(fmaStructure, a);
			break;
		case natom:
			convert_from_atomi_atom(preCondition->a, a);
			addNATOMToFMAStrucutre(fmaStructure, a);
			break;
		case conj:
			addConjuctionsObjectToFMAStructure(fmaStructure,
					preCondition->juncts);
			break;
		case disj:
			addDisjunctionObjectToFMAStructure(fmaStructure,
					preCondition->juncts);
			break;
		case TRUE:
			addFMAType(fmaStructure, 5);
			break;
		case FALSE:
			addFMAType(fmaStructure, 6);
			break;
		}

		conformantAction->precondition[i] = fmaStructure;

		/* Set Flag to create useful action is 0 */
		conformantAction->add_useful_action_flag[i] = 0;
	}

}

void addConjuctionsObjectToFMAStructure(FMAStructure *fmaStructure, fmalist *l) {
	while (l != NULL) {
		int *a = (int *) malloc(sizeof(int) * SMALL_LENGTH);
		convert_from_atomi_atom(l->hd->a, a);

		if (fmaStructure == NULL) {
			fmaStructure = (FMAStructure *) malloc(sizeof(FMAStructure));
			fmaStructure->number_conjunction_object = 0;
			fmaStructure->number_disjunction_object = 0;
			fmaStructure->fmatype = 3;
			fmaStructure->number_conjunction_object = 1;
			fmaStructure->Conjunction[0] = a;
		} else {
			int currentLength = fmaStructure->number_conjunction_object;
			fmaStructure->Conjunction[currentLength] = a;
			fmaStructure->number_conjunction_object = currentLength + 1;
			fmaStructure->fmatype = 3;
		}
		l = l->tl;
	}

}

void addDisjunctionObjectToFMAStructure(FMAStructure *fmaStructure, fmalist *l) {
	while (l != NULL) {
		int *a = (int *) malloc(sizeof(int) * SMALL_LENGTH);
		convert_from_atomi_atom(l->hd->a, a);
		if (fmaStructure == NULL) {
			fmaStructure = (FMAStructure *) malloc(sizeof(FMAStructure));
			fmaStructure->number_conjunction_object = 0;
			fmaStructure->number_disjunction_object = 0;
			fmaStructure->fmatype = 4;
			fmaStructure->number_disjunction_object = 1;
			fmaStructure->Disjunction[0] = a;
		} else {
			int currentLength = fmaStructure->number_disjunction_object;
			fmaStructure->Disjunction[currentLength] = a;
			fmaStructure->number_disjunction_object = currentLength + 1;
			fmaStructure->fmatype = 4;
		}
		l = l->tl;
	}
}

void addFMAType(FMAStructure *fmaStructure, int index) {
	if (index != 1 && index != 2 && index != 3 && index != 4 && index != 5
			&& index != 6) {
		return;
	}
	if (fmaStructure == NULL) {
		fmaStructure = (FMAStructure *) malloc(sizeof(FMAStructure));
		fmaStructure->number_conjunction_object = 0;
		fmaStructure->number_disjunction_object = 0;
		fmaStructure->fmatype = index;
	} else {
		fmaStructure->fmatype = index;
	}
}

void addPATOMToFMAStrucutre(FMAStructure *fmaStructure, atom a) {
	if (a == NULL)
		return;
	if (fmaStructure == NULL) {
		fmaStructure = (FMAStructure *) malloc(sizeof(FMAStructure));
		fmaStructure->number_conjunction_object = 0;
		fmaStructure->number_disjunction_object = 0;
		fmaStructure->fmatype = 1;
		fmaStructure->positiveAtom = a;
	} else {
		fmaStructure->fmatype = 1;
		fmaStructure->positiveAtom = a;
	}
}

void addNATOMToFMAStrucutre(FMAStructure *fmaStructure, atom a) {
	if (a == NULL)
		return;
	if (fmaStructure == NULL) {
		fmaStructure = (FMAStructure *) malloc(sizeof(FMAStructure));
		fmaStructure->number_conjunction_object = 0;
		fmaStructure->number_disjunction_object = 0;
		fmaStructure->fmatype = 2;
		fmaStructure->negativeAtom = a;
	} else {
		fmaStructure->fmatype = 2;
		fmaStructure->negativeAtom = a;
	}
}

void print_all_action_conformant_action(ConformantAction *cAction) {
	int i = 0;
	printf("\n");
	for (i = 0; i < cAction->NUMBER_ACTIONS; i++) {
		printaction_thanhnh(i, 0);
	}
}

void print_useful_action_conformant_action(ConformantAction *cAction) {
	int i = 0;
	printf("\n");
	for (i = 0; i < cAction->NUMBER_ACTIONS; i++) {
		if (cAction->add_useful_action_flag[i] == 1) {
			printaction_thanhnh(i, 0);
		}
	}
}

void printeff_thanhnh(eff *e) {
	fma *c;
	int *ls;
	if (e == NULL)
		return;
	c = e->condition;
	ls = e->effectlits;

	printf(" CAUSES {");
	while (*ls != -1) {
		printf(" ");
		if ((*ls) & 1) {
			printf("(not ");
			printatomi(feVAR(*ls));
			printf(")");
		} else {
			printatomi(feVAR(*ls));
		}
		ls = ls + 1;
	}
	printf("}");

	printf(" IF {");
	if (c->t != TRUE) {
		printfma(c);
	}
	if (c->t != TRUE)
		printf(")");
	printf(" } ; ");

	printeff_thanhnh(e->tl);
}

void printaction_thanhnh(int i, int message) {
	action testAction;
	if (message == 1)
		testAction = conformantAction->usefulAction[i];
	else
		testAction = conformantAction->allAction[i];

	int *l;
	/* Print operator name action(p1,...,pn) */
	l = testAction.name;
	printf("ACTION %i:%s(", i, symbol(*l));
	l = l + 1;
	while (*l != -1) {
		printf("%s", symbol(*l));
		if (*(l + 1) != -1)
			printf(",");
		l = l + 1;
	}
	printf(")  USEFUL %d \n", conformantAction->add_useful_action_flag[i]);
	/* Print precondition */
	printf("------Preconditions : ");
	printfma(testAction.precon);
	printf("\n");
	/* Print effect */
	printf("------Effects : ");
	printeff_thanhnh(&(testAction.effects));
	printf("\n");
}

void print_action_precondition_of_action_if_condition_per_effect_and_effect(
		int index) {
	action tempAction = conformantAction->allAction[index];
	printf("\n--------------------------------------------\n");
	printaction_thanhnh(index, 2);
	FMAStructure *fmaStructure = conformantAction->precondition[index];
	printf("\n-----PRE-CONDITION OF ACTION-----");
	if (fmaStructure->fmatype == 1) {
		printf("\n Chi co PATOM : ");
		printatom(fmaStructure->positiveAtom);
	} else if (fmaStructure->fmatype == 2) {
		printf("\n Chi co NATOM : ");
		printatom(fmaStructure->negativeAtom);
	} else if (fmaStructure->fmatype == 3) {
		printf("\n Conjunctions : ");
		int i = 0;
		for (i = 0; i < fmaStructure->number_conjunction_object; i++) {
			printatom(fmaStructure->Conjunction[i]);
			printf(" ");
		}

	} else if (fmaStructure->fmatype == 4) {
		printf("\n Disjunction : ");
		int i = 0;
		for (i = 0; i < fmaStructure->number_disjunction_object; i++) {
			printatom(fmaStructure->Disjunction[i]);
			printf(" ");
		}
	} else if (fmaStructure->fmatype == 5) {
		printf("\n Co the chay tren moi STATE : ");
	} else {
		printf("\n KHONG THE CHAY: ");
	}
	printf("\n============================");
	/* Print IF Condition */
	printf("\n=======IF CONDITION=========");
	SecondFMAStructure* tempSecondDMA = conformantAction->ifCondition[index];
	printf("\n IF of ACTIONS %d : ", index);
	while (tempSecondDMA != NULL) {
		FMAStructure *FMASmall = tempSecondDMA->fmaStructure;
		printf("\n=======================");
		if (FMASmall->fmatype == 1) {
			printf("\n PATOM : ");
			printatom(FMASmall->positiveAtom);
		} else if (FMASmall->fmatype == 2) {
			printf("\n NATOM : ");
			printatom(FMASmall->negativeAtom);
		} else if (FMASmall->fmatype == 3) {
			printf("\n Conj : ");
			int i = 0;
			for (i = 0; i < FMASmall->number_conjunction_object; i++) {
				printatom(FMASmall->Conjunction[i]);
				printf(" ");
			}

		} else if (FMASmall->fmatype == 4) {
			printf("\n Disj : ");
			int i = 0;
			for (i = 0; i < FMASmall->number_disjunction_object; i++) {
				printatom(FMASmall->Disjunction[i]);
				printf(" ");
			}
		} else if (FMASmall->fmatype == 5) {
			printf("\n Co the chay tren moi STATE : ");
		} else {
			printf("\n KHONG THE CHAY: ");
		}
		tempSecondDMA = tempSecondDMA->next;
	}
	printf("\n=============================");
	/* Print Effect */
	printf("\n=======CAC EFFECTS TUONG UNG=");
	printf("\n===Effect %d : ", index);
	EffectsStructure *effect = conformantAction->effectAction[index];
	int i = 0;
	for (i = 0; i < effect->NUMBER_EFFECTS; i++) {
		printf("\n====Small effect %d : ", i);
		newAtom *lstObject = effect->list_atom_per_each_effect[i];
		int j = 0;
		for (j = 0; j < effect->number_atom_per_each_effect[i]; j++) {
			newAtom object = lstObject[j];
			printf(" ");
			if (object.pos_neg == 1) {
				printatom(object);
			} else {
				printf("-");
				printatom(object);
			}
		}
	}
	printf("\n");

}

void runningReduceActions() {
	printf("\n------------------------------------------------------");
	printf("\n---ThanhNH----Running Reduce Actions and Literals-----");
	initConformantAction();
	printf("\n---Co %d action-----", conformantAction->NUMBER_ACTIONS);
	printf("\n---Danh sach tat ca cac action-----");

	setUpConformantAction();
	int i = 0;
	if (displayAllAction == 1) {
		for (i = 0; i < conformantAction->NUMBER_ACTIONS; i++) {
			print_action_precondition_of_action_if_condition_per_effect_and_effect(
					i);
		}
	}

	int old_pos = 0, old_neg = 0, new_pos = 1, new_neg = 1;
	int count = 0;
	while ((old_pos != new_pos) || (old_neg != new_neg)) {
		old_pos = allLiteral->positiveLength;
		old_neg = allLiteral->negativeLength;
		/* Core Logic */
		for (i = 0; i < conformantAction->NUMBER_ACTIONS; i++) {
			if (check_useful_action(i) == 1
					&& conformantAction->add_useful_action_flag[i] == 0) {
				/* Add action to useful action */
				if (conformantAction->usefulAction == NULL) {
					conformantAction->usefulAction = (action *) malloc(
							sizeof(action) * NORMAL_LENGTH);
					conformantAction->usefulAction[0] =
							conformantAction->allAction[i];
					conformantAction->NUMBER_USEFUL_ACTIONS = 1;
				} else {
					int currentIndex = conformantAction->NUMBER_USEFUL_ACTIONS;
					conformantAction->usefulAction[currentIndex] =
							conformantAction->allAction[i];
					conformantAction->NUMBER_USEFUL_ACTIONS = currentIndex + 1;
				}
				conformantAction->add_useful_action_flag[i] = 1;
				/* Add effects of this action to I_0 */
				/* Su dung cai nay trong truong hop xet den cac IF PRECONDITION cua moi effects */
				// EffectsStructure *effect = conformantAction->effectAction[i];
				printf("\n=====Xac dinh useful action %d======", i);
				print_action_precondition_of_action_if_condition_per_effect_and_effect(
						i);
				newAtom* effect = conformantAction->effAction[i];
				int number_of_atom =
						conformantAction->number_Of_Atom_effAction[i];
				int j = 0;
				for (j = 0; j < number_of_atom; j++) {
					if (effect[j].pos_neg == 1) {
						if (check_Atom_In_AllLiteral_2(effect[j].atom, 1)
								== 1) {
							continue;
						} else {
							addLiteralToAllLiteralList(effect[j].atom, 4, 1);
						}
					} else {
						if (check_Atom_In_AllLiteral_2(effect[j].atom, -1)
								== 1) {
							continue;
						} else {
							addLiteralToAllLiteralList(effect[j].atom, 4, -1);
						}
					}
				}

				/* Testing */
				print_all_atom_conformant();

			}
		}
		new_pos = allLiteral->positiveLength;
		new_neg = allLiteral->negativeLength;
		/* Core Logic */
		count++;
		printf(
				"\n===THANHNH====Loop %d===Check I_i and I_(i-1) : [%d %d] [%d %d] ",
				count, old_pos, new_pos, old_neg, new_neg);
	}

	printf("\n------------------------------------------------------");
	printf("\n---After REDUCE : There are %d USEFUL actions",
			conformantAction->NUMBER_USEFUL_ACTIONS);
	printf("\n------------------------------------------------------");
	if (displayUsefulActionl == 1) {
		print_useful_action_conformant_action(conformantAction);
	}
	printf("\n");

	/* Set up Running */
	actions = conformantAction->usefulAction;
}

int isExecutable_Precondition(int i, FMAStructure *condition) {
	if (condition->fmatype == 1) {
		atom patom = condition->positiveAtom;
		if (check_Atom_In_AllLiteral_2(patom, 1) == 1) {
			return 1;
		} else {
			return 0;
		}
	} else if (condition->fmatype == 2) {
		atom natom = condition->negativeAtom;
		if (check_Atom_In_AllLiteral_2(natom, -1) == 1) {
			return 1;
		} else {
			return 0;
		}
	} else if (condition->fmatype == 3) {
		int i = 0;
		for (i = 0; i < condition->number_conjunction_object; i++) {
			atom a = condition->Conjunction[i];
			if (check_Atom_In_AllLiteral_2(a, 1) == 0) {
				return 0;
			}
		}
		return 1;
	} else if (condition->fmatype == 4) {
		int i = 0;
		for (i = 0; i < condition->number_disjunction_object; i++) {
			atom a = condition->Disjunction[i];
			if (check_Atom_In_AllLiteral_2(a, 1) == 1) {
				return 1;
			}
		}
		return 0;
	} else if (condition->fmatype == 5) {
		return 1;
	} else if (condition->fmatype == 6) {
		return 0;
	}

	return 0;
}

int check_Atom_In_AllLiteral_2(atom a, int pos_neg) {
	int i = 0;
	if (allLiteral == NULL
			|| (allLiteral->positiveLength == 0
					&& allLiteral->negativeLength == 0))
		return 0;
	if (pos_neg == 1) {
		for (i = 0; i < allLiteral->positiveLength; i++) {
			atom checkAtom = allLiteral->positiveList[i];
			if (compareTowAtomList(a, checkAtom) == 1) {
				return 1;
			}
		}
	} else {
		for (i = 0; i < allLiteral->negativeLength; i++) {
			atom checkAtom = allLiteral->negativeList[i];
			if (compareTowAtomList(a, checkAtom) == 1) {
				return 1;
			}
		}
	}
	return 0;
}

int check_Atom_In_AllLiteral(atom a) {
	int i = 0;
	if (allLiteral == NULL
			|| (allLiteral->positiveLength == 0
					&& allLiteral->negativeLength == 0))
		return 0;
	for (i = 0; i < allLiteral->positiveLength; i++) {
		atom checkAtom = allLiteral->positiveList[i];
		if (compareTowAtomList(a, checkAtom) == 1) {
			return 1;
		}
	}

	for (i = 0; i < allLiteral->negativeLength; i++) {
		atom checkAtom = allLiteral->negativeList[i];
		if (compareTowAtomList(a, checkAtom) == 1) {
			return 1;
		}
	}
	return 0;
}

int check_useful_action(int index) {
	if (conformantAction == NULL) {
		return -1;
	}
	FMAStructure *pre_condition = conformantAction->precondition[index];
	int checkIsExecutable = isExecutable_Precondition(index, pre_condition);
	if (checkIsExecutable == 1) {
		return 1;
	} else {
		return 0;
	}
}

void restartInitialState() {
	atom *al;
	int i = 0;
	int j = 0;
	al = Sinit;
	while (*al != NULL) {
		atomindex(*al, NULL);
		al = al + 1;
	}

	initialstate = (int *) malloc(sizeof(int) * nOfAtoms);
	for (i = 0; i < nOfAtoms; i++)
		initialstate[i] = 0;

	al = Sinit;
	while (*al != NULL) {
		j = atomindex(*al, NULL);
		initialstate[j] = 1;

#ifdef ASSERTS
		assert(j>=0); assert(j<nOfAtoms);
#endif

		al = al + 1;
	}
}
/*******************************************************/
/* PART IV : REDUCE ONE-OF CLAUSES**********************/
/*******************************************************/
void initOneOfCombination() {
	oneOfCombinationList = (OneOfCombinationList *) malloc(
			sizeof(OneOfCombinationList));
	oneOfCombinationList->NUMBER_OF_LIST = 0;
}

void addOneOfCbObjectToOneOfCombine(OneOfCombination *oneOfCbCom,
		OneOfCombinationObject *oneOfCbObj) {
	if (oneOfCbObj == NULL) {
		return;
	}
	if (oneOfCbCom == NULL) {
		oneOfCbCom = (OneOfCombination *) malloc(sizeof(OneOfCombination));
		oneOfCbCom->NUMBER_OF_OBJECT = 1;
		oneOfCbCom->listOneOfCombinationObject[0] = oneOfCbObj;
	} else {
		int currentLength = oneOfCbCom->NUMBER_OF_OBJECT;
		oneOfCbCom->listOneOfCombinationObject[currentLength] = oneOfCbObj;
		oneOfCbCom->NUMBER_OF_OBJECT = currentLength + 1;
	}
}

void addOneOfCbComToOneOfCombineList(OneOfCombinationList *oneOfCBList,
		OneOfCombination *oneOfCbCom) {
	if (oneOfCbCom == NULL) {
		return;
	}
	if (oneOfCBList == NULL) {
		oneOfCBList = (OneOfCombinationList *) malloc(
				sizeof(OneOfCombinationList));
		oneOfCBList->NUMBER_OF_LIST = 1;
		oneOfCBList->listOneOfCombination[0] = oneOfCbCom;
	} else {
		int currentLength = oneOfCBList->NUMBER_OF_LIST;
		oneOfCBList->listOneOfCombination[currentLength] = oneOfCbCom;
		oneOfCBList->NUMBER_OF_LIST = currentLength + 1;
	}

}

void performOneOfCombine() {
	printf("\n-----------------------------------------------");
	printf("\n---ThanhNH---Start Running : One Of Combination");
	complexAtomList* tempOneOFAtomList = oneOfAtomList;
	int i = 0;
	int length = tempOneOFAtomList->length;
	OneOfCombinationObject *oneOfCbObj = (OneOfCombinationObject *) malloc(
			sizeof(OneOfCombinationObject));
	OneOfCombination *oneOfCbCom;
	while (i < length) {
		atomlist *a = tempOneOFAtomList->list[i];
		atomlist *b = tempOneOFAtomList->list[i + 1];
		if (checkOneOFCombinable(a, b) == 1) {
			printf("\n---ThanhNH---Check %d : Can be Combined", i);
			if (oneOfCombinationList == NULL) {
				initOneOfCombination();
			}
			int countA = count_element_atomlist(a);
			int countB = count_element_atomlist(b);
			oneOfCbCom = (OneOfCombination *) malloc(sizeof(OneOfCombination));
			if (countA == countB) {
				while (a != NULL && b != NULL) {
					atom aa = a->hd;
					atom bb = b->hd;
					oneOfCbObj = (OneOfCombinationObject *) malloc(
							sizeof(OneOfCombinationObject));
					oneOfCbObj->NUMBER_OF_OBJECT = 2;
					oneOfCbObj->listAtom[0] = aa;
					oneOfCbObj->listAtom[1] = bb;
					oneOfCbObj->operation = 1;
					a = a->tl;
					b = b->tl;
					addOneOfCbObjectToOneOfCombine(oneOfCbCom, oneOfCbObj);
				}
			} else if (countA > countB) {
				while (b != NULL) {
					atom aa = a->hd;
					atom bb = b->hd;
					oneOfCbObj = (OneOfCombinationObject *) malloc(
							sizeof(OneOfCombinationObject));
					oneOfCbObj->NUMBER_OF_OBJECT = 2;
					oneOfCbObj->listAtom[0] = aa;
					oneOfCbObj->listAtom[1] = bb;
					oneOfCbObj->operation = 1;
					a = a->tl;
					b = b->tl;
					addOneOfCbObjectToOneOfCombine(oneOfCbCom, oneOfCbObj);
				}
				b = tempOneOFAtomList->list[i + 1];
				atom bb = b->hd;
				while (a != NULL) {
					atom aa = a->hd;
					oneOfCbObj = (OneOfCombinationObject *) malloc(
							sizeof(OneOfCombinationObject));
					oneOfCbObj->NUMBER_OF_OBJECT = 2;
					oneOfCbObj->listAtom[0] = aa;
					oneOfCbObj->listAtom[1] = bb;
					oneOfCbObj->operation = 1;
					a = a->tl;
					addOneOfCbObjectToOneOfCombine(oneOfCbCom, oneOfCbObj);
				}
			} else if (countA < countB) {
				while (a != NULL) {
					atom aa = a->hd;
					atom bb = b->hd;
					oneOfCbObj = (OneOfCombinationObject *) malloc(
							sizeof(OneOfCombinationObject));
					oneOfCbObj->NUMBER_OF_OBJECT = 2;
					oneOfCbObj->listAtom[0] = aa;
					oneOfCbObj->listAtom[1] = bb;
					oneOfCbObj->operation = 1;
					a = a->tl;
					b = b->tl;
					addOneOfCbObjectToOneOfCombine(oneOfCbCom, oneOfCbObj);
				}
				a = tempOneOFAtomList->list[i];
				atom aa = a->hd;
				while (b != NULL) {
					atom bb = b->hd;
					oneOfCbObj = (OneOfCombinationObject *) malloc(
							sizeof(OneOfCombinationObject));
					oneOfCbObj->NUMBER_OF_OBJECT = 2;
					oneOfCbObj->listAtom[0] = aa;
					oneOfCbObj->listAtom[1] = bb;
					oneOfCbObj->operation = 1;
					b = b->tl;
					addOneOfCbObjectToOneOfCombine(oneOfCbCom, oneOfCbObj);
				}
			} else {
				printf("---Exception---Exit----");
				exit(1);
			}
			addOneOfCbComToOneOfCombineList(oneOfCombinationList, oneOfCbCom);

		} else {
			printf("\n---ThanhNH---Check %d : Cannot Combine", i);
		}
		i = i + 2;
	}
	printf("\n-----------------------------------------------\n");
}

int count_element_atomlist(atomlist *a) {
	int count = 0;
	while (a != NULL) {
		count++;
		a = a->tl;
	}
	return count;
}

void print_actions_depended_by_literal(SetOfAction *sOfAction) {
	int i = 0;
	printf(" {");
	for (i = 0; i < sOfAction->length; i++) {
		printf(" %d ", sOfAction->index_action[i]);
	}
	printf("}  ");
}

int check_index_action_exist_in_set_of_action(int index,
		SetOfAction *setOfAction) {
	int i = 0;
	for (i = 0; i < setOfAction->length; i++) {
		if (index == setOfAction->index_action[i]) {
			return 1;
		}
	}
	return 0;
}

SetOfAction* get_preact_from_set_of_literal(atomlist *literalList) {
	SetOfAction *sOfAction_One_OF = (SetOfAction *) malloc(sizeof(SetOfAction));
	sOfAction_One_OF->length = 0;
	printf("\n==================================\n");
	while (literalList != NULL) {
		atom a = literalList->hd;
		newAtom na;
		na.atom = a;
		na.pos_neg = 1;
		SetOfAction *setOfAction_depends_literal = (SetOfAction *) malloc(
				sizeof(SetOfAction));
		setOfAction_depends_literal = preact_of_literal(na, conformantAction);

		/* Add each set of action to group set of depends action one_of list */
		int currentOneOf = sOfAction_One_OF->length;
		int i = 0;
		for (i = 0; i < setOfAction_depends_literal->length; i++) {
			if (check_index_action_exist_in_set_of_action(
					setOfAction_depends_literal->index_action[i],
					sOfAction_One_OF) == 0) {
				sOfAction_One_OF->index_action[currentOneOf] =
						setOfAction_depends_literal->index_action[i];
				currentOneOf++;
				sOfAction_One_OF->length = currentOneOf;
			}
		}

		/* End Add */
		printatom(na.atom);
		print_actions_depended_by_literal(setOfAction_depends_literal);
		literalList = literalList->tl;
	}
	printf("\n=Action depends ONE-OF=PREACT(L)=");
	print_actions_depended_by_literal(sOfAction_One_OF);
	printf("\n==================================\n");
	return sOfAction_One_OF;
}

SetOfLiteral *convert_atomlist_to_setOfLiteral(atomlist *list) {
	if (list == NULL)
		return NULL;

	SetOfLiteral *sOfLiteral = (SetOfLiteral *) malloc(sizeof(SetOfLiteral));
	sOfLiteral->length = 0;
	while (list != NULL) {
		atom a = list->hd;
		newAtom na;
		na.atom = a;
		na.pos_neg = 1;

		int currentLength = sOfLiteral->length;
		sOfLiteral->set_of_literal[currentLength] = na;
		sOfLiteral->length = currentLength + 1;

		list = list->tl;
	}
	return sOfLiteral;
}

int checkOneOFCombinable(atomlist *oneOfComplex_1, atomlist *oneOfComplex_2) {
	if (oneOfComplex_1 == NULL || oneOfComplex_2 == NULL) {
		return 0;
	}
	SetOfAction *sOfAction_One_OF_1 = get_preact_from_set_of_literal(
			oneOfComplex_1);
	SetOfAction *sOfAction_One_OF_2 = get_preact_from_set_of_literal(
			oneOfComplex_2);

	if (check_intersect_2_sets_of_action(sOfAction_One_OF_1, sOfAction_One_OF_2)
			== 1) {
		return 0;
	}

	printf("\n =====PREACT(L1) intersect PREACT(L2) = Empty=====");
	printf("\n ==================================================");

	SetOfLiteral *sOfLiteral_one_of_1 = deps_of_set_action(sOfAction_One_OF_1,
			conformantAction, allLiteral);
	SetOfLiteral *sOfLiteral_one_of_2 = deps_of_set_action(sOfAction_One_OF_2,
			conformantAction, allLiteral);

	printf("\n =====REL(L1)=DEPS(PREACT(L1)=");
	print_literal_depend_on_action(sOfLiteral_one_of_1);
	printf("\n =====REL(L2)=DEPS(PREACT(L2)=");
	print_literal_depend_on_action(sOfLiteral_one_of_2);

	if (check_intersect_2_sets_of_literal(sOfLiteral_one_of_1,
			sOfLiteral_one_of_2) == 1) {
		return 0;
	}
	printf("\n =====REL(L1) intersect REL(L2) = EMPTY ==");

	printf("\n ==========================================");

	SetOfLiteral *litLiteral_one_of_1 = lit_of_literal(oneOfComplex_1);
	SetOfLiteral *litLiteral_one_of_2 = lit_of_literal(oneOfComplex_2);

	printf("\n =====LIT(L1)=");
	print_literal_depend_on_action(litLiteral_one_of_1);
	printf("\n =====LIT(L2)=");
	print_literal_depend_on_action(litLiteral_one_of_2);

	if (check_intersect_2_sets_of_literal(sOfLiteral_one_of_1,
			litLiteral_one_of_2) == 1) {
		return 0;
	}
	printf("\n =====REL(L1) intersect LIT(L2) = EMPTY ==");

	if (check_intersect_2_sets_of_literal(sOfLiteral_one_of_2,
			litLiteral_one_of_1) == 1) {
		return 0;
	}
	printf("\n =====REL(L2) intersect LIT(L1) = EMPTY ==");
	printf("\n ==========================================");
	return 1;
}

int check_literal_exist_in_set_of_literal(newAtom atom, SetOfLiteral *S) {
	int length = S->length;
	int i = 0;
	for (i = 0; i < length; i++) {
		if (atom.pos_neg == 1 && S->set_of_literal[i].pos_neg == 1) {
			if (compareTowAtomList(atom.atom, S->set_of_literal[i].atom) == 1) {
				return 1;
			}
		}
		if (atom.pos_neg == -1 && S->set_of_literal[i].pos_neg == -1) {
			if (compareTowAtomList(atom.atom, S->set_of_literal[i].atom) == 1) {
				return 1;
			}
		}
	}
	return 0;
}

int check_intersect_2_sets_of_literal(SetOfLiteral *S1, SetOfLiteral *S2) {
	int lengthS1 = S1->length;
	int lengthS2 = S2->length;

	if (lengthS1 <= lengthS2) {
		int i = 0;
		for (i = 0; i < lengthS1; i++) {
			if (check_literal_exist_in_set_of_literal(S1->set_of_literal[i], S2)
					== 1) {
				return 1;
			}
		}
		return 0;
	} else if (lengthS1 > lengthS2) {
		int i = 0;
		for (i = 0; i < lengthS2; i++) {
			if (check_literal_exist_in_set_of_literal(S2->set_of_literal[i], S1)
					== 1) {
				return 1;
			}
		}
		return 0;
	}

	return 0;
}

void print_literal_depend_on_action(SetOfLiteral *sOfLiteral) {
	int length = sOfLiteral->length;
	int i = 0;
	printf(" {");
	for (i = 0; i < length; i++) {
		newAtom atom = sOfLiteral->set_of_literal[i];
		if (atom.pos_neg == 1) {
			printatom(atom.atom);
		} else {
			printf("-");
			printatom(atom.atom);
		}
	}
	printf("}");
}

int check_intersect_2_sets_of_action(SetOfAction *S1, SetOfAction *S2) {
	int lengthS1 = S1->length;
	int lengthS2 = S2->length;

	if (lengthS1 <= lengthS2) {
		int i = 0;
		for (i = 0; i < lengthS1; i++) {
			if (check_index_action_exist_in_set_of_action(S1->index_action[i],
					S2) == 1) {

				return 1;
			}
		}
		return 0;
	} else if (lengthS1 > lengthS2) {
		int i = 0;
		for (i = 0; i < lengthS2; i++) {
			if (check_index_action_exist_in_set_of_action(S2->index_action[i],
					S1) == 1) {

				return 1;
			}
		}
		return 0;
	}

	return 0;

}

SetOfLiteral *lit_of_literal(atomlist *oneOfComplex) {
	if (oneOfComplex == NULL)
		return NULL;
	SetOfLiteral *S = (SetOfLiteral *) malloc(sizeof(SetOfLiteral));
	S->length = 0;
	while (oneOfComplex != NULL) {
		atom a = oneOfComplex->hd;
		//Add to positive literal
		newAtom pNA, nNA;
		pNA.atom = a;
		pNA.pos_neg = 1;
		int currentLength;
		if (check_literal_exist_in_set_of_literal(pNA, S) == 0) {
			currentLength = S->length;
			S->set_of_literal[currentLength] = pNA;
			S->length = currentLength + 1;
		}

		//Add to negative literal
		nNA.atom = a;
		nNA.pos_neg = -1;
		if (check_literal_exist_in_set_of_literal(nNA, S) == 0) {
			currentLength = S->length;
			S->set_of_literal[currentLength] = nNA;
			S->length = currentLength + 1;
		}
		oneOfComplex = oneOfComplex->tl;
	}

	return S;
}

SetOfAction *preact_of_literal(newAtom atom, ConformantAction *sCActions) {
	SetOfAction *setOfAction = (SetOfAction *) malloc(sizeof(SetOfAction));
	setOfAction->length = 0;
	int number_of_action = sCActions->NUMBER_ACTIONS;
	int i = 0;
	for (i = 0; i < number_of_action; i++) {
		if (check_action_depends_literal(i, atom, sCActions) == 1) {
			int currentLength = setOfAction->length;
			setOfAction->index_action[currentLength] = i;
			setOfAction->length = currentLength + 1;
		}
	}
	return setOfAction;
}

SetOfAction *preact_of_set_literal(SetOfLiteral *sOfLiteral,
		ConformantAction *sCActions) {
	SetOfAction *setOfAction = (SetOfAction *) malloc(sizeof(SetOfAction));
	setOfAction->length = 0;
	int number_literal = sOfLiteral->length;
	int i = 0;
	for (i = 0; i < number_literal; i++) {
		SetOfAction *miniSetOfAction = preact_of_literal(
				sOfLiteral->set_of_literal[i], sCActions);
		/* Add each set of action to group set of depends action one_of list */
		int currentOneOf = setOfAction->length;
		int i = 0;
		for (i = 0; i < miniSetOfAction->length; i++) {
			if (check_index_action_exist_in_set_of_action(
					miniSetOfAction->index_action[i], setOfAction) == 0) {
				setOfAction->index_action[currentOneOf] =
						miniSetOfAction->index_action[i];
				currentOneOf++;
				setOfAction->length = currentOneOf;
			}
		}
		/* End Add */
	}

	return setOfAction;
}

int check_action_depends_literal(int actionIndex, newAtom atom,
		ConformantAction *sCActions) {
	if (sCActions->NUMBER_USEFUL_ACTIONS == 0) {
		return 0;
	}

	if (check_literal_satisfy_full_condition(atom, actionIndex) == 1) {
		return 1;
	} else {
		//* PHAN NAY RAT KHO - TIEP TUC NGHIEN CUU DE CODE HIEU QUA - BAT BUOC SU DUNG DEQUY
		/**
		 *  ________________++++++++++++++++++++++++++++++++++++++++++====================
		 */
	}
	return 0;

}

int check_literal_satisfy_full_condition(newAtom atom, int actionIndex) {
	/* Check Useful */
	if (conformantAction->add_useful_action_flag[actionIndex] != 1) {
		return 0;
	}

	/* Check Literal satisfy Precondtion or Not */
	FMAStructure *precondition = conformantAction->precondition[actionIndex];
	if (precondition->fmatype == 1) {
		if (atom.pos_neg == 1) {
			if (compareTowAtomList(atom.atom, precondition->positiveAtom)
					== 1) {
				return 1;
			} else {
				//return 0;
			}
		} else {
			//return 0;
		}
	} else if (precondition->fmatype == 2) {
		if (atom.pos_neg == -1) {
			if (compareTowAtomList(atom.atom, precondition->negativeAtom)
					== 1) {
				return 1;
			} else {
				//return 0;
			}
		} else {
			//return 0;
		}
	} else if (precondition->fmatype == 3) {
		int number_atom = precondition->number_conjunction_object;
		int i = 0;
		for (i = 0; i < number_atom; i++) {
			if (compareTowAtomList(atom.atom, precondition->Conjunction[i])
					== 1) {
				return 1;
			}
		}
		//return 0;
	} else if (precondition->fmatype == 4) {
		int number_atom = precondition->number_disjunction_object;
		int i = 0;
		for (i = 0; i < number_atom; i++) {
			if (compareTowAtomList(atom.atom, precondition->Disjunction[i])
					== 1) {
				return 1;
			}
		}
		//return 0;
	} else if (precondition->fmatype == 5) {
		//return 1;
	} else if (precondition->fmatype == 6) {
		//return 0;
	} else {
		//return 0;
	}

	/* Check Literal satisfy IF-CONDITION OR NOT or Not */
	SecondFMAStructure *ifCondition = conformantAction->ifCondition[actionIndex];
	int k = 0;
	while (ifCondition != NULL) {

		FMAStructure *smallCondition = ifCondition->fmaStructure;
		if (smallCondition->fmatype == 1) {
			if (atom.pos_neg == 1) {
				if (compareTowAtomList(atom.atom, smallCondition->positiveAtom)
						== 1) {
					return 1;
				} else {
					//return 0;
				}
			} else {
				//return 0;
			}
		} else if (smallCondition->fmatype == 2) {
			if (atom.pos_neg == -1) {
				if (compareTowAtomList(atom.atom, smallCondition->negativeAtom)
						== 1) {
					return 1;
				} else {
					//return 0;
				}
			} else {
				//return 0;
			}
		} else if (smallCondition->fmatype == 3) {
			int number_atom = smallCondition->number_conjunction_object;
			int i = 0;
			for (i = 0; i < number_atom; i++) {
				if (compareTowAtomList(atom.atom,
						smallCondition->Conjunction[i]) == 1) {
					return 1;
				}
			}

		} else if (smallCondition->fmatype == 4) {
			int number_atom = smallCondition->number_disjunction_object;
			int i = 0;
			for (i = 0; i < number_atom; i++) {
				if (compareTowAtomList(atom.atom,
						smallCondition->Disjunction[i]) == 1) {
					return 1;
				}
			}
			//return 0;

		} else if (smallCondition->fmatype == 5) {
//			if (conformantAction->effectAction[actionIndex]->number_atom_per_each_effect[k]
//					!= 0) {
//				return 1;
//			}
		} else if (smallCondition->fmatype == 6) {

		} else {

		}
		k++;
		ifCondition = ifCondition->next;

	}

	/* Chot */
	return 0;
}

SetOfLiteral *deps_of_action(int actionIndex, ConformantAction *cAction,
		AllLiteralStructure *lstLiteral) {
	SetOfLiteral* sOfLiteral = (SetOfLiteral *) malloc(sizeof(SetOfAction));
	sOfLiteral->length = 0;

	if (lstLiteral == NULL)
		return NULL;

	newAtom* effects = cAction->effAction[actionIndex];
	int number_atom_effect = cAction->number_Of_Atom_effAction[actionIndex];

	int i = 0;
	int currentLength = 0;
	for (i = 0; i < number_atom_effect; i++) {
		newAtom na;
		na.atom = effects[i].atom;
		na.pos_neg = effects[i].pos_neg;
		sOfLiteral->set_of_literal[i] = na;
		sOfLiteral->length = i + 1;
	}

	return sOfLiteral;
}

void combine_setOfLiteral(SetOfLiteral *main, SetOfLiteral *add) {
	int currentLength = main->length;
	int addLength = add->length;
	int i = 0;
	for (i = 0; i < addLength; i++) {
		if (check_literal_exist_in_set_of_literal(add->set_of_literal[i], main)
				== 0) {
			currentLength = main->length;
			main->set_of_literal[currentLength] = add->set_of_literal[i];
			main->length = currentLength + 1;
		}
	}
}

SetOfLiteral *deps_of_set_action(SetOfAction *sOfAction,
		ConformantAction *cAction, AllLiteralStructure *lstLiteral) {
	int number_set_action = sOfAction->length;
	int i = 0;
	SetOfLiteral *sOfLiteral = (SetOfLiteral *) malloc(sizeof(SetOfLiteral));
	for (i = 0; i < number_set_action; i++) {
		SetOfLiteral *miniSOfLiteral = deps_of_action(
				sOfAction->index_action[i], cAction, lstLiteral);
		combine_setOfLiteral(sOfLiteral, miniSOfLiteral);
	}
	return sOfLiteral;
}

int check_literal_depends_action(newAtom atom, int actionIndex,
		ConformantAction *cAction) {
	if (cAction->NUMBER_USEFUL_ACTIONS == 0) {
		return 0;
	}

	if (check_literal_in_effects_of_action(atom, actionIndex) == 1) {
		return 1;
	} else {
		//* PHAN NAY RAT KHO - TIEP TUC NGHIEN CUU DE CODE HIEU QUA - BAT BUOC SU DUNG DEQUY
		/**
		 *  ________________++++++++++++++++++++++++++++++++++++++++++====================
		 */
	}
	return 0;
}

int check_literal_in_effects_of_action(newAtom atom, int actionIndex) {
	newAtom* lstAtom = conformantAction->effAction[actionIndex];
	int number_atom = conformantAction->number_Of_Atom_effAction[actionIndex];
	int i = 0;
	for (i = 0; i < number_atom; i++) {
		if ((atom.atom == lstAtom[i].atom)
				&& (atom.pos_neg == lstAtom[i].pos_neg)) {
			return 1;
		}
	}
	return 0;
}
