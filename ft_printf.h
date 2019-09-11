/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:40:22 by vvaras            #+#    #+#             */
/*   Updated: 2019/03/18 13:55:45 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <locale.h>

# define MAX_ACCESSLEN	3

# define SPC_ITALICS	"\033[38;3;m"
# define SPC_UNDERLINE	"\033[38;4;m"
# define SPC_BACKGROUND	"\033[38;7;m"
# define SPC_BOLD		"\033[38;1;m"
# define SPEC_RESET		"\e[0m"
# define TXT_BLACK		"\e[0;30m"
# define TXT_RED		"\e[0;31m"
# define TXT_GREEN		"\e[0;32m"
# define TXT_YELLOW		"\e[0;33m"
# define TXT_BLUE		"\e[0;34m"
# define TXT_PURPLE		"\e[0;35m"
# define TXT_CYAN		"\e[0;36m"
# define TXT_WHITE		"\e[0;37m"
# define TXT_AQUA		"\033[38;5;51m"
# define MAX_COLSIZE	11

# define FLAG_HASH		0b00000000000001
# define FLAG_ZERO		0b00000000000010
# define FLAG_DASH		0b00000000000100
# define FLAG_PLUS		0b00000000001000
# define FLAG_SPACE		0b00000000010000
# define FLAG_QUOTE		0b00000000100000

# define FLAG_MINWIDTH	0b00000001000000
# define FLAG_PRECISION	0b00000010000000
# define FLAG_LENGTH	0b00000100000000
# define FLAG_ACCESS	0b00001000000000

# define FLAG_AST_PREC	0b01000000000000
# define FLAG_AST_MINW	0b10000000000000

typedef struct			s_gv
{
	char				*format;
	int					fd;
	int					pflags;
	va_list				ap;
	int					pbufflen;
	int					access;
	int					minlen;
	int					precision;
	char				leng[3];
	char				*keycodes[128];
	int					takeout;
	char				*cnotat;
}						t_gv;

int						ft_printf(const char *format, ...);
void					addtobuff(t_gv *gv);
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *b, int c, size_t len);
void					addstrtobuff(t_gv *gv, char *str);
void					parse_iscolor(t_gv *gv, char *color);
void					parse_notcolor(t_gv *gv);
int						parse_access(t_gv *gv);
void					parse_flags(t_gv *gv);
int						parse_minwidth(t_gv *gv);
int						parse_precision(t_gv *gv);
int						parse_length(t_gv *gv);
int						parse_specifics(t_gv *gv);
void					parse_colors(t_gv *gv);
void					parse_stuff(t_gv *gv);
int						ft_strncmpcolor(const char *col1, const char *col2);
size_t					ft_strlen(char *str);
int						ft_isdigit(int c);
int						ft_atoi(const char *str);
int						countdigits(t_gv *gv);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					manage_x(t_gv *gv, va_list lst);
void					manage_ux(t_gv *gv, va_list lst);
void					manage_f(t_gv *gv, va_list lst);
void					manage_u(t_gv *gv, va_list lst);
void					ultoa_base
	(t_gv *gv, unsigned long num, int base, int is_upper);
void					manage_o(t_gv *gv, va_list lst);
void					manage_d(t_gv *gv, va_list lst);
char					*ft_itoa(int n);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *s1, const char *s2);
void					*ft_memalloc(size_t size);
void					manage_b(t_gv *gv, va_list lst);
int						ft_strlento(char *s, char c);
int						ft_strlenfrom(char *s, char c);
void					manage_pers(t_gv *gv, va_list lst);
char					*ft_ldtoa(long double n);
char					*ft_lltoa(long long n);
char					*ft_strjoin(char const *s1, char const *s2);
double					ft_power(double num, int pow);
int						ft_isprint(int c);
void					setupkeycodes(t_gv *gv);
void					manage_r(t_gv *gv, va_list lst);
void					addchartobuff(t_gv *gv, char c);
void					manage_k(t_gv *gv, va_list lst);
char					*cnot(long double n, t_gv *gv);
void					manage_e(t_gv *gv, va_list lst);
void					manage_s(t_gv *gv, va_list lst);
void					manage_v(t_gv *gv, va_list lst);
int						getlen_biggeststr(char **pstr);
void					manage_c(t_gv *gv, va_list lst);
void					manage_p(t_gv *gv, va_list lst);
void					addstrtobuff_wlimit(t_gv *gv, char *str, int limit);
void					addstrtobuff_wlimit_from
	(t_gv *gv, char *str, int limit, char f);
int						getlen_dpointer(char **pstr);
int						ft_min(int a, int b);
int						get_mwidth(t_gv *gv, va_list lst);
int						get_prec(t_gv *gv, va_list lst);
void					manage_y(t_gv *gv, va_list lst);
void					parse_iscolor_txt(t_gv *gv, char *color);
void					parse_iscolor_spec(t_gv *gv, char *color);
int						ft_max(int a, int b);
void					add_mwidth_str
	(t_gv *gv, char ifzero, char *str, char nozero);
void					add_prec_str(t_gv *gv, char *str);
void					addstrtobuff_wdotprec
	(t_gv *gv, char *str, int prec, int o);
int						addstrtobuff_wdotprec_count
	(t_gv *gv, char *str, int prec, int o);
char					*dec_to_hexa(unsigned long long n, char strt, int gv);
void					manage_s_helper(t_gv *gv, int j, char *o, int minwidth);
void					manage_p_helper(t_gv *gv, int j, char *hex);
void					manage_p_helper_2(t_gv *gv, char *hex);
void					manage_v_helper
	(t_gv *gv, int greatstr, int lendp, char **o);
void					manage_v_add_utop(t_gv *gv, int greatstr, int j);
void					manage_v_add_top(t_gv *gv, int i);
void					manage_v_add_top_2(t_gv *gv, int j, int lendp, int i);
void					manage_v_add_bottom
	(t_gv *gv, char **o, int greatstr, int i);
void					manage_v_add_ubottom(t_gv *gv, int greatstr);
int						ilen(int i);
void					add_mwidth(t_gv *gv, char ifzero);
void					manage_f_ex
	(t_gv *gv, long double o, char *str, int counttosave);
void					manage_f_e
	(t_gv *gv, char *str, long double o, int counttosave);
void					manage_o_ex(t_gv *gv, va_list lst);
void					manage_r_ex(t_gv *gv, char *str, int j);
void					manage_xx_ex(t_gv *gv, unsigned long long o, char *hex);
void					manage_xx_ext
	(t_gv *gv, char *hex, unsigned long long o);
void					manage_u_extra
	(t_gv *gv, unsigned long long o, va_list lst);
void					manage_d_e(t_gv *gv, char *str, signed long long o);
void					manage_d_ex
	(t_gv *gv, signed long long o, char *str, int j);
void					manage_d_ext
	(t_gv *gv, signed long long o, int j, char *str);
void					manage_d_extr
	(t_gv *gv, int j, signed long long o, char *str);
void					manage_d_extra
	(t_gv *gv, int j, char *str, signed long long o);
void					manage_k_e(t_gv *gv, char *str, int j);
void					manage_e_e(t_gv *gv, char *str, int j, long double o);
int						parse_specifics_e(t_gv *gv, int i);
int						parse_specifics_ex(t_gv *gv, va_list vlist);
char					*ft_ulltoa(unsigned long long n);
char					*mighty_potato
	(long double n, char *first, size_t len, int neg);
char					*confident_potato
	(char *str, char *first, size_t len, int neg);
char					*round_potato(long double n);
char					*self_conscious_potato(char *str, int i);
char					*replace_c(char *s1, char c, unsigned long long n);
char					*low_carb_potato(long double n, int neg);
long double				potato_magic(long double n, char *first, size_t len);
char					*potato_supreme
	(long double n, char *first, char c, int neg);
char					*str_chop2(char *str, int n);
char					*insert_c(char *s1, char c, unsigned long long n);
size_t					ft_strlenfc(const char *str);
long double				ft_pow(long double base, long double ex);
char					*ft_strdupfc(const char *s1);
char					*ft_strjoinfc(const char *s1, const char *s2);
void					add_ox_forxconv_rem(t_gv *gv);
void					add_ox_forxconv(t_gv *gv);
void					addstrtobuff_wdotprec_e
	(t_gv *gv, int prec, int dot);
int						addstrtobuff_wdotprec_count_e
	(char *str, int prec, int dot, int count);
void					pp_mid(t_gv *gv, char *prec, int i, int len);
int						pp_top(t_gv *gv);
void					pp_hat(t_gv *gv);
int						pl_mbot(t_gv *gv);
int						pl_bot(t_gv *gv);
int						pl_top(t_gv *gv);
void					pl_mid(t_gv *gv);
void					setupkeycodes2(t_gv *gv);
char					*dec_to_hexa_e
	(char *hex, char *hexa_deci_num, int i);
char					*dec_to_hexa_prp(int gv);
void					ultoa_base_e
	(t_gv *gv, int j, unsigned long temp_nbr, char *str);
void					ultoa_base_ex
	(t_gv *gv, unsigned long temp_nbr, char *str);
void					ultoa_base_ext
	(t_gv *gv, int j, char *str, unsigned long temp_nbr);
char					*ft_strjoin_fl(char const *s1, char *s2);
void					manage_e_ex(t_gv *gv, long double o, int j, char *str);
void					check_mwidth(t_gv *gv, int *len, char *minwid);
char					*cnot_e(t_gv *gv, int neg, char *cnota, int ex);
int						ft_printfd(int fd, const char *format, ...);
void                    manage_p_helper_else(t_gv *gv, int j, char *hex);

#endif
