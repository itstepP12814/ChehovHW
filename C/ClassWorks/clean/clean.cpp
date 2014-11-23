#include "clean.h"
#include <stdlib.h>
#include <iostream>

#ifdef __WIN32__//если есть вин - то сработает эта функция, иначе - сработает линуксовая
#define CLEAN_CONSOLE "cls"
#else
#define CLEAN_CONSOLE "clear"
#endif // __WIN32__

void clean_commline()
{
    system(CLEAN_CONSOLE);
}
