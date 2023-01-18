#pragma once
#include <vector>
using namespace std;




class Stats {
public:
	Stats() {}
	void AddMatch(int Win, int Gold, int Exp, int WardPlaced, int WardDestroyed, int FirstBlood,
		int Kills, int FirstInhibitor, int Inhibitors, int Heralds, int FirstBaron, int Barons);
	void AddTime(float time);
	int getTime(int index);
	int getWin(int index) const;
	int getGold(int index) const;
	int getExp(int index) const;
	int getWardPlaced(int index) const;
	int getWardDestroyed(int index) const;
	int getFirstBlood(int index) const;
	int getKills(int index) const;
	int getFirstInhibitor(int index) const;
	int getInhibitors(int index) const;
	int getHeralds(int index) const;
	int getFirstBaron(int index) const;
	int getBarons(int index) const;
	void getScore(int index) const;
	int getSize() const;

private:
	float Time = 0;
	struct Match {
		int Win = 0;
		int Gold;
		int Exp;
		int WardPlaced;
		int WardDestroyed;
		int FirstBlood;
		int Kills;
		int FirstInhibitor;
		int Inhibitors;
		int Heralds;//potwor po zabiciu pomaga w zniszczeniu wiezy
		int FirstBaron;
		int Barons;//smok po zabiciu pomaga w grze

	};
	vector<float> Times;
	vector<Match> Matches;
};

class stats
{
public:
	stats() {}
	void AddMatch(int Win,int WardPlaced,int WardDestroyed,int FirstBlood,int Kills,int EliteMonsters,int Dragons,
		int Heralds,int TowersDestroyed,int Gold,int Exp,int MinionsKilled,int JungleMinionsKilled);
	int getWin(int index) const;
	int getWardPlaced(int index) const;
	int getWardDestroyed(int index) const;
	int getFirstBlood(int index) const;
	int getKills(int index) const;
	int getEliteMonsters(int index) const;
	int getDragons(int index) const;
	int getHeralds(int index) const;
	int getTowersDestroyed(int index) const;
	int getGold(int index) const;
	int getExp(int index) const;
	int getMinions(int index) const;
	int getJungleMinions(int index) const;
	int getSize() const;

private:
	struct Match {
		int Win;
		int WardPlaced;
		int WardDestroyed;
		int FirstBlood;
		int Kills;
		int EliteMonsters;
		int Dragons;
		int Heralds;//potwor po zabiciu pomaga w zniszczeniu wiezy
		int TowersDestroyed;
		int Gold;
		int Exp;
		int MinionsKilled;
		int JungleMinionsKilled;
	};
	vector<Match> Matches;
};
