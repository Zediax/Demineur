#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>
#include <chrono>

using namespace std;
using namespace chrono;

void Croissant(int tabC[], int taille_tabC) {
	int j = 0;
	cout << "Voici le Tableau avant le tri:" << endl;
	for (int x = 0; x < taille_tabC; x++) {
		cout << tabC[x] << " ";
	}
	cout << "" << endl;
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
	cout << "Voici le tableau C apres le tri: " << endl;
	for (int x = 0; x < taille_tabC; x++) {
		cout << tabC[x] << " ";
	}
	cout << "" << endl;
}
void Flip(int tabF[], int tabFT[], int taille_tabF, int taille_tabFT) {
	cout << "Voici le tableau avant le tri:" << endl;
	for (int x = 0; x < taille_tabF; x++) {
		cout << tabF[x] << " ";
	}
	for (int z = 0; z < taille_tabF; z++) {
		for (int y = taille_tabFT; y >= 0; y--) {
			tabFT[y] = tabF[z];
		}
	}
	cout << "Voici le tableau apres le tri:" << endl;
	for (int x = 0; x < taille_tabFT; x++) {
		cout << tabFT[x] << " ";
	}
	cout << "" << endl;
}

//fonction initialisation de grille:
void InitGrid(int* Grid, int gridCol, int gridLig) {
	//index= 0=>n-1 (si 5 lig et 5 col: 4*5+4 = 24 (index 4 lig * 5 colonnes + index 4 col)
	for (int index = 0; index < gridLig; index++) {
		for (int index2 = 0; index2 < gridCol; index2++) {
			int tab_index = index * gridCol + index2;
			Grid[tab_index] = 0;
		}
	}
}
//

//fonctions Game of Life:
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
			cout << aliveNeighbors;
		}
		cout << endl;
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
				cout << "o";
			}
			else {
				cout << "x";
			}
			if (neighborhood[index_x * gridCol + index_y] < 2 || neighborhood[index_x * gridCol + index_y] > 3){
				Grid[index_x * gridCol + index_y] = 0;
			}
			else if (neighborhood[index_x * gridCol + index_y] == 3){
				Grid[index_x * gridCol + index_y] = 1;
			}
		}
		cout << endl;
	}
	delete neighborhood;
	neighborhood = nullptr;
}
//

//fonctions démineur:
bool isKeyPressed(int pressedKey) {
	SHORT keyPressed = GetKeyState(pressedKey);
	return (keyPressed & 0x8000) !=0;
}

