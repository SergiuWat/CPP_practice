#include <iostream>
#include <vector>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>  

#include <time.h>

using namespace std;

class Random
{
private:
	double min, max;

public:

	Random()
	{
		srand(time(NULL));

		if (max > min)
		{
			this->min = max;
			this->max = min;
		}
		else
		{
			this->min = min;
			this->max = max;
		}
	}

	Random(double min, double max)
	{
		srand(time(NULL));

		this->min = min;
		this->max = max;
	}

	int NextInt()
	{
		return NextInt((int)this->min, (int)this->max);
	}

	int NextInt(int min, int max)
	{
		int num = min + rand() % (max - min + 1);
		return num;
	}

	int* GetArrayInt(int count)
	{
		int* A = new int[count];
		for (int i = 0; i < count; i++)
			A[i] = NextInt();
		return A;
	}

};

class GameOfLife {
private:
	vector<string> v;
	vector<vector<string>> matrix;

public:

	//This will set the matrix with random values ('*' or '-')  

	//void setGrid(int rows, int columns) {
	//	Random R1(0, 1);
	//	for (int i = 0; i < rows; i++) {
	//		matrix.push_back(v);
	//		int* D = R1.GetArrayInt(columns);
	//		for (int j = 0; j < columns; j++) {
	//			srand(time(NULL));
	//			if (D[j] == 0) {
	//				matrix.at(i).push_back("-");
	//			}
	//			else {
	//				matrix.at(i).push_back("*");
	//			}
	//			
	//			srand(1);
	//		}
	//		delete D;
	//	}		
	//}


	//Pentru tema

	void setGrid(int rows, int columns) {
		
		for (int i = 0; i < rows; i++) {
			matrix.push_back(v);
			
			for (int j = 0; j < columns; j++) {
				
				matrix.at(i).push_back("-");
				
			}
			
		}
	}

	void printMatrix() {
		for (int i = 0; i < matrix.size(); i++) {

			for (int j = 0; j < matrix.at(0).size(); j++) {
				cout << matrix.at(i).at(j) << " ";
			}
			cout << endl;
		}
	}

	void nextGeneration() {
		int neighborsAlive = 0;
		vector<vector<string>> secondMatrix = matrix;
		for (int i = 0; i < secondMatrix.size(); i++) {
			for (int j = 0; j < secondMatrix.at(0).size(); j++) {

				if (j + 1 != secondMatrix.at(0).size()) {
					if (secondMatrix.at(i).at(j + 1) == "*") { //dreapta
						neighborsAlive++;
					}
				}
				if (j - 1 != -1) {
					if (secondMatrix.at(i).at(j - 1) == "*") {//stanga
						neighborsAlive++;
					}
				}
				if (i - 1 != -1) {
					if (secondMatrix.at(i - 1).at(j) == "*") { // sus
						neighborsAlive++;
					}
				}
				if (i + 1 != secondMatrix.size()) {
					if (secondMatrix.at(i + 1).at(j) == "*") { // jos
						neighborsAlive++;
					}
				}
				if (i - 1 != -1 && j + 1 != secondMatrix.at(0).size()) {
					if (secondMatrix.at(i - 1).at(j + 1) == "*") {//sus dreapta
						neighborsAlive++;
					}
				}
				if (i - 1 != -1 && j - 1 != -1) {
					if (secondMatrix.at(i - 1).at(j - 1) == "*") { //sus stanga
						neighborsAlive++;
					}
				}

				if (i + 1 != secondMatrix.size() && j + 1 != secondMatrix.at(0).size()) {
					if (secondMatrix.at(i + 1).at(j + 1) == "*") {//jos dreapta
						neighborsAlive++;
					}
				}
				if (i + 1 != secondMatrix.size() && j - 1 != -1) {
					if (secondMatrix.at(i + 1).at(j - 1) == "*") { //jos stanga
						neighborsAlive++;
					}
				}

				if (secondMatrix.at(i).at(j) == "-") {
					if (neighborsAlive == 3) {
						matrix.at(i).at(j) = "*";
					}
				}
				if (secondMatrix.at(i).at(j) == "*") {
					if (neighborsAlive < 2) {
						matrix.at(i).at(j) = "-";
					}
					else if (neighborsAlive > 3) {
						matrix.at(i).at(j) = "-";
					}
				}
				neighborsAlive = 0;
			}

		}
	}

