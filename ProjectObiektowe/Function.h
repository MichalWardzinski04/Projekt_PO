#pragma once
#include<iostream>
#include<fstream> //zapis i odczyt pliku
#include<string> //getline
#include<sstream>//stringstream
#include<iostream>
#include"Stats.h"


int  ReadData(Stats& team1, Stats& team2, string plik);

void AvgTime(Stats& team);

void AvgWinGold(Stats& team1, Stats& team2);

void AvgWinExp(Stats& team1, Stats& team2);

void AvgWinWardPlaced(Stats& team1, Stats& team2);

void AvgWinWardDestroyed(Stats& team1, Stats& team2);

void AvgWinFirstBlood(Stats& team1, Stats& team2);

void AvgWinKill(Stats& team1, Stats& team2);

void AvgWinFirstInhibitor(Stats& team1, Stats& team2);

void AvgWinInhibitor(Stats& team1, Stats& team2);

void AvgWinHeralds(Stats& team1, Stats& team2);

void AvgWinFirstBaron(Stats& team1, Stats& team2);

void AvgWinBarons(Stats& team1, Stats& team2);






int  ReadData(stats& team1, stats& team2, string plik);

void AvgWinGold(stats& team1, stats& team2);

void AvgWinExp(stats& team1, stats& team2);

void AvgWinWardPlaced(stats& team1, stats& team2);

void AvgWinWardDestroyed(stats& team1, stats& team2);

void AvgWinFirstBlood(stats& team1, stats& team2);

void AvgWinKill(stats& team1, stats& team2);

void AvgWinEliteMonsters(stats& team1, stats& team2);

void AvgWinDragons(stats& team1, stats& team2);

void AvgWinHeralds(stats& team1, stats& team2);

void AvgWinTowersDestroyed(stats& team1, stats& team2);

void AvgWinMinions(stats& team1, stats& team2);

void AvgWinJungleMinions(stats& team1, stats& team2);
