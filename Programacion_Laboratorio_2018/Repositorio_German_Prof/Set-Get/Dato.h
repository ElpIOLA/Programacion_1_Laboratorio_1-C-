
typedef struct
{
    int a;
    char b[50];
}eDato;

int eDato_set_a(eDato*, int);
int eDato_set_b(eDato*, char*);

int eDato_get_a(eDato*);
char* eDato_get_b(eDato*);

