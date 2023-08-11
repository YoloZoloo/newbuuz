#include<stdio.h>
#ifndef Q_KEY
    #include "newbuuz.h"
#endif
#include <ApplicationServices/ApplicationServices.h>


int setInputUniChar(CGEventRef event, input_ctx *ctx);

int keyIsPressed(CGEventFlags flag, CGEventFlags mask) {
    if ((flag & mask) == mask) {
        return 1;
    }
    return 0;
}

int setInputUniChar(CGEventRef event, input_ctx *ctx) {
    CGEventFlags flag = CGEventGetFlags(event);
    int commandKeyIsPressed = keyIsPressed(flag, kCGEventFlagMaskCommand);
    int controlKeyIsPressed = keyIsPressed(flag, kCGEventFlagMaskControl);
    int shiftKeyIsPressed = keyIsPressed(flag, kCGEventFlagMaskShift);
    int fnKeyIsPressed = keyIsPressed(flag, kCGEventFlagMaskSecondaryFn);
    if (fnKeyIsPressed == 1 && shiftKeyIsPressed == 1 && 
        ctx->inputInt == 49 )
    {
        ctx->boardSwitch = -ctx->boardSwitch;
        if (ctx->boardSwitch > 0) {
            printf("Mongolian Keyboard is in use\n");
        } else {
            printf("The other keyboard is in use\n");
        }
        return 1;
    }
    if (ctx->boardSwitch < 0) {
        CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t) ctx->inputInt);
        return 1;
    }
    if(controlKeyIsPressed == 1 || commandKeyIsPressed == 1) {
        CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t) ctx->inputInt);
        return 1;
    }
    if (shiftKeyIsPressed == 1) {
        switch(ctx->inputInt) {
            case Q_KEY:
                *ctx->inputChar=CYRILLIC_OU;
                break;
            case W_KEY:
                switch(ctx->buffer){
                    case Y_KEY:
                        *ctx->inputChar=CYRILLIC_YU;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_W;
                        break;
                }
                break;
            case E_KEY:
                switch(ctx->buffer){
                    case Y_KEY:
                        *ctx->inputChar=CYRILLIC_YE;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_E;
                        break;
                }
                break;
            case R_KEY:
                *ctx->inputChar=CYRILLIC_R;
                break;
            case T_KEY:
                *ctx->inputChar=CYRILLIC_T;
                break;
            case Y_KEY:
                *ctx->inputChar=CYRILLIC_Y;
                break;
            case U_KEY:
                switch(ctx->buffer){
                    case Y_KEY:
                        *ctx->inputChar=CYRILLIC_YU;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_U;
                        break;
                }
                break;
            case I_KEY:
                switch(ctx->buffer){
                    case A_KEY:
                        *ctx->inputChar=CYRILLIC_II;
                        break;
                    case E_KEY:
                        *ctx->inputChar=CYRILLIC_II;
                        break;
                    case I_KEY:
                        *ctx->inputChar=CYRILLIC_II;
                        break;
                    case O_KEY:
                        *ctx->inputChar=CYRILLIC_II;
                        break;
                    case U_KEY:
                        *ctx->inputChar=CYRILLIC_II;
                        break;
                    case Q_KEY:
                        *ctx->inputChar=CYRILLIC_II;
                        break;
                    case W_KEY:
                        *ctx->inputChar=CYRILLIC_II;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_I;
                        break;
                }
                break;
            case O_KEY:
                switch(ctx->buffer){
                    case Y_KEY:
                        *ctx->inputChar=CYRILLIC_YO;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_O;
                        break;
                }
                break;
            case P_KEY:
                *ctx->inputChar=CYRILLIC_P;
                break;
            case A_KEY:
                switch(ctx->buffer){
                    case Y_KEY:
                        *ctx->inputChar=CYRILLIC_YA;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_A;
                        break;
                }
                break;
            case S_KEY:
                *ctx->inputChar=CYRILLIC_S;
                break;
            case D_KEY:
                *ctx->inputChar=CYRILLIC_D;
                break;
            case F_KEY:
                *ctx->inputChar=CYRILLIC_F;
                break;
            case G_KEY:
                *ctx->inputChar=CYRILLIC_G;
                break;
            case H_KEY:
                switch(ctx->buffer){
                    case S_KEY:
                        *ctx->inputChar=CYRILLIC_SH;
                        break;
                    case C_KEY:
                        *ctx->inputChar=CYRILLIC_CH;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_X;
                        break;
                }
                break;
            case J_KEY:
                *ctx->inputChar=CYRILLIC_J;
                break;
            case K_KEY:
                *ctx->inputChar=CYRILLIC_K;
                break;
            case L_KEY:
                *ctx->inputChar=CYRILLIC_L;
                break;
            case Z_KEY:
                *ctx->inputChar=CYRILLIC_Z;
                break;
            case X_KEY:
                *ctx->inputChar=CYRILLIC_X;
                break;
            case C_KEY:
                switch(ctx->buffer){
                    case S_KEY:
                        *ctx->inputChar=CYRILLIC_SCH;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_C;
                        break;
                }
                break;
            case V_KEY:
                *ctx->inputChar=CYRILLIC_V;
                break;
            case B_KEY:
                *ctx->inputChar=CYRILLIC_B;
                break;
            case N_KEY:
                *ctx->inputChar=CYRILLIC_N;
                break;
            case M_KEY:
                *ctx->inputChar=CYRILLIC_M;
                break;
            case ZUULNII_TEMDEG_MARK:
                *ctx->inputChar=CYRILLIC_zt;
                break;
            case HATUUGIIN_TEMDEG_MARK:
                *ctx->inputChar=CYRILLIC_xt;
                break;
            default:
                CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t) ctx->inputInt);
                return 1;
        }
    } else {
        switch(ctx->inputInt) {
            case Q_KEY:
                *(ctx->inputChar)=CYRILLIC_ou;
                break; 
            case W_KEY:
                switch(ctx->buffer){
                    case Y_KEY:
                        *ctx->inputChar=CYRILLIC_yu;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_w;
                        break;
                }
                break;
            case E_KEY:
                switch(ctx->buffer){
                    case Y_KEY:
                        *ctx->inputChar=CYRILLIC_ye;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_e;
                        break;
                }
                break;
            case R_KEY:
                *ctx->inputChar=CYRILLIC_r;
                break;
            case T_KEY:
                *ctx->inputChar=CYRILLIC_t;
                break;
            case Y_KEY:
                *ctx->inputChar=CYRILLIC_y;
                break;
            case U_KEY:
                switch(ctx->buffer){
                    case Y_KEY:
                        *ctx->inputChar=CYRILLIC_yu;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_u;
                        break;
                }
                break;
            case I_KEY:
                switch(ctx->buffer){
                    case A_KEY:
                        *ctx->inputChar=CYRILLIC_ii;
                        break;
                    case E_KEY:
                        *ctx->inputChar=CYRILLIC_ii;
                        break;
                    case I_KEY:
                        *ctx->inputChar=CYRILLIC_ii;
                        break;
                    case O_KEY:
                        *ctx->inputChar=CYRILLIC_ii;
                        break;
                    case U_KEY:
                        *ctx->inputChar=CYRILLIC_ii;
                        break;
                    case Q_KEY:
                        *ctx->inputChar=CYRILLIC_ii;
                        break;
                    case W_KEY:
                        *ctx->inputChar=CYRILLIC_ii;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_i;
                        break;
                }
                break;
            case O_KEY:
                switch(ctx->buffer){
                    case Y_KEY:
                        *ctx->inputChar=CYRILLIC_yo;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_o;
                        break;
                }
                break;
            case P_KEY:
                *ctx->inputChar=CYRILLIC_p;
                break;
            case A_KEY:
                switch(ctx->buffer){
                    case Y_KEY:
                        *ctx->inputChar=CYRILLIC_ya;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_a;
                        break;
                }
                break;
            case S_KEY:
                *ctx->inputChar=CYRILLIC_s;
                break;
            case D_KEY:
                *ctx->inputChar=CYRILLIC_d;
                break;
            case F_KEY:
                *ctx->inputChar=CYRILLIC_f;
                break;
            case G_KEY:
                *ctx->inputChar=CYRILLIC_g;
                break;
            case H_KEY:
                switch(ctx->buffer){
                    case S_KEY:
                        *ctx->inputChar=CYRILLIC_sh;
                        break;
                    case C_KEY:
                        *ctx->inputChar=CYRILLIC_ch;
                        break;
                    default:
                        *ctx->inputChar=CYRILLIC_x;
                        break;
                }
                break;
            case J_KEY:
                *ctx->inputChar=CYRILLIC_j;
                break;
            case K_KEY:
                *ctx->inputChar=CYRILLIC_k;
                break;
            case L_KEY:
                *ctx->inputChar=CYRILLIC_l;
                break;
            case Z_KEY:
                *ctx->inputChar=CYRILLIC_z;
                break;
            case X_KEY:
                *ctx->inputChar=CYRILLIC_x;
                break;
            case C_KEY:
                switch(ctx->buffer){
                    case S_KEY:
                        *ctx->inputChar=CYRILLIC_sch;
                        break;
                    default:
                         *ctx->inputChar=CYRILLIC_c;
                        break;
                }
                break;
            case V_KEY:
                *ctx->inputChar=CYRILLIC_v;
                break;
            case B_KEY:
                *ctx->inputChar=CYRILLIC_b;
                break;
            case N_KEY:
                *ctx->inputChar=CYRILLIC_n;
                break;
            case M_KEY:
                *ctx->inputChar=CYRILLIC_m;
                break;
            case ZUULNII_TEMDEG_MARK:
                *ctx->inputChar=CYRILLIC_zt;
                break;
            case HATUUGIIN_TEMDEG_MARK:
                *ctx->inputChar=CYRILLIC_xt;
                break;
            default:
                CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, (int64_t) ctx->inputInt);
                return 1;
        }
    }
    ctx->buffer=ctx->inputInt;
    return 0;
}