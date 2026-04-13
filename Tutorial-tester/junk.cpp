#include <iostream>
using namespace std;


void xyz (int *ptr){
    *ptr = 30;
}
int main(){

    int y = 20;
    xyz(&y);
    printf("%d", y);
                                                    
    return 0;
}
