
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        int n = tickets.size();
        if(n == 0) return ans;

        // creating the adjacency list
        unordered_map<string, multiset<string>> adj;
        for(int i = 0; i < n; i++){
            string sourceCity = tickets[i][0];
            string destinationCity = tickets[i][1];
            adj[sourceCity].insert(destinationCity);
        }

        // creating the iternaty
        stack<string> st;
        st.push("JFK");
        while(!st.empty()){
            auto currentCity = st.top();

                if(adj[currentCity].size() == 0){
                    ans.push_back(currentCity);
                    st.pop();
                }else{
                    auto nextCity = adj[currentCity].begin();
                    st.push(*nextCity);
                    adj[currentCity].erase(nextCity);
                }
            }
        

        reverse(ans.begin(), ans.end());
        return ans;
    }
};