/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    

    void push(ListNode* &stack, int data){
        ListNode* nn=new ListNode(data);
        if(stack==nullptr){
            stack=nn;
        }
        else{
            nn->next=stack;
            stack=nn;
        }
    }

    void insertAtEnd(ListNode* &ansPtr, int data){
        if(ansPtr==nullptr){
            ansPtr=new ListNode(data);
        }
        else{
            ListNode* temp=ansPtr;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=new ListNode(data);
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ansPtr=nullptr;
        int carry=0;
        int result;
        ListNode* one=l1;
        ListNode* two=l2;

        while (!((one==nullptr)&&(two==nullptr)&&(carry==0))){
            if(one==nullptr){
                insertAtEnd(ansPtr,two->val);
                two=two->next;
            }
            else if(two==nullptr){
                insertAtEnd(ansPtr,one->val);
                one=one->next;
            }
            else if((one==nullptr)&&(two==nullptr)&&(carry=1)){
                insertAtEnd(ansPtr,1);
                carry=0;
            }
            else{
                result=one->val+two->val+carry;
                insertAtEnd(ansPtr,result%10);
                (result>9)?carry=1:carry=0;
                one=one->next;
                two=two->next;
            }
        }
        return ansPtr;
    }
};
