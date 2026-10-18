class MinStack {
public:
    // Normal values ke saath encoded values bhi store karenge.
    // long long use kiya hai taaki encoding ke calculations mein
    // int range se bahar jaane par overflow ka risk kam ho.
    stack<long long> st;

    // Ye variable hamesha stack ka current minimum store karega.
    // Iske liye alag minimum stack maintain nahi karna padta.
    long long min;

    // Constructor: stack create hone par minimum ko
    // ek bahut badi value se initialize kar rahe hain.
    // First push ke time actual minimum set ho jayega.
    MinStack() {
        min = LLONG_MAX;
    }

    void push(int val) {
        // Input int hai, lekin calculations long long mein karenge.
        long long x = (long long)val;

        // CASE 1: Stack empty hai.
        // Abhi koi previous minimum nahi hai,
        // isliye x hi stack ka pehla aur minimum element hoga.
        if (st.size() == 0) {
            st.push(x);
            min = x;
        }

        // CASE 2: New value current minimum se greater ya equal hai.
        // Is value ko encode karne ki zarurat nahi hai,
        // kyunki isse current minimum change nahi hoga.
        else if (x >= min) {
            st.push(x);
        }

        // CASE 3: New value current minimum se chhoti hai.
        // Hume new minimum bhi store karna hai aur purana minimum
        // bhi future pop() ke liye recover kar paana hai.
        else {
            /*
                Maan lo:
                Previous minimum = oldMin
                New value = x

                Hum actual x ko directly store karne ke bajaye:
                encoded = 2*x - oldMin store karte hain.

                Is encoding ki wajah se encoded value,
                new minimum x se strictly chhoti hoti hai.

                Proof:
                x < oldMin

                Isliye:
                2*x - oldMin < x

                Matlab encoded < min.

                Baad mein agar stack top < current min hua,
                toh hume pata chal jayega ki top encoded value hai.
            */

            st.push(2 * x - min);

            // Ab x hi naya minimum hai,
            // kyunki x previous minimum se chhota tha.
            min = x;
        }
    }

    void pop() {
        /*
            Agar top current minimum se chhota hai,
            toh iska matlab top normal value nahi,
            balki encoded value hai.

            Aisa isliye kyunki encoding ke time:
            encoded = 2*x - oldMin
            aur encoded < x = current min.
        */

        if (st.top() < min) {

            /*
                Encoded value se previous minimum recover karenge.

                Encoding formula:
                encoded = 2*currentMin - oldMin

                Rearrange karne par:
                oldMin = 2*currentMin - encoded

                Isliye purana minimum restore ho jayega.
                Ye zaroori hai kyunki current minimum wala element
                ab stack se remove hone wala hai.
            */

            long long oldMin = 2 * min - st.top();

            // Previous minimum restore kar do,
            // taaki pop ke baad min remaining stack ke according correct rahe.
            min = oldMin;
        }

        // Ab top element remove kar do.
        // Agar top encoded tha, toh uska previous minimum
        // remove karne se pehle hi restore kar chuke hain.
        st.pop();
    }

    int top() {

        /*
            Agar top < min hai, toh top encoded value hai.
            Stack mein actual value store nahi hai,
            lekin woh actual value current minimum hi hai.

            Example:
            Actual pushed value = 3
            Encoded value = 1
            Current minimum = 3

            Stack top 1 return nahi karna,
            actual value 3 return karni hai.
        */

        if (st.top() < min)
            return (int)min;

        // Agar encoding condition nahi hai,
        // toh stack top hi actual element hai.
        else
            return st.top();
    }

    int getMin() {
        // Minimum ko hum har push/pop ke saath update karte hain,
        // isliye poora stack traverse karne ki zarurat nahi hai.
        return (int)min;
    }
};

/*
    KEY INTUITION:

    Normally minimum track karne ke liye do stacks use kar sakte hain:
    1. Actual elements ke liye
    2. Minimum values ke liye

    Lekin yahan hum ek hi stack use karte hain.

    Jab new value current minimum se chhoti hoti hai,
    toh encoded value store karte hain:

        encoded = 2 * newMin - oldMin

    Isse do fayde hote hain:
    1. encoded < newMin, toh encoded value ko identify kar sakte hain.
    2. Pop karte waqt old minimum recover kar sakte hain:

        oldMin = 2 * currentMin - encoded

    Isliye getMin() aur baaki operations O(1) mein hote hain.

    Time Complexity:
    push()    -> O(1)
    pop()     -> O(1)
    top()     -> O(1)
    getMin()  -> O(1)

    Auxiliary Space:
    O(N), kyunki ek stack mein maximum N entries store ho sakti hain.
*/