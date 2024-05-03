#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"
/**×¢ÊÍ**/

int a(){}

int main(void) {
    Node* list = NULL;
    add_before_head(&list, 1);
    add_before_head(&list, 2);
    add_before_head(&list, 3);
   

    //display_list(list);

    printf("%p \n", search_list(list, 2));

    //free_list(list);
    //display_list(list);
    return 0;
}