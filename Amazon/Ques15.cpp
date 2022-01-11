// https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here
        while(head) {
            int temp1 = M;
            while(head && --temp1) head = head -> next;
            int temp2 = N;
            Node *prevNode = head;
            while(head && temp2--) head = head -> next;
            if(prevNode) {
                head = head ? head -> next : NULL;
                prevNode -> next = head;
            }
        }
    }
};