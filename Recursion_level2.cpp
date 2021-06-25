#include<bits/stdc++.h>
using namespace std;

#define lli long long int 

// Sort array using recursion
void insertArr(vector<int> &arr, int k){
	if(arr.size() == 0 || arr[arr.size()-1] <= k){
		arr.push_back(k);
		return;
	}

	int val = arr[arr.size()-1];
	arr.pop_back();
	insertArr(arr, k);
	arr.push_back(val);
}

void sortArr(vector<int> &arr){
	if(arr.size() == 1)
		return;

	int tmp = arr[arr.size()-1];
	arr.pop_back();
	sort(arr.begin(), arr.end());
	insertArr(arr, tmp);
}


// Sort stack using recursion
void insertStack(stack<int> &st, int k){
	if(st.empty() || st.top() <= k)
		st.push(k);
	else{
		int tp = st.top();
		st.pop();
		insertStack(st, k);
	}
}

void sortStack(stack<int> &st){
	if(st.size() == 1)
		return;

	int tp = st.top();
	st.pop();
	vector<int> v;

	while(!st.empty()){
		int val = st.top();
		v.push_back(val);
		st.pop();
	}
	sort(v.begin(), v.end());

	for(int i: v)
		st.push(i);

	insertStack(st, tp);
}

// ###################################### Recursion Pepcoding L2 ########################################

void combinations(int combs, int boxes, int selection_so_far, int total_selection, string as){
	if(combs == boxes){
		if(selection_so_far == total_selection)
			cout<<as<<endl;
		return;
	}

	combinations(combs+1, boxes, selection_so_far, total_selection, as+"-");
	combinations(combs+1, boxes, selection_so_far+1, total_selection, as+"i");
}

void comb_2(bool boxes[], int curr, int total, int lst, int n){  // Combinations using permutaion
	if(curr == total){
		for(int i=0; i<n; i++){
			if(boxes[i])
				cout<<"i";
			else cout<<"-";
		}cout<<endl;
		return;
	}

	for(int i=lst+1; i<n; i++){
		if(!boxes[i]){
			boxes[i] = true;	
			comb_2(boxes, curr+1, total, i, n);
			boxes[i] = false;
		}
	}
}
	
void permutations(vector<int> boxes, int curr, int total){
	if(curr > total){
		for(int v : boxes)
			cout<<v<<" ";
		cout<<"\n";
		return;
	}

	for(int i=0; i<boxes.size(); i++){
		if(!boxes[i]){
			boxes[i] = curr;
			permutations(boxes, curr+1, total);
			boxes[i] = 0;
		}
	}
}

// ######################################################################################################

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	// combinations(0, 4, 0, 2, "");  
	cout<<endl;
	vector<bool> vec(4, false);
	int n = 4;
	bool arr[n];
	// comb_2(arr, 0, 2, -1, n);  // n!/(n-r)!*r! = nPr
		//comb_2(bool boxes[], int curr, int total, int lst, int n)
	

	vector<int> v(n, 0);
	// permutations(v, 0, 4);  // n!/(n-r)!

	// vector<int> inp {7,34,6,3,7,4,7,3,8,4};
	// sortArr(inp);

	// for(int e:inp)
	// 	cout<<e<<" ";
	// cout<<endl;

	// Stack sort
	stack<int> st;
	st.push(4);
	st.push(6);
	st.push(2);
	st.push(1);
	st.push(8);

	sortStack(st);

	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}

	// Time taken
    cout<<"\nTime taken : "<<(double)clock()/CLOCKS_PER_SEC <<" sec"<<endl;

	return 0;
}