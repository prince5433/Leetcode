class Solution {
public:

    unordered_map<int,string> mp;
    int id=0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        id++;
        mp[id]=longUrl;
        return "http://tinyurl.com/"+to_string(id);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int id=stoi(shortUrl.substr(19));
        return mp[id];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));