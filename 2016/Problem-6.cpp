//note: this is not a completely working solution. There still is a problem for a particular case.

#include <iostream>
#include <vector>

using namespace std;

bool path(vector<vector<int>> loc, int p, int c) {
	c++;
	for (int k = 0; k < loc[p].size(); k++) {
		int q = loc[p][k];
		if (!q)
			return true;
		else if (c > loc.size())
			return false;
		return path(loc, q, c);
	}
}

int main(){
	int nLoc, n, nCalls = 0;
	bool wayHome = false;
	cin >> nLoc;
	cin.ignore(1, ' ');
	vector<vector<int>> loc(nLoc);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a;
		cin.ignore(1, ' ');
		cin >> b;
		loc[a].push_back(b);
	}
	for (int i = 1; i < loc.size(); i++) {
		int p;
		for (int j = 0; j < loc[i].size(); j++) {
			p = loc[i][j];
			if (!p) {
				wayHome = true;
				break;
			}
			wayHome = path(loc, p, nCalls);
		}
		if (!wayHome)
			break;
	}
	if (wayHome)
		cout << "home safe\n";
	else cout << "stranded\n";
    return 0;
}