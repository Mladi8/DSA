#include<iostream>
#include<vector>
using namespace std;



void merge(vector<int>&b,vector<int>&c,vector<int>&a,int p,int q){
    int i=0;
    int j=0;
    int k=0;
    while(i<p&&j<q){
        if(b[i]<=c[j]){
            a[k]=b[i];
            i++;
        }
        else{
            a[k]=c[j];
            j++;
        }
        k++;
    }
    if(i==p){
        while (j<q)
        {
            a[k]=c[j];
            k++;
            j++;
        }
    
        
    }
    else{
        while (i<p)
        {
             a[k]=b[i];
             k++;
             i++;
        }
        
    }
}

void mergesort(vector<int>&a,int n){
    if(n<=1){
        return;
    }
    int len=n/2;

    vector<int>b(len);
    vector<int>c(n-len);

    for(int i=0;i<len;i++){
        b[i]=a[i];
    }
    for(int i=len;i<n;i++){
        c[i-len]=a[i];

    }
    mergesort(b,len);
    mergesort(c,n-len);
    merge(b,c,a,len,n-len);
}
int main()
{
vector<int> a={4,6,3,9,8,2};
int n=a.size();
cout<<"Before sorting\n";
for(int i=0;i<n;i++){
    cout<<a[i]<<"\t";
}
mergesort(a,n);

cout<<"\n After sorting\n";
for (int i = 0; i < n; i++)
{
    /* code */
    cout<<a[i]<<"\t";
}


    return 0;
}