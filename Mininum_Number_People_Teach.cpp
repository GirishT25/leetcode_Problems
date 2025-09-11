class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();  // number of users
        
        // Step 1: Store each user's languages in a set for quick lookup
        vector<unordered_set<int>> userLang(m + 1); 
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                userLang[i + 1].insert(lang); // users are 1-indexed
            }
        }
        
        // Step 2: Find problematic users (who cannot communicate with a friend)
        unordered_set<int> mustTeachUsers;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int lang : userLang[u]) {
                if (userLang[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                mustTeachUsers.insert(u);
                mustTeachUsers.insert(v);
            }
        }
        
        // If no problematic friendships → no teaching needed
        if (mustTeachUsers.empty()) return 0;
        
        // Step 3: Try teaching each language and compute minimum
        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int alreadyKnow = 0;
            for (int user : mustTeachUsers) {
                if (userLang[user].count(lang)) {
                    alreadyKnow++;
                }
            }
            ans = min(ans, (int)mustTeachUsers.size() - alreadyKnow);
        }
        
        return ans;
    }
};
