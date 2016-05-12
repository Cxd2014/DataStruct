#ifndef _h_HASH
#define _h_HASH 1

/**
    Allocate strings using malloc
 */
#define VALUE_ALLOCATE      0x1

/*
    The handle list stores the length of the list and the number of used handles in the first two words.  These are
    hidden from the caller by returning a pointer to the third word to the caller.
 */
#define H_LEN       0       /* First entry holds length of list */
#define H_USED      1       /* Second entry holds number of used */
#define H_OFFSET    2       /* Offset to real start of list */
#define H_INCR      16      /* Grow handle list in chunks this size */

/************************************ Tunables ********************************/

#define WEBS_MAX_LISTEN     8           /**< Maximum number of listen endpoints */
#define WEBS_SMALL_HASH     31          /**< General small hash size */
#define WEBS_MAX_PASSWORD   32          /**< Default maximum password */

typedef int WebsHash;                       /* Returned by symCreate */
typedef unsigned int uint;
typedef int ssize;
typedef const char cchar;

#ifndef BITSPERBYTE
    #define BITSPERBYTE     ((int) (8 * sizeof(char)))
#endif

#ifndef BITS
    #define BITS(type)      ((int) (BITSPERBYTE * (int) sizeof(type)))
#endif


typedef enum WebsType {
    undefined   = 0,
    byteint     = 1,
    shortint    = 2,
    integer     = 3,
    hex         = 4,
    percent     = 5,
    octal       = 6,
    big         = 7,
    flag        = 8,
    floating    = 9,
    string      = 10,
    bytes       = 11,
    symbol      = 12,
    errmsg      = 13
} WebsType;


/**
    Value union to store primitive value types
 */
typedef struct WebsValue {
    union {
        char    flag;
        char    byteint;
        short   shortint;
        char    percent;
        long    integer;
        long    hex;
        long    octal;
        long    big[2];
#if ME_FLOAT
        double  floating;
#endif
        char    *string;
        char    *bytes;
        char    *errmsg;
        void    *symbol;
    } value;
    WebsType    type;
    uint        valid       : 8;
    uint        allocated   : 8;        /* String was allocated */
}WebsValue;


typedef struct WebsKey {
    struct WebsKey  *forw;                  /* Pointer to next hash list */
    WebsValue       name;                   /* Name of symbol */
    WebsValue       content;                /* Value of symbol */
    int             arg;                    /* Parameter value */
    int             bucket;                 /* Bucket index */
} WebsKey;


/* List of symbol tables */
typedef struct HashTable {              /* Symbol table descriptor */
    WebsKey     **hash_table;           /* Allocated at run time */
    int         inuse;                  /* Is this entry in use */
    int         size;                   /* Size of the table below */
} HashTable;


typedef void (*WebsAction)();

int wallocHandle(void *mapArg);
void *walloc(ssize num);
void wfree(void *mem); 
int wfreeHandle(void *mapArg, int handle);
void *wrealloc(void *mem, ssize num); 
void valueFree(WebsValue* v);
WebsValue valueString(char *value, int flags);
char *sclone(char *s);
WebsHash hashCreate(int size);
WebsKey *hashEnter(WebsHash sd, char *name, WebsValue v, int arg);
WebsValue valueSymbol(void *value);
int websDefineAction(WebsHash sd, cchar *name, void *fn);
WebsKey *hash(HashTable *tp, char *name);
WebsKey *hashLookup(WebsHash sd, char *name);


void helloActionHandler();
void cxdActionHandler();

void ActionHandler_1();
void ActionHandler_2();
void ActionHandler_3();
void ActionHandler_4();

#endif