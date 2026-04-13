class AuthenticationManager {
private:
    int ttl;
    unordered_map<string, int> tokenExpiry; // tokenId -> expiration time (current + ttl)
    set<pair<int, string>> byExpiry;

    bool isActive(const string& tokenId, int time) {
        return tokenExpiry.count(tokenId) && tokenExpiry[tokenId] > time;
    }

    void cleanup(int time) {
        while (!byExpiry.empty() && byExpiry.begin()->first <= time) {
            tokenExpiry.erase(byExpiry.begin()->second);
            byExpiry.erase(byExpiry.begin());
        }
    }
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        if (tokenExpiry.count(tokenId)) {
            byExpiry.erase({tokenExpiry[tokenId], tokenId});
        }
        tokenExpiry[tokenId] = currentTime + ttl;
        byExpiry.insert({currentTime + ttl, tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        if (isActive(tokenId, currentTime)) {
            byExpiry.erase({tokenExpiry[tokenId], tokenId});
            tokenExpiry[tokenId] = currentTime + ttl;
            byExpiry.insert({currentTime + ttl, tokenId});
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        cleanup(currentTime);
        return byExpiry.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */