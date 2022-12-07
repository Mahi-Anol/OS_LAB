#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
struct prcs{

    int id;
    int at;
    int bt;
};

void swp(prcs &a,prcs &b)
{
    prcs temp;

    temp.at=a.at;
    temp.bt=a.bt;
    temp.id=a.id;

    a.at=b.at;
    a.bt=b.bt;
    a.id=b.id;

    b.at=temp.at;
    b.bt=temp.bt;
    b.id=temp.id;

}
bool cmp(prcs a,prcs b)
{
    if(a.at==b.at)
    {
        if(a.bt==b.bt)return a.id<b.id;
        return a.bt<b.bt;
    }
    return a.at<b.at;
}

prcs jq[200];
int main()
{
    cout<<"Enter number of process: ";
    int n;
    cin>>n;
    
    cout<<"Now enter pID,A.T,B.T "<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>jq[i].id;
        cin>>jq[i].at;
        cin>>jq[i].bt;
    }
    
    sort(jq,jq+n,cmp);


    int st[n];//start time.
    int wt[n];
    int start=0;
    int tat[n];
    int ct[n];
    int rt[n];

    int sj=jq[0].at;

    for(int i=0;i<n;i++)
    {
       int sel=INT_MAX;
       int btx=INT_MAX;

       for(int j=i;j<n;j++)
       {
            if(jq[j].at<=sj && jq[j].bt<btx)
            {
                btx=jq[i].bt;
                sel=j;
            }
       }

       if(i!=sel)swp(jq[i],jq[sel]);

       if(jq[i].at>start)
       {
           st[i]=jq[i].at;
           start=jq[i].at+jq[i].bt;
       }
       else
       {
        st[i]=start;
        start=start+jq[i].bt;
       }
        wt[i]=st[i]-jq[i].at;
        tat[i]=wt[i]+jq[i].bt;
        ct[i]=st[i]+jq[i].bt;
        rt[i]=st[i]-jq[i].at;
        sj=ct[i];
    }

    for(int i=0;i<(8*16)+(8+1);i++)
    {
        cout<<"-";
    }
    cout<<endl;

    printf("|%-16s|%-16s|%-16s|%-16s|%-16s|%-16s|%-16s|%-16s|\n","Process id","Arrival Time","Burst Time","start time","completion time","waiting time","Turn around time","Response time");

     for(int i=0;i<(8*16)+(8+1);i++)
    {
        cout<<"-";
    }
    cout<<endl;
     for(int i=0;i<n;i++)
     {
        printf("|%-16d|%-16d|%-16d|%-16d|%-16d|%-16d|%-16d|%-16d|\n",jq[i].id,jq[i].at,jq[i].bt,st[i],ct[i],wt[i],tat[i],rt[i]);
     }
    for(int i=0;i<(8*16)+(8+1);i++)
    {
        cout<<"-";
    }
    cout<<endl;
      cout<<"Grant Chart: "<<endl;
     int s=0;
    for(int i=0;i<n;i++)
    {
        cout<<" ";
        for(int j=0;j<ct[i]-s;j++)
        {
            cout<<"---";
        }

        s=ct[i];
    }

    s=0; 
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"|";
        int num=(ct[i]-s);
        num*=3;
        int p=0;
        if(num%2==0)
        {
            p=(num/2)-1;
            
        }
        else
        {
            p=num/2;   
        }

        // cout<<p<<endl;
        for(int j=0;j<num;j++)
        {

            if(j==p)
            {
                cout<<"p"<<jq[i].id;
                num-=1;
            }
            else cout<<" ";
        }

        s=ct[i];


    }
    cout<<"|"<<endl;

    s=0;
    for(int i=0;i<n;i++)
    {
        cout<<" ";
        for(int j=0;j<ct[i]-s;j++)
        {
            cout<<"---";
        }

        s=ct[i];
    }

    cout<<endl;

    cout<<"0";
    s=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<ct[i]-s;j++)
       {
        cout<<"   ";
       }
       if(flag)cout<<"\b";
       cout<<ct[i];
       if(ct[i]>9)flag=1;
       s=ct[i];
    }
    cout<<endl;

    return 0;
}
