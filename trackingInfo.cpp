#include "Header.hpp"

using namespace std;

Maze::Maze():robot("wheel2 motor", "wheel1 motor",
	"distanceSensorFront", "distanceSensorLeft", "distanceSensorRight", "distanceSensorBack",
	"colourSensor", "LCam", "RCam", "inertialSensor", "gps", "lidarSensor")
{
	tracker = Tracker();
	
}

void Maze::insert_border(Border border, Direction dir)
{
	int x = tracker.curRow;
	int y = tracker.curCol;
	
	map[x][y].visited = true;
	switch (dir)
	{
	case Up:
		map[x][y].top = border;
		map[x][y - 1].bottom = border;
		return;
	case Left:
		map[x][y].left = border;
		map[x - 1][y].right = border;
		return;
	case Right:
		map[x][y].right = border;
		map[x + 1][y].left = border;
		return;
	case Down:
		map[x][y].bottom = border;
		map[x][y + 1].top = border;
		return;
	}
}

void Maze::update()
{
	Border left, right, up, down;
	if (robot.getDist(Up) < 12.0)
	{
		up = Wall;
	}
	else
	{
		up = Empty;
	}
	if (robot.getDist(Down) < 12.0)
	{
		down = Wall;
	}
	else
	{
		down = Empty;
	}
	if (robot.getDist(Left) < 12.0)
	{
		left = Wall;
	}
	else
	{
		left = Empty;
	}
	if (robot.getDist(Right) < 12.0)
	{
		right = Wall;
	}
	else
	{
		right = Empty;
	}

	insert_border(left, Left);
	insert_border(right, Right);
	insert_border(up, Up);
	insert_border(down, Down);

	cout << "Left: " << map[tracker.curRow][tracker.curCol].left << endl;
}

vector<Direction> Maze::BFS()
{
    return { Left };
}