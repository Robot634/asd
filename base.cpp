//База


//euler function
ll phi(ll n) {
	ll result = n;
	for (ll i = 2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}



//self-written lower_bound
typedef long long ll;
ll lower_bound_(const vector<ll> &mas, const ll &value){
  ll l = 0, r = mas.size() - 1;
  while (l < r){
    ll m = (r - l)/2;
    if (mas[m] >= value)
      r = m;
    else
      l = m + 1;
  }
  return mas[l] == value ? l : -1;
}

//pref_sums
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i = 0; i<n; i++)cin>>a[i];
    vector<ll>pref(n+1, 0);
    for(ll i = 0; i<a.size(); i++){
        pref[i+1] = pref[i]+a[i];
    }



// the second line in the first: quantity
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int count = 0;
    for (int i = s1.size() - 1; i >= 0; i--) {
        if (s1.substr(i, s2.size()) == s2)
            count++;
    }


// решето эратосфена
bool is_prime[500001];
    for(ll i = 0; i<=500000; i++){
        is_prime[i] = true;
    }
    for(ll i = 2; i*i<= 500000; i++){
        for(ll j = i*i; j<=500000; j+=i){
            is_prime[j] = false;
        }
    }

//z-function
vector<ll> function_not_from_emax(string s){
    ll n = s.size();
    vector<ll>a(n);
    for (ll i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)a[i] = min (r-i+1, a[i-l]);
        while (i+a[i] < n and s[a[i]] == s[i+a[i]])a[i]++;
        if(i+a[i]-1 > r)l = i,  r = i+a[i]-1;
    }
    return a;
}
