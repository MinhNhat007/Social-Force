#ifndef XMLINITIALIZER_H
#define XMLINITIALIZER_H

#include <iostream>
#include <string>
#include <regex>
#include <map>
#include "SocialForce.h"

using namespace std;

class XMLInitializer
{
public:
	const static regex wpRegex;
	const static regex idRegex;
	const static regex xRegex;
	const static regex x1Regex;
	const static regex x2Regex;
	const static regex yRegex;
	const static regex y1Regex;
	const static regex y2Regex;
	const static regex rRegex;
	const static regex obstacleRegex;
	const static regex addwaypointRegex;
	const static regex agentRegex;
	const static regex scenarioRegex;
	const static regex nRegex;
	const static regex dxRegex;
	const static regex dyRegex;

	static SocialForce initSocialForce(string fileName);

private:
	static void initObstacles(string content, SocialForce* sf);
	static Wall initWall(string content);
	static map<int, WayPoint*> initWayPoints(string content);
	static WayPoint* initSingleWayPoint(string content);
	static void initAgents(string content, SocialForce* sf, map<int,WayPoint*> wp);
	static void initSingleAgent(string content, SocialForce* sf, map<int,WayPoint*> wp);
	static int getAddWpID(string content);
	XMLInitializer() {}
};

#endif