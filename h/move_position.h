#ifndef __MOVE_POSITION__
#define __MOVE_POSITION__

typedef struct coordinates_s
{
	int x;
	int y;
}coordinates;

#define UP      1
#define DOWN    2
#define LEFT    3
#define RIGHT   4

coordinates Selection(coordinates &coor);

#endif // __MOVE_POSITION__