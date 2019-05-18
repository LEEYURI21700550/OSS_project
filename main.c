#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    UNDEFINED = 0,
    OBJECT = 1,
    ARRAY = 2,
    STRING =3,
    PRIMITIVE = 4
}type_t;

typedef struct {
    type_t type;
    int start;
    int end;
    int size;
}tok_t;


char* readfile(char* filename, int* filesize)
{
    FILE* fp = fopen(filename, "r");

    if (fp ==  NULL){
        printf("WRONG FILENAME\n");
        return NULL;
    }

    int size;
    char* buffer;

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = (char*)malloc(size+1);
    memset(buffer, 0, size+1);

    if(fread(buffer,1, size, fp)<1){
        *filesize = 0;
        free(buffer);
        fclose(fp);
        return NULL;
    }

    *filesize = size;

    fclose(fp);

    return buffer;

}

void json_parse(char *doc, int size)
{
    int pos = 0;

    while(pos < size)
    {
        switch(doc[pos])
        {
            case '"':
             while(doc[pos+1]!= '"'){
                 printf("%c", doc[pos+1]);
                 pos++;
                 
             }break;
             
            
            default:
             pos++;
        }
    }
}

int main(int argc, char** argv)
{
    int filesize=0;
    char* doc = readfile(argv[1], &filesize);
    int i=0;

    if(doc == NULL){
        printf("NULL");
        return -1;
    }

    //json_parse(doc, filesize);


    while(doc[i]){
        printf("%c", doc[i]);
        i++;
    }


    return 0;
}