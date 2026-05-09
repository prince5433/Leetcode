/**
 * 💡 INTUITION (Soch / Logic kya hai iske peeche?):
 * 
 * Bhai, kisi bhi Binary Tree ka 'Diameter' do nodes ke beech ka sabse lamba path hota hai.
 * Dhyan rakhna, yeh rasta zaroori nahi ki top wali 'root' node se hoke hi guzre. 
 * Woh tree ke kisi neeche wale hisse mein bhi ho sakta hai.
 *
 * Toh solution kya hai? Hum tree ke HAR node par khade hoke 2 sawal puchenge:
 * 1. "Tere left child se sabse lamba rasta (height) kitna aa raha hai?" -> `left`
 * 2. "Tere right child se sabse lamba rasta (height) kitna aa raha hai?" -> `right`
 *
 * 👉 Kisi bhi current node ke through banne wala lamba path kya hoga? = `left + right`
 *
 * Hum ek global variable 'maxDia' banayenge. Har node apna `left + right` check karega,
 * aur agar woh ab tak ke `maxDia` se bada nikla, toh usko update kar dega.
 *
 * Aur DFS function ka kaam kya hai? Woh calculate karke apne parent ko bas apni 
 * "height" wapas karega (return karega), taaki parent apna calculation kar sake.
 * Node ki height = 1 (main khud) + maximum of(meri left height, meri right height).
 * 
 * Yeh ek Bottom-Up (Post-order) approach hai, matlab pehle leaves solve honge fir upar jayenge.
 */

class Solution {
public:
    // Yeh hamara global variable hai jo poore tree me sabse maximum diameter ko store karega
    int maxDia = 0;  

    // DFS function: Yeh kisi node ki "height" return karta hai edges ke terms me.
    int dfs(TreeNode* root) {
        
        // 🛑 BASE CASE: Agar node hi nahi hai (hum patto/leaves ke bhi neeche aagaye hain), 
        // toh uski height 0 hogi. Yahan se wapas laut jao.
        if (root == NULL) return 0;  

        // 🟢 STEP 1: Left bache se pucho ki "teri maximum height kitni hai?"
        int left = dfs(root->left);

        // 🟢 STEP 2: Right bache se pucho ki "teri maximum height kitni hai?"
        int right = dfs(root->right);

        // 🔥 STEP 3: MAIN LOGIC (Calculate Diameter)
        // Iss current node ko center maan kar jo path banega, uski length hogi (left + right).
        // Check karo ki kya yeh naya path purane maxDia se bada hai? Agar haan, toh update karo.
        maxDia = max(maxDia, left + right);

        // 🔼 STEP 4: Parent ko apni height return karo
        // Main (current node) apne parent ko bataunga ki meri height kitni hai.
        // Meri height = 1 (mera apna edge) + mere left aur right me se jo bhi zyada lamba ho.
        return 1 + max(left, right);
    }

    // Yeh main function hai jo platform pehle call karega
    int diameterOfBinaryTree(TreeNode* root) {
        
        dfs(root);        // DFS start karo. Yeh function chalega aur 'maxDia' ko chup-chaap calculate kar dega.
        
        return maxDia;    // Jab poora tree ghoom lenge, toh final maximum value return kar do.
    }
};