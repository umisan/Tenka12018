#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <deque>

using namespace std;
typedef long long int ll;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if(n == 2)
  {
    cout << (a[1] - a[0]) << endl;
    return 0;
  }
  auto calc = [n](vector<ll> a)
  {
    deque<ll> deq;
    int r = 0;
    int l = n - 1;
    bool flag = false; 
    deq.push_front(a[l--]);
    deq.push_front(a[r++]);
    deq.push_front(a[l--]);
    while(l >= r)
    {
      if(flag)
      {
        //大きいものを追加
        if(r < l - 1)
        {
          deq.push_front(a[l--]);
          deq.push_back(a[l--]);
        }else{
          ll rc = deq.front();
          ll lc = deq.back();
          if(abs(rc - a[l]) < abs(lc - a[l]))
          {
            deq.push_back(a[l--]);
          }else{
            deq.push_front(a[l--]);
          }
        }
      }else{
        //小さいものを追加 
        if(r + 1 < l)
        { 
          deq.push_front(a[r++]);
          deq.push_back(a[r++]);
        }else{
          ll rc = deq.front();
          ll lc = deq.back();
          if(abs(rc - a[r]) < abs(lc - a[r]))
          {
            deq.push_back(a[r++]);
          }else{
            deq.push_front(a[r++]);
          }
        }
      }
      flag = !flag;
    }
    ll result = 0;
    for(int i = 0; i < n - 1; i++)
    {
      result += abs(deq[i] - deq[i + 1]);
    }
    return result;
  };
  ll result1 = calc(a);
  reverse(a.begin(), a.end());
  ll result2 = calc(a);
  ll result = result1 < result2 ? result2 : result1;
  cout << result << endl;
	return 0;
}
