#include <iostream>
#include <random>
#include <time.h>

void Croissant(int tabC[], int taille_tabC) {
	int j = 0;
	std::cout << "Voici le Tableau avant le tri:" << std::endl;
	for (int x = 0; x < taille_tabC; x++) {
		std::cout << tabC[x] << " ";
	}
	std::cout << "" << std::endl;
	while (j < taille_tabC) {
		for (int i = 0; i < tabC[i + 1]; i++) {
			if (tabC[i + 1] < tabC[i]) {
				int temp = tabC[i];
				tabC[i] = tabC[i + 1];
				tabC[i + 1] = temp;
			}
		}
		j++;
	}
	std::cout << "Voici le tableau C apres le tri: " << std::endl;
	for (int x = 0; x < taille_tabC; x++) {
		std::cout << tabC[x] << " ";
	}
	std::cout << "" << std::endl;
}
void Flip(int tabF[], int tabFT[], int taille_tabF, int taille_tabFT) {
	std::cout << "Voici le tableau avant le tri:" << std::endl;
	for (int x = 0; x < taille_tabF; x++) {
		std::cout << tabF[x] << " ";
	}
	for (int z = 0; z < taille_tabF; z++) {
		for (int y = taille_tabFT; y >= 0; y--) {
			tabFT[y] = tabF[z];
		}
	}
	std::cout << "Voici le tableau apres le tri:" << std::endl;
	for (int x = 0; x < taille_tabFT; x++) {
		std::cout << tabFT[x] << " ";
	}
	std::cout << "" << std::endl;
}
//int Taille(int tabT[5]) {}

void InitGrid(int* Grid, int gridCol, int gridLig) {
	//index= 0=>n-1 (si 5 lig et 5 col: 4*5+4 = 24 (index 4 lig * 5 colonnes + index 4 col)
	for (int index = 0; index < gridLig; index++) {
		for (int index2 = 0; index2 < gridCol; index2++) {
			int tab_index = index * gridCol + index2;
			Grid[tab_index] = 0;
		}
	}
}
int GetNeighborsStatus (int CellX, int CellY, int* Grid, int gridCol, int gridLig){
	//initialise un nombre de voisins vivants
	int nbrAliveNeighbor = 0;
	//parcour grille 3*3 autour d'index actuel + incremente nbrAliveNeighbor si cellule vivante around
	for (int neighborX = CellX - 1; neighborX <= CellX + 1; neighborX++) {	
		for (int neighborY = CellY - 1; neighborY <= CellY + 1; neighborY++) {
			if (!(neighborX == CellX && neighborY == CellY) && neighborX >= 0 && neighborY >= 0 && neighborX < gridLig && neighborY < gridCol) {
				if (Grid[neighborX * gridCol + neighborY] > 0) {
					nbrAliveNeighbor++;
				}
			}
		}
	}
	return nbrAliveNeighbor;
}

void displayNeighbors(int* Grid, int gridCol, int gridLig) {
	int aliveNeighbors = 0;
	for (int lig = 0; lig < gridLig; lig++) {
		for (int col = 0; col < gridCol; col++) {
			aliveNeighbors = GetNeighborsStatus(lig, col, Grid, gridCol, gridLig);
			std::cout << aliveNeighbors;
		}
		std::cout << std::endl;
	}
}

void printGrid(int* Grid, int gridCol, int gridLig) {
	//imprime cellule vivante/morte en fonction de si l'index = 1 (alive) ou 0 (dead)
	int neighbors;
	int* neighborhood = new int[gridCol * gridLig];
	for (int x = 0; x < gridLig; x++) {
		for (int y = 0; y < gridCol; y++) {
		neighbors = GetNeighborsStatus(x, y, Grid, gridCol, gridLig);
		neighborhood[x * gridCol + y] = neighbors;
		}
	}
	for (int index_x = 0; index_x < gridLig; index_x++) {
		for (int index_y = 0; index_y < gridCol; index_y++){
			if (Grid[index_x * gridCol + index_y] ==1){
				std::cout << "o";
			}
			else {
				std::cout << "x";
			}
			if (neighborhood[index_x * gridCol + index_y] < 2 || neighborhood[index_x * gridCol + index_y] > 3){
				Grid[index_x * gridCol + index_y] = 0;
			}
			else if (neighborhood[index_x * gridCol + index_y] == 3){
				Grid[index_x * gridCol + index_y] = 1;
			}
		}
		std::cout << std::endl;
	}
	delete neighborhood;
	neighborhood = nullptr;
}

//fonction demineur:


