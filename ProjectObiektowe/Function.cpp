#include "Function.h"

//getline bierze ca�� linie
//linestream odczyt kazdej wartosci z osobna

int  ReadData(Stats& team1, Stats& team2, string plik) {

	ifstream file(plik);

	if (!file.is_open()) //sprawdzenie czy plik zosat� otwarty
	{
		cerr << "Error file is not open" << endl;
		return -1;
	}

	string line;		 //zmienna string dla nag�owka
	getline(file, line); //czytanie nag�owna
	float time = 0;
	int win = 0;
	int gold1 = 0, gold2 = 0;
	int exp1 = 0, exp2 = 0;
	int WardPlaced1 = 0, WardPlaced2 = 0;
	int WardDestroyed1 = 0, WardDestroyed2 = 0;
	int FirstBlood = 0;
	int Kills1 = 0, Kills2 = 0;
	int FirstInhibitor = 0;
	int Inhibitors1 = 0, Inhibitors2 = 0;
	int Heralds1 = 0, Heralds2 = 0;
	int FirstBaron = 0;
	int Barons1 = 0, Barons2 = 0;
	while (getline(file, line))
	{
		stringstream linestream(line);
		linestream >> time >> win >> gold1 >> gold2 >> exp1 >> exp2 >> WardPlaced1 >> WardPlaced2 >> WardDestroyed1
			>> WardDestroyed2 >> FirstBlood >> Kills1 >> Kills2 >> FirstInhibitor >> Inhibitors1 >> Inhibitors2
			>> Heralds1 >> Heralds2 >> FirstBaron >> Barons1 >> Barons2;
		team1.AddTime(time);
		team2.AddTime(time);
		int x = 0, y = 0, z = 0;
		if (FirstBlood == -1) {
			FirstBlood = 0;
			x = 1;
		}
		if (FirstInhibitor == -1) {
			FirstInhibitor = 0;
			y = 1;
		}
		if (FirstBaron == -1) {
			FirstBaron = 0;
			z = 1;
		}
		team1.AddMatch(win, gold1, exp1, WardPlaced1, WardDestroyed1, FirstBlood, Kills1, FirstInhibitor, Inhibitors1, Heralds1, FirstBaron, Barons1);
		if (win == 0) {
			win = 1;
		}
		else win = 0;
		team2.AddMatch(win, gold2, exp2, WardPlaced2, WardDestroyed2, x, Kills2, y, Inhibitors2, Heralds2, z, Barons2);
	}
	file.close();
	return 0;
}
void AvgTime(Stats& team) {
	int i = 0;
	long double Suma = 0;
	while (i < team.getSize())
	{
		Suma += team.getTime(i);
		i++;
	}
	Suma = Suma / team.getSize();
	cout << "Sredni czas gry = " << Suma;
}
void AvgWinGold(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getGold(i) > team2.getGold(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team2.getWin(i)) {
			W++;
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zlota wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinExp(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getExp(i) > team2.getExp(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team2.getWin(i)) {
			W++;
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia punktow doswiadczenia wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinWardPlaced(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getWardPlaced(i) > team2.getWardPlaced(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getWardPlaced(i) < team2.getWardPlaced(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia postawionych totemow wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinWardDestroyed(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getWardDestroyed(i) > team2.getWardDestroyed(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getWardDestroyed(i) < team2.getWardDestroyed(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zniszczonych totemow wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinFirstBlood(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getFirstBlood(i) > team2.getFirstBlood(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getFirstBlood(i) < team2.getFirstBlood(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna ktora dokona pierwszej krwi wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinKill(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getKills(i) > team2.getKills(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getKills(i) < team2.getKills(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zabojstw wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinFirstInhibitor(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getFirstInhibitor(i) > team2.getFirstInhibitor(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getFirstInhibitor(i) < team2.getFirstInhibitor(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna ktora zniszczyla pierwszy inhibitor wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinInhibitor(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	int k = 0;
	while (i < team1.getSize()) {
		if (team1.getInhibitors(i) > team2.getInhibitors(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getInhibitors(i) < team2.getInhibitors(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		else if (team1.getInhibitors(i) == team2.getInhibitors(i)) k++;
		i++;
	}
	cout << "Statystycznie druzyna ktora zniszczyla wiecej inhibitorow wygrywa  " << (double)W / (team1.getSize()-k) * 100 << "% meczy";
}
void AvgWinHeralds(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	int k = 0;
	while (i < team1.getSize()) {
		if (team1.getHeralds(i) >= team2.getHeralds(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getHeralds(i) < team2.getHeralds(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		else if (team1.getHeralds(i) < team2.getHeralds(i)) k++;
		i++;
	}
	cout << "Statystycznie druzyna ktora zabila wiecej Heraldow wygrywa  " << (double)W / (team1.getSize() - k) * 100 << "% meczy";
}
void AvgWinFirstBaron(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getFirstBaron(i) > team2.getFirstBaron(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getFirstBaron(i) < team2.getFirstBaron(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna ktora zabila pierwszego Barona wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinBarons(Stats& team1, Stats& team2) {
	int i = 0;
	int W = 0;
	int k = 0;
	while (i < team1.getSize()) {
		if (team1.getBarons(i) > team2.getBarons(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getBarons(i) < team2.getBarons(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		else if (team1.getBarons(i) == team2.getBarons(i)) k++;
		i++;
	}
	cout << "Statystycznie druzyna ktora zabila wiecej Baronow wygrywa  " << (double)W / (team1.getSize() - k) * 100 << "% meczy";
}



int  ReadData(stats& team1, stats& team2, string plik) {

	ifstream file("Zeszyt1.txt");

	if (!file.is_open()) //sprawdzenie czy plik zosat� otwarty
	{
		cerr << "Error file is not open" << endl;
		return -1;
	}

	string line;		 //zmienna string dla nag�owka
	getline(file, line); //czytanie nag�owna

	int win = 0;
	int gold = 0;
	int exp = 0;
	int wardplaced = 0;
	int warddestroyed = 0;
	int firstBlood = 0;
	int kills = 0;
	int heralds = 0;
	int elitemonsters = 0;
	int dragons = 0;
	int towersdestroyed = 0;
	int minionskilled = 0;
	int jungleminionskilled = 0;

	while (getline(file, line))
	{
		stringstream linestream(line);
		linestream >> win >> wardplaced >> warddestroyed >> firstBlood >> kills >> elitemonsters >> dragons
			>> heralds >> towersdestroyed >> gold >> exp >> minionskilled >> jungleminionskilled;

		team1.AddMatch(win, wardplaced, warddestroyed, firstBlood, kills, elitemonsters, dragons, heralds, towersdestroyed, gold, exp, minionskilled, jungleminionskilled);

		linestream >> wardplaced >> warddestroyed >> firstBlood >> kills >> elitemonsters >> dragons
			>> heralds >> towersdestroyed >> gold >> exp >> minionskilled >> jungleminionskilled;

		if (win == 0) {
			win = 1;
		}
		else win = 0;
		team2.AddMatch(win, wardplaced, warddestroyed, firstBlood, kills, elitemonsters, dragons, heralds, towersdestroyed, gold, exp, minionskilled, jungleminionskilled);

	}
	file.close();
	return 0;
}

void AvgWinGold(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getGold(i) > team2.getGold(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team2.getWin(i)) {
			W++;
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zlota wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinExp(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getExp(i) > team2.getExp(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team2.getWin(i)) {
			W++;
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia punktow doswiadczenia wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinWardPlaced(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getWardPlaced(i) > team2.getWardPlaced(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getWardPlaced(i) < team2.getWardPlaced(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia postawionych totemow wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinWardDestroyed(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getWardDestroyed(i) > team2.getWardDestroyed(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getWardDestroyed(i) < team2.getWardDestroyed(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zniszczonych totemow wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinFirstBlood(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getFirstBlood(i) > team2.getFirstBlood(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getFirstBlood(i) < team2.getFirstBlood(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna ktora dokona pierwszej krwi wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinKill(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getKills(i) > team2.getKills(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getKills(i) < team2.getKills(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zabojstw wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}

void AvgWinEliteMonsters(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getEliteMonsters(i) > team2.getEliteMonsters(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getEliteMonsters(i) < team2.getEliteMonsters(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zabitych elitarnych potworow wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}

void AvgWinDragons(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	int k = 0;
	while (i < team1.getSize()) {
		if (team1.getDragons(i) > team2.getDragons(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getDragons(i) < team2.getDragons(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		else if (team1.getDragons(i) == team2.getDragons(i)) k++;
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zabitych smokow wygrywa  " << (double)W / (team1.getSize() - k) * 100 << "% meczy";
}
void AvgWinHeralds(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	int k = 0;
	while (i < team1.getSize()) {
		if (team1.getHeralds(i) > team2.getHeralds(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getHeralds(i) < team2.getHeralds(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		else if (team1.getHeralds(i) == team2.getHeralds(i)) k++;
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zabitych Heraldow wygrywa  " << (double)W / (team1.getSize() - k) * 100 << "% meczy";
}
void AvgWinTowersDestroyed(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	int k = 0;
	while (i < team1.getSize()) {
		if (team1.getTowersDestroyed(i) > team2.getTowersDestroyed(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getTowersDestroyed(i) < team2.getTowersDestroyed(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		else if (team1.getTowersDestroyed(i) == team2.getTowersDestroyed(i)) k++;
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zniszczonych wiez wygrywa  " << (double)W / (team1.getSize() - k) * 100 << "% meczy";
}
void AvgWinMinions(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getTowersDestroyed(i) > team2.getTowersDestroyed(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getTowersDestroyed(i) < team2.getTowersDestroyed(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia zabitych minionow wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
void AvgWinJungleMinions(stats& team1, stats& team2) {
	int i = 0;
	int W = 0;
	while (i < team1.getSize()) {
		if (team1.getJungleMinions(i) > team2.getJungleMinions(i)) {
			if (team1.getWin(i)) {
				W++;
			}
		}
		else if (team1.getJungleMinions(i) < team2.getJungleMinions(i)) {
			if (team2.getWin(i)) {
				W++;
			}
		}
		i++;
	}
	cout << "Statystycznie druzyna z wieksza iloscia minionow z jungli wygrywa  " << (W / (double)team1.getSize()) * 100 << "% meczy";
}
