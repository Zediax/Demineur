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
		std::cout << "6. Quitter" << std::endl;
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
			int gridCol;
			int gridLig;
			int cellCol;
			int cellLig;
			std::cout << "Veuillez entrer un nombre de Colonnes: ";
			std::cin >> gridCol;
			std::cout << "Veuillez entrer un nombre de Lignes: ";
			std::cin >> gridLig;
			std::cout << "Veuillez selectioner l'emplacement de la cellule" << std::endl;
			std::cout << "Colonne: ";
			std::cin >> cellCol;
			std::cout << "Ligne: ";
			std::cin >> cellLig;
			//generation grille avec Cellule établie
			for (int y = 0; y < gridLig*2-1; y++) {
				if (y % 2 == 1) {
					for (int x = 0; x < gridCol; x++) {
						std::cout << "--- ";
					}
					std::cout << std::endl;
				}
				else {
					for (int x = 0;x<=gridCol-1; x++) {
						if (x == cellCol && y/2 == cellLig) {
							std::cout << " o ";
						}
						else {
							std::cout << " x ";
						}
						if (x < gridCol - 1) {
							std::cout << "|";
						}
					}
				std::cout << std::endl;
				}
			}

			//logique de vie de cellules:

		}
		else if (choixGame == 6) {
			return 0;
		}
	}

	

	return 0;
}