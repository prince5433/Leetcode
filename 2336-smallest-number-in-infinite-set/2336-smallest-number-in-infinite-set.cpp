class SmallestInfiniteSet {
public:
    set<int> st;   // ordered set → hamesha sorted rahega

    SmallestInfiniteSet() {
        // initially set me 1 se 1000 tak saare numbers daal diye
        // constraints ke hisaab se itna kaafi hai
        for (int i = 1; i <= 1000; i++) {
            st.insert(i);
        }
    }
    
    int popSmallest() {
        // set ka begin() hamesha smallest element deta hai
        int x = *st.begin();

        // us smallest element ko set se hata dete hain
        st.erase(st.begin());

        // wahi smallest number return
        return x;
    }
    
    void addBack(int num) {
        // agar num already set me nahi hai
        // (matlab pehle pop ho chuka tha)
        if (st.find(num) == st.end()) {
            st.insert(num);   // wapas add kar do
        }
    }
};
