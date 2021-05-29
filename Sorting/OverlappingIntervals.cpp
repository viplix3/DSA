#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> interval_1, pair<int, int> interval_2)
{
    return (interval_1.first < interval_2.first);
}

int mergeOverlappingInvervals(vector<pair<int, int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), comparator);
    int resultIdx = 0;

    for(int i=1; i<intervals.size(); i++){
        if(intervals[resultIdx].second >= intervals[i].first){
            intervals[resultIdx].first = min(intervals[resultIdx].first, intervals[i].first);
            intervals[resultIdx].second = max(intervals[resultIdx].second, intervals[i].second);
        }
        else{
            resultIdx += 1;
            intervals[resultIdx] = intervals[i];
        }
    }
    return resultIdx+1;
}

void printIntervals(vector<pair<int, int>> &intervals, int size)
{
    for(int i=0; i<size; i++)
        printf("{%d, %d}\n", intervals[i].first, intervals[i].second);
    printf("\n");

}

int main(){
    vector<pair<int, int>> test_intervals;
    int numMergedIntervals;

    test_intervals = {  {1, 3},
                        {2, 4},
                        {5, 7},
                        {6, 8}};
    printf("\nInput intervals\n");
    printIntervals(test_intervals, test_intervals.size());
    numMergedIntervals = mergeOverlappingInvervals(test_intervals);
    printf("After merging overlapping intervals\n");
    printIntervals(test_intervals, numMergedIntervals);

    test_intervals = {  {5, 10},
                        {3, 15},
                        {18, 30},
                        {2, 7}};
    printf("\nInput intervals\n");
    printIntervals(test_intervals, test_intervals.size());
    numMergedIntervals = mergeOverlappingInvervals(test_intervals);
    printf("After merging overlapping intervals\n");
    printIntervals(test_intervals, numMergedIntervals);
    
    test_intervals = {  {7, 9},
                        {6, 10},
                        {4, 5},
                        {1, 3},
                        {2, 4}};
    printf("\nInput intervals\n");
    printIntervals(test_intervals, test_intervals.size());
    numMergedIntervals = mergeOverlappingInvervals(test_intervals);
    printf("After merging overlapping intervals\n");
    printIntervals(test_intervals, numMergedIntervals);
       
    
    return 0;
}