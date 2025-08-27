class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_diagonal_sq = 0;
        int max_area = 0;
        for (const auto& dim : dimensions) {
            int current_diagonal_sq = (dim[0] * dim[0]) + (dim[1] * dim[1]);
            int current_area = dim[0] * dim[1];

            if (current_diagonal_sq > max_diagonal_sq) {
                max_diagonal_sq = current_diagonal_sq;
                max_area = current_area;
            } else if (current_diagonal_sq == max_diagonal_sq) {
                max_area = std::max(max_area, current_area);
            }
        }
        return max_area;
    }
};