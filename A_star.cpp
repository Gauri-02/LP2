#include <bits/stdc++.h>

using namespace std;

struct state {
	vector<vector<int>> matrix;
	int hn;
	int gn;
	state* parent;
};

struct compare {
	bool operator() (state* s1, state* s2) {
		return (s1->gn + s1->hn) > (s2->gn + s2->hn);
	}
};

class Eight_Puzzle {
	vector<vector<int>> initial;
	vector<vector<int>> end;
	priority_queue<state*, vector<state*>, compare> pq;

	int calcCost(vector<vector<int> > c) {
		int cost = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (c[i][j] != end[i][j]) {
					cost++;
				}
			}
		}
		return cost;
	}

	pair<int,int> getBlankTile(vector<vector<int> > c) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (c[i][j] == 0) {
					std::make_pair (i,j);
				}
			}
		}
	}

	state* makeState(vector<vector<int> > c, int gn, state* parent) {
		state* s = new state;
		s->matrix = c;
		s->gn = gn;
		s->hn = calcCost(c);
		s->parent = parent;	
		return s;
	}

	bool isSafe(int x, int y) {
		return (x >= 0 && x < 3 && y >= 0 && y < 3);
	}

	void makeMove(int x, int y, int nx, int ny, state* s) {
		vector<vector<int> > mat(s->matrix);
		swap(mat[x][y], mat[nx][ny]);
		state* newState = makeState(mat, s->gn + 1, s);
		pq.push(newState);
	}

	void printMatrix(vector<vector<int> > a) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
public:
	Eight_Puzzle(vector<vector<int> > i, vector<vector<int> > e) {
		initial = i;
		end = e;
		state* startstate = makeState(i, 0, NULL);
		pq.push(startstate);
	}

	void solve() {
		vector<int> rows{0, 1, 0, -1};
		vector<int> cols{1, 0, -1, 0};
		while (calcCost(pq.top()->matrix) != 0) {
			state* current = pq.top();
			pq.pop();
			pair<int,int> cords = getBlankTile(current->matrix);
			int x = cords.first;
			int y = cords.second;			
			for (int i = 0; i < 4; i++) {
				if (isSafe(x + rows[i], y + cols[i])) {
					makeMove(x, y, x + rows[i], y + cols[i], current);
				}
			}
		}
		vector<state*> ans;
		state* current = pq.top();
		while (current->parent) {
			ans.push_back(current);
			current = current->parent;
		}
		ans.push_back(current);
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			printMatrix(ans[i]->matrix);
			cout << "|" << endl;
			cout << "v" << endl;
		}
	}
};

bool isSolvable(vector<vector<int> > initial, vector<vector<int> > end) {
	vector<int> ini;
	vector<int> en;
	int ini_inversion_count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ini.push_back(initial[i][j]);
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (ini[i] && ini[j] && ini[i] > ini[j]) {
				ini_inversion_count++;
			}
		}
	}
	int en_inversion_count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			en.push_back(end[i][j]);
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (en[i] && en[j] && en[i] > en[j]) {
				en_inversion_count++;
			}
		}
	}
	return (en_inversion_count % 2) == (ini_inversion_count % 2);
}

int main() {
	vector<vector<int> > initial(3, vector<int>(3));
	vector<vector<int> > end(3, vector<int>(3));
	cout << "Enter the initial 8 puzzle configuration: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> initial[i][j];
		}
	}
	cout << "Enter the final 8 puzzle configuration: " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> end[i][j];
		}
	}
	if (!isSolvable(initial, end)) {
		cout << "Not Solvable" << endl;
		return 0;
	}
	Eight_Puzzle solve(initial, end);
	solve.solve();
}

