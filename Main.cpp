#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <queue>
#include <random>
#include <time.h>

using namespace std;

//fonctions démineur:
int DemNeighbors(int* DGrid, int demCol, int demLig, int posX, int posY) {
	//compte le nombre de bombes autour d'une case donnée
	int nbrMineNeighbors = 0;
	for (int nX = posX - 1; nX <= posX + 1; nX++) {
		for (int nY = posY - 1; nY <= posY + 1; nY++) {
			if (!(nX == posX && nY == posY) && nX >= 0 && nY >= 0 && nX < demLig && nY < demCol) {
				if (DGrid[nX * demCol + nY] == 19) {
					nbrMineNeighbors++;
				}
			}
		}
	}
	return nbrMineNeighbors;
}
void InitDGrid(int* DGrid, int demCol, int demLig, int nbrBombes) {
	srand(time(NULL));
	int tab_index;
	//placement aléatoire des bombes sur la grille:
	while (nbrBombes != 0) {
		int rX = rand() % demLig;
		int rY = rand() % demCol;
		tab_index = rX * demCol + rY;
		if (DGrid[tab_index] != 19) {
			DGrid[tab_index] = 19;
			nbrBombes--;
		}
	}
	for (int indX = 0; indX < demLig; indX++) {
		for (int indY = 0; indY < demCol; indY++) {
			//affichage de la grille completement cachée:
			tab_index = indX * demCol + indY;
			if (DGrid[tab_index] != 19) {
				DGrid[tab_index] = 10 + DemNeighbors(DGrid, demCol, demLig, indX, indY);
			}
		}
	cout << endl;
	cout << endl;
	}
}
bool isKeyPressed(int pressedKey) {
	// vérifie si une touche est actuellement enfoncée
	SHORT keyPressed = GetKeyState(pressedKey);
	return (keyPressed & 0x8000) !=0;
}
void printGridDem(int* DGrid, int demCol, int demLig, int posX, int posY) {
	system("cls");
	for (int demIndX = 0; demIndX < demLig; demIndX++) {
		for (int demIndY = 0; demIndY < demCol; demIndY++) {
			int i = demIndX * demCol + demIndY;
			// définition des cellules en fonction de leur état
			if (DGrid[i] == 0) {
				//safe cell
				if (demIndX == posY && demIndY == posX) {
					cout << "[__]";
				}
				else {
					cout << " __ ";
				}
			}
			else if (DGrid[i] == 1) {
				if (demIndX == posY && demIndY == posX) {
					cout << "[ 1]";
				}
				else {
					cout << "  1 ";
				}
			}
			else if (DGrid[i] == 2) {
				if (demIndX == posY && demIndY == posX) {
					cout << "[ 2]";
				}
				else {
					cout << "  2 ";
				}
			}
			else if (DGrid[i] == 3) {
				if (demIndX == posY && demIndY == posX) {
					cout << "[ 3]";
				}
				else {
					cout << "  3 ";
				}
			}
			else if (DGrid[i] == 4) {
				if (demIndX == posY && demIndY == posX) {
					cout << "[ 4]";
				}
				else {
					cout << "  4 ";
				}
			}
			else if (DGrid[i] == 5) {
				if (demIndX == posY && demIndY == posX) {
					cout << "[ 5]";
				}
				else {
					cout << "  5 ";
				}
			}
			else if (DGrid[i] == 6) {
				if (demIndX == posY && demIndY == posX) {
					cout << "[ 6]";
				}
				else {
					cout << "  6 ";
				}
			}
			else if (DGrid[i] == 7) {
				if (demIndX == posY && demIndY == posX) {
					cout << "[ 7]";
				}
				else {
					cout << "  7 ";
				}
			}
			else if (DGrid[i] == 8) {
				if (demIndX == posY && demIndY == posX) {
					cout << "[ 8]";
				}
				else {
					cout << "  8 ";
				}
			}
			else if (DGrid[i] == 9) {
				//case bombe, si cliquée, on affiche une explosion, sinon on affiche la bombe
				if (demIndX == posY && demIndY == posX) {
					cout << "[💥]";
				}
				else {
					cout << " 💣 ";
				}
			}
			else if (DGrid[i] >= 30) {
				//case flag
				if (demIndX == posY && demIndY == posX) {
					cout << "[🚩]";
				}
				else {
					cout << " 🚩 ";
				}
			}
			else if (DGrid[i] >= 10) {
				//case non dévoilée
				if (demIndX == posY && demIndY == posX) {
					cout << "[██]";
				}
				else {
					cout << " ██ ";
				}
			}
		} 
		cout << endl;
		cout << endl;
	}
}
void FloodFill(int posX, int posY, int* DGrid, int gridCol, int gridLig) {
	queue<pair<int, int>> q;
	// directions pour les 8 cellules voisines (N, S, E, W, NE, SE, NW, SW)
	int qx[8] = { 0,0,1,-1,1,1,-1,-1 };
	int qy[8] = { 1,-1,0,0,1,-1,1,-1 };
	int start = posY * gridCol + posX;
	// si la cellule actuelle est vide, on la dévoile et on entame le floodfill
	if (DGrid[start] >= 10 && DGrid[start] <= 19) {
		DGrid[start] -= 10;
		if (DGrid[start] == 0) {
			q.push({ posX,posY });
		}
		while (!q.empty()) {
			pair<int, int> current = q.front();
			int cx = current.first;
			int cy = current.second;
			q.pop();
			for (int j = 0; j < 8; j++) {
				int nx = cx + qx[j];
				int ny = cy + qy[j];
				if (nx < 0 || nx >= gridCol || ny < 0 || ny >= gridLig) continue;
				int i = ny * gridCol + nx;
				if (DGrid[i] >= 10 && DGrid[i] <= 18) {
					DGrid[i] -= 10;
					if (DGrid[i] == 0) {
						q.push({ nx, ny });
					}
				}
			}
		}
	}
}
bool victoire(int* DGrid, int demCol, int demLig, int totalMines) {
	int mineFlag = 0;
	//compte le nombre de bombes correctement flaggées et vérifie si toutes les cases sont dévoilées 
	//attention, les cases flag même de façon incorrecte font déscendre le compteur de bombes !
	for (int i = 0; i < demLig * demCol; i++) {
		int v = DGrid[i];
		if (v == 39) {
			mineFlag++;
		}
		else if (v > 8) {
			return false;
		}
	}
	return mineFlag == totalMines;
}

