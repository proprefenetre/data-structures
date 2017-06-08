/* Hashtable, K&R ch. 6 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

#define HASHSIZE    101

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void show_table(void);

int main(void)
{
    install("Dutch", "hallo");
    install("English", "hello");
    install("French", "bonjour");
    install("German", "gutentag");

    show_table();
    return 0;
}

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 33 * hashval;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;
        } 
        return NULL;
    }
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = malloc(sizeof(struct nlist));  
        if (np == NULL || (np->name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free(np->defn);
    }
    if ((np->defn = strdup(defn)) == NULL)  {
        return NULL;
    } 
    return np;
}

void show_table(void)
{
    struct nlist *np;

    for (int i = 0; i < HASHSIZE; i++) {
        if (hashtab[i]) {
            for (np = hashtab[i]; np != NULL; np=np->next) {
                printf("\t%-10s\t%-10s\n", hashtab[i]->name, hashtab[i]->defn);
            }
        }
    }
}
