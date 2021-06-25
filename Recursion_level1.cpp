#include<bits/stdc++.h>
using namespace std;

#define lli long long int 

// ####################### Recursion Pepcoding #######################

int power(int x, int n){
	if(n == 0)
		return 1;

	lli xpnb2 = power(x, n/2);
	lli ans = xpnb2*xpnb2;

	if(n%2)
		ans *= x;

	return ans;
}

int maxOfArr(vector<int> arr, int idx){
	if(idx == arr.size()-1)
		return arr[idx];

	int misa = maxOfArr(arr, idx+1);

	return max(misa, arr[idx]);
}

int firstIdx(vector<int> arr, int idx, int x){
	if(arr[idx] == x)
		return idx;
	if(idx == arr.size()-1)
		return -1;

	int first_occ = firstIdx(arr, idx+1, x);

	return first_occ;
}

int lstIdx(vector<int> arr, int idx, int x){
	if(idx == arr.size())
		return -1;

	int last_occ = lstIdx(arr, idx+1, x);

	if(last_occ != -1)
		return last_occ;
	if(arr[idx] == x)
		return idx;
	else
		return -1;
}

void allIdx(vector<int> arr, int idx, int x){
	if(idx == arr.size())
		return;
	if(arr[idx] == x)
		cout<<idx<<" ";

	allIdx(arr, idx+1, x);
}

vector<int> AllIdx(vector<int> arr, int idx, int x){
	if(idx == arr.size())
		return {};

	vector<int> ans = AllIdx(arr, idx+1, x);

	if(arr[idx] == x)
		ans.push_back(idx);
	return ans;
}

vector<int> ALLIdx(vector<int> arr, int idx, int x, int fsf){
	if(idx == arr.size())
		return vector<int>(fsf);

	if(arr[idx] == x){
		vector<int> ans = ALLIdx(arr, idx+1, x, fsf+1);
		ans[fsf] = idx;
		return ans;
	} else {
		vector<int> ans = ALLIdx(arr, idx+1, x, fsf);
		return ans;
	}
}

vector<string> getSs(string str){
	if(str.length() == 0)
		return {""};

	char start = str[0];
	
	string remaining = str.substr(1);

	vector<string> res = getSs(remaining);
	int size = res.size();

	for(int i=0; i<size; i++)
		res.push_back(start+res[i]);

	return res;
}


map<int, string> keypad = {{0,".;"}, {1,"abc"}, {2,"def"}, {3,"ghi"}, 
						   {4,"jkl"}, {5,"mno"}, {6,"pqrs"}, {7,"tu"}, 
						   {8,"vwx"}, {9,"yz"}};

vector<string> KPC(string nums){
	if(nums.length() == 0)
		return {""};

	char first = nums[0];
	string remaining = nums.substr(1);
	vector<string> ans = KPC(remaining);
	vector<string> myans;

	string str_key = keypad[first - '0'];
	for(char ch : str_key){
		for(string st : ans)
			myans.push_back(st+ch);
	}

	return myans;
}

vector<string> stairsPath(int x, int a, int b, int c){
	if(x == 0)
		return {""};
	if(x < 0)
		return {};

	vector<string> paths1 = stairsPath(x-a, a, b, c);
	vector<string> paths2 = stairsPath(x-b, a, b, c);
	vector<string> paths3 = stairsPath(x-c, a, b, c);

	vector<string> paths;
	char ac = a+'0';
	char bc = b+'0';
	char cc = c+'0';

	for(auto path: paths1)
		paths.push_back(ac+path);
	for(auto path: paths2)
		paths.push_back(bc+path);
	for(auto path: paths3)
		paths.push_back(cc+path);

	return paths;
}

// ***************************** Maze Paths *******************************
vector<string> getMazePaths(int sr, int sc, int dr, int dc){
	if(sr == dr && sc == dc)
		return {""};
	else if(sr > dr || sc > dc)
		return {};

	vector<string> paths_h = getMazePaths(sr, sc+1, dr, dc);
	vector<string> paths_v = getMazePaths(sr+1, sc, dr, dc);

	vector<string> paths;

	for(auto path : paths_h)
		paths.push_back("h"+path);
	for(auto path: paths_v)
		paths.push_back("v"+path);

	return paths;
 }

vector<string> getMazePathswJumps(int sr, int sc, int dr, int dc){
	// sr -> source row
	// sc -> source column
	// dr -> destination row
	// dc -> destination column

	if(sr == dr && sc == dc)
		return {""};
	else if(sr > dr || sc > dc)
		return {};

	vector<string> paths;
	for(int i=1; i<=dr-sr; i++){
		// horizontal move
		vector<string> paths_h = getMazePathswJumps(sr+i, sc, dr, dc);
		
		for(auto path : paths_h){
			string str = "h"+to_string(i);
			paths.push_back(path+str);
		}
	}

	for(int i=1; i<=dc-sc; i++){
		// vertical move
		vector<string> paths_v = getMazePathswJumps(sr, sc+i, dr, dc);

		for(auto path : paths_v){
			string str = "v"+to_string(i);
			paths.push_back(path+str);
		}
	}

	for(int i=1; i<=dr-sr && i<=dc-sc; i++){
		// diagonal move
		vector<string> paths_d = getMazePathswJumps(sr+i, sc+i, dr, dc);

		for(auto path : paths_d){
			string str = "d"+to_string(i);
			paths.push_back(path+str);
		}
	}
	
	return paths;
}
// ************************************************************************

