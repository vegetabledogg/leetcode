bool isValid(char* s) {
    int length = strlen(s);
    int *stack = (int*)malloc(length * sizeof(int));
    int i, top = -1;
    for(i = 0; i < length; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stack[++top] = s[i];
        }
        else{
            if(-1 == top){
                return false;
            }
            else if(stack[top] == '(' && s[i] == ')'){
                top--;
            }
            else if(stack[top] == '[' && s[i] == ']'){
                top--;
            }
            else if(stack[top] == '{' && s[i] == '}'){
                top--;
            }
            else{
                return false;
            }
        }
    }
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}
