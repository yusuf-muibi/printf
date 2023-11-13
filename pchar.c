#include "main.h"

/**
* init_pchar - clears struct fields and reset buffer
* @pchar: the parameters struct
* @ap: the argument pointer
* Return: void
*/
void init_pchar(pchar_t *pchar, va_list ap)
{
pchar->unsign = 0;
pchar->plus_flag = 0;
pchar->space_flag = 0;
pchar->hashtag_flag = 0;
pchar->zero_flag = 0;
pchar->minus_flag = 0;
pchar->width = 0;
pchar->precision = UINT_MAX;
pchar->h_modifier = 0;
pchar->l_modifier = 0;
(void)ap;
}
