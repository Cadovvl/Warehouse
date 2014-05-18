#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iterator>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

void getNeighbourSwap(vi permutation, vvi& neibhours){
	int n = permutation.size();
	
	vi::iterator end = permutation.end();
	vi::iterator it = permutation.begin();
	++it;
	--end;
	for(; it != end; ++it)
		for(vi::iterator jt = it; ++jt != end; ){
			swap(*it,*jt);
			neibhours.push_back(permutation);
			swap(*it,*jt);
		}
}


long CalculatePatchLength(vvi matrix, vi permutation, vi path){
	long res = 0;
	vi::iterator it = path.begin();
	vi::iterator jt = it;
	++jt;
	vi::iterator end = path.end();
	for(; jt != end; ++it,++jt){
		res += matrix[permutation[*it]][permutation[*jt]];
	}
	return res;
}



template<typename Func,typename Uns>
void (vvi matrix,vi permutation,Func f );



int main(){
	/*
	vi v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vvi rv;

	getNeighbourSwap(v,rv);

	vvi::iterator end = rv.end();
	for (vvi::iterator it = rv.begin(); it != end; ++it){
		copy(it->begin(), it->end(), ostream_iterator<int>(cout," "));
		cout << endl;
	}
	*/

	cin.get();
}