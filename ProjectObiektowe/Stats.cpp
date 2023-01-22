#include "Stats.h"


void Stats::AddTime(float time) {
	Times.push_back({ time });
}
void Stats::AddMatch(int win, int gold, int exp, int wardplaced, int warddestroyed, int firstblood,
	int kills, int firstinhibitor, int inhibitors, int heralds, int firstbaron, int barons) {
	Matches.push_back({ win, gold, exp, wardplaced, warddestroyed, firstblood, kills, firstinhibitor, inhibitors, heralds,firstbaron, barons });
}
int Stats::getTime(int index) {
	return Times[index];
}
int Stats::getWin(int index) const {
	return Matches[index].Win;
}
int Stats::getGold(int index) const {
	return Matches[index].Gold;
}
int Stats::getExp(int index) const {
	return Matches[index].Exp;
}
int Stats::getWardPlaced(int index) const {
	return Matches[index].WardPlaced;
}
int Stats::getWardDestroyed(int index) const {
	return Matches[index].WardDestroyed;
}
int Stats::getFirstBlood(int index) const {
	return Matches[index].FirstBlood;
}
int Stats::getKills(int index) const {
	return Matches[index].Kills;
}
int Stats::getFirstInhibitor(int index) const {
	return Matches[index].FirstInhibitor;
}
int Stats::getInhibitors(int index) const {
	return Matches[index].Inhibitors;
}
int Stats::getHeralds(int index) const {
	return Matches[index].Heralds;
}
int Stats::getFirstBaron(int index) const {
	return Matches[index].FirstBaron;
}
int Stats::getBarons(int index) const {
	return Matches[index].Barons;
}

int Stats::getSize() const {
	return Matches.size();
}




void stats::AddMatch(int win, int wardplaced, int warddestroyed, int firstblood, int Kills, int EliteMonsters, int Dragons,
	int Heralds, int TowersDestroyed, int Gold, int Exp, int MinionsKilled, int JungleMinionsKilled){
	Matches.push_back({ win, wardplaced, warddestroyed, firstblood, Kills, EliteMonsters, Dragons, Heralds, TowersDestroyed, Gold,
		Exp, MinionsKilled, JungleMinionsKilled });
}
int stats::getWin(int index) const {
	return Matches[index].Win;
}
int stats::getWardPlaced(int index) const {
	return Matches[index].WardPlaced;
}
int stats::getWardDestroyed(int index) const {
	return Matches[index].WardDestroyed;
}
int stats::getFirstBlood(int index) const {
	return Matches[index].FirstBlood;
}
int stats::getKills(int index) const {
	return Matches[index].Kills;
}
int stats::getEliteMonsters(int index) const {
	return Matches[index].EliteMonsters;
}
int stats::getDragons(int index) const {
	return Matches[index].Dragons;
}
int stats::getHeralds(int index) const {
	return Matches[index].Heralds;
}
int stats::getTowersDestroyed(int index) const {
	return Matches[index].TowersDestroyed;
}
int stats::getGold(int index) const {
	return Matches[index].Gold;
}
int stats::getExp(int index) const {
	return Matches[index].Exp;
}	
int stats::getMinions(int index) const {
	return Matches[index].MinionsKilled;
}
int stats::getJungleMinions(int index) const {
	return Matches[index].JungleMinionsKilled;
}
int stats::getSize() const {
	return Matches.size();
}
