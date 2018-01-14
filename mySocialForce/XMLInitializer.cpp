#include "XMLInitializer.h"
#include <fstream>
#include <deque>


const regex XMLInitializer::wpRegex = regex("<waypoint[^/]+/>");
const regex XMLInitializer::idRegex = regex("id *= *\"([0-9]+)\"");
const regex XMLInitializer::xRegex = regex("x *= *\"(-?[0-9]+(\\.[0-9]+)?)\"");
const regex XMLInitializer::yRegex = regex("y *= *\"(-?[0-9]+(\\.[0-9]+)?)\"");
const regex XMLInitializer::x1Regex = regex("x1 *= *\"(-?[0-9]+(\\.[0-9]+)?)\"");
const regex XMLInitializer::y1Regex = regex("y1 *= *\"(-?[0-9]+(\\.[0-9]+)?)\"");
const regex XMLInitializer::x2Regex = regex("x2 *= *\"(-?[0-9]+(\\.[0-9]+)?)\"");
const regex XMLInitializer::y2Regex = regex("y2 *= *\"(-?[0-9]+(\\.[0-9]+)?)\"");
const regex XMLInitializer::rRegex = regex("r *= *\"([0-9]+(\\.[0-9]+)?)\"");
const regex XMLInitializer::obstacleRegex = regex("<obstacle[^/]+/>");
const regex XMLInitializer::addwaypointRegex = regex("<addwaypoint[^/]+/>");
const regex XMLInitializer::agentRegex = regex("<agent[\\S\\s]+?</agent>");
const regex XMLInitializer::scenarioRegex = regex("<scenario>[\\S\\s]+?</scenario>");
const regex XMLInitializer::nRegex = regex("n *= *\"([0-9]+)\"");
const regex XMLInitializer::dxRegex = regex("dx *= *\"([0-9]+(\\.[0-9]+)?)\"");
const regex XMLInitializer::dyRegex = regex("dy *= *\"([0-9]+(\\.[0-9]+)?)\"");

SocialForce XMLInitializer::initSocialForce(string fileName) {
	ifstream ifs(fileName);
	string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	SocialForce sf;
	smatch m;

	if (regex_search(content, m, scenarioRegex)) {
		string scenarioString = m[0];

		initObstacles(scenarioString, &sf);
		map<int, WayPoint*> wp = initWayPoints(scenarioString);
		initAgents(scenarioString, &sf, wp);

	}

	return sf;
}

void XMLInitializer::initObstacles(string content, SocialForce* sf) {
	smatch m;

	while (regex_search(content, m, obstacleRegex)) {
		sf->addWall(initWall(m[0]));
		content = m.suffix().str();
	}
}

Wall XMLInitializer::initWall(string content) {
	smatch m;
	float x1, x2, y1, y2;

	if (regex_search(content, m, x1Regex)) {
		 x1 = stof(m[1]);
	}
	if (regex_search(content, m, x2Regex)) {
		x2 = stof(m[1]);
	}
	if (regex_search(content, m, y1Regex)) {
		y1 = stof(m[1]);
	}
	if (regex_search(content, m, y2Regex)) {
		y2 = stof(m[1]);
	}

	return Wall(Line(Point(x1, y1), Point(x2, y2)));
}

map<int, WayPoint*> XMLInitializer::initWayPoints(string content) {
	map<int, WayPoint*> map;
	smatch m;
	WayPoint* tmpWp;

	while (regex_search(content, m, wpRegex)) {
		tmpWp = initSingleWayPoint(m[0]);
		map[tmpWp->getId()] = tmpWp;
		content = m.suffix().str();
	}

	return map;
}

WayPoint* XMLInitializer::initSingleWayPoint(string content) {
	smatch m;
	int id;
	float x, y, r;

	if (regex_search(content, m, idRegex)) {
		id = stoi(m[1]);
	}
	if (regex_search(content, m, xRegex)) {
		x = stof(m[1]);
	}
	if (regex_search(content, m, yRegex)) {
		y = stof(m[1]);
	}
	if (regex_search(content, m, rRegex)) {
		r = stof(m[1]);
	}

	return new WayPoint(id, x, y, r);
}

void XMLInitializer::initAgents(string content, SocialForce* sf, map<int, WayPoint*> wp) {
	smatch m;

	while (regex_search(content, m, agentRegex)) {
		initSingleAgent(m[0], sf, wp);
		content = m.suffix().str();
	}

}

void XMLInitializer::initSingleAgent(string content, SocialForce* sf, map<int, WayPoint*> wp) {
	smatch m;
	int n;
	float x, y, dx, dy;
	deque<int> wpIDs;
	string cont2;

	cont2.insert(0, content);

	while (regex_search(cont2, m, addwaypointRegex)) {
		wpIDs.push_back(getAddWpID(m[0]));
		cont2 = m.suffix().str();
	}

	if (regex_search(content, m, nRegex)) {
		n = stoi(m[1]);
	}
	if (regex_search(content, m, xRegex)) {
		x = stof(m[1]);
	}
	if (regex_search(content, m, yRegex)) {
		y = stof(m[1]);
	}
	if (regex_search(content, m, dxRegex)) {
		dx = stof(m[1]);
	}
	if (regex_search(content, m, dyRegex)) {
		dy = stof(m[1]);
	}

	for (int i = 0; i < n; i++) {
		float tmpX = SocialForce::randomFloat(x-dx, x+dx);
		float tmpY = SocialForce::randomFloat(y-dy, y+dy);

		Point currentPoint(tmpX, tmpY);
		Agent agent(currentPoint);

		for (auto it = wpIDs.begin(); it != wpIDs.end(); ++it)
			agent.addWayPoint(wp[*it]);

		sf->addAgent(agent);
	}
}

int XMLInitializer::getAddWpID(string content) {
	smatch m;
	int id;
	if (regex_search(content, m, idRegex)) {
		id = stoi(m[1]);
	}

	return id;
}