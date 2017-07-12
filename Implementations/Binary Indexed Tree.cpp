#include <bits/stdc++.h>
 
using namespace std;
 
const int SZ = 100000;
 
struct BinaryIndexedTree {
	int bit[SZ+1];
	
	BinaryIndexedTree() {
		memset(bit,0,sizeof bit);
	}
	
	void upd(int k, int val) {
		for( ;k <= SZ; k += (k&-k)) bit[k] += val;
	}
	 
	int query(int k) {
		int temp = 0;
		for (;k > 0;k -= (k&-k)) temp += bit[k];
		return temp;
	}
	
	int query(int l, int r) {
		return query(r)-query(l-1);
	}
};
 
int main() {
	BinaryIndexedTree b;
	b.upd(5,2);
	b.upd(4,1);
	cout << b.query(3,5);
}
 
