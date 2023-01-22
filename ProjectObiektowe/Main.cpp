#include "Function.h"


int main()
{

	Stats Blue; //tworzenie dwoch druzy klasy Stats
	Stats Red;

	stats Green; //tworzenie dwoch druzy klasy stats
	stats Black;


	ReadData(Blue, Red, "Zeszyt2.txt"); //czytanie wartosci z pliku przy uzyciu funkcji i zapisywanie do vektora druzyny

	ReadData(Green, Black, "Zeszyt1.txt"); // to samo dla 2 pliku
	
	int i = 1; // dwie zmienne dla petli
	int k = 1;
	int choice = 0; //wybory analizy podawane przez uzytkownika
	int choice1 = 0;
	//interfejs analizy 
	while (i) 
	{
		cout << "STATYSTYKI ROZGRYWEK LEAGUE OF LEGENDS, RANGA DIAMENT:\nWybierz opcje analizy:\n1. Analiza pierwszych 15 min meczu.\n2. Analiz calego meczu.\n3. Zakoncz dzilanie programu\n";
		k = 1;
		cin >> choice;
		switch (choice) 
		{
		case 1:
			cout << "Wybrales opcje nr 1: Analiza pierwszych 15 minut meczu\n\n";
			cout << "Mozliwe opcje analizy:\n1. Wplyw zlota na wynik gry\n2. Wplyw punktow doswiadczenia na wynik gry\n" <<
				"3. Wplyw postawionych totemow na wynik gry\n4. Wplyw zniszczonych totemow na wynik gry\n5. Wplyw pierwszego zabojstwa na wynik gry\n" <<
				"6. Wplyw ilosci zabojstw na wynik gry\n7. Wplyw ilosci zabitych elitarnych potworow na wynik gry\n8. Wplyw ilosci zabitych smokow na wynik gry" <<
				"\n9. Wplyw ilosci zabitych Heraldow na wynik gry\n10. Wplyw ilosci zniszczonych wiez na wynik gry\n11. Wplyw ilosci zabitych minionow na wynik gry" <<
				"\n12. Wplyw ilosci zabitych minionow w jungli na wynik gry" << "\n13. Zmien wybrana opcje\n////////////////////////////////////////";
			while (k) {

				cout << "\nWybierz z listy (1, 2, 3...)\n";

				cin >> choice1;

				switch (choice1) {
				
				case 1:
					cout << "Wybrales opcje nr 1" << endl;
					AvgWinGold(Green, Black);
					break;
				case 2:
					cout << "Wybrales opcje nr 2" << endl;
					AvgWinExp(Green, Black);
					break;
				case 3:
					cout << "Wybrales opcje nr 3" << endl;
					AvgWinWardPlaced(Green, Black);
					break;
				case 4:
					cout << "Wybrales opcje nr 4" << endl;
					AvgWinWardDestroyed(Green, Black);
					break;
				case 5:
					cout << "Wybrales opcje nr 5" << endl;
					AvgWinFirstBlood(Green, Black);
					break;
				case 6:
					cout << "Wybrales opcje nr 6" << endl;
					AvgWinKill(Green, Black);
					break;
				case 7:
					cout << "Wybrales opcje nr 7" << endl;
					AvgWinEliteMonsters(Green, Black);
					break;
				case 8:
					cout << "Wybrales opcje nr 8" << endl;
					AvgWinDragons(Green, Black);
					break;
				case 9:
					cout << "Wybrales opcje nr 9" << endl;
					AvgWinHeralds(Green, Black);
					break;
				case 10:
					cout << "Wybrales opcje nr 10" << endl;
					AvgWinTowersDestroyed(Green, Black);
					break;
				case 11:
					cout << "Wybrales opcje nr 11" << endl;
					AvgWinJungleMinions(Green, Black);
					break;
				case 12:
					cout << "Wybrales opcje nr 12" << endl;
					AvgWinMinions(Green, Black);
					break;
				case 13:
					cout << "Wybrales opcje nr 13" << endl;
					k = 0;
					break;
				default:
					cout << "Nie ma wybranej opcji" << endl;
					break;
				}
			}
			break;
		case 2:
			cout << "Wybrales opcje nr 2:\n\n";
			cout << "Mozliwe opcje analizy:\n1. Sredni czas gry\n2. Wplyw zlota na wynik gry\n3. Wplyw punktow doswiadczenia na wynik gry\n" <<
				"4. Wplyw postawionych totemow na wynik gry\n5. Wplyw zniszczonych totemow na wynik gry\n6. Wplyw pierwszego zabojstwa na wynik gry\n" <<
				"7. Wplyw ilosci zabojstw na wynik gry\n8. Wplyw pierwszego zniszczonego inhibitora na wynik gry\n9. Wplyw ilosci zniszczonych inhibitorw na wynik gry" <<
				"\n10. Wplyw ilosci zabitych Heraldow na wynik gry\n11. Wplyw pierszego zabitego Barona na wynik gry\n12. Wplyw ilosci zabitych Baronow na wynik gry" <<
				"\n13. Zmień wybrana opcje\n////////////////////////////////////////";
			while (k) {

				cout << "\nWybierz z listy (1, 2, 3...)\n";
				cin >> choice1;
				switch (choice1) {
				
				case 1:
					cout << "Wybrales opcje nr 1" << endl;
					AvgTime(Blue);
					break;
				case 2:
					cout << "Wybrales opcje nr 2" << endl;
					AvgWinGold(Blue, Red);
					break;
				case 3:
					cout << "Wybrales opcje nr 3" << endl;
					AvgWinExp(Blue, Red);
					break;
				case 4:
					cout << "Wybrales opcje nr 4" << endl;
					AvgWinWardPlaced(Blue, Red);
					break;
				case 5:
					cout << "Wybrales opcje nr 5" << endl;
					AvgWinWardDestroyed(Blue, Red);
					break;
				case 6:
					cout << "Wybrales opcje nr 6" << endl;
					AvgWinFirstBlood(Blue, Red);
					break;
				case 7:
					cout << "Wybrales opcje nr 7" << endl;
					AvgWinKill(Blue, Red);
					break;
				case 8:
					cout << "Wybrales opcje nr 8" << endl;
					AvgWinFirstInhibitor(Blue, Red);
					break;
				case 9:
					cout << "Wybrales opcje nr 9" << endl;
					AvgWinInhibitor(Blue, Red);
					break;
				case 10:
					cout << "Wybrales opcje nr 10" << endl;
					AvgWinHeralds(Blue, Red);
					break;
				case 11:
					cout << "Wybrales opcje nr 11" << endl;
					AvgWinFirstBaron(Blue, Red);
					break;
				case 12:
					cout << "Wybrales opcje nr 12" << endl;
					AvgWinBarons(Blue, Red);
					break;
				case 13:
					cout << "Wybrales opcje nr 13" << endl;
					k = 0;
					break;
				default:
					cout << "Nie ma wybranej opcji" << endl;
					break;
				}
			}
			break;
		case 3:
			cout << "Wybrales opcje nr 3:";
			i = 0;
			break;
		default:
			cout << "Nie ma wybranej opcji" << endl;
		}

	}
return 0;
}
