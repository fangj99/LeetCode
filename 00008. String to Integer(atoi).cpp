const int minLen = 11;
const int maxLen = 10;
const char strMin[] ="-2147483648";
const char strMax[] ="2147483647";
char tmp[1024];
int myAtoi(char *str) {
    int flag = 1,star = 0;
    int ans = 0;
    int len = (int)strlen(str);
    while(star < len && str[star] == ' ') star++;
    if(str[star] == '-' || str[star] == '+'){
        if(str[star] == '-'){
            flag = -1;
        }
        else{
            flag = 1;
        }
    }
    int end = star + (str[star]=='-'||str[star]=='+' ? 1 : 0);
    while(end < len && str[end]>='0' && str[end]<='9') end++;
    if(str[star] == '+') star++;
    memset(tmp, 0, sizeof(tmp));
    strncpy(tmp, str+star, end - star);
    if(star-1 >-1 && str[star-1] == '+') star--;
    int tmpLen = (int)strlen(tmp);
    if(flag == -1){
        if(tmpLen>minLen || (tmpLen == minLen && (strcmp(tmp, strMin) > 0))){
            return INT_MIN;
        }
    }
    else{
        if(tmpLen>maxLen || (tmpLen == maxLen && (strcmp(tmp, strMax) > 0))){
            return INT_MAX;
        }
    }
    if(str[star] == '-' || str[star] == '+') star++;
    for(int i = star,j;i<len;i++){
        j = str[i]-'0';
        if(j>=0 && j<=9){
            ans = (ans<<3) + (ans<<1);
            if(flag == -1) ans -= j;
            else ans += j;
        }
        else
            break;
    }
    return ans;
}