int main() {

	bool game=true;
	while (game == true){
		int choixGame;
		cout << "Que voulez-vous faire ?" << endl;
		cout << "1. Calculatrice" << endl;
		cout << "2. Plus ou Moins" << endl;
		cout << "3. Jeu de Nim" << endl;
		cout << "4. Fonctions" << endl;
		cout << "5. Game of Life" << endl;
		cout << "6. Demineur (WIP)" << endl;
		cout << "7. Quitter" << endl;
		cin >> choixGame;
		if (choixGame==1){
			bool calculatrice = true;
			while (calculatrice == true){
				int choixOP;
				cout << "Quel type d'operation voulez vous faire ?" << endl;
				cout << "1. Addition" << endl;
				cout << "2. Soustraction" << endl;
				cout << "3. Multiplication" << endl;
				cout << "4. Division" << endl;
				cout << "5. Modulo" << endl;
				cin >> choixOP;
				if (choixOP == 1){
					int addnmb1;
					int addnmb2;
					cout << "Inserez un premier nombre" << endl;
					cin >> addnmb1;
					bool isGood = addnmb1 / 1;
					if (!isGood){
						cout << "Erreur: Nombre Invalid";
						return 0;
					}
					cout << "Inserez un deuxieme nombre" << endl;
					cin >> addnmb2;
					cout << "Voici le resultat de votre addition" << endl;
					cout << addnmb1 + addnmb2 << endl;
				}
				else if (choixOP == 2){
					int remnmb1;
					int remnmb2;
					cout << "Inserez un premier nombre" << endl;
					cin >> remnmb1;
					bool isGood = remnmb1 / 1;
					if (!isGood){
						cout << "Erreur: Nombre Invalid";
						return 0;
					}
					cout << "Inserez un deuxieme nombre" << endl;
					cin >> remnmb2;
					cout << "Voici le resultat de votre soustraction" << endl;
					cout << remnmb1 - remnmb2 << endl;
				}
				else if (choixOP == 3){
					int multnmb1;
					int multnmb2;
					cout << "Inserez un premier nombre" << endl;
					cin >> multnmb1;
					bool isGood = multnmb1 / 1;
					if (!isGood){
						cout << "Erreur: Nombre Invalid";
						return 0;
					}
					cout << "Inserez un deuxieme nombre" << endl;
					cin >> multnmb2;
					cout << "Voici le resultat de votre multiplication" << endl;
					cout << multnmb1 * multnmb2 << endl;
				}
				else if (choixOP == 4){
					int divnmb1;
					int divnmb2;
					cout << "Inserez un premier nombre" << endl;
					cin >> divnmb1;
					bool isGood = divnmb1 / 1;
					if (!isGood){
						cout << "Erreur: Nombre Invalid";
						return 0;
					}
					cout << "Inserez un deuxieme nombre" << endl;
					cin >> divnmb2;
					cout << "Voici le resultat de votre division" << endl;
					cout << divnmb1 / divnmb2 << endl;
				}
				else if (choixOP == 5){
					int modnmb1;
					int modnmb2;
					cout << "Inserez un premier nombre" << endl;
					cin >> modnmb1;
					bool isGood = modnmb1 / 1;
					if (!isGood){
						cout << "Erreur: Nombre Invalid";
						return 0;
					}
					cout << "Inserez un deuxieme nombre" << endl;
					cin >> modnmb2;
					cout << "Voici le resultat de votre modulo" << endl;
					cout << modnmb1 % modnmb2 << endl;
				}
				else{
					return 0;
				}
				cout << "Voulez-vous continuer a utiliser la calculatrice ?" << endl;
				cout << "0. Non" << endl;
				cout << "1. Oui" << endl;
				cin >> calculatrice;
			}
		}
		else if (choixGame == 2){
			srand(time(NULL));
			int const rando = rand()%100;
			int guess = rando+1;
			cout << "Un nombre a ete choisi." << endl;
			cout << "Veuillez inserez un nombre pour deviner:" << endl;
			while (guess != rando){
				cin >> guess;
				if (guess < rando){
					cout << "Le nombre recherche est plus grand !" << endl;
				}
				else{
					cout << "Le nombre recherche est plus petit !" << endl;
				}
			}
			cout << "Bravo, vous avez trouver !";
		}
		else if (choixGame == 3){
			int batons = 20;
			int tour;
			int pick = 0;
			cout << "Choisissez qui commence (0. Vous) (1. ORDI):";
			cin >> tour;
			if (tour == 0 || tour == 1){
				while (batons != 1){
					if (tour == 0 && batons != 1) {
						cout << "Veuillez choisir un nombre de baton a retirer entre 1 et 3:" << endl;
						cout << "Batons Restants: " << batons << endl;
						cin >> pick;
						if (pick > 3 || pick < 1 || pick > batons - 1) {
							cout << "Impossible de prendre autant de batons !" << endl;
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
						random_device rd;
						mt19937 gen(rd());
						uniform_int_distribution<int> dist(1, 3);
						int iapick = dist(gen);
						cout << "L'IA a choisis de retirer " << iapick << " batons" << endl;
						if (iapick > 3 || iapick < 1 || iapick > batons - 1) {
							cout << "Impossible de prendre autant de batons !" << endl;
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
					cout << "Vous avez perdu !" << endl;
				}
				else if (tour == 1) {
					cout << "Vous avez gagner !" << endl;
				}
			}
			else{
				return 0;
			}
		}
		else if (choixGame == 4){
			int choixFonc;
			cout << "Que voulez vous faire ?" << endl;
			cout << "1. Ordre Croissant" << endl;
			cout << "2. Flip Tableau" << endl;
			cout << "3. Taille Tableau" << endl;
			cout << "4. Quitter" << endl;
			cin >> choixFonc;
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
			cout << "Veuillez entrer un nombre de Colonnes: ";
			int gridCol;
			cin >> gridCol;
			cout << endl;
			cout << "Veuillez entrer un nombre de Lignes: ";
			int gridLig;
			cin >> gridLig;
			cout << endl;
			int choiceCase = 0;
			//
			int* Grid = new int[gridCol * gridLig];
			InitGrid(Grid, gridCol, gridLig);
			//choix nombre cellules vivantes: (max taille tab):
			cout << "Combien de cellules voulez vous: ";
			int nbrBirth;
			cin >> nbrBirth;
			while (nbrBirth >= gridCol * gridLig || nbrBirth < 1) {
				cout << "Erreur: Valeur Invalide.";
				cin >> nbrBirth;
			}
			for (int i =0; i < nbrBirth; i++){
				// choix des coordonnées
				cout << "Choisissez une ligne pour la cellule: ";
				int ligCell;
				while (choiceCase == 0) {
					cin >> ligCell;
					if (ligCell < gridLig && ligCell >= 0) {
						choiceCase = 1;
					}
					else {
						cout << "Erreur: Valeur Invalide" << endl;
					}
				}
				cout << endl;
				choiceCase = 0;
				cout << "Choisissez une colonne pour la cellule: ";
				int colCell;
				while (choiceCase == 0) {
					cin >> colCell;
					if (colCell < gridCol && colCell >= 0) {
						choiceCase = 1;
					}
					else {
						cout << "Erreur: Valeur Invalide" << endl;
					}
					cout << endl;
				}
				choiceCase = 0;
				Grid[ligCell * gridCol + colCell] = 1;
				//
			}
			cout << endl;
			cout << "Combien de fois voulez-vous que la simulation itere: ";
			int temps;
			cin >> temps;
			while (temps > 0) {
				displayNeighbors(Grid, gridCol, gridLig);
				printGrid(Grid, gridCol, gridLig);
				temps--;
			}
			delete Grid;
			Grid = nullptr;
		}
		else if (choixGame == 6) {
			int demCol;
			int demLig;
			int nbrBombes;
			int nbrCases;
			int posX=0;
			int posY=0;
			int choicediff;
			//selection de la difficulté
			cout << "Selectionnez la difficulte (1. Facile) (2. Normal) (3. Difficile): ";
			cin >> choicediff;
			if (choicediff < 1 || choicediff >3) {
				cout << "Erreur, Valeur Invalide.";
				cout << endl;
			}
			else if (choicediff == 1) {
				//10x10 en facile | bombe = 10 (10%)
				demCol = 10;
				demLig = 10;
				nbrBombes = 10;
			}
			else if (choicediff == 2){
				//15x15 en normal | bombe = 34 (18%)
				demCol = 15;
				demLig = 15;
				nbrBombes = 34;
			}
			else if (choicediff == 3) {
				//20x20 en difficile | bombe = 100 (25%)
				demCol = 20;
				demLig = 20;
				nbrBombes = 100;
			}
			int* DGrid = new int[demCol * demLig];
			bool demRun = true;
			const auto delay = milliseconds(300);
			auto timeLastInput = steady_clock::now() - delay;
			while (demRun == true) {
				bool isBomb;
				auto now = steady_clock::now();
				auto time_diff = now - timeLastInput;
				//detection barre espace pour devoiler une case => si vide: rien, si bombe: boom, sinon chiffre (de 1 a 8)
				if (isKeyPressed(VK_SPACE) && time_diff >= delay && 0x8000) {
					cout << "Space Pressed" << endl;
					//break;$
					Sleep(500);
				}
				//break;
				demRun == !demRun;
			}
			//
			cout << endl;
			delete DGrid;
			DGrid = nullptr;
		}
		else if (choixGame == 7) {
			return 0;
		}
	}
	return 0;
}