int maxProfit(int* prices, int pricesSize) {
    int *min = (int*)calloc(pricesSize, sizeof(int));
    int profit = 0;
    int i;
    for (i = 0; i < pricesSize; i++)
    {
        if (0 == i)
        {
            min[i] = prices[i];
        }
        else
        {
            if (min[i - 1] > prices[i])
            {
                min[i] = prices[i];
            }
            else
            {
                min[i] = min[i - 1];
                if (profit < prices[i] - min[i - 1])
                {
                    profit = prices[i] - min[i - 1];
                }
            }
        }
    }
    return profit;
}
