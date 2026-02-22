
#include "ft_printf_fd.h"
#include <stdio.h>

int main(void)
{
    // Test sur stdout (1)
    ft_printf_fd(1, "Ceci va dans stdout (comme sa, pb...)\n");
    
    // Test sur stderr (2)
    ft_printf_fd(2, "[bench] Ceci va dans stderr (statistiques)\n");
    
    return (0);
}