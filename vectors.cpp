#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
  std::vector<int> v;
  int n;
  cin>>n;
  int ele;
  for(int i=0;i<n;i++){
    cin>>ele;
    v.push_back(ele);
  }
  vector <int>:: iterator it;

  cout<<"\nthe vector array is:\n";
  for(it=v.begin();it!=v.end();++it){
    cout<<*it<<"\n";
  }

  int m=v.size();
  cout<<"\n length is:"<<m<<"\n";

  v.pop_back();
  cout<<"\n popped the last element\n";

  cout<<"\nnow the vector array is:\n";
  for(it=v.begin();it!=v.end();++it){
    cout<<*it<<"\n";
  }

  m=v.size();
  cout<<"\nnow the length is:"<<m<<"\n";
  return 0;
}
