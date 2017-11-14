#include <stdio.h>
#include <stdlib.h>
#ifndef EH
#define EH 0
#endif //!EH
#ifndef LH
#define LH 1
#endif //!LH
#ifndef RH
#define RH -1
#endif //!RH
#ifndef TRUE
#define TRUE 1
#endif //!TRUE
#ifndef FALSE
#define FALSE 0
#endif //!FALSE

struct node
{
	int data;
	int bf;
	struct node *lchild;
	struct node *rchild;

};

typedef node* Tree;

//Left child is higher and the new element is inserted into the left child, so balance the left child! 
void LeftBalance(Tree *T) {
	Tree L, LR;

	L=(*T)->lchild;

	switch (L->bf) {
	//LL
	case LH:
		(*T)->bf=L->bf=EH;
		RRotate(T);
		break;
	//LR
	case RH:
		LR=L->rchild;

		//Refresh the balance factor after double rotation
		switch (LR->bf) {
		case LH:
			(*T)->bf=RH;
			L->bf=EH;
			break;
		case EH:
			(*T)->bf=L->bf=EH;
			break;
		case RH:
			(*T)->bf=EH;
			L->bf=LH;
			break;
		}
		LR->bf=EH;
		LRotate(&(*T)->lchild);
		RRotate(T);
		break;
	case EH:
		//break;
	}
}

void LRotate(Tree *T) {
	Tree temp;
	temp=(*T)->rchild;
	(*T)->rchild=temp->lchild;
	temp->lchild=(*T);
}

void RRotate(Tree *p) {
	Tree L;
	L=(*p)->lchild;
	(*p)->lchild=L->rchild;
	L->rchild=(*p);
	(*p)=L;
}


int insertAVL(Tree *T, int e, int *taller) {
	if (!*T) {
		T=(BiTree)malloc(sizeof(BiNode));
		(*T)->data=e;
		(*T)->lchild=(*T)->lchild=NULL;
		(*T)->bf=EH;
		*taller=TRUE;
	}
	else {
		if (e==(*T)->data) {
			*taller=FALSE;
			return FALSE;
		}

		//Inserted in left child!
		if (e<(*T)->data) {
			if (!insertAVL(&(*T)->lchild, e, taller)) {
				return FALSE;
			}
			//If it is taller, the left child will be taller.
			if (*taller) {
				switch((*T)->bf) {

				//If the previous balance factor is LH(Left Higher), 
				//	when the left child is taller, we should re-balance the tree.
				case LH:
					LeftBalance(T);

					//When the tree is rotated, it will no longer be taller.
					*taller=FALSE;
					break;

				//If the previous balance factor is EH(Equal Height),
				//	when the left child is taller, the balance factor will be LH.
				case EH:
					(*T)->bf=LH;
					*taller=TRUE;
					break;

				//If the previous balance factor is RH(Right Higher),
				//	when the left child is taller, the balance factor will be EH, the tree is balanced.
				case RH:
					(*T)->bf=EH;
					*taller=FALSE;
					break;

				default:
					break;
				}
			}
		} 
		else {
			if (!insertAVL(&(*T)->rchild, e, taller)) {
				*taller=FALSE;
				return FALSE;
			} else {
				switch ((*T)->bf) {
				case LH:
					(*T)->bf=EH;
					*taller=FALSE;
					break;
				case EH:
					(*T)->bf=RH;
					*taller=TRUE;
					break;
				case RH:
					RightBalance(T);
					*taller=FALSE;
					break;
				default:
					break;
				}
			}
		}
	}
}