#include<iostream>
using namespace std;

struct Rect {
    double x, y, w, h;
};

/*double overlap(Rect *r1, Rect *r2) {
    Rect waifu ={0,0,0,0} ;
    if ((r1->x + r1->w) - r2->x > 0) {
        waifu.x = r1->x;
        waifu.w = (r1->x + r1->w) - r2->x;
        if ((r1->x + r1->w) > (r2->x + r2->w)) {
            waifu.x = r2->x;
            waifu.w = r2->w;
        }
    } else if ((r1->x + r1->w) - r2->x <= 0) {
        waifu.x = 0;
        waifu.w = 0;
    }
    if (r2->y - (r1->y - r1->h) > 0) {
        waifu.y = r1->y;
        waifu.h = r1->y - (r2->y - r2->h);
        if ((r1->y - r1->h) < (r2->y - r2->h) && (r1->y > r2->y)) {
            waifu.y = r2->y;
            waifu.h = r2->h;
        }
    } else if ((r1->x + r1->w) - r2->x <= 0) {
        waifu.y = 0;
        waifu.h = 0;
    }
    return (waifu.w) * (waifu.h);
}
*/
double overlap(Rect *r1, Rect *r2) {
    Rect waifu = {0, 0, 0, 0};
    waifu.w = max(0.0, min(r1->x + r1->w, r2->x + r2->w) - max(r1->x, r2->x));
    waifu.h = max(0.0, min(r1->y, r2->y) - max(r1->y - r1->h, r2->y - r2->h));
    
    return waifu.w * waifu.h;
}

int main(){
	Rect R1 = {1,1,5,5};
	Rect R2 = {2,2,5,5};	
	cout << overlap(&R1,&R2);	
}