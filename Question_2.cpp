#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCourses(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });
//intializing 
    int currentTime = 0;
    int courseCount = 0;

    for (const auto& course : courses) {
        if (currentTime + course[0] <= course[1]) {
            currentTime += course[0];
            courseCount++;
        }
    }

    return courseCount;
}
//calling function
int main() {
    int n;
    cin >> n;
    vector<vector<int>> courses(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> courses[i][0] >> courses[i][1];
    }

    cout << maxCourses(courses) << endl;
    return 0;
}

