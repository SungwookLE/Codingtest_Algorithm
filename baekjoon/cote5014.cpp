#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class solver_5014{
	public:
	solver_5014(int _F, int _S, int _G, int _U, int _D){
		F = _F;
		S = _S;
		G = _G;
		U = _U;
		D = _D;
		
		floors = vector<int>(F+1,0);
		visited = vector<int>(F+1,0);		
		delta = {U, -D};
	}
	
	void BFS(){
		opens.push(S);
		visited[S] = 1;
		
		while(!opens.empty()){
			int now = opens.front();
			opens.pop();
			
			if (now == G){
				cout << floors[now] << endl;
				return;
			}
			
			for(auto d : delta){
				int next = now+d;
				if (next > 0 && next <= F && visited[next] == 0){
						floors[next] = floors[now] + 1;
						visited[next] = 1;
						opens.push(next);
				}
			}
		}
		
		cout << "use the stairs" << endl;
	}
		
	private:
	int F, S, G, U, D;
	vector<int> floors;
	vector<int> visited;
	queue<int> opens;
	vector<int> delta;
};

int main() {
	int F, S, G, U,D ;
    cin >> F >> S >> G >> U >> D;
	solver_5014 solver(F,S,G,U,D);
	solver.BFS();
 
	return 0;
}