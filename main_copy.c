//#include "ft_printf.h"
//#include <stdio.h>
//#include <limits.h>
//
//int main	() {
//    /************************************TEST_s***********************************
//     *****************************************************************************/
//
//    printf("************************************TEST_s***********************************\n");
//    printf("*************************************BEGIN***********************************\n");
//    char        *str = NULL;
//    ft_printf("%s\n", "pouet");
//    ft_printf(" pouet %s !!\n", "camembert");
//    ft_printf("%s !\n", "Ceci n'est pas un \0 exercice !");
//    ft_printf("%s!\n", "Ceci n'est toujours pas un exercice !");
//    ft_printf("%s!\n", NULL);
//    printf("*********************************NOW COMPARE*********************************\n");
//    printf("%s\n", "pouet");
//    printf(" pouet %s !!\n", "camembert");
//    printf("%s !\n", "Ceci n'est pas un \0 exercice !");
//    printf("%s!\n", "Ceci n'est toujours pas un exercice !");
//    printf("%s!\n", NULL);
//
//    /************************************TEST_c***********************************
//     *****************************************************************************/
//
//    printf("************************************TEST_c***********************************\n");
//    printf("*************************************BEGIN***********************************\n");
//    ft_printf("%c\n", 42);
//    ft_printf("Kashim a %c histoires à raconter", 1001);
//    ft_printf("Il fait au moins %c\n", -8000);;
//    ft_printf("%c\n", -0);
//    ft_printf("%c\n", 0);
//    ft_printf("%c\n", INT_MAX);
//    ft_printf("%c\n", 'c');
//    ft_printf("%c\n", '\n');
//    ft_printf("%c\n", 'l');
//    ft_printf("%c\n", 'y');
//    ft_printf("%c\n", ' ');
//    ft_printf("%c\n", 'e');
//    ft_printf("%c\n", 's');
//    ft_printf("%c\n", 't');
//    ft_printf("%c\n", ' ');
//    ft_printf("%c\n", 'f');
//    ft_printf("%c\n", 'a');
//    ft_printf("%c\n", 'n');
//    ft_printf("%c\n", 't');
//    ft_printf("%c\n", 'a');
//    ft_printf("%c\n", 's');
//    ft_printf("%c\n", 't');
//    ft_printf("%c\n", 'i');
//    ft_printf("%c\n", 'q');
//    ft_printf("%c\n", 'u');
//    ft_printf("%c\n", 'e');
//    ft_printf("%c\n", '!');
//    ft_printf("%c\n", '\r');
//    ft_printf("%c\n", '\t');
//    printf("*********************************NOW COMPARE*********************************\n");
//    printf("%c\n", 42);
//    printf("Kashim a %c histoires à raconter", 1001);
//    printf("Il fait au moins %c\n", -8000);
//    printf("%c\n", -0);
//    printf("%c\n", 0);
//    printf("%c\n", INT_MAX);
//    printf("%c\n", 'c');
//    printf("%c\n", '\n');
//    printf("%c\n", 'l');
//    printf("%c\n", 'y');
//    printf("%c\n", ' ');
//    printf("%c\n", 'e');
//    printf("%c\n", 's');
//    printf("%c\n", 't');
//    printf("%c\n", ' ');
//    printf("%c\n", 'f');
//    printf("%c\n", 'a');
//    printf("%c\n", 'n');
//    printf("%c\n", 't');
//    printf("%c\n", 'a');
//    printf("%c\n", 's');
//    printf("%c\n", 't');
//    printf("%c\n", 'i');
//    printf("%c\n", 'q');
//    printf("%c\n", 'u');
//    printf("%c\n", 'e');
//    printf("%c\n", '!');
//    printf("%c\n", '\r');
//    printf("%c\n", '\t');
//
//    /************************************TEST_D***********************************
//     *****************************************************************************/
//
//    printf("************************************TEST_D***********************************\n");
//    printf("*************************************BEGIN***********************************\n");
//    ft_printf("%D\n", 42);
//    ft_printf("Kashim a %D histoires à raconter\n", 1001);
//    ft_printf("Il fait au moins %D\n", -8000);
//    ft_printf("%D\n", -0);
//    ft_printf("%D\n", 0);
//    ft_printf("%D\n", INT_MAX);
//    ft_printf("%D\n", INT_MIN);
//    ft_printf("%D\n", INT_MIN - 1);
//    ft_printf("%D\n", INT_MAX + 1);
//    ft_printf("%%D 0000042 == |%D|\n", 0000042);
//    ft_printf("%%D \t == |%D|\n", '\t');
//    ft_printf("%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');
//    printf("*********************************NOW COMPARE*********************************\n");
//    printf("%D\n", 42);
//    printf("Kashim a %D histoires à raconter\n", 1001);
//    printf("Il fait au moins %D\n", -8000);
//    printf("%D\n", -0);
//    printf("%D\n", 0);
//    printf("%D\n", INT_MAX);
//    printf("%D\n", INT_MIN);
//    printf("%D\n", INT_MIN - 1);
//    printf("%D\n", INT_MAX + 1);
//    printf("%%D 0000042 == |%D|\n", 0000042);
//    printf("%%D \t == |%D|\n", '\t');
//    printf("%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');
//
//    /************************************TEST_d***********************************
//     *****************************************************************************/
//
//    printf("************************************TEST_d***********************************\n");
//    printf("*************************************BEGIN***********************************\n");
//    ft_printf("%d\n", 42);
//    ft_printf("Kashim a %d histoires à raconter\n", 1001);
//    ft_printf("Il fait au moins %d\n", -8000);
//    ft_printf("%d\n", -0);
//    ft_printf("%d\n", 0);
//    ft_printf("%d\n", INT_MAX);
//    ft_printf("%d\n", INT_MIN);
//    ft_printf("%d\n", INT_MIN - 1);
//    ft_printf("%d\n", INT_MAX + 1);
//    ft_printf("%%d 0000042 == |%d|\n", 0000042);
//    ft_printf("%%d \t == |%d|\n", '\t');
//    ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
//    printf("*********************************NOW COMPARE*********************************\n");
//    printf("%d\n", 42);
//    printf("Kashim a %d histoires à raconter\n", 1001);
//    printf("Il fait au moins %d\n", -8000);
//    printf("%d\n", -0);
//    printf("%d\n", 0);
//    printf("%d\n", INT_MAX);
//    printf("%d\n", INT_MIN);
//    printf("%d\n", INT_MIN - 1);
//    printf("%d\n", INT_MAX + 1);
//    printf("%%d 0000042 == |%d|\n", 0000042);
//    printf("%%d \t == |%d|\n", '\t');
//    printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
//
//    /************************************TEST_i***********************************
//     *****************************************************************************/
//
//    printf("************************************TEST_i***********************************\n");
//    printf("*************************************BEGIN***********************************\n");
//    ft_printf("%i\n", 42);
//    ft_printf("Kashim a %i histoires à raconter\n", 1001);
//    ft_printf("Il fait au moins %i\n", -8000);
//    ft_printf("%i\n", -0);
//    ft_printf("%i\n", 0);
//    ft_printf("%i\n", INT_MAX);
//    ft_printf("%i\n", INT_MIN);
//    ft_printf("%i\n", INT_MIN - 1);
//    ft_printf("%i\n", INT_MAX + 1);
//    ft_printf("%%i 0000042 == |%i|\n", 0000042);
//    ft_printf("%%i \t == |%i|\n", '\t');
//    ft_printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');
//    printf("*********************************NOW COMPARE*********************************\n");
//    printf("%i\n", 42);
//    printf("Kashim a %i histoires à raconter\n", 1001);
//    printf("Il fait au moins %i\n", -8000);
//    printf("%i\n", -0);
//    printf("%i\n", 0);
//    printf("%i\n", INT_MAX);
//    printf("%i\n", INT_MIN);
//    printf("%i\n", INT_MIN - 1);
//    printf("%i\n", INT_MAX + 1);
//    printf("%%i 0000042 == |%i|\n", 0000042);
//    printf("%%i \t == |%i|\n", '\t');
//    printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');
//
//    /************************************TEST_o***********************************
//     *****************************************************************************/
//
//    printf("************************************TEST_o***********************************\n");
//    printf("*************************************BEGIN***********************************\n");
//    ft_printf("%o\n", 42);
//    ft_printf("Kashim a %o histoires à raconter\n", 1001);
//    ft_printf("Il fait au moins %o\n", -8000);
//    ft_printf("%o\n", -0);
//    ft_printf("%o\n", 0);
//    ft_printf("%o\n", INT_MAX);
//    ft_printf("%o\n", INT_MIN);
//    ft_printf("%o\n", INT_MIN - 1);
//    ft_printf("%o\n", INT_MAX + 1);
//    ft_printf("%%o 0000042 == |%o|\n", 0000042);
//    ft_printf("%%o \t == |%o|\n", '\t');
//    ft_printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
//    printf("*********************************NOW COMPARE*********************************\n");
//    printf("%o\n", 42);
//    printf("Kashim a %o histoires à raconter\n", 1001);
//    printf("Il fait au moins %o\n", -8000);
//    printf("%o\n", -0);
//    printf("%o\n", 0);
//    printf("%o\n", INT_MAX);
//    printf("%o\n", INT_MIN);
//    printf("%o\n", INT_MIN - 1);
//    printf("%o\n", INT_MAX + 1);
//    printf("%%o 0000042 == |%o|\n", 0000042);
//    printf("%%o \t == |%o|\n", '\t');
//    printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
//
//    /************************************TEST_u***********************************
//     *****************************************************************************/
//
//    printf("************************************TEST_u***********************************\n");
//    printf("*************************************BEGIN***********************************\n");
//    ft_printf("%u\n", 42);
//    ft_printf("Kashim a %u histoires à raconter\n", 1001);
//    ft_printf("Il fait au moins %u\n", -8000);
//    ft_printf("%u\n", -0);
//    ft_printf("%u\n", 0);
//    ft_printf("%u\n", INT_MAX);
//    ft_printf("%u\n", INT_MIN);
//    ft_printf("%u\n", INT_MIN - 1);
//    ft_printf("%u\n", INT_MAX + 1);
//    ft_printf("%%u 0000042 == |%u|\n", 0000042);
//    ft_printf("%%u \t == |%u|\n", '\t');
//    ft_printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');
//    printf("*********************************NOW COMPARE*********************************\n");
//    printf("%u\n", 42);
//    printf("Kashim a %u histoires à raconter\n", 1001);
//    printf("Il fait au moins %u\n", -8000);
//    printf("%u\n", -0);
//    printf("%u\n", 0);
//    printf("%u\n", INT_MAX);
//    printf("%u\n", INT_MIN);
//    printf("%u\n", INT_MIN - 1);
//    printf("%u\n", INT_MAX + 1);
//    printf("%%u 0000042 == |%u|\n", 0000042);
//    printf("%%u \t == |%u|\n", '\t');
//    printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');
//
//    /************************************TEST_x***********************************
//     *****************************************************************************/
//
//    printf("************************************TEST_x***********************************\n");
//    printf("*************************************BEGIN***********************************\n");
//    ft_printf("%x\n", 42);
//    ft_printf("Kashim a %x histoires à raconter\n", 1001);
//    ft_printf("Il fait au moins %x\n", -8000);
//    ft_printf("%x\n", -0);
//    ft_printf("%x\n", 0);
//    ft_printf("%x\n", INT_MAX);
//    ft_printf("%x\n", INT_MIN);
//    ft_printf("%x\n", INT_MIN - 1);
//    ft_printf("%x\n", INT_MAX + 1);
//    ft_printf("%%x 0000042 == |%x|\n", 0000042);
//    ft_printf("%%x \t == |%x|\n", '\t');
//    ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
//    printf("*********************************NOW COMPARE*********************************\n");
//    printf("%x\n", 42);
//    printf("Kashim a %x histoires à raconter\n", 1001);
//    printf("Il fait au moins %x\n", -8000);
//    printf("%x\n", -0);
//    printf("%x\n", 0);
//    printf("%x\n", INT_MAX);
//    printf("%x\n", INT_MIN);
//    printf("%x\n", INT_MIN - 1);
//    printf("%x\n", INT_MAX + 1);
//    printf("%%x 0000042 == |%x|\n", 0000042);
//    printf("%%x \t == |%x|\n", '\t');
//    printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
//
//    /************************************TEST_sharp*******************************
//     *****************************************************************************/
//
//    printf("**********************************TEST_sharp*********************************\n");
//    printf("*************************************BEGIN***********************************\n");
//    ft_printf("%%#X 42 ==  %#X\n", 42);
//    ft_printf("%%X 42 ==  %X\n", 42);
//    ft_printf("%%#o 0 ==  %#o\n", 0);
//    ft_printf("%%o 0 ==  %o\n", 0);
//    ft_printf("%%#o INT_MAX ==  %#o\n", INT_MAX);
//    ft_printf("%%o INT_MAX ==  %o\n", INT_MAX);
//    ft_printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
//    ft_printf("%%o INT_MIN ==  %o\n", INT_MIN);
//    ft_printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
//    ft_printf("%%X INT_MIN ==  %X\n", INT_MIN);
//    ft_printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
//    ft_printf("%%X INT_MAX ==  %X\n", INT_MAX);
//    printf("*********************************NOW COMPARE*********************************\n");
//    printf("%%#X 42 ==  %#X\n", 42);
//    printf("%%X 42 ==  %X\n", 42);
//    printf("%%#o 0 ==  %#o\n", 0);
//    printf("%%o 0 ==  %o\n", 0);
//    printf("%%#o INT_MAX ==  %#o\n", INT_MAX);
//    printf("%%o INT_MAX ==  %o\n", INT_MAX);
//    printf("%%#o INT_MIN ==  %#o\n", INT_MIN);
//    printf("%%o INT_MIN ==  %o\n", INT_MIN);
//    printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
//    printf("%%X INT_MIN ==  %X\n", INT_MIN);
//    printf("%%#X INT_MAX ==  %#X\n", INT_MAX);
//    printf("%%X INT_MAX ==  %X\n", INT_MAX);
//
//    /************************************TEST_hhhlll******************************
//     *****************************************************************************/
//    unsigned char a = -125;
//    unsigned int b = -125;
//    unsigned long c = -125;
//    unsigned short d = -125;
//    size_t e = -125;
//    uintmax_t f = -125;
//    unsigned long long    g = -125;
//
//    unsigned char h = 0;
//    unsigned int i = 0;
//    unsigned long j = 0;
//    unsigned short k = 0;
//    size_t l = 0;
//    uintmax_t m = 0;
//    unsigned long long n = 0;
//
//    unsigned char o = (unsigned char)~0U>>1;
//    unsigned int p = ~0U>>1;
//    unsigned long q = ~0U>>1;
//    unsigned short r = (short)~0U>>1;
//    size_t s = (size_t)~0U>>1;
//    uintmax_t t = (uintmax_t)~0U>>1;
//    unsigned long long u = (unsigned long long)~0U>>1;
//
//    unsigned char v = -m-1;
//    unsigned int w = -n-1;
//    unsigned long x = -o-1;
//    unsigned short y = -p-1;
//    unsigned long z = -q-1;
//    uintmax_t zz = -r-1;
//    unsigned long long aa = -r-1;
//
//    printf("*********************************TEST_hhhlll*********************************\n");
//    printf("*************************************BEGIN***********************************\n");
//    ft_printf("unsigned char        a = %hhu sizeof a = %lu\n", a,sizeof(a));
//    ft_printf("unsigned int        b = %u sizeof b = %lu\n",b,sizeof(b));
//    ft_printf("unsigned long        c = %lu sizeof c = %lu\n",c,sizeof(c));
//    ft_printf("unsigned short        d = %hu sizeof d = %lu\n",d,sizeof(d));
//    ft_printf("unsigned long long    g = %llu sizeof g = %lu\n\n",g,sizeof(g));
//
//    ft_printf("unsigned char        h = %hhu sizeof h = %lu\n", h,sizeof(h));
//    ft_printf("unsigned int        i = %u sizeof i = %lu\n",i,sizeof(i));
//    ft_printf("unsigned long        j = %lu sizeof j = %lu\n",j,sizeof(j));
//    ft_printf("unsigned short        k = %hu sizeof k = %lu\n",k,sizeof(k));
//    ft_printf("unsigned long long    n = %llu sizeof n = %lu\n\n",n,sizeof(n));
//
//    ft_printf("unsigned char        o = %hhu sizeof o = %lu\n", o,sizeof(o));
//    ft_printf("unsigned int        p = %u sizeof p = %lu\n",p,sizeof(p));
//    ft_printf("unsigned long        q = %lu sizeof q = %lu\n",q,sizeof(q));
//    ft_printf("unsigned short        r = %hu sizeof r = %lu\n",r,sizeof(r));
//    ft_printf("unsigned long long    u = %llu sizeof u = %lu\n\n",u,sizeof(u));
//
//    ft_printf("unsigned char        v = %hhu sizeof v = %lu\n", v,sizeof(v));
//    ft_printf("unsigned int        w = %u sizeof w = %lu\n",w,sizeof(w));
//    ft_printf("unsigned long        x = %lu sizeof x = %lu\n",x,sizeof(x));
//    ft_printf("unsigned short        y = %hu sizeof y = %lu\n",y,sizeof(y));
//    ft_printf("unsigned long long    aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa));
//    printf("**********************************NOW COMPARE*********************************\n");
//    printf("unsigned char        a = %hhu sizeof a = %lu\n", a,sizeof(a));
//    printf("unsigned int        b = %u sizeof b = %lu\n",b,sizeof(b));
//    printf("unsigned long        c = %lu sizeof c = %lu\n",c,sizeof(c));
//    printf("unsigned short        d = %hu sizeof d = %lu\n",d,sizeof(d));
//    printf("unsigned long long    g = %llu sizeof g = %lu\n\n",g,sizeof(g));
//
//    printf("unsigned char        h = %hhu sizeof h = %lu\n", h,sizeof(h));
//    printf("unsigned int        i = %u sizeof i = %lu\n",i,sizeof(i));
//    printf("unsigned long        j = %lu sizeof j = %lu\n",j,sizeof(j));
//    printf("unsigned short        k = %hu sizeof k = %lu\n",k,sizeof(k));
//    printf("unsigned long long    n = %llu sizeof n = %lu\n\n",n,sizeof(n));
//
//    printf("unsigned char        o = %hhu sizeof o = %lu\n", o,sizeof(o));
//    printf("unsigned int        p = %u sizeof p = %lu\n",p,sizeof(p));
//    printf("unsigned long        q = %lu sizeof q = %lu\n",q,sizeof(q));
//    printf("unsigned short        r = %hu sizeof r = %lu\n",r,sizeof(r));
//    printf("unsigned long long    u = %llu sizeof u = %lu\n\n",u,sizeof(u));
//
//    printf("unsigned char        v = %hhu sizeof v = %lu\n", v,sizeof(v));
//    printf("unsigned int        w = %u sizeof w = %lu\n",w,sizeof(w));
//    printf("unsigned long        x = %lu sizeof x = %lu\n",x,sizeof(x));
//    printf("unsigned short        y = %hu sizeof y = %lu\n",y,sizeof(y));
//    printf("unsigned long long    aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa));
//
//    system("leaks ft_printf");
//}
