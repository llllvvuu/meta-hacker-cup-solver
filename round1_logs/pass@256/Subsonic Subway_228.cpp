
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
function check(mid_speed):
    time_elapsed = 0
    for each station_schedule (distance, A_i, B_i):
        # Adjust time to reach this station based on current speed
        expected_time = distance / mid_speed
        if expected_time < A_i or expected_time > B_i:
            return false
        # Update time_elapsed to reflect the last station's end timing within constraints
        time_elapsed = max(time_elapsed, expected_time)
    return true

function solve(N, station_schedule):
    sort station_schedule based on B_i in ascending order
    low_speed = 1e-9, high_speed = 1_000_000
    while high_speed - low_speed > 1e-9:
        mid_speed = (low_speed + high_speed) / 2
        if check(mid_speed):
            high_speed = mid_speed
        else:
            low_speed = mid_speed
    min_speed = (low_speed + high_speed) / 2
    if min_speed <= 1e-6:
        return -1
    return min_speed
