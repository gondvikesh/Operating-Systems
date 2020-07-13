#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>v;
	int n,value,seek_time=0,lower,upper,head,index;
	cout<<"Enter lower bound:\n";
	cin>>lower;
	cout<<"\n";
	
	cout<<"Enter upper bound:\n";
	cin>>upper;
	cout<<"\n";
	
	cout<<"Enter initial head position:\n";
	cin>>head;
	cout<<"\n";
	
	cout<<"Enter the number of sequence elements:\n";
	cin>>n;
	cout<<"\n";
	
	cout<<"Enter the elements:\n";
	for(int i=0;i<n;i++)
	{
		cin>>value;
		v.push_back(value);
	}
	v.push_back(head);
	sort(v.begin(),v.end());

	for(int i=0;i<v.size();i++)
	{
		if(v[i]==head){
		index=i;
		break;
		}
	}
	
	for(int i=index+1;i<v.size();i++)
	{
	seek_time=seek_time+abs(head-v[i]);
	head=v[i];
	}
	
	for(int i=index-1;i>=0;i--)
	{
	seek_time=seek_time+abs(head-v[i]);
	head=v[i];
	}
	
	cout<<"Total Seek movement:\n "<<seek_time;
	return 0;
}
	