int main() {
	SetConsoleOutputCP(65001);
	int choixGame;
	cout << "Que voulez-vous faire ?" << endl;
	cout << "1. Jouer" << endl;
	cout << "2. Quitter" << endl;
	cin >> choixGame;
	if (choixGame == 1) {
		int demCol;
		int demLig;
		int nbrBombes;
		int posX = 0;
		int posY = 0;
		int choicediff;
		//selection de la difficulté
		cout << "Selectionnez la difficulte (1. Facile) (2. Normal) (3. Difficile): ";
		cin >> choicediff;
		while (choicediff < 1 || choicediff > 3) {
			cout << "Erreur, Valeur Invalide. Veuillez reessayer: ";
			cin >> choicediff;
		}
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
		else if (choicediff == 2) {
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
		int totalMines = nbrBombes;
		InitDGrid(DGrid, demCol, demLig, nbrBombes);
		printGridDem(DGrid, demCol, demLig, posX, posY);
		cout << "Appuyez sur ESPACE pour devoiler une case, F pour placer un drapeau, et les fleches directionnelles pour vous deplacer." << endl;
		cout << endl;
		cout << "Coordonnees: " << posX << " - " << posY << " | Bombes Restantes: " << nbrBombes << endl;
		while (demRun == true) {
			//detection barre espace pour devoiler une case => si vide: rien, si bombe: boom, sinon chiffre (de 1 a 8)
			if (isKeyPressed(VK_SPACE) && 0x8000) {
				while (isKeyPressed(VK_SPACE) && 0x8000);
				FloodFill(posX, posY, DGrid, demCol, demLig);
				printGridDem(DGrid, demCol, demLig, posX, posY);
				//si toutes les cases sont dévoilées et que toutes les bombes sont flag, on gagne
				if (victoire(DGrid, demCol, demLig, totalMines) == true) {
					cout << "Vous avez gagne !" << endl;
					demRun = false;
				}
				//si la case est une bombe, on perd et on affiche toutes les bombes
				else if (DGrid[posY * demCol + posX] == 9) {
					for (int i = 0; i < demCol * demLig; i++) {
						if (DGrid[i] == 19 || DGrid[i] == 39) {
							DGrid[i] = 9;
						}
					}
					cout << "BOOM ! Vous avez perdu !" << endl;
					demRun = false;
				}
				cout << "Coordonnees: " << posX << " - " << posY << " | Bombes Restantes: " << nbrBombes << endl;
			}
			//detection touches de déplacement:
			if (isKeyPressed(VK_LEFT) && 0x8000) {
				while (isKeyPressed(VK_LEFT) && 0x8000);
				if (posX == 0) {
					printGridDem(DGrid, demCol, demLig, posX, posY);
					cout << "Impossible d'aller plus loin !" << endl;
				}
				else {
					posX--;
					printGridDem(DGrid, demCol, demLig, posX, posY);
					cout << "Coordonnees: " << posX << " - " << posY << " | Bombes Restantes: " << nbrBombes << endl;
				}
			}
			if (isKeyPressed(VK_RIGHT) && 0x8000) {
				while (isKeyPressed(VK_RIGHT) && 0x8000);
				if (posX == demCol - 1) {
					printGridDem(DGrid, demCol, demLig, posX, posY);
					cout << "Impossible d'aller plus loin !" << endl;
				}
				else {
					posX++;
					printGridDem(DGrid, demCol, demLig, posX, posY);
					cout << "Coordonnees: " << posX << " - " << posY << " | Bombes Restantes: " << nbrBombes << endl;
				}
			}
			if (isKeyPressed(VK_UP) && 0x8000) {
				while (isKeyPressed(VK_UP) && 0x8000);
				if (posY == 0) {
					printGridDem(DGrid, demCol, demLig, posX, posY);
					cout << "Impossible d'aller plus loin !" << endl;
				}
				else {
					posY--;
					printGridDem(DGrid, demCol, demLig, posX, posY);
					cout << "Coordonnees: " << posX << " - " << posY << " | Bombes Restantes: " << nbrBombes << endl;
				}
			}
			if (isKeyPressed(VK_DOWN) && 0x8000) {
				while (isKeyPressed(VK_DOWN) && 0x8000);
				if (posY == demLig - 1) {
					printGridDem(DGrid, demCol, demLig, posX, posY);
					cout << "Impossible d'aller plus loin !" << endl;
				}
				else {
					posY++;
					printGridDem(DGrid, demCol, demLig, posX, posY);
					cout << "Coordonnees: " << posX << " - " << posY << " | Bombes Restantes: " << nbrBombes << endl;
				}
			}
			//détection de la touche F pour placer un drapeau sur une case:
			if (isKeyPressed('F') && 0x8000) {
				while (isKeyPressed('F') && 0x8000);
				int i = posY * demCol + posX;
				if (DGrid[i] >= 10 && DGrid[i] <= 19) {
					DGrid[i] += 20;
					nbrBombes--;
					printGridDem(DGrid, demCol, demLig, posX, posY);
				}

				else if (DGrid[i] >= 30) {
					DGrid[i] -= 20;
					nbrBombes++;
					printGridDem(DGrid, demCol, demLig, posX, posY);
				}
				printGridDem(DGrid, demCol, demLig, posX, posY);
				cout << "Coordonnees: " << posX << " - " << posY << " | Bombes Restantes: " << nbrBombes << endl;
				if (victoire(DGrid, demCol, demLig, totalMines) == true) {
					cout << "Vous avez gagne !" << endl;
					demRun = false;
				}
			}
		}
		cout << endl;
		//libération de la mémoire
		delete DGrid;
		DGrid = nullptr;
	}
	else {
		return 0;
	}
}