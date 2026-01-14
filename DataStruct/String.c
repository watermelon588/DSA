#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

//global variables
int vowels[5] = {'A','E','I','O','U'};
int special[]={' ','!','@','#','$','%','^','&','*','(',')',',','.','?','/',1,2,3,4,5,6,7,8,9,0};

// Length
int Length(char A[]){
    int i;
    for(i=0;A[i] != '\0';i++){
    }i--;
    return i;
}
// space count
int space(char A[]){
    int i,j,space=0;
    for(i=0;A[i] != '\0';i++){
        for(j=0;j<15;j++){
                if(A[i] == special[j]){
                    space+=1;
                }
        }
    }
    return space;
}
int Len(char A[]){
    int len = strlen(A);
    return len;
}
// Display Str Array
void display(char A[]){
    int i;
    for(i=0;A[i]!= '\0';i++){
        printf("%c ",A[i]);
    }
}
// Case changing
void casechange(char A[],int x){
    int i;
    for(i=0;A[i] != '\0';i++){
        if(A[i] != ' ' ){
            if(x == 1){
                A[i] = toupper(A[i]);
            }else if(x == 2){
                A[i] = tolower(A[i]);
            }
            else{
                printf("invalid input !");
            }
        }
    }
}
// Vowel / Consonent count
int vowelCount(char A[]){

    int i,j,count=0;
    for(i=0;A[i] != '\0';i++){
        if(A[i] != ' ' ){
            for(j=0;j<5;j++){
                if(toupper(A[i]) == vowels[j]){
                    count+=1;
                }
            }
        }
    }
    return count;
}
// Word Count
int wordCount(char A[]){
    int i,j,count=0;
    for(i=0;A[i] != '\0';i++){
        count ++;
    }
    return count;
}
// Reversing
void reverse(char A[]){
    int i,j,temp;
    for(j=0;A[j]!='\0';j++){

    }
    j--;
    for(i=0;i<j;i++,j--){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}
// Palindrome
int isPalindromeWord(char word[]) {
    int i = 0, j = strlen(word) - 1;
    while(i < j) {
        if(tolower(word[i]) != tolower(word[j]))
            return 0;
        i++;
        j--;
    }
    return 1;
}
void palindromeWords(char A[]) {
    char temp[100];
    int i = 0, j = 0, found = 0;

    while(A[i] != '\0') {
        if(isalpha(A[i])) {
            temp[j++] = A[i];
        }
        else {
            if(j > 0) {
                temp[j] = '\0';
                if(isPalindromeWord(temp)) {
                    printf("%s is a palindrome word\n", temp);
                    found = 1;
                }
                j = 0;
            }
        }
        i++;
    }

    // Check last word
    if(j > 0) {
        temp[j] = '\0';
        if(isPalindromeWord(temp)) {
            printf("%s is a palindrome word\n", temp);
            found = 1;
        }
    }

    if(!found) {
        printf("No palindrome words found.\n");
    }
}

// Duplicate find using hash
void duplicate(char A[]){
    int hash[26];
    int i,idx;
    int found = 0;
    for(i=0;i<26;i++){
        hash[i] = 0;
    }
    for(i=0;A[i]!='\0';i++){
        idx = tolower(A[i])-97;
        hash[idx]+=1;
    }
    for(i=0;i<26;i++){
        if(hash[i] > 1){
            printf("%c:",(i+97));
            printf(" %d\n",hash[i]);
            found++; 
        }
    }
    if(found == 0){
        printf("No duplicate characters found.\n");
    }
}
void anagram(char A[],char B[]){
    int i,hash[26],idx,found=0;
    for(i=0;i<26;i++){
        hash[i] = 0;
    }
    int la=Length(A);
    int lb=Length(B);
    if(la != lb){
        printf("\nstrings are NOT Anagrams !\n");
    }
    for(i=0;A[i]!='\0';i++){
        idx = tolower(A[i])-97;
        hash[idx] += 1;
    }
    for(i=0;B[i]!='\0';i++){
        idx = tolower(B[i])-97;
        hash[idx] -= 1;
    }
    for(i=0;i<26;i++){
        if(hash[i] != 0){
            printf("\nstrings are NOT Anagrams !\n");
        }else{
            found+=1;
        }
    }
    if(found != 0){
        printf("\nstrings are Anagram !\n");
    }
    
}
int main(){
    char A[100],str1[25],str2[25];
    int choice,i,l,x,s,vowel,consonent,w,word,check;
    printf("Enter String :");
    fgets(A,sizeof(A),stdin);
    do
    {
        printf("\n________________ MENU _________________\n");
        printf("1. Length \n");
        printf("2. Case Change\n");
        printf("3. Vowel/consonent count\n");
        printf("4. Word count\n");
        printf("5. Reverse \n");
        printf("6. Pallindrome check \n");
        printf("7. Duplicate find \n");
        printf("8. Anagram \n");
        printf("9. ... \n");
        printf("10. ... \n");
        printf("11. ... \n");
        printf("12. Exit \n");
        printf("\n_________________________________________________________________________\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            l=Length(A);
            printf("Length of string : %d",l);
            printf("\n");
            display(A);
            break;
        case 2:
            printf("1. uppercase\n2. lowercase \n");
            printf("1/2 ? :");
            scanf("%d", &x);
            casechange(A,x);
            display(A);
            break;
        case 3:
            l=Length(A);
            s=space(A);
            vowel = vowelCount(A);
            printf("Vowel Count : %d\n",vowel);
            consonent = l-(s+vowel);
            printf("Consonent Count : %d",consonent);
            printf("\n");
            display(A);
            break;
        case 4:
            w = wordCount(A)-1;
            s=space(A);
            word = w-s;
            printf("Word Count : %d\n",word);
            printf("Special Count(space incl.) : %d\n",s);
            printf("\n");
            display(A);
            break;
        case 5:
            reverse(A);
            printf("Reverse String : ");
            display(A);
            break;
        case 6:
            printf("Palindrome words in the sentence:\n");
            palindromeWords(A);
            break;
        case 7:
            printf("Duplicate char check : \n");
            duplicate(A);
            break;
        case 8:
            printf("Enter 2 separate strings \n");
            printf("Enter str 1:");
            fgets(str1,sizeof(str1),stdin);
            printf("Enter str 2:");
            fgets(str2,sizeof(str2),stdin);
            anagram(str1,str2);
            break;
        case 12:
            printf("Exitting ...");
            break;
        default :
            printf("Invalid input !\n");
            break;
        }
    }while(choice != 12);
    return 0;
}