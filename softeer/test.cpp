#include<iostream>
#include<vector>

using namespace std;



void dfs(int iter, int n, int ex, vector<int> visited, vector<int> secret, vector<int> user){


	if (iter == n){

		cout << "secret" << endl;
		exit(0);

	}
	else{


		for(int i =0 ; i < user.size() ; ++i){


			if(visited[i] == 0){
				
					if (secret[iter] == user[i]){
											
						for(int j =0 ; j <= i ; ++j){
							visited[j] = 1;
						}

						

						asdasd
eee
asd
						cout << "foud:" ;
						cout << secret[iter] << " ";
						cout << endl;

						dfs(iter+1, n, i, visited, secret, user);
						cout << endl;

						for(int j = ex; j <= i ; ++j)
							visited[j] = 0;
					}
				
			}
		}
	}
	
}

int main(int argc, char** argv)
{

	int M, N, K;
	cin >> M >> N >> K;

	vector<int> secret(M,0);
	for(int i =0 ; i < M ; ++i){
		cin >> secret[i];
	}

	vector<int> user(N,0);
	for(int i=0 ; i < N ; ++i){
		cin >> user[i];
	}


	vector<int> visited(N,0);
	vector<int> ans(M,0);

	dfs(0, M, -1, visited, secret, user);
	cout << "normal" << endl;

	return 0;
}