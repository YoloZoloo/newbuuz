#include <stdio.h>
#include <ApplicationServices/ApplicationServices.h>
#include "characters.h"
#include "functions.c"


#define MY_KEYBOARD 93

CGEventRef myCGEventCallback(CGEventTapProxy proxy, CGEventType type,
    CGEventRef event, void *refcon) 
{
    int keyboard = 0;
    // Paranoid sanity check.
    if ((type != kCGEventKeyDown) && (type != kCGEventKeyUp))
        return event;

    keyboard = CGEventGetIntegerValueField(event, kCGKeyboardEventKeyboardType);

    // if you found your keyboard-value...
    if (keyboard != MY_KEYBOARD) {
        return event;
    }

    int input = CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);
    CGEventFlags flag = CGEventGetFlags(event);
    int commandKeyIsPressed = keyIsPressed(flag, kCGEventFlagMaskCommand);
    int shiftKeyIsPressed = keyIsPressed(flag, kCGEventFlagMaskShift);
    UniChar* uniStr = malloc(sizeof(CYRILLIC_OU));

    // printf("shift %d\n", shiftKeyIsPressed);
    if (shiftKeyIsPressed == 1) {
        switch(input) {
            case Q_KEY:
                *uniStr=CYRILLIC_OU;
                break; 
            case W_KEY:
                *uniStr=CYRILLIC_W;
                break;
            case E_KEY:
                *uniStr=CYRILLIC_E;
                break;
            case R_KEY:
                *uniStr=CYRILLIC_R;
                break;
            case T_KEY:
                *uniStr=CYRILLIC_T;
                break;
            case Y_KEY:
                *uniStr=CYRILLIC_Y;
                break;
            case U_KEY:
                *uniStr=CYRILLIC_U;
                break;
            case I_KEY:
                *uniStr=CYRILLIC_I;
                break;
            case O_KEY:
                *uniStr=CYRILLIC_O;
                break;
            case P_KEY:
                *uniStr=CYRILLIC_P;
                break;
            case A_KEY:
                *uniStr=CYRILLIC_A;
                break;
            case S_KEY:
                *uniStr=CYRILLIC_S;
                break;
            case D_KEY:
                *uniStr=CYRILLIC_D;
                break;
            case F_KEY:
                *uniStr=CYRILLIC_F;
                break;
            case G_KEY:
                *uniStr=CYRILLIC_G;
                break;
            case H_KEY:
                *uniStr=CYRILLIC_X;
                break;
            case J_KEY:
                *uniStr=CYRILLIC_J;
                break;
            case K_KEY:
                *uniStr=CYRILLIC_K;
                break;
            case L_KEY:
                *uniStr=CYRILLIC_L;
                break;
            case Z_KEY:
                *uniStr=CYRILLIC_Z;
                break;
            case X_KEY:
                *uniStr=CYRILLIC_X;
                break;
            case C_KEY:
                *uniStr=CYRILLIC_C;
                break;
            case V_KEY:
                *uniStr=CYRILLIC_V;
                break;
            case B_KEY:
                *uniStr=CYRILLIC_B;
                break;
            case N_KEY:
                *uniStr=CYRILLIC_N;
                break;
            case M_KEY:
                *uniStr=CYRILLIC_M;
                break;
            case ZUULNII_TEMDEG_MARK:
                *uniStr=CYRILLIC_zt;
                break;
            case HATUUGIIN_TEMDEG_MARK:
                *uniStr=CYRILLIC_xt;
                break;
            default:
                CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t) input);
                break;
        }
    } else {
        switch(input) {
            case Q_KEY:
                *uniStr=CYRILLIC_ou;
                break; 
            case W_KEY:
                *uniStr=CYRILLIC_w;
                break;
            case E_KEY:
                *uniStr=CYRILLIC_e;
                break;
            case R_KEY:
                *uniStr=CYRILLIC_r;
                break;
            case T_KEY:
                *uniStr=CYRILLIC_t;
                break;
            case Y_KEY:
                *uniStr=CYRILLIC_y;
                break;
            case U_KEY:
                *uniStr=CYRILLIC_u;
                break;
            case I_KEY:
                *uniStr=CYRILLIC_i;
                break;
            case O_KEY:
                *uniStr=CYRILLIC_o;
                break;
            case P_KEY:
                *uniStr=CYRILLIC_p;
                break;
            case A_KEY:
                *uniStr=CYRILLIC_a;
                break;
            case S_KEY:
                *uniStr=CYRILLIC_s;
                break;
            case D_KEY:
                *uniStr=CYRILLIC_d;
                break;
            case F_KEY:
                *uniStr=CYRILLIC_f;
                break;
            case G_KEY:
                *uniStr=CYRILLIC_g;
                break;
            case H_KEY:
                *uniStr=CYRILLIC_x;
                break;
            case J_KEY:
                *uniStr=CYRILLIC_j;
                break;
            case K_KEY:
                *uniStr=CYRILLIC_k;
                break;
            case L_KEY:
                *uniStr=CYRILLIC_l;
                break;
            case Z_KEY:
                *uniStr=CYRILLIC_z;
                break;
            case X_KEY:
                *uniStr=CYRILLIC_x;
                break;
            case C_KEY:
                *uniStr=CYRILLIC_c;
                break;
            case V_KEY:
                *uniStr=CYRILLIC_v;
                break;
            case B_KEY:
                *uniStr=CYRILLIC_b;
                break;
            case N_KEY:
                *uniStr=CYRILLIC_n;
                break;
            case M_KEY:
                *uniStr=CYRILLIC_m;
                break;
            case ZUULNII_TEMDEG_MARK:
                *uniStr=CYRILLIC_zt;
                break;
            case HATUUGIIN_TEMDEG_MARK:
                *uniStr=CYRILLIC_xt;
                break;
            default:
                CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t) input);
                free(uniStr);
                uniStr=NULL;
                break;
        }
    }
    // printf(" - input value: %d\n", input);
    // CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t) input);
    if (uniStr!=NULL) {
        CGEventKeyboardSetUnicodeString(event, 1, uniStr);
        free(uniStr);
    }
    
    // We must return the event for it to be useful.
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