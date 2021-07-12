#include <iostream>
#include <vector>
using namespace std;

void fill_ones_rows(vector<vector<int>>& mat) {
	vector<int> rows;
	vector<int> row_of_ones(mat[0].size());
	fill(row_of_ones.begin(), row_of_ones.end(), 1);

	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat[i].size(); j++) {
			if(mat[i][j] == 1) {
				rows.emplace_back(i);
				break;
			}
		}
	}

	for(int i=0; i<rows.size(); i++)
		mat[rows[i]] = row_of_ones;
}

void print_matrix(vector<vector<int>> &arr)
{
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
	printf("\n");
}

int main() {
	vector<vector<int>> bool_mat;
	int num_test_cases;
	
	cin >> num_test_cases;
	while(num_test_cases) {
		int m, n;
		cin >> m >> n;
		bool_mat.assign(m, std::vector<int>(n));

		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				int temp;
				cin >> temp;
				bool_mat[i][j] = temp;
			}
		}

		fill_ones_rows(bool_mat);
		print_matrix(bool_mat);

		num_test_cases--;
	}

	return 0;
}