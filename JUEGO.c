

#define _XTAL_FREQ 20000000UL

#include <xc.h>
//#include <xc.h>
#include <string.h>
#include "flex_lcd.h"
#include <stdio.h>
#include "config.h"

#define ARRIBA PORTDbits.RD7
#define ABAJO PORTDbits.RD6
#define IZQUIERDA PORTDbits.RD5
#define DERECHA PORTDbits.RD4
#define PODER PORTDbits.RD3

#define TRIS_CONTROL TRISD

int valor_de_vidas;

int general_no_especifica;
int var_1;
int var_2;
int var_3;
int var_4;
int var_5;

int dato = 0XFF;

void vidas(int);
void clear(void);

void main(void) {
    valor_de_vidas = 0;
    TRISC = 0x00;
    TRIS_CONTROL = 0XFF;
    int r;
    TRISDbits.RD0 = 0;
    LATDbits.LD0 = 1;
    Lcd_Init();
    Lcd_Cmd(LCD_CLEAR);
    Lcd_Cmd(LCD_CURSOR_OFF);
    __delay_ms(50);
    // lcd_put_caracter(0x01,personaje);

    Lcd_Out(1, 0, "HOLA! Bienvenido");
    Lcd_Out(2, 2, "Jumper  ");

    Lcd_Chr_CP(8 + 0x30);

    __delay_ms(1000);

    Lcd_Cmd(LCD_CLEAR);

LEVEL1:

    r = 0xFC;
    Lcd_Out(1, 0, "Historia...");
    Lcd_Out(2, 2, "Empezar? S/N");

SENSA:
    if (PODER == 0) goto SENSA;

    Lcd_Cmd(LCD_CLEAR);

    Lcd_Out(1, 6, "OK");
    __delay_ms(1500);
    Lcd_Cmd(LCD_CLEAR);
    __delay_ms(1500);
    Lcd_Out(1, 0, "En alguna parte");
    Lcd_Out(2, 0, "del multiverso...");

    __delay_ms(1500);
    Lcd_Cmd(LCD_CLEAR);

    Lcd_Out(1, 0, "en un mundo");
    Lcd_Out(2, 0, "lleno de ceros ");

    __delay_ms(1500);
    Lcd_Cmd(LCD_CLEAR);

    Lcd_Out(1, 0, "00o0O0o0O00o00O00");
    Lcd_Out(2, 0, "00o0O00oO00o0O000");

    __delay_ms(1500);
    Lcd_Cmd(LCD_CLEAR);

    Lcd_Out(1, 0, "un 8 trendra que");
    Lcd_Out(2, 0, "sobrevivir!");

    __delay_ms(1500);

CINEMATICA:

    for (general_no_especifica = 0; general_no_especifica < 6; general_no_especifica++) {
        Lcd_Out2(2, general_no_especifica, "8");
        __delay_ms(250);
        if (general_no_especifica < 5) {
            Lcd_Cmd(LCD_CLEAR);
        } else {

        }
    }

    Lcd_Out(1, 6, "Soy 8!");
    __delay_ms(1500);
    Lcd_Cmd(LCD_CLEAR);

    Lcd_Out(2, 5, "8");

    for (general_no_especifica = 15; general_no_especifica >= 7; general_no_especifica--) {
        Lcd_Out(2, general_no_especifica, "0");
        __delay_ms(250);
    }

    Lcd_Out(1, 8, "Vete 8!!");
    __delay_ms(1000 / 2);

    for (general_no_especifica = 5; general_no_especifica >= 0; general_no_especifica--) {
        Lcd_Out(2, general_no_especifica, "8");
        __delay_ms(500);
        Lcd_Cmd(LCD_CLEAR);
    }
    Lcd_Out(2, 0, " ");

    Lcd_Cmd(LCD_CLEAR);

INICIO:


    var_1 = 2;
    var_2 = 0;
    var_3 = 0;

    Lcd_Out(1, 0, "Movamos a 8");
    Lcd_Out(2, 0, " <   >   v   ^");
    __delay_ms(2000);
    Lcd_Cmd(LCD_CLEAR);

    while (PODER == 0) {
        Lcd_Out(var_1, var_2, "8");

        if (ARRIBA == 1 && ABAJO == 0) {
            var_1 = 1;
            Lcd_Cmd(LCD_CLEAR);
        } else {
            if (ARRIBA == 0 && ABAJO == 1) {
                var_1 = 2;
                Lcd_Cmd(LCD_CLEAR);
            }
            else {

            }
        }

        if (DERECHA == 0 && IZQUIERDA == 1) {
            var_2 = var_2 + 1;
            if (var_2 >= 15) {
                var_2 = 15;
            }
            __delay_ms(100);
            Lcd_Cmd(LCD_CLEAR);
        } else {
            if (DERECHA == 1 && IZQUIERDA == 0) {
                var_2 = var_2 - 1;
                if (var_2 == 0) {

                    var_2 = 0;

                }
                __delay_ms(100);
                Lcd_Cmd(LCD_CLEAR);
            } else {

            }
        }
        __delay_ms(100);
    }

    Lcd_Cmd(LCD_CLEAR);

COMIENZO:

    Lcd_Out(1, 0, "Bueno empecemos!");

    __delay_ms(1000);

    Lcd_Cmd(LCD_CLEAR);

    Lcd_Out(1, 0, "Llega al:");
    Lcd_Out(1, 11, "#");

    __delay_ms(1000);

    Lcd_Cmd(LCD_CLEAR);

    PODER = 0;
    var_1 = 2;
    var_2 = 0;

CONDICION:

    Lcd_Out(1, 15, "#");

    LATDbits.LD0 = 1;
    do {
        Lcd_Out(1, 15, "#");

        Lcd_Out(var_1, var_2, "8");

        if (DERECHA == 0 && IZQUIERDA == 1) {
            var_2 = var_2 + 1;
            if (var_2 >= 15) {
                var_2 = 15;
            } else {

            }
            __delay_ms(200);
            Lcd_Cmd(LCD_CLEAR);
        } else {
            if (DERECHA == 1 && IZQUIERDA == 0) {
                var_2 = var_2 - 1;

                if (var_2 <= 0) {
                    var_2 = 0;
                }
                __delay_ms(200);
                Lcd_Cmd(LCD_CLEAR);
            } else {

            }
        }

        if (ARRIBA == 1 && ABAJO == 0) {
            var_1 = 1;
            Lcd_Cmd(LCD_CLEAR);
            __delay_ms(200);
        } else {
            if (ARRIBA == 0 && ABAJO == 1) {
                var_1 = 2;
                Lcd_Cmd(LCD_CLEAR);
                __delay_ms(200);
            }
        }

        if (var_1 == 1 && var_2 == 15) {
            var_3 = 1;
        } else {
            var_3 = 0;
        }

    } while (var_3 == 0);

    LATDbits.LD0 = 0;

    Lcd_Cmd(LCD_CLEAR);
    __delay_ms(500);

    Lcd_Out(1, 5, "BIEN!");

    clear();

    Lcd_Out(1, 0, "Recuerda que si ");
    Lcd_Out(2, 0, "los ceros te ");

    __delay_ms(2000);

    clear();

    Lcd_Out(1, 0, "tocan moriras!!");

PRIMER_RETO:

    __delay_ms(2000);

    clear();

    Lcd_Out(1, 0, "Llega al # ojo:");
    Lcd_Out(2, 0, "no toques los 0");

    __delay_ms(2000);



    clear();
    __delay_ms(1000);

    for (general_no_especifica = 0; general_no_especifica < 15; general_no_especifica++) {
        Lcd_Out(1, general_no_especifica, "Nivel 1");

        __delay_ms(300);

        clear();

    }

    __delay_ms(1000);

    var_1 = 2;
    var_2 = 0;
    var_3 = 0;

    clear();

    do {
        PORTC = dato;
        Lcd_Out(1, 15, "#");
        Lcd_Out(1, 6, "0");
        Lcd_Out(2, 10, "o");

        Lcd_Out(var_1, var_2, "8");

        if (DERECHA == 0 && IZQUIERDA == 1) {
            var_2 = var_2 + 1;
            if (var_2 >= 15) {
                var_2 = 15;
            } else {

            }
            __delay_ms(200);
            Lcd_Cmd(LCD_CLEAR);
        } else {
            if (DERECHA == 1 && IZQUIERDA == 0) {
                var_2 = var_2 - 1;

                if (var_2 <= 0) {
                    var_2 = 0;
                }
                __delay_ms(200);
                Lcd_Cmd(LCD_CLEAR);
            } else {

            }
        }

        if (ARRIBA == 1 && ABAJO == 0) {
            var_1 = 1;
            Lcd_Cmd(LCD_CLEAR);
            __delay_ms(200);
        } else {
            if (ARRIBA == 0 && ABAJO == 1) {
                var_1 = 2;
                Lcd_Cmd(LCD_CLEAR);
                __delay_ms(200);
            }
        }

        if (var_1 == 1 && var_2 == 15) {
            var_3 = 1;
        } else {
            var_3 = 0;
        }

        if ((var_1 == 1 && var_2 == 6) || (var_1 == 2 && var_2 == 10)) {
            clear();

            valor_de_vidas = valor_de_vidas + 1;

            vidas(valor_de_vidas);

            if (valor_de_vidas <= 2) {
                clear();
                Lcd_Out(1, 2, "Tocaste un 0");
                Lcd_Out(2, 0, "Una vida menos :(");
                __delay_ms(2000);
                goto PRIMER_RETO;
            }
            else {
                if (valor_de_vidas > 2) {
                    LATC = 0x00;
                    clear();
                    Lcd_Out(1, 2, "Moriste");
                    Lcd_Out(2, 0, "Te quedaste sin vidas :(");
                    __delay_ms(2000);
                    clear();
                    Lcd_Out(1, 3, "GAME OVER");
                    while (1);
                }
            }


        } else {

        }

    } while (var_3 == 0);

    clear();

    Lcd_Out(1, 1, "Bien! pasaste!");
    Lcd_Out(2, 1, "Sigamos -_-");


    __delay_ms(2000);

    clear();

    ////////////////////////////////////////////////////////////////

RETO_2:

    clear();
    __delay_ms(1000);

    for (general_no_especifica = 0; general_no_especifica < 15; general_no_especifica++) {
        Lcd_Out(1, general_no_especifica, "Nivel 2");
        __delay_ms(300);

        clear();
    }

    __delay_ms(1000);

    Lcd_Out(1, 0, "Llega al # ojo:");
    Lcd_Out(2, 0, "no toques los 0");

    __delay_ms(2000);

    var_1 = 2;
    var_2 = 0;
    var_3 = 0;

    clear();

    do {
        PORTC = dato;

        Lcd_Out(1, 15, "#");
        Lcd_Out(1, 6, "O0");
        Lcd_Out(2, 10, "0o0");

        Lcd_Out(var_1, var_2, "8");

        if (DERECHA == 0 && IZQUIERDA == 1) {
            var_2 = var_2 + 1;
            if (var_2 >= 15) {
                var_2 = 15;
            } else {

            }
            __delay_ms(200);
            Lcd_Cmd(LCD_CLEAR);
        } else {
            if (DERECHA == 1 && IZQUIERDA == 0) {
                var_2 = var_2 - 1;

                if (var_2 <= 0) {
                    var_2 = 0;
                }
                __delay_ms(200);
                Lcd_Cmd(LCD_CLEAR);
            } else {

            }
        }

        if (ARRIBA == 1 && ABAJO == 0) {
            var_1 = 1;
            Lcd_Cmd(LCD_CLEAR);
            __delay_ms(200);
        } else {
            if (ARRIBA == 0 && ABAJO == 1) {
                var_1 = 2;
                Lcd_Cmd(LCD_CLEAR);
                __delay_ms(200);
            }
        }

        if (var_1 == 1 && var_2 == 15) {
            var_3 = 1;
        } else {
            var_3 = 0;
        }

        if ((var_1 == 1 && var_2 == 6) || (var_1 == 1 && var_2 == 7) || (var_1 == 2 && (var_2 == 10 || var_2 == 11 || var_2 == 12))) {
            clear();

            valor_de_vidas = valor_de_vidas + 1;

            vidas(valor_de_vidas);

            if (valor_de_vidas <= 2) {
                clear();
                Lcd_Out(1, 2, "Tocaste un 0");
                Lcd_Out(2, 0, "Una vida menos :(");
                __delay_ms(2000);
                goto RETO_2;
            }
            else {
                if (valor_de_vidas > 2) {
                    LATC = 0x00;
                    clear();
                    Lcd_Out(1, 2, "Moriste");
                    Lcd_Out(2, 0, "Te quedaste sin vidas :(");
                    __delay_ms(2000);
                    clear();
                    Lcd_Out(1, 3, "GAME OVER");
                    while (1);
                }
            }
        } else {

        }

    } while (var_3 == 0);


    /////////////////////////////////////////////////////////////////////////////////

RETO_3:

    var_1 = 2;
    var_2 = 0;
    var_3 = 0;


    clear();
    __delay_ms(1000);

    for (general_no_especifica = 0; general_no_especifica < 15; general_no_especifica++) {
        Lcd_Out(1, general_no_especifica, "Nivel 3");
        __delay_ms(300);

        clear();
    }
    do {
        PORTC = dato;
        Lcd_Out(1, 15, "#");
        Lcd_Out(1, 5, "0o0");
        Lcd_Out(2, 10, "0OO0");

        Lcd_Out(var_1, var_2, "8");

        if (DERECHA == 0 && IZQUIERDA == 1) {
            var_2 = var_2 + 1;
            if (var_2 >= 15) {
                var_2 = 15;
            } else {

            }
            __delay_ms(200);
            Lcd_Cmd(LCD_CLEAR);
        } else {
            if (DERECHA == 1 && IZQUIERDA == 0) {
                var_2 = var_2 - 1;

                if (var_2 <= 0) {
                    var_2 = 0;
                }
                __delay_ms(200);
                Lcd_Cmd(LCD_CLEAR);
            } else {

            }
        }

        if (ARRIBA == 1 && ABAJO == 0) {
            var_1 = 1;
            Lcd_Cmd(LCD_CLEAR);
            __delay_ms(200);
        } else {
            if (ARRIBA == 0 && ABAJO == 1) {
                var_1 = 2;
                Lcd_Cmd(LCD_CLEAR);
                __delay_ms(200);
            }
        }

        if (var_1 == 1 && var_2 == 15) {
            var_3 = 1;
        } else {
            var_3 = 0;
        }

        if ((var_1 == 1 && (var_2 == 6 || var_2 == 5)) || (var_1 == 1 && var_2 == 7) || (var_1 == 2 && (var_2 == 10 || var_2 == 11 || var_2 == 12 || var_2 == 13))) {
            clear();

            valor_de_vidas = valor_de_vidas + 1;
            vidas(valor_de_vidas);
            if (valor_de_vidas <= 2) {
                clear();
                Lcd_Out(1, 2, "Tocaste un 0");
                Lcd_Out(2, 0, "Una vida menos :(");
                __delay_ms(2000);
                goto RETO_3;
            }
            else {
                if (valor_de_vidas > 2) {
                    LATC = 0x00;
                    clear();
                    Lcd_Out(1, 2, "Moriste");
                    Lcd_Out(2, 0, "Te quedaste sin vidas :(");
                    __delay_ms(2000);
                    clear();
                    Lcd_Out(1, 3, "GAME OVER");
                    while (1);
                }
            }
        } else {

        }
        PORTC = dato;
    } while (var_3 == 0);

    //////////////////////////////////////////////////////////////////////////////////////////////////////

RETO4:

    var_1 = 2;
    var_2 = 0;
    var_3 = 0;


    clear();
    __delay_ms(1000);

    for (general_no_especifica = 0; general_no_especifica < 15; general_no_especifica++) {
        Lcd_Out(1, general_no_especifica, "Nivel 4");
        __delay_ms(300);

        clear();
    }

    do {
        PORTC = dato;

        Lcd_Out(1, 15, "#");
        Lcd_Out(2, 2, "oo");
        Lcd_Out(1, 5, "0o0");
        Lcd_Out(2, 10, "0Oo0");

        Lcd_Out(var_1, var_2, "8");

        if (DERECHA == 0 && IZQUIERDA == 1) {
            var_2 = var_2 + 1;
            if (var_2 >= 15) {
                var_2 = 15;
            } else {

            }
            __delay_ms(200);
            Lcd_Cmd(LCD_CLEAR);
        } else {
            if (DERECHA == 1 && IZQUIERDA == 0) {
                var_2 = var_2 - 1;

                if (var_2 <= 0) {
                    var_2 = 0;
                }
                __delay_ms(200);
                Lcd_Cmd(LCD_CLEAR);
            } else {

            }
        }

        if (ARRIBA == 1 && ABAJO == 0) {
            var_1 = 1;
            Lcd_Cmd(LCD_CLEAR);
            __delay_ms(200);
        } else {
            if (ARRIBA == 0 && ABAJO == 1) {
                var_1 = 2;
                Lcd_Cmd(LCD_CLEAR);
                __delay_ms(200);
            }
        }

        if (var_1 == 1 && var_2 == 15) {
            var_3 = 1;
        } else {
            var_3 = 0;
        }

        if ((var_1 == 1 && (var_2 == 6 || var_2 == 5)) || (var_1 == 1 && var_2 == 7) || (var_1 == 2 && (var_2 == 10 || var_2 == 11 || var_2 == 12 || var_2 == 13 || var_2 == 2 || var_2 == 3))) {
            clear();

            valor_de_vidas = valor_de_vidas + 1;
            vidas(valor_de_vidas);
            if (valor_de_vidas <= 2) {
                clear();
                Lcd_Out(1, 2, "Tocaste un 0");
                Lcd_Out(2, 0, "Una vida menos :(");
                __delay_ms(2000);
                goto RETO4;
            }
            else {
                if (valor_de_vidas > 2) {
                    LATC = 0x00;
                    clear();
                    Lcd_Out(1, 2, "Moriste");
                    Lcd_Out(2, 0, "Te quedaste sin vidas :(");
                    __delay_ms(2000);
                    clear();
                    Lcd_Out(1, 3, "GAME OVER");
                    while (1);
                }
            }
        } else {

        }

    } while (var_3 == 0);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////

RETO5:

    var_1 = 2;
    var_2 = 0;
    var_3 = 0;


    clear();
    __delay_ms(1000);

    for (general_no_especifica = 0; general_no_especifica < 15; general_no_especifica++) {
        Lcd_Out(1, general_no_especifica, "Nivel 5");
        __delay_ms(300);

        clear();
    }

    var_4 = 0;
    var_5 = 0;

    var_4 = 1;
    var_5 = 2;
    do {
        PORTC = dato;
        __delay_ms(200);
        Lcd_Out(1, 15, "#");
        Lcd_Out(var_4, 2, "O");
        Lcd_Out(var_5, 5, "o");
        Lcd_Out(var_4, 10, "O");

        Lcd_Out(var_1, var_2, "8");



        if (DERECHA == 0 && IZQUIERDA == 1) {
            clear();
            var_4 = 2;
            var_5 = 1;
            //            Lcd_Out(var_1, var_2, "8");
            Lcd_Out(var_4, 2, "0");
            Lcd_Out(var_5, 5, "0");
            Lcd_Out(var_4, 10, "0");
            __delay_ms(100);
            var_2 = var_2 + 1;
            if (var_2 >= 15) {
                var_2 = 15;
            } else {

            }
            __delay_ms(200);
            // Lcd_Cmd(LCD_CLEAR);
        } else {
            if (DERECHA == 1 && IZQUIERDA == 0) {
                clear();
                var_4 = 2;
                var_5 = 1;
                //  Lcd_Out(var_1, var_2, "8");
                Lcd_Out(var_4, 2, "0");
                Lcd_Out(var_5, 5, "0");
                Lcd_Out(var_4, 10, "0");
                __delay_ms(100);
                var_2 = var_2 - 1;

                if (var_2 <= 0) {
                    var_2 = 0;
                }
                __delay_ms(200);
                //      Lcd_Cmd(LCD_CLEAR);
            } else {

            }
            Lcd_Out(var_1, var_2, "8");
        }

        if (ARRIBA == 1 && ABAJO == 0) {
            clear();
            var_4 = 2;
            var_5 = 1;
            //     Lcd_Out(var_1, var_2, "8");
            Lcd_Out(var_4, 2, "0");
            Lcd_Out(var_5, 5, "0");
            Lcd_Out(var_4, 10, "0");
            __delay_ms(100);
            var_1 = 1;
            //     Lcd_Cmd(LCD_CLEAR);
            __delay_ms(200);
        } else {
            if (ARRIBA == 0 && ABAJO == 1) {
                clear();
                var_4 = 2;
                var_5 = 1;
                //Lcd_Out(var_1, var_2, "8");
                Lcd_Out(var_4, 2, "0");
                Lcd_Out(var_5, 5, "0");
                Lcd_Out(var_4, 10, "0");
                __delay_ms(100);
                var_1 = 2;
                //      Lcd_Cmd(LCD_CLEAR);
                __delay_ms(200);
            }
        }

        if (var_1 == 1 && var_2 == 15) {
            var_3 = 1;
        } else {
            var_3 = 0;
        }
        Lcd_Out(var_1, var_2, "8");

        if ((var_1 == var_4 && (var_2 == 10 || var_2 == 2)) || (var_1 == var_5 && var_2 == 5)) {
            clear();

            valor_de_vidas = valor_de_vidas + 1;

            vidas(valor_de_vidas);

            if (valor_de_vidas <= 2) {
                clear();
                Lcd_Out(1, 2, "Tocaste un 0");
                Lcd_Out(2, 0, "Una vida menos :(");
                __delay_ms(2000);
                goto RETO5;
            }
            else {
                if (valor_de_vidas > 2) {
                    LATC = 0x00;
                    clear();
                    Lcd_Out(1, 2, "Moriste");
                    Lcd_Out(2, 0, "Te quedaste sin vidas :(");
                    __delay_ms(2000);
                    clear();
                    Lcd_Out(1, 3, "GAME OVER");
                    while (1);
                }
            }
        } else {

        }



        if (ABAJO == 1 || ARRIBA == 1 || DERECHA == 1 || IZQUIERDA == 1) {
            Lcd_Out(1, 15, "#");
            Lcd_Out(var_1, var_2, "8");
            var_4 = 1;
            var_5 = 2;
            Lcd_Out(var_4, 2, "0");
            Lcd_Out(var_5, 5, "0");
            Lcd_Out(var_4, 10, "0");
            clear();
        }

    } while (var_3 == 0);

    clear();

    Lcd_Out(1, 0, "Genial, espera...");
    Lcd_Out(2, 0, "Que es eso?");

    __delay_ms(2000);

    clear();

    for (general_no_especifica = 0; general_no_especifica < 16; general_no_especifica++) {
        Lcd_Out(1, general_no_especifica, "8");
        __delay_ms(150);
        clear();
    }

    __delay_ms(1000);

    clear();

    for (general_no_especifica = 0; general_no_especifica < 16; general_no_especifica++) {
        Lcd_Out(1, general_no_especifica, ">");
        Lcd_Out(2, general_no_especifica, ">");
        __delay_ms(150);

    }

    clear();


    __delay_ms(2000);


    for (general_no_especifica = 0; general_no_especifica < 5; general_no_especifica++) {

        Lcd_Out(2, general_no_especifica, "8");
        __delay_ms(200);
        clear();
    }

    Lcd_Out(2, general_no_especifica, "8");

    Lcd_Out(1, 4, "Donde estoy?");

    __delay_ms(2000);

    clear();

CINEMATICA_FIN:

    for (general_no_especifica = 0; general_no_especifica < 6; general_no_especifica++) {
        Lcd_Out2(2, general_no_especifica, "8");
        __delay_ms(250);
        if (general_no_especifica < 5) {
            Lcd_Cmd(LCD_CLEAR);
        } else {

        }
    }

    Lcd_Out(1, 4, "Que raro...");
    __delay_ms(1500);
    Lcd_Cmd(LCD_CLEAR);

    Lcd_Out(2, 5, "8");

    for (general_no_especifica = 15; general_no_especifica >= 7; general_no_especifica--) {
        Lcd_Out(2, general_no_especifica, "8");
        __delay_ms(250);
    }

    Lcd_Out(1, 4, "Bienvenido!");
    general_no_especifica = 1;
    __delay_ms(1000);
    clear();


    int general_no_especifica1;

    for (general_no_especifica1 = 1; general_no_especifica1 < 3; general_no_especifica1++) {
        Lcd_Out(general_no_especifica, 6, "FIN");
        __delay_ms(700);
        clear();
    }
    __delay_ms(1000);

    Lcd_Out(1, 2, "Gracias por ");
    Lcd_Out(2, 5, "jugar =)");

    while (1);

    //goto CONDICION;


    return;
}

void clear(void) {
    Lcd_Cmd(LCD_CLEAR);
}

void vidas(int numero_de_vidas) {
    int x;
    switch (numero_de_vidas) {
        case 0:

            dato = 0x07;

            break;

        case 1:

            dato = 0x03;

            break;


        case 2:

            dato = 0x01;

            break;
    }
}
