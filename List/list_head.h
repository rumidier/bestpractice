#ifndef   HEAD_H
#define   HEAD_H

#define     MAX_LEN     256
#define     ADD         "add"
#define     DEL         "del"
#define     CHANGE      "change"
#define     SEARCH      "search"

int
list_cat_command (int, char **);

void
list_search (void);

#endif
