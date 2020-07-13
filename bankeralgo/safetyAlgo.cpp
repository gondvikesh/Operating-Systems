#include<bits/stdc++.h>
using namespace std;
class process
{
public:
int a,b,c;
bool done;
};


process request[5],allocation[5],available;
int main()
{
int ans[5];
cout<<"enter 5 processes allocation"<<endl;

cout<<"enter allocation a b c "<<endl;
for(int i=0;i<5;i++)
{
cin>>allocation[i].a>>allocation[i].b>>allocation[i].c;
}

cout<<"enter request of  a b c "<<endl;
for(int i=0;i<5;i++)
{
request[i].done=true;
cin>>request[i].a>>request[i].b>>request[i].c;
}

cout<<"enter avaliable"<<endl;
cin>>available.a>>available.b>>available.c;
int count=0;

	for(int j=0;j<5;j++)
{
for(int i=0;i<5;i++)
 {
if(request[i].a<=available.a and request[i].b<=available.b and  request[i].c<=available.c and request[i].done)
{
available.a+=allocation[i].a;
available.b+=allocation[i].b;
available.c+=allocation[i].c;
request[i].done=false;
cout<<"process"<<i<<"is done"<<endl;
count++;
}

}
	if(count==5)
	{
	cout<<"process done"<<endl;
	break;
	}	
  }

if(count<5)
cout<<"process is in deadlock"<<endl;

}
