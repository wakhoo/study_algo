#include<iostream>

int findCombination(int K, int *tri)
{
    for(int i = 1; i <= 44; i++) {
        for (int j = 1; j <= 44; j++) {
            for (int k = 1; k <= 44; k++) {
                if (tri[i] + tri[j] + tri[k] == K) {
                    return 1;
                }
            }
        }
    }
 
    return 0;
}
 
int main() {
 
    int N;
    std::cin >> N;
    int K;
    int tri[45];

    for (int i = 0; i <= 44; i++) {
        tri[i] = i * (i + 1) / 2;
    }
 
    for (int i = 0; i < N; i++) {
        std::cin >> K;
        std::cout << findCombination(K, tri) << std::endl;
    }
    return 0;
}
