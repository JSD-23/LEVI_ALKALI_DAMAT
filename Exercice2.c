#include <stdio.h>

int maxProfit(int prix[], int prix_size){
    
    int prixMin = prix[0], profit=0;

    for(int i = 0; i < prix_size; i++)
    {
        if(prix[i] > prixMin)
        {
            if(profit > prix[i] - prixMin)
            {
                profit = profit;
            }
            else
            {
                profit = prix[i] - prixMin;
            }
        }
        else
        {
            prixMin = prix[i];
        }
    }

    return profit;
}
