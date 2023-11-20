#ifdef _MSC_VER
#include "dirent.c"
#endif
#include "glob.c"

#include <stdio.h>


int main()
{
    glob_t g;

    /*
     * Possible output:
     * C:/users/John Doe\Desktop
     * C:/users/John Doe\Downloads
     */
    int rv = glob("~\\D*", GLOB_WIN32 | GLOB_TILDE, NULL, &g);

    switch (rv) {
        case 0:
            break;
        case GLOB_NOSPACE:
            puts("error: GLOB_NOSPACE (malloc call failed)");
            exit(1);
        case GLOB_ABORTED:
            puts("error: GLOB_ABORTED (read error)");
            exit(1);
        case GLOB_NOMATCH:
            puts("error: GLOB_NOMATCH (no match found)");
            exit(1);
        default:
            printf("error: glob returned non-zero: %d\n", rv);
            exit(1);
    }

    for (size_t i = 0; i < g.gl_pathc; i++) {
        puts(g.gl_pathv[i]);
    }

    return 0;
}
