int lengthOfLastWord(char* s){

    int i=strlen(s)-1;

    while(i>=0 && s[i]==' ')
        i--;

    int len=0;

    while(i>=0 && s[i]!=' '){

        len++;
        i--;
    }

    return len;
}