//Name: Ayush
//Roll Number: 25/DA/018
//7. Write a program to solve the Activity Selection problem using the Greedy approach.
#include <iostream>
#include <algorithm>
using namespace std;

struct Activity{
    int start;
    int finish;
};

// Compare activities according to finish time
bool compare(Activity a, Activity b){
    return a.finish < b.finish;
}

int main(){
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity activities[100];
    cout << "Enter start time and finish time of each activity:\n";

    for (int i = 0; i < n; i++){
        cout << "Activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }

    // Sort activities according to finish time
    sort(activities, activities + n, compare);

    cout << "\nSelected activities:\n";

    // Select the first activity
    int lastFinish = activities[0].finish;

    cout << "Activity with start time "
         << activities[0].start
         << " and finish time "
         << activities[0].finish << endl;

    int count = 1;

    // Select remaining activities
    for (int i = 1; i < n; i++){
        // Activity can be selected if it starts
        // after or exactly when previous activity finishes
        if (activities[i].start >= lastFinish){
            cout << "Activity with start time "
                 << activities[i].start
                 << " and finish time "
                 << activities[i].finish << endl;

            lastFinish = activities[i].finish;
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count;

    return 0;
}