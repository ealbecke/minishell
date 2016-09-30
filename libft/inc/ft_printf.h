/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:16:12 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/27 17:16:14 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>

# define FT_NAME "ft_printf"
# define FT_ERROR -1
# define FT_STD_OUT 1
# define FT_BEG_FLAG '%'
# define FT_NULL "(null)"
# define FT_STR_S_HEX "0123456789abcdef"
# define FT_FL_OCT "0"
# define FT_FL_S_HEX "0x"
# define FT_FL_HEX "0X"
# define FT_FL_S_BIN "bx"
# define FT_FL_BIN "BX"
# define FT_NOACCU(stc) (((stc)->ck & FT_ACCU) && (stc)->accu == 0)

/*
** Message
*/
# define FT_M_MALLOC "[Error]> Allocation failed"

/*
** Flags
** -----
*/
# define FT_CHECK_FLAG 1
# define FT_AREA 2
# define FT_ACCU 4
# define FT_CAST 8
# define FT_STAR '*'

/*
** Flags for types
*/
# define FT_TYPES "sSdDioOuUxXcCpbB"
# define FT_WCS 2
# define FT_D 4
# define FT_S_O 6
# define FT_O 7
# define FT_S_U 8
# define FT_U 9
# define FT_S_X 10
# define FT_X 11
# define FT_S_C 12
# define FT_WIC 13
# define FT_S_P 14
# define FT_S_B 15
# define FT_B 16
# define FT_FL_O(type) ((type) == FT_S_O || (type) == FT_O ? (type) : 0)
# define FT_FL_X(type) ((type) == FT_S_X || (type) == FT_X ? (type) : 0)

/*
** Flags for special flags
** Reference flags:
** '#' = FT_SHARP
** ' ' = FT_SPACE
** '0' = FT_ZERO
** '+' = FT_MORE
** '-' = FT_LESS
*/
# define FT_FLAGS "# 0+-"
# define FT_SHARP  1
# define FT_SPACE  2
# define FT_ZERO   4
# define FT_MORE   8
# define FT_LESS  16

/*
** Flags for cast
*/
# define FT_CAST_FLAG "hljz"
# define FT_H 1
# define FT_L 2
# define FT_J 4
# define FT_Z 8
# define FT_HH 16
# define FT_LL 32

typedef unsigned char	t_flags;
typedef unsigned char	t_checks;
typedef enum			e_boolean
{
	F_ = 0,
	T_ = 1
}						t_boolean;
typedef struct			s_options
{
	t_checks			ck;
	t_flags				fl;
	unsigned int		area;
	unsigned int		accu;
	t_flags				cast;
	unsigned int		type;
	int					sc;
}						t_options;
typedef struct			s_main
{
	unsigned int		n;
	int					tot_size;
	int					sc;
}						t_main;

/*
** In ft_printf.c
** ==============
*/
int						ft_printf(const char *format, ...);

/*
** In ft_sprintf.c
** ===============
*/
int						ft_sprintf(char *str, const char *format, ...);
void					ft_memcat(char *dst, const char *cat, t_main snt);

/*
** In ft_dprintf.c
** ===============
*/
int						ft_dprintf(int fd, const char *format, ...);

/*
** In ft_vprintf.c
** ===============
*/
int						ft_vprintf(const char *format, va_list ap);

/*
** In ft_vdprintf.c
** ================
*/
int						ft_vdprintf(int fd, const char *format, va_list ap);

/*
** In ft_string.c
** --------------
*/
int						ft_next_flag(const char *str, char **new_str, char c);
int						ft_conv_flag(const char *src, char **dst, va_list ap,
								int *sc);

/*
** In ft_flags.c
** -------------
*/
int						ft_flag(const char *str, char **sflag, va_list ap,
								int *sc);
void					ft_simple_flag(char c, t_options *stc);
unsigned int			ft_area_flag(const char *sarea, t_options *stc,
								va_list ap);
unsigned int			ft_accu_flag(const char *saccu, t_options *stc,
								va_list ap);
unsigned int			ft_cast_flag(const char *scast, t_options *stc);

/*
** In ft_arguments.c
** -----------------
*/
char					*ft_s_arg(t_options *stc, va_list ap);
char					*ft_c_arg(t_options *stc, va_list ap);
char					*ft_di_arg(t_options *stc, va_list ap);
char					*ft_oux_arg(t_options *stc, va_list ap);
char					*ft_p_arg(t_options *stc, va_list ap);

/*
** In ft_funcflag.c
** ----------------
*/
char					*ft_di_size(t_options *stc, int n);
char					*ft_ldi_size(t_options *stc, long long int n);
char					*ft_sdi_size(t_options *stc, short n);
char					*ft_cdi_size(t_options *stc, char n);
char					*ft_oux_size(t_options *stc, unsigned long long n,
								char *bs);

/*
** In ft_s_flag.c
** --------------
*/
char					*ft_str_conv(t_options *stc, char *str);
char					*ft_wcs_conv(t_options *stc, wchar_t *wcs);
unsigned int			ft_wcsconv_len(t_options *stc, wchar_t *wcs);

/*
** In ft_c_flag.c
** -------------
*/
char					*ft_char_conv(t_options *stc, unsigned int c);
char					*ft_wi_conv(t_options *stc, wchar_t wic);

/*
** In ft_di_flag.c
** ---------------
*/
char					*ft_di_conv(t_options *stc, int num);
char					*ft_ldi_conv(t_options *stc, long long int num);
char					*ft_sdi_conv(t_options *stc, short num);
char					*ft_cdi_conv(t_options *stc, char num);

/*
** In ft_oux_flag.c
** ----------------
*/
char					*ft_oux_conv(t_options *stc, unsigned long long x);
char					*ft_str_base(unsigned int type);
char					*ft_flag_base(t_options *stc, unsigned long long x);

/*
** In ft_structure.c
** -------------
*/
void					ft_stcoptclr(t_options *stc);
void					ft_stcmainclr(t_main *stc);

#endif
