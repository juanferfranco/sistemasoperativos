#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct point2{
    struct point p;
    float f1;
    float f2;
}


struct point{
    int x;
    int y;
};

void pointConst(struct point *this,int,int);
void printPoint(struct point *this);



void printPointByValue(struct point st);

struct point pGlobal;

int main(void){
    struct point p1;
    pointConst(&p1, 1, 2);
    printPoint(&p1);
    //printPointByValue(p1);
    printPoint(&p1);

    struct point *pPoint = malloc(sizeof(struct point) * 1);
    pointConst(pPoint , 10, 20);
    printPoint(pPoint);

    pointConst(&pGlobal, 30, 40);
    printPoint(&pGlobal);

    return EXIT_SUCCESS;
}

void printPoint(struct point *this){
    printf("x:%d,y:%d\n",this->x,this->y);
    this->x = 3;
    this->y = 4;
}

void printPointByValue(struct point st){
    printf("x:%d,y:%d\n",st.x,st.y);

}

void pointConst(struct point *this, int _x,int _y){
    this->x = _x;
    this->y = _y;
}