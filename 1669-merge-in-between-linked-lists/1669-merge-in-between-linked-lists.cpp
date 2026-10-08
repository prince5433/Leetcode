class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        // 🔥 Step 1: temp1 ko (a-1)th node tak le jao
        // 👉 ye node hoga jahan se hume connection todna hai
        ListNode* temp1 = list1;
        for(int i = 1; i <= a-1; i++){
            temp1 = temp1->next;
        }
        // 👉 temp1 = node just BEFORE index 'a'


        // 🔥 Step 2: temp3 ko (b+1)th node tak le jao
        // 👉 ye node hoga jahan wapas connection jodega
        ListNode* temp3 = list1;
        for(int i = 1; i <= b+1; i++){
            temp3 = temp3->next;
        }
        // 👉 temp3 = node just AFTER index 'b'


        // 🔥 Step 3: list2 ka head connect karo temp1 ke baad
        temp1->next = list2;


        // 🔥 Step 4: list2 ke end tak jao
        ListNode* temp2 = list2;
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        // 👉 temp2 = last node of list2


        // 🔥 Step 5: list2 ke last ko temp3 se connect karo
        temp2->next = temp3;


        // 🔥 Final: modified list1 return
        return list1;
    }
};