void printSubS(string str){
	if(str.length() == 0)
		return;

	char st = str[0];
	string rem = str.substr(1);
	printSubS(rem);

	for(char ch : rem){
		string print(1, st);
		print+=(char)ch;
		cout<<print<<endl;
	}

	for(char ch: rem)
		cout<<ch<<endl;
}

void printSS(string ques, string ans){
	if(ques.length() == 0){
		cout<<ans<<endl;
		return;
	}

	char first = ques[0];
	string rem = ques.substr(1);

	printSS(rem, ans);
	printSS(rem, ans+first);
}

void print_KPC(string ques, string ans){
	if(ques.length() == 0){
		cout<<ans<<endl;
		return;
	}

	char first = ques[0];
	string rem = ques.substr(1);

	string keys = keypad[first-'0'];

	for(int i=0; i<keys.length(); i++)
		print_KPC(rem, ans+keys[i]);
}

void print_stairPaths(int x, int a, int b, int c, string ans){
	if(x == 0){
		cout<<ans<<endl;
		return;
	}else if(x < 0)
		return;

	char ac = a+'0';
	char bc = b+'0';
	char cc = c+'0';

	print_stairPaths(x-a, a, b, c, ac+ans);
	print_stairPaths(x-b, a, b, c, bc+ans);
	print_stairPaths(x-c, a, b, c, cc+ans);
}

void print_mazePaths(int sr, int sc, int dr, int dc, string ans){
	if(sr == dr && sc == dc){
		cout<<ans<<endl;
		return;
	}else if(sr > dr || sc > dc)
		return;

	print_mazePaths(sr+1, sc, dr, dc, ans+"h");
	print_mazePaths(sr, sc+1, dr, dc, ans+"v");
}

void print_mazePathswJumps(int sr, int sc, int dr, int dc, string ans){
	if(sr == dr && sc == dc){
		cout<<ans<<"\n";
		return;
	}

	for(int i=1; i<=dr-sr; i++){
		string str = "h";
		str+=to_string(i);
		print_mazePathswJumps(sr+i, sc, dr, dc, ans+str);
	}

	for(int i=1; i<=dc-sc; i++){
		string str = "v";
		str+=to_string(i);
		print_mazePathswJumps(sr, sc+i, dr, dc, ans+str);
	}

	for(int i=1; i<=dc-sc && i<=dr-sr; i++){
		string str = "d";
		str+=to_string(i);
		print_mazePathswJumps(sr+i, sc+i, dr, dc, ans+str);
	}
}

void print_perm(string str, string ans){
	if(str.length() == 0){
		cout<<ans<<endl;
		return;
	}

	char ch;
	string fst, scd;
	for(int i=0; i<str.length(); i++){
		ch = str[i];
		fst = str.substr(0, i);
		scd = str.substr(i+1);

		print_perm(fst+scd, ans+ch);
	}
}

void print_encodings(string ques, string ans){
	if(ques.length() == 0){
		cout<<ans<<endl;
		return;
	}else if(ques.length() == 1){
		char ch = ques[0];
		if(ch == '0')
			return;
		else{
			int chv = ch - '0';
			char chr = (char)(chv -1 + 'a');
			ans+=chr;
			cout<<ans<<endl;
		}
	}else{
		char ch = ques[0];
		if(ch == '0')
			return;
		else{
			int chv = ch - '0';
			char chr = (char)(chv -1 + 'a');
			string stripped_ques = ques.substr(1);
			print_encodings(stripped_ques, ans+chr);
		}
		string first = ques.substr(0, 2);
		string ros = ques.substr(2);

		stringstream ss(first);
		int x;
		ss>>x;

		if(x <= 26){
			char alphabet = (x - 1 + 'a');
			print_encodings(ros, ans+alphabet);
		}
		return;
	}
}

void floodFill(vector<vector<int>> maze, int r, int c, string ans, vector<vector<bool>> visited){
	if(r > maze.size() || c > maze[0].size() || r == maze.size() || c == maze[0].size() || maze[r][c] == 1 || visited[r][c] == true)
		return;
	if(r == maze.size()-1 && c == maze[0].size()-1){
		cout<<ans<<endl;
		return;
	}

	visited[r][c] = 1;
	floodFill(maze, r+1, c, ans+"d", visited);
	floodFill(maze, r, c+1, ans+"r", visited);
	floodFill(maze, r-1, c, ans+"t", visited);
	floodFill(maze, r, c-1, ans+"l", visited);
	visited[r][c] = 0;
}

