#ifndef __MOVE_POSITION__
#define __MOVE_POSITION__

typedef struct coordinates_s
{
    int x;
    int y;
} coordinates;

enum DIRECTOR_OPT {
    UP       = 1,
    DOWN     = 2,
    LEFT     = 3,
    RIGHT    = 4,
    UNDEFINE
};

coordinates Selection(coordinates &coor);

#endif // __MOVE_POSITION__