
// https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        vector<string> itenary;
        int size = tickets.size();
        if(size == 0) return itenary;

        unordered_map<string, multiset<string>> mp;
        for(auto ticket : tickets){
            string sourceCity = ticket[0];
            string destinationCity = ticket[1];
            mp[sourceCity].insert(destinationCity);
        }
        
        stack<string> st;
        st.push("JFK");
        while(!st.empty()){
            auto currentCity = st.top();

            if(mp[currentCity].size() == 0){
                itenary.push_back(currentCity);
                st.pop();
            }else{
                auto nextCity = mp[currentCity].begin();
                st.push(*nextCity);
                mp[currentCity].erase(nextCity);
            }
        }

        reverse(itenary.begin(), itenary.end());
        return itenary;

    }
};