class Solution {
public:
    // Map to store: id -> original long URL
    unordered_map<int, string> mp;

    // Unique ID for each URL
    int id = 0;

    // Encodes a URL to a shortened URL
    string encode(string longUrl) {
        id++;                 // generate new id
        mp[id] = longUrl;     // store mapping
        return "http://tinyurl.com/" + to_string(id); // create short URL
    }

    // Decodes a shortened URL to its original URL
    string decode(string shortUrl) {
        // remove "http://tinyurl.com/" (19 chars) and get id
        int id = stoi(shortUrl.substr(19));
        return mp[id];        // return original URL
    }
};