	void setCells(string life, int rows, int columns) {
		matrix.at(rows).at(columns) = life;
	}

	void printShape(string shapeName, int row, int column) {
		if (row > matrix.size() || row < 0 || column < 0 || column >= matrix.at(0).size()) {
			cout << "Wrong coordinates" << endl;
			return;
		}
		if (shapeName == "Block") {

			if (row - 1 < 0 || column < 0 || column + 1 >= matrix.at(0).size()) {
				cout << "Wrong coordinates" << endl;
				return;
			}

			matrix.at(row).at(column) = "*";
			matrix.at(row).at(column + 1) = "*";
			matrix.at(row - 1).at(column) = "*";
			matrix.at(row - 1).at(column + 1) = "*";
		}
		if (shapeName == "Blinker") {

			if (row >= matrix.size() || row < 0 || column - 1 < 0 || column + 1 >= matrix.at(0).size()) {
				cout << "Wrong coordinates" << endl;
				return;
			}

			matrix.at(row).at(column) = "*";
			matrix.at(row).at(column + 1) = "*";
			matrix.at(row).at(column - 1) = "*";
		}
		if (shapeName == "Boat") {

			if (row - 1 < 0 || row + 1 >= matrix.size() || column - 1 < 0 || column + 1 >= matrix.at(0).size()) {
				cout << "Wrong coordinates" << endl;
				return;
			}

			matrix.at(row - 1).at(column) = "*";
			matrix.at(row - 1).at(column - 1) = "*";
			matrix.at(row).at(column - 1) = "*";
			matrix.at(row).at(column + 1) = "*";
			matrix.at(row + 1).at(column) = "*";
		}

		if (shapeName == "Glider") {

			if (row - 1 < 0 || row + 1 >= matrix.size() || column - 1 < 0 || column + 1 >= matrix.at(0).size()) {
				cout << "Wrong coordinates" << endl;
				return;
			}

			matrix.at(row - 1).at(column) = "*";
			matrix.at(row - 1).at(column + 1) = "*";
			matrix.at(row - 1).at(column - 1) = "*";
			matrix.at(row).at(column + 1) = "*";
			matrix.at(row + 1).at(column) = "*";
		}

		if (shapeName == "Beacon") {

			if (row - 1 < 0 || row + 2 >= matrix.size() || row + 1 >= matrix.size() || column - 1 < 0 || column + 1 >= matrix.at(0).size() || column + 2 >= matrix.size()) {
				cout << "Wrong coordinates" << endl;
				return;
			}

			matrix.at(row - 1).at(column) = "*";
			matrix.at(row - 1).at(column - 1) = "*";
			matrix.at(row).at(column - 1) = "*";
			matrix.at(row + 1).at(column + 2) = "*";
			matrix.at(row + 2).at(column + 2) = "*";
			matrix.at(row + 2).at(column + 1) = "*";
		}
	}
};

int main()
{
	GameOfLife gameOfLife;
	int ticks = 20;
	gameOfLife.setGrid(20, 20); // sunt 2 functii setGrid, functia care este acum este pentru tema si cealalta va genera un grid cu valori random
	gameOfLife.printShape("Glider", 10, 10);
	gameOfLife.printMatrix();

	//Just for fun using the random setGrid function
	/*while (true) {
		gameOfLife.nextGeneration();
		gameOfLife.printMatrix();
		Sleep(500);
		system("cls");

	}*/
	for (int i = 0; i < ticks; i++) {
		cin.ignore();
		system("cls");
		gameOfLife.printMatrix();
		gameOfLife.nextGeneration();
		
	}
}