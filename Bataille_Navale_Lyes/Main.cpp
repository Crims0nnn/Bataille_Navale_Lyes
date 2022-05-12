#include <stdio.h>
#include <string>
#include <string.h>

#define T 10

typedef struct Case {
	int n_col;
	int n_lig;
}Case;

typedef enum class ori {H,V}ori;

typedef struct position {
	int n_col;
	int n_lig;
	int orientation;
}position;


typedef struct Bateau {
	Case* t_case;
	int n_avion;
	int n_croiseur;
	int n_marin1 ;
	int n_marin2;
	int n_torpi;
	position* t_placement;

}Bateau;

typedef struct Flotte {
	Bateau* t_bateau;
}Flotte;

void Terrainvide(Case* t_case);
//Placement = uniquement les coordonners des bateaux
void Placement(position* t_placement);
void CreaBateau(position* t_placement, Case* t_case,Bateau* taille);
void VerificationCase(position* t_position);
void VerificationFlotte(Case* t_case);


int main() {

//Les Cases
	Case* t_case;
	t_case = nullptr;
	t_case = (Case*)malloc(T * sizeof(Case));
//Position / Taille et orientation ds bateaux
	position* t_placement;
	t_placement = nullptr;
	t_placement = (position*)malloc(T * sizeof(position));
	ori* H_V;
	H_V = nullptr;
	H_V = (ori*)malloc(T * sizeof(ori));
	Bateau* taille;
	taille = nullptr;
	taille = (Bateau*)malloc(T * sizeof(Bateau*));
	//placement des bateaux dans un tableaux
	Placement(t_placement);
	//creation des bateaux
	CreaBateau(t_placement, t_case,taille);
	VerificationCase(t_placement);//Verification s'il y a un bateau
	VerificationFlotte(t_case);//Verification si il appartient a la flotte
//Tableaux avec les coordonners des bateaux

	return 0;
}

void Terrainvide(Case* t_case) {
	for (int i = 1; i < T ; i++) {
		t_case[i].n_lig = 0;
		for (int j = 1; j < T; j++) {
			t_case[j].n_col = 0;
		}
	}
}
void Placement(position* t_placement) {
	char Ori;
	int i = 0;
	do {
		printf_s("Quel est la position du porte avion?\n");
		printf_s("La ligne\n");
		scanf_s("%d",&t_placement[i].n_lig);
		printf_s("La colonne\n");
		scanf_s("%d",&t_placement[i].n_col);
		printf_s("Quel orientation souhaitez vous H ou V\n");
		scanf_s(" %c", &Ori,1);
		if (Ori == 'V') {
			t_placement[i].orientation = 1;
		}
		else {
			t_placement[i].orientation = 0;
		}
	} while (t_placement[i].n_lig < 0 || t_placement[i].n_lig > 11 || t_placement->n_col < 0 || t_placement->n_col>11);
	i++;
/*	do {
		printf_s("Quel est la position du croisseur?\n");
		printf_s("La ligne\n");
		scanf_s("%d", &t_placement[i].n_lig);
		printf_s("La colonne\n");
		scanf_s("%d", &t_placement[i].n_col);
		printf_s("Quel orientation souhaitez vous H ou V\n");
		scanf_s(" %c", &Ori, 1);
		if (Ori == 'V') {
			t_placement[i].orientation = 1;
		}
	} while (t_placement[i].n_lig < 0 || t_placement[i].n_lig > 11 || t_placement->n_col < 0 || t_placement->n_col>11);
	i++;
	do {
		printf_s("Quel est la position du sous marin 1?\n");
		printf_s("La ligne\n");
		scanf_s("%d", &t_placement[i].n_lig);
		printf_s("La colonne\n");
		scanf_s("%d", &t_placement[i].n_col);
		printf_s("Quel orientation souhaitez vous H ou V\n");
		scanf_s(" %c", &Ori, 1);
		if (Ori == 'V') {
			t_placement[i].orientation = 1;
		}
	} while (t_placement[i].n_lig < 0 || t_placement[i].n_lig > 11 || t_placement->n_col < 0 || t_placement->n_col>11);
	i++;
	do {
		printf_s("Quel est la position du sous marin 2?\n");
		printf_s("La ligne\n");
		scanf_s("%d", &t_placement[i].n_lig);
		printf_s("La colonne\n");
		scanf_s("%d", &t_placement[i].n_col);
		printf_s("Quel orientation souhaitez vous H ou V\n");
		scanf_s(" %c", &Ori, 1);
		if (Ori == 'V') {
			t_placement[i].orientation = 1;
		}
	} while (t_placement[i].n_lig < 0 || t_placement[i].n_lig > 11 || t_placement->n_col < 0 || t_placement->n_col>11);
	i++;
	do {
		printf_s("Quel est la position du torpieur?\n");
		printf_s("La ligne\n");
		scanf_s("%d", &t_placement[i].n_lig);
		printf_s("La colonne\n");
		scanf_s("%d", &t_placement[i].n_col);
		printf_s("Quel orientation souhaitez vous H ou V\n");
		scanf_s(" %c", &Ori, 1);
		if (Ori == 'V') {
			t_placement[i].orientation = 1;
		}
	} while (t_placement[i].n_lig < 0 || t_placement[i].n_lig > 11 || t_placement->n_col < 0 || t_placement->n_col>11);
	i++;
	*/
}

void CreaBateau(position* t_placement, Case* t_case,Bateau* taille) {
	int i = 0;
	int ligne = 0;
	int colonne = 0;
	int a = 5;
	int b = 4;
	do{
		if (i == 0 && t_placement[i].orientation == 0) {
			ligne = t_placement[i].n_lig;
			colonne = t_placement[i].n_col;
			for (int l = 0; l < T; l++) {
				t_case[l].n_lig = 0;
				printf_s("%d", t_case[l].n_lig);
				printf_s("\n");
				for (int c = 1; c < T; c++) {
					if (c >= colonne && c <= colonne + b && l + 1 == ligne) {
						t_case[c].n_col = 1;
					}
					else { t_case[c].n_col = 0; }
					printf_s("%d", t_case[c].n_col);
				}
			}
		}
		if (i == 0 && t_placement[i].orientation == 1) {
			ligne = t_placement[i].n_lig;
			colonne = t_placement[i].n_col;
			for (int l = 0; l < T - 1; l++) {
				if (t_case[l].n_lig == 0) {
					t_case[l].n_lig = 0;
				}
				printf_s("%d", t_case[l].n_lig);
				printf_s("\n");
				for (int c = 0; c < T - 1; c++) {
					if (l >= ligne && l <= ligne + a && ligne + a <= 10 && c >= colonne && c <= colonne + 5) {
						t_case[l + 1].n_col = 1;
					}
					else {
						t_case[c].n_col = 0;
						t_case[c].n_lig = 0;
					}
					printf_s("%d", t_case[c].n_col);
				}
			}
		}
		i++;
	} while (i==1);
}
void VerificationCase(position* t_placement) {
	int c = 0;
	for (int i = 0; i <= 4; i++) {
		if (t_placement[i].n_lig != 0) {
			c++;
		}
	}
	if (c > 0) {
		printf_s("Il y a un bateau sur cette case\n");
	}
	else { printf_s("Il n'y a rien\n"); }
}

void VerificationFlotte(Case* t_case) {
	int c = 0;
	for (int i = 0; i <= 4; i++) {
		if (t_case[i].n_lig || t_case[i].n_col != 0) {
			c++;
		}
	}
	if (c > 0) {
		printf_s("Appartient a la Flotte\n");
	}
	else { printf_s("N'appartient a la Flotte\n"); }


}