void targetSumSubset(vector<int> powerSet, int k, int sum, string ans, int i){
	if(i == powerSet.size()){
		if(sum == k)
			cout<<ans<<endl;
		return;
	}

	targetSumSubset(powerSet, k, sum, ans, i+1);
	string new_ans = ans+to_string(powerSet[i])+" ";
	targetSumSubset(powerSet, k, sum+powerSet[i], new_ans, i+1);
}

bool isItaSafePlaceForTheQueen(vector<vector<int>> chess, int row, int col){
	// Vertical check
	for(int i = row-1; i>=0; i--)
		if(chess[i][col] == 1)
			return false;

	// Left diagonal check
	for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
		if(chess[i][j] == 1)
			return false;

	// Right diagonal check
	for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--, j++)
		if(chess[i][j] == 1)
			return false;

	return true;
}

void printNQueens(vector<vector<int>> chess, string qsf, int row){
	if(row == chess.size()){
		cout<<qsf<<endl;
		return;
	}

	for(int col=0; col<chess.size(); col++){
		if(isItaSafePlaceForTheQueen(chess, row, col) == true){
			chess[row][col] = 1;
			printNQueens(chess, qsf+to_string(row)+"-"+to_string(col)+", ", row+1);
			chess[row][col] = 0;
		}
	}
}

void displayBoard(vector<vector<int>> chess){
	for(int i=0; i<chess.size(); i++){
		for(int j=0; j<chess[0].size(); j++)
			cout<<chess[i][j]<<" ";
		cout<<"\n";
	}
}

void printKnightsTour(vector<vector<int>> chess, int r, int c, int move){
	if(r < 0 || c < 0 || r >= chess.size() || c >= chess.size() || chess[r][c] > 0)
		return;
	else if(move == chess.size()*chess.size()){
		chess[r][c] = move;
		displayBoard(chess);
		chess[r][c] = 0;
		return;
	}

	chess[r][c] = move;
	printKnightsTour(chess, r-2, c + 1, move+1);
	printKnightsTour(chess, r-1, c + 2, move+1);
	printKnightsTour(chess, r+1, c + 2, move+1);
	printKnightsTour(chess, r+2, c + 1, move+1);
	printKnightsTour(chess, r+2, c - 1, move+1);
	printKnightsTour(chess, r+1, c - 2, move+1);
	printKnightsTour(chess, r-1, c - 2, move+1);
	printKnightsTour(chess, r-2, c - 1, move+1);
	chess[r][c] = 0;
}

// ##########################################################################    

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	// cout<<power(2, 10)<<endl;
		// cout<<maxOfArr({3, 1, 0, 53, 20, 435, 45, 88}, 0)<<endl;
		// cout<<firstIdx({2, 8, 7, 8, 56, 4, 9}, 0, 44)<<endl;

		// cout<<lstIdx({2, 8, 7, 8, 56, 4, 9, 83, 4, 32}, 0, 32)<<endl;

		// allIdx({2, 8, 7, 8, 56, 4, 9, 83, 4, 32}, 0, 4);
		// vector<int> ans = AllIdx({2, 8, 7, 8, 56, 4, 9, 83, 4, 32}, 0, 32);

		// vector<int> ans = ALLIdx({2, 8, 7, 8, 56, 4, 9, 83, 4, 32}, 0, 32, 0);
		// for(int val : ans)
		// 	cout<<val<<" ";

		// vector<string> ans = getSs("abcd");
		// for(string val : ans)
		//  	cout<<val<<endl;

		// vector<string> ans = KPC("573");
		// for(string val : ans)
		// 	cout<<val<<endl;

		// vector<string> paths = stairsPath(7, 1, 2, 3);
		// vector<string> paths = getMazePaths(1, 1, 3, 3);

		// vector<string> paths = getMazePathswJumps(1, 1, 4, 3); // getMazePathswJumps(sr, sc, dr, dc)
		// for(auto path: paths)
		// 	cout<<path<<endl;
		// cout<<"\n\n\n";

		// printSubS("abc");
		// printSS("abc", "");
		// print_KPC("678", "");

		// print_stairPaths(5, 1, 2, 3, "");
		// print_mazePaths(1, 1, 4, 3, "");

		// print_mazePathswJumps(1, 1, 3, 3, "");

		// print_perm("abc", "");

		// print_encodings("12103", "");
		// int r, c;
		// cin>>r>>c;

		// vector<vector<int>> maze(r, vector<int> (c, 0));
		// for(int i=0; i<r; i++)
		// 	for(int j=0; j<c; j++)
		// 		cin>>maze[i][j];

		// vector<vector<bool>> visited(r, vector<bool> (c, false));
		// if(maze[r-1][c-1] == 1)
		// 	cout<<"[-] Not reachable...."<<endl;
		// else{
		// 	floodFill(maze, 0, 0, "", visited);
		// 	cout<<"[+] Completed!!"<<endl;
		// }

	targetSumSubset({10, 50, 20, 30, 40}, 40, 0, "", 0);

	// int n = 5;
	// vector<vector<int>> chess(n, vector<int>(n, 0));
	// // printNQueens(chess, "", 0);

	// printKnightsTour(chess, 2, 3, 1);

	return 0;
}