class ProductOfNumbers {
public:
    vector<int> prefixProduct;

    ProductOfNumbers() {
        // 1 se start, taaki prefix division easy rahe.
        prefixProduct = {1};
    }

    void add(int num) {
        if (num == 0) {
            // Zero ke baad kisi bhi range mein zero include hua,
            // toh product zero hoga. Naya prefix start karo.
            prefixProduct = {1};
        } else {
            // Previous product mein current number multiply karo.
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefixProduct.size();

        // Reset ke baad sirf n-1 numbers store hain.
        // Agar k unse zyada hain, toh range mein zero tha.
        if (k >= n) return 0;

        // Last k numbers ka product = total prefix / unwanted prefix.
        return prefixProduct[n - 1] / prefixProduct[n - 1 - k];
    }
};