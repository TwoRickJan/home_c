 void print_digit(char s[]){
    int i = 0;    
    int a[10] = {0};
    while(s[i+1]!='\0')
       { if(s[i]>='0'&&s[i]<='9')
            a[s[i]-'0']++;
        i++;}
        
    for(int i=0;i<=9;i++)
        if(a[i]!=0)
            printf("%d %d\n",i,a[i]);}