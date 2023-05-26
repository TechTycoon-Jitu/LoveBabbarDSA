#include <bits/stdc++.h> 
int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N)
{
	long long int deficite = 0;
    long long int balance =0;
    long long int start = 0;
    for(int i=0;i<N;i++)
    {
        balance +=petrol[i]-distance[i];
        if(balance<0)
        {
            deficite +=balance;
            start = i+1;
            balance = 0;
        }
    }
    if(deficite+balance>=0)
    {
        return start;
    }
    else{
        return -1;
    }
}
