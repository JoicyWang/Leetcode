class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        std::map<int, int> start_indexes;
        for (int i = 0; i < intervals.size(); i++) {
            start_indexes.emplace(intervals[i].start, i);
        }
        vector<int> result;
        for (auto& interval : intervals) {
            auto lower_bound_it = start_indexes.lower_bound(interval.end);
            result.push_back(lower_bound_it == start_indexes.end() ? -1 : lower_bound_it->second);
        }
        return result;
    }
};