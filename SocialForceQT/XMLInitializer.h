#ifndef XMLINITIALIZER_H
#define XMLINITIALIZER_H

#include <iostream>
#include <string>
#include <regex>
#include <map>
#include "SocialForce.h"

using namespace std;

/**
 * @brief The XMLInitializer static class includes method to initialize Social force object from xml file
 */
class XMLInitializer
{
public:
    // regular expresions to find specific data
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

    /**
     * @brief initSocialForce static function initializing Social force object from file
     * @param fileName file name
     * @param isCorrect is set to true, if object was correctly initialized
     * @return social force object
     */
    static SocialForce initSocialForce(string fileName, bool* isCorrect);

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
