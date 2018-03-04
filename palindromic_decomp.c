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

   // printf("isPalindrome String is: <--%s--> \n" , str);
    //   printf("Before Substring : %s, offset: %d, len: %d \n" , input, offset, len);

  if (offset + len > input_len)
  {
     return NULL;
  }

  strncpy (test, input + offset, len);
  strcpy(dest,test);
  
// //   dest = "";
//   for(x=0;x<len;x++){
//       test[x] = dest[x];
//   }
//   test[len] = '\0';
//   printf("after Substring: %s , len:%d, element:%c , newString:%s \n" , dest, strlen(dest),dest[len-1], test);
  
  
  return dest;
}

int checkPalindromeOfString(char str[], int low, int high)
{
    // printf("checkPalindromeOfString String is: <--%s--> \n" , str);
    
    // printf("lol first = %c, second= %c \n", str[low], str[h]);
    
    while (high > low)
    {   
		//printf("low=%d, h=%d, \n", low,h);
        if (str[low++] != str[high--])
        {
            // printf("low=%d, h=%d, \n", low,h);
            // printf("first = %c, second= %c \n", str[low], str[h]);
            return 0;
        }
        // printf("first = %c, second= %c \n", str[low], str[h]);
    }
    return 1;
}

	
void PalindromicDecomposition(char* str,char* out,int low,int n)
{
    char *change;
    char sub[100];
    // char *subchange = "";
    if(low==n)
    {
        printf("%s\n",out);
        return;
    }
    for(int i=low;i<n;i++)
    {
        if(checkPalindromeOfString(str,low,i))
        {
				//out+" "+str.substr(low,i-low+1)

//             printf("Current String: %s == OutPut String: %s == Going String: %s \n", str,out,change);
            change = subString (str, low, i-low+1, sub);
			change = concat(out, " ", change, ",");
            // printf("OutPut String: %s !!!! Sub String: %s \n",out,change);

            PalindromicDecomposition(str,change,i+1,n);
            // free(change);
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
// 			printf("Enter the array element %d : ",(i+1));
			scanf("%d",&a[i]);
		}
// 		printf("the array elements are:");
// 		for(int i=0;i<size;i++){
// 			printf("%d  ",a[i]);
// 		}
		check=increasing(a,size-1);
		printf("%d\n",check);
                                        
    }

	
    while(1){
        printf("Enter a string\n");
        gets(str);
        
        // printf("Value1: %d, Value2: %d",str[0], str[1] );
        
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