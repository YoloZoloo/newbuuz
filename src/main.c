#include <stdio.h>
#include <ApplicationServices/ApplicationServices.h>
#ifndef Q_KEY
    #include "characters.h"
#endif
#ifndef keyIsPressed
    #include "utils.c"
#endif

#define MY_KEYBOARD 93 //Customizable value

UniChar *bufferOfSizeOne;

CGEventRef myCGEventCallback(CGEventTapProxy proxy, CGEventType type,
    CGEventRef event, void *refcon) 
{
    int keyboard = 0;
    if ((type != kCGEventKeyDown) && (type != kCGEventKeyUp))
        return event;

    keyboard = CGEventGetIntegerValueField(event, kCGKeyboardEventKeyboardType);

    if (keyboard != MY_KEYBOARD) {
        return event;
    }

    int input = CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);
    UniChar* inputUniStr = malloc(sizeof(CYRILLIC_OU));

    int ret = setInputUniChar(event, input, inputUniStr, bufferOfSizeOne);
    if (ret == 0) {
        CGEventKeyboardSetUnicodeString(event, 1, inputUniStr);
    }
    free(inputUniStr);
    
    return event;
}


int main(int argc, char* argv[]) {
    CFMachPortRef      eventTap;
    CGEventMask        eventMask;
    CFRunLoopSourceRef runLoopSource;

    // Create an event tap. We are interested in key presses.
    eventMask = ((1 << kCGEventKeyDown) | (1 << kCGEventKeyUp));
    eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0,
            eventMask, myCGEventCallback, NULL);
    if (!eventTap) {
        fprintf(stderr, "failed to create event tap\n");
        exit(1);
    }

    bufferOfSizeOne = malloc(sizeof(CYRILLIC_A));

    if (bufferOfSizeOne == NULL) {
        fprintf(stderr, "failed to allocate memory\n");
        exit(1);
    }

    // Create a run loop source.
    runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);

    // Add to the current run loop.
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);

    // Enable the event tap.
    CGEventTapEnable(eventTap, true);

    // Set it all running.
    CFRunLoopRun();
    return 0;
}