int main() {

	bool game=true;
	while (game == true){
		int choixGame;
		std::cout << "Que voulez-vous faire ?" << std::endl;
		std::cout << "1. Calculatrice" << std::endl;
		std::cout << "2. Plus ou Moins" << std::endl;
		std::cout << "3. Jeu de Nim" << std::endl;
		std::cout << "4. Fonctions" << std::endl;
		std::cout << "5. Game of Life" << std::endl;
		std::cout << "6. Demineur (WIP)" << std::endl;
		std::cout << "7. Quitter" << std::endl;
		std::cin >> choixGame;
		if (choixGame==1){
			bool calculatrice = true;
			while (calculatrice == true){
				int choixOP;
				std::cout << "Quel type d'operation voulez vous faire ?" << std::endl;
				std::cout << "1. Addition" << std::endl;
				std::cout << "2. Soustraction" << std::endl;
				std::cout << "3. Multiplication" << std::endl;
				std::cout << "4. Division" << std::endl;
				std::cout << "5. Modulo" << std::endl;
				std::cin >> choixOP;
				if (choixOP == 1){
					int addnmb1;
					int addnmb2;
					std::cout << "Inserez un premier nombre" << std::endl;
					std::cin >> addnmb1;
					bool isGood = addnmb1 / 1;
					if (!isGood){
						std::cout << "Erreur: Nombre Invalid";
						return 0;
					}
					std::cout << "Inserez un deuxieme nombre" << std::endl;
					std::cin >> addnmb2;
					std::cout << "Voici le resultat de votre addition" << std::endl;
					std::cout << addnmb1 + addnmb2 << std::endl;
				}
				else if (choixOP == 2){
					int remnmb1;
					int remnmb2;
					std::cout << "Inserez un premier nombre" << std::endl;
					std::cin >> remnmb1;
					bool isGood = remnmb1 / 1;
					if (!isGood){
						std::cout << "Erreur: Nombre Invalid";
						return 0;
					}
					std::cout << "Inserez un deuxieme nombre" << std::endl;
					std::cin >> remnmb2;
					std::cout << "Voici le resultat de votre soustraction" << std::endl;
					std::cout << remnmb1 - remnmb2 << std::endl;
				}
				else if (choixOP == 3){
					int multnmb1;
					int multnmb2;
					std::cout << "Inserez un premier nombre" << std::endl;
					std::cin >> multnmb1;
					bool isGood = multnmb1 / 1;
					if (!isGood){
						std::cout << "Erreur: Nombre Invalid";
						return 0;
					}
					std::cout << "Inserez un deuxieme nombre" << std::endl;
					std::cin >> multnmb2;
					std::cout << "Voici le resultat de votre multiplication" << std::endl;
					std::cout << multnmb1 * multnmb2 << std::endl;
				}
				else if (choixOP == 4){
					int divnmb1;
					int divnmb2;
					std::cout << "Inserez un premier nombre" << std::endl;
					std::cin >> divnmb1;
					bool isGood = divnmb1 / 1;
					if (!isGood){
						std::cout << "Erreur: Nombre Invalid";
						return 0;
					}
					std::cout << "Inserez un deuxieme nombre" << std::endl;
					std::cin >> divnmb2;
					std::cout << "Voici le resultat de votre division" << std::endl;
					std::cout << divnmb1 / divnmb2 << std::endl;
				}
				else if (choixOP == 5){
					int modnmb1;
					int modnmb2;
					std::cout << "Inserez un premier nombre" << std::endl;
					std::cin >> modnmb1;
					bool isGood = modnmb1 / 1;
					if (!isGood){
						std::cout << "Erreur: Nombre Invalid";
						return 0;
					}
					std::cout << "Inserez un deuxieme nombre" << std::endl;
					std::cin >> modnmb2;
					std::cout << "Voici le resultat de votre modulo" << std::endl;
					std::cout << modnmb1 % modnmb2 << std::endl;
				}
				else{
					return 0;
				}
				std::cout << "Voulez-vous continuer a utiliser la calculatrice ?" << std::endl;
				std::cout << "0. Non" << std::endl;
				std::cout << "1. Oui" << std::endl;
				std::cin >> calculatrice;
			}
		}
		else if (choixGame == 2){
			std::srand(time(NULL));
			int const rando = rand()%100;
			int guess = rando+1;
			std::cout << "Un nombre a ete choisi." << std::endl;
			std::cout << "Veuillez inserez un nombre pour deviner:" << std::endl;
			while (guess != rando){
				std::cin >> guess;
				if (guess < rando){
					std::cout << "Le nombre recherche est plus grand !" << std::endl;
				}
				else{
					std::cout << "Le nombre recherche est plus petit !" << std::endl;
				}
			}
			std::cout << "Bravo, vous avez trouver !";
		}
		else if (choixGame == 3){
			int batons = 20;
			int tour;
			int pick = 0;
			std::cout << "Choisissez qui commence (0. Vous) (1. ORDI):";
			std::cin >> tour;
			if (tour == 0 || tour == 1){
				while (batons != 1){
					if (tour == 0 && batons != 1) {
						std::cout << "Veuillez choisir un nombre de baton a retirer entre 1 et 3:" << std::endl;
						std::cout << "Batons Restants: " << batons << std::endl;
						std::cin >> pick;
						if (pick > 3 || pick < 1 || pick > batons - 1) {
							std::cout << "Impossible de prendre autant de batons !" << std::endl;
							tour = 0;
						}
						else if (pick == 1) {
							batons = batons - pick;
							tour = 1;
						}
						else if (pick == 2) {
							batons = batons - pick;
							tour = 1;
						}
						else if (pick == 3) {
							batons = batons - pick;
							tour = 1;
						}
					}
					else if (tour == 1 && batons != 1) {
						std::random_device rd;
						std::mt19937 gen(rd());
						std::uniform_int_distribution<int> dist(1, 3);
						int iapick = dist(gen);
						std::cout << "L'IA a choisis de retirer " << iapick << " batons" << std::endl;
						if (iapick > 3 || iapick < 1 || iapick > batons - 1) {
							std::cout << "Impossible de prendre autant de batons !" << std::endl;
							tour = 1;
						}
						else if (iapick == 1) {
							batons = batons - iapick;
							tour = 0;
						}
						else if (iapick == 2) {
							batons = batons - iapick;
							tour = 0;
						}
						else if (iapick == 3) {
							batons = batons - iapick;
							tour = 0;
						}
					}
				}
				if (tour == 0) {
					std::cout << "Vous avez perdu !" << std::endl;
				}
				else if (tour == 1) {
					std::cout << "Vous avez gagner !" << std::endl;
				}
			}
			else{
				return 0;
			}
		}
		else if (choixGame == 4){
			int choixFonc;
			std::cout << "Que voulez vous faire ?" << std::endl;
			std::cout << "1. Ordre Croissant" << std::endl;
			std::cout << "2. Flip Tableau" << std::endl;
			std::cout << "3. Taille Tableau" << std::endl;
			std::cout << "4. Quitter" << std::endl;
			std::cin >> choixFonc;
			if (choixFonc==1){
				int tabC[5] = { 9, 50 ,87, 45, 63 };
				Croissant(tabC, 5);
			}
			else if (choixFonc == 2) {
				int tabF[5] = {9, 50 ,87, 45, 63};
				int tabFT[5] = {};
				Flip(tabF,tabFT, 5, 5);
			}
			//else if (choixFonc == 3) {
			//	int tabT[5] = {9, 50 ,87, 45, 63};
			//	Taille(tabT, 5);}
		}
		else if (choixGame == 5) {
			//taille de la grille
			std::cout << "Veuillez entrer un nombre de Colonnes: ";
			int gridCol;
			std::cin >> gridCol;
			std::cout << std::endl;
			std::cout << "Veuillez entrer un nombre de Lignes: ";
			int gridLig;
			std::cin >> gridLig;
			std::cout << std::endl;
			int choiceCase = 0;
			//
			int* Grid = new int[gridCol * gridLig];
			InitGrid(Grid, gridCol, gridLig);
			//choix nombre cellules vivantes: (max taille tab):
			std::cout << "Combien de cellules voulez vous: ";
			int nbrBirth;
			std::cin >> nbrBirth;
			while (nbrBirth >= gridCol * gridLig || nbrBirth < 1) {
				std::cout << "Erreur: Valeur Invalide.";
				std::cin >> nbrBirth;
			}
			for (int i =0; i < nbrBirth; i++){
				// choix des coordonnées
				std::cout << "Choisissez une ligne pour la cellule: ";
				int ligCell;
				while (choiceCase == 0) {
					std::cin >> ligCell;
					if (ligCell < gridLig && ligCell >= 0) {
						choiceCase = 1;
					}
					else {
						std::cout << "Erreur: Valeur Invalide" << std::endl;
					}
				}
				std::cout << std::endl;
				choiceCase = 0;
				std::cout << "Choisissez une colonne pour la cellule: ";
				int colCell;
				while (choiceCase == 0) {
					std::cin >> colCell;
					if (colCell < gridCol && colCell >= 0) {
						choiceCase = 1;
					}
					else {
						std::cout << "Erreur: Valeur Invalide" << std::endl;
					}
					std::cout << std::endl;
				}
				choiceCase = 0;
				Grid[ligCell * gridCol + colCell] = 1;
				//
			}
			std::cout << std::endl;
			std::cout << "Combien de fois voulez-vous que la simulation itere: ";
			int temps;
			std::cin >> temps;
			while (temps > 0) {
				displayNeighbors(Grid, gridCol, gridLig);
				printGrid(Grid, gridCol, gridLig);
				temps--;
			}
			delete Grid;
			Grid = nullptr;
		}
		else if (choixGame == 6) {
			std::cout << "Selectionnez la difficulte (1. Facile) (2. Normal) (3. Difficile): ";
			int choicediff;
			std::cin >> choicediff;
			if (choicediff < 1 || choicediff >3) {
				std::cout << "Erreur, Valeur Invalide.";
				std::cout << std::endl;
			}
			else if (choicediff == 1) {
				std::cout << "Diff 1";
			}
			else if (choicediff == 2){
				std::cout << "Diff 2";
			}
			else if (choicediff == 3) {
				std::cout << "Diff 3";
			}
		}
		else if (choixGame == 7) {
			return 0;
		}
	}
	return 0;
}