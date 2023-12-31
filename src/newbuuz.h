#include <stdio.h>
#include <ApplicationServices/ApplicationServices.h>

#define Q_KEY 12
#define W_KEY 13
#define E_KEY 14
#define R_KEY 15
#define T_KEY 17
#define Y_KEY 16
#define U_KEY 32
#define I_KEY 34
#define O_KEY 31
#define P_KEY 35
#define A_KEY 0
#define S_KEY 1
#define D_KEY 2
#define F_KEY 3
#define G_KEY 5
#define H_KEY 4
#define J_KEY 38
#define K_KEY 40
#define L_KEY 37
#define Z_KEY 6
#define X_KEY 7
#define C_KEY 8
#define V_KEY 9
#define B_KEY 11
#define N_KEY 45
#define M_KEY 46
#define SPACE_BAR_KEY 49
#define BACKSPACE_KEY 51
#define ZUULNII_TEMDEG_MARK 33
#define HATUUGIIN_TEMDEG_MARK 30

#define CYRILLIC_A L'А'
#define CYRILLIC_B L'Б'
#define CYRILLIC_V L'В'
#define CYRILLIC_G L'Г'
#define CYRILLIC_D L'Д'
#define CYRILLIC_YE L'Е'
#define CYRILLIC_YO L'Ё'
#define CYRILLIC_J L'Ж'
#define CYRILLIC_Z L'З'
#define CYRILLIC_I L'И'
#define CYRILLIC_II L'Й'
#define CYRILLIC_K L'К'
#define CYRILLIC_L L'Л'
#define CYRILLIC_M L'М'
#define CYRILLIC_N L'Н'
#define CYRILLIC_O L'О'
#define CYRILLIC_OU L'Ө'
#define CYRILLIC_P L'П'
#define CYRILLIC_R L'Р'
#define CYRILLIC_S L'С'
#define CYRILLIC_T L'Т'
#define CYRILLIC_U L'У'
#define CYRILLIC_W L'Ү'
#define CYRILLIC_F L'Ф'
#define CYRILLIC_X L'Х'
#define CYRILLIC_C L'Ц'
#define CYRILLIC_CH L'Ч'
#define CYRILLIC_SH L'Ш'
#define CYRILLIC_SCH L'Щ'
#define CYRILLIC_Y L'Ы'
#define CYRILLIC_ZT L'Ь'
#define CYRILLIC_E L'Э'
#define CYRILLIC_YU L'Ю'
#define CYRILLIC_YA L'Я'

#define CYRILLIC_a L'а'
#define CYRILLIC_b L'б'
#define CYRILLIC_v L'в'
#define CYRILLIC_g L'г'
#define CYRILLIC_d L'д'
#define CYRILLIC_ye L'е'
#define CYRILLIC_yo L'ё'
#define CYRILLIC_j L'ж'
#define CYRILLIC_z L'з'
#define CYRILLIC_i L'и'
#define CYRILLIC_ii L'й'
#define CYRILLIC_k L'к'
#define CYRILLIC_l L'л'
#define CYRILLIC_m L'м'
#define CYRILLIC_n L'н'
#define CYRILLIC_o L'о'
#define CYRILLIC_ou L'ө'
#define CYRILLIC_p L'п'
#define CYRILLIC_r L'р'
#define CYRILLIC_s L'с'
#define CYRILLIC_t L'т'
#define CYRILLIC_u L'у'
#define CYRILLIC_w L'ү'
#define CYRILLIC_f L'ф'
#define CYRILLIC_x L'х'
#define CYRILLIC_c L'ц'
#define CYRILLIC_ch L'ч'
#define CYRILLIC_sh L'ш'
#define CYRILLIC_sch L'щ'
#define CYRILLIC_y L'ы'
#define CYRILLIC_zt L'ь'
#define CYRILLIC_xt L'ъ'
#define CYRILLIC_e L'э'
#define CYRILLIC_yu L'ю'
#define CYRILLIC_ya L'я'


typedef struct keyboard_input_ctx {
    int buffer;
    UniChar* inputChar;
    int inputInt;
    int boardSwitch;
    int junctionLetter;
} input_ctx;