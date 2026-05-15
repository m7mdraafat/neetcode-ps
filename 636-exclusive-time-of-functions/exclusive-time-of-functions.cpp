struct Log {
    int id;
    string type;
    int timestamp;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<Log> st;
        for (string log : logs) {
            stringstream ss(log);
            string id, type, timestamp;
            getline(ss, id, ':');
            getline(ss, type, ':');
            getline(ss, timestamp, ':');

            Log item = {stoi(id), type, stoi(timestamp)};
            if (item.type == "start") {
                st.push(item);
            } else {
                assert(st.top().id == item.id);

                int time_added = item.timestamp - st.top().timestamp + 1;
                times[item.id] += time_added;
                st.pop();

                if (!st.empty()) {
                    assert(st.top().type == "start");
                    times[st.top().id] -= time_added;
                }
            }
        }

        return times;
    }
};