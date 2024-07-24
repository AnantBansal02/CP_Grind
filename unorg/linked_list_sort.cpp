#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ListNode* findMiddle(ListNode* head){
//     ListNode* slow = head;
//     ListNode* fast = head->next;

//     while (fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     return slow;
// }

// ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//     // Dummy node to provide an easy handle on the merged list
//     ListNode dummy(0);
//     ListNode* tail = &dummy;

//     while (l1 && l2) {
//         if (l1->val < l2->val) {
//             tail->next = l1;
//             l1 = l1->next;
//         } else {
//             tail->next = l2;
//             l2 = l2->next;
//         }
//         tail = tail->next;
//     }

//     // Attach the remaining elements, if any
//     tail->next = l1 ? l1 : l2;
    
//     return dummy.next;
// }

// ListNode* sortList(ListNode* A) {
//     if (!A || !A->next) {
//         return A;
//     }
//     ListNode* middle = findMiddle(A);
//     ListNode* nextToMiddle = middle->next;

//     // Split the list into two halves
//     middle->next = nullptr;

//     // Recursively sort the two halves
//     ListNode* left = sortList(A);
//     ListNode* right = sortList(nextToMiddle);

//     // Merge the sorted halves
//     return mergeTwoLists(left, right);
//     return A;
// }
ListNode* insertionSortList(ListNode* A) {
    ListNode* dummy = new ListNode(INT_MIN);
    dummy->next = A;
    ListNode* curr = A;
    while(curr->next != NULL){
        if(curr->next->val < curr->val){
            ListNode* nextToCurr = curr->next;
            curr->next = curr->next->next;
            ListNode* temp = dummy;
            while(temp->next and temp->next->val < nextToCurr->val){
                temp = temp->next;
            }
            ListNode* nextToTemp = temp->next;
            temp->next = nextToCurr;
            nextToCurr->next =  nextToTemp;
        }
        else{
            curr = curr->next;
        }
    }
    return dummy->next;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i=1;i<n;i++){
        ListNode* curr = new ListNode(arr[i]);
        temp->next = curr;
        temp = temp->next;
    }
    temp = insertionSortList(head);
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
}
