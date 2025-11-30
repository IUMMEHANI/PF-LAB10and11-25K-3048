#include <stdio.h>
#define FACTOR 0.001
float Kilometers(float meters) {
    static int Count = 0;  
    Count++;
    printf("Function called %d time\n",Count);
    float km = meters * FACTOR;
    return km;
}
int main() {
    float meters;
    printf("Enter value in meters: ");
    scanf("%f", &meters);
    float km = Kilometers(meters);
    printf("%.2f meters = %.3f kilometers\n", meters, km);
    km =Kilometers(5000);
    printf("5000 meters = %.3f kilometers\n", km);
    return 0;
}

