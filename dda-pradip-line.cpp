#include<graphics.h>
#include<conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2;
    printf("Enter x1, y1, x2, y2: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    float x_increment = (float)dx / (float)steps;
    float y_increment = (float)dy / (float)steps;
    float x = x1, y = y1;

    for (int i = 0; i < steps; i++) {
        x = x + x_increment;
        y = y + y_increment;
        putpixel((int)x, (int)y, WHITE);
    }

    delay(20000);
    closegraph();
    return 0;
}
