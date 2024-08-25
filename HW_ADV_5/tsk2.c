#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAX(c,b) (((c) < (b)) ? (b) : (c)) 


void zFunction(char *s, int z[]) {
	int n = strlen(s);
	for (int i=1; i<n; ++i){
		while ( i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if(z[i]==1)
		    z[i] = 0;
	}
}
void printa(int *array, int a_size)
{
	//int len = sizeof(array)/sizeof(int);
	for(int j = 0; j < a_size; j++)
	{
		printf("%d  ", array[j]);
	}
	printf("\n");
}
void creata(int *array, int a_size)
{
	for(int j = 0; j < a_size; j++)
	{
		array[j] = 0;
	}
}

void max_in_z(int z[],int size)
{
    int max = INT_MIN;
    for(int i = 0; i < size; i++)
        if (max != MAX(z[i],max))
		    max = MAX(z[i],max);
    printf("%d ",max);
}

char* prefix(char *w)
{
    return strtok(w,"_");
}

char* suffix(char *w)
{
    char *endptr3 = NULL;
	char *endptr = strtok (w,"_\n");
	while(1)
	{
	    endptr = strtok (NULL,"_\n");
	    if(!endptr)
	        break;
	    endptr3 = endptr;
	}
	return endptr3;
}


int main()
{
	//char w1[]="don't_panic";
	//char w2[]="nick_is_a_mastodon";
	//char w1[]="monty_python";
	//char w2[]="python_has_list_comprehensions";
	char w1[104];
	char w2[104];
	int i = 2;
	scanf("%104s%104s", w1,w2);


	

	char w1_copy[sizeof(w1)];
	char w2_copy[sizeof(w2)];
	strncpy(w1_copy, w1,strlen(w1));
	strncpy(w2_copy, w2,strlen(w2));
	char *p_pref_w1 = prefix(w1);
	char *p_suf_w2 = suffix(w2);
	
	char *p_suf_w1_c = suffix(w1_copy);
	char *p_pref_w2_c = prefix(w2_copy);
	
	
	char s[strlen(p_pref_w1)+strlen(p_suf_w2)+1];
	char s1[strlen(p_suf_w1_c)+strlen(p_pref_w2_c)+1];
	
	sprintf(s,"%s#%s",p_pref_w1,p_suf_w2);
	sprintf(s1,"%s#%s",p_pref_w2_c,p_suf_w1_c);
	
	
	int SIZE = strlen(s);
	int z[SIZE];
    creata(z,SIZE);
    zFunction(s,z);
    max_in_z(z,SIZE);
    
    SIZE = strlen(s1);
    int z1[SIZE];
    creata(z1,SIZE);
	zFunction(s1,z1);
	max_in_z(z1,SIZE);

	return 0;
}
