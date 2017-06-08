/*
 * implementation from K&R ch. 6
 * binary search tree that collects word frequencies
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 

#define MAXWORD     100

#define getch()     getc(stdin)
#define ungetch(x)  ungetc((x), stdin)

struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
void treeprint(struct tnode *);
char *mstrdup(char *);
int getword(char *, int);

struct tnode {
    char *word;
    int freq;
    struct tnode *left;
    struct tnode *right;
};

int main(void)
{
    struct tnode *root;
    char woord[MAXWORD];

    root = NULL;
    while (getword(woord, MAXWORD) != EOF) {
        if (isalpha(woord[0])) {
            root = addtree(root, woord);
        }
    }

    treeprint(root);

    return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
    // {{{1 // 
{
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = mstrdup(w);
        p->freq = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->freq++;
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }

    return p;
}
//  1}}} // 

void treeprint(struct tnode *p)
//  {{{1 // 
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->freq, p->word);
        treeprint(p->right);
    }
}
//  1}}} // 

struct tnode *talloc(void)
// {{{1
{
    return malloc(sizeof(struct tnode));
}
//  1}}}

char *mstrdup(char *s)
//  {{{1 // 
{
    char *p;

    p = malloc(strlen(s)+1);     // +1 voor \0

    if (p != NULL) {
        strcpy(p, s);
    }

    return p;
}
//  1}}} // 

int getword(char *word, int lim)
//  getword {{{1
{
    int c;
    char *w = word;

    while (isspace(c = getch())) {
        ;
    }

    if (c != EOF) {
        *w++ = c;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
} //  1}}}
