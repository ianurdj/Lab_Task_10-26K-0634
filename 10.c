
#include <stdio.h>
#include <string.h>

int countRepeat(char s[], int i){
    if (s[i + 1] == s[i])
        return 1 + countRepeat(s, i + 1);
    return 1;
}

void compress(char s[], int i, char out[], int j){
    int count;

    if (s[i] == '\0')
      {
        out[j] = '\0';
        return;
    }

    count = countRepeat(s, i);

    out[j] = s[i];
    out[j + 1] = count + '0';

    compress(s, i + count, out, j + 2);
}

void expand(char in[], int i, char out[], int j)
{
    int count, k;

    if (in[i] == '\0')
        {  
        out[j] = '\0';
        return;
    }

    count = in[i + 1] - '0';

    for (k = 0; k < count; k++){
        out[j + k] = in[i];

    expand(in, i + 2, out, j + count);
    }
}

int main()
{
    char str[100], comp[200], exp[100];

    printf("Original: ");
    scanf("%99s", str);

    compress(str, 0, comp, 0);

    printf("Compressed: %s\n", comp);

    expand(comp, 0, exp, 0);
    printf("Expanded: %s\n", exp);

    if (strcmp(str, exp) == 0){

    
        printf("Match: Yes\n");
    }
    else{
        printf("Match: No\n");
    }
    return 0;
}
