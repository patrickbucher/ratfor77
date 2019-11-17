#include <stdio.h>
#include "lookup.h"

static
struct	hashlist *hashtab[HASHMAX];

/*
 * from K&R "The C Programming language"
 * Table lookup routines
 *
 * hash - for a hash value for string s
 *
 */
hash(s)
S_CHAR *s;
{
	int	hashval;

	for (hashval = 0; *s != '\0';)
		hashval += *s++;
	return (hashval % HASHMAX);
}

/*
 * lookup - lookup for a string s in the hash table
 *
 */
struct hashlist
*lookup(s)
S_CHAR *s;
{
	struct hashlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return(np);	/* found     */
	return(NULL);		/* not found */
}

/*
 * install - install a string name in hashtable and its value def
 *
 */
struct hashlist
*install(name,def)
S_CHAR *name;
S_CHAR *def;
{
	int hashval;
	struct hashlist *np, *lookup();
	S_CHAR *strsave(), *malloc();

	if ((np = lookup(name)) == NULL) {	/* not found.. */
		np = (struct hashlist *) malloc(sizeof(*np));
		if (np == NULL)
			return(NULL);
		if ((np->name = strsave(name)) == NULL)
			return(NULL);
		hashval = hash(np->name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else					/* found..     */
		free(np->def);			/* free prev.  */
	if ((np->def = strsave(def)) == NULL)
		return(NULL);
	return(np);
}

/*
 * strsave - save string s somewhere
 *
 */
S_CHAR
*strsave(s)
S_CHAR *s;
{
	S_CHAR *p, *malloc();

	if ((p = malloc(strlen(s)+1)) != NULL)
		strcpy(p, s);
	return(p);
}


