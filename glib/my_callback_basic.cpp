#include <stdio.h>


struct PLAYER_H{
    int info;
    void (*cb)(const char *);
};


void A(const char *str)
{    printf("A: %s\n",str);    return; }

void B(const char *str)
{    printf("B: %s\n",str);    return; }


void (*myCB)(const char *);
void  set_callback(PLAYER_H *player, void (*func)(const char *))
{
    myCB=func;
    player->cb = func;
}


int main()
{

    PLAYER_H* player = new PLAYER_H;

    set_callback(player, A);
    set_callback(player, B);

    player->cb("call by player->cb");
    myCB("call by myCB");

    delete player;

    return 0;
}


