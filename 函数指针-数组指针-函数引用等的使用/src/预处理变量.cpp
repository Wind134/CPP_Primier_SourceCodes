#include <cstdlib>
/* EXIT_FAILURE和EXIT_SUCCESS是预处理变量
 *       这些变量不在std的命名空间内 
 *       因此不需要使用using去处理命名空间
*/
int main()
{
    bool some_failure = false;
    if (some_failure)
        return EXIT_FAILURE;  // defined in cstdlib
    else
        return EXIT_SUCCESS;  // defined in cstdlib
}
