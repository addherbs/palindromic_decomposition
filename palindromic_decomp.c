#include <conio.h>
#include <stdio.h>
#include <string.h>

int increasing(int * A, int N){
  
    if(N==0 ||N==1){
        return 1;
    }
    else if(A[N-1]<=A[N]){
    return increasing(A,N-1);
    }
    else { 
        printf("N= %d",N);
        return 0;
    }
    
}

char* concat(const char *s1, const char *s2, const char *s3, const char *s4)
{
    char *result = malloc(strlen(s1)+strlen(s2)+strlen(s3)+strlen(s4)+1);//+1 for the null-terminator
    strcpy(result, s1);
    strcat(result, s2);
    strcat(result, s3);
    strcat(result, s4);
    return result;
}

char* subString (const char* input, int offset, int len, char* dest)
{
    int x=0;
    char test[100] = "";
  int input_len = strlen (input);

  if (offset + len > input_len)
  {
     return NULL;
  }

  strncpy (test, input + offset, len);
  strcpy(dest,test);

  return dest;
}

int checkPalindromeOfString(char str[], int low, int high)
{

    while (high > low)
    {   
        if (str[low++] != str[high--])
        {
            return 0;
        }
    }
    return 1;
}

	
void PalindromicDecomposition(char* str,char* out,int low,int n)
{
    char *change;
    char sub[100];
    if(low==n)
    {
        printf("%s\n",out);
        return;
    }
    for(int i=low;i<n;i++)
    {
        if(checkPalindromeOfString(str,low,i))
        {
            change = subString (str, low, i-low+1, sub);
			change = concat(out, " ", change, ",");
            PalindromicDecomposition(str,change,i+1,n);
        }
    }
}


signed main() {
    
    char str[100] = "";
    char out[100] = "";
    int low=0;
	int a[100],size=0,check;
	
	printf("Here is Task1: Increasing Order");
	while(size!=-1){        
		printf("\nEnter array size ");
		scanf("%d",&size);
		for(int i=0;i<size;i++){
			scanf("%d",&a[i]);
		}
		check=increasing(a,size-1);
		printf("%d\n",check);
                                        
    }
    
	printf("Here is Task3: Palindromic Decomposition");
    while(1){
        printf("Enter a string\n");
        gets(str);
        
        if((int)str[0]== 45 && (int)str[1]== 49 ){
            printf("Thank You!");
            break;
        }else{
            printf("The Palindromic Decomposition of the String, '%s' is: \n", str);
            int m=strlen (str);
            PalindromicDecomposition(str,out,low,m);
        }
        printf("\n");
    }
    
	return 0;
}