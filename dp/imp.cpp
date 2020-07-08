int evaluate_table(int i, int W, int n) {
    if (W < 0) return INF;
    if (i == n) {
        if (W == 0) return 0;
        return INF;
    }
    
    return mem[i][W];
    
}

int coin_change_iterative(int n, int target) {
    for (int i = n - 1;i >= 0;i--) {
        for (int w = 0; w <= target; w++) {
            
            int res_1 = 1 + evaluate_table(i + 1, w - C[i], n);
            int res_2 = evaluate_table(i + 1, w, n);
            mem[i][w] = min(res_1, res_2);
        }
    }
    
    return mem[0][target];
}