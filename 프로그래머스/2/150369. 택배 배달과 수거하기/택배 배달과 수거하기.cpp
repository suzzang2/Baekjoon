#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    int deliLeft = 0, pickupLeft = 0;
    long long distance = 0;

    for (int d : deliveries) deliLeft += d;
    for (int p : pickups) pickupLeft += p;

    if (!deliLeft && !pickupLeft) return 0;

    int delEnd = n - 1, pickEnd = n - 1;

    while (deliLeft > 0 || pickupLeft > 0) {
        while (delEnd >= 0 && deliveries[delEnd] == 0) delEnd--;
        while (pickEnd >= 0 && pickups[pickEnd] == 0) pickEnd--;

        int dist = max(delEnd, pickEnd) + 1;
        distance += 2LL * dist;

        int capLeft = cap;

        // 배달
        for (int i = delEnd; i >= 0 && capLeft > 0; --i) {
            if (deliveries[i] == 0) continue;
            int take = min(deliveries[i], capLeft);
            deliveries[i] -= take;
            deliLeft -= take;
            capLeft -= take;
        }

        capLeft = cap;

        // 수거
        for (int i = pickEnd; i >= 0 && capLeft > 0; --i) {
            if (pickups[i] == 0) continue;
            int take = min(pickups[i], capLeft);
            pickups[i] -= take;
            pickupLeft -= take;
            capLeft -= take;
        }

        // 디버깅 출력 원하면 아래 주석 해제
        // cout << "[ "; for (int n : deliveries) cout << n << " "; cout << "]\n";
        // cout << "[ "; for (int n : pickups) cout << n << " "; cout << "]\n";
        // printf("distance +%d\n", 2 * dist);
    }

    return distance;
}
