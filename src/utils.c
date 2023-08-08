#include<stdio.h>
#include "characters.h"
#include <ApplicationServices/ApplicationServices.h>

int keyIsPressed(CGEventFlags flag, CGEventFlags mask) {
    if ((flag & mask) == mask) {
        return 1;
    }
    return 0;
}

int setInputUniChar(CGEventRef event, int input, UniChar *uniStr, UniChar* buffer) {
    CGEventFlags flag = CGEventGetFlags(event);
    int commandKeyIsPressed = keyIsPressed(flag, kCGEventFlagMaskCommand);
    int controlKeyIsPressed = keyIsPressed(flag, kCGEventFlagMaskControl);
    int shiftKeyIsPressed = keyIsPressed(flag, kCGEventFlagMaskShift);
    if(controlKeyIsPressed == 1 || commandKeyIsPressed == 1) {
        CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t) input);
        return 1;
    }
    if (shiftKeyIsPressed == 1) {
        switch(input) {
            case Q_KEY:
                *uniStr=CYRILLIC_OU;
                break;
            case W_KEY:
                switch(*buffer){
                    case Y_KEY:
                        *uniStr=CYRILLIC_YU;
                        break;
                    default:
                        *uniStr=CYRILLIC_W;
                        break;
                }
                break;
            case E_KEY:
                switch(*buffer){
                    case Y_KEY:
                        *uniStr=CYRILLIC_YE;
                        break;
                    default:
                        *uniStr=CYRILLIC_E;
                        break;
                }
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
                switch(*buffer){
                    case Y_KEY:
                        *uniStr=CYRILLIC_YU;
                        break;
                    default:
                        *uniStr=CYRILLIC_U;
                        break;
                }
                break;
            case I_KEY:
                switch(*buffer){
                    case A_KEY:
                        *uniStr=CYRILLIC_II;
                        break;
                    case E_KEY:
                        *uniStr=CYRILLIC_II;
                        break;
                    case I_KEY:
                        *uniStr=CYRILLIC_II;
                        break;
                    case O_KEY:
                        *uniStr=CYRILLIC_II;
                        break;
                    case U_KEY:
                        *uniStr=CYRILLIC_II;
                        break;
                    case Q_KEY:
                        *uniStr=CYRILLIC_II;
                        break;
                    case W_KEY:
                        *uniStr=CYRILLIC_II;
                        break;
                    default:
                        *uniStr=CYRILLIC_I;
                        break;
                }
                break;
            case O_KEY:
                switch(*buffer){
                    case Y_KEY:
                        *uniStr=CYRILLIC_YO;
                        break;
                    default:
                        *uniStr=CYRILLIC_O;
                        break;
                }
                break;
            case P_KEY:
                *uniStr=CYRILLIC_P;
                break;
            case A_KEY:
                switch(*buffer){
                    case Y_KEY:
                        *uniStr=CYRILLIC_YA;
                        break;
                    default:
                        *uniStr=CYRILLIC_A;
                        break;
                }
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
                switch(*buffer){
                    case S_KEY:
                        *uniStr=CYRILLIC_SH;
                        break;
                    case C_KEY:
                        *uniStr=CYRILLIC_CH;
                        break;
                    default:
                        *uniStr=CYRILLIC_X;
                        break;
                }
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
                switch(*buffer){
                    case S_KEY:
                        *uniStr=CYRILLIC_SCH;
                        break;
                    default:
                        *uniStr=CYRILLIC_C;
                        break;
                }
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
                return 1;
        }
    } else {
        switch(input) {
            case Q_KEY:
                *uniStr=CYRILLIC_ou;
                break; 
            case W_KEY:
                switch(*buffer){
                    case Y_KEY:
                        *uniStr=CYRILLIC_yu;
                        break;
                    default:
                        *uniStr=CYRILLIC_w;
                        break;
                }
                break;
            case E_KEY:
                switch(*buffer){
                    case Y_KEY:
                        *uniStr=CYRILLIC_ye;
                        break;
                    default:
                        *uniStr=CYRILLIC_e;
                        break;
                }
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
                switch(*buffer){
                    case Y_KEY:
                        *uniStr=CYRILLIC_yu;
                        break;
                    default:
                        *uniStr=CYRILLIC_u;
                        break;
                }
                break;
            case I_KEY:
                switch(*buffer){
                    case A_KEY:
                        *uniStr=CYRILLIC_ii;
                        break;
                    case E_KEY:
                        *uniStr=CYRILLIC_ii;
                        break;
                    case I_KEY:
                        *uniStr=CYRILLIC_ii;
                        break;
                    case O_KEY:
                        *uniStr=CYRILLIC_ii;
                        break;
                    case U_KEY:
                        *uniStr=CYRILLIC_ii;
                        break;
                    case Q_KEY:
                        *uniStr=CYRILLIC_ii;
                        break;
                    case W_KEY:
                        *uniStr=CYRILLIC_ii;
                        break;
                    default:
                        *uniStr=CYRILLIC_i;
                        break;
                }
                break;
            case O_KEY:
                switch(*buffer){
                    case Y_KEY:
                        *uniStr=CYRILLIC_yo;
                        break;
                    default:
                        *uniStr=CYRILLIC_o;
                        break;
                }
                break;
            case P_KEY:
                *uniStr=CYRILLIC_p;
                break;
            case A_KEY:
                switch(*buffer){
                    case Y_KEY:
                        *uniStr=CYRILLIC_ya;
                        break;
                    default:
                        *uniStr=CYRILLIC_a;
                        break;
                }
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
                switch(*buffer){
                    case S_KEY:
                        *uniStr=CYRILLIC_sh;
                        break;
                    case C_KEY:
                        *uniStr=CYRILLIC_ch;
                        break;
                    default:
                        *uniStr=CYRILLIC_x;
                        break;
                }
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
                switch(*buffer){
                    case S_KEY:
                        *uniStr=CYRILLIC_sch;
                        break;
                    default:
                         *uniStr=CYRILLIC_c;
                        break;
                }
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
                return 1;
        }
    }
    *buffer=input;
    return 0;
}