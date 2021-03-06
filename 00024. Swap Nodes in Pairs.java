
//Accepted    364 ms    java
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode fir,sec,tmp;
        fir = head;
        sec = head.next;
        head = sec;
        fir.next = sec.next;
        sec.next = fir;
        tmp = fir;
        fir = fir.next;
        if(fir != null)
            sec = fir.next;
        else 
            return head;
        while(fir != null && sec != null)
        {
            fir.next = sec.next;
            tmp.next = sec;
            sec.next = fir;
            tmp = fir;
            fir = fir.next;
            if(fir != null)
                sec = fir.next;
        }
        return head;
    }
}

