bool isValidSerialization(char* preorder) {
    int node = 0, nullNode = 0, i;
    for (i = 0; i < strlen(preorder); i++)
    {
        if ('#' == preorder[i])
        {
            nullNode++;
        }
        else
        {
            node++;
        }
        for ( ; i < strlen(preorder); i++)
        {
            if (',' == preorder[i])
            {
                break;
            }
        }
        if (nullNode > node && i < strlen(preorder) - 1)
        {
            return false;
        }
    }
    if (nullNode > node)
    {
        return true;
    }
    else
    {
        return false;
    }
}
