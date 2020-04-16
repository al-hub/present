#include <stdio.h>


struct PLAYER_H{
    int info;
     //public API
    void (*cb)(const char *);
};


void A(const char *str)
{    printf("A: %s\n",str);    return; }

void B(const char *str)
{    printf("B: %s\n",str);    return; }


void  set_callback(PLAYER_H *player, void (*func)(const char *))
{
    player->cb = func;
}


void (*myCB)(const char *);
void public_cb(const char *str)
{
    myCB("modified");
}


void product_decoded_cb(PLAYER_H *player, void (*product_cb)(const char *) )
{

//이슈상황
      myCB=product_cb;


      set_callback(player, public_cb); //public API

      
//기존
//    set_callback(player, product_cb);
}



int main()
{

    PLAYER_H *player = new PLAYER_H[2];


    product_decoded_cb(&player[0], A);
    product_decoded_cb(&player[1], B);


//    player->cb("product callback");
    player[0].cb("product callback");
    player[1].cb("product callback");


    delete player;

    return 0;
}


