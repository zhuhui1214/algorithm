/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);//头结点为0
        ListNode *tmp = result;//tmp 和result 是同一个链表
        int sum = 0;//初始化一个值,0
        while(l1||l2){
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            //上面就把l1和l2加起来
            tmp->next = new ListNode(sum%10);//tmp的下一个指针域变成余数
            sum = sum/10;//重新初始化值，如果有进位，就为1，没有就为0
            tmp=tmp->next;//tmp,就是一个光标，下一次循环需要前进一步
        }
        if(sum)
            tmp->next = new ListNode(1);//百位加起来，有进位，就要初始化1
        //tmp此时存的时候是先存个位，再存十位，再存百位，如果有千位，就加1
        return result->next;
    }
};
