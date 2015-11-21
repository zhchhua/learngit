#include<iostream>
#include<set>
using namespace std;
int main()
{
int sz[9]={2,1,3,5,4,6,3,5,6};
multiset<int> A(sz,sz+9);
cout<<A.size()<<endl;
multiset<int>::iterator it=A.begin();
while(it!=A.end())
{
cout<<(*it)<<" ";
it++;
}
cout<<endl;
return 0;
}
