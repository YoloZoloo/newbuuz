#include<stdio.h>
#include <ApplicationServices/ApplicationServices.h>

int keyIsPressed(CGEventFlags flag, CGEventFlags mask) {
    if ((flag & mask) == mask) {
        return 1;
    }
    return 0